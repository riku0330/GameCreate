#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Key.h"
//初期化
void Config_Initialize() {
}
//更新
void Config_Update() {
    if (Keyboard_Get(KEY_INPUT_M) == 1) { //Mキーが押されていたら
        SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
    }
}
//描画
void Config_Draw() {
    DrawString(0, 0, "設定画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "Mキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
}
//終了処理
void Config_Finalize() {
}