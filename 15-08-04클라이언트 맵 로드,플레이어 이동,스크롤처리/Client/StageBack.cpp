#include "StdAfx.h"
#include "StageBack.h"
#include "Include.h"

CStageBack::CStageBack(void) :
m_vScroll(0.f,0.f,0.f)
{
}

CStageBack::CStageBack( const OBJINFO& Info ) :
CStageStatic(Info),
m_vScroll(0.f,0.f,0.f)
{

}


CStageBack::~CStageBack(void)
{
}

HRESULT CStageBack::Initialize()
{
	m_SortID = SORTID_FIRST;
	InitTileLoadfile();
	m_pObjKey = L"StageBack";
	m_pStateKey = L"Tile";



	return S_OK;
}

SCENE CStageBack::Progress()
{

	return SCENE_NONPASS;
}

void CStageBack::Render()
{
	D3DXMATRIX matTrans;

	TCHAR szTmp[128] = L"";

	//for (unsigned int i=0; i<m_vecTile.size(); ++i)
	
	for (int i = 0; i< 19; ++i)
	{
		for (int j = 0; j<8; ++j)
		{
			int nIndex = (i + -int(m_vScroll.y)/(TILESIZEY/2)) * TILECNTX + (j + -int(m_vScroll.x)/TILESIZEX);
					
					
			if(nIndex >= TILECNTX * TILECNTY || nIndex<0 )
				continue;

			const TEXINFO* pTexInfo= GET_SINGLE(CTextureMgr)->GetTexture(m_pObjKey,m_pStateKey,m_vecTile[nIndex]->byDrawId);

			if (pTexInfo == NULL)
			{
				return;
			}
			D3DXMatrixTranslation(&matTrans,m_vecTile[nIndex]->vPos.x + m_vScroll.x , m_vecTile[nIndex]->vPos.y + m_vScroll.y ,m_vecTile[nIndex]->vPos.z);

			m_Info.matWorld = matTrans;

			m_Info.vCenter = D3DXVECTOR3(65.f, 34.f, 0.f);

			GET_SINGLE(CDevice)->GetSprite()->SetTransform(&m_Info.matWorld);
			GET_SINGLE(CDevice)->GetSprite()->Draw(pTexInfo->pTexture, NULL,&m_Info.vCenter, NULL, D3DCOLOR_ARGB(255,255,255,255));

			wsprintf(szTmp,L"%d",nIndex);

			RECT	rcRect = {0};
			GET_SINGLE(CDevice)->GetFont()->DrawTextW(GET_SINGLE(CDevice)->GetSprite(),szTmp,lstrlen(szTmp),&rcRect,DT_NOCLIP,D3DCOLOR_ARGB(255,0,0,0));

		}
		
	}

}

void CStageBack::Release()
{

}

CObj* CStageBack::Clone()
{

	return new CStageBack(*this);
}

void CStageBack::InitTileLoadfile()
{
	HANDLE	hFile;
	DWORD	dwByte;

	hFile = CreateFile(L"../Data/Tile.dat",GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);

	while(true)
	{
		TILE*	pTile = new TILE;
		ReadFile(hFile,pTile,sizeof(TILE),&dwByte,NULL);
		if (dwByte == 0)
		{
			SAFE_DELETE(pTile);
			break;
		}

		m_vecTile.push_back(pTile);
	}

	CloseHandle(hFile);
}

void CStageBack::MapScroll()
{
	POINT ptMouse;

	GetCursorPos(&ptMouse);

	ScreenToClient(g_hWnd,&ptMouse);

	if (WINSIZEX - 2 <= ptMouse.x)
	{
		m_vScroll.x -= 100.f * GET_SINGLE(CTimeMgr)->GetTime();
	}
	if (2 >= ptMouse.x)
	{
		m_vScroll.x += 100.f * GET_SINGLE(CTimeMgr)->GetTime();
	}
	if (WINSIZEY - 2 <= ptMouse.y)
	{
		m_vScroll.y -= 100.f * GET_SINGLE(CTimeMgr)->GetTime();
	}
	if ( 2 >= ptMouse.y)
	{
		m_vScroll.y += 100.f * GET_SINGLE(CTimeMgr)->GetTime();
	}
}
