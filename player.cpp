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
	//初期リス
	transform_.position_.x = 0;
	transform_.position_.y = 0;
	transform_.position_.z = -3;
	hModel_ = Model::Load("player.fbx");
	assert(hModel_ >= 0);
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.25, 0.25, 0.25));
	AddCollider(collision);
}

void player::Update()
{
	//AD押したら左右に動く（テレポート）
	if (Input::IsKey(DIK_LEFT)) {
		transform_.position_.x = -2;
		transform_.position_.y = 0;
		transform_.position_.z = -3;
	}
	else if (Input::IsKey(DIK_RIGHT)) {
		transform_.position_.x = 2;
		transform_.position_.y = 0;
		transform_.position_.z = -3;
	}
	else {
		transform_.position_.x = 0;
	}
}

void player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void player::Release()
{
}

void player::OnCollision(GameObject* pTarget)
{
	KillMe();
}
