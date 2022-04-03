#pragma once

class CCollider;

class CObject
{
private:
	Vec2	m_vPos;
	Vec2	m_vScale;

	// 상속을 통해 구현하면 끝도없다 >> 유지보수가 힘들다
	// 컴포넌트(부품)형태로 구현한다 >> 필요하면 가지고, 필요없으면 안가진다
	CCollider* m_pCollider;

public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }

	CCollider* GetCollider() { return m_pCollider; }

	void CreateCollider();				// 콜라이더 컴포넌트 생성 함수

public:
	virtual void update() = 0;
	virtual void finalupdate() final; // 자식이 상속되지 않게 해야한다! 다른 프로그래머가 자식에 오버라이딩 못하게 final키워드로 막는다
	virtual void render(HDC _dc);
	void component_render(HDC _dc);



public:
	CObject();
	virtual ~CObject();

};

