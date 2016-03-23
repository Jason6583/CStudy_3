#pragma once
#include "Define.h"

class CTexture;
class CTextureMgr
{
public:
	DECLARE_SINGLETON(CTextureMgr);

private:
	//Texture
	map<const TCHAR*, CTexture*>	m_MapTexture;

public:
	const TEXINFO* GetTexture(const TCHAR* pObjKey , const TCHAR* pStateKey = NULL, const int& nCnt = 0);
	
public:
	HRESULT InsertTexture(const TCHAR* pFileName, const TCHAR* pObjKey, TEXTYPE TypeId , const TCHAR* pStateKey = NULL,const int& nCnt = 0);

	void Release();
public:
	CTextureMgr(void);
	~CTextureMgr(void);
};

