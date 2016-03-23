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
	m_SortID = SORTID_SORTY;
	m_pObjKey = L"Ball";
	m_pStateKey = NULL;


	return S_OK;
}

SCENE CBall::Progress()
{
	D3DXMATRIX	matTrans;
	D3DXMATRIX	matRotZ;
	
	OBJINFO MouseInfo = SetMouseInfo();


	Chase_Move(MouseInfo);

	m_fAngle += D3DXToRadian(90.f * GET_SINGLE(CTimeMgr)->GetTime());

	static float fTest;
	fTest += GET_SINGLE(CTimeMgr)->GetTime();	
		
	if (fTest > 3.f)
	{
		return SCENE_STAGE;
	}


	D3DXMatrixTranslation(&matTrans,m_Info.vPos.x, m_Info.vPos.y, m_Info.vPos.z);
	D3DXMatrixRotationZ(&matRotZ,m_fAngle);
	
	m_Info.matWorld = matRotZ * matTrans; //트랜스만 넣어서 이동값만 셋팅
	
	
	return SCENE_NONPASS;
}

void CBall::Render()
{
	const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(m_pObjKey);

	if (pTexInfo == NULL)
	{
		return;
	}

	m_Info.vCenter = D3DXVECTOR3(pTexInfo->ImgInfo.Width / 2.f , pTexInfo->ImgInfo.Height / 2.f, 0);

	GET_SINGLE(CDevice)->GetSprite()->SetTransform(&m_Info.matWorld);

	GET_SINGLE(CDevice)->GetSprite()->Draw(pTexInfo->pTexture, NULL,&m_Info.vCenter, NULL, D3DCOLOR_ARGB(255,255,255,255));



}

void CBall::Release()
{

}

CObj* CBall::Clone()
{

	return new CBall(*this); //자기꺼를 복사생성해서 넣는다 
}

const OBJINFO CBall::SetMouseInfo()
{

	POINT ptMouse;
	GetCursorPos(&ptMouse);

	ScreenToClient(g_hWnd,&ptMouse);

	OBJINFO Info;
	ZeroMemory(&Info,sizeof(Info));

	Info.vPos = D3DXVECTOR3(float(ptMouse.x),float(ptMouse.y),0.f);

	return Info;
}
