#pragma once
#include"Engine/GameObject.h"
class glound:public GameObject
{
    int hModel_;
public:
    //�R���X�g���N�^
    glound(GameObject* parent);

    //�f�X�g���N�^
    ~glound();

    //������
    void Initialize()override;

    //�X�V
    void Update()override;

    //�`��
    void Draw()override;

    //�J��
    void Release()override;
};

