#pragma once

#include "Defines.h"

class CAStar
{
public:
	DECLARE_SINGLETON(CAStar);
private:
	list<NODE*>			m_OpenList; // �����ؾ��� ���
	list<NODE*>			m_CloseList; // ������ ���
	list<int>			m_BestList; // ������ ���

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
