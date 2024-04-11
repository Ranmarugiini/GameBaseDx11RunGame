#include "Enemy.h"
#include"Engine/Model.h"
#include"Engine/BoxCollider.h"
#include"Engine/Audio.h"

Enemy::Enemy(GameObject* parent) :GameObject(parent, "Enemy"), hModel_(-1),hSound(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{//‰ŠúƒŠƒX
	float X = (rand() %3)+1;
	if (X == 1)
	{
		transform_.position_.x = 0;
	}
	else if (X == 2) {
	
	}
	else if (X == 3)
	{
		transform_.position_.x = 2;
	}
	transform_.position_.y = 0.5;
	transform_.position_.z = 150;
	float Y = (rand() % 3) + 1;
	if (Y == 1)
	{
		hModel_ = Model::Load("suv.fbx");
		transform_.scale_.x = 0.1;
		transform_.scale_.y = 0.1;
		transform_.scale_.z = 0.1;
		transform_.rotate_.y = 180;
	}
	else if (Y == 2) {
		hModel_ = Model::Load("van.fbx");
		transform_.scale_.x = 0.1;
		transform_.scale_.y = 0.1;
		transform_.scale_.z = 0.1;
		transform_.rotate_.y = 180;
	}
	else if (Y == 3)
	{
		hModel_ = Model::Load("deliveryFlat.fbx");
		transform_.scale_.x = 0.1;
		transform_.scale_.y = 0.1;
		transform_.scale_.z = 0.1;
		transform_.rotate_.y = 180;
	}
	assert(hModel_ >= 0);
	hSound = Audio::Load("yukito.wav");
	assert(hSound >= 0);
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.5, 1, 0.5));
	AddCollider(collision);
}

void Enemy::Update()
{
	transform_.position_.z -= 0.5;
	if (transform_.position_.z <= -20)
	{
		Audio::Play(hSound);
		KillMe();
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}
