#include "StdAfx.h"
#include "MainGame.h"
#include "Player.h"
#include "Monster.h"

CMainGame::CMainGame(void)
{
}


CMainGame::~CMainGame(void)
{
	Release();
}

void CMainGame::Initialize()
{
	m_hdc = GetDC(g_hWnd);

	m_pPlayer = new CPlayer;
	m_pPlayer->Initialize();

	m_pMonster = new CMonster;
	m_pMonster->Initialize();

}

void CMainGame::Progress()
{
	Rectangle(m_hdc,0,0,800,600);
	m_pPlayer->Progress();
	m_pMonster->Progress();
}

void CMainGame::Render()
{
	m_pPlayer->Render(m_hdc);
	m_pMonster->Render(m_hdc);
}

void CMainGame::Release()
{
	delete m_pPlayer;
	m_pPlayer = NULL;

	delete m_pMonster;
	m_pMonster = NULL;

	ReleaseDC(g_hWnd,m_hdc);
}
