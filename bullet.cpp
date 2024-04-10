#include "bullet.h"
#include "Engine/Model.h"

bullet::bullet(GameObject*parent):GameObject(parent,"bullet"),hModel_(-1)
{

}
bullet::~bullet() {

}
void bullet::Initialize()
{
	hModel_ = Model::Load("bullet.fbx");
	assert(hModel_ >= 0);
}

void bullet::Update()
{
	int i = 0;
	while (i >= 100) {
		transform_.position_.z -= 0.1;
		if (transform_.position_.z = -1.0f)
		{
			break;
		}
		else
		{
			i++;
		}
	}
}

void bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void bullet::Release()
{
}