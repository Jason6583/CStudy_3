#pragma once
#include "Define.h"

class CTexture
{
public:
	virtual const TEXINFO* GetTexture()PURE;

public:
	virtual HRESULT InsertTexture(const TCHAR* pFileName)PURE;
	virtual void Release()PURE;


public:
	CTexture(void);
	virtual ~CTexture(void);
};

