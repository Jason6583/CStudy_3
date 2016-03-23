#pragma once
#include "StageDynamic.h"

class CPlayer : public CStageDynamic
{
public:
	virtual HRESULT Initialize();
	virtual SCENE Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();
public:
	CPlayer(void);
	CPlayer(const OBJINFO& Info);
	virtual ~CPlayer(void);
};

