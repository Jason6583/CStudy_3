
// 15-07-16 MapTool (mfc)View.h : CMy150716MapToolmfcView Ŭ������ �������̽�
//

#pragma once


class CMy150716MapToolmfcView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy150716MapToolmfcView();
	DECLARE_DYNCREATE(CMy150716MapToolmfcView)

// Ư���Դϴ�.
public:
	CMy150716MapToolmfcDoc* GetDocument() const;

// �۾��Դϴ�.
public:

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
	virtual ~CMy150716MapToolmfcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // 15-07-16 MapTool (mfc)View.cpp�� ����� ����
inline CMy150716MapToolmfcDoc* CMy150716MapToolmfcView::GetDocument() const
   { return reinterpret_cast<CMy150716MapToolmfcDoc*>(m_pDocument); }
#endif

