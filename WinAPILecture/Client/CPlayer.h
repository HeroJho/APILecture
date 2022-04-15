#pragma once
#include "Creature.h"

class CTexture;

class CPlayer :
    public Creature
{
private:

   

public:
    virtual void update();
    virtual void render(HDC _dc);

private:
    void SkillUpdate();


    CLONE(CPlayer)
public:
    CPlayer(CreatureInfo* _sInfo);
    ~CPlayer();
};

