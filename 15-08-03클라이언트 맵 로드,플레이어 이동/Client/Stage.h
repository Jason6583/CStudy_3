#pragma once
#include "SceneObj.h"

class CStage : public CSceneObj
{
public:
	virtual HRESULT Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	CStage(void);
	~CStage(void);
};

