// MiniView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "15-07-16 MapTool (mfc).h"
#include "MiniView.h"
#include "MainFrm.h"
#include "Device.h"
#include "15-07-16 MapTool (mfc)View.h"

// CMiniView

IMPLEMENT_DYNCREATE(CMiniView, CView)

CMiniView::CMiniView()
{

}

CMiniView::~CMiniView()
{
}

BEGIN_MESSAGE_MAP(CMiniView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CMiniView 그리기입니다.

void CMiniView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.

	pDC->Rectangle(m_Rect[0]);
	pDC->Rectangle(m_Rect[1]);

	GET_SINGLE(CDevice)->Render_Begin();

	GET_SINGLE(CDevice)->Render_End(m_hWnd);
	pDC->Rectangle(m_Rect[0]);
	pDC->Rectangle(m_Rect[1]);
}

// CMiniView 진단입니다.

#ifdef _DEBUG
void CMiniView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CMiniView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMiniView 메시지 처리기입니다.


void CMiniView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	m_Rect[0] = CRect(50,50,100,100);
	m_Rect[1] = CRect(200,50,250,100);

}


void CMiniView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();

	if (m_Rect[0].PtInRect(point))
	{
		--pMainFrm->m_pMainView->m_nSelDrawID; //메인프레임은 전체를 관리 ,ㅡ알고있음
		if (pMainFrm->m_pMainView->m_nSelDrawID < 0)
		{
			pMainFrm->m_pMainView->m_nSelDrawID = 0;
		}
	}

	if (m_Rect[1].PtInRect(point))
	{
		++pMainFrm->m_pMainView->m_nSelDrawID; //메인프레임은 전체를 관리 ,ㅡ알고있음
		if (pMainFrm->m_pMainView->m_nSelDrawID >= 38)
		{
			pMainFrm->m_pMainView->m_nSelDrawID = 37;
		}
	}

	CView::OnLButtonDown(nFlags, point);
}
