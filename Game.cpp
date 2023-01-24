#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Key.h"
#include "GameOver.h"
#include "Clear.h"
#include <math.h>

//�n��
int mimageHandle5;

//�L����
int  ch_x = 20;
int ch_y = 240;
int mimageHandle;

//�G�L����
int mimageHandle2;
int ball_x = 600;
int ball_y = 240;
int x_speed = -1;
int y_speed = -1;

//�e
int Rand_x = GetRand(620) + 15;
int x = 0;
int Rand_x2 = GetRand(620) + 15;
int x2 = 0;
int Rand_y = GetRand(460) + 15;
int y = 0;
int Rand_y2 = GetRand(460) + 15;
int y2 = 0;
int Red = GetColor(255, 0, 0);

//�����蔻��
int range = 8;
int range2 = 13;
int range4 = 13;
int range7 = 13;
int range3 = (range + range2);
int range5 = (range4 + range2);
int range6 = (range7 + range2);

//����
int timelimit = 30;
int time = 0;

//������
void Game_Initialize() {
    //�L����
    mimageHandle = LoadGraph("�摜/�L����.png");
    //�G�L����
    mimageHandle2 = LoadGraph("�摜/���l�^�����X�^�[2.png");
    //�n��
    mimageHandle5 = LoadGraph("�摜/�n��.jpg");
}

//�X�V
void Game_Update() {
    //�e�̈ړ�
    if (x < 1360) {
        x = x - 3;
        if (x < 0) {
            x = 650;
            Rand_x = GetRand(620) + 15;
        }
    }
    if (y < 1360) {
        y = y - 3;
        if (y < 0) {
            y = 650;
            Rand_y = GetRand(460) + 15;
        }
    }

    //�G�L�����̈ړ�
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

    //�L�����̈ړ�(�㉺�ړ�)
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

    //�����蔻��(�L�����ƓG)
    int x2 = abs(ch_x - ball_x);
    int y2 = abs(ch_y - ball_y);
    if (x2 * x2 + y2 * y2 < range3 * range3) {
        SceneMgr_ChangeScene(eScene_GameOver);
    }

    //�����蔻��(�L�����ƒe)
    int x3 = abs(ch_x - Rand_x);
    int y3 = abs(ch_y - y);
    if (x3 * x3 + y3 * y3 < range5 * range5) {
        SceneMgr_ChangeScene(eScene_GameOver);
    }

    int x4 = abs(ch_x - x);
    int y4 = abs(ch_y - Rand_y);
    if (x4 * x4 + y4 * y4 < range6 * range6) {
        SceneMgr_ChangeScene(eScene_GameOver);
    }

    //��������
    time++;
    if (time == 60) {
        timelimit--;
        time = 0;
    }
    if (timelimit == 0) {
        SceneMgr_ChangeScene(eScene_Clear);
    }
}

//�`��
void Game_Draw() {
    //�n��
    DrawRotaGraph(320, 240, 1.0, 0.0, mimageHandle5, TRUE);
    //�L����
    DrawRotaGraph(ch_x, ch_y, 0.04, 0.0, mimageHandle, TRUE);
    //�G�L����
    DrawRotaGraph(ball_x, ball_y, 0.06, 0.0, mimageHandle2, TRUE);

    //�������ԕ\��
    DrawFormatString(5, 5, GetColor(255, 255, 255), "�^�C�� = %d�b",timelimit);

    //�e
    DrawCircle(Rand_x, y, 30, Red, TRUE);
    DrawCircle(x, Rand_y, 30, Red, TRUE);
}

//�I������
void Game_Finalize() {
    
}