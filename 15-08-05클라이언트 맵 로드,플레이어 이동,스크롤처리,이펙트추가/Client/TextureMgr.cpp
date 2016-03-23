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

HRESULT CTextureMgr::InsertTexture( const TCHAR* pFileName, const TCHAR* pObjKey, TEXTYPE TypeId , const TCHAR* pStateKey,const int& nCnt )
{
	map<const TCHAR*,CTexture*>::iterator iter = m_MapTexture.find(pObjKey);

	 // 키가 없을경우 
	
		CTexture* pTexture = NULL;

		switch(TypeId)
		{
		case TEXTYPE_SINGLE:
			if (iter == m_MapTexture.end())
			{
				pTexture = new CSingleTexture;
			}
			else
				return E_FAIL;
			break;
		case TEXTYPE_MULTI:
			if (iter == m_MapTexture.end())
			{
				pTexture = new CMultiTexture;
			}
			else
				pTexture = (*iter).second;
			break;
		}

		if (FAILED(pTexture->InsertTexture(pFileName,pStateKey,nCnt))) // 추가하는곳 
		{
			return E_FAIL;
		}

		m_MapTexture.insert(make_pair(pObjKey,pTexture));
	
	

	return S_OK;
}

const TEXINFO* CTextureMgr::GetTexture( const TCHAR* pObjKey, const TCHAR* pStateKey , const int& nCnt  )
{
	map<const TCHAR*,CTexture*>::iterator iter = m_MapTexture.find(pObjKey);

	if (iter == m_MapTexture.end())
	{
		return NULL;
	}


	return iter->second->GetTexture(pStateKey,nCnt); // 있으면 리턴으로 가져옴 
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
