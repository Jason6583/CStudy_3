#pragma once
#include "define.h"

class CObj
{
protected:
	INFO	m_Info;
public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Release()PURE;
public:
	CObj(void);
	virtual ~CObj(void);
};

