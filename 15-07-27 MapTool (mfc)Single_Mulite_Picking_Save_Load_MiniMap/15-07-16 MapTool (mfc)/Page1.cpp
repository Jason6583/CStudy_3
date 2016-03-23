// Page1.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "15-07-16 MapTool (mfc).h"
#include "Page1.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "15-07-16 MapTool (mfc)View.h"

// CPage1 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPage1, CPropertyPage)

CPage1::CPage1()
	: CPropertyPage(CPage1::IDD)
{

}

CPage1::~CPage1()
{
}

void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	DDX_Control(pDX, IDC_PICTURE, m_Picture);
}


BEGIN_MESSAGE_MAP(CPage1, CPropertyPage)
	ON_WM_DESTROY()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CPage1::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CPage1 �޽��� ó�����Դϴ�.


BOOL CPage1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	TCHAR szTmp[128] = L"";
	
	for (int i = 0; i<38; ++i)
	{
		wsprintf(szTmp,L"Tile%d",i); //�޺��ڽ��ȿ� ������� ������ ��
		m_Combo.AddString(szTmp);
	}
	m_Combo.SetCurSel(0);

	RECT	rcPicture;

	m_Picture.GetWindowRect(&rcPicture); //����� ���Ϳ� ���Ļ����� ��Ʈ�� ��

	SetRect(&rcPicture,0,0, rcPicture.right - rcPicture.left, rcPicture.bottom - rcPicture.top);

	for(int i = 0; i<38; ++i)
	{
		wsprintf(szTmp,L"../Resource/Texture/TileBmp/Tile%d.bmp",i);
		m_Bitmap[i] = (HBITMAP)LoadImage(NULL,szTmp,IMAGE_BITMAP,rcPicture.right,rcPicture.bottom,LR_LOADFROMFILE);
	}

	m_Picture.SetBitmap(m_Bitmap[0]);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CPage1::OnDestroy()
{
	CPropertyPage::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	for(int i = 0; i<38; ++i)
	{
		DeleteObject(m_Bitmap[i]);
	}
}


void CPage1::OnCbnSelchangeCombo1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	int nIndex = m_Combo.GetCurSel();

	m_Picture.SetBitmap(m_Bitmap[nIndex]);
	CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();

	pMainFrm->m_pMainView->m_nSelDrawID = nIndex;

}
