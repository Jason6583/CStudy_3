#pragma once
#include "Define.h"

class CTexture
{
public:
	virtual const TEXINFO* GetTexture(const TCHAR* pStateKey = NULL, const int& nCnt = 0)PURE;

public:
	virtual HRESULT InsertTexture(const TCHAR* pFileName,const TCHAR* pStateKey=0,const int& nCnt = 0)PURE;
	virtual void Release()PURE;


public:
	CTexture(void);
	virtual ~CTexture(void);
};

