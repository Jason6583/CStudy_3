#pragma once

#include "Defines.h"

class CSceneObj;
class CSceneMgr
{
public:
	DECLARE_SINGLETON(CSceneMgr);
private:
	CSceneObj*			m_pSceneObj;
public:
	HRESULT InitScene(SCENE Scene);
	void Progress(void);
	void Render(void);
	void Release(void);

private:
	CSceneMgr(void);
public:
	~CSceneMgr(void);
};
