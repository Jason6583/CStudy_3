#pragma once
#include "Define.h"


class CAstar
{
public:
	DECLARE_SINGLETON(CAstar);
private:
	list<NODE*>	m_OpenList; //�����ؾ��� ���
	list<NODE*>	m_CloseList; //������ ���
	list<int>	m_BestList; //������ ���
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

