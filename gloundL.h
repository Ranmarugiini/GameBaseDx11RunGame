#pragma once
#include"Engine/GameObject.h"
class gloundL :public GameObject
{
    int hModel_;
public:
    //�R���X�g���N�^
    gloundL(GameObject* parent);

    //�f�X�g���N�^
    ~gloundL();

    //������
    void Initialize()override;

    //�X�V
    void Update()override;

    //�`��
    void Draw()override;

    //�J��
    void Release()override;
};


