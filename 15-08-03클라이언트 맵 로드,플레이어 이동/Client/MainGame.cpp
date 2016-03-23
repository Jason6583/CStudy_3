#include "StdAfx.h"
#include "MainGame.h"
#include "Include.h"

CMainGame::CMainGame(void)
{
}


CMainGame::~CMainGame(void)
{
}

HRESULT CMainGame::Initialize()
{
	if (FAILED(GET_SINGLE(CDevice)->InitDevice(WINMODE_WIN)))
	{
		ERR_MSG(g_hWnd,L"장치 초기화 실패");
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CSceneMgr)->InitScene(SCENE_LOGO)))
	{
		ERR_MSG(g_hWnd,L"씬 초기화 실패");
		return E_FAIL;
	}

	return S_OK;
}

void CMainGame::Progress()
{
	GET_SINGLE(CSceneMgr)->Progress();
}

void CMainGame::Render()
{
	GET_SINGLE(CDevice)->Render_Begin();
	GET_SINGLE(CSceneMgr)->Render();
	GET_SINGLE(CDevice)->Render_End();
}

void CMainGame::Release()
{
	DESTROY_SINGLE(CDevice);
	DESTROY_SINGLE(CSceneMgr);
}
