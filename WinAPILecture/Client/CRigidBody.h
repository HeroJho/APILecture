#pragma once


class CRigidBody
{
private:
	CObject* m_pOwner;

	Vec2	 m_vGravityPar;
	Vec2	 m_vVelocity;

public:
	Vec2 GetVelocity() { return m_vVelocity; }

public:
	void finalupdate();
	void render(HDC _dc);


public:
	CRigidBody();
	~CRigidBody();

	friend class CObject;
};

