#pragma once
#include"Engine/GameObject.h"
class Enemy3 :public GameObject
{
    int hModel_;
public:
    //�R���X�g���N�^
    Enemy3(GameObject* parent);

    //�f�X�g���N�^
    ~Enemy3();

    //������
    void Initialize()override;

    //�X�V
    void Update()override;

    //�`��
    void Draw()override;

    //�J��
    void Release()override;
};


