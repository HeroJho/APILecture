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
	GetCurrentDirectory(255, m_szContentPath); // ���� ���������� �ִ� ��θ� �����´�
	
	int iLen = wcslen(m_szContentPath);

	// ���� ������
	for (int i = iLen - 1; 0 <= i; --i)
	{
		if ('\\' == m_szContentPath[i])
		{
			m_szContentPath[i] = '\0';
			break;;
		}
	}

	// �θ� -> bin -> content����
	// �̷��� �����, ������ ��忡�� �׻� content������ ã�� �� �ְԵȴ�.
	wcscat_s(m_szContentPath, 255, L"\\bin\\content\\");

}


