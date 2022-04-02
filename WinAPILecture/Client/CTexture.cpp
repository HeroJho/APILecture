#include "pch.h"
#include "CTexture.h"
#include "CCore.h"

CTexture::CTexture()
	: m_hBit(0)
	, m_dc(0)
	, m_bitInfo{}
{
}
CTexture::~CTexture()
{
	DeleteDC(m_dc);
	DeleteObject(m_hBit);
}

// 이 경로는 PathManager에서 받아온다
// 실행 파일의 위치에 따라서 계속 경로가 바뀐다
// PathMgr이 프로그램이 실행할 때 관리해 준다.
void CTexture::Load(const wstring& _strFilePath)
{
	// 경로의 이미지를 받아서 비트맵에 넣는다 (id 반환)
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(m_hBit);// id가 안 나왔다 >> 로딩 실패 >> 예외 처리

	// 비트맵과 연결할 DC
	m_dc = CreateCompatibleDC(CCore::GetInst()->GetMainDC());

	// 비트맵과 DC 연결
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hPrevBit);

	// 가로 세로 길이 (비트맵 정보 받기)
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
}
