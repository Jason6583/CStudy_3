#pragma once
#include "Define.h"

class CDevice
{
private:
	//��ġ�� ������ �����Ѵ�. m_pDevice��� ��ü�� �������ش�.
	LPDIRECT3D9	m_p3D;

	//��ġ�� ��ǥ�ϴ� ��ü
	LPDIRECT3DDEVICE9	m_pDevice;

public:
	HRESULT InitDevice();

public:
	CDevice(void);
	~CDevice(void);
};

