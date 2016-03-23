#pragma once
#include "Obj.h"

class CLogoDynamic : public CObj
{
public:
	virtual HRESULT Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual CObj* Clone()PURE;
public:
	CLogoDynamic(void);
	CLogoDynamic(const OBJINFO& Info);
	virtual ~CLogoDynamic(void);
};

