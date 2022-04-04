#pragma once

class CObject;

class CCollider
{
private:
	static UINT g_iNextID;

	CObject* m_pOwner;			// 콜라이더를 소유하고있는 객체
	Vec2	m_vOffsetPos;		// 상대거리
	Vec2	m_vFinalPos;		// 최종 위치
	Vec2	m_vScale;			// 충돌체 크기 정보

	UINT	m_iID;				// 충돌체 고유한 ID 값
	int		m_iCol;				// 충돌에 따른 콜라이더 색상 변화

public:
	void SetOffsetPos(Vec2 _vPos) { m_vOffsetPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 GetOffsetPos() { return m_vOffsetPos; }
	Vec2 GetScale() { return m_vScale; }

	Vec2 GetFinalPos() { return m_vFinalPos; }

	CObject* GetObj() { return m_pOwner; }

	UINT GetID() { return m_iID; }

public:
	void finalupdate();
	void render(HDC _dc);

public:
	// 충돌 시점 함수
	void OnCollision(CCollider* _pOther);			// 충돌중인 경우 호출되는 함수
	void OnCollisionEnter(CCollider* _pOther);		// 충돌 진입 시
	void OnCollisionExit(CCollider* _pOther);		// 충돌 해제 시



	CCollider& operator = (CCollider& _origin) = delete;	// 디폴트 대입연산자 함수를 만들지 못 하게 >> 대입 불가능!

public:
	CCollider();
	CCollider(const CCollider& _origin);	// 복사할 때 아이디 값 겹침 >> 깊은 복사를 해줘야함
	~CCollider();

	friend class CObject;
};

