#pragma once
#include "Obj.h"
class CStageStatic : public CObj
{
public:
	virtual HRESULT Initialize()PURE;
	virtual SCENE Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual CObj* Clone()PURE;

public:
	CStageStatic(void);
	CStageStatic(const OBJINFO& Info);
	virtual ~CStageStatic(void);
};

