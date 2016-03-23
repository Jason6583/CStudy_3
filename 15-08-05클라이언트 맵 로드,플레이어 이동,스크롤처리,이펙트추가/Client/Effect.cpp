#include "StdAfx.h"
#include "Effect.h"

#include "Include.h"

CEffect::CEffect(void)
{
}

CEffect::CEffect( const OBJINFO& Info ) :
CStageDynamic(Info)
{

}


CEffect::~CEffect(void)
{
	Release();
}

HRESULT CEffect::Initialize()
{
	m_SortID = SORTID_SORTY;
	m_pObjKey = L"Effect";
	m_pStateKey = L"Lightining";

	m_fFrame = 0.0f;
	m_Info.vPos = D3DXVECTOR3(0.f, 0.f, 0.f);

	return S_OK;
}

SCENE CEffect::Progress()
{
	Frame_Move(6,6);

	D3DXMATRIX matTrans;
	D3DXMATRIX matRotz;

	const OBJINFO* pPlayerInfo = GET_SINGLE(CObjMgr)->GetInfo(L"Player");
	m_fAngle += D3DXToRadian(90.f * GET_SINGLE(CTimeMgr)->GetTime());
	D3DXMatrixRotationZ(&matRotz,m_fAngle);


	D3DXMatrixTranslation(&matTrans, m_Info.vPos.x, m_Info.vPos.y, m_Info.vPos.z);
	
	//크자이공부					//부모의 행렬
	m_Info.matWorld = matTrans *  matRotz *pPlayerInfo->matWorld;


	return SCENE_NONPASS;
}

void CEffect::Render()
{
	GET_SINGLE(CDevice)->GetSprite()->End();
	GET_SINGLE(CDevice)->GetDevice()->EndScene();

	GET_SINGLE(CDevice)->GetDevice()->BeginScene();
	GET_SINGLE(CDevice)->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);

	GET_SINGLE(CDevice)->GetDevice()->SetRenderState(D3DRS_BLENDOP,D3DBLENDOP_ADD);
	GET_SINGLE(CDevice)->GetDevice()->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_ONE);
	GET_SINGLE(CDevice)->GetDevice()->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_ONE);



	const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(m_pObjKey,m_pStateKey,int(m_fFrame));

	if (pTexInfo == NULL)
	{
		return;
	}
	
	m_Info.vCenter = D3DXVECTOR3(pTexInfo->ImgInfo.Width/2.f + 50.f, pTexInfo->ImgInfo.Height/2.f + 100.f, 0.0f);

	GET_SINGLE(CDevice)->GetSprite()->SetTransform(&m_Info.matWorld);
	GET_SINGLE(CDevice)->GetSprite()->Draw(pTexInfo->pTexture, NULL,&m_Info.vCenter, NULL, D3DCOLOR_ARGB(255,255,255,255));

	GET_SINGLE(CDevice)->GetSprite()->End();
	GET_SINGLE(CDevice)->GetDevice()->EndScene();

	GET_SINGLE(CDevice)->GetDevice()->BeginScene();
	GET_SINGLE(CDevice)->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);

}

void CEffect::Release()
{

}

CObj* CEffect::Clone()
{

	return new CEffect(*this);
}
