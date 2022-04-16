#pragma once


#include "CCamera.h"

class CCollider;
class CAnimator;
class CPooling;

class CObject
{
private:
	wstring	m_strName;	// �ڽ� ��ü ���п� �̸�

	Vec2	m_vPos;
	Vec2	m_vScale;

	// ����� ���� �����ϸ� �������� >> ���������� �����
	// ������Ʈ(��ǰ)���·� �����Ѵ� >> �ʿ��ϸ� ������, �ʿ������ �Ȱ�����
	CCollider*	m_pCollider;
	CAnimator*	m_pAnimator;
	CPooling*	m_pPooling;

	bool		m_bAlive;	// Ȱ��ȭ���� ��Ȱ��ȭ����(���� ����)

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

	void CreateCollider();				// �ݶ��̴� ������Ʈ ���� �Լ�
	void CreateAnimator();				// �ִϸ��� ������Ʈ ���� �Լ�
	void CreatePooling(POOLING_TYPE _ePoolingType);				// Ǯ�� ������ ������Ʈ�� ������ ������Ʈ

	virtual void OnCollision(CCollider* _pOther) {}
	virtual void OnCollisionEnter(CCollider* _pOther) {}
	virtual void OnCollisionExit(CCollider* _pOther) {}

private:
	void SetDead() { m_bAlive = false; }		// ������ EVenMgr�� ���� ���� ����

public:
	virtual void update() = 0;
	virtual void finalupdate(); // final; // �ڽ��� ��ӵ��� �ʰ� �ؾ��Ѵ�! �ٸ� ���α׷��Ӱ� �ڽĿ� �������̵� ���ϰ� finalŰ����� ���´�
	virtual void render(HDC _dc);

	void component_render(HDC _dc);

	virtual CObject* Clone() = 0;		// �ڱ��ڽô� ����

public:
	CObject();
	CObject(const CObject& _origin);	// �ݶ��̴� ���� ����
	virtual ~CObject();

	friend class CEvenMgr;
};

