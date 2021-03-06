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

HRESULT CObjMgr::AddObject( CPrototype* pProto, const TCHAR* pObjKey )
{
	map<const TCHAR*,list<CObj*>>::iterator iter = m_MapObject.find(pObjKey);
	
	CObj* pProtoInst = ((CObjProto*)pProto)->GetProto(pObjKey);

	if (pProtoInst == NULL)
	{
		return E_FAIL;
	} //객체를 가져온다

	CObj* pObject = pProtoInst->Clone(); //복사해서 담아온다
	pObject->Initialize();
	
	if (iter == m_MapObject.end())
	{//처음에 iter가 없다 (키가없다)
		list<CObj*> Objlist;
		Objlist.push_back(pObject); //프로토타입으로 복제한 오브젝트를 넣어줌

		m_MapObject.insert(make_pair(pObjKey,Objlist));
	}
	else
	{//키가 있을때 
		iter->second.push_back(pObject);
	}

	return S_OK;
}

SCENE CObjMgr::Progress()
{
	for (map<const TCHAR*,list<CObj*>>::iterator iter = m_MapObject.begin(); 
		iter != m_MapObject.end(); ++iter)
	{
		for (list<CObj*>::iterator iter1 = iter->second.begin();
			iter1 != iter->second.end(); ++iter1)
		{
			SCENE SceneID = (*iter1)->Progress();
			
			if (SceneID >= 0) //리턴해서 신->로고 로 감 
			{
				return SceneID;
			}

			GET_SINGLE(CSortMgr)->AddSortObject(*iter1); //iter1은 오브젝트
		}
	}

	return SCENE_NONPASS;

}

void CObjMgr::Render()
{
	GET_SINGLE(CSortMgr)->RenderObject();

	/*for (map<const TCHAR*,list<CObj*>>::iterator iter = m_MapObject.begin(); 
		iter != m_MapObject.end(); ++iter)
	{
		for (list<CObj*>::iterator iter1 = iter->second.begin();
			iter1 != iter->second.end(); ++iter1)
		{
			(*iter1)->Render();
		}
	}*/

}

void CObjMgr::Release()
{
	for (map<const TCHAR*,list<CObj*>>::iterator iter = m_MapObject.begin(); 
		iter != m_MapObject.end(); ++iter)
	{
		for (list<CObj*>::iterator iter1 = iter->second.begin();
			iter1 != iter->second.end(); ++iter1)
		{
			SAFE_DELETE(*iter1);
		}
		iter->second.clear();
	}
	m_MapObject.clear();

}

const vector<TILE*>* CObjMgr::GetTileInfo()
{
	map<const TCHAR*,list<CObj*>>::iterator iter = m_MapObject.find(L"StageBack");

	if (iter == m_MapObject.end())
	{
		ERR_MSG(g_hWnd,L"타일 정보를 가지고 있는 객체가 없습니다");
		return NULL;
	}
	return ((CStageBack*)(iter->second.front()))->GetTileInfo();
}
