#include "glound.h"
#include"Engine/Model.h"

glound::glound(GameObject*parent) :GameObject(parent, "glound"), hModel_(-1)
{


}
glound::~glound(){}

void glound::Initialize()
{//初期リス
	transform_.position_.x = 2;
	transform_.position_.y = -2;
	transform_.position_.z = 25;

	transform_.rotate_.y= 90;
	//モデルのサイズ変更
	transform_.scale_.x = 200;
	transform_.scale_.z = 0.5;

	hModel_ = Model::Load("tile016.fbx");
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
