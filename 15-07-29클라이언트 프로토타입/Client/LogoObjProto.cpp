#include "StdAfx.h"
#include "LogoObjProto.h"
#include "Include.h"

CLogoObjProto::CLogoObjProto(void)
{
}


CLogoObjProto::~CLogoObjProto(void)
{
}

HRESULT CLogoObjProto::InitProtoInstance()
{
	//���� ��ü�� �����ϴ� �۾�
	OBJINFO		ObjInfo;
	ZeroMemory(&ObjInfo,sizeof(ObjInfo));

	D3DXMatrixIdentity(&ObjInfo.matWorld);

	ObjInfo.vPos = D3DXVECTOR3(400.f, 300.f, 0.f);

	ObjInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);
	ObjInfo.vLook = D3DXVECTOR3(1.f, 0.f, 0.f);

	m_MapProto.insert(make_pair(L"LogoBack",new CBackGround(ObjInfo)));
	m_MapProto.insert(make_pair(L"Ball",new CBall(ObjInfo)));  //Ŭ������ ����Ǹ鼭 ���鵵 ������ ��



	return S_OK;
}
