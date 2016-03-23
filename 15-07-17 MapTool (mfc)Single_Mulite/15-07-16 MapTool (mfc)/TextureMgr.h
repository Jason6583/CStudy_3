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
	const TEXINFO* GetTexture(const TCHAR* pObjKey);
	
public:
	HRESULT InsertTexture(const TCHAR* pFileName, const TCHAR* pObjKey, TEXTYPE TypeId);

	void Release();
public:
	CTextureMgr(void);
	~CTextureMgr(void);
};

