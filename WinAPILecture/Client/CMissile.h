#pragma once
#include "CObject.h"

class CTexture;
class Creature;

class CMissile :
    public CObject
{
private:
    Creature*    m_pOwner;      // ����ü ����
    float        m_fSpeed;      // ����ü ���ǵ�
    float        m_fRange;      // ����ü �Ÿ�
    Vec2         m_vInitPos;    // �ʱ� ��ġ

    float   m_fTheta;           // �̵� ����
    Vec2    m_vDir;             // �̵� ����

private:
    CTexture* m_pTex;

public:
    void SetDir(float _fTheta) { m_fTheta = _fTheta; }
    void SetDir(Vec2 _vDir) 
    { 
        m_vDir = _vDir; 
        m_vDir.Normalize();
    }

    void Init(Creature* _pOwner, float _fRange, float _fSpeed);

public:
    virtual void update();
    virtual void render(HDC _dc);

public:
    virtual void OnCollisionEnter(CCollider* _pOther);

    CLONE(CMissile)
public:
    CMissile(Creature* _pOwner, float _fRange, float _fSpeed);
    ~CMissile();

};

