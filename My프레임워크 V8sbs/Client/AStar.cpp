#include "StdAfx.h"
#include "AStar.h"

#include "Include.h"

CAStar::CAStar(void)
{
}

CAStar::~CAStar(void)
{
	Release();
}

void CAStar::AstarStart(const int& iStartIdx
				, const int& iGoalIdx)
{
	if(iStartIdx == iGoalIdx)
		return;

	const vector<TILE*>* pVecTile = GET_SINGLE(CObjMgr)->GetTileInfo();

	if(pVecTile == NULL)
		return;

	if((*pVecTile)[iGoalIdx]->byOption == 1)
		return;

	Release();

	m_iStartIdx = iStartIdx;
	m_iGoalIdx = iGoalIdx;

	MakeRoute();

	
}

void CAStar::MakeRoute(void)
{
	NODE*			pParent = new NODE;
	pParent->iIndex = m_iStartIdx;
	pParent->pParent = NULL;
	pParent->fCost = 0.f;
	m_CloseList.push_back(pParent);

	const vector<TILE*>* pVecTile = GET_SINGLE(CObjMgr)->GetTileInfo();

	if(pVecTile == NULL)
		return;

	NODE*		pNode = NULL;

	int			iIndex = 0;

	while(true)
	{
		// 위
		iIndex = pParent->iIndex - TILECNTX * 2;

		//if( 존재하는 타일이냐, 갈수있는 타일이냐, 이미 조사했거나, 오픈리스트에 추가되어있는녀석은 제외)
		if(pParent->iIndex >= TILECNTX * 2
			&& (*pVecTile)[iIndex]->byOption == 0
			&& CheckList(iIndex))
		{
			// 위 인덱스에 해당하는 타일에 대한 정보(Astar용)를 생성하기위해서.
			pNode = MakeNode(iIndex, pParent, pVecTile);
			m_OpenList.push_back(pNode);
		}	

		// 오.위
		iIndex = pParent->iIndex - (TILECNTX - (pParent->iIndex / TILECNTX) % 2);

		//if( 존재하는 타일이냐, 갈수있는 타일이냐, 이미 조사했거나, 오픈리스트에 추가되어있는녀석은 제외)
		if(pParent->iIndex >= TILECNTX
			&& pParent->iIndex % (TILECNTX * 2) != TILECNTX * 2 - 1
			&& (*pVecTile)[iIndex]->byOption == 0
			&& CheckList(iIndex))
		{
			// 위 인덱스에 해당하는 타일에 대한 정보(Astar용)를 생성하기위해서.
			pNode = MakeNode(iIndex, pParent, pVecTile);
			m_OpenList.push_back(pNode);
		}	

		// 오
		iIndex = pParent->iIndex + 1;

		//if( 존재하는 타일이냐, 갈수있는 타일이냐, 이미 조사했거나, 오픈리스트에 추가되어있는녀석은 제외)
		if(pParent->iIndex >= TILECNTX
			&& pParent->iIndex % TILECNTX != TILECNTX - 1
			&& (*pVecTile)[iIndex]->byOption == 0
			&& CheckList(iIndex))
		{
			// 위 인덱스에 해당하는 타일에 대한 정보(Astar용)를 생성하기위해서.
			pNode = MakeNode(iIndex, pParent, pVecTile);
			m_OpenList.push_back(pNode);
		}	

		// 오.아
		iIndex = pParent->iIndex + (TILECNTX + (pParent->iIndex / TILECNTX) % 2);

		//if( 존재하는 타일이냐, 갈수있는 타일이냐, 이미 조사했거나, 오픈리스트에 추가되어있는녀석은 제외)
		if(pParent->iIndex < TILECNTX * TILECNTY - TILECNTX
			&& pParent->iIndex % (TILECNTX * 2) != TILECNTX * 2 - 1
			&& (*pVecTile)[iIndex]->byOption == 0
			&& CheckList(iIndex))
		{
			// 위 인덱스에 해당하는 타일에 대한 정보(Astar용)를 생성하기위해서.
			pNode = MakeNode(iIndex, pParent, pVecTile);
			m_OpenList.push_back(pNode);
		}	

		// 아
		iIndex = pParent->iIndex + TILECNTX * 2;

		//if( 존재하는 타일이냐, 갈수있는 타일이냐, 이미 조사했거나, 오픈리스트에 추가되어있는녀석은 제외)
		if(pParent->iIndex < TILECNTX * TILECNTY - TILECNTX * 2		
			&& (*pVecTile)[iIndex]->byOption == 0
			&& CheckList(iIndex))
		{
			// 위 인덱스에 해당하는 타일에 대한 정보(Astar용)를 생성하기위해서.
			pNode = MakeNode(iIndex, pParent, pVecTile);
			m_OpenList.push_back(pNode);
		}	

		// 왼.아
		iIndex = pParent->iIndex + (TILECNTX - 1 + (pParent->iIndex / TILECNTX) % 2);

		//if( 존재하는 타일이냐, 갈수있는 타일이냐, 이미 조사했거나, 오픈리스트에 추가되어있는녀석은 제외)
		if(pParent->iIndex < TILECNTX * TILECNTY - TILECNTX		
			&& pParent->iIndex % (TILECNTX * 2) != 0
			&& (*pVecTile)[iIndex]->byOption == 0
			&& CheckList(iIndex))
		{
			// 위 인덱스에 해당하는 타일에 대한 정보(Astar용)를 생성하기위해서.
			pNode = MakeNode(iIndex, pParent, pVecTile);
			m_OpenList.push_back(pNode);
		}	

		// 왼
		iIndex = pParent->iIndex - 1;

		//if( 존재하는 타일이냐, 갈수있는 타일이냐, 이미 조사했거나, 오픈리스트에 추가되어있는녀석은 제외)
		if(pParent->iIndex < TILECNTX * TILECNTY - TILECNTX		
			&& pParent->iIndex % (TILECNTX) != 0
			&& (*pVecTile)[iIndex]->byOption == 0
			&& CheckList(iIndex))
		{
			// 위 인덱스에 해당하는 타일에 대한 정보(Astar용)를 생성하기위해서.
			pNode = MakeNode(iIndex, pParent, pVecTile);
			m_OpenList.push_back(pNode);
		}	

		// 왼.위
		iIndex = pParent->iIndex - (TILECNTX + 1 - (pParent->iIndex / TILECNTX) % 2);

		//if( 존재하는 타일이냐, 갈수있는 타일이냐, 이미 조사했거나, 오픈리스트에 추가되어있는녀석은 제외)
		if(pParent->iIndex >= TILECNTX 
			&& pParent->iIndex % (TILECNTX * 2) != 0
			&& (*pVecTile)[iIndex]->byOption == 0
			&& CheckList(iIndex))
		{
			// 위 인덱스에 해당하는 타일에 대한 정보(Astar용)를 생성하기위해서.
			pNode = MakeNode(iIndex, pParent, pVecTile);
			m_OpenList.push_back(pNode);
		}	

		m_OpenList.sort(Compare);

		list<NODE*>::iterator	iter = m_OpenList.begin();

		pParent = *iter;

		m_CloseList.push_back(*iter);

		iter = m_OpenList.erase(iter);

		if(pParent->iIndex == m_iGoalIdx)			
		{
			while(true)
			{			
				m_BestList.push_back(pParent->iIndex);
				pParent = pParent->pParent;
				if(pParent->iIndex == m_iStartIdx)
					break;
			}
			m_BestList.reverse();
			break;
		}
	}
}

bool CAStar::CheckList(const int& iIndex)
{
	for (list<NODE*>::iterator	iter = m_OpenList.begin();
		iter != m_OpenList.end(); ++iter)
	{
		if((*iter)->iIndex == iIndex)
			return false;	
	}
	

	for (list<NODE*>::iterator	iter = m_CloseList.begin();
		iter != m_CloseList.end(); ++iter)
	{
		if((*iter)->iIndex == iIndex)
			return false;		
	}
	return true;
}

NODE* CAStar::MakeNode(int iIndex, NODE* pParent, const vector<TILE*>* pVecTile)
{
	NODE*		pNode = new NODE;	
	pNode->iIndex = iIndex;
	pNode->pParent = pParent;

	// 부모노드까지의 거리
	D3DXVECTOR3 vDir = (*pVecTile)[iIndex]->vPos 
		- (*pVecTile)[pParent->iIndex]->vPos; 
	float		fPCost = D3DXVec3Length(&vDir);

	// 도착노드까지의 거리
	vDir = (*pVecTile)[iIndex]->vPos 
		- (*pVecTile)[m_iGoalIdx]->vPos; 
	float		fGCost = D3DXVec3Length(&vDir);

	pNode->fCost = fPCost + fGCost;
	return pNode;
}

void CAStar::Release(void)
{
	for (list<NODE*>::iterator	iter = m_OpenList.begin();
		iter != m_OpenList.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	m_OpenList.clear();

	for (list<NODE*>::iterator	iter = m_CloseList.begin();
		iter != m_CloseList.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	m_CloseList.clear();
	m_BestList.clear();
}