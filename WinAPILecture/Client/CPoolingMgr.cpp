#include "pch.h"
#include "CPoolingMgr.h"

#include "CObject.h"
#include "CPooling.h"

CPoolingMgr::CPoolingMgr()
{
}

CPoolingMgr::~CPoolingMgr()
{
}


CObject* CPoolingMgr::Get_PoolingObj(POOLING_TYPE _eType)
{
	if (m_vecPool[(UINT)_eType].empty())
	{
		return nullptr;
	}

	CPooling* pPooling = m_vecPool[(UINT)_eType].back();
	m_vecPool[(UINT)_eType].pop_back();

	pPooling->Set_Active(true);

	return pPooling->GetOwner();
}

void CPoolingMgr::Set_PoolingObj(CObject* _pObj)
{
	CPooling* pPooling = _pObj->GetPooling();
	POOLING_TYPE eType = pPooling->Get_PoolingType();

	pPooling->Set_Active(false);

	m_vecPool[(UINT)eType].push_back(pPooling);
}
