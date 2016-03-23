#pragma once
#include "obj.h"

class CLogoStatic :
	public CObj
{
public:
	virtual HRESULT Initialize(void)PURE;
	virtual SCENE Progress(void)PURE;
	virtual void Render(void)PURE;
	virtual void Release(void)PURE;
	virtual CObj* Clone(void)PURE;
public:
	CLogoStatic(void);
	CLogoStatic(const OBJINFO& Info);
	~CLogoStatic(void);
};
