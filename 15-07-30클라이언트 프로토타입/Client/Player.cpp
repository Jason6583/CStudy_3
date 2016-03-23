#include "StdAfx.h"
#include "Player.h"


CPlayer::CPlayer(void)
{
}

CPlayer::CPlayer( const OBJINFO& Info ) : 
CStageDynamic(Info)
{

}


CPlayer::~CPlayer(void)
{
}

HRESULT CPlayer::Initialize()
{

	return S_OK;
}

SCENE CPlayer::Progress()
{

	return SCENE_NONPASS;
}

void CPlayer::Render()
{

}

void CPlayer::Release()
{

}

CObj* CPlayer::Clone()
{
	return new CPlayer(*this);
}
