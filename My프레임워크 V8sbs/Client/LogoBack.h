#pragma once
#include "LogoStatic.h"

class CLogoBack :
	public CLogoStatic
{
public:
	virtual HRESULT Initialize(void);
	virtual SCENE Progress(void);
	virtual void Render(void);
	virtual void Release(void);
	virtual CObj* Clone(void);
public:
	CLogoBack(void);
	CLogoBack(const OBJINFO& Info);
	~CLogoBack(void);
};
