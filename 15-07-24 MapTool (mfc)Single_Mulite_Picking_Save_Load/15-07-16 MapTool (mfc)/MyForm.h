#pragma once
#include "stdafx.h"
#include "Define.h"


// CMyForm 폼 뷰입니다.

class CMyForm : public CFormView
{
	DECLARE_DYNCREATE(CMyForm)

protected:
	CMyForm();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CMyForm();

public:
	enum { IDD = IDD_MYFORM };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	/*afx_msg void OnEnChangeEdit1();
	CString m_StrEdit1;
	CString m_StrEdit2;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();*/
	map <CString,INFO*>	m_MapData;

	CString m_StrName;
	int m_nLevel;
	int m_nAttack;
	int m_nDefence;
	CButton m_Gender[3];
	CString m_StrResult;
	CButton m_Item[3];
	CListBox m_ListBox;
	CString m_StrSearch;

	afx_msg void OnBnClickedButton3();	
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnLbnSelchangeList1();
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
};


