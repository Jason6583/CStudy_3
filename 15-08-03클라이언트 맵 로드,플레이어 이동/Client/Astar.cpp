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
		return; //������ Ÿ��, 1 �̸� ���� 
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
		//��
		nIndex = pParent->nIndex - TILECNTX * 2;  //�� ��ġ���� 2�� �Ѱ��� ��
		
		//�����ϴ� Ÿ���̳�, �����ִ� Ÿ���̳�, �̹� �����߰ų� 
		//���� ����Ʈ�� �߰��Ǿ� �ִ��� �˻�

		if (pParent->nIndex >= TILECNTX*2 
			&& (*pVecTile)[nIndex]->byOption == 0 
			&& CheckList(nIndex)) //�˻縦 ��� �Ҽ� �ִ�.
		{
			//�� �ε����� �ش��ϴ� Ÿ�Ͽ� ���� ���� ����
			pNode = MakeNode(nIndex,pParent,pVecTile); //��� ����
			m_OpenList.push_back(pNode);	

		}

		//������ ��
		nIndex = pParent->nIndex - (TILECNTX - (pParent->nIndex/TILECNTX) % 2) ;//Ȧ���϶� 1 , ¦���϶� 0
		if (pParent->nIndex >= TILECNTX 
			&& pParent->nIndex % (TILECNTX * 2) != TILECNTX * 2 -1
			&& (*pVecTile)[nIndex]->byOption == 0 
			&& CheckList(nIndex)) //���� �κб����� üũ 
		{
			//�� �ε����� �ش��ϴ� Ÿ�Ͽ� ���� ���� ����
			pNode = MakeNode(nIndex,pParent,pVecTile); //��� ����
			m_OpenList.push_back(pNode);
		}

		//������
		nIndex = pParent->nIndex + 1; //�ڱⲨ���� +1
		if (pParent->nIndex >= TILECNTX
			&& pParent->nIndex % TILECNTX != TILECNTX - 1
			&& (*pVecTile)[nIndex]->byOption == 0
			&& CheckList(nIndex))
		{
			//�� �ε����� �ش��ϴ� Ÿ�Ͽ� ���� ���� ����
			pNode = MakeNode(nIndex,pParent,pVecTile); //��� ����
			m_OpenList.push_back(pNode);
		}
		
		//������ �Ʒ�
		nIndex = pParent->nIndex + (TILECNTX + (pParent->nIndex/TILECNTX)%2);
		if (pParent->nIndex < TILECNTX * TILECNTY - TILECNTX 
			&& pParent->nIndex % (TILECNTX * 2) != TILESIZEX * 2 - 1
			&& (*pVecTile)[nIndex]->byOption == 0
			&&CheckList(nIndex))
		{
			//�� �ε����� �ش��ϴ� Ÿ�Ͽ� ���� ���� ����
			pNode = MakeNode(nIndex,pParent,pVecTile); //��� ����
			m_OpenList.push_back(pNode);
		}

		//�Ʒ�
		nIndex = pParent->nIndex + TILECNTX * 2;
		if (pParent->nIndex < TILECNTX * TILECNTY - TILECNTX * 2
			&& (*pVecTile)[nIndex]->byOption == 0
			&& CheckList(nIndex))
		{
			//�� �ε����� �ش��ϴ� Ÿ�Ͽ� ���� ���� ����
			pNode = MakeNode(nIndex,pParent,pVecTile); //��� ����
			m_OpenList.push_back(pNode);
		}

		//���� �Ʒ� 
		nIndex = pParent->nIndex + (TILECNTX - 1 + (pParent->nIndex / TILECNTX) % 2);
		if (pParent->nIndex < TILECNTX * TILECNTY - TILECNTX
			&& pParent->nIndex % (TILECNTX * 2) != 0
			&& (*pVecTile)[nIndex]->byOption == 0
			&& CheckList(nIndex))
		{
			//�� �ε����� �ش��ϴ� Ÿ�Ͽ� ���� ���� ����
			pNode = MakeNode(nIndex,pParent,pVecTile); //��� ����
			m_OpenList.push_back(pNode);
		}
		
		//����
		nIndex = pParent->nIndex - 1;
		
		if (pParent->nIndex < TILECNTX * TILECNTY - TILECNTX
			&& pParent->nIndex %(TILECNTX) != 0
			&& (*pVecTile)[nIndex]->byOption == 0
			&& CheckList(nIndex))
		{
			//�� �ε����� �ش��ϴ� Ÿ�Ͽ� ���� ���� ����
			pNode = MakeNode(nIndex,pParent,pVecTile); //��� ����
			m_OpenList.push_back(pNode);
		}

		//���� �� 
		nIndex = pParent->nIndex - (TILECNTX + 1 - (pParent->nIndex / TILECNTX) % 2);

		if (pParent->nIndex >= TILECNTX
			&& pParent->nIndex % (TILECNTX * 2) != 0
			&& (*pVecTile)[nIndex]->byOption == 0
			&& CheckList(nIndex))
		{
			//�� �ε����� �ش��ϴ� Ÿ�Ͽ� ���� ���� ����
			pNode = MakeNode(nIndex,pParent,pVecTile); //��� ����
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

	//�θ� ��� ������ �Ÿ�
	D3DXVECTOR3 vDir = (*pVecTile)[nIndex]->vPos - (*pVecTile)[pParent->nIndex]->vPos;

	float fPCost = D3DXVec3Length(&vDir); //���̸� ���Ѵ�
	
	//���� ��� ������ �Ÿ�
	vDir = (*pVecTile)[nIndex]->vPos - (*pVecTile)[m_nGoalIdx]->vPos;
	float fGCost = D3DXVec3Length(&vDir);

	pNode->fCost = fPCost + fGCost;


	return pNode;
}
