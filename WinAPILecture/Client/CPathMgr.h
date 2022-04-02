#pragma once

class CPathMgr
{
	SINGLE(CPathMgr);
private:
	wchar_t		m_szContentPath[255];	// 윈도우에서 경로는 255로 제한 걸려있음

public:
	void init();
	const wchar_t* GetContentPath() { return m_szContentPath; }

};

