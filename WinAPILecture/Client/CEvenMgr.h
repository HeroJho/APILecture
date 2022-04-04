#pragma once

// 神崎詮闘 持失, 肢薦 去 戚坤闘級精 疑獣娃企拭 坦軒掬醤廃陥!
// けけけけしけけけ 廃 覗傾績 奄層生稽 戚坤闘研 郊稽 坦軒馬檎
// 廃 覗傾績戚 疑獣娃税 鯵割戚 焼艦艦 神崎詮闘研 肢薦梅陥馬檎
// 廃 覗傾績 坪球 奄層生稽 蒋拭辞澗 糎仙梅壱, 及澗 凧繕亜 災亜管廃 肢薦亜 吉陥!
// 走尻 坦軒研 背層陥!! 戚坤闘 乞焼砧壱 覗傾績戚 魁蟹檎 廃腰拭 坦軒!
struct tEvent
{
	EVENT_TYPE		eEven;	// 戚坤闘 展脊
	DWORD_PTR		lParam; // 戚坤闘 舛左
	DWORD_PTR		wParam; // 戚坤闘 舛左
};

class CEvenMgr
{
	SINGLE(CEvenMgr)
private:
	vector<tEvent> m_vecEvent;

	vector<CObject*> m_vecDead;	// 肢薦森舛 神崎詮闘


public:
	void update();

private:
	void Excute(const tEvent& _eve);

public:
	void AddEvent(const tEvent& _exe) { m_vecEvent.push_back(_exe); }
};

