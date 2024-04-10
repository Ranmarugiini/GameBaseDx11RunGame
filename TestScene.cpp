#include "TestScene.h"
#include"glound.h"
#include"player.h"
#include"Enemy.h"
#include"Enemy3.h"
#include"Enmey2.h"
#include<cstdlib>
#include<chrono>
#include<thread>
using namespace std;
//�R���X�g���N�^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//������
void TestScene::Initialize()
{
	Instantiate<glound>(this);
	Instantiate<player>(this);
}

//�X�V
void TestScene::Update()
{
	 int k=rand() % 350;
	 if (k == 0)
	 {
		 Instantiate<Enemy>(this);
	 }
	 else if (k == 1)
	 {
		 Instantiate<Enemy2>(this);
	 }
	 else if(k==2)
	 {
		 Instantiate<Enemy3>(this);
	 }
	 else if (k == 4)
	 {
		 Instantiate<Enemy>(this);
		 Instantiate<Enemy2>(this);
	 }
	 else if (k == 5)
	 {
		 Instantiate<Enemy>(this);
		 Instantiate<Enemy3>(this);
	 }
	 else if (k == 6)
	 {
		 Instantiate<Enemy2>(this);
		 Instantiate<Enemy3>(this);
	 }
}

//�`��
void TestScene::Draw()
{
}

//�J��
void TestScene::Release()
{
}
