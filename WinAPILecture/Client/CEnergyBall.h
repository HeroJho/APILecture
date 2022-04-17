#pragma once


class CEnergyBall
{
private:

	SKILL_LEVEL			m_eLevel;
	float				m_fCurCool;			// �ð� ����
	float               m_fCoolDown;		// ���� �ӵ�
	float               m_fCurSkillDir;		// ��ų ����
	float				m_fSpeed;			// ����ü ���ǵ�
	float				m_fRange;			// ����ü �Ÿ�


public:
	virtual void update();

public:
	void CreateMissile();
	void Upgrade();

private:
	void SetSkill_One();
	void SetSkill_Two();
	void SetSkill_Three();
	void SetSkill_Four();
	void SetSkill_Five();

public:
	CEnergyBall();
	~CEnergyBall();

};

