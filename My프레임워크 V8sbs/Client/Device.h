#pragma once

#include "Defines.h"

class CDevice
{
public:
	DECLARE_SINGLETON(CDevice);
private:
	// ��ġ�� ������ �����Ѵ�. m_pDevice��� ��ü�� �������ش�.
	LPDIRECT3D9			m_p3D;

	// ��ġ�� ��ǥ�ϴ� ��ü
	LPDIRECT3DDEVICE9	m_pDevice;

	LPD3DXSPRITE		m_pSprite;

	// ��Ʈ�� ����ϱ����� ��ü
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
