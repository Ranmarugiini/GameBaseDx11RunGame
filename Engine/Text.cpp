#include <stdlib.h>
#include "Direct3D.h"
#include "Text.h"

Text::Text() : hPict_(-1), width_(16), height_(32), fileName_("char.png"), rowLength_(16)
{
}

Text::~Text()
{
}

//�������i�f�t�H���g�j
HRESULT Text::Initialize()
{
	hPict_ = Image::Load(fileName_);
	assert(hPict_ >= 0);

	if (hPict_ < 0)
		return E_FAIL;

	return S_OK;
}

//�������i�I���W�i���̉摜�j
HRESULT Text::Initialize(const char* fileName, const unsigned int charWidth, const unsigned int charHeight, const unsigned int rowLength)
{
	strcpy_s(fileName_, fileName);
	width_ = charWidth;
	height_ = charHeight;
	rowLength_ = rowLength;
	return Initialize();
}


//�`��i������j
void Text::Draw(int x, int y, const char* str)
{
	//�\���ʒu�i����j���v�Z
	//Sprite�N���X�͒��S��(0,0)�A�E�オ(1,1)�Ƃ������W�����A�����̈����͍����(0,0)�A�h�b�g�P�ʂŎw�肵�Ă���
	float px, py;

	//�����͍��㌴�_�����A�X�v���C�g�͉�ʒ��������_�Ȃ̂ŁA��ʃT�C�Y�̔������炷
	px = (float)(x - Direct3D::screenWidth_ / 2);
	py = (float)(-y + Direct3D::screenHeight_ / 2);	//Y����+-���]

	//�X�v���C�g��Position��1���炷�Ɖ�ʃT�C�Y�̔��������̂ŁA�s�N�Z���P�ʂɕϊ�
	px /= (float)(Direct3D::screenWidth_ / 2.0f);
	py /= (float)(Direct3D::screenHeight_ / 2.0f);


	//�P�������\������
	for (int i = 0; str[i] != '\0'; i++)	//������̖����܂ŗ�����I���
	{
		//�\���������������A�摜�̉��Ԗڂɏ����Ă��邩�����߂�
		int id = str[i] - '!';		//�\�������������̃R�[�h����u!�v�̃R�[�h���������ƂŁA!��0�A"=1�A#��2����Ƃ����ԍ��ɂ���

		//�\���������������A�摜�̂ǂ��ɂ��邩�����߂�
		int x = id % rowLength_;	//�����牽�Ԗ�
		int y = id / rowLength_;	//�ォ�牽�Ԗ�

		//�\������ʒu
		Transform transform;
		transform.position_.x = px;
		transform.position_.y = py;
		Image::SetTransform(hPict_, transform);

		//�\������͈�
		Image::SetRect(hPict_, width_ * x, height_ * y, width_, height_);
		
		//�\��
		Image::Draw(hPict_);

		//���̈ʒu�ɂ��炷
		px += width_ / (float)(Direct3D::screenWidth_ / 2.0f);
	}
}

//�`��i�����l�j
void Text::Draw(int x, int y, int value)
{
	//������ɕϊ�
	char str[256];
	sprintf_s(str, "%d", value);

	Draw(x, y, str);
}

//���
void Text::Release()
{
	Image::Release(hPict_);
}
