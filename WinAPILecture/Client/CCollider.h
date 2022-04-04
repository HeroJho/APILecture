#pragma once

class CObject;

class CCollider
{
private:
	static UINT g_iNextID;

	CObject* m_pOwner;			// �ݶ��̴��� �����ϰ��ִ� ��ü
	Vec2	m_vOffsetPos;		// ���Ÿ�
	Vec2	m_vFinalPos;		// ���� ��ġ
	Vec2	m_vScale;			// �浹ü ũ�� ����

	UINT	m_iID;				// �浹ü ������ ID ��
	int		m_iCol;				// �浹�� ���� �ݶ��̴� ���� ��ȭ

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
	// �浹 ���� �Լ�
	void OnCollision(CCollider* _pOther);			// �浹���� ��� ȣ��Ǵ� �Լ�
	void OnCollisionEnter(CCollider* _pOther);		// �浹 ���� ��
	void OnCollisionExit(CCollider* _pOther);		// �浹 ���� ��



	CCollider& operator = (CCollider& _origin) = delete;	// ����Ʈ ���Կ����� �Լ��� ������ �� �ϰ� >> ���� �Ұ���!

public:
	CCollider();
	CCollider(const CCollider& _origin);	// ������ �� ���̵� �� ��ħ >> ���� ���縦 �������
	~CCollider();

	friend class CObject;
};

