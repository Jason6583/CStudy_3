#include "StdAfx.h"
#include "Astar.h"

#include "Include.h"
CAstar::CAstar(void)
{
}


CAstar::~CAstar(void)
{
	Release();
}

void CAstar::AstarStart( const int& nStartIdx, const int& nGoalIdx )
{
	if (nStartIdx == nGoalIdx)
	{
		return;
	}

	const vector<TILE*>*	pVecTile = GET_SINGLE(CObjMgr)->GetTileInfo();

	if (pVecTile == NULL)
	{
		return;
	}
	if ((*pVecTile)[nGoalIdx]->byOption == 1)
	{
		return; //못가는 타일, 1 이면 리턴 
	}
	
	Release();

	m_nStartIdx = nStartIdx;
	m_nGoalIdx = nGoalIdx; 

	MakeRoute();
}

void CAstar::MakeRoute( void )
{
	NODE*	pParent	 = new NODE;
	pParent->nIndex	 = m_nStartIdx;
	pParent->pParent = NULL;
	pParent->fCost	 = 0;
	m_CloseList.push_back(pParent);

	const vector<TILE*>* pVecTile = GET_SINGLE(CObjMgr)->GetTileInfo();

	if (pVecTile == NULL)
	{
		return;
	}

	NODE*	pNode = NULL;
	int nIndex = 0;
	
	while(true)
	{
		//위
		nIndex = pParent->nIndex - TILECNTX * 2;  //내 위치에서 2배 한곳을 뺌
		
		//존재하는 타일이냐, 갈수있는 타일이냐, 이미 조사했거나 
		//오픈 리스트에 추가되어 있는지 검사

		if (pParent->nIndex >= TILECNTX*2 
			&& (*pVecTile)[nIndex]->byOption == 0 
			&& CheckList(nIndex)) //검사를 계속 할수 있다.
		{
			//위 인덱스에 해당하는 타일에 대한 정보 생성
			pNode = MakeNode(nIndex,pParent,pVecTile); //노드 생성
			m_OpenList.push_back(pNode);	

		}

		//오른쪽 위
		nIndex = pParent->nIndex - (TILECNTX - (pParent->nIndex/TILECNTX) % 2) ;//홀수일때 1 , 짝수일때 0
		if (pParent->nIndex >= TILECNTX 
			&& pParent->nIndex % (TILECNTX * 2) != TILECNTX * 2 -1
			&& (*pVecTile)[nIndex]->byOption == 0 
			&& CheckList(nIndex)) //안쪽 부분까지만 체크 
		{
			//위 인덱스에 해당하는 타일에 대한 정보 생성
			pNode = MakeNode(nIndex,pParent,pVecTile); //노드 생성
			m_OpenList.push_back(pNode);
		}

		//오른쪽
		nIndex = pParent->nIndex + 1; //자기꺼에서 +1
		if (pParent->nIndex >= TILECNTX
			&& pParent->nIndex % TILECNTX != TILECNTX - 1
			&& (*pVecTile)[nIndex]->byOption == 0
			&& CheckList(nIndex))
		{
			//위 인덱스에 해당하는 타일에 대한 정보 생성
			pNode = MakeNode(nIndex,pParent,pVecTile); //노드 생성
			m_OpenList.push_back(pNode);
		}
		
		//오른쪽 아래
		nIndex = pParent->nIndex + (TILECNTX + (pParent->nIndex/TILECNTX)%2);
		if (pParent->nIndex < TILECNTX * TILECNTY - TILECNTX 
			&& pParent->nIndex % (TILECNTX * 2) != TILESIZEX * 2 - 1
			&& (*pVecTile)[nIndex]->byOption == 0
			&&CheckList(nIndex))
		{
			//위 인덱스에 해당하는 타일에 대한 정보 생성
			pNode = MakeNode(nIndex,pParent,pVecTile); //노드 생성
			m_OpenList.push_back(pNode);
		}

		//아래
		nIndex = pParent->nIndex + TILECNTX * 2;
		if (pParent->nIndex < TILECNTX * TILECNTY - TILECNTX * 2
			&& (*pVecTile)[nIndex]->byOption == 0
			&& CheckList(nIndex))
		{
			//위 인덱스에 해당하는 타일에 대한 정보 생성
			pNode = MakeNode(nIndex,pParent,pVecTile); //노드 생성
			m_OpenList.push_back(pNode);
		}

		//왼쪽 아래 
		nIndex = pParent->nIndex + (TILECNTX - 1 + (pParent->nIndex / TILECNTX) % 2);
		if (pParent->nIndex < TILECNTX * TILECNTY - TILECNTX
			&& pParent->nIndex % (TILECNTX * 2) != 0
			&& (*pVecTile)[nIndex]->byOption == 0
			&& CheckList(nIndex))
		{
			//위 인덱스에 해당하는 타일에 대한 정보 생성
			pNode = MakeNode(nIndex,pParent,pVecTile); //노드 생성
			m_OpenList.push_back(pNode);
		}
		
		//왼쪽
		nIndex = pParent->nIndex - 1;
		
		if (pParent->nIndex < TILECNTX * TILECNTY - TILECNTX
			&& pParent->nIndex %(TILECNTX) != 0
			&& (*pVecTile)[nIndex]->byOption == 0
			&& CheckList(nIndex))
		{
			//위 인덱스에 해당하는 타일에 대한 정보 생성
			pNode = MakeNode(nIndex,pParent,pVecTile); //노드 생성
			m_OpenList.push_back(pNode);
		}

		//왼쪽 위 
		nIndex = pParent->nIndex - (TILECNTX + 1 - (pParent->nIndex / TILECNTX) % 2);

		if (pParent->nIndex >= TILECNTX
			&& pParent->nIndex % (TILECNTX * 2) != 0
			&& (*pVecTile)[nIndex]->byOption == 0
			&& CheckList(nIndex))
		{
			//위 인덱스에 해당하는 타일에 대한 정보 생성
			pNode = MakeNode(nIndex,pParent,pVecTile); //노드 생성
			m_OpenList.push_back(pNode);
		}

		m_OpenList.sort(Compare);

		list<NODE*>::iterator iter = m_OpenList.begin();

		pParent  = *iter;

		m_CloseList.push_back(*iter);
		iter = m_OpenList.erase(iter);

		if (pParent->nIndex == m_nGoalIdx)
		{
			while(true)
			{
				m_BestList.push_back(pParent->nIndex);
				pParent = pParent->pParent;
				if (pParent->nIndex == m_nStartIdx)
				{
					break;
				}
			}
			m_BestList.reverse();
			break;
		}


	}


}

bool CAstar::CheckList( const int& nIndex )
{
	for (list<NODE*>::iterator iter = m_OpenList.begin(); iter != m_OpenList.end(); ++iter)
	{
		if ((*iter)->nIndex == nIndex)
		{
			return false;
		}
	}

	for (list<NODE*>::iterator iter = m_CloseList.begin(); iter != m_CloseList.end(); ++iter)
	{
		if ((*iter)->nIndex == nIndex)
		{
			return false;
		}
	}
	
	return true;
}

void CAstar::Release()
{
	for (list<NODE*>::iterator iter = m_OpenList.begin(); iter != m_OpenList.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	m_OpenList.clear();

	for (list<NODE*>::iterator iter = m_CloseList.begin(); iter != m_CloseList.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	m_CloseList.clear();

	m_BestList.clear();


}

NODE* CAstar::MakeNode( int nIndex, NODE* pParent, const vector<TILE*>* pVecTile )
{
	NODE*	pNode = new NODE;
	pNode->nIndex = nIndex;
	pNode->pParent = pParent;

	//부모 노드 까지의 거리
	D3DXVECTOR3 vDir = (*pVecTile)[nIndex]->vPos - (*pVecTile)[pParent->nIndex]->vPos;

	float fPCost = D3DXVec3Length(&vDir); //길이를 구한다
	
	//도착 노드 까지의 거리
	vDir = (*pVecTile)[nIndex]->vPos - (*pVecTile)[m_nGoalIdx]->vPos;
	float fGCost = D3DXVec3Length(&vDir);

	pNode->fCost = fPCost + fGCost;


	return pNode;
}
