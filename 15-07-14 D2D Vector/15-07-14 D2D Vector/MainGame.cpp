#include "StdAfx.h"
#include "MainGame.h"
#include "Player.h"

CMainGame::CMainGame(void)
{
}


CMainGame::~CMainGame(void)
{
}

void CMainGame::Initialize()
{
	m_hdc = GetDC(g_hWnd);

	m_pPlayer = new CPlayer;
	m_pPlayer->Initialize();
}

void CMainGame::Progress()
{
	Rectangle(m_hdc,0,0,800,600);
	m_pPlayer->Progress();

}

void CMainGame::Render()
{
	m_pPlayer->Render(m_hdc);
}

void CMainGame::Release()
{
	delete m_pPlayer;
	m_pPlayer = NULL;

	ReleaseDC(g_hWnd,m_hdc);
}
