#pragma once


class CSkill
{
protected:
	float				m_fCurCool;			// �ð� ����
	float               m_fCoolDown;		// ���� �ӵ�

public:
	virtual void update() = 0;

public:
	void SetStat(float _fCoolDown);

public:
	CSkill(float _fCoolDown);
	~CSkill();

};

