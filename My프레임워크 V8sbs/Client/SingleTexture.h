#pragma once

// 이미지 한장
#include "Texture.h"

class CSingleTexture
	: public CTexture
{
private:
	TEXINFO*		m_pTexInfo;
public:
	virtual const TEXINFO*	GetTexture(const TCHAR* pStateKey = NULL
		, const int& iCnt = 0 );
public:
	virtual HRESULT InsertTexture(const TCHAR* pFileName
		, const TCHAR* pStateKey = 0, const int& iCnt = 0);
	virtual void Release(void);
public:
	CSingleTexture(void);
	~CSingleTexture(void);
};
