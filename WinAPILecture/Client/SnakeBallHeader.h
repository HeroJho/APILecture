#pragma once
#include "CObject.h"

class CTexture;
class Creature;
class CSnakeBall;

class SnakeBallHeader :
    public CObject
{
private:
    Creature*    m_pOwner;      // ����ü ����
    
    CSnakeBall*   m_pNextSankeBall;
    
    float        m_fSpeed;      // ����ü ���ǵ�
    float        m_fRange;      // ����ü �Ÿ�

    float   m_fTheta;           // �̵� ����
    Vec2    m_vDir;             // �̵� ����
    UINT    m_iCheckDir;        // �� ȭ�� ������ ������ �ٵ�ٵ� ����

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

