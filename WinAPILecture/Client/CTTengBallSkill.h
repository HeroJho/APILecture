#pragma once

class CTTengBall;

class CTTengBallSkill
{
private:
	vector<CTTengBall*>	m_vecTTengBall;

	SKILL_LEVEL			m_eLevel;
	float				m_fSpeed;			// 투사체 스피드
	UINT				m_iCount;			// 갯수

public:
	virtual void update();

public:
	void CreateTTengBall();
	void Upgrade();

private:
	void SetSkill_One();
	void SetSkill_Two();
	void SetSkill_Three();
	void SetSkill_Four();
	void SetSkill_Five();



public:
	CTTengBallSkill();
	~CTTengBallSkill();
};

