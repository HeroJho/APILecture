#pragma once
#include "Creature.h"

class CTexture;

class CMonster :
    public Creature
{
private:
    float   m_fSpeed;
    bool    m_bIsOnMonster;

private:
    CTexture* m_pTex;


public:
    float GetSpeed() { return m_fSpeed; }
    void SetSpeed(float _f) { m_fSpeed = _f; }
    void SetIsOnMonster(bool _bIsOnMonster) { m_bIsOnMonster = _bIsOnMonster; }


public:
    virtual void OnCollision(CCollider* _pOther);
    virtual void OnCollisionEnter(CCollider* _pOther);
    virtual void OnCollisionExit(CCollider* _pOther);
    

public:
    virtual void CreatureUpdate();
    virtual void render(HDC _dc);
    virtual void Die();

    CLONE(CMonster)
public:
    CMonster(CreatureInfo* _sInfo);
    ~CMonster();
};

