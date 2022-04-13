#pragma once
#include "Creature.h"

class CTexture;

class CMonster :
    public Creature
{
private:
    Vec2    m_vCenterPos;
    float   m_fSpeed;
    float   m_fMaxDistance;
    int     m_iDir;             // 진행 방향

private:
    CTexture* m_pTex;


public:
    float GetSpeed() { return m_fSpeed; }
    void SetSpeed(float _f) { m_fSpeed = _f; }
    void SetMoveDistance(float _f) { m_fMaxDistance = _f; }
    void SetCenterPos(Vec2 _vPos) { m_vCenterPos = _vPos; }

    virtual void OnCollision(CCollider* _pOther);
    virtual void OnCollisionEnter(CCollider* _pOther);
    

public:
    virtual void update();
    virtual void render(HDC _dc);

    CLONE(CMonster)
public:
    CMonster(CreatureInfo* _sInfo);
    ~CMonster();
};

