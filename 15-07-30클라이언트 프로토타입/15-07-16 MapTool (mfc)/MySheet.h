#pragma once



// CMySheet
#include "Page1.h"
#include "Page2.h"



class CMySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CMySheet)
public:
	CPage1 m_Page1;
	CPage2 m_Page2;

public:
	CMySheet();
	CMySheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CMySheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CMySheet();

protected:
	DECLARE_MESSAGE_MAP()
};


