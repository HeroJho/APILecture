#pragma once



class CSpawner
{
private:
	MONSTER_TYPE	m_eMonsterType;			// ���� ��ȯ���� ����
	float			m_fGenSpeed;			// �� �ӵ�
	UINT			m_iCount;				// �� �ӵ��� ������

	float			m_fCurTime;				// ���� �ð�
	float			m_fSpawnTheta;			// �÷��̾� ���� ���� ��ġ

public:
	void Init(MONSTER_TYPE _eMonsterType, float _fGenSpeed, UINT _iCount);
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

