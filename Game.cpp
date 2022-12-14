#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Key.h"
#include <stdlib.h>
#include <time.h>

#define SIZE 16//��ʏ�ɕ\�������}�X�̔����̃T�C�Y
#define MAPX 80//�}�b�v�̉���
#define MAPY 60//�}�b�v�̏c��

float ch_x = 320;
float ch_y = 240;
int mimageHandle;

//�����蔻��p�̃t���O
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
    int type;//0��1��2�K�i3
    bool Flag;
} box_t;

//�����_���ɒ����`�̕��������蔲���֐�
void roomMaker(box_t array[][MAPX]) {
    //�����̎n�܂�ƏI���������_���Ɍ��߂�
    int room_StartX = 1 + rand() % (MAPX - 2);
    int room_StartY = 1 + rand() % (MAPY - 2);
    int room_EndX = room_StartX + rand() % (MAPX - room_StartX);
    int room_EndY = room_StartY + rand() % (MAPY - room_StartY);
    //���͈̔͂����蔲��
    for (int i = room_StartY; i < room_EndY; i++) {
        for (int j = room_StartX; j < room_EndX; j++) {
            array[i][j].type = 0;
        }
    }
}

//�K�i�����֐�
void stairsMaker(box_t array[][MAPX]) {
    //�K�i�����ꏊ�������_���Ɍ��߂�
    int stairs_X = 3 + rand() % (MAPX - 6);
    int stairs_Y = 3 + rand() % (MAPY - 6);

    //�K�i�̎���8�}�X�����蔲��
    for (int i = stairs_Y - 1; i <= stairs_Y + 1; i++) {
        for (int j = stairs_X - 1; j <= stairs_X + 1; j++) {
            array[i][j].type = 0;
        }
    }
    //�K�i�܂ł̓������
    for (int k = 1; k < MAPX - 1; k++) {
        array[stairs_Y][k].type = 0;
    }
    for (int l = 1; l < MAPY - 1; l++) {
        array[l][stairs_X].type = 0;
    }
    //�K�i��ݒu
    array[stairs_Y][stairs_X].type = 2;
}

//roomMaker�֐����Ăяo���ă_���W�����}�b�v�����֐�
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

//������
void Game_Initialize() {

    mimageHandle = LoadGraph("�摜/�L����.png");

}

//�X�V
void Game_Update() {

    srand((unsigned int)time(NULL));

    box_t box[MAPY][MAPX];
    //�ǂ̈ʒu�ƃt���O�̏�����
    for (int i = 0; i < MAPY; i++) {
        for (int j = 0; j < MAPX; j++) {
            box[i][j].x = SIZE + j * (SIZE * 2);
            box[i][j].y = SIZE + i * (SIZE * 2);
            box[i][j].type = 1;
            box[i][j].Flag = 0;
        }
    }

    //�e�u���b�N�̃t���O�̏�����
    for (int i = 0; i < MAPY; i++) {
        for (int j = 0; j < MAPX; j++) {
            box[i][j].Flag = 0;
        }
    }

    //�A��Q�����Ƃɓ����蔻��
    for (int i = 0; i < MAPY; i++) {
        for (int j = 0; j < MAPX; j++) {
            //mybox�̂ǂ����������Ă��邩�̔���
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
    if (Keyboard_Get(KEY_INPUT_R) == 1) {
        mapMaker(box);
    }

    //Map�̕��𓮂������͂������L����
    for (int i = 0; i < MAPY; i++) {
        for (int j = 0; j < MAPX; j++) {
            box[i][j].x = box[i][j].x - ch_x;
            box[i][j].y = box[i][j].y - ch_y;
        }
    }

    for (int i = 0; i < MAPY; i++) {
        for (int j = 0; j < MAPX; j++) {
            if (box[i][j].type == 1) {
                DrawBox(box[i][j].x - SIZE, box[i][j].y - SIZE, box[i][j].x + SIZE, box[i][j].y + SIZE, Green, TRUE);   // ��Q��
                DrawBox(box[i][j].x - SIZE, box[i][j].y - SIZE, box[i][j].x + SIZE, box[i][j].y + SIZE, aliceblue, false);   // ��Q��
            }
            if (box[i][j].type == 2) {
                DrawBox(box[i][j].x - SIZE, box[i][j].y - SIZE, box[i][j].x + SIZE, box[i][j].y + SIZE, Red, TRUE);   // ��Q��
                DrawBox(box[i][j].x - SIZE, box[i][j].y - SIZE, box[i][j].x + SIZE, box[i][j].y + SIZE, aliceblue, false);   // ��Q��c
            }
            if (box[i][j].type != 0) {//�u���b�N�̃t���O�\���i-3�͈ʒu�̔������j
                //DrawFormatString(box[i][j].x-3, box[i][j].y-3, White, "%d", box[i][j].Flag);
            }
        }
    }
}

//�`��
void Game_Draw() {
    DrawRotaGraph(ch_x, ch_y, 0.05, 0.0, mimageHandle, TRUE);
}

//�I������
void Game_Finalize() {

}