#include "StdAfx.h"
#include "Logo.h"
#include "Include.h"

CLogo::CLogo(void)
{
}


CLogo::~CLogo(void)
{
	Release();
}

HRESULT CLogo::Initialize()
{
	//객체를 생성 하기 위한 준비
	m_pPrototype = new CLogoObjProto;


	if (FAILED(m_pPrototype->InitProtoInstance()))
	{
		ERR_MSG(g_hWnd,L"원형 객체 생성 실패");
		return E_FAIL;
	}

	if (FAILED(GET_SINGLE(CObjMgr)->AddObject(m_pPrototype,L"LogoBack")))
	{
		ERR_MSG(g_hWnd,L"객체 생성 실패");
		return E_FAIL;
	}

	if (FAILED(GET_SINGLE(CObjMgr)->AddObject(m_pPrototype,L"Ball")))
	{
		ERR_MSG(g_hWnd,L"객체 생성 실패");
		return E_FAIL;
	}

	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Logo/LogoBack.png",L"LogoBack",TEXTYPE_SINGLE)))
	{
		ERR_MSG(g_hWnd,L"LogoBackTexture 실패");
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Logo/Ball.png",L"Ball",TEXTYPE_SINGLE)))
	{
		ERR_MSG(g_hWnd,L"LogoBackTexture 실패");
		return E_FAIL;
	}


	return S_OK;
}

void CLogo::Progress()
{
	GET_SINGLE(CObjMgr)->Progress();
}

void CLogo::Render()
{
	GET_SINGLE(CObjMgr)->Render();
}

void CLogo::Release()
{
	DESTROY_SINGLE(CObjMgr);
}
