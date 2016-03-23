
// 15-07-16 MapTool (mfc)View.cpp : CMy150716MapToolmfcView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "15-07-16 MapTool (mfc).h"
#endif

#include "15-07-16 MapTool (mfc)Doc.h"
#include "15-07-16 MapTool (mfc)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy150716MapToolmfcView

IMPLEMENT_DYNCREATE(CMy150716MapToolmfcView, CView)

BEGIN_MESSAGE_MAP(CMy150716MapToolmfcView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy150716MapToolmfcView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy150716MapToolmfcView ����/�Ҹ�

CMy150716MapToolmfcView::CMy150716MapToolmfcView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy150716MapToolmfcView::~CMy150716MapToolmfcView()
{
}

BOOL CMy150716MapToolmfcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy150716MapToolmfcView �׸���

void CMy150716MapToolmfcView::OnDraw(CDC* /*pDC*/)
{
	CMy150716MapToolmfcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy150716MapToolmfcView �μ�


void CMy150716MapToolmfcView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy150716MapToolmfcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy150716MapToolmfcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy150716MapToolmfcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy150716MapToolmfcView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy150716MapToolmfcView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy150716MapToolmfcView ����

#ifdef _DEBUG
void CMy150716MapToolmfcView::AssertValid() const
{
	CView::AssertValid();
}

void CMy150716MapToolmfcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy150716MapToolmfcDoc* CMy150716MapToolmfcView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy150716MapToolmfcDoc)));
	return (CMy150716MapToolmfcDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy150716MapToolmfcView �޽��� ó����
