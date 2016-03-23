#pragma once

#include "Defines.h"

class CTexture;
class CTextureMgr
{
public:
	DECLARE_SINGLETON(CTextureMgr);
private:
	// Texture
	map<const TCHAR*, CTexture*>		m_MapTexture;
public:
	const TEXINFO*	GetTexture(const TCHAR* pObjKey
		, const TCHAR* pStateKey = NULL
		, const int& iCnt = 0);
public:
	HRESULT		InsertTexture(const TCHAR* pFileName
		, const TCHAR* pObjKey, TEXTYPE TypeID
		, const TCHAR* pStateKey = NULL, const int& iCnt = 0);
	void Release(void);	


private:
	CTextureMgr(void);
public:
	~CTextureMgr(void);
};
