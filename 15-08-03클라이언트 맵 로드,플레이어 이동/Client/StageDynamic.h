#pragma once
#include "Obj.h"
class CStageDynamic : public CObj
{
protected:
	float	m_fAngle;
public:
	void Chase_Move(const OBJINFO& DestInfo);
	void SetDirect(const OBJINFO& DestInfo);

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

