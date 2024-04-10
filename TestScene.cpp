#include "TestScene.h"
#include"bullet.h"
#include"glound.h"
#include"player.h"
//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{
	Instantiate<bullet>(this);
	Instantiate<glound>(this);
	Instantiate<player>(this);
}

//更新
void TestScene::Update()
{
}

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}
