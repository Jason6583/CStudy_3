#pragma once
#include "Obj.h"
class CMonster : public CObj
{
private:
	D3DXVECTOR3		m_vOriPoint[4];
	D3DXVECTOR3		m_ConPoint[4];
	float			m_fAngle;

private:
	CObj*			m_pPlayer;
public:
	void SetPlayerInfo(CObj* pPlayer) { m_pPlayer = pPlayer; }

public:
	void GetAngle();
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();

public:
	CMonster(void);
	~CMonster(void);
};

