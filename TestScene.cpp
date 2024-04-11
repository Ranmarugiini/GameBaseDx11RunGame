#include "TestScene.h"
#include"glound.h"
#include"gloundL.h"
#include"player.h"
#include"Enemy.h"
#include"object1.h"
#include<cstdlib>


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
	Instantiate<gloundL>(this);
}
//�X�V

void TestScene::Update()
{//�����_���ɓG�o��
	int e = 0;
	if (e % 60 == 0)
	{
		int k = rand() % 750;
		if (k == 0)
		{
			Instantiate<Enemy>(this);
		}
		else if (k == 1)
		{
			Instantiate<Enemy>(this);
			Instantiate<Enemy>(this);
		}
		e = 0;
	}
	else {
		e++;
	}
	int OJ = rand() % 100;
	if (OJ == 0)
	{
		Instantiate<object1>(this);
	}
	else if (OJ == 1)
	{
		Instantiate<object1>(this);
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
