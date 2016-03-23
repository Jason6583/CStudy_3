#pragma once

#include "Defines.h"

class CAStar
{
public:
	DECLARE_SINGLETON(CAStar);
private:
	list<NODE*>			m_OpenList; // 조사해야할 대상
	list<NODE*>			m_CloseList; // 조사한 대상
	list<int>			m_BestList; // 가야할 경로

public:
	int					m_iStartIdx;
	int					m_iGoalIdx;
public:
	list<int>*	GetBestList(void) {
		return &m_BestList;}
public:
	static bool Compare(NODE* pDestNode, NODE* pSourNode)
	{
		return pDestNode->fCost < pSourNode->fCost;
	}
public: 
	void AstarStart(const int& iStartIdx
		, const int& iGoalIdx);
	void MakeRoute(void);
	bool CheckList(const int& iIndex);
	NODE* MakeNode(int iIndex, NODE* pParent, const vector<TILE*>* pVecTile);
	void Release(void);

private:
	CAStar(void);
public:
	~CAStar(void);
};
