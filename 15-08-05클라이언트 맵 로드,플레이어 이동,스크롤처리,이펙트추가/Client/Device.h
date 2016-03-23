#pragma once
#include "Define.h"

class CDevice
{
	DECLARE_SINGLETON(CDevice);
private:
	//장치의 성능을 조사한다. m_pDevice라는 객체를 생성해준다.
	LPDIRECT3D9	m_p3D;

	//장치를 대표하는 객체
	LPDIRECT3DDEVICE9	m_pDevice;
	
	LPD3DXSPRITE		m_pSprite;
	
	//폰트를 출력 하기 위한 객체
	LPD3DXFONT			m_pFont;

	LPD3DXLINE			m_pLine;
	
public:
	LPD3DXLINE	GetLine()
	{
		return m_pLine;
	}
	LPD3DXFONT	GetFont()
	{
		return m_pFont;
	}
	LPDIRECT3DDEVICE9 GetDevice()
	{
		return m_pDevice;
	}
	LPD3DXSPRITE GetSprite()
	{
		return m_pSprite;
	}

public:
	HRESULT InitDevice(WINMODE Mode);

	void Render_Begin();
	void Render_End();
	void Release();

private:
	CDevice(void);
public:
	~CDevice(void);
};

