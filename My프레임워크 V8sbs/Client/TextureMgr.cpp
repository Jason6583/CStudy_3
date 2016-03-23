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

const TEXINFO*	CTextureMgr::GetTexture(const TCHAR* pObjKey
										, const TCHAR* pStateKey
										, const int& iCnt)
{
	map<const TCHAR*, CTexture*>::iterator	iter = m_MapTexture.find(pObjKey);

	if(iter == m_MapTexture.end())
		return NULL;

	return iter->second->GetTexture(pStateKey, iCnt);
}

HRESULT	CTextureMgr::InsertTexture(const TCHAR* pFileName
								   , const TCHAR* pObjKey, TEXTYPE TypeID
								   , const TCHAR* pStateKey/* = NULL*/, const int& iCnt/* = 0*/)
{
	map<const TCHAR*, CTexture*>::iterator	iter = m_MapTexture.find(pObjKey);

	
		CTexture*			pTexture = NULL;
		switch(TypeID)
		{
		case TEXTYPE_SINGLE:
			if(iter == m_MapTexture.end())
 			pTexture = new CSingleTexture;
			else		
			return E_FAIL;	
			break;
		case TEXTYPE_MULTI:
			if(iter == m_MapTexture.end())
			pTexture = new CMultiTexture;
			else
				pTexture = (*iter).second;
				break;
		}

		if(FAILED(pTexture->InsertTexture(pFileName
			, pStateKey, iCnt)))
			return E_FAIL;
		m_MapTexture.insert(make_pair(pObjKey, pTexture));

	
	return S_OK;
}

void CTextureMgr::Release(void)
{
	for (map<const TCHAR*, CTexture*>::iterator	iter = m_MapTexture.begin();
		iter != m_MapTexture.end() ;++iter)
	{
		delete iter->second;
		iter->second = NULL;
	}
	m_MapTexture.clear();

}