

#define SINGLE(type) public:\
						 static type* GetInst()\
						 {\
							static type mgr;\
							return &mgr;\
						 }\
					private:\
						type();\
						~type();


#define fDT CTimeMgr::GetInst()->GetfDT()
#define DT CTimeMgr::GetInst()->GetDT()

#define CLONE(type) type* Clone() {return new type(*this);}


#define KEY_CHECK(key, state) CKeyMgr::GetInst()->GetKeyState(key) == state
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE)
#define	MOUSE_POS CKeyMgr::GetInst()->GetMousePos()

#define PI 3.1415926535f
#define DPI PI * 2.f

#define TILE_SIZE 64



enum class GROUP_TYPE
{
	DEFAULT,
	TILE,
	ITEM,
	PLAYER,
	MONSTER,
	PROJ_MONSTER,
	PROJ_PLAYER,

	UI = 31,			// UI는 가장 앞에 그려져야 한다!
	END = 32
};

enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,

	END
};

enum class BRUSH_TYPE
{
	HOLLOW,
	END
};

enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,
	END
};

// 지연처리할 상황들
enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,
	
	
	END
};


enum class MONSTER_TYPE
{
	NONE,
	BALLMAN,



	END
};



enum class SKILL_TYPE
{
	ENERGEBALL,
	TWISTER,
	TTENGBALL,

	
	END
};
enum class SKILL_LEVEL
{
	NONE,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,


	END
};




enum class POOLING_TYPE
{
	MONSTER,
	ENERGEBALL,



	END
};