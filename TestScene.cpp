#include "TestScene.h"
#include"bullet.h"
#include"glound.h"
#include"player.h"
//�R���X�g���N�^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//������
void TestScene::Initialize()
{
	Instantiate<bullet>(this);
	Instantiate<glound>(this);
	Instantiate<player>(this);
}

//�X�V
void TestScene::Update()
{
}

//�`��
void TestScene::Draw()
{
}

//�J��
void TestScene::Release()
{
}
