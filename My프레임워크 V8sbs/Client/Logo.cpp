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

HRESULT CLogo::Initialize( void )
{
	GET_SINGLE(CTimeMgr)->InitTimeMgr();


	// 객체를 생성하기위한 준비
	m_pPrototype = new CLogoObjProto;
	if(FAILED(m_pPrototype->InitProtoInstance()))
	{
		ERR_MSG(g_hWnd, L"원형객체생성실패");
		return E_FAIL;
	}

	if(FAILED(GET_SINGLE(CObjMgr)->AddObject(m_pPrototype, L"LogoBack")))
	{
		ERR_MSG(g_hWnd, L"객체생성실패");
		return E_FAIL;
	}

	if(FAILED(GET_SINGLE(CObjMgr)->AddObject(m_pPrototype, L"LogoButton")))
	{
		ERR_MSG(g_hWnd, L"객체생성실패");
		return E_FAIL;
	}

	if(FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Logo/BackGround.png"
		, L"LogoBack", TEXTYPE_SINGLE)))
	{
		ERR_MSG(g_hWnd, L"LogoBackTexture Loading Failed");
		return E_FAIL;
	}

	if(FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Logo/Login.png"
		, L"LogoButton", TEXTYPE_SINGLE)))
	{
		ERR_MSG(g_hWnd, L"BallTexture Loading Failed");
		return E_FAIL;
	}

	return S_OK;
}

void CLogo::Progress( void )
{	
	GET_SINGLE(CTimeMgr)->SetTime();
	SCENE SceneID = GET_SINGLE(CObjMgr)->Progress();

	if(SceneID >= 0)
	{
		GET_SINGLE(CSceneMgr)->InitScene(SceneID);
		return;
	}
}

void CLogo::Render( void )
{
	GET_SINGLE(CObjMgr)->Render();
}

void CLogo::Release( void )
{
	DESTROY_SINGLE(CObjMgr);
	DESTROY_SINGLE(CTextureMgr);
	SAFE_DELETE(m_pPrototype);
	DESTROY_SINGLE(CTimeMgr);
}

