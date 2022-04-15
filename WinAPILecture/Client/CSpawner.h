#pragma once



class CSpawner
{
private:
	MONSTER_TYPE	m_eMonsterType;			// 현재 소환중인 몬스터
	float			m_fGenSpeed;			// 젠 속도
	float			m_fCurTime;				// 누적 시간
	
											// 어느 위치에 생성할 지
	
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

