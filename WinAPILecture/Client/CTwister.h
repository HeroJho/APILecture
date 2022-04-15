#pragma once
#include "CObject.h"

class CTexture;
class Creature;

class CTwister :
	public CObject
{
private:
    Creature*    m_pOwner;      // 투사체 오너
    float        m_fSpeed;      // 투사체 스피드
    float        m_fRange;      // 투사체 거리
    Vec2         m_vInitPos;    // 초기 위치

    float   m_fTheta;           // 이동 방향
    Vec2    m_vDir;             // 이동 방향

private:
    CTexture* m_pTex;

public:
    void SetDir(float _fTheta) { m_fTheta = _fTheta; }
    void SetDir(Vec2 _vDir)
    {
        m_vDir = _vDir;
        m_vDir.Normalize();
    }

public:
    virtual void update();
    virtual void render(HDC _dc);

public:
    virtual void OnCollisionEnter(CCollider* _pOther);

    CLONE(CTwister)
public:
    CTwister(Creature* _pOwner, float _fRange);
    ~CTwister();

};

