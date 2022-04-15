#pragma once
#include "CSkill.h"

class CTwister;

class CTwisterSkill :
    public CSkill
{
private:
	vector<CTwister*>	m_vecTwister;
	
	float               m_fCurSkillDir;		// ��ų ����
	float				m_fSpeed;			// ����ü ���ǵ�
	float				m_fRange;			// ����ü �Ÿ�
	UINT				m_iCount;			// ����

public:
	virtual void update();

public:
	void CreateTwister();

public:
	CTwisterSkill(float _fCoolDown, float _fSpeed, float _fRange, UINT _iCount);
	~CTwisterSkill();
};

