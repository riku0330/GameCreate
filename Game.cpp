#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Key.h"
#include "GameOver.h"
#include <math.h>

//キャラ
int  ch_x = 20;
int ch_y = 240;
int mimageHandle;

//敵キャラ
int mimageHandle2;
int ball_x = 600;
int ball_y = 240;
int x_speed = -1;
int y_speed = -1;

//当たり判定
int range = 8;
int range2 = 10;
int range3 = (range + range2);

// 変数宣言
int cnt = 0, test = 1;
int startTime;		// スタート時刻を記憶しておく
unsigned int color = GetColor(0, 0, 255);	// カラーデータの格納
bool flg = false;

//初期化
void Game_Initialize() {
    //キャラ
    mimageHandle = LoadGraph("画像/キャラ.png");
    //敵キャラ
    mimageHandle2 = LoadGraph("画像/巨人型モンスター2.png");
}

//更新
void Game_Update() {

    // 現在経過時間を得る
    startTime = GetNowCount();

    // 計測時間から 21 秒が過ぎるまでカウント
    while (GetNowCount() - startTime < 1000 * 21) {
        // 現在の経過時間を表示
        if (true) {
            ClearDrawScreen();
            DrawFormatString(250, 240, color, "現在の経過時間は %d秒%d です。\n",
                (GetNowCount() - startTime) / 1000,
                GetNowCount() - startTime);

        }
        if (GetNowCount() - startTime <= 1000) {
            // 画面に表示
            ClearDrawScreen();
            test++;
            flg = true;
        }
        // メッセージ処理
        if (ProcessMessage() == -1) {
            break;							// エラーが起きたらループを抜ける
        }
    }

    //敵キャラの移動
    ball_x = ball_x + x_speed;
    ball_y = ball_y + y_speed;
    if (ball_x >= 640) {
        ball_x = 640 - 5;
        x_speed *= -1;
    }
    if (ball_x <= 0) {
        ball_x = 5;
        x_speed *= -1;
    }
    if (ball_y >= 480) {
        ball_y = 480 - 5;
        y_speed *= -1;
    }
    if (ball_y <= 0) {
        ball_y = 5;
        y_speed *= -1;
    }

    //キャラの移動(上下移動)
    if (Keyboard_Get(KEY_INPUT_RIGHT) >= 1) {
        ch_x++;
    }
    if (Keyboard_Get(KEY_INPUT_LEFT) >= 1) {
        ch_x--;
    }
    if (Keyboard_Get(KEY_INPUT_UP) >= 1) {
        ch_y--;
    }
    if (Keyboard_Get(KEY_INPUT_DOWN) >= 1) {
        ch_y++;
    }

    //当たり判定
    int x2 = abs(ch_x - ball_x);
    int y2 = abs(ch_y - ball_y);
    if (x2 * x2 + y2 * y2 < range3 * range3) {
        SceneMgr_ChangeScene(eScene_GameOver);
    }
}

//描画
void Game_Draw() {
    //キャラ
    DrawRotaGraph(ch_x, ch_y, 0.03, 0.0, mimageHandle, TRUE);
    //敵キャラ
    DrawRotaGraph(ball_x, ball_y, 0.04, 0.0, mimageHandle2, TRUE);
}

//終了処理
void Game_Finalize() {
    
}