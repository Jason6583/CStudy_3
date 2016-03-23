// Page1.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "15-07-16 MapTool (mfc).h"
#include "Page1.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "15-07-16 MapTool (mfc)View.h"

// CPage1 대화 상자입니다.

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


// CPage1 메시지 처리기입니다.


BOOL CPage1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	TCHAR szTmp[128] = L"";
	
	for (int i = 0; i<38; ++i)
	{
		wsprintf(szTmp,L"Tile%d",i); //콤보박스안에 순서대로 나오게 함
		m_Combo.AddString(szTmp);
	}
	m_Combo.SetCurSel(0);

	RECT	rcPicture;

	m_Picture.GetWindowRect(&rcPicture); //빈공간 렉터에 픽쳐사이즈 렉트가 들어감

	SetRect(&rcPicture,0,0, rcPicture.right - rcPicture.left, rcPicture.bottom - rcPicture.top);

	for(int i = 0; i<38; ++i)
	{
		wsprintf(szTmp,L"../Resource/Texture/TileBmp/Tile%d.bmp",i);
		m_Bitmap[i] = (HBITMAP)LoadImage(NULL,szTmp,IMAGE_BITMAP,rcPicture.right,rcPicture.bottom,LR_LOADFROMFILE);
	}

	m_Picture.SetBitmap(m_Bitmap[0]);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CPage1::OnDestroy()
{
	CPropertyPage::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	for(int i = 0; i<38; ++i)
	{
		DeleteObject(m_Bitmap[i]);
	}
}


void CPage1::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int nIndex = m_Combo.GetCurSel();

	m_Picture.SetBitmap(m_Bitmap[nIndex]);
	CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();

	pMainFrm->m_pMainView->m_nSelDrawID = nIndex;

}
