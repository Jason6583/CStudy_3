#include "StdAfx.h"
#include "Device.h"


CDevice::CDevice(void) :
m_p3D(NULL),
m_pDevice(NULL)
{
}


CDevice::~CDevice(void)
{
}

HRESULT CDevice::InitDevice()
{

	return S_OK;  //HRESULT  = 0 아니면 1 리턴 

}
