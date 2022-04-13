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
    // ü��, �ִ�ü��, ���ݷ�, ����
    CreatureInfo* m_sInfo;

public:
    void Attacked(Creature* _pAttacker);
    bool IsDead() { return 0 >= m_sInfo->m_iHp; }
   

public:
    Creature();
    virtual ~Creature();
};

