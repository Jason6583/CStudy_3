#pragma once
#include "Define.h"

class CMainGame
{
public:
	HRESULT Initialize();
	void Progress();
	void Render();
	void Release();
public:
	CMainGame(void);
	~CMainGame(void);
};

