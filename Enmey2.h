#pragma once
#pragma once
#include"Engine/GameObject.h"
class Enemy2 :public GameObject
{
    int hModel_;
public:
    //�R���X�g���N�^
    Enemy2(GameObject* parent);

    //�f�X�g���N�^
    ~Enemy2();

    //������
    void Initialize()override;

    //�X�V
    void Update()override;

    //�`��
    void Draw()override;

    //�J��
    void Release()override;
};

