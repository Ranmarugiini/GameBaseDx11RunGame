#pragma once
#pragma once
#include"Engine/GameObject.h"
class Enemy2 :public GameObject
{
    int hModel_;
public:
    //コンストラクタ
    Enemy2(GameObject* parent);

    //デストラクタ
    ~Enemy2();

    //初期化
    void Initialize()override;

    //更新
    void Update()override;

    //描画
    void Draw()override;

    //開放
    void Release()override;
};

