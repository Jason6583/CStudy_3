#include "StdAfx.h"
#include "BackGround.h"


CBackGround::CBackGround(void)
{
}

CBackGround::CBackGround( const OBJINFO& Info ) :
CLogoStatic(Info)
{

}


CBackGround::~CBackGround(void)
{
}

HRESULT CBackGround::Initialize()
{

	return S_OK;
}

void CBackGround::Progress()
{

}

void CBackGround::Render()
{

}

void CBackGround::Release()
{

}

CObj* CBackGround::Clone()
{
	return new CBackGround(*this); //��������� �ϸ鼭 ���� �Ѿ�鼭 ���� �� 
}
