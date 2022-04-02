
// 동적 싱글톤
//class CCore
//{
//private:
//	static CCore* g_pInst;
//	CCore();
//	~CCore();
//
//public:
//	static CCore* GetInstance()
//	{
//		if (nullptr == g_pInst)
//			g_pInst = new CCore;
//
//		return g_pInst;
//	}
//
//	static void Release()
//	{
//		if (nullptr != g_pInst)
//		{
//			delete g_pInst;
//			g_pInst = nullptr;
//		}
//	}
//};

// 정적 싱글톤
class CCore
{
	SINGLE(CCore);
private:
	HWND	m_hWnd;			// 메인 윈도우 핸들(ID)
	POINT	m_ptResolution;	// 메인 윈도우 해상도
	HDC		m_hDC;			// 메인 윈도우에 Draw할 DC

	HBITMAP m_hBit;
	HDC		m_memDC;

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

private:
	void update();
	void render();

public:
	HWND GetMainHwnd() { return m_hWnd; }
	HDC GetMainDC() { return m_hDC; }
	POINT GetResolution() { return m_ptResolution; }

};  