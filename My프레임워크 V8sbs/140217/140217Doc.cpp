// 140217Doc.cpp : CMy140217Doc 클래스의 구현
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


// CMy140217Doc 생성/소멸

CMy140217Doc::CMy140217Doc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CMy140217Doc::~CMy140217Doc()
{
}

BOOL CMy140217Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CMy140217Doc serialization

void CMy140217Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}


// CMy140217Doc 진단

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


// CMy140217Doc 명령
