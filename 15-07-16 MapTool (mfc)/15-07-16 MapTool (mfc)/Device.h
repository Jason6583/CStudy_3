#pragma once
#include "Define.h"

class CDevice
{
private:
	//장치의 성능을 조사한다. m_pDevice라는 객체를 생성해준다.
	LPDIRECT3D9	m_p3D;

	//장치를 대표하는 객체
	LPDIRECT3DDEVICE9	m_pDevice;

public:
	HRESULT InitDevice();

public:
	CDevice(void);
	~CDevice(void);
};

