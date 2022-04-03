#pragma once

class CObject;

class CCollider
{
private:
	CObject* m_pOwner;			// �ݶ��̴��� �����ϰ��ִ� ��ü

	Vec2	m_vOffsetPos;		// ���Ÿ�
	Vec2	m_vFinalPos;		// ���� ��ġ

	Vec2	m_vScale;			// �浹ü ũ�� ����

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
