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

