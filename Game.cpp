#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Key.h"
//������
void Game_Initialize() {

}
//�X�V
void Game_Update() {
    if (Keyboard_Get(KEY_INPUT_M) == 1) { //M�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
    }
}
//�`��
void Game_Draw() {
    DrawString(0, 0, "�Q�[����ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "M�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}
//�I������
void Game_Finalize() {
}