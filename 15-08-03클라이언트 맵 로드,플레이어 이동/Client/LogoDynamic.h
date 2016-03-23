#pragma once
#include "Obj.h"

class CLogoDynamic : public CObj
{
protected: //움직이는 함수
	float	m_fAngle;
public:
	void Chase_Move(const OBJINFO& DestInfo);
public:
	virtual HRESULT Initialize()PURE;
	virtual SCENE Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual CObj* Clone()PURE;
public:
	CLogoDynamic(void);
	CLogoDynamic(const OBJINFO& Info);
	virtual ~CLogoDynamic(void);
};

