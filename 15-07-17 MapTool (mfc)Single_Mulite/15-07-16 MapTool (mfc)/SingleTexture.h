#pragma once

//이미지 한장
#include "Texture.h"

class CSingleTexture : public CTexture
{
private:
	TEXINFO*	m_pTexInfo;
public:
	virtual const TEXINFO* GetTexture();
public:
	virtual HRESULT InsertTexture(const TCHAR* pFileName);
	virtual void Release();
public:
	CSingleTexture(void);
	virtual ~CSingleTexture(void);
};

