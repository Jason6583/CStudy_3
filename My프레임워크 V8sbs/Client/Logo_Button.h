#pragma once
#include "LogoDynamic.h"

class CLogo_Button :
	public CLogoDynamic
{
private:
	bool m_bRenderCheck;
public:
	const OBJINFO  SetMouseInfo(void);
public:
	virtual HRESULT Initialize(void);
	virtual SCENE Progress(void);
	virtual void Render(void);
	virtual void Release(void);
	virtual CObj* Clone(void);
public:
	CLogo_Button(void);
	CLogo_Button(const OBJINFO& Info);	
	~CLogo_Button(void);
};
