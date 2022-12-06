#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Key.h"

int Handle;
int White = GetColor(255, 255, 255);

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

    DrawString(0, 0, "�N���b�V���R���b�Z�I", White);
}
//�I������
void Menu_Finalize() {
}