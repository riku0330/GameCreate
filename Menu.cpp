#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Key.h"
//������
void Menu_Initialize() {

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
    DrawString(0, 0, "���j���[��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "G�L�[�������ƃQ�[����ʂɐi�݂܂��B", GetColor(255, 255, 255));
    DrawString(0, 40, "C�L�[�������Ɓ@�ݒ��ʂɐi�݂܂��B", GetColor(255, 255, 255));
}
//�I������
void Menu_Finalize() {
}