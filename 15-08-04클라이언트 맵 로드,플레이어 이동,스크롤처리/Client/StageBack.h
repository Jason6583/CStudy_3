#pragma once
#include "StageStatic.h"

class CStageBack  : public CStageStatic
{
private:
	vector<TILE*>		m_vecTile;
private:
	D3DXVECTOR3		m_vScroll;
public:
	const D3DXVECTOR3* GetScrollInfo()
	{
		return &m_vScroll;
	}
public:
	void MapScroll();

public:
	const vector<TILE*>*	GetTileInfo()
	{
		return &m_vecTile;
	}
public:
	void InitTileLoadfile();
public:
	virtual HRESULT Initialize();
	virtual SCENE Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();
public:
	CStageBack(void);
	CStageBack(const OBJINFO& Info);
	virtual ~CStageBack(void);
};

