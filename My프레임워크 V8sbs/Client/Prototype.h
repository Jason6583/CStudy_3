#pragma once

#include "Defines.h"

class CPrototype
{
public:
	virtual HRESULT InitProtoInstance(void) PURE;
	virtual void Release(void) PURE;
public:
	CPrototype(void);
	virtual ~CPrototype(void);
};
