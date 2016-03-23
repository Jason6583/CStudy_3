#include "StdAfx.h"
#include "Stage.h"

#include "Include.h"

CStage::CStage(void)
{
}

CStage::~CStage(void)
{
	Release();
}

HRESULT CStage::Initialize( void )
{
	GET_SINGLE(CTimeMgr)->InitTimeMgr();
	

	// 객체를 생성하기위한 준비
	m_pPrototype = new CStageObjProto;

	if(FAILED(m_pPrototype->InitProtoInstance()))
	{
		ERR_MSG(g_hWnd, L"원형객체생성실패");
		return E_FAIL;
	}

	if(FAILED(GET_SINGLE(CObjMgr)->AddObject(m_pPrototype, L"BackGround")))
	{
		ERR_MSG(g_hWnd, L"객체생성실패");
		return E_FAIL;
	}
	
	if(FAILED(GET_SINGLE(CObjMgr)->AddObject(m_pPrototype, STAGE_PLAYER)))
	{
		ERR_MSG(g_hWnd, L"객체생성실패");
		return E_FAIL;
	}

	if(FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Desert.png"
		, L"BackGround", TEXTYPE_MULTI, L"Desert", 1)))
	{
		ERR_MSG(g_hWnd, L"LogoBackTexture Loading Failed");
		return E_FAIL;
	}


	if(FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Tile/Tile%d.png"
		, L"BackGround", TEXTYPE_MULTI, L"Tile", 38)))
	{
		ERR_MSG(g_hWnd, L"LogoBackTexture Loading Failed");
		return E_FAIL;
	}


	if(FAILED(PlayerTextureStand()))
	{
		ERR_MSG(g_hWnd, L"PlayerTextureStand");
		return E_FAIL;
	}




	return S_OK;
}

void CStage::Progress( void )
{
	GET_SINGLE(CTimeMgr)->SetTime();
	GET_SINGLE(CKeyMgr)->SetKeyCheck();

	SCENE SceneID = GET_SINGLE(CObjMgr)->Progress();

	if(SceneID >= 0)
	{
		GET_SINGLE(CSceneMgr)->InitScene(SceneID);
		return;
	}
}

void CStage::Render( void )
{
	GET_SINGLE(CObjMgr)->Render();
}

void CStage::Release( void )
{
	DESTROY_SINGLE(CObjMgr);
	DESTROY_SINGLE(CTextureMgr);
	SAFE_DELETE(m_pPrototype);
	DESTROY_SINGLE(CTimeMgr);
	DESTROY_SINGLE(CKeyMgr);
	
}


HRESULT CStage::PlayerTextureStand()
{
	if(FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Stage/Mage/MageStand/MageStandR/MageStandR%d.png"
		, STAGE_PLAYER, TEXTYPE_MULTI, STAND_RIGHT, 6)))
	{
		ERR_MSG(g_hWnd, L"Player_StandR Texture Loading Failed");
		return E_FAIL;
	}

	if(FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Stage/Mage/MageStand/MageStandRD/MageStandRD%d.png"
		, STAGE_PLAYER, TEXTYPE_MULTI, STAND_RIGHT_DOWN, 6)))
	{
		ERR_MSG(g_hWnd, L"Player_StandRD Texture Loading Failed");
		return E_FAIL;
	}

	if(FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Stage/Mage/MageStand/MageStandD/MageStandD%d.png"
		, STAGE_PLAYER, TEXTYPE_MULTI, STAND_DOWN, 6)))
	{
		ERR_MSG(g_hWnd, L"Player_StandD Texture Loading Failed");
		return E_FAIL;
	}

	if(FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Stage/Mage/MageStand/MageStandLD/MageStandLD%d.png"
		, STAGE_PLAYER, TEXTYPE_MULTI,STAND_LEFT_DOWN, 6)))
	{
		ERR_MSG(g_hWnd, L"Player_StandLD Texture Loading Failed");
		return E_FAIL;
	}

	if(FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Stage/Mage/MageStand/MageStandL/MageStandL%d.png"
		, STAGE_PLAYER, TEXTYPE_MULTI, STAND_LEFT, 6)))
	{
		ERR_MSG(g_hWnd, L"Player_StandL Texture Loading Failed");
		return E_FAIL;
	}


	if(FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Stage/Mage/MageStand/MageStandLU/MageStandLU%d.png"
		, STAGE_PLAYER, TEXTYPE_MULTI, STAND_LEFT_UP, 6)))
	{
		ERR_MSG(g_hWnd, L"Player_StandLU Texture Loading Failed");
		return E_FAIL;
	}

	if(FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Stage/Mage/MageStand/MageStandU/MageStandU%d.png"
		, STAGE_PLAYER, TEXTYPE_MULTI, STAND_UP, 6)))
	{
		ERR_MSG(g_hWnd, L"Player_StandU Texture Loading Failed");
		return E_FAIL;
	}

	if(FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Stage/Mage/MageStand/MageStandRU/MageStandRU%d.png"
		, STAGE_PLAYER, TEXTYPE_MULTI, STAND_RIGHT_UP, 6)))
	{
		ERR_MSG(g_hWnd, L"Player_StandRU Texture Loading Failed");
		return E_FAIL;
	}

	return S_OK;
}