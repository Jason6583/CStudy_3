#pragma once



// CMyForm �� ���Դϴ�.

class CMyForm : public CFormView
{
	DECLARE_DYNCREATE(CMyForm)

protected:
	CMyForm();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	/*afx_msg void OnEnChangeEdit1();
	CString m_StrEdit1;
	CString m_StrEdit2;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();*/
	CString m_StrName;
	int m_nLevel;
	int m_nAttack;
	int m_nDefence;
	CButton m_Gender[3];
	CString m_StrResult;
	afx_msg void OnBnClickedButton3();
	CString m_StrSearch;
	CListBox m_ListBox;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};


