
// ���� �̱���
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

// ���� �̱���
class CCore
{
	SINGLE(CCore);
private:
	HWND	m_hWnd;			// ���� ������ �ڵ�(ID)
	POINT	m_ptResolution;	// ���� ������ �ػ�
	HDC		m_hDC;			// ���� �����쿡 Draw�� DC

	HBITMAP m_hBit;
	HDC		m_memDC;

	// ���� ����ϴ� GDI Object
	HBRUSH	m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN	m_arrPen[(UINT)PEN_TYPE::END];

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

private:
	void CreateBrushPen();

public:
	HWND GetMainHwnd() { return m_hWnd; }
	HDC GetMainDC() { return m_hDC; }
	POINT GetResolution() { return m_ptResolution; }
	HBRUSH GetBrush(BRUSH_TYPE _eType) { return m_arrBrush[(UINT)_eType]; }
	HPEN GetPen(PEN_TYPE _eType) { return m_arrPen[(UINT)_eType]; }
};  