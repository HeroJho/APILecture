#include "pch.h"
#include "CPooling.h"


CPooling::CPooling(CObject* _pOwner, POOLING_TYPE _ePoolingType)
	: m_bIsActive(true)
	, m_pOwner(_pOwner)
    , m_ePoolingType(_ePoolingType)
{

}

CPooling::~CPooling()
{

}
