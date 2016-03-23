#pragma once
#include "sceneobj.h"

class CStage :
	public CSceneObj
{
public:
	HRESULT PlayerTextureStand();
public:
	HRESULT Initialize(void);
	void Progress(void);
	void Render(void);
	void Release(void);
public:
	CStage(void);
	~CStage(void);
};
