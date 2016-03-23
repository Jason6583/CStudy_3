#pragma once
#include "StageStatic.h"

class CStageBack  : public CStageStatic
{
private:
	vector<TILE*>	m_vecTile;
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

