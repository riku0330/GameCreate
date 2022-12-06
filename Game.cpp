#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Key.h"

float ch_x = 70;
float ch_y = 400;
float y_prev = 0;
float y_temp = 0;
bool jflag = false;
int mimageHandle;

//初期化
void Game_Initialize() {
    mimageHandle = LoadGraph("画像/キャラ.png");
}

//更新
void Game_Update() {
    //キャラの移動(上下移動)
    if (Keyboard_Get(KEY_INPUT_RIGHT) >= 1) {
        ch_x++;
    }
    if (Keyboard_Get(KEY_INPUT_LEFT) >= 1) {
        ch_x--;
    }
    if (jflag == true) {
        y_temp = ch_y;
        ch_y += (ch_y - y_prev) + 1;
        y_prev = y_temp;
        if (ch_y == 360) {
            jflag = false;
        }
    }
    if (Keyboard_Get(KEY_INPUT_SPACE) >= 1 && jflag==false) {
        jflag = true;
        y_prev = ch_y;
        ch_y = ch_y - 20;
    }
}

//描画
void Game_Draw() {
    DrawRotaGraph(ch_x, ch_y, 0.05, 0.0, mimageHandle, TRUE);
}

//終了処理
void Game_Finalize() {

}