#include "StdAfx.h"
#include "StageBack.h"
#include "Include.h"

CStageBack::CStageBack(void)
{
}

CStageBack::CStageBack( const OBJINFO& Info ) :
CStageStatic(Info)
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

	for (unsigned int i=0; i<m_vecTile.size(); ++i)
	{
		const TEXINFO* pTexInfo= GET_SINGLE(CTextureMgr)->GetTexture(m_pObjKey,m_pStateKey,m_vecTile[i]->byDrawId);

		if (pTexInfo == NULL)
		{
			return;
		}
		D3DXMatrixTranslation(&matTrans,m_vecTile[i]->vPos.x, m_vecTile[i]->vPos.y ,m_vecTile[i]->vPos.z);

		m_Info.matWorld = matTrans;

		m_Info.vCenter = D3DXVECTOR3(65.f, 34.f, 0.f);

		GET_SINGLE(CDevice)->GetSprite()->SetTransform(&m_Info.matWorld);
		GET_SINGLE(CDevice)->GetSprite()->Draw(pTexInfo->pTexture, NULL,&m_Info.vCenter, NULL, D3DCOLOR_ARGB(255,255,255,255));
		
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
