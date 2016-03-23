#pragma once
#include "obj.h"

class CLogoDynamic :
	public CObj
{
protected:
	float			m_fAngle;
public:
	void Chase_Move(const OBJINFO& DestInfo);	
public:
	virtual HRESULT Initialize(void)PURE;
	virtual SCENE Progress(void)PURE;
	virtual void Render(void)PURE;
	virtual void Release(void)PURE;
public:
	CLogoDynamic(void);
	CLogoDynamic(const OBJINFO& Info);
	~CLogoDynamic(void);
};
