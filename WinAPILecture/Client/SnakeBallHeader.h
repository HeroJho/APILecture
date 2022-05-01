#pragma once
#include "CObject.h"

class CTexture;
class Creature;
class CSnakeBall;

class SnakeBallHeader :
    public CObject
{
private:
    Creature*    m_pOwner;      // 투사체 오너
    
    CSnakeBall*   m_pNextSankeBall;
    
    float        m_fSpeed;      // 투사체 스피드
    float        m_fRange;      // 투사체 거리

    float   m_fTheta;           // 이동 방향
    Vec2    m_vDir;             // 이동 방향
    UINT    m_iCheckDir;        // 공 화면 밖으로 나가면 바들바들 방지

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

    CLONE(SnakeBallHeader)
public:
    SnakeBallHeader(Creature* _pOwner, float _fSpeed);
    ~SnakeBallHeader();

};

