#include "DxLib.h"
#include "SceneMgr.h"
#include "Menu.h"
#include "Game.h"
#include "GameOver.h"
#include "Clear.h"

static eScene mScene = eScene_Menu; // 現シーンの管理変数
static eScene mNextScene = eScene_None; //次のシーン管理変数
static void SceneMgr_InitializeModule(eScene scene);//指定モジュールを初期化する
static void SceneMgr_FinalizeModule(eScene scene);//指定モジュールの終了処理を行う

//初期化
void SceneMgr_Initialize() {
    SceneMgr_InitializeModule(mScene);
}

//シーンの更新
void SceneMgr_Update() {
    if (mNextScene != eScene_None) {    //次のシーンがセットされていたら
        SceneMgr_FinalizeModule(mScene); //現在のシーンの終了処理を実行
        mScene = mNextScene;    //次のシーンを現在のシーンセット
        mNextScene = eScene_None;    //次のシーン情報をクリア
        SceneMgr_InitializeModule(mScene);    //現在のシーンを初期化
    }
    //現在のシーンによって処理を分岐
    switch (mScene) {
    case eScene_Menu:
        Menu_Update();   //メニュー画面の更新処理をする
        break;
    case eScene_Game:
        Game_Update();
        break;
    case eScene_GameOver:
        GameOver_Update();
        break;
    case eScene_Clear:
        Clear_Update();
        break;
    default:
        break;
    }
}

//各シーンの描画
void SceneMgr_Draw() {
    //現在のシーンによって処理を分岐
    switch (mScene) {
    case eScene_Menu:
        Menu_Draw();   //メニュー画面の更新処理をする
        break;
    case eScene_Game:
        Game_Draw();
        break;
    case eScene_GameOver:
        GameOver_Draw();
        break;
    case eScene_Clear:
        Clear_Draw();
        break;
    default:
        break;
    }
}

//引数 nextScene のシーンを変更する
void SceneMgr_ChangeScene(eScene NextScene) {
    mNextScene = NextScene;    //次のシーンをセットする
}

//終了処理
void SceneMgr_Finalize() {
    SceneMgr_FinalizeModule(mScene);
}

// 引数sceneモジュールを初期化する
static void SceneMgr_InitializeModule(eScene scene) {
    switch (scene) {          //シーンによって処理を分岐
    case eScene_Menu:       //指定画面がメニュー画面なら
        Menu_Initialize();  //メニュー画面の初期化処理をする
        break;//以下略
    case eScene_Game:
        Game_Initialize();
        break;
    case eScene_GameOver:
        GameOver_Initialize();
        break;
    case eScene_Clear:
        Clear_Initialize();
        break;
    }
}

// 引数sceneモジュールの終了処理を行う
static void SceneMgr_FinalizeModule(eScene scene) {
    switch (scene) {         //シーンによって処理を分岐
    case eScene_Menu:      //指定画面がメニュー画面なら
        Menu_Finalize();   //メニュー画面の終了処理処理をする
        break;//以下略
    case eScene_Game:
        Game_Finalize();
        break;
    case eScene_GameOver:
        GameOver_Finalize();
        break;
    case eScene_Clear:
        Clear_Finalize();
        break;
    }
}