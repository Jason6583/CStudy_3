#pragma once

//이미지 여러장
#include "Texture.h"
class CMultiTexture : public CTexture
{
private:
	//Player : walk : 01234  벡터에 텍스쳐를 넣어서 여러개를 받는다.
	

	map<const TCHAR*,vector<TEXINFO*>>	m_MapTexture;

public:
	virtual const TEXINFO* GetTexture(const TCHAR* pStateKey = NULL, const int& nCnt = 0);
	virtual HRESULT InsertTexture(const TCHAR* pFileName,const TCHAR* pStateKey=0,const int& nCnt = 0);
	virtual void Release();


public:
	CMultiTexture(void);
	~CMultiTexture(void);
};

