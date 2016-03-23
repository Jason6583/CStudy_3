#pragma once
#include "Obj.h"
class CStageDynamic : public CObj
{
protected:
	float	m_fAngle;
public:
	void Chase_Move(const OBJINFO& DestInfo);
	void SetDirect(const OBJINFO& DestInfo);

	void Astar_start(const D3DXVECTOR3& vDestPos, const D3DXVECTOR3& vSourPos);
	void Astar_Move();

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

