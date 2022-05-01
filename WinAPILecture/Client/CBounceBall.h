#pragma once
#include "CObject.h"

class CTexture;
class Creature;


class CBounceBall :
    public CObject
{
private:
    Creature*       m_pOwner;           // ����ü ����
    float           m_fTheta;           // ������ ����
    float           m_fPower;           // ������ ��

    float           m_fDuration;        // ���� �ð�
    float           m_fCurTime;         // ���� �ð�

private:
    CTexture* m_pTex;

public:


public:
    virtual void update();
    virtual void render(HDC _dc);

public:
    virtual void OnCollisionEnter(CCollider* _pOther);

    CLONE(CBounceBall)
public:
    CBounceBall(Creature* _pOwner);
    ~CBounceBall();

};

