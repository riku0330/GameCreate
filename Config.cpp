#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Key.h"
//������
void Config_Initialize() {
}
//�X�V
void Config_Update() {
    if (Keyboard_Get(KEY_INPUT_M) == 1) { //M�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
    }
}
//�`��
void Config_Draw() {
    DrawString(0, 0, "�ݒ��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "M�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}
//�I������
void Config_Finalize() {
}