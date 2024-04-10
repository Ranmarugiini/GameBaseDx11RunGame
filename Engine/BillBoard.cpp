#include "BillBoard.h"
#include "Camera.h"
#include "Global.h"

BillBoard::BillBoard():
	pVertexBuffer_(nullptr), pIndexBuffer_(nullptr), pConstantBuffer_(nullptr), pTexture_(nullptr)
{
}

BillBoard::~BillBoard()
{
}

//�摜�����[�h���ă|���S�����쐬
HRESULT BillBoard::Load(std::string fileName)
{
	HRESULT hr;

	// ���_���
	VERTEX vertices[] =
	{
		{ XMFLOAT3(-0.5f, 0.5f, 0.0f),XMFLOAT3(0.0f, 0.0f, 0.0f) },   // �l�p�`�̒��_�i����j
		{ XMFLOAT3(0.5f, 0.5f, 0.0f),	XMFLOAT3(1.0f, 0.0f, 0.0f) },   // �l�p�`�̒��_�i�E��j
		{ XMFLOAT3(0.5f, -0.5f, 0.0f),	XMFLOAT3(1.0f, 1.0f, 0.0f) },   // �l�p�`�̒��_�i�E���j
		{ XMFLOAT3(-0.5f, -0.5f, 0.0f),XMFLOAT3(0.0f, 1.0f, 0.0f) },   // �l�p�`�̒��_�i�����j
	};

	// ���_�f�[�^�p�o�b�t�@�̐ݒ�
	D3D11_BUFFER_DESC bd_vertex;
	bd_vertex.ByteWidth = sizeof(vertices);
	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd_vertex.CPUAccessFlags = 0;
	bd_vertex.MiscFlags = 0;
	bd_vertex.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA data_vertex;
	data_vertex.pSysMem = vertices;
	hr = Direct3D::pDevice_->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_);
	if (FAILED(hr))
	{
		return hr;
	}



	//�C���f�b�N�X���
	int index[] = { 0,2,3, 0,1,2 };

	// �C���f�b�N�X�o�b�t�@�𐶐�����
	D3D11_BUFFER_DESC   bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(index);
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = index;
	InitData.SysMemPitch = 0;
	InitData.SysMemSlicePitch = 0;
	hr = Direct3D::pDevice_->CreateBuffer(&bd, &InitData, &pIndexBuffer_);
	if (FAILED(hr))
	{
		return hr;
	}

	//�R���X�^���g�o�b�t�@�쐬
	D3D11_BUFFER_DESC cb;
	cb.ByteWidth = sizeof(CONSTANT_BUFFER);
	cb.Usage = D3D11_USAGE_DYNAMIC;
	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	cb.MiscFlags = 0;
	cb.StructureByteStride = 0;

	// �R���X�^���g�o�b�t�@�̍쐬
	Direct3D::pDevice_->CreateBuffer(&cb, nullptr, &pConstantBuffer_);


	//�e�N�X�`��
	pTexture_ = new Texture;
	pTexture_->Load(fileName.c_str());

	return S_OK;
}


//�`��
void BillBoard::Draw(XMMATRIX matWorld, XMFLOAT4 color)
{
	//�R���X�^���g�o�b�t�@�ɓn�����
	CONSTANT_BUFFER cb;
	cb.matWVP = XMMatrixTranspose(matWorld * Camera::GetViewMatrix() * Camera::GetProjectionMatrix());
	cb.color = color;

	D3D11_MAPPED_SUBRESOURCE pdata;
	Direct3D::pContext_->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPU����̃f�[�^�A�N�Z�X���~�߂�
	memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));	// �f�[�^��l�𑗂�

	ID3D11SamplerState* pSampler = pTexture_->GetSampler();
	Direct3D::pContext_->PSSetSamplers(0, 1, &pSampler);

	ID3D11ShaderResourceView* pSRV = pTexture_->GetSRV();
	Direct3D::pContext_->PSSetShaderResources(0, 1, &pSRV);

	Direct3D::pContext_->Unmap(pConstantBuffer_, 0);	//�ĊJ



	//���_�o�b�t�@
	UINT stride = sizeof(VERTEX);
	UINT offset = 0;
	Direct3D::pContext_->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);

	// �C���f�b�N�X�o�b�t�@�[���Z�b�g
	stride = sizeof(int);
	offset = 0;
	Direct3D::pContext_->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);

	//�R���X�^���g�o�b�t�@
	Direct3D::pContext_->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//���_�V�F�[�_�[�p	
	Direct3D::pContext_->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//�s�N�Z���V�F�[�_�[�p

	Direct3D::pContext_->DrawIndexed(6, 0, 0);
}


//���
void BillBoard::Release()
{
	SAFE_DELETE(pTexture_);
	SAFE_RELEASE(pConstantBuffer_);
	SAFE_RELEASE(pIndexBuffer_);
	SAFE_RELEASE(pVertexBuffer_);
}