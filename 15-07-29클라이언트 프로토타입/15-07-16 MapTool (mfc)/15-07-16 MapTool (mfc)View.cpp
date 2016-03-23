
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
#include "MainFrm.h"
#include "MiniView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy150716MapToolmfcView

IMPLEMENT_DYNCREATE(CMy150716MapToolmfcView, CScrollView)

BEGIN_MESSAGE_MAP(CMy150716MapToolmfcView, CScrollView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy150716MapToolmfcView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy150716MapToolmfcView ����/�Ҹ�

CMy150716MapToolmfcView::CMy150716MapToolmfcView()
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

	return CScrollView::PreCreateWindow(cs);
}

// CMy150716MapToolmfcView �׸���

void CMy150716MapToolmfcView::OnDraw(CDC* /*pDC*/)
{
	CMy150716MapToolmfcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.

	/*const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"Test");

	if (pTexInfo == NULL)
	{
		return;
	}	*/

	GET_SINGLE(CDevice)->Render_Begin();

	//for (unsigned int i = 0; i<m_vecTile.size(); ++i)
	for(int i = 0; i<18; ++i)
	{
		for (int j =0; j<6; ++j)
		{
			int nIndex =  (i + GetScrollPos(1)/(TILESIZEY/2)) * TILECNTX + ( j + (GetScrollPos(0)/(TILESIZEX)));

			if (nIndex >= TILECNTX * TILECNTY || nIndex < 0)
			{
				continue;
			}

			const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"BackGround",L"Tile"
				,m_vecTile[nIndex]->byDrawId);

			if(pTexInfo == NULL)
				return;

			D3DXMATRIX matWorld;
			D3DXMATRIX matTrans;
			D3DXMatrixTranslation(&matTrans,m_vecTile[nIndex]->vPos.x - GetScrollPos(0), m_vecTile[nIndex]->vPos.y - GetScrollPos(1), m_vecTile[nIndex]->vPos.z);

			//ũ���̰���
			matWorld = matTrans;

			GET_SINGLE(CDevice)->GetSprite()->SetTransform(&matWorld);
			GET_SINGLE(CDevice)->GetSprite()->Draw(pTexInfo->pTexture, NULL, &D3DXVECTOR3(65, 34,0),NULL,D3DCOLOR_ARGB(255,255,255,255));
		}
	}

	GET_SINGLE(CDevice)->Render_End(m_hWnd);

	CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();
	
	pMainFrm->m_pMiniView->Invalidate(FALSE);
	

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
	CScrollView::AssertValid();
}

void CMy150716MapToolmfcView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
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
	CScrollView::OnInitialUpdate();
	
	m_nSelDrawID = 0;
	SetScrollSizes(MM_TEXT,CSize(TILESIZEX * TILECNTX , TILESIZEY * TILECNTY/2));
	
	
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	if (FAILED(GET_SINGLE(CDevice)->InitDevice(m_hWnd)))
	{
		return;
	}

	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Tile/Tile37.png",L"Test",TEXTYPE_SINGLE)))
	{
		AfxMessageBox(L"�̹��� �ε� ����1");
		return;
	}

	if(FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Tile/Tile%d.png"
		,L"BackGround",TEXTYPE_MULTI,L"Tile",38)))
	{
		AfxMessageBox(L"�̹��� �ε� ����2");
		return;
	}


	//mainframe mfc�� ��ü������ �����ϰ� �ִ� �� 
	CMainFrame* pMainFrm =(CMainFrame*)AfxGetMainWnd(); 
	
	RECT rcWindow;
	pMainFrm->GetWindowRect(&rcWindow); //w��ü �������� rect�� ���ü�����

	SetRect(&rcWindow,0,0,rcWindow.right - rcWindow.left,
		rcWindow.bottom - rcWindow.top);

	RECT rcMainView;
	GetClientRect(&rcMainView); //view ��ǥ , Ŭ���̾�Ʈ�� rect

	float fRowFrm = rcWindow.bottom - rcMainView.bottom;
	float fColFrm = rcWindow.right - rcMainView.right;

	pMainFrm->SetWindowPos(NULL,0,0,800+fColFrm,600+fRowFrm,SWP_NOZORDER);
	


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
	CScrollView::OnDestroy();

	GET_SINGLE(CDevice)->DestroyInstance();

	for (unsigned int i = 0; i<m_vecTile.size(); ++i)
	{
		delete m_vecTile[i];
		m_vecTile[i] = NULL;
	}
	m_vecTile.clear();


	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}

void CMy150716MapToolmfcView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CView::OnLButtonUp(nFlags, point);
}

bool CMy150716MapToolmfcView::CollisionMouseToTile( D3DXVECTOR2 vMousePos, const TILE* pTileInfo )
{
	// y = ax + b;
	//a 
	float fGrad = (TILESIZEY/2.f)/(TILESIZEX/2.f); //����
	
	//b
	// b= y - ax;
	D3DXVECTOR2	vPoint[4];

	vPoint[0] = D3DXVECTOR2(pTileInfo->vPos.x, pTileInfo->vPos.y + TILESIZEY / 2.f);
	vPoint[1] = D3DXVECTOR2(pTileInfo->vPos.x + TILESIZEX/2.f , pTileInfo->vPos.y );
	vPoint[2] = D3DXVECTOR2(pTileInfo->vPos.x, pTileInfo->vPos.y - TILESIZEY / 2.f);
	vPoint[3] = D3DXVECTOR2(pTileInfo->vPos.x - TILESIZEX/2.f , pTileInfo->vPos.y );

	float fB[4] = 
	{
		vPoint[0].y - fGrad * vPoint[0].x,
		vPoint[1].y + fGrad * vPoint[1].x,
		vPoint[2].y - fGrad * vPoint[2].x,
		vPoint[3].y + fGrad * vPoint[3].x
	};

	// y = ax + b , ������������ y������ �� �ѱ�� 
	// y - ax - b = 0 �����߾�
	// y- ax - b < 0 ���� �Ʒ�
	//y - ax - b > 0 ���� ����

	if (vMousePos.y - fGrad * vMousePos.x - fB[0] < 0 
	  &&vMousePos.y + fGrad * vMousePos.x - fB[1] < 0
	  &&vMousePos.y - fGrad * vMousePos.x - fB[2] >= 0
	  &&vMousePos.y + fGrad * vMousePos.x - fB[3] >= 0)
	{
		//�浹
		return true;
	}

	return false;
}
void CMy150716MapToolmfcView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	int	nIndex = 0;

	D3DXVECTOR2 vMousePoint = D3DXVECTOR2(point.x + GetScrollPos(0), point.y + GetScrollPos(1));

	for (int i = 0; i<m_vecTile.size(); ++i)
	{
		if (CollisionMouseToTile(vMousePoint,m_vecTile[i])) //����Ÿ���� �ϳ��� ��
		{
			nIndex = i;
			break;
		}
	}
	m_vecTile[nIndex]->byDrawId = m_nSelDrawID;

	Invalidate(FALSE);


	CScrollView::OnLButtonDown(nFlags, point);

}

void CMy150716MapToolmfcView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (!(GetKeyState(VK_LBUTTON)& 0x8000))
	{
		return;
	}

	OnLButtonDown(nFlags,point);

	CScrollView::OnMouseMove(nFlags, point);
}
