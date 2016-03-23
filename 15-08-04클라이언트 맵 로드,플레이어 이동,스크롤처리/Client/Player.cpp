#include "StdAfx.h"
#include "Player.h"
#include "Include.h"

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
	m_SortID = SORTID_SORTY;
	m_pObjKey = L"Player";
	m_pStateKey = L"Stand";



	return S_OK;
}

SCENE CPlayer::Progress()
{
	Frame_Move(26,26);
	//SetDirect(SetMouseInfo());

	if (GetKeyState(VK_LBUTTON) < 0)
	{
		Astar_start(m_Info.vPos,SetMouseInfo().vPos);
	}

	Astar_Move();


	D3DXMATRIX	matTrans;
	//D3DXMATRIX	matRotZ;

	//D3DXMatrixRotationZ(&matRotZ,m_fAngle);
	//D3DXVec3TransformNormal(&m_Info.vDir, &m_Info.vLook, &matRotZ);	
	//m_Info.vPos += m_Info.vDir * 100.f * GET_SINGLE(CTimeMgr)->GetTime();
	
	D3DXMatrixTranslation(&matTrans, m_Info.vPos.x + GET_SINGLE(CObjMgr)->GetScrollInfo()->x  , m_Info.vPos.y + GET_SINGLE(CObjMgr)->GetScrollInfo()->y, m_Info.vPos.z);

	m_Info.matWorld =  matTrans;



	return SCENE_NONPASS;
}

void CPlayer::Render()
{
	const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(m_pObjKey,m_pStateKey,int(m_fFrame));

	if (pTexInfo == NULL)
	{
		return;
	}

	m_Info.vCenter = D3DXVECTOR3(pTexInfo->ImgInfo.Width / 2.f , pTexInfo->ImgInfo.Height / 2.f, 0);

	GET_SINGLE(CDevice)->GetSprite()->SetTransform(&m_Info.matWorld);

	GET_SINGLE(CDevice)->GetSprite()->Draw(pTexInfo->pTexture, NULL,&m_Info.vCenter, NULL, D3DCOLOR_ARGB(255,255,255,255));


}

void CPlayer::Release()
{

}

CObj* CPlayer::Clone()
{
	return new CPlayer(*this);
}

const OBJINFO CPlayer::SetMouseInfo()
{
	POINT ptMouse;
	GetCursorPos(&ptMouse);

	ScreenToClient(g_hWnd,&ptMouse);

	OBJINFO Info;
	ZeroMemory(&Info,sizeof(Info));

	Info.vPos = D3DXVECTOR3(float(ptMouse.x) - GET_SINGLE(CObjMgr)->GetScrollInfo()->x ,float(ptMouse.y) - GET_SINGLE(CObjMgr)->GetScrollInfo()->y,0.f);

	return Info;
}
