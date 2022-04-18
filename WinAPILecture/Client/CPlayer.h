#pragma once
#include "Creature.h"

class CTexture;

class CPlayer :
    public Creature
{
private:

   

public:
    virtual void CreatureUpdate();
    virtual void render(HDC _dc);
    virtual void Die();

private:
    void SkillUpdate();

    virtual void OnCollision(CCollider* _pOther);
    virtual void OnCollisionEnter(CCollider* _pOther);

    CLONE(CPlayer)
public:
    CPlayer(CreatureInfo* _sInfo);
    ~CPlayer();
};

