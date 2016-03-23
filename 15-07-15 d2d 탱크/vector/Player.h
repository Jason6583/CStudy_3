#pragma once
#include "Obj.h"
class CPlayer:public CObj
{
private:
	D3DXVECTOR3		m_vOriPoint[4];
	D3DXVECTOR3		m_vConPoint[4];
	D3DXVECTOR3		m_vConPos;

	D3DXVECTOR3		m_vMoveDir;

	float			m_fSpeed;
	float			m_fAngle;
	float			m_fAngleBody;
	D3DXVECTOR2		m_vPoint;

public:
	void KeyCheck();
	INFO GetInfo() { return m_Info;}
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CPlayer(void);
	~CPlayer(void);
};

