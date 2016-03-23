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
	
	//��Ʈ�� ��� �ϱ� ���� ��ü
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

