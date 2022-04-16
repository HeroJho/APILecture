#pragma once


class CPooling
{
private:
	bool				m_bIsActive;
	CObject*			m_pOwner;
	POOLING_TYPE		m_ePoolingType;

public:
	void Set_Active(bool _bIsActive) { m_bIsActive = _bIsActive; }
	bool Get_Active() { return m_bIsActive; }
	POOLING_TYPE Get_PoolingType() { return m_ePoolingType; }
	CObject* GetOwner() { return m_pOwner; }

public:
	CPooling(CObject* _pOwner, POOLING_TYPE _ePoolingType);
	~CPooling();
};

