#include "DxLib.h"
#include "Key.h"
#include "SceneMgr.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ウィンドウモードに設定
    ChangeWindowMode(TRUE);
    // DXライブラリ初期化処理
    if (DxLib_Init() < 0) {
        //エラーなら終了する
        return -1;
    }
    //描画先を裏画面にする
    SetDrawScreen(DX_SCREEN_BACK);
    // 画面モードの変更
    SetGraphMode(640, 480, 32);
    SceneMgr_Initialize();
    // while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
        Keyboard_Update();
        SceneMgr_Update();
        SceneMgr_Draw();
        if (Keyboard_Get(KEY_INPUT_ESCAPE) > 0) {
            break;
        }
    }
    SceneMgr_Finalize();
    DxLib_End();    // DXライブラリ終了処理
    return 0;
}