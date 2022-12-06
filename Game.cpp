#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Key.h"
//初期化
void Game_Initialize() {

}
//更新
void Game_Update() {
    if (Keyboard_Get(KEY_INPUT_M) == 1) { //Mキーが押されていたら
        SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
    }
}
//描画
void Game_Draw() {
    DrawString(0, 0, "ゲーム画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "Mキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
}
//終了処理
void Game_Finalize() {
}