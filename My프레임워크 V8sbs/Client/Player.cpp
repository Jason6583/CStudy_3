#include "StdAfx.h"
#include "Player.h"

#include "Include.h"

CPlayer::CPlayer(void)
:m_bClick(false)
,m_iMaxCnt(0.f)
{
}

CPlayer::CPlayer(const OBJINFO& Info)
: CStageDynamic(Info)
, m_iMaxCnt(0.f)
{

}

CPlayer::~CPlayer(void)
{
	Release();
}

HRESULT CPlayer::Initialize( void )
{
	m_SortID = SORTID_SORTY;
	m_pObjKey = STAGE_PLAYER;
	m_pStateKey = STAND_RIGHT;

	m_Info.vCenter = D3DXVECTOR3(64.f / 2.f, 64.f / 2.f, 0.0f);
	m_Info.vPos = D3DXVECTOR3(400.f, 300.f, 0.f);
	m_bMagic = false;

	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);

	ptMouse.x -= LONG(m_vScroll.x);
	ptMouse.y -= LONG(m_vScroll.y);

	m_iMaxCnt = 6;
	
	return S_OK;
}

SCENE CPlayer::Progress( void )
{
	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);

	ptMouse.x -= LONG(m_vScroll.x);
	ptMouse.y -= LONG(m_vScroll.y);

	m_pBestList = GET_SINGLE(CAStar)->GetBestList();

	if(!m_pBestList->empty())
	{
		AStar_Move();

	}

	KeyInput();

	
	D3DXMATRIX		matTrans;		

	D3DXMatrixTranslation(&matTrans, m_Info.vPos.x
		, m_Info.vPos.y, m_Info.vPos.z);

	m_Info.matWorld = matTrans;


	Frame_Move(m_iMaxCnt, m_iMaxCnt);

	return SCENE_NONPASS;
}

void CPlayer::KeyInput(void)
{
	//const vector<TILE*>* pVecTile = GET_SINGLE(CObjMgr)->GetTileInfo();


	if(PUSH_KEY(KEY_LBUTTON))
	{
		if (m_bClick)
		{
			return;
		}
		m_bClick = true;


		AStar_start(m_Info.vPos, SetMouseInfo().vPos);
	}
	else
		m_bClick = false;



	//if(PUSH_KEY(KEY_F5))
	//{
	//	if(m_bMagicReady==true)
	//		return;

	//	 m_bMagicReady = true;
	//	
	//}

	//CObj* m_pMonster = CObjMgr::GetInstance()->GetObj(OBJECT_STAGE_MONSTER);


	//if(m_bMagicReady == true)
	//{
	//	//마우스오버 
	//	//ShowCursor(FALSE);//마우스 커서를 않보이게
	//	HCURSOR hCursor; // 로드할 변수를 하나 선언합니다.
	//	hCursor = LoadCursor( NULL, NULL );
	//	SetCursor( hCursor );

	//	CObjProto*		m_pObjProto  = new CStageProto;
	//	CObjMgr::GetInstance()->AddObject(OBJECT_STAGE_MOUSE, m_pObjProto);

	//	if(PUSH_KEY(KEY_RBUTTON))
	//	{
	//		if(PtInRect(&((CMonster*)m_pMonster)->GetRect(),ptMouse))
	//		{
	//			SetWindowText(g_hWnd,L"충돌");		
	//			CreateMagic(true);
	//			m_bMagicReady = false;
	//		}
	//		else
	//		{
	//			m_bMagicReady = false;
	//		}

	//	}
	//}
	//else
	//{
	//	//마우스오버 끄기
	//	ShowCursor(TRUE);
	//	CObjMgr::GetInstance()->DeleteObj(OBJECT_STAGE_MOUSE);
	//	//HCURSOR hCursor; // 로드할 변수를 하나 선언합니다.
	//	//hCursor = LoadCursor( NULL, IDC_ARROW );
	//	//SetCursor( hCursor );
	//}


	//방향설정
					
	DWORD mdKey =	GET_SINGLE(CKeyMgr)->GetKey();

	if(mdKey == NULL&&m_pBestList->empty()&&m_bMagic==false)
	{	
		m_iMaxCnt = 6;
		//마우스 좌표가 캐리터좌표 보다 우
		if(ptMouse.y >= GetRect().top && ptMouse.y <= GetRect().bottom && ptMouse.x > GetRect().right)
		{
			//lstrcpy(m_pStateKey,L"StandR");
			m_pStateKey = STAND_RIGHT;
		}
		//마우스 좌표가 캐리터좌표 보다 우상
		if(ptMouse.x  > GetRect().right && ptMouse.y  < GetRect().top)
		{
			//m_iStateID = OBJECT_STATEID_PLAYER_STAND_RU;
			//lstrcpy(m_pStateKey,L"StandRU");
			m_pStateKey = STAND_RIGHT_UP;
		}
		//마우스 좌표가 캐리터좌표 보다 상
		if(ptMouse.x  >= GetRect().left && ptMouse.x  <= GetRect().right && ptMouse.y  < GetRect().top)
		{
			//m_iStateID = OBJECT_STATEID_PLAYER_STAND_U;
			//lstrcpy(m_pStateKey,L"StandU");
			m_pStateKey = STAND_UP;
		}
		//마우스 좌표가 캐리터좌표 보다 좌상
		if(ptMouse.x  < GetRect().left && ptMouse.y  < GetRect().top)
		{
			//m_iStateID = OBJECT_STATEID_PLAYER_STAND_LU;
			//lstrcpy(m_pStateKey,L"StandLU");
			m_pStateKey = STAND_LEFT_UP;
		}
		//마우스 좌표가 캐리터좌표 보다 좌
		if(ptMouse.y  >= GetRect().top && ptMouse.y  <= GetRect().bottom && ptMouse.x  < GetRect().left)
		{
			//m_iStateID = OBJECT_STATEID_PLAYER_STAND_L;
			//lstrcpy(m_pStateKey,L"StandL");
			m_pStateKey = STAND_LEFT;
		}
		//마우스 좌표가 캐리터좌표 보다 좌하
		if(ptMouse.x  < GetRect().left && ptMouse.y  > GetRect().bottom)
		{
			//m_iStateID = OBJECT_STATEID_PLAYER_STAND_LD;
			//lstrcpy(m_pStateKey,L"StandLD");
			m_pStateKey = STAND_LEFT_DOWN;
		}
		//마우스 좌표가 캐리터좌표 보다 하
		if(ptMouse.x  >= GetRect().left && ptMouse.x  <= GetRect().right && ptMouse.y  > GetRect().bottom)
		{
			//m_iStateID = OBJECT_STATEID_PLAYER_STAND_D;
			//lstrcpy(m_pStateKey,L"StandD");
			m_pStateKey = STAND_DOWN;
		}
		//마우스 좌표가 캐리터좌표 보다 우하
		if(ptMouse.x  > GetRect().right && ptMouse.y  > GetRect().bottom)
		{
			//m_iStateID = OBJECT_STATEID_PLAYER_STAND_RD;
			//lstrcpy(m_pStateKey,L"StandRD");
			m_pStateKey = STAND_RIGHT_DOWN;
		}

	}

}
void CPlayer::Render( void )
{
	const TEXINFO*	pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(m_pObjKey, m_pStateKey, int(m_fFrame));

	if(pTexInfo == NULL)
		return;

	m_Info.vCenter = D3DXVECTOR3(pTexInfo->ImgInfo.Width / 2.f
		, pTexInfo->ImgInfo.Height / 2.f , 0.0f);

	GET_SINGLE(CDevice)->GetSprite()->SetTransform(&m_Info.matWorld);
	GET_SINGLE(CDevice)->GetSprite()->Draw(pTexInfo->pTexture, NULL
		, &m_Info.vCenter, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void CPlayer::Release( void )
{

}

const OBJINFO CPlayer::SetMouseInfo(void)
{
	//POINT		ptMouse;

	GetCursorPos(&ptMouse);

	ScreenToClient(g_hWnd, &ptMouse);

	OBJINFO			MouseInfo;
	ZeroMemory(&MouseInfo, sizeof(MouseInfo));

	MouseInfo.vPos = D3DXVECTOR3(float(ptMouse.x), float(ptMouse.y), 0.f);	

	return MouseInfo;
}

CObj* CPlayer::Clone( void )
{
	return new CPlayer(*this);
}
