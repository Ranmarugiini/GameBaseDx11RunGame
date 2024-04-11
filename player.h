#pragma once
#include"Engine/GameObject.h"
#include"Engine/Text.h"
class player :public GameObject
{
    int hModel_;
private:
    Text*pText;
public:
    //コンストラクタ
    player(GameObject* parent);

    //デストラクタ
    ~player();

    //初期化
    void Initialize()override;

    //更新
    void Update()override;

    //描画
    void Draw()override;

    //開放
    void Release()override;
    void OnCollision(GameObject* pTarget)override;
};
