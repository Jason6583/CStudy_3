#pragma once
#include "Define.h"
#include "Obj.h"
#include "Prototype.h"


class CObjMgr
{
public:
	DECLARE_SINGLETON(CObjMgr);
private:
	map<const TCHAR*,list<CObj*>>	m_MapObject;
public:
	const vector<TILE*>*	GetTileInfo();
	const D3DXVECTOR3* GetScrollInfo();
	const OBJINFO* GetInfo(const TCHAR* pObjKey,const int& nCnt = 0);

public:
	HRESULT AddObject(CPrototype* pProto, const TCHAR* pObjKey);
	SCENE Progress();
	void Render();
	void Release();
	
private:
	CObjMgr(void);
public:	
	~CObjMgr(void);
};

