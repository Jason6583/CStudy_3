#pragma once
#include "sceneobj.h"

class CLogo :
	public CSceneObj
{
public:
	HRESULT Initialize(void);
	void Progress(void);
	void Render(void);
	void Release(void);
public:
	CLogo(void);
	~CLogo(void);
};
