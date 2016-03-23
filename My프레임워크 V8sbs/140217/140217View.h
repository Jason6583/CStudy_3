// 140217View.h : CMy140217View 클래스의 인터페이스
//
#pragma once

#include "Defines.h"
#include "140217Doc.h"

class CMy140217View : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	CMy140217View();
	DECLARE_DYNCREATE(CMy140217View)

// 특성입니다.
public:
	CMy140217Doc* GetDocument() const;

// 작업입니다.
public:
	vector<TILE*>		m_vecTile;
	int					m_iSelDrawID;
	int					m_iSelObjID;
	bool				m_bCheck;
public:
	void InitTile(void);
	bool CollisionMouseToTile(D3DXVECTOR2 vPoint
		, const TILE* pTileInfo);


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
	virtual ~CMy140217View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 140217View.cpp의 디버그 버전
inline CMy140217Doc* CMy140217View::GetDocument() const
   { return reinterpret_cast<CMy140217Doc*>(m_pDocument); }
#endif

