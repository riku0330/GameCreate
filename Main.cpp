#include "DxLib.h"
#include "Key.h"
#include "SceneMgr.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // �E�B���h�E���[�h�ɐݒ�
    ChangeWindowMode(TRUE);
    // DX���C�u��������������
    if (DxLib_Init() < 0) {
        //�G���[�Ȃ�I������
        return -1;
    }
    //�`���𗠉�ʂɂ���
    SetDrawScreen(DX_SCREEN_BACK);
    // ��ʃ��[�h�̕ύX
    SetGraphMode(640, 480, 32);
    SceneMgr_Initialize();
    // while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
        Keyboard_Update();
        SceneMgr_Update();
        SceneMgr_Draw();
        if (Keyboard_Get(KEY_INPUT_ESCAPE) > 0) {
            break;
        }
    }
    SceneMgr_Finalize();
    DxLib_End();    // DX���C�u�����I������
    return 0;
}