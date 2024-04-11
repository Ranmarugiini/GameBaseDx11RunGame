#pragma once
#include"Engine/GameObject.h"
class object1:public GameObject
{
	int hModel_;
public:
    //コンストラクタ
    object1(GameObject* parent);

    //デストラクタ
    ~object1();

    //初期化
    void Initialize()override;

    //更新
    void Update()override;

    //描画
    void Draw()override;

    //開放
    void Release()override;
};

