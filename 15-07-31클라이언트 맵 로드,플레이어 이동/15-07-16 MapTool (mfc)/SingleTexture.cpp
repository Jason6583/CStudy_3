#include "StdAfx.h"
#include "SingleTexture.h"
#include "Device.h"

CSingleTexture::CSingleTexture(void)
{
}


CSingleTexture::~CSingleTexture(void)
{
	Release();
}

const TEXINFO* CSingleTexture::GetTexture(const TCHAR* pStateKey , const int& nCnt )
{
	

	return m_pTexInfo;
	

}

HRESULT CSingleTexture::InsertTexture(const TCHAR* pFileName,const TCHAR* pStateKey,const int& nCnt )
{
	m_pTexInfo = new TEXINFO;
	ZeroMemory(m_pTexInfo,sizeof(TEXINFO));
	if (FAILED(D3DXGetImageInfoFromFile(pFileName,&m_pTexInfo->ImgInfo)))
	{
		return E_FAIL;
	}
	if (FAILED(D3DXCreateTextureFromFileEx(GET_SINGLE(CDevice)->GetDevice(),pFileName,m_pTexInfo->ImgInfo.Width,
		m_pTexInfo->ImgInfo.Height, m_pTexInfo->ImgInfo.MipLevels, 0,
		m_pTexInfo->ImgInfo.Format,
		D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT,
		D3DCOLOR_ARGB(255,255,255,255),
		&m_pTexInfo->ImgInfo,
		NULL, &m_pTexInfo->pTexture)))
	{
		return S_OK;
	}

}

void CSingleTexture::Release()
{
	if (m_pTexInfo)
	{
		m_pTexInfo->pTexture->Release();
		delete m_pTexInfo;
		m_pTexInfo = NULL;
	}
}
