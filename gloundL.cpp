#include "gloundL.h"
#include"Engine/Model.h"

gloundL::gloundL(GameObject* parent) :GameObject(parent, "gloundL"), hModel_(-1)
{


}
gloundL::~gloundL() {}

void gloundL::Initialize()
{//初期リス
	transform_.position_.x = -2;
	transform_.position_.y = -2;
	transform_.position_.z = 25;

	transform_.rotate_.y = 270;
	//モデルのサイズ変更
	transform_.scale_.x = 200;
	transform_.scale_.z = 0.5;

	hModel_ = Model::Load("tile016.fbx");
	assert(hModel_ >= 0);
}
void gloundL::Update()
{
}

void gloundL::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void gloundL::Release()
{
}