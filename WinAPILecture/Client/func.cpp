#include "pch.h"
#include "func.h"

#include "CEvenMgr.h"

void CreateObject(CObject* _pObj, GROUP_TYPE _eGroup)
{
	// DWORD_PTR : ������ ȯ��(32, 64��Ʈ)�� ���� �ڷ���(��Ʈ)�� �ٲ��
	// �������� ��� 4, 8����Ʈ ������ ������ ����Ѵ�
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::CREATE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;
	evn.wParam = (DWORD_PTR)_eGroup;

	CEvenMgr::GetInst()->AddEvent(evn);
}

void DeleteObject(CObject* _pObj)
{
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::DELETE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;

	CEvenMgr::GetInst()->AddEvent(evn); 
}

void ChangeScene(SCENE_TYPE _eNext)
{
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::SCENE_CHANGE;
	evn.lParam = (DWORD_PTR)_eNext;

	CEvenMgr::GetInst()->AddEvent(evn);
}
