#include "StdAfx.h"
#include "Ball.h"
#include "Include.h"


CBall::CBall(void)
{
}

CBall::CBall( const OBJINFO& Info ) : 
CLogoDynamic(Info)//�ڱⲲ ������ Clogodynamic���� �Ѱ��ش� 
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

	m_Info.matWorld = matTrans; //Ʈ������ �־ �̵����� ����
	
	

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

	return new CBall(*this); //�ڱⲨ�� ��������ؼ� �ִ´� 
}
