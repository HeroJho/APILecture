#include "pch.h"
#include "CResMgr.h"

#include "CPathMgr.h"
#include "CTexture.h"

CResMgr::CResMgr()
{

}
CResMgr::~CResMgr()
{
	// 리소스 동적할당 해제
	Safe_Delete_Map(m_mapTex);
}
													// 상대 경로
CTexture* CResMgr::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	// 먼저 가지고 있는 리소스인지 확인을 한다
	CTexture* pTex = FindTexture(_strKey);
	if (nullptr != pTex)
	{
		return pTex;
	}

	// 상대 경로에 따른 Texture 생성
	wstring strFilePath = CPathMgr::GetInst()->GetContentPath();
	strFilePath += _strRelativePath;

	pTex = new CTexture;
	pTex->Load(strFilePath);
	// 자신의 키값과 상대 경로를 들고 있는다
	pTex->SetKey(_strKey);
	pTex->SetRelativePath(_strRelativePath);

	// map에 넣는다
	m_mapTex.insert(make_pair(_strKey, pTex)); 

	return pTex;
}

CTexture* CResMgr::FindTexture(const wstring& _strKey)
{
	map<wstring, CRes*>::iterator iter = m_mapTex.find(_strKey);

	if (iter == m_mapTex.end())
	{
		return nullptr;
	}

	return (CTexture*)iter->second;
}
