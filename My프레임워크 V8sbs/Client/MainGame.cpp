#include "StdAfx.h"
#include "MainGame.h"

#include "Include.h"

CMainGame::CMainGame(void)
{
}

CMainGame::~CMainGame(void)
{
	Release();
}

HRESULT CMainGame::Initialize(void)
{
	if(FAILED(GET_SINGLE(CDevice)->InitDevice(WINMODE_FULL)))
	{
		ERR_MSG(g_hWnd, L"장치초기화 실패");
		return E_FAIL;
	}

	if(FAILED(GET_SINGLE(CSceneMgr)->InitScene(SCENE_LOGO)))
	{
		ERR_MSG(g_hWnd, L"씬초기화 실패");
		return E_FAIL;
	}
	return S_OK;
}
void CMainGame::Progress(void)
{
	GET_SINGLE(CSceneMgr)->Progress();
}
void CMainGame::Render(void)
{
	GET_SINGLE(CDevice)->Render_Begin();
	GET_SINGLE(CSceneMgr)->Render();
	GET_SINGLE(CDevice)->Render_End();
}

void CMainGame::Release(void)
{
	DESTROY_SINGLE(CDevice);
	DESTROY_SINGLE(CSceneMgr);
	DESTROY_SINGLE(CObjMgr);
	DESTROY_SINGLE(CAStar);
	DESTROY_SINGLE(CSortMgr);
}