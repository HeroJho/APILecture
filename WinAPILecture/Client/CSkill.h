#pragma once


class CSkill
{
protected:
	float				m_fCurCool;			// 시간 누적
	float               m_fCoolDown;		// 공격 속도

public:
	virtual void update() = 0;

public:
	void SetStat(float _fCoolDown);

public:
	CSkill(float _fCoolDown);
	~CSkill();

};

