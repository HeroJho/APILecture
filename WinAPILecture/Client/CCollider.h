#pragma once

class CObject;

class CCollider
{
private:
	CObject* m_pOwner;			// 콜라이더를 소유하고있는 객체

	Vec2	m_vOffsetPos;		// 상대거리
	Vec2	m_vFinalPos;		// 최종 위치

	Vec2	m_vScale;			// 충돌체 크기 정보

public:
	void SetOffsetPos(Vec2 _vPos) { m_vOffsetPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 GetOffsetPos() { return m_vOffsetPos; }
	Vec2 GetScale() { return m_vScale; }

public:
	void finalupdate();
	void render(HDC _dc);

public:
	CCollider();
	~CCollider();

	friend class CObject;
};

