#pragma once
#include "Define.h"


class CAstar
{
public:
	DECLARE_SINGLETON(CAstar);
private:
	list<NODE*>	m_OpenList; //조사해야할 대상
	list<NODE*>	m_CloseList; //조사한 대상
	list<int>	m_BestList; //가야할 경로
public:
	list<int>* GetBestList()
	{
		return &m_BestList;
	}
public:
	static bool Compare(NODE* pDestNode, NODE* pSourNode)
	{
		return pDestNode->fCost < pSourNode->fCost;
	}
public:
	int			m_nStartIdx;
	int			m_nGoalIdx;
public:
	void AstarStart(const int& nStartIdx, const int& nGoalIdx);
	void MakeRoute(void);
	bool CheckList(const int& nIndex);
	NODE* MakeNode(int nIndex, NODE* pParent, const vector<TILE*>* pVecTile);
	void Release();

private:
	CAstar(void);
public:
	~CAstar(void);
};

