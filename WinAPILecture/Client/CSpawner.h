#pragma once



class CSpawner
{
private:
	MONSTER_TYPE	m_eMonsterType;			// ���� ��ȯ���� ����
	float			m_fGenSpeed;			// �� �ӵ�
	float			m_fCurTime;				// ���� �ð�
	
											// ��� ��ġ�� ������ ��
	
	float m_test;

public:
	void update();


public:
	void Set_MonsterType(MONSTER_TYPE _eMonsterType);


private:
	void CreateMonster();
	void CreateBallMan();
	Vec2 GenerateRandomPos();

public:
	CSpawner();
	~CSpawner();

};

