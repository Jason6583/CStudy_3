// MiniView.cpp : ���� �����Դϴ�.
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


// CMiniView �׸����Դϴ�.

void CMiniView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.

	pDC->Rectangle(m_Rect[0]);
	pDC->Rectangle(m_Rect[1]);

	GET_SINGLE(CDevice)->Render_Begin();

	GET_SINGLE(CDevice)->Render_End(m_hWnd);
	pDC->Rectangle(m_Rect[0]);
	pDC->Rectangle(m_Rect[1]);
}

// CMiniView �����Դϴ�.

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


// CMiniView �޽��� ó�����Դϴ�.


void CMiniView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	m_Rect[0] = CRect(50,50,100,100);
	m_Rect[1] = CRect(200,50,250,100);

}


void CMiniView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();

	if (m_Rect[0].PtInRect(point))
	{
		--pMainFrm->m_pMainView->m_nSelDrawID; //������������ ��ü�� ���� ,�Ѿ˰�����
		if (pMainFrm->m_pMainView->m_nSelDrawID < 0)
		{
			pMainFrm->m_pMainView->m_nSelDrawID = 0;
		}
	}

	if (m_Rect[1].PtInRect(point))
	{
		++pMainFrm->m_pMainView->m_nSelDrawID; //������������ ��ü�� ���� ,�Ѿ˰�����
		if (pMainFrm->m_pMainView->m_nSelDrawID >= 38)
		{
			pMainFrm->m_pMainView->m_nSelDrawID = 37;
		}
	}

	CView::OnLButtonDown(nFlags, point);
}
