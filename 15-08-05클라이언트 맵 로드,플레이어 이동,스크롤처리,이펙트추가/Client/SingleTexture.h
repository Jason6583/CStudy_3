#pragma once

//이미지 한장
#include "Texture.h"

class CSingleTexture : public CTexture
{
private:
	TEXINFO*	m_pTexInfo;
public:
	virtual const TEXINFO* GetTexture(const TCHAR* pStateKey = NULL, const int& nCnt = 0);
public:
	virtual HRESULT InsertTexture(const TCHAR* pFileName,const TCHAR* pStateKey=0,const int& nCnt = 0);
	virtual void Release();
public:
	CSingleTexture(void);
	virtual ~CSingleTexture(void);
};

