#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Key.h"
#include <stdlib.h>
#include <time.h>

//�L����
int  ch_x = 320;
int ch_y = 240;
int move_x = 0;
int move_y = 0;
int mimageHandle;

//�G�L����
int mimageHandle2;
int enemy_x = 610;
int enemy_y = 240;

//�����蔻��p�̃t���O
bool LEFTFlag = false;
bool RIGHTFlag = false;
bool TOPFlag = false;
bool BOTTOMFlag = false;

int Red = GetColor(211, 0, 0);
int G_Blue = GetColor(0, 255, 255);
int aliceblue = GetColor(240, 248, 255);
int Green = GetColor(0, 255, 0);



//������
void Game_Initialize() {
    //�L����
    mimageHandle = LoadGraph("�摜/�L����.png");
    //�G�L����
    mimageHandle2 = LoadGraph("�摜/���l�^�����X�^�[2.png");
}

//�X�V
void Game_Update() {
    //�L�����̈ړ�(�㉺�ړ�)
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

//�`��
void Game_Draw() {
    //�L����
    DrawRotaGraph(ch_x, ch_y, 0.03, 0.0, mimageHandle, TRUE);
    //�G�L����
    DrawRotaGraph(enemy_x, enemy_y, 0.04, 0.0, mimageHandle2, TRUE);
}

//�I������
void Game_Finalize() {
    
}