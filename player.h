#pragma once
#include"Engine/GameObject.h"
#include"Engine/Text.h"
class player :public GameObject
{
    int hModel_;
private:
    Text*pText;
public:
    //�R���X�g���N�^
    player(GameObject* parent);

    //�f�X�g���N�^
    ~player();

    //������
    void Initialize()override;

    //�X�V
    void Update()override;

    //�`��
    void Draw()override;

    //�J��
    void Release()override;
    void OnCollision(GameObject* pTarget)override;
};
