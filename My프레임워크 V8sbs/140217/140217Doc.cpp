// 140217Doc.cpp : CMy140217Doc Ŭ������ ����
//

#include "stdafx.h"
#include "140217.h"

#include "140217Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy140217Doc

IMPLEMENT_DYNCREATE(CMy140217Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy140217Doc, CDocument)
END_MESSAGE_MAP()


// CMy140217Doc ����/�Ҹ�

CMy140217Doc::CMy140217Doc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CMy140217Doc::~CMy140217Doc()
{
}

BOOL CMy140217Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CMy140217Doc serialization

void CMy140217Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}


// CMy140217Doc ����

#ifdef _DEBUG
void CMy140217Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy140217Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy140217Doc ���
