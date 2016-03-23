#include "StdAfx.h"
#include "MultiTexture.h"
#include "Device.h"


CMultiTexture::CMultiTexture(void)
{
}


CMultiTexture::~CMultiTexture(void)
{
}

const TEXINFO* CMultiTexture::GetTexture(const TCHAR* pStateKey , const int& nCnt)
{
	map<const TCHAR*, vector<TEXINFO*>>::iterator iter = m_MapTexture.find(pStateKey);

	if (iter == m_MapTexture.end())
	{
		return NULL;
	}



	return iter->second[nCnt];
}

HRESULT CMultiTexture::InsertTexture(const TCHAR* pFileName,const TCHAR* pStateKey,const int& nCnt  )
{
	TCHAR szPath[128] = L"";

	vector<TEXINFO*> vecTexture;

	for (int i = 0; i<nCnt; ++i)
	{
		wsprintf(szPath,pFileName,i);
		TEXINFO* m_pTexInfo = new TEXINFO;
		ZeroMemory(m_pTexInfo,sizeof(TEXINFO));
		
		if (FAILED(D3DXGetImageInfoFromFile(szPath,&m_pTexInfo->ImgInfo)))
		{
			return E_FAIL;
		}
		if (FAILED(D3DXCreateTextureFromFileEx(GET_SINGLE(CDevice)->GetDevice(),
			szPath,m_pTexInfo->ImgInfo.Width,
			m_pTexInfo->ImgInfo.Height, m_pTexInfo->ImgInfo.MipLevels, 0,
			m_pTexInfo->ImgInfo.Format,
			D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT,
			D3DCOLOR_ARGB(255,255,255,255),
			&m_pTexInfo->ImgInfo,
			NULL, &m_pTexInfo->pTexture)))
		{
			return E_FAIL;
		}

		vecTexture.push_back(m_pTexInfo);
		
	}
	m_MapTexture.insert(make_pair(pStateKey,vecTexture));

	return S_OK;
}

void CMultiTexture::Release()
{
	for (map<const TCHAR*,vector<TEXINFO*>>::iterator iter = m_MapTexture.begin(); iter != m_MapTexture.end(); ++iter)
	{
		for (unsigned int i = 0; i<iter->second.size(); ++i)
		{
			iter->second[i]->pTexture->Release();
			delete iter->second[i];
			iter->second[i] = NULL;
		}
		iter->second.clear();
	}

	m_MapTexture.clear();
}
