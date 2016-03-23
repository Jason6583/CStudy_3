#pragma once
#include "Obj.h"
class CStageDynamic : public CObj
{
public:
	virtual HRESULT Initialize()PURE;
	virtual SCENE Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual CObj* Clone()PURE;

public:
	CStageDynamic(void);
	CStageDynamic(const OBJINFO& Info);
	virtual ~CStageDynamic(void);
};

