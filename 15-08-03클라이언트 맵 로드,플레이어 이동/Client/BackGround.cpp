#include "StdAfx.h"
#include "BackGround.h"
#include "Include.h"

CBackGround::CBackGround(void)
{
}

CBackGround::CBackGround( const OBJINFO& Info ) :
CLogoStatic(Info)
{

}

CBackGround::~CBackGround(void)
{
	Release();
}

HRESULT CBackGround::Initialize()
{
	m_SortID = SORTID_FIRST;
	m_pObjKey = L"LogoBack";
	m_pStateKey = NULL;


	return S_OK;
}

SCENE CBackGround::Progress()
{
	D3DXMATRIX	matTrans;

	D3DXMatrixTranslation(&matTrans,m_Info.vPos.x, m_Info.vPos.y, m_Info.vPos.z);

	m_Info.matWorld = matTrans;

	return SCENE_NONPASS;
}

void CBackGround::Render()
{

	const TEXINFO* pTextInfo = GET_SINGLE(CTextureMgr)->GetTexture(m_pObjKey);

	if (pTextInfo == NULL)
	{
		return;
	}
	m_Info.vCenter = D3DXVECTOR3(pTextInfo->ImgInfo.Width / 2.f , pTextInfo->ImgInfo.Height / 2.f, 0);

	GET_SINGLE(CDevice)->GetSprite()->SetTransform(&m_Info.matWorld);

	GET_SINGLE(CDevice)->GetSprite()->Draw(pTextInfo->pTexture, NULL,&m_Info.vCenter, NULL, D3DCOLOR_ARGB(255,255,255,255));


}

void CBackGround::Release()
{

}

CObj* CBackGround::Clone()
{
	return new CBackGround(*this); //복사생성을 하면서 값이 넘어가면서 값을 줌 
}
