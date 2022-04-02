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

// �� ��δ� PathManager���� �޾ƿ´�
// ���� ������ ��ġ�� ���� ��� ��ΰ� �ٲ��
// PathMgr�� ���α׷��� ������ �� ������ �ش�.
void CTexture::Load(const wstring& _strFilePath)
{
	// ����� �̹����� �޾Ƽ� ��Ʈ�ʿ� �ִ´� (id ��ȯ)
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(m_hBit);// id�� �� ���Դ� >> �ε� ���� >> ���� ó��

	// ��Ʈ�ʰ� ������ DC
	m_dc = CreateCompatibleDC(CCore::GetInst()->GetMainDC());

	// ��Ʈ�ʰ� DC ����
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hPrevBit);

	// ���� ���� ���� (��Ʈ�� ���� �ޱ�)
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
}
