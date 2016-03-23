#pragma once
#include "SceneObj.h"

class CLogo :public CSceneObj
{
public:
	virtual HRESULT Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	CLogo(void);
	~CLogo(void);
};

