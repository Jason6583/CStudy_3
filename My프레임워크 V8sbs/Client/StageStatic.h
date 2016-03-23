#pragma once

#include "Obj.h"

class CStageStatic
	: public CObj
{
protected:
	float		m_fAngle;
public:
	virtual HRESULT Initialize(void)PURE;
	virtual SCENE Progress(void)PURE;
	virtual void Render(void)PURE;
	virtual void Release(void)PURE;
	virtual CObj* Clone(void)PURE;
public:
	CStageStatic(void);
	CStageStatic(const OBJINFO& Info);
	~CStageStatic(void);
};
