#pragma once

class CObject;
class CAnimation;
class CTexture;

class CAnimator
{
private:
	map<wstring, CAnimation*>	m_mapAnim;		// 모든 Animation
	CAnimation*					m_pCurAnim;		// 현재 재생중인 Animation
	CObject*					m_pOwner;		// Animator 소유 오브젝트
	bool						m_bRepeat;		// 반복재생 여부

public:
	CObject* GetObj() { return m_pOwner; }

	CAnimator& operator = (CAnimator& _origin) = delete;	// 디폴트 대입연산자 함수를 만들지 못 하게 >> 대입 불가능!

public:
	//					   애니메이션 이름		  애니 템플릿		좌상단      자를 사이즈		템플릿 상대위치  1프레임 시간     프레임 수
	void CreateAnimation(const wstring& _strName, CTexture* _pTex, Vec2 _vLT, Vec2 _vSliceSize, Vec2 _vStep, float _fDuration, UINT _iFrameCount);
	CAnimation* FindAnimation(const wstring& _strName);
	void Play(const wstring& _strName, bool _bRepeat);

	void update();

	void render(HDC _dc);
	 
public:
	CAnimator();
	CAnimator(const CAnimator& _origin);
	~CAnimator();
	
	friend class CObject;
};

