#pragma once
#include "Define.h"

class CDevice
{
	DECLARE_SINGLETON(CDevice);
private:
	//��ġ�� ������ �����Ѵ�. m_pDevice��� ��ü�� �������ش�.
	LPDIRECT3D9	m_p3D;

	//��ġ�� ��ǥ�ϴ� ��ü
	LPDIRECT3DDEVICE9	m_pDevice;

	LPD3DXSPRITE		m_pSprite;

public:
	LPDIRECT3DDEVICE9 GetDevice()
	{
		return m_pDevice;
	}
	LPD3DXSPRITE GetSprite()
	{
		return m_pSprite;
	}

public:
	HRESULT InitDevice(HWND hWnd);

	void Render_Begin();
	void Render_End();

private:
	CDevice(void);
public:
	~CDevice(void);
};

