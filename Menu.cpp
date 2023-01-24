#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Key.h"

int Handle;
int White = GetColor(0, 0, 0);

//������
void Menu_Initialize() {
    Handle = LoadGraph("�摜/�z�[����ʂQ.png");
}
//�X�V
void Menu_Update() {
    if (Keyboard_Get(KEY_INPUT_G) == 1) {//G�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
    }
    if (Keyboard_Get(KEY_INPUT_C) == 1) {//C�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
    }
}
//�`��
void Menu_Draw() {
    //�z�[�����
    LoadGraphScreen(0, 0, "�摜/�z�[����ʂQ.png", TRUE);

    DrawString(250, 100, "�N���b�V�� ����", White);
    DrawString(250, 150, "���L�[�ŏ㉺���E�ړ�", White);
    DrawString(250, 400, "G�L�[�ŃQ�[���X�^�[�g�I�I", White);
}
//�I������
void Menu_Finalize() {
}