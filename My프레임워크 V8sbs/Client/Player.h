#pragma once
#include "stagedynamic.h"

class CPlayer :
	public CStageDynamic
{
	bool		m_bClick;
	POINT		ptMouse;
	bool		m_bMagic;
	list<int>*	m_pBestList;
	float		m_iMaxCnt;
public:
	const OBJINFO SetMouseInfo(void);
public:
	void KeyInput(void);

public:
	virtual HRESULT Initialize(void);
	virtual SCENE Progress(void);
	virtual void Render(void);
	virtual void Release(void);
	virtual CObj* Clone(void);
public:
	CPlayer(void);
	CPlayer(const OBJINFO& Info);
	~CPlayer(void);
};

