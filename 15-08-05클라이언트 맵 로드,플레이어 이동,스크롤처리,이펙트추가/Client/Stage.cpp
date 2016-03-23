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

HRESULT CStage::Initialize()
{
	GET_SINGLE(CTimeMgr)->InitTimeMgr();

	//객체를 생성하기 위한 준비
	m_pPrototype = new CStageObjProto;
	if (FAILED(m_pPrototype->InitProtoInstance()))
	{
		ERR_MSG(g_hWnd,L"원형 객체 생성 실패");
		return E_FAIL;
	}

	if (FAILED(GET_SINGLE(CObjMgr)->AddObject(m_pPrototype,L"StageBack")))
	{
		ERR_MSG(g_hWnd,L"객체 생성 실패");
		return E_FAIL;
	}

	if (FAILED(GET_SINGLE(CObjMgr)->AddObject(m_pPrototype,L"Player")))
	{
		ERR_MSG(g_hWnd,L"객체 생성 실패");
		return E_FAIL;
	}

	if (FAILED(GET_SINGLE(CObjMgr)->AddObject(m_pPrototype,L"Effect")))
	{
		ERR_MSG(g_hWnd,L"객체 생성 실패");
		return E_FAIL;
	}


	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Tile/Tile%d.png",L"StageBack",TEXTYPE_MULTI,L"Tile",38)))
	{
		ERR_MSG(g_hWnd,L"StageTileTexture 실패");
		return E_FAIL;
	}

	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Stage/Player/Stand/archon%04d.bmp",L"Player",TEXTYPE_MULTI,L"Stand",27)))
	{
		ERR_MSG(g_hWnd,L"Player Texture 실패");
		return E_FAIL;
	}

	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Stage/lightning/Lightning%d.png",L"Effect",TEXTYPE_MULTI,L"Lightining",6)))
	{
		ERR_MSG(g_hWnd,L"Lightning 실패");
		return E_FAIL;
	}




	return S_OK;
}

void CStage::Progress()
{
	GET_SINGLE(CTimeMgr)->SetTime();

	SCENE SceneID = GET_SINGLE(CObjMgr)->Progress();

	if (SceneID >= 0) //다른씬이 생기면 넘어갈수 있게함
	{
		GET_SINGLE(CSceneMgr)->InitScene(SceneID);
		return;
	}
	
}

void CStage::Render()
{
	GET_SINGLE(CObjMgr)->Render();


}

void CStage::Release()
{
	DESTROY_SINGLE(CObjMgr);
	DESTROY_SINGLE(CTextureMgr);
	SAFE_DELETE(m_pPrototype);
	DESTROY_SINGLE(CTimeMgr);

}
