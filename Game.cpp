#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Key.h"
#include "GameOver.h"
#include <math.h>

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

//�����蔻��
int range = 8;
int range2 = 10;
int range3 = (range + range2);

// �ϐ��錾
int cnt = 0, test = 1;
int startTime;		// �X�^�[�g�������L�����Ă���
unsigned int color = GetColor(0, 0, 255);	// �J���[�f�[�^�̊i�[
bool flg = false;

//������
void Game_Initialize() {
    //�L����
    mimageHandle = LoadGraph("�摜/�L����.png");
    //�G�L����
    mimageHandle2 = LoadGraph("�摜/���l�^�����X�^�[2.png");
}

//�X�V
void Game_Update() {

    // ���݌o�ߎ��Ԃ𓾂�
    startTime = GetNowCount();

    // �v�����Ԃ��� 21 �b���߂���܂ŃJ�E���g
    while (GetNowCount() - startTime < 1000 * 21) {
        // ���݂̌o�ߎ��Ԃ�\��
        if (true) {
            ClearDrawScreen();
            DrawFormatString(250, 240, color, "���݂̌o�ߎ��Ԃ� %d�b%d �ł��B\n",
                (GetNowCount() - startTime) / 1000,
                GetNowCount() - startTime);

        }
        if (GetNowCount() - startTime <= 1000) {
            // ��ʂɕ\��
            ClearDrawScreen();
            test++;
            flg = true;
        }
        // ���b�Z�[�W����
        if (ProcessMessage() == -1) {
            break;							// �G���[���N�����烋�[�v�𔲂���
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

    //�����蔻��
    int x2 = abs(ch_x - ball_x);
    int y2 = abs(ch_y - ball_y);
    if (x2 * x2 + y2 * y2 < range3 * range3) {
        SceneMgr_ChangeScene(eScene_GameOver);
    }
}

//�`��
void Game_Draw() {
    //�L����
    DrawRotaGraph(ch_x, ch_y, 0.03, 0.0, mimageHandle, TRUE);
    //�G�L����
    DrawRotaGraph(ball_x, ball_y, 0.04, 0.0, mimageHandle2, TRUE);
}

//�I������
void Game_Finalize() {
    
}