#pragma once

class CObject;

class CScene
{
private:
	// CObj의 벡터가 END개
	vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END];
	wstring			m_strName;

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }
	
	virtual void update();
	virtual void finalupdate();
	virtual void render(HDC _dc);

	virtual void Enter() = 0;	// 순수 가상함수
	virtual void Exit() = 0;	 

public:	// 헤더에서 구현한 함수는 Inline
	void AddObject(CObject* _pObj, GROUP_TYPE _eType)
	{
		m_arrObj[(UINT)_eType].push_back(_pObj);
	}
	const vector<CObject*>& GetGroupObject(GROUP_TYPE _eType) { return m_arrObj[(UINT)_eType]; }
	void DeleteGroup(GROUP_TYPE _eTarget);
	void DeleteAll();

public:
	CScene();
	virtual ~CScene();
};

