#pragma once

//이미지 여러장
#include "Texture.h"
class CMultiTexture : public CTexture
{
private:
	map<const TCHAR*,vector<TEXINFO*>>	m_MapTexture;

public:
	virtual const TEXINFO* GetTexture();
	virtual HRESULT InsertTexture(const TCHAR* pFileName);
	virtual void Release();

public:
	CMultiTexture(void);
	~CMultiTexture(void);
};

