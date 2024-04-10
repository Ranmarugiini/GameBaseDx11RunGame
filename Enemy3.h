#pragma once
#include"Engine/GameObject.h"
class Enemy3 :public GameObject
{
    int hModel_;
public:
    //コンストラクタ
    Enemy3(GameObject* parent);

    //デストラクタ
    ~Enemy3();

    //初期化
    void Initialize()override;

    //更新
    void Update()override;

    //描画
    void Draw()override;

    //開放
    void Release()override;
};


