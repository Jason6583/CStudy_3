
// 15-07-16 MapTool (mfc)View.cpp : CMy150716MapToolmfcView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "15-07-16 MapTool (mfc).h"
#endif

#include "15-07-16 MapTool (mfc)Doc.h"
#include "15-07-16 MapTool (mfc)View.h"
#include "Include.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy150716MapToolmfcView

IMPLEMENT_DYNCREATE(CMy150716MapToolmfcView, CView)

BEGIN_MESSAGE_MAP(CMy150716MapToolmfcView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy150716MapToolmfcView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy150716MapToolmfcView ����/�Ҹ�

CMy150716MapToolmfcView::CMy150716MapToolmfcView() :
m_bIDCheck(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy150716MapToolmfcView::~CMy150716MapToolmfcView()
{
}

BOOL CMy150716MapToolmfcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy150716MapToolmfcView �׸���

void CMy150716MapToolmfcView::OnDraw(CDC* /*pDC*/)
{
	CMy150716MapToolmfcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.

	const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"Test");

	if (pTexInfo == NULL)
	{
		return;
	}	

	GET_SINGLE(CDevice)->Render_Begin();

	for (unsigned int i = 0; i<m_vecTile.size(); ++i)
	{
		D3DXMATRIX matWorld;
		D3DXMATRIX matTrans;
		D3DXMatrixTranslation(&matTrans,m_vecTile[i]->vPos.x, m_vecTile[i]->vPos.y, m_vecTile[i]->vPos.z);

		//ũ���̰���
		matWorld = matTrans;

		GET_SINGLE(CDevice)->GetSprite()->SetTransform(&matWorld);
		GET_SINGLE(CDevice)->GetSprite()->Draw(pTexInfo->pTexture, NULL, &D3DXVECTOR3(65, 34,0),NULL,D3DCOLOR_ARGB(255,255,255,255));

	}

	GET_SINGLE(CDevice)->Render_End();




}


// CMy150716MapToolmfcView �μ�


void CMy150716MapToolmfcView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy150716MapToolmfcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy150716MapToolmfcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy150716MapToolmfcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy150716MapToolmfcView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy150716MapToolmfcView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy150716MapToolmfcView ����

#ifdef _DEBUG
void CMy150716MapToolmfcView::AssertValid() const
{
	CView::AssertValid();
}

void CMy150716MapToolmfcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy150716MapToolmfcDoc* CMy150716MapToolmfcView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy150716MapToolmfcDoc)));
	return (CMy150716MapToolmfcDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy150716MapToolmfcView �޽��� ó����


void CMy150716MapToolmfcView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	if (FAILED(GET_SINGLE(CDevice)->InitDevice(m_hWnd)))
	{
		return;
	}


	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Tile/Tile37.png",L"Test",TEXTYPE_SINGLE)))
	{
		AfxMessageBox(L"�̹����ε����");
		return;
	}

	InitTile();

}

void CMy150716MapToolmfcView::InitTile()
{
	m_vecTile.reserve(TILECNTX * TILECNTY);

	for (int y = 0;  y<TILECNTY; ++y)
	{
		for (int x = 0; x<TILECNTX; ++x)
		{
			int nIndex = y * TILECNTX + x; 

			TILE* pTile = new TILE;
			
			pTile->vPos = D3DXVECTOR3(x * TILESIZEX + (y % 2) * (TILESIZEX / 2.0f ), y * (TILESIZEY / 2.0f ), 0.f);
			pTile->vSize = D3DXVECTOR3(TILESIZEX,TILESIZEY,0.f);
			pTile->byDrawId = 0;
			pTile->byOption = 0;
			m_vecTile.push_back(pTile);
		}
	}

}


void CMy150716MapToolmfcView::OnDestroy()
{
	CView::OnDestroy();

	GET_SINGLE(CDevice)->DestoryInstance();

	for (unsigned int i = 0; i<m_vecTile.size(); ++i)
	{
		delete m_vecTile[i];
		m_vecTile[i] = NULL;
	}
	m_vecTile.clear();


	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CMy150716MapToolmfcView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CView::OnLButtonDown(nFlags, point);

	m_bIDCheck = true;





	
}


void CMy150716MapToolmfcView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CView::OnLButtonUp(nFlags, point);
}
