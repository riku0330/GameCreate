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

//������
void Game_Initialize() {
    mimageHandle = LoadGraph("�摜/�L����.png");
}

//�X�V
void Game_Update() {
    //�L�����̈ړ�(�㉺�ړ�)
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

//�`��
void Game_Draw() {
    DrawRotaGraph(ch_x, ch_y, 0.05, 0.0, mimageHandle, TRUE);
}

//�I������
void Game_Finalize() {

}