// 140217.h : 140217 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy140217App:
// �� Ŭ������ ������ ���ؼ��� 140217.cpp�� �����Ͻʽÿ�.
//

class CMy140217App : public CWinApp
{
public:
	CMy140217App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy140217App theApp;