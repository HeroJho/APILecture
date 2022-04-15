#pragma once
#include "CSkill.h"

class CTwister;

class CTwisterSkill :
    public CSkill
{
private:
	vector<CTwister*>	m_vecTwister;
	
	float               m_fCurSkillDir;		// 스킬 방향
	float				m_fSpeed;			// 투사체 스피드
	float				m_fRange;			// 투사체 거리
	UINT				m_iCount;			// 갯수

public:
	virtual void update();

public:
	void CreateTwister();

public:
	CTwisterSkill(float _fCoolDown, float _fSpeed, float _fRange, UINT _iCount);
	~CTwisterSkill();
};

