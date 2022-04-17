#pragma once

class CObject;

void CreateObject(CObject* _pObj, GROUP_TYPE _eGroup);
void DeleteObject(CObject* _pObj);
void ChangeScene(SCENE_TYPE _eNext);




// 해당 그룹을 delete하고, 벡터의 포인터 값 까지 비워주는 함수 
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

// map을 순회하며 delete해주는 함수
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


 float GetRandomNum(float _tLeft, float _tRight);
 int GetRandomNum(int _tLeft, int _tRight);