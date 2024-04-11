#include "object1.h"
#include"Engine/Model.h"
object1::object1(GameObject* parent) :GameObject(parent, "Enemy"), hModel_(-1)
{
}

object1::~object1()
{
}
void object1 :: Initialize()
{
	float X = (rand() % 2) + 1;
	if (X == 1)
	{
		transform_.position_.x = 3;
	}
	else if (X == 2) {
		transform_.position_.x = -3;
	}
	transform_.position_.y = 0.5;
	transform_.position_.z = 100;
	float Y = (rand() % 2) + 1;
	if (Y == 1)
	{
		hModel_ = Model::Load("lightPostLarge.fbx");
		transform_.scale_.x = 0.25;
		transform_.scale_.y = 0.25;
		transform_.scale_.z = 0.25;
		transform_.rotate_.y = 90;
		if (transform_.position_.x = -3)
		{
			transform_.rotate_.y = 270;
		}
	}
	else if (Y == 2) {
		hModel_ = Model::Load("treeSmall.fbx");
		transform_.scale_.x = 0.25;
		transform_.scale_.y = 0.25;
		transform_.scale_.z = 0.25;
		transform_.rotate_.y = 180;
	}
	
	assert(hModel_ >= 0);
}
void object1::Update()
{
	transform_.position_.z -= 0.25;
	if (transform_.position_.z <= -20)
	{
		KillMe();
	}
}
void object1::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}
void object1::Release()
{

}
