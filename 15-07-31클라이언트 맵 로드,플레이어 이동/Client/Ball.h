#pragma once
#include "LogoDynamic.h"

class CBall : public CLogoDynamic
{
public:
	const OBJINFO SetMouseInfo();


public:
	virtual HRESULT Initialize();
	virtual SCENE Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();
public:
	CBall(void);
	CBall(const OBJINFO& Info);
	virtual ~CBall(void);
};

