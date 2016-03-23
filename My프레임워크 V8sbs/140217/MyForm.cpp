// MyForm.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "140217.h"
#include "MyForm.h"

#include "MainFrm.h"
#include "140217View.h"


// CMyForm

IMPLEMENT_DYNCREATE(CMyForm, CFormView)

CMyForm::CMyForm()
	: CFormView(CMyForm::IDD)
	, m_pMySheet(NULL)	
{

}

CMyForm::~CMyForm()
{
}

void CMyForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyForm, CFormView)		
	ON_WM_DESTROY()	
END_MESSAGE_MAP()


// CMyForm �����Դϴ�.

#ifdef _DEBUG
void CMyForm::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyForm �޽��� ó�����Դϴ�.
void CMyForm::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	m_pMySheet = new CMySheet;

	m_pMySheet->Create(this, WS_VISIBLE | WS_CHILD);

	m_pMySheet->MoveWindow(0, 0, 300, 300, FALSE);
}

void CMyForm::OnDestroy()
{
	CFormView::OnDestroy();

	delete m_pMySheet;
	m_pMySheet = NULL;

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.	
}

