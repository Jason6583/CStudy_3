// MySheet.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "140217.h"
#include "MySheet.h"


// CMySheet

IMPLEMENT_DYNAMIC(CMySheet, CPropertySheet)

CMySheet::CMySheet(void)
{
	AddPage(&m_Page1);
	AddPage(&m_Page2);
}

CMySheet::CMySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

CMySheet::CMySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}

CMySheet::~CMySheet()
{
}


BEGIN_MESSAGE_MAP(CMySheet, CPropertySheet)
END_MESSAGE_MAP()


// CMySheet �޽��� ó�����Դϴ�.
