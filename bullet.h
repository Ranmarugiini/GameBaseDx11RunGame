#pragma once
#include"Engine/GameObject.h"
class bullet:public GameObject
{
    int hModel_;
public:
    //�R���X�g���N�^
    bullet(GameObject* parent);

    //�f�X�g���N�^
    ~bullet();

    //������
    void Initialize()override;

    //�X�V
    void Update()override;

    //�`��
    void Draw()override;

    //�J��
    void Release()override;
};