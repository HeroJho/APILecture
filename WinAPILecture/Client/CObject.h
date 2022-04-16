#pragma once


#include "CCamera.h"

class CCollider;
class CAnimator;
class CPooling;

class CObject
{
private:
	wstring	m_strName;	// 자식 객체 구분용 이름

	Vec2	m_vPos;
	Vec2	m_vScale;

	// 상속을 통해 구현하면 끝도없다 >> 유지보수가 힘들다
	// 컴포넌트(부품)형태로 구현한다 >> 필요하면 가지고, 필요없으면 안가진다
	CCollider*	m_pCollider;
	CAnimator*	m_pAnimator;
	CPooling*	m_pPooling;

	bool		m_bAlive;	// 활성화인지 비활성화인지(삭제 예정)

public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }

	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName;}

	CCollider* GetCollider() { return m_pCollider; }
	CAnimator* GetAnimator() { return m_pAnimator; }
	CPooling* GetPooling() { return m_pPooling; }

	bool IsDead() { return !m_bAlive; }

	void CreateCollider();				// 콜라이더 컴포넌트 생성 함수
	void CreateAnimator();				// 애니메터 컴포넌트 생성 함수
	void CreatePooling(POOLING_TYPE _ePoolingType);				// 풀링 가능한 오브젝트면 가지는 컴포넌트

	virtual void OnCollision(CCollider* _pOther) {}
	virtual void OnCollisionEnter(CCollider* _pOther) {}
	virtual void OnCollisionExit(CCollider* _pOther) {}

private:
	void SetDead() { m_bAlive = false; }		// 오로지 EVenMgr를 통해 삭제 가능

public:
	virtual void update() = 0;
	virtual void finalupdate(); // final; // 자식이 상속되지 않게 해야한다! 다른 프로그래머가 자식에 오버라이딩 못하게 final키워드로 막는다
	virtual void render(HDC _dc);

	void component_render(HDC _dc);

	virtual CObject* Clone() = 0;		// 자기자시늘 복제

public:
	CObject();
	CObject(const CObject& _origin);	// 콜라이더 깊은 복사
	virtual ~CObject();

	friend class CEvenMgr;
};

