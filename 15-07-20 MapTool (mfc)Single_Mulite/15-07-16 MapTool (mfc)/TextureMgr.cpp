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

	if (iter == m_MapTexture.end()) // Ű�� ������� 
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

		if (FAILED(pTexture->InsertTexture(pFileName))) // �߰��ϴ°� 
		{
			return E_FAIL;
		}

		m_MapTexture.insert(make_pair(pObjKey,pTexture));
	}
	else  //Ű�� ������ ����
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

	return iter->second->GetTexture(); // ������ �������� ������ 
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
