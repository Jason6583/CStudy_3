#pragma once
#include "afxwin.h"


// CPage1 ��ȭ �����Դϴ�.

class CPage1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CPage1)

public:
	CPage1();
	virtual ~CPage1();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PAGE1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_Combo;
	virtual BOOL OnInitDialog();
	CStatic m_Picture;

	HBITMAP		m_BitMap[38];
	HBITMAP		m_BitMap2[4];
	afx_msg void OnDestroy();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox m_Combo2;
	CStatic m_Picture2;
	CButton m_cButton4;
	afx_msg void OnBnClickedButton1();
};
