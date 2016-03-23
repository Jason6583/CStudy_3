#pragma once

// �̹��� ������
#include "Texture.h"

class CMultiTexture
	: public CTexture
{
private:
	// Key : ���� 
	// Player : walk : 012345
	// Player : attack : 012
	// Player : jump : 0123

	// BackGround : Tile : 38
	// BackGround : Back : 5

	map<const TCHAR*, vector<TEXINFO*>>		m_MapTexture;
public:
	virtual const TEXINFO*	GetTexture(const TCHAR* pStateKey = NULL
		, const int& iCnt = 0 );
public:
	virtual HRESULT InsertTexture(const TCHAR* pFileName
		, const TCHAR* pStateKey = 0, const int& iCnt = 0);

	virtual void Release(void);
public:
	CMultiTexture(void);
	~CMultiTexture(void);
};

