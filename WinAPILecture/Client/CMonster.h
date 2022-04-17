#pragma once
#include "Creature.h"

class CTexture;

class CMonster :
    public Creature
{
private:
    float   m_fSpeed;

private:
    CTexture* m_pTex;


public:
    float GetSpeed() { return m_fSpeed; }
    void SetSpeed(float _f) { m_fSpeed = _f; }



public:
    virtual void OnCollision(CCollider* _pOther);
    virtual void OnCollisionEnter(CCollider* _pOther);
    

public:
    virtual void update();
    virtual void render(HDC _dc);
    virtual void Die();

    CLONE(CMonster)
public:
    CMonster(CreatureInfo* _sInfo);
    ~CMonster();
};

