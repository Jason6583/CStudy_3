#include "StdAfx.h"
#include "Obj.h"

#include "Include.h"

D3DXVECTOR2	CObj::m_vScroll;

CObj::CObj(void)
: m_fFrame(0.f)
{
}

CObj::CObj(const OBJINFO& Info)
: m_Info(Info)
, m_fFrame(0.f)
{

}
CObj::~CObj(void)
{
}


void CObj::Frame_Move(const float& fCnt
					  , const float& fMax)
{
	m_fFrame += fCnt * GET_SINGLE(CTimeMgr)->GetTime();

	if(m_fFrame > fMax)
		m_fFrame = 0.f;	
}


int CObj::GetTileIndex(const D3DXVECTOR3& vPos)
{
	const vector<TILE*>* pVecTile = GET_SINGLE(CObjMgr)->GetTileInfo();

	for (unsigned int i = 0; i < pVecTile->size(); ++i)
	{
		if(CollisionMouseToTile(vPos, (*pVecTile)[i]))
		{
			return i;
		}
	}	
	return -1;
}

bool CObj::CollisionMouseToTile(D3DXVECTOR3 vPos
										 , const TILE* pTileInfo)
{
	// y = ax + b;
	// a ?
	float		fGrad = (TILESIZEY / 2.f) / (TILESIZEX / 2.f);

	// b?
	// b = y - ax
	D3DXVECTOR3		vPoint[4];
	vPoint[0] = D3DXVECTOR3(pTileInfo->vPos.x, pTileInfo->vPos.y + TILESIZEY / 2.f, 0.f);
	vPoint[1] = D3DXVECTOR3(pTileInfo->vPos.x + TILESIZEX / 2.f, pTileInfo->vPos.y, 0.f);
	vPoint[2] = D3DXVECTOR3(pTileInfo->vPos.x, pTileInfo->vPos.y - TILESIZEY / 2.f, 0.f);
	vPoint[3] = D3DXVECTOR3(pTileInfo->vPos.x - TILESIZEX / 2.f, pTileInfo->vPos.y, 0.f);

	float		fB[4] = {vPoint[0].y - fGrad * vPoint[0].x
		, vPoint[1].y - -fGrad * vPoint[1].x
		, vPoint[2].y - fGrad * vPoint[2].x
		, vPoint[3].y - -fGrad * vPoint[3].x};

	// y = ax + b
	// y - ax - b = 0 送識掻
	// y - ax - b < 0 送識馬
	// y - ax - b > 0 送識雌

	if(vPos.y - fGrad * vPos.x - fB[0] < 0
		&& vPos.y - -fGrad * vPos.x - fB[1] < 0
		&& vPos.y - fGrad * vPos.x - fB[2] >= 0
		&& vPos.y - -fGrad * vPos.x - fB[3] >= 0)
	{
		return true;
	}
	return false;
}


RECT CObj::GetRect()
{
	RECT rc;
	if(m_Info.vRect == D3DXVECTOR3(0.f,0.f,0.f))
	{
		SetRect(&rc,
			int(m_Info.vPos.x - m_Info.vCenter.x),
			int(m_Info.vPos.y - m_Info.vCenter.y),
			int(m_Info.vPos.x + m_Info.vCenter.x),
			int(m_Info.vPos.y + m_Info.vCenter.y)
			);
	}
	else
	{
		SetRect(&rc,
			int(m_Info.vPos.x - m_Info.vRect.x),
			int(m_Info.vPos.y - m_Info.vRect.y),
			int(m_Info.vPos.x + m_Info.vRect.x),
			int(m_Info.vPos.y + m_Info.vRect.y)
		);
	}
	

	return rc;
}