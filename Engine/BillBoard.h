#pragma once
#include "Direct3D.h"
#include "Texture.h"
#include <DirectXMath.h>
#include <string>
using namespace DirectX;

//�R���X�^���g�o�b�t�@�[
struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;
	XMFLOAT4	color;
};

//���_���
struct VERTEX
{
	XMFLOAT3 position;
	XMFLOAT3 uv;
};


//��ɃJ�����̕��������l�p�`�|���S��
class BillBoard
{
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;	//�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@

	Texture* pTexture_;	//�摜

public:
	BillBoard();
	~BillBoard();

	//���[�h
	//�����FfileName	�摜�t�@�C����
	//�ߒl�F����/���s
	HRESULT Load(std::string fileName);

	//�`��
	//�����Fmatrix	�ϊ��s��i���[���h�s��j
	//�����Fcolor	�F
	void Draw(XMMATRIX matWorld, XMFLOAT4 color);

	//���
	void Release();
};