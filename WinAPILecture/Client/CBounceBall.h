#pragma once
#include "CObject.h"

class CTexture;
class Creature;


class CBounceBall :
    public CObject
{
private:
    Creature*       m_pOwner;           // 투사체 오너
    float           m_fTheta;           // 던지는 각도
    float           m_fPower;           // 던지는 힘

    float           m_fDuration;        // 지속 시간
    float           m_fCurTime;         // 누적 시간

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

