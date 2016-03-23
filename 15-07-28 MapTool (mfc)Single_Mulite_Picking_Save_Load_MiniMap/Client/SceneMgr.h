#pragma once
#include "Define.h"

class CSceneObj;
class CSceneMgr
{
public:
	DECLARE_SINGLETON(CSceneMgr);
private:
	CSceneObj*	m_pSceneObj;
public:
	HRESULT InitScene(SCENE Scene);
	void Progress();
	void Render();
	void Release();
	
private:
	CSceneMgr(void);
public:	
	~CSceneMgr(void);
};

