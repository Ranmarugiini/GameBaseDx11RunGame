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
}

//更新
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

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}
