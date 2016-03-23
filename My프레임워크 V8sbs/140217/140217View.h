// 140217View.h : CMy140217View Ŭ������ �������̽�
//
#pragma once

#include "Defines.h"
#include "140217Doc.h"

class CMy140217View : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	CMy140217View();
	DECLARE_DYNCREATE(CMy140217View)

// Ư���Դϴ�.
public:
	CMy140217Doc* GetDocument() const;

// �۾��Դϴ�.
public:
	vector<TILE*>		m_vecTile;
	int					m_iSelDrawID;
	int					m_iSelObjID;
	bool				m_bCheck;
public:
	void InitTile(void);
	bool CollisionMouseToTile(D3DXVECTOR2 vPoint
		, const TILE* pTileInfo);


// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMy140217View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 140217View.cpp�� ����� ����
inline CMy140217Doc* CMy140217View::GetDocument() const
   { return reinterpret_cast<CMy140217Doc*>(m_pDocument); }
#endif

