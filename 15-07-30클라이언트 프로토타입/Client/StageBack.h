#pragma once
#include "StageStatic.h"

class CStageBack  : public CStageStatic
{
public:
	virtual HRESULT Initialize();
	virtual SCENE Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();
public:
	CStageBack(void);
	CStageBack(const OBJINFO& Info);
	virtual ~CStageBack(void);
};

