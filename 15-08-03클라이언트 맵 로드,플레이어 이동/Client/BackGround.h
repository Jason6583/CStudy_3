#pragma once
#include "LogoStatic.h"

class CBackGround : public CLogoStatic
{
public:
	virtual HRESULT Initialize();
	virtual SCENE Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();
public:
	CBackGround(void);
	CBackGround(const OBJINFO& Info);
	virtual ~CBackGround(void);
};

