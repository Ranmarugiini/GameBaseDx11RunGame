#include "glound.h"
#include"Engine/Model.h"

glound::glound(GameObject*parent) :GameObject(parent, "glound"), hModel_(-1)
{


}
glound::~glound(){}

void glound::Initialize()
{//�������X
	transform_.position_.x = 0;
	transform_.position_.y = 0;
	transform_.position_.z = 25;
	//���f���̃T�C�Y�ύX
	transform_.scale_.z = 2.0;

	hModel_ = Model::Load("Floor.fbx");
	assert(hModel_ >= 0);
}

void glound::Update()
{
}

void glound::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void glound::Release()
{
}
