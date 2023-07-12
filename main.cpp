#define WINDOW_WIDTH 1280 //ウィンドウの幅
#define WINDOW_HEIGHT 720 //ウィンドウの高さ

#include <Novice.h>
#include "MyMatrix.h"

const char kWindowTitle[] = "GC2C_07_サカイレイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, WINDOW_WIDTH, WINDOW_HEIGHT);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//関数クラスの制作
	MyMatrix* myMatrix = new MyMatrix();

	//カメラの位置
	Vec3 cameraPos{ 0.0f,1.9f,-6.49f };
	//	〃	の角度
	Vec3 cameraRotate{ 0.26f,0.0f,0.0f };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0)
	{
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		/// ↓更新処理ここから
		
		//1.
		Matrix4x4 cameraMatrix = myMatrix->MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraPos);
		//2.ビュー座標系に変換
		Matrix4x4 viewMatrix = myMatrix->Inverse(cameraMatrix);
		//3.ビュー座標系から同時クリップ座標系に変換
		Matrix4x4 projectionMatrix = myMatrix->MakePerspectiveFovMatrix(0.45f, float(WINDOW_WIDTH) / float(WINDOW_HEIGHT), 0.1f, 100.0f);
		//4.
		Matrix4x4 viewProjectionMatrix = myMatrix->Multiply(viewMatrix, projectionMatrix);
		//5.正規化デバイス座標系からスクリーン座標系に変換
		Matrix4x4 viewportMatrix = myMatrix->MakeViewportMatrix(0, 0, float(WINDOW_WIDTH), float(WINDOW_HEIGHT), 0.0f, 1.0f);
		
		/// ↑更新処理ここまで
		

		
		/// ↓描画処理ここから
		
		//グリッド描画
		myMatrix->DrawGrid(viewProjectionMatrix, viewportMatrix);
		
		/// ↑描画処理ここまで		

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0)
		{
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
