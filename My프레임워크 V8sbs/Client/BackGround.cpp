#include "StdAfx.h"
#include "BackGround.h"

#include "Include.h"

CBackGround::CBackGround(void)
{
}
CBackGround::CBackGround(const OBJINFO& Info)
: CStageStatic(Info)
{

}

CBackGround::~CBackGround(void)
{
	Release();
}

HRESULT CBackGround::Initialize(void)
{
	m_SortID = SORTID_FIRST;
	InitTileFormFile();
	m_pObjKey = L"BackGround";
	m_pStateKey = L"Desert";
	m_Info.vPos = D3DXVECTOR3(3200/2 ,1374/2,0.f);
	
	return S_OK;
}
SCENE CBackGround::Progress(void)
{
	/*GET_SINGLE(CAStar)->AstarStart(180, 202);*/

	return SCENE_NONPASS;
}

void CBackGround::Render(void)
{
	D3DXMATRIX		matTrans;


	

	const TEXINFO*	pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(m_pObjKey, L"Desert", 0);

		if(pTexInfo == NULL)
			return;

		D3DXMatrixTranslation(&matTrans, m_Info.vPos.x, m_Info.vPos.y,m_Info.vPos.z);


		m_Info.matWorld = matTrans;

		m_Info.vCenter = D3DXVECTOR3(3200/2,1374/2 , 0.f);

		GET_SINGLE(CDevice)->GetSprite()->SetTransform(&m_Info.matWorld);
		GET_SINGLE(CDevice)->GetSprite()->Draw(pTexInfo->pTexture, NULL
			, &m_Info.vCenter, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	

			TCHAR			szTmp[128] = L"";

			for (int i = 0; i < 20; ++i)
			{
				for (int j = 0; j < 8; ++j)		
				{	
					int		iCullX = -m_vScroll.x / TILESIZEX;
					int		iCullY = -m_vScroll.y / (TILESIZEY / 2);

					int		iIndex = (i + iCullY) * TILECNTX + (j + iCullX);	

					if(iIndex < 0|| iIndex >= TILECNTX * TILECNTY)
					{
						continue;
					}
					

					const TEXINFO*	pTexInfo2 = GET_SINGLE(CTextureMgr)->GetTexture(m_pObjKey, L"Tile", m_vecTile[iIndex]->byDrawId);

					if(pTexInfo2 == NULL)
						return;

					D3DXMatrixTranslation(&matTrans, m_vecTile[iIndex]->vPos.x+ m_vScroll.x, m_vecTile[iIndex]->vPos.y+ m_vScroll.y, 0.f);

					m_Info.matWorld = matTrans;

					m_Info.vCenter = D3DXVECTOR3(65.0f, 34.0f, 0.0f);
					if(GetAsyncKeyState('1'))
					{
						GET_SINGLE(CDevice)->GetSprite()->SetTransform(&m_Info.matWorld);
						GET_SINGLE(CDevice)->GetSprite()->Draw(pTexInfo2->pTexture, NULL, &m_Info.vCenter, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

						wsprintf(szTmp, L"%d", iIndex);
						//swprintf(szTmp, L"%f", 0.5);

						RECT		rcFont = {0};
						GET_SINGLE(CDevice)->GetFont()->DrawTextW(GET_SINGLE(CDevice)->GetSprite()
							, szTmp, lstrlen(szTmp), &rcFont, DT_NOCLIP, D3DCOLOR_ARGB(255, 0, 0, 0));
					}
				}
			}
	

		


}

void CBackGround::Release(void)
{
	for(unsigned int i= 0; i< m_vecTile.size(); ++i)
	{
		SELF_DELETE(m_vecTile[i]) ;
	}
	m_vecTile.clear();

}

void CBackGround::InitTileFormFile(void)
{
	HANDLE		hFile;
	DWORD		dwByte;

	hFile = CreateFile(L"../Data/Tile.dat", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	while(true)
	{
		TILE*		pTile = new TILE;
		ReadFile(hFile, pTile, sizeof(TILE), &dwByte, NULL);
		if(dwByte == 0)
		{
			SAFE_DELETE(pTile);
			break;
		}
		m_vecTile.push_back(pTile);
	}
	CloseHandle(hFile);
}
CObj* CBackGround::Clone(void)
{
	return new CBackGround(*this);
}