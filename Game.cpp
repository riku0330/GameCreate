#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Key.h"
#include <stdlib.h>
#include <time.h>

#define SIZE 16//画面上に表示されるマスの半分のサイズ
#define MAPX 80//マップの横数
#define MAPY 60//マップの縦数

float ch_x = 320;
float ch_y = 240;
int mimageHandle;

//当たり判定用のフラグ
bool LEFTFlag = false;
bool RIGHTFlag = false;
bool TOPFlag = false;
bool BOTTOMFlag = false;

int Red = GetColor(211, 0, 0);
int G_Blue = GetColor(0, 255, 255);
int aliceblue = GetColor(240, 248, 255);
int Green = GetColor(0, 255, 0);

typedef struct {
    int x;
    int y;
    int type;//0床1壁2階段3
    bool Flag;
} box_t;

//ランダムに長方形の部屋をくり抜く関数
void roomMaker(box_t array[][MAPX]) {
    //部屋の始まりと終わりをランダムに決める
    int room_StartX = 1 + rand() % (MAPX - 2);
    int room_StartY = 1 + rand() % (MAPY - 2);
    int room_EndX = room_StartX + rand() % (MAPX - room_StartX);
    int room_EndY = room_StartY + rand() % (MAPY - room_StartY);
    //その範囲をくり抜く
    for (int i = room_StartY; i < room_EndY; i++) {
        for (int j = room_StartX; j < room_EndX; j++) {
            array[i][j].type = 0;
        }
    }
}

//階段を作る関数
void stairsMaker(box_t array[][MAPX]) {
    //階段を作る場所をランダムに決める
    int stairs_X = 3 + rand() % (MAPX - 6);
    int stairs_Y = 3 + rand() % (MAPY - 6);

    //階段の周り8マスをくり抜く
    for (int i = stairs_Y - 1; i <= stairs_Y + 1; i++) {
        for (int j = stairs_X - 1; j <= stairs_X + 1; j++) {
            array[i][j].type = 0;
        }
    }
    //階段までの道を作る
    for (int k = 1; k < MAPX - 1; k++) {
        array[stairs_Y][k].type = 0;
    }
    for (int l = 1; l < MAPY - 1; l++) {
        array[l][stairs_X].type = 0;
    }
    //階段を設置
    array[stairs_Y][stairs_X].type = 2;
}

//roomMaker関数を呼び出してダンジョンマップを作る関数
void mapMaker(box_t array[][MAPX]) {
    for (int i = 0; i < MAPY; i++) {
        for (int j = 0; j < MAPX; j++) {
            array[i][j].x = SIZE + j * (SIZE * 2) - (SIZE * MAPX / 2);
            array[i][j].y = SIZE + i * (SIZE * 2) - (SIZE * MAPY / 2);
            array[i][j].type = 1;
            array[i][j].Flag = 0;
        }
    }
    for (int i = 0; i < 20; i++) {
        roomMaker(array);
    }
    stairsMaker(array);
}

//初期化
void Game_Initialize() {

    mimageHandle = LoadGraph("画像/キャラ.png");

}

//更新
void Game_Update() {

    srand((unsigned int)time(NULL));

    box_t box[MAPY][MAPX];
    //壁の位置とフラグの初期化
    for (int i = 0; i < MAPY; i++) {
        for (int j = 0; j < MAPX; j++) {
            box[i][j].x = SIZE + j * (SIZE * 2);
            box[i][j].y = SIZE + i * (SIZE * 2);
            box[i][j].type = 1;
            box[i][j].Flag = 0;
        }
    }

    //各ブロックのフラグの初期化
    for (int i = 0; i < MAPY; i++) {
        for (int j = 0; j < MAPX; j++) {
            box[i][j].Flag = 0;
        }
    }

    //②障害物ごとに当たり判定
    for (int i = 0; i < MAPY; i++) {
        for (int j = 0; j < MAPX; j++) {
            //myboxのどこが当たっているかの判定
            if (box[i][j].type != 0 && ch_x == box[i][j].x + SIZE * 2 && ch_y > box[i][j].y - SIZE * 2 && ch_y < box[i][j].y + SIZE * 2) {
                LEFTFlag = TRUE;
                box[i][j].Flag = 1;
            }
            if (box[i][j].type != 0 && ch_x == box[i][j].x - SIZE * 2 && ch_y > box[i][j].y - SIZE * 2 && ch_y < box[i][j].y + SIZE * 2) {
                RIGHTFlag = TRUE;
                box[i][j].Flag = 1;
            }
            if (box[i][j].type != 0 && ch_y == box[i][j].y - SIZE * 2 && ch_x > box[i][j].x - SIZE * 2 && ch_x < box[i][j].x + SIZE * 2) {
                BOTTOMFlag = TRUE;
                box[i][j].Flag = 1;
            }
            if (box[i][j].type != 0 && ch_y == box[i][j].y + SIZE * 2 && ch_x > box[i][j].x - SIZE * 2 && ch_x < box[i][j].x + SIZE * 2) {
                TOPFlag = TRUE;
                box[i][j].Flag = 1;
            }
        }
    }

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
    if (Keyboard_Get(KEY_INPUT_R) == 1) {
        mapMaker(box);
    }

    //Mapの方を動かす時はこちらを有効に
    for (int i = 0; i < MAPY; i++) {
        for (int j = 0; j < MAPX; j++) {
            box[i][j].x = box[i][j].x - ch_x;
            box[i][j].y = box[i][j].y - ch_y;
        }
    }

    for (int i = 0; i < MAPY; i++) {
        for (int j = 0; j < MAPX; j++) {
            if (box[i][j].type == 1) {
                DrawBox(box[i][j].x - SIZE, box[i][j].y - SIZE, box[i][j].x + SIZE, box[i][j].y + SIZE, Green, TRUE);   // 障害物
                DrawBox(box[i][j].x - SIZE, box[i][j].y - SIZE, box[i][j].x + SIZE, box[i][j].y + SIZE, aliceblue, false);   // 障害物
            }
            if (box[i][j].type == 2) {
                DrawBox(box[i][j].x - SIZE, box[i][j].y - SIZE, box[i][j].x + SIZE, box[i][j].y + SIZE, Red, TRUE);   // 障害物
                DrawBox(box[i][j].x - SIZE, box[i][j].y - SIZE, box[i][j].x + SIZE, box[i][j].y + SIZE, aliceblue, false);   // 障害物c
            }
            if (box[i][j].type != 0) {//ブロックのフラグ表示（-3は位置の微調整）
                //DrawFormatString(box[i][j].x-3, box[i][j].y-3, White, "%d", box[i][j].Flag);
            }
        }
    }
}

//描画
void Game_Draw() {
    DrawRotaGraph(ch_x, ch_y, 0.05, 0.0, mimageHandle, TRUE);
}

//終了処理
void Game_Finalize() {

}