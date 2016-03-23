
// 15-07-16 MapTool (mfc)View.h : CMy150716MapToolmfcView 클래스의 인터페이스
//

#pragma once
#include "Define.h"
#include "15-07-16 MapTool (mfc)Doc.h"


class CMy150716MapToolmfcView : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	CMy150716MapToolmfcView();
	DECLARE_DYNCREATE(CMy150716MapToolmfcView)

// 특성입니다.
public:
	CMy150716MapToolmfcDoc* GetDocument() const;

// 작업입니다.
public:
	vector<TILE*>	m_vecTile;
	int				m_nSelDrawID;
public:
	void InitTile();
	bool CollisionMouseToTile(D3DXVECTOR2 vMousePos, const TILE* pTileInfo);

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy150716MapToolmfcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 15-07-16 MapTool (mfc)View.cpp의 디버그 버전
inline CMy150716MapToolmfcDoc* CMy150716MapToolmfcView::GetDocument() const
   { return reinterpret_cast<CMy150716MapToolmfcDoc*>(m_pDocument); }
#endif

