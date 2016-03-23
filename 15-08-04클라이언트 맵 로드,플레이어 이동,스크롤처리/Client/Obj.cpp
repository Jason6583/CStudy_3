#include "StdAfx.h"
#include "Obj.h"
#include "Include.h"

CObj::CObj(void) :
m_fFrame(0.f)
{
}

CObj::CObj( const OBJINFO& Info ) :
m_Info(Info),
m_fFrame(0.f)
{

}


CObj::~CObj(void)
{
}

void CObj::Frame_Move( const float& fCnt, const float& fMax )
{
	m_fFrame += fCnt * GET_SINGLE(CTimeMgr)->GetTime(); //cnt 넣어준만큼 늘어남
	
	if (m_fFrame > fMax)
	{
		m_fFrame = 0.f;
	}
}

int CObj::GetTileIndex( const D3DXVECTOR3& vPos )
{
	const vector<TILE*>* pVectorTile = GET_SINGLE(CObjMgr)->GetTileInfo();
	
	for (unsigned int i = 0; i<pVectorTile->size(); ++i)
	{
		if (CollisionMouseToTile(vPos,(*pVectorTile)[i]))
		{
			return i; //충돌된 i 값을 반환
		}
	}
	return -1;
}

bool CObj::CollisionMouseToTile( D3DXVECTOR3 vPos, const TILE* pTileInfo )
{
	// y = ax + b;
	//a 
	float fGrad = (TILESIZEY/2.f)/(TILESIZEX/2.f); //기울기

	//b
	// b= y - ax;
	D3DXVECTOR2	vPoint[4];

	vPoint[0] = D3DXVECTOR2(pTileInfo->vPos.x, pTileInfo->vPos.y + TILESIZEY / 2.f);
	vPoint[1] = D3DXVECTOR2(pTileInfo->vPos.x + TILESIZEX/2.f , pTileInfo->vPos.y );
	vPoint[2] = D3DXVECTOR2(pTileInfo->vPos.x, pTileInfo->vPos.y - TILESIZEY / 2.f);
	vPoint[3] = D3DXVECTOR2(pTileInfo->vPos.x - TILESIZEX/2.f , pTileInfo->vPos.y );

	float fB[4] = 
	{
		vPoint[0].y - fGrad * vPoint[0].x,
		vPoint[1].y + fGrad * vPoint[1].x,
		vPoint[2].y - fGrad * vPoint[2].x,
		vPoint[3].y + fGrad * vPoint[3].x
	};

	// y = ax + b , 직선방정식이 y쪽으로 다 넘기면 
	// y - ax - b = 0 직선중앙
	// y- ax - b < 0 직선 아래
	//y - ax - b > 0 직선 위에

	if (vPos.y - fGrad * vPos.x - fB[0] < 0 
		&&vPos.y + fGrad * vPos.x - fB[1] < 0
		&&vPos.y - fGrad * vPos.x - fB[2] >= 0
		&&vPos.y + fGrad * vPos.x - fB[3] >= 0)
	{
		//충돌
		return true;
	}

	return false;
}
