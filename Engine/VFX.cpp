#include "VFX.h"
#include "Camera.h"

namespace VFX
{
    std::list<Emitter*>		emitterList_;	//�G�~�b�^�[�B
    std::list<Particle*>	particleList_;	//�p�[�e�B�N���B
};

//�X�V
void VFX::Update()
{
    //�e�G�~�b�^�[�̏���
    EmitterUpdate();

    //�e�p�[�e�B�N���̏���
    ParticleUpdate();
}


//�������̃p�[�e�B�N���̍X�V
void VFX::ParticleUpdate()
{
    for (auto particle = particleList_.begin(); particle != particleList_.end();)
    {
        //�������s�����̂ŏ���
        if ((*particle)->life == 0)
        {
            (*particle)->pEmitter->particleNum--;
            delete (*particle);
            particle = particleList_.erase(particle);
        }

        //�܂������Ă�
        else
        {
            (*particle)->life--;
            (*particle)->now.position.x += (*particle)->delta.position.x;
            (*particle)->now.position.y += (*particle)->delta.position.y;
            (*particle)->now.position.z += (*particle)->delta.position.z;
            (*particle)->delta.position.x *= (*particle)->accel;
            (*particle)->delta.position.y *= (*particle)->accel;
            (*particle)->delta.position.z *= (*particle)->accel;
            (*particle)->delta.position.y -= (*particle)->gravity;

            (*particle)->now.rotation.x += (*particle)->delta.rotation.x;
            (*particle)->now.rotation.y += (*particle)->delta.rotation.y;
            (*particle)->now.rotation.z += (*particle)->delta.rotation.z;

            (*particle)->now.scale.x *= (*particle)->delta.scale.x;
            (*particle)->now.scale.y *= (*particle)->delta.scale.y;
            (*particle)->now.color.x += (*particle)->delta.color.x; //R
            (*particle)->now.color.y += (*particle)->delta.color.y; //G
            (*particle)->now.color.z += (*particle)->delta.color.z; //B
            (*particle)->now.color.w += (*particle)->delta.color.w; //A

            particle++;
        }
    }
}


//�e�G�~�b�^�̍X�V
void VFX::EmitterUpdate()
{
    for (auto emitter = emitterList_.begin(); emitter != emitterList_.end();)
    {
        //��������ł�G�~�b�^�[
        if ((*emitter)->isDead)
        {
            //���̃G�~�b�^�[����o���p�[�e�B�N�����S�������Ă���G�~�b�^�[���폜
            if ((*emitter)->particleNum <= 0)
            {
                (*emitter)->pBillBoard->Release();
                delete ((*emitter)->pBillBoard);
                delete (*emitter);
                emitter = emitterList_.erase(emitter);
            }
            else
            {
                emitter++;
            }
        }

        //�܂������Ă�
        else
        {
            //�p�[�e�B�N���𔭐�������^�C�~���O�Ȃ�
            if ((*emitter)->data.delay == 0 || (*emitter)->frameCount % (*emitter)->data.delay == 0)
            {
                //�p�[�e�B�N������
                CreateParticle(emitter);
            }

            (*emitter)->frameCount++;


            //delay��0�̃G�~�b�^�[�͂P���o������폜
            if ((*emitter)->data.delay == 0)
            {
                (*emitter)->isDead = true;

            }

            emitter++;
        }
    }
}

//�p�[�e�B�N������
void VFX::CreateParticle(std::list<VFX::Emitter*>::iterator& emitter)
{
    //�w�����
    for (DWORD i = 0; i < (*emitter)->data.number; i++)
    {
        //�p�[�e�B�N������
        Particle* pParticle = new Particle;

        //����
        {
            //�ʒu
            pParticle->now.position = (*emitter)->data.position;
            float dx = (float)((*emitter)->data.positionRnd.x == 0 ? 0 : rand() % (int)((*emitter)->data.positionRnd.x * 201) - ((*emitter)->data.positionRnd.x * 100)) / 100.0f;
            float dy = (float)((*emitter)->data.positionRnd.y == 0 ? 0 : rand() % (int)((*emitter)->data.positionRnd.y * 201) - ((*emitter)->data.positionRnd.y * 100)) / 100.0f;
            float dz = (float)((*emitter)->data.positionRnd.z == 0 ? 0 : rand() % (int)((*emitter)->data.positionRnd.z * 201) - ((*emitter)->data.positionRnd.z * 100)) / 100.0f;
            pParticle->now.position.x += dx;
            pParticle->now.position.y += dy;
            pParticle->now.position.z += dz;

            //�F
            pParticle->now.color = (*emitter)->data.color;

            //�g�嗦
            dx = (float)((*emitter)->data.sizeRnd.x == 0 ? 0 : rand() % (int)((*emitter)->data.sizeRnd.x * 201) - ((*emitter)->data.sizeRnd.x * 100)) / 100.0f + 1.0f;
            dy = (float)((*emitter)->data.sizeRnd.y == 0 ? 0 : rand() % (int)((*emitter)->data.sizeRnd.y * 201) - ((*emitter)->data.sizeRnd.y * 100)) / 100.0f + 1.0f;
            pParticle->now.scale.x = (*emitter)->data.size.x * dx;
            pParticle->now.scale.y = (*emitter)->data.size.y * dy;

            //��]
            pParticle->now.rotation = (*emitter)->data.rotate;
            dx = (float)((*emitter)->data.rotateRnd.x == 0 ? 0 : rand() % (int)((*emitter)->data.rotateRnd.x * 201) - ((*emitter)->data.rotateRnd.x * 100)) / 100.0f;
            dy = (float)((*emitter)->data.rotateRnd.y == 0 ? 0 : rand() % (int)((*emitter)->data.rotateRnd.y * 201) - ((*emitter)->data.rotateRnd.y * 100)) / 100.0f;
            dz = (float)((*emitter)->data.rotateRnd.z == 0 ? 0 : rand() % (int)((*emitter)->data.rotateRnd.z * 201) - ((*emitter)->data.rotateRnd.z * 100)) / 100.0f;
            pParticle->now.rotation.x += dx;
            pParticle->now.rotation.y += dy;
            pParticle->now.rotation.z += dz;
        }

        //�ω���
        {
            //�ړ�����
            XMVECTOR vecDir = XMLoadFloat3(&(*emitter)->data.direction);
            float dx = (float)((*emitter)->data.directionRnd.x == 0 ? 0 : rand() % (int)((*emitter)->data.directionRnd.x * 201) - ((*emitter)->data.directionRnd.x * 100)) / 100.0f;
            float dy = (float)((*emitter)->data.directionRnd.y == 0 ? 0 : rand() % (int)((*emitter)->data.directionRnd.y * 201) - ((*emitter)->data.directionRnd.y * 100)) / 100.0f;
            float dz = (float)((*emitter)->data.directionRnd.z == 0 ? 0 : rand() % (int)((*emitter)->data.directionRnd.z * 201) - ((*emitter)->data.directionRnd.z * 100)) / 100.0f;
            XMMATRIX matRotX = XMMatrixRotationX(XMConvertToRadians(dx));
            XMMATRIX matRotY = XMMatrixRotationY(XMConvertToRadians(dy));
            XMMATRIX matRotZ = XMMatrixRotationZ(XMConvertToRadians(dz));
            vecDir = XMVector3TransformCoord(vecDir, matRotX * matRotY * matRotZ);

            float s = (float)((*emitter)->data.speedRnd == 0 ? 0 : rand() % (int)((*emitter)->data.speedRnd * 201) - ((*emitter)->data.speedRnd * 100)) / 100.0f + 1.0f;
            vecDir = XMVector3Normalize(vecDir) * ((*emitter)->data.speed * s);
            XMStoreFloat3(&pParticle->delta.position, vecDir);

            //�g�嗦
            pParticle->delta.scale = (*emitter)->data.scale;

            pParticle->delta.rotation = (*emitter)->data.spin;

            //�F
            pParticle->delta.color = (*emitter)->data.deltaColor;


        }

        pParticle->life = (*emitter)->data.lifeTime;    //�c�����
        pParticle->gravity = (*emitter)->data.gravity;  //�d��
        pParticle->accel = (*emitter)->data.accel;      //����

        pParticle->pEmitter = *emitter; //������

                                    
        particleList_.push_back(pParticle);    //����

        pParticle->pEmitter->particleNum++; //�������̃p�[�e�B�N�������J�E���g�A�b�v

    }
}

//�p�[�e�B�N���`��
void VFX::Draw()
{
    Direct3D::SetShader(Direct3D::SHADER_BILLBOARD);
    Direct3D::SetBlendMode(Direct3D::BLEND_ADD);

 
    for (auto particle = particleList_.begin(); particle != particleList_.end(); particle++)
    {
        XMMATRIX matWorld;
        XMMATRIX matTrans = XMMatrixTranslation((*particle)->now.position.x, (*particle)->now.position.y, (*particle)->now.position.z);

        XMMATRIX matRotateX = XMMatrixRotationX(XMConvertToRadians((*particle)->now.rotation.x));
        XMMATRIX matRotateY = XMMatrixRotationY(XMConvertToRadians((*particle)->now.rotation.y));
        XMMATRIX matRotateZ = XMMatrixRotationZ(XMConvertToRadians((*particle)->now.rotation.z));
        XMMATRIX matRotate = matRotateZ * matRotateX * matRotateY;

        XMMATRIX matScale = XMMatrixScaling((*particle)->now.scale.x, (*particle)->now.scale.y, 1.0f);

        if ((*particle)->pEmitter->data.isBillBoard)
        {
            matWorld = matScale * matRotate * Camera::GetBillboardMatrix() * matTrans;
        }
        else
        {
            matWorld = matScale * matRotate * matTrans;
        }
        (*particle)->pEmitter->pBillBoard->Draw(matWorld,(*particle)->now.color);
    }

    Direct3D::SetShader(Direct3D::SHADER_3D);
    Direct3D::SetBlendMode(Direct3D::BLEND_DEFAULT);
}

//���
void VFX::Release()
{
    //�S�p�[�e�B�N���폜
    for (auto particle = particleList_.begin(); particle != particleList_.end();)
    {
        delete (*particle);
        particle = particleList_.erase(particle);
    }
    particleList_.clear();

    //�S�G�~�b�^�[�폜
    for (auto emitter = emitterList_.begin(); emitter != emitterList_.end();)
    {
		(*emitter)->pBillBoard->Release();
		delete ((*emitter)->pBillBoard);
		delete (*emitter);
		emitter = emitterList_.erase(emitter);
	}
    emitterList_.clear();
}


//�G�~�b�^�̍쐬
int VFX::Start(EmitterData emitterData)
{
    int handle = 0;
    for (auto i = emitterList_.begin(); i != emitterList_.end(); i++)
    {
        handle++;
    }


    Emitter* pEmitter = new Emitter;

    pEmitter->data = emitterData;
    pEmitter->handle = handle;
    pEmitter->frameCount = 0;

    pEmitter->pBillBoard = new BillBoard;
    pEmitter->pBillBoard->Load(emitterData.textureFileName);

    emitterList_.push_back(pEmitter);

    return handle;
}

//�G�~�b�^�̍폜
void VFX::End(int handle)
{
    for (auto i = emitterList_.begin(); i != emitterList_.end(); i++)
    {
        if ((*i)->handle == handle)
        {
            (*i)->isDead = true;
            break;
        }
    }
}
