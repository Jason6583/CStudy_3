#pragma once

#include "StageStatic.h"

class CBackGround
	: public CStageStatic
{
private:
	vector<TILE*>			m_vecTile;

public:
	void InitTileFormFile(void);
	const vector<TILE*>* GetTileInfo(void) 	{
		return &m_vecTile;}
public:
	virtual HRESULT Initialize(void);
	virtual SCENE Progress(void);
	virtual void Render(void);
	virtual void Release(void);
	virtual CObj* Clone(void);
public:
	CBackGround(void);
	CBackGround(const OBJINFO& Info);
	~CBackGround(void);
};
