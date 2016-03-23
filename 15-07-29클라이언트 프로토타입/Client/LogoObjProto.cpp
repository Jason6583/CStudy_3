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
	//원형 객체를 생성하는 작업
	OBJINFO		ObjInfo;
	ZeroMemory(&ObjInfo,sizeof(ObjInfo));

	D3DXMatrixIdentity(&ObjInfo.matWorld);

	ObjInfo.vPos = D3DXVECTOR3(400.f, 300.f, 0.f);

	ObjInfo.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);
	ObjInfo.vLook = D3DXVECTOR3(1.f, 0.f, 0.f);

	m_MapProto.insert(make_pair(L"LogoBack",new CBackGround(ObjInfo)));
	m_MapProto.insert(make_pair(L"Ball",new CBall(ObjInfo)));  //클론으로 복사되면서 값들도 가지고 옴



	return S_OK;
}
