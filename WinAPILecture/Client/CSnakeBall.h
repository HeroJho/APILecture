#pragma once
#include "CObject.h"

class CTexture;
class Creature;


class CSnakeBall :
    public CObject
{
private:
    Creature* m_pOwner;             // 투사체 오너
    CSnakeBall* m_pNextSankeBall;


private:
    CTexture* m_pTex;


public:
    virtual void update();
    virtual void render(HDC _dc);

public:
    virtual void OnCollisionEnter(CCollider* _pOther);

    CLONE(CSnakeBall)

public:
    CSnakeBall(Creature* _pOwner, CSnakeBall* _pNextSankeBall);
    ~CSnakeBall();

};

