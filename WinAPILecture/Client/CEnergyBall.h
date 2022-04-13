#pragma once

#include "CSkill.h"

class CEnergyBall :
	public CSkill
{
private:
	float               m_fCurSkillDir;		// 스킬 방향
	float				m_fSpeed;      // 투사체 스피드
	float				m_fRange;      // 투사체 거리

public:
	virtual void update();

public:
	void CreateMissile();

public:
	CEnergyBall(float _fCoolDown, float _fSpeed, float _fRange);
	~CEnergyBall();

};

