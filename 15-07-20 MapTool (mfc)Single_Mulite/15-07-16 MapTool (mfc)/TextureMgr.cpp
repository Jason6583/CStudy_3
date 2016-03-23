#include "StdAfx.h"
#include "TextureMgr.h"
#include "Texture.h"

#include "Include.h"


CTextureMgr::CTextureMgr(void)
{
}


CTextureMgr::~CTextureMgr(void)
{
	Release();
}

HRESULT CTextureMgr::InsertTexture( const TCHAR* pFileName, const TCHAR* pObjKey, TEXTYPE TypeId )
{
	map<const TCHAR*,CTexture*>::iterator iter = m_MapTexture.find(pObjKey);

	if (iter == m_MapTexture.end()) // 키가 없을경우 
	{
		CTexture* pTexture = NULL;

		switch(TypeId)
		{
		case TEXTYPE_SINGLE:
			pTexture = new CSingleTexture;
			break;
		case TEXTYPE_MULTI:
			pTexture = new CMultiTexture;
			break;
		}

		if (FAILED(pTexture->InsertTexture(pFileName))) // 추가하는곳 
		{
			return E_FAIL;
		}

		m_MapTexture.insert(make_pair(pObjKey,pTexture));
	}
	else  //키가 있으면 나감
	{
		return E_FAIL;
	}

	return S_OK;
}

const TEXINFO* CTextureMgr::GetTexture( const TCHAR* pObjKey )
{
	map<const TCHAR*,CTexture*>::iterator iter = m_MapTexture.find(pObjKey);

	if (iter == m_MapTexture.end())
	{
		return NULL;
	}

	return iter->second->GetTexture(); // 있으면 리턴으로 가져옴 
}

void CTextureMgr::Release()
{
	for (map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.begin(); iter != m_MapTexture.end(); ++iter)
	{
		delete iter->second;
		iter->second = NULL;
	}
	m_MapTexture.clear();
}
