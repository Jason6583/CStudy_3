#pragma once

#include "Obj.h"

class CStageDynamic
	: public CObj
{	
protected:
	float		m_fAngle;
public:
	void Chase_Move(const OBJINFO& DestInfo);
	void SetDirect(const OBJINFO& DestInfo);
	void AStar_start(const D3DXVECTOR3& vDestPos
		, const D3DXVECTOR3& vSourPos);
	void AStar_Move(void);
public:
	virtual HRESULT Initialize(void)PURE;
	virtual SCENE Progress(void)PURE;
	virtual void Render(void)PURE;
	virtual void Release(void)PURE;
	virtual CObj* Clone(void)PURE;
public:
	CStageDynamic(void);
	CStageDynamic(const OBJINFO& Info);
	~CStageDynamic(void);
};
