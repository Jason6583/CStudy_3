
// 15-07-16 MapTool (mfc).h : 15-07-16 MapTool (mfc) ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy150716MapToolmfcApp:
// �� Ŭ������ ������ ���ؼ��� 15-07-16 MapTool (mfc).cpp�� �����Ͻʽÿ�.
//

class CMy150716MapToolmfcApp : public CWinAppEx
{
public:
	CMy150716MapToolmfcApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy150716MapToolmfcApp theApp;
