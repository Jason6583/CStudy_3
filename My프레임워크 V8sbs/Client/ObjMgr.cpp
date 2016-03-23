#include "StdAfx.h"
#include "ObjMgr.h"

#include "Include.h"

CObjMgr::CObjMgr(void)
{
}

CObjMgr::~CObjMgr(void)
{
	Release();
}

HRESULT CObjMgr::AddObject(CPrototype* pProto, const TCHAR* pObjKey)
{
	map<const TCHAR*, list<CObj*>>::iterator	iter = m_MapObject.find(pObjKey);

	CObj*		pProtoInst = ((CObjProto*)pProto)->GetProto(pObjKey);
	if(pProtoInst == NULL)
		return E_FAIL;

	CObj*		pObject = pProtoInst->Clone();
	pObject->Initialize();

	if(iter == m_MapObject.end())	
	{
		list<CObj*>		Objlist;
		Objlist.push_back(pObject);

		m_MapObject.insert(map<const TCHAR*, list<CObj*>>::value_type(pObjKey, Objlist));	
	}

	else
	{
		iter->second.push_back(pObject);
	}
	return S_OK;
}

SCENE CObjMgr::Progress(void)
{
	for (map<const TCHAR*, list<CObj*>>::iterator	iter = m_MapObject.begin();
		iter != m_MapObject.end(); ++iter)
	{
		for (list<CObj*>::iterator	iter1 = iter->second.begin();
			iter1 != iter->second.end(); ++iter1)
		{
			SCENE SceneID = (*iter1)->Progress();
			if(SceneID >= 0)
				return SceneID;

			GET_SINGLE(CSortMgr)->AddSortObject(*iter1);
		}
	}

	return SCENE_NONPASS;
}
void CObjMgr::Render(void)
{
	GET_SINGLE(CSortMgr)->RenderObject();
/*
	for (map<const TCHAR*, list<CObj*>>::iterator	iter = m_MapObject.begin();
		iter != m_MapObject.end(); ++iter)
	{
		for (list<CObj*>::iterator	iter1 = iter->second.begin();
			iter1 != iter->second.end(); ++iter1)
		{
			(*iter1)->Render();
		}
	}*/

}
void CObjMgr::Release(void)
{
	for (map<const TCHAR*, list<CObj*>>::iterator	iter = m_MapObject.begin();
		iter != m_MapObject.end(); ++iter)
	{
		for (list<CObj*>::iterator	iter1 = iter->second.begin();
			iter1 != iter->second.end(); ++iter1)
		{
			SAFE_DELETE(*iter1);
		}
		iter->second.clear();
	}
	m_MapObject.clear();		
}

const vector<TILE*>* CObjMgr::GetTileInfo( void )
{
	map<const TCHAR*, list<CObj*>>::iterator	iter = m_MapObject.find(L"BackGround");

	if(iter == m_MapObject.end())
	{
		ERR_MSG(g_hWnd, L"타일정보를 가지고있는 객체가 없습니다.");
		return NULL;
	}
	return ((CBackGround*)(iter->second.front()))->GetTileInfo();
}
