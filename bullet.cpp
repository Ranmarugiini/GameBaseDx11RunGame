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

	
}

void bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void bullet::Release()
{
}