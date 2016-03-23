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
	DDX_Control(pDX, IDC_CHECK1, m_Item[0]);
	DDX_Control(pDX, IDC_CHECK2, m_Item[1]);
	DDX_Control(pDX, IDC_CHECK3, m_Item[2]);
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
	ON_LBN_SELCHANGE(IDC_LIST1, &CMyForm::OnLbnSelchangeList1)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON8, &CMyForm::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON6, &CMyForm::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMyForm::OnBnClickedButton7)
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
	//생성
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	m_ListBox.AddString(m_StrName);
		
	INFO* pInfo = new INFO;
	ZeroMemory(pInfo,sizeof(INFO));

	lstrcpy(pInfo->szName,m_StrName.GetString());

	pInfo->nLevel = m_nLevel;
	pInfo->nAttack = m_nAttack;
	pInfo->nDefence = m_nDefence;

	for (int i = 0; i<3 ; i++)
	{
		if (m_Gender[i].GetCheck())
		{
			pInfo->nGenderIdx = i;
			break;
		}
	}
	for (int i = 0; i<3; i++)
	{
		if (m_Item[i].GetCheck())
		{
			switch (i)
			{
			case 0:
				pInfo->byItem |= ITEM_GOLD;
				break;
			case 1:
				pInfo->byItem |= ITEM_MENTAL;
				break;
			case 2:
				pInfo->byItem |= ITEM_EAR;
				break;
			}
		}
	}
	m_MapData.insert(make_pair(m_StrName,pInfo));




	UpdateData(FALSE);


}


void CMyForm::OnBnClickedButton4()
{
	//리스트 박스 내용물 삭제 
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int nIndex =	m_ListBox.GetCurSel();

	if (nIndex < 0)
	{
		return;
	}
	
	CString StrFind;
	m_ListBox.GetText(nIndex,StrFind);
	m_ListBox.DeleteString(nIndex);

	map<CString,INFO*>::iterator iter =m_MapData.find(StrFind);
	delete iter->second;
	iter->second = NULL;
	iter= m_MapData.erase(iter);

}


void CMyForm::OnBnClickedButton5()
{
	OnBnClickedButton4();
	OnBnClickedButton3();


	//수정
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//int nSel =	m_ListBox.GetCurSel();

	//if (nSel >=0)
	//{
	//	UpdateData(TRUE);

	//	m_ListBox.InsertString(nSel,m_StrName);
	//	m_ListBox.DeleteString(nSel+1);
	//	INFO* pInfo = new INFO;
	//	ZeroMemory(pInfo,sizeof(INFO));

	//	lstrcpy(pInfo->szName,m_StrName.GetString());

	//	pInfo->nLevel = m_nLevel;
	//	pInfo->nAttack = m_nAttack;
	//	pInfo->nDefence = m_nDefence;

	//	for (int i = 0; i<3 ; i++)
	//	{
	//		if (m_Gender[i].GetCheck())
	//		{
	//			pInfo->nGenderIdx = i;
	//			break;
	//		}
	//	}
	//	for (int i = 0; i<3; i++)
	//	{
	//		if (m_Item[i].GetCheck())
	//		{
	//			switch (i)
	//			{
	//			case 0:
	//				pInfo->byItem |= ITEM_GOLD;
	//				break;
	//			case 1:
	//				pInfo->byItem |= ITEM_MENTAL;
	//				break;
	//			case 2:
	//				pInfo->byItem |= ITEM_EAR;
	//				break;
	//			}
	//		}
	//	}		
	//	m_MapData.insert(make_pair(m_StrName,pInfo));



	//	

	//	UpdateData(FALSE);
	//	
	//}

}


void CMyForm::OnLbnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int nIndex = m_ListBox.GetCurSel();
		
	//리스트 박스에 문자열 전부다 지우기
	//m_ListBox.ResetContent();
	
	if (nIndex < 0)
	{
		return;
	}
	for (int i = 0; i<3; ++i)
	{
		m_Gender[i].SetCheck(0);
	}
	for (int i = 0; i<3; ++i)
	{
		m_Item[i].SetCheck(0);
	}

	CString StrFind;
	m_ListBox.GetText(nIndex,StrFind);

	map<CString,INFO*>::iterator iter = m_MapData.find(StrFind);

	m_StrName = iter->second->szName;
	m_nLevel = iter->second->nLevel;
	m_nAttack = iter->second->nAttack;
	m_nDefence = iter->second->nDefence;
	m_Gender[iter->second->nGenderIdx].SetCheck(1);

	if (iter->second->byItem & ITEM_GOLD)
	{
		m_Item[0].SetCheck(1);
	}
	if (iter->second->byItem & ITEM_MENTAL)
	{
		m_Item[1].SetCheck(1);
	}
	if (iter->second->byItem & ITEM_EAR)
	{
		m_Item[2].SetCheck(1);
	}

	UpdateData(FALSE);
}


void CMyForm::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_Gender[0].SetCheck(1);
	m_Item[0].SetCheck(1);

}


void CMyForm::OnDestroy()
{
	CFormView::OnDestroy();

	for (map<CString,INFO*>::iterator iter = m_MapData.begin(); iter != m_MapData.end(); ++iter)
	{
		delete iter->second;
		iter->second = NULL;
	}
	m_MapData.clear();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

//검색
void CMyForm::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	int nIndex = m_ListBox.FindString(0,m_StrSearch);

	m_ListBox.SetCurSel(nIndex);
	OnLbnSelchangeList1();


}


void CMyForm::OnBnClickedButton6()
{
	//저장
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CFileDialog Dlg(FALSE,L"dat",L"*.dat",OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT);

	if (Dlg.DoModal() == IDCANCEL)
	{
		return;
	}

	HANDLE	hFile;
	DWORD	dwByte;

	hFile = CreateFile(Dlg.GetPathName(),GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL, NULL);

	for (map<CString,INFO*> ::iterator iter = m_MapData.begin(); iter != m_MapData.end(); ++iter)
	{
		WriteFile(hFile,iter->second, sizeof(INFO),&dwByte,NULL);
	}

	CloseHandle(hFile);

}


void CMyForm::OnBnClickedButton7()
{
	//불러오기
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	CFileDialog	Dlg(TRUE,L"dat",L"*.dat",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,L"*.dat",this);

	if (Dlg.DoModal() == IDCANCEL)
	{
		return;
	}
	for (map<CString,INFO*>::iterator iter = m_MapData.begin(); iter != m_MapData.end(); ++iter)
	{
		delete iter->second;
		iter->second = NULL;
	}
	m_MapData.clear();
	m_ListBox.ResetContent();

	HANDLE	hFile;
	DWORD	dwByte;
	hFile = CreateFile(Dlg.GetPathName(),GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,NULL);

	while(true)
	{
		INFO*	pInfo = new INFO;
		ZeroMemory(pInfo,sizeof(INFO));
		ReadFile(hFile,pInfo,sizeof(INFO),&dwByte,NULL);

		if (dwByte == 0) //다 읽으면 삭제
		{
			delete pInfo;
			pInfo = NULL;
			break;
		}
		m_MapData.insert(make_pair(pInfo->szName,pInfo)); //맵에 다시 담금
		m_ListBox.AddString(pInfo->szName); //리스트에 다시 로드 
	}

	m_ListBox.SetCurSel(0);
	OnLbnSelchangeList1();

	CloseHandle(hFile);

}
