#pragma once
#include "Obj.h"

class CLogoStatic : public CObj
{
public:
	virtual HRESULT Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual CObj* Clone()PURE;
public:
	CLogoStatic(void);
	CLogoStatic(const OBJINFO& Info);
	virtual ~CLogoStatic(void);
};

