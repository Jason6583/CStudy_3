// Page1.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "140217.h"
#include "Page1.h"

#include "MainFrm.h"
#include "140217View.h"


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
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_Control(pDX, IDC_PICTURE2, m_Picture2);
	DDX_Control(pDX, IDC_BUTTON1, m_cButton4);
}


BEGIN_MESSAGE_MAP(CPage1, CPropertyPage)
	ON_WM_DESTROY()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CPage1::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CPage1::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON1, &CPage1::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPage1 메시지 처리기입니다.

BOOL CPage1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.


	TCHAR		szTmp[128] = L"";

	for (int i = 0; i < 38; ++i)
	{
		wsprintf(szTmp, L"Tile%d", i);
		m_Combo.AddString(szTmp);
	}

	m_Combo.SetCurSel(0);

	RECT			rcPicture;	

	m_Picture.GetWindowRect(&rcPicture);
	SetRect(&rcPicture, 0, 0, rcPicture.right - rcPicture.left
		, rcPicture.bottom - rcPicture.top);
	
	for (int i = 0; i < 38; ++i)
	{
		wsprintf(szTmp, L"../Resource/Texture/TileBmp/Tile%d.bmp", i);
		m_BitMap[i] = (HBITMAP)LoadImage(NULL, szTmp, IMAGE_BITMAP, rcPicture.right, rcPicture.bottom, LR_LOADFROMFILE);
	}

	m_Picture.SetBitmap(m_BitMap[0]);



	TCHAR		szTmp2[128] = L"";

	for (int i = 0; i < 4; ++i)
	{
		wsprintf(szTmp2, L"Monster%d", i);
		m_Combo2.AddString(szTmp2);
	}

	m_Combo2.SetCurSel(0);

	RECT			rcPicture2;	

	m_Picture2.GetWindowRect(&rcPicture2);
	SetRect(&rcPicture2, 0, 0, rcPicture2.right - rcPicture2.left
		, rcPicture2.bottom - rcPicture2.top);
	
	for (int i = 0; i < 4; ++i)
	{
		wsprintf(szTmp2, L"../Resource/Texture/Monster/Monster%d.bmp", i);
		m_BitMap2[i] = (HBITMAP)LoadImage(NULL, szTmp2, IMAGE_BITMAP, rcPicture2.right, rcPicture2.bottom, LR_LOADFROMFILE);
	}

	m_Picture2.SetBitmap(m_BitMap2[0]);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CPage1::OnDestroy()
{
	CPropertyPage::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	for (int i = 0; i < 38; ++i)
	{
		DeleteObject(m_BitMap[i]);
	}

	for (int i = 0; i < 4; ++i)
	{
		DeleteObject(m_BitMap2[i]);
	}

}



// Combo
void CPage1::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iIndex = m_Combo.GetCurSel();
	m_Picture.SetBitmap(m_BitMap[iIndex]);

	CMainFrame*		pMainFrm = (CMainFrame*)AfxGetMainWnd();

	pMainFrm->m_pMainView->m_iSelDrawID = iIndex;

}

void CPage1::OnCbnSelchangeCombo2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iIndex = m_Combo2.GetCurSel();
	m_Picture2.SetBitmap(m_BitMap2[iIndex]);

	CMainFrame*		pMainFrm = (CMainFrame*)AfxGetMainWnd();

	pMainFrm->m_pMainView->m_iSelObjID = iIndex;
}

void CPage1::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		 CMainFrame*		pMainFrm = (CMainFrame*)AfxGetMainWnd();
	 if(pMainFrm->m_pMainView->m_bCheck==false)
	 {
		  pMainFrm->m_pMainView->m_bCheck  = true;
		  m_cButton4.SetWindowTextW(L"오브젝트");
	 }
	 else
	 {
		  pMainFrm->m_pMainView->m_bCheck  = false;
		  m_cButton4.SetWindowTextW(L"타일");
	 }
}
