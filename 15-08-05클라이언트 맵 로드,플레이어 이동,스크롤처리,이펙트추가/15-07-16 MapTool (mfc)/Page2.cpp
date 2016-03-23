// Page2.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "15-07-16 MapTool (mfc).h"
#include "Page2.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "15-07-16 MapTool (mfc)View.h"

// CPage2 ��ȭ �����Դϴ�.

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


// CPage2 �޽��� ó�����Դϴ�.


//����
void CPage2::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	CFileDialog Dlg(FALSE, L"dat",L"*.dat",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"*.dat",this);
	
	if (Dlg.DoModal() == IDCANCEL)
	{
		return;
	}

	HANDLE hFile;
	DWORD dwByte;

	hFile = CreateFile(Dlg.GetPathName(), GENERIC_WRITE, 0,NULL,CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL,NULL);

	CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();

	for (unsigned int  i= 0; i<pMainFrm->m_pMainView->m_vecTile.size(); ++i) //��ü�� �޾ƿ´�
	{
		WriteFile(hFile,pMainFrm->m_pMainView->m_vecTile[i],sizeof(TILE),&dwByte,NULL);
	}
	
	CloseHandle(hFile);

}
