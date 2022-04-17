#pragma once
#include "CObject.h"

struct CreatureInfo
{
    int m_iHp;
    int m_iMaxHp;
    int m_iAt;
    int m_iDt;

    CreatureInfo(int _iMaxHp, int _iAt, int _iDt)
        : m_iHp(_iMaxHp)
        , m_iMaxHp(_iMaxHp)
        , m_iAt(_iAt)
        , m_iDt(_iDt)
    {}
};

class Creature :
    public CObject
{
protected:
    // 체력, 최대체력, 공격력, 방어력
    CreatureInfo* m_sInfo;

    float   m_fTheta;           // 이동 방향
    Vec2    m_vDir;             // 이동 방향

    bool    m_bIsDie;

public:
    void Attacked(Creature* _pAttacker);
    bool IsHpZero() { return 0 >= m_sInfo->m_iHp; }
   
    virtual void Die() = 0;

public:
    void SetDir(float _fTheta) { m_fTheta = _fTheta; }
    void SetDir(Vec2 _vDir)
    {
        m_vDir = _vDir;
        m_vDir.Normalize();
    }


public:
    Creature();
    virtual ~Creature();
};

