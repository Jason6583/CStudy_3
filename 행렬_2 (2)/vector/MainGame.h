#pragma once
#include "define.h"

class CObj;
class CMainGame
{
private:
	HDC		m_hdc;
	CObj*	m_pPlayer;
	CObj*	m_pMonster;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	CMainGame(void);
	~CMainGame(void);
};

