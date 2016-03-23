#pragma once

#include "Defines.h"

class CTexture
{
public: //getter
	virtual const TEXINFO*	GetTexture(const TCHAR* pStateKey = NULL
		, const int& iCnt = 0 )PURE;
public:
	virtual HRESULT InsertTexture(const TCHAR* pFileName
		, const TCHAR* pStateKey = 0, const int& iCnt = 0) PURE;
	virtual void Release(void)PURE;
public:
	CTexture(void);
	virtual ~CTexture(void);
};
