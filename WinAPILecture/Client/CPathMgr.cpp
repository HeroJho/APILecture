#include "pch.h"
#include "CPathMgr.h"

CPathMgr::CPathMgr()
	:m_szContentPath{}
{
}
CPathMgr::~CPathMgr()
{
}

void CPathMgr::init()
{
	GetCurrentDirectory(255, m_szContentPath); // 현재 실행파일이 있는 경로를 가져온다
	
	int iLen = wcslen(m_szContentPath);

	// 상위 폴더로
	for (int i = iLen - 1; 0 <= i; --i)
	{
		if ('\\' == m_szContentPath[i])
		{
			m_szContentPath[i] = '\0';
			break;;
		}
	}

	// 부모 -> bin -> content파일
	// 이러면 디버그, 릴리즈 모드에서 항상 content파일을 찾을 수 있게된다.
	wcscat_s(m_szContentPath, 255, L"\\bin\\content\\");

}


