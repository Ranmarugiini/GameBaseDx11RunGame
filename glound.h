#pragma once
#include"Engine/GameObject.h"
class glound:public GameObject
{
    int hModel_;
public:
    //コンストラクタ
    glound(GameObject* parent);

    //デストラクタ
    ~glound();

    //初期化
    void Initialize()override;

    //更新
    void Update()override;

    //描画
    void Draw()override;

    //開放
    void Release()override;
};

