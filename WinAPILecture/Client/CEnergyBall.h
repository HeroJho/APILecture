#pragma once

#include "CSkill.h"

class CEnergyBall :
	public CSkill
{
private:
	float               m_fCurSkillDir;		// ��ų ����
	float				m_fSpeed;      // ����ü ���ǵ�
	float				m_fRange;      // ����ü �Ÿ�

public:
	virtual void update();

public:
	void CreateMissile();

public:
	CEnergyBall(float _fCoolDown, float _fSpeed, float _fRange);
	~CEnergyBall();

};

