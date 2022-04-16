#pragma once

class CPooling;

class CPoolingMgr
{
private:
	vector<CPooling*>		m_vecPool[(UINT)POOLING_TYPE::END];


public:
	CObject* Get_PoolingObj(POOLING_TYPE _eType);
	void Set_PoolingObj(CObject* _pObj);


public:
	CPoolingMgr();
	~CPoolingMgr();
};

