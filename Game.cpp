#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Key.h"
#include <stdlib.h>
#include <time.h>

//キャラ
int  ch_x = 320;
int ch_y = 240;
int move_x = 0;
int move_y = 0;
int mimageHandle;

//敵キャラ
int mimageHandle2;
int enemy_x = 610;
int enemy_y = 240;

//当たり判定用のフラグ
bool LEFTFlag = false;
bool RIGHTFlag = false;
bool TOPFlag = false;
bool BOTTOMFlag = false;

int Red = GetColor(211, 0, 0);
int G_Blue = GetColor(0, 255, 255);
int aliceblue = GetColor(240, 248, 255);
int Green = GetColor(0, 255, 0);



//初期化
void Game_Initialize() {
    //キャラ
    mimageHandle = LoadGraph("画像/キャラ.png");
    //敵キャラ
    mimageHandle2 = LoadGraph("画像/巨人型モンスター2.png");
}

//更新
void Game_Update() {
    //キャラの移動(上下移動)
    if (Keyboard_Get(KEY_INPUT_RIGHT) >= 1) {
        if (!RIGHTFlag) {
            ch_x++;
        }
    }
    if (Keyboard_Get(KEY_INPUT_LEFT) >= 1) {
        if (!LEFTFlag) {
            ch_x--;
        }
    }
    if (Keyboard_Get(KEY_INPUT_UP) >= 1) {
        if (!TOPFlag) {
            ch_y--;
        }
    }
    if (Keyboard_Get(KEY_INPUT_DOWN) >= 1) {
        if (!BOTTOMFlag) {
            ch_y++;
        }
    }
}

//描画
void Game_Draw() {
    //キャラ
    DrawRotaGraph(ch_x, ch_y, 0.03, 0.0, mimageHandle, TRUE);
    //敵キャラ
    DrawRotaGraph(enemy_x, enemy_y, 0.04, 0.0, mimageHandle2, TRUE);
}

//終了処理
void Game_Finalize() {
    
}