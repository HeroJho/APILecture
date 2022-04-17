#pragma once



class CSpawner
{
private:
	MONSTER_TYPE	m_eMonsterType;			// 현재 소환중인 몬스터
	float			m_fGenSpeed;			// 젠 속도
	UINT			m_iCount;				// 젠 속도당 마릿수

	float			m_fCurTime;				// 누적 시간
	float			m_fSpawnTheta;			// 플레이어 기준 스폰 위치

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

