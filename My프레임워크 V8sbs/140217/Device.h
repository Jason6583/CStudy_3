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
public: //getter
	LPD3DXSPRITE GetSprite(void) {
		return m_pSprite;}
	LPDIRECT3DDEVICE9 GetDevice(void) {
		return m_pDevice;}

public:
	HRESULT InitDevice(HWND hWnd);
	void Release(void);
public:
	void Render_Begin(void);
	void Render_End(HWND hWnd);
private:
	CDevice(void);
	~CDevice(void);
};
