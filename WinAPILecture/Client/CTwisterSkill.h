#pragma once

class CTwister;

class CTwisterSkill
{
private:
	vector<CTwister*>	m_vecTwister;

	SKILL_LEVEL			m_eLevel;
	float				m_fCurCool;			// 시간 누적
	float               m_fCoolDown;		// 공격 속도
	float               m_fCurSkillDir;		// 스킬 방향
	float				m_fSpeed;			// 투사체 스피드
	float				m_fRange;			// 투사체 거리
	UINT				m_iCount;			// 갯수

public:
	virtual void update();

public:
	void CreateTwister();
	void Upgrade();

private:
	void SetSkill_One();
	void SetSkill_Two();
	void SetSkill_Three();
	void SetSkill_Four();
	void SetSkill_Five();

	

public:
	CTwisterSkill();
	~CTwisterSkill();
};

