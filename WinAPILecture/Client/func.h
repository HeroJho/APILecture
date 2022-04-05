#pragma once

class CObject;

void CreateObject(CObject* _pObj, GROUP_TYPE _eGroup);
void DeleteObject(CObject* _pObj);
void ChangeScene(SCENE_TYPE _eNext);




// �ش� �׷��� delete�ϰ�, ������ ������ �� ���� ����ִ� �Լ� 
template<typename T>
void Safe_Delete_Vec(vector<T>& _vec)
{
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		if (nullptr != _vec[i])
			delete _vec[i];
	}
	_vec.clear();
}

// map�� ��ȸ�ϸ� delete���ִ� �Լ�
 template<typename T1, typename T2>
 void Safe_Delete_Map(map<T1, T2>& _map)
 {
	 typename map<T1, T2>::iterator iter = _map.begin();

	 for (; iter != _map.end(); ++iter)
	 {
		 if (nullptr != iter->second)
			 delete iter->second;
	 }
	 _map.clear();
 }