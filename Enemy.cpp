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
	transform_.position_.x = 0;
	transform_.position_.y = 0;
	transform_.position_.z = 20;
	hModel_ = Model::Load("Enemy.fbx");
	assert(hModel_ >= 0);
	hSound = Audio::Load("yukito.wav");
	assert(hSound >= 0);
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.5, 0.5, 0.5));
	AddCollider(collision);
}

void Enemy::Update()
{
	transform_.position_.z -= 0.25;
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
