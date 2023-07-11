#define WINDOW_WIDTH 1280 //ウィンドウの幅
#define WINDOW_HEIGHT 720 //ウィンドウの高さ

#include <Novice.h>
#include "MyMatrix.h"

const char kWindowTitle[] = "GC2C_07_サカイレイ";

//行の間隔
static const int rowHeight = 20;
//列の間隔
static const int columnWidth = 60;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, WINDOW_WIDTH, WINDOW_HEIGHT);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	MyMatrix *myMatrix = new MyMatrix();

	//正射影行列
	Matrix4x4 orthographicsMatrix =
		myMatrix->MakeOrthographicMatrix(-160.0f, 160.0f, 200.0f, 300.0f, 0.0f, 1000.0f);
	//透視投影行列
	Matrix4x4 perspectiveFovMatrix =
		myMatrix->MakePerspectiveFovMatrix(0.63f, 1.33f, 0.1f, 1000.0f);
	//ビューポート変換行列
	Matrix4x4 viewportMatrix =
		myMatrix->MakeViewportMatrix(100.0f, 200.0f, 600.0f, 300.0f, 0.0f, 1.0f);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0)
	{
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		/// ↓更新処理ここから
		
		
		
		/// ↑更新処理ここまで
		

		
		/// ↓描画処理ここから
		
		myMatrix->MatrixScreenPrintf(0, 0, orthographicsMatrix, "orthographicsMatrix",columnWidth,rowHeight);
		myMatrix->MatrixScreenPrintf(0, rowHeight * 5, perspectiveFovMatrix, "perspectiveFovMatrix",columnWidth,rowHeight);
		myMatrix->MatrixScreenPrintf(0, rowHeight * 10, viewportMatrix, "viewportMatrix",columnWidth,rowHeight);
		
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
