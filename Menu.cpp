#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Key.h"

int Handle;
int White = GetColor(255, 255, 255);

//初期化
void Menu_Initialize() {
    Handle = LoadGraph("画像/ホーム画面２.png");
}
//更新
void Menu_Update() {
    if (Keyboard_Get(KEY_INPUT_G) == 1) {//Gキーが押されていたら
        SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
    }
    if (Keyboard_Get(KEY_INPUT_C) == 1) {//Cキーが押されていたら
        SceneMgr_ChangeScene(eScene_Config);//シーンを設定画面に変更
    }
}
//描画
void Menu_Draw() {
    //ホーム画面
    LoadGraphScreen(0, 0, "画像/ホーム画面２.png", TRUE);

    DrawString(0, 0, "クラッシュコロッセオ", White);
}
//終了処理
void Menu_Finalize() {
}