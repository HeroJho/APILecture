#pragma once
#include "CObject.h"

class CTexture;

class CItem :
    public CObject
{
protected:
    CTexture* m_pTex;

public:
    virtual void useItem(CObject* _pObj) = 0;

public:
    CItem();
    ~CItem();
};

