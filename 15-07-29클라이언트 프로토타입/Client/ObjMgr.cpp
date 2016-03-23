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
	} //��ü�� �����´�

	CObj* pObject = pProtoInst->Clone(); //�����ؼ� ��ƿ´�
	pObject->Initialize();
	
	if (iter == m_MapObject.end())
	{//ó���� iter�� ���� (Ű������)
		list<CObj*> Objlist;
		Objlist.push_back(pObject); //������Ÿ������ ������ ������Ʈ�� �־���

		m_MapObject.insert(make_pair(pObjKey,Objlist));
	}
	else
	{//Ű�� ������ 
		iter->second.push_back(pObject);
	}

	return S_OK;
}

void CObjMgr::Progress()
{
	for (map<const TCHAR*,list<CObj*>>::iterator iter = m_MapObject.begin(); 
		iter != m_MapObject.end(); ++iter)
	{
		for (list<CObj*>::iterator iter1 = iter->second.begin();
			iter1 != iter->second.end(); ++iter1)
		{
			(*iter1)->Progress();
		}
	}

}

void CObjMgr::Render()
{
	for (map<const TCHAR*,list<CObj*>>::iterator iter = m_MapObject.begin(); 
		iter != m_MapObject.end(); ++iter)
	{
		for (list<CObj*>::iterator iter1 = iter->second.begin();
			iter1 != iter->second.end(); ++iter1)
		{
			(*iter1)->Render();
		}
	}

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
