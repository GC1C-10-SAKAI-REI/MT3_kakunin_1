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

	//行列クラスの作成
	MyMatrix* myMatrix = new MyMatrix();

	//移動成分
	Vec3 translate{};
	//回転成分
	Vec3 rotate{};
	//カメラの位置
	Vec3 cameraPos{ 0.0f,0.0f,-5.0f };
	//ローカル座標上の三角形の頂点座標
	Vec3 localVertices[3] =
	{
		{ 0.0f,0.5f,0.0f },
		{ 0.5f,-0.5f,0.0f },
		{ -0.5f,-0.5f,0.0f }
	};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0)
	{
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);


		/// ↓更新処理ここから
		
		//Y軸を中心に回転
		rotate.Y += 0.03f;

		//キー入力受付
		if (keys[DIK_W])
		{
			translate.Z += 0.03f;
		}
		if (keys[DIK_S])
		{
			translate.Z -= 0.03f;
		}
		if (keys[DIK_A])
		{
			translate.X -= 0.02f;
		}
		if (keys[DIK_D])
		{
			translate.X += 0.02f;
		}

		//1.ローカル座標系からワールド座標系に変換
		Matrix4x4 worldMatrix = myMatrix->MakeAffineMatrix({ 1.0f,1.0f,1.0f }, rotate, translate);
		//2.
		Matrix4x4 cameraMatrix = myMatrix->MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, cameraPos);
		//3.ビュー座標系に変換
		Matrix4x4 viewMatrix = myMatrix->Inverse(cameraMatrix);
		//4.ビュー座標系から同時クリップ座標系に変換
		Matrix4x4 projectionMatrix = myMatrix->MakePerspectiveFovMatrix(0.45f, float(WINDOW_WIDTH) / float(WINDOW_HEIGHT), 0.1f, 100.0f);
		//5.
		Matrix4x4 worldViewProjectionMatrix = myMatrix->Multiply(worldMatrix, myMatrix->Multiply(viewMatrix, projectionMatrix));
		//6.正規化デバイス座標系からスクリーン座標系に変換
		Matrix4x4 viewportMatrix = myMatrix->MakeViewportMatrix(0, 0, float(WINDOW_WIDTH), float(WINDOW_HEIGHT), 0.0f, 1.0f);

		//スクリーン空間へと頂点を変換する
		Vec3 scrVertices[3];

		for (uint32_t i = 0; i < 3; i++)
		{
			//正規化デバイス座標系まで変換。Transformを使うと同時
			Vec3 ndcVertex = myMatrix->Transform(localVertices[i], worldViewProjectionMatrix);
			//ビューポート変換を行ってスクリーン空間へ
			scrVertices[i] = myMatrix->Transform(ndcVertex, viewportMatrix);
		}
		
		/// ↑更新処理ここまで
		

		
		/// ↓描画処理ここから
		
		Novice::DrawTriangle(
			int(scrVertices[0].X), int(scrVertices[0].Y),
			int(scrVertices[1].X), int(scrVertices[1].Y),
			int(scrVertices[2].X), int(scrVertices[2].Y),
			RED, kFillModeSolid
		);
		
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