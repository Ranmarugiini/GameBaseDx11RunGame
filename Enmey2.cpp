#include "Enmey2.h"
#include"Engine/Model.h"
#include"Engine/BoxCollider.h"

Enemy2::Enemy2(GameObject* parent) :GameObject(parent, "Enemy2"), hModel_(-1)
{
}

Enemy2::~Enemy2()
{
}

void Enemy2::Initialize()
{//‰ŠúƒŠƒX
	transform_.position_.x = -2;
	transform_.position_.y = 0;
	transform_.position_.z = 20;
	hModel_ = Model::Load("Enemy.fbx");
	assert(hModel_ >= 0);
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.5, 0.5, 0.5));
	AddCollider(collision);
}
void Enemy2::Update()
{
	transform_.position_.z -= 0.25;
	if (transform_.position_.z <= -20)
	{
		KillMe();
	}
}

void Enemy2::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy2::Release()
{
}
