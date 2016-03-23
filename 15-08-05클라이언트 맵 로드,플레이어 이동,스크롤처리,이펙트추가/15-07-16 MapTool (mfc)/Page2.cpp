// Page2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "15-07-16 MapTool (mfc).h"
#include "Page2.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "15-07-16 MapTool (mfc)View.h"

// CPage2 대화 상자입니다.

IMPLEMENT_DYNAMIC(CPage2, CPropertyPage)

CPage2::CPage2()
	: CPropertyPage(CPage2::IDD)
{

}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPage2, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON1, &CPage2::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPage2 메시지 처리기입니다.


//저장
void CPage2::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CFileDialog Dlg(FALSE, L"dat",L"*.dat",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"*.dat",this);
	
	if (Dlg.DoModal() == IDCANCEL)
	{
		return;
	}

	HANDLE hFile;
	DWORD dwByte;

	hFile = CreateFile(Dlg.GetPathName(), GENERIC_WRITE, 0,NULL,CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL,NULL);

	CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();

	for (unsigned int  i= 0; i<pMainFrm->m_pMainView->m_vecTile.size(); ++i) //전체를 받아온다
	{
		WriteFile(hFile,pMainFrm->m_pMainView->m_vecTile[i],sizeof(TILE),&dwByte,NULL);
	}
	
	CloseHandle(hFile);

}
