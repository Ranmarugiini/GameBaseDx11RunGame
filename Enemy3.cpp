#include "Enemy3.h"
#include"Engine/Model.h"
#include"Engine/BoxCollider.h"

Enemy3::Enemy3(GameObject* parent) :GameObject(parent, "Enemy"), hModel_(-1)
{
}

Enemy3::~Enemy3()
{
}

void Enemy3::Initialize()
{//‰ŠúƒŠƒX
	transform_.position_.x = 2;
	transform_.position_.y = 0;
	transform_.position_.z = 20;
	hModel_ = Model::Load("Enemy.fbx");
	assert(hModel_ >= 0);
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.5, 0.5, 0.5));
	AddCollider(collision);
}
void Enemy3::Update()
{
	transform_.position_.z -= 0.25;
	if (transform_.position_.z <= -20)
	{
		KillMe();
	}
}

void Enemy3::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy3::Release()
{
}
