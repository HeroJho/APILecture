#pragma once

class CTTengBall;

class CTTengBallSkill
{
private:
	vector<CTTengBall*>	m_vecTTengBall;

	SKILL_LEVEL			m_eLevel;
	float				m_fSpeed;			// ����ü ���ǵ�
	UINT				m_iCount;			// ����

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

