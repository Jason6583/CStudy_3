#include "StdAfx.h"
#include "Logo_Button.h"

#include "Include.h"

CLogo_Button::CLogo_Button(void)
{
}

CLogo_Button::CLogo_Button(const OBJINFO& Info)
: CLogoDynamic(Info)
{

}

CLogo_Button::~CLogo_Button(void)
{
	Release();
}

HRESULT CLogo_Button::Initialize( void )
{
	m_SortID = SORTID_SORTY;
	m_pObjKey = L"LogoButton";
	m_pStateKey = NULL;
	m_Info.vPos		= D3DXVECTOR3(694.f, 472.f, 0.0f);
	m_Info.vCenter	= D3DXVECTOR3(51.f/2, 25.f/2, 0.0f);
	m_bRenderCheck = false;		
	return S_OK;
}

SCENE CLogo_Button::Progress( void )
{
	OBJINFO MouseInfo = SetMouseInfo();

	//Chase_Move(MouseInfo);
	/*m_fAngle += D3DXToRadian(90.0f * GET_SINGLE(CTimeMgr)->GetTime());

	static float fTest;

	fTest += GET_SINGLE(CTimeMgr)->GetTime();

	if(fTest > 3.f)		
		return SCENE_STAGE;*/


	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd,&pt);

	if(PtInRect(&GetRect(), pt))
	{
		m_bRenderCheck = true;		
		if(GetAsyncKeyState(VK_LBUTTON))
		{
			return SCENE_STAGE;
		}	

	}
	else
	{
		m_bRenderCheck = false;		
	}




	D3DXMATRIX		matTrans;
	D3DXMATRIX		matRotZ;



	D3DXMatrixTranslation(&matTrans, m_Info.vPos.x
		, m_Info.vPos.y, m_Info.vPos.z);

	m_Info.matWorld =  matTrans;

	return SCENE_NONPASS;
}

void CLogo_Button::Render( void )
{
	if(m_bRenderCheck == true)
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

}

const OBJINFO CLogo_Button::SetMouseInfo(void)
{
	POINT		ptMouse;

	GetCursorPos(&ptMouse);

	ScreenToClient(g_hWnd, &ptMouse);

	OBJINFO			BallInfo;
	ZeroMemory(&BallInfo, sizeof(BallInfo));

	BallInfo.vPos = D3DXVECTOR3(float(ptMouse.x), float(ptMouse.y), 0.f);	

	return BallInfo;
}

CObj* CLogo_Button::Clone(void)
{
	return new CLogo_Button(*this);
}

void CLogo_Button::Release( void )
{

}
