#pragma once

#include "Defines.h"

class CDevice
{
public:
	DECLARE_SINGLETON(CDevice);
private:
	// 장치의 성능을 조사한다. m_pDevice라는 객체를 생성해준다.
	LPDIRECT3D9			m_p3D;

	// 장치를 대표하는 객체
	LPDIRECT3DDEVICE9	m_pDevice;

	LPD3DXSPRITE		m_pSprite;

	// 폰트를 출력하기위한 객체
	LPD3DXFONT			m_pFont;

public: //getter
	LPD3DXFONT	GetFont(void) {
		return m_pFont;}
	LPD3DXSPRITE GetSprite(void) {
		return m_pSprite;}
	LPDIRECT3DDEVICE9 GetDevice(void) {
		return m_pDevice;}

public:
	HRESULT InitDevice(WINMODE Mode);
	void Release(void);
public:
	void Render_Begin(void);
	void Render_End(void);
private:
	CDevice(void);
public:
	~CDevice(void);
};
