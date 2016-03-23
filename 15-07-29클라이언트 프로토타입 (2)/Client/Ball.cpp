#include "StdAfx.h"
#include "Ball.h"
#include "Include.h"


CBall::CBall(void)
{
}

CBall::CBall( const OBJINFO& Info ) : 
CLogoDynamic(Info)//자기께 들어오면 Clogodynamic한테 넘겨준다 
{

}


CBall::~CBall(void)
{
	Release();
}

HRESULT CBall::Initialize()
{
	m_pObjKey = L"Ball";
	m_pStateKey = NULL;

	return S_OK;
}

void CBall::Progress()
{
	D3DXMATRIX	matTrans;

	D3DXMatrixTranslation(&matTrans,m_Info.vPos.x, m_Info.vPos.y, m_Info.vPos.z);

	m_Info.matWorld = matTrans; //트랜스만 넣어서 이동값만 셋팅
	
	

}

void CBall::Render()
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

void CBall::Release()
{

}

CObj* CBall::Clone()
{

	return new CBall(*this); //자기꺼를 복사생성해서 넣는다 
}
