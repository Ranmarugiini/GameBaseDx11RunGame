#include "player.h"
#include "Engine/Model.h"
#include"Engine/Input.h"

player::player(GameObject* parent) :GameObject(parent, "player"), hModel_(-1)
{

}
player::~player() {

}
void player::Initialize()
{
	hModel_ = Model::Load("player.fbx");
	assert(hModel_ >= 0);
}

void player::Update()
{
	if (Input::IsKey(DIK_SPACE))
	{
		transform_.position_.y += 0.2;

	}
	else if (Input::IsKey(DIK_A))
        transform_.position_.x -= 0.2;
	
	else if (Input::IsKey(DIK_D))
		transform_.position_.x += 0.2;
}

void player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void player::Release()
{
}