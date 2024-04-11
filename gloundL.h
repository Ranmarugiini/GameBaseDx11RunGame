#pragma once
#include"Engine/GameObject.h"
class gloundL :public GameObject
{
    int hModel_;
public:
    //コンストラクタ
    gloundL(GameObject* parent);

    //デストラクタ
    ~gloundL();

    //初期化
    void Initialize()override;

    //更新
    void Update()override;

    //描画
    void Draw()override;

    //開放
    void Release()override;
};


