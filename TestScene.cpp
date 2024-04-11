#include "TestScene.h"
#include"glound.h"
#include"gloundL.h"
#include"player.h"
#include"Enemy.h"
#include"object1.h"
#include<cstdlib>


//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{
	Instantiate<glound>(this);
	Instantiate<player>(this);
	Instantiate<gloundL>(this);
}
//更新

void TestScene::Update()
{//ランダムに敵出す
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

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}
