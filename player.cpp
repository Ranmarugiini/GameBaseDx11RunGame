#include "player.h"
#include "Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"
player::player(GameObject* parent) :GameObject(parent, "player"), hModel_(-1),pText(nullptr)
{

}
player::~player() {

}
void player::Initialize()
{
	transform_.scale_.x = 0.1;
	transform_.scale_.y = 0.1;
	transform_.scale_.z = 0.1;
	//初期リス
	transform_.position_.x = 0;
	transform_.position_.y = 0;
	transform_.position_.z = -3;
	hModel_ = Model::Load("sedanSports.fbx");
	assert(hModel_ >= 0);
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.25, 0.25, 0.25));
	AddCollider(collision);
}

void player::Update()
{

	//左右キー押したら左右に動く（テレポート）
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
		transform_.position_.x = -2;
	}
	if (Input::IsKey(DIK_UP))
	{
		transform_.position_.z += 0.5;
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
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
}
