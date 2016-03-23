#pragma once

#include "Defines.h"
#include "Obj.h"
#include "Prototype.h"


class CObjMgr
{
public:
	DECLARE_SINGLETON(CObjMgr);
private:
	map<const TCHAR*, list<CObj*>>		m_MapObject;
public:
	const vector<TILE*>* GetTileInfo(void);
public:
	HRESULT AddObject(CPrototype* pProto, const TCHAR* pObjKey);
	SCENE Progress(void);
	void Render(void);
	void Release(void);

private:
	CObjMgr(void);
public:
	~CObjMgr(void);
};
