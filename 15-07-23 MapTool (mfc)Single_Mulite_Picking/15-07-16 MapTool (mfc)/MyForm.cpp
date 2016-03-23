// MyForm.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "15-07-16 MapTool (mfc).h"
#include "MyForm.h"
#include "MainFrm.h"
#include "15-07-16 MapTool (mfc)View.h"


// CMyForm

IMPLEMENT_DYNCREATE(CMyForm, CFormView)

CMyForm::CMyForm()
	: CFormView(CMyForm::IDD)
	/*, m_StrEdit1(_T(""))
	, m_StrEdit2(_T(""))*/
	, m_StrName(_T(""))
	, m_nLevel(0)
	, m_nAttack(0)
	, m_nDefence(0)
	, m_StrResult(_T(""))
	, m_StrSearch(_T(""))
{

}

CMyForm::~CMyForm()
{
}

void CMyForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	/*DDX_Text(pDX, IDC_EDIT1, m_StrEdit1);
	DDX_Text(pDX, IDC_EDIT2, m_StrEdit2);*/
	DDX_Text(pDX, IDC_EDIT3, m_StrName);
	DDX_Text(pDX, IDC_EDIT4, m_nLevel);
	DDX_Text(pDX, IDC_EDIT5, m_nAttack);
	DDX_Text(pDX, IDC_EDIT6, m_nDefence);
	DDX_Text(pDX, IDC_EDIT7, m_StrResult);
	DDX_Control(pDX, IDC_RADIO1, m_Gender[0]);
	DDX_Control(pDX, IDC_RADIO2, m_Gender[1]);
	DDX_Control(pDX, IDC_RADIO3, m_Gender[2]);
	DDX_Text(pDX, IDC_EDIT8, m_StrSearch);
	DDX_Control(pDX, IDC_LIST1 ,m_ListBox);
}

BEGIN_MESSAGE_MAP(CMyForm, CFormView)
	/*ON_EN_CHANGE(IDC_EDIT1, &CMyForm::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMyForm::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyForm::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyForm::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyForm::OnBnClickedButton2)*/
	ON_BN_CLICKED(IDC_BUTTON3, &CMyForm::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMyForm::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMyForm::OnBnClickedButton5)
END_MESSAGE_MAP()


// CMyForm 진단입니다.

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






// CMyForm 메시지 처리기입니다.

//
//void CMyForm::OnEnChangeEdit1()
//{
//	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
//	// CFormView::OnInitDialog() 함수를 재지정 
//	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
//	// 이 알림 메시지를 보내지 않습니다.
//
//	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
//}
//
//
//void CMyForm::OnBnClickedButton4()
//{
//	//우
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();
//
//	++pMainFrm->m_pMainView->m_nSelDrawID; //메인프레임은 전체를 관리 ,ㅡ알고있음
//	if (pMainFrm->m_pMainView->m_nSelDrawID >= 38)
//	{
//		pMainFrm->m_pMainView->m_nSelDrawID = 37;
//	}
//}
//
//
//void CMyForm::OnBnClickedButton3()
//{
//	//좌
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//
//	CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();
//
//	--(pMainFrm->m_pMainView->m_nSelDrawID);
//	if (pMainFrm->m_pMainView->m_nSelDrawID < 0)
//	{
//		pMainFrm->m_pMainView->m_nSelDrawID = 0;
//	}
//
//}
//
//
//void CMyForm::OnBnClickedButton1()
//{
//	//리셋
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//
//	CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();
//
//	for (int i =0 ; i<pMainFrm->m_pMainView->m_vecTile.size(); ++i)
//	{
//		pMainFrm->m_pMainView->m_vecTile[i]->byDrawId = 0;
//	}
//
//	pMainFrm->m_pMainView->Invalidate(FALSE);
//
//}
//
//
//void CMyForm::OnBnClickedButton2()
//{
//	//복사
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	//컨트롤에 있는 데이터를 변수에 저장한다.
//	//UpdateData(TRUE); //데이타를 넘겨준다
//	//
//	//m_StrEdit2 = m_StrEdit1;
//
//	//UpdateData(FALSE); //컨트롤의 변수값을 뿌려준다 , 넘어간걸 보여줌 
//
//
//
//}


void CMyForm::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	m_StrResult = L"";

	TCHAR szTmp[128];
	

	m_StrResult += m_StrName;

	wsprintf(szTmp,L" %d", m_nLevel);
	m_StrResult += szTmp;

	wsprintf(szTmp,L" %d", m_nAttack);
	m_StrResult += szTmp;

	wsprintf(szTmp,L" %d", m_nDefence);
	m_StrResult += szTmp;

	for (int i = 0; i<3; ++i)
	{
		if (m_Gender[i].GetCheck())
		{
			CString StrTmp;
			m_Gender[i].GetWindowText(StrTmp);
			m_StrResult += StrTmp; //문자열 결과에 계쏙 담아짐
			break;
		}
	}

	m_ListBox.AddString(m_StrResult); //리스트박스에 추가


	UpdateData(FALSE);
}


void CMyForm::OnBnClickedButton4()
{
	//리스트 박스 내용물 삭제 
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int nSel =	m_ListBox.GetCurSel();

	if (nSel >=0)
	{
		m_ListBox.DeleteString(nSel);
	}
}


void CMyForm::OnBnClickedButton5()
{
	//수정
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int nSel =	m_ListBox.GetCurSel();

	if (nSel >=0)
	{
		UpdateData(TRUE);

		m_StrResult = L"";

		TCHAR szTmp[128];

		

		m_StrResult += m_StrName;

		wsprintf(szTmp,L" %d", m_nLevel);
		m_StrResult += szTmp;

		wsprintf(szTmp,L" %d", m_nAttack);
		m_StrResult += szTmp;

		wsprintf(szTmp,L" %d", m_nDefence);
		m_StrResult += szTmp;		

		for (int i = 0; i<3; ++i)
		{
			if (m_Gender[i].GetCheck())
			{
				CString StrTmp;
				m_Gender[i].GetWindowText(StrTmp);
				m_StrResult += StrTmp; //문자열 결과에 계쏙 담아짐
				break;
			}
		}

		
		//m_StrResult += m_StrResult;



		m_ListBox.InsertString(nSel,m_StrResult);
		m_ListBox.DeleteString(nSel+1);

		UpdateData(FALSE);
		
	}

}
