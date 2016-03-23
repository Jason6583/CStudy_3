#include "StdAfx.h"
#include "LogoBack.h"

#include "Include.h"

CLogoBack::CLogoBack(void)
{
}


CLogoBack::CLogoBack(const OBJINFO& Info)
: CLogoStatic(Info)
{
	

}

CLogoBack::~CLogoBack(void)
{
	Release();
}

HRESULT CLogoBack::Initialize( void )
{
	m_SortID = SORTID_FIRST;
	m_pObjKey = L"LogoBack";
	m_pStateKey = NULL;

	return S_OK;
}

SCENE CLogoBack::Progress( void )
{	
	D3DXMATRIX		matTrans;

	D3DXMatrixTranslation(&matTrans, m_Info.vPos.x
		, m_Info.vPos.y
		, m_Info.vPos.z);

	float			fAngle = 0.0f;

	fAngle += 90.0f * GET_SINGLE(CTimeMgr)->GetTime();

	m_Info.matWorld = matTrans;

	return SCENE_NONPASS;
}

void CLogoBack::Render( void )
{	
	const TEXINFO*	pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(m_pObjKey);

	if(pTexInfo == NULL)
		return;

	m_Info.vCenter = D3DXVECTOR3(pTexInfo->ImgInfo.Width / 2.f
		, pTexInfo->ImgInfo.Height / 2.f, 0.0f);

	GET_SINGLE(CDevice)->GetSprite()->SetTransform(&m_Info.matWorld);
	GET_SINGLE(CDevice)->GetSprite()->Draw(pTexInfo->pTexture, NULL
		, &m_Info.vCenter, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void CLogoBack::Release( void )
{

}

CObj* CLogoBack::Clone( void )
{
	return new CLogoBack(*this);
}
