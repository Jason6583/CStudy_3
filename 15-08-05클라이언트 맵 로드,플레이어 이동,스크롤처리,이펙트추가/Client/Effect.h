#pragma once
#include "StageDynamic.h"

class CEffect : public CStageDynamic
{
public:
	virtual HRESULT Initialize();
	virtual SCENE Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();

public:
	CEffect(void);
	CEffect(const OBJINFO& Info);
	~CEffect(void);
};

