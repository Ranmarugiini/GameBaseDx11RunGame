#pragma once
#include"Engine/GameObject.h"
class object1:public GameObject
{
	int hModel_;
public:
    //�R���X�g���N�^
    object1(GameObject* parent);

    //�f�X�g���N�^
    ~object1();

    //������
    void Initialize()override;

    //�X�V
    void Update()override;

    //�`��
    void Draw()override;

    //�J��
    void Release()override;
};

