// 140217View.cpp : CMy140217View Ŭ������ ����
//

#include "stdafx.h"
#include "140217.h"

#include "140217Doc.h"
#include "140217View.h"

#include "Include.h"
#include "MainFrm.h"
#include "MiniView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy140217View

IMPLEMENT_DYNCREATE(CMy140217View, CScrollView)

BEGIN_MESSAGE_MAP(CMy140217View, CScrollView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy140217View ����/�Ҹ�

CMy140217View::CMy140217View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy140217View::~CMy140217View()
{
}

BOOL CMy140217View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// CMy140217View �׸���

void CMy140217View::OnDraw(CDC* pDC)
{
	CMy140217Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	GET_SINGLE(CDevice)->Render_Begin();	

	/*for (unsigned int i = 0; i < m_vecTile.size(); ++i)*/
	for	(int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			int		iIndex = (i + GetScrollPos(1) / (TILESIZEY / 2)) * TILECNTX + (j + (GetScrollPos(0) / TILESIZEX));

			if(iIndex >= TILECNTX * TILECNTY
				|| iIndex < 0)
				continue;

			const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"BackGround", L"Tile", m_vecTile[iIndex]->byDrawId);
			if(pTexInfo == NULL)
				return;

			const TEXINFO* pTexInfo2 = GET_SINGLE(CTextureMgr)->GetTexture(L"Monster", L"Mon", m_vecTile[iIndex]->byObject);

			if(pTexInfo2 == NULL)
				return;

			D3DXMATRIX		matWorld;
			D3DXMATRIX		matTrans;
			D3DXMatrixTranslation(&matTrans, m_vecTile[iIndex]->vPos.x - GetScrollPos(0)
				, m_vecTile[iIndex]->vPos.y - GetScrollPos(1), m_vecTile[iIndex]->vPos.z);

			matWorld = matTrans;

			GET_SINGLE(CDevice)->GetSprite()->SetTransform(&matWorld);
			GET_SINGLE(CDevice)->GetSprite()->Draw(pTexInfo->pTexture
				, NULL, &D3DXVECTOR3(65, 34, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

					GET_SINGLE(CDevice)->GetSprite()->SetTransform(&matWorld);
			GET_SINGLE(CDevice)->GetSprite()->Draw(pTexInfo2->pTexture
				, NULL, &D3DXVECTOR3(pTexInfo2->ImgInfo.Width/2.f,pTexInfo2->ImgInfo.Height/2.f , 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
	}	
	GET_SINGLE(CDevice)->Render_End(m_hWnd);

	CMainFrame*		pMainFrm = (CMainFrame*)AfxGetMainWnd();

	pMainFrm->m_pMiniView->Invalidate(FALSE);
}


// CMy140217View �μ�

BOOL CMy140217View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy140217View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy140217View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy140217View ����

#ifdef _DEBUG
void CMy140217View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMy140217View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMy140217Doc* CMy140217View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy140217Doc)));
	return (CMy140217Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy140217View �޽��� ó����

void CMy140217View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	SetScrollSizes(MM_TEXT, CSize(TILESIZEX * TILECNTX
		, TILESIZEY * TILECNTY / 2));

	m_iSelDrawID = 0;
	m_iSelObjID  = 0;
	m_bCheck = false;

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if(FAILED(GET_SINGLE(CDevice)->InitDevice(m_hWnd)))
		return;

	if(FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Tile/Tile37.png"
		, L"Test", TEXTYPE_SINGLE)))
	{
		AfxMessageBox(L"�̹����ε����");
		return;
	}

	if(FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Tile/Tile%d.png"
		, L"BackGround", TEXTYPE_MULTI, L"Tile", 38)))
	{
		AfxMessageBox(L"�̹����ε����");
		return;
	}


	if(FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/Texture/Monster/Monster%d.png"
		, L"Monster", TEXTYPE_MULTI, L"Mon", 4)))
	{
		AfxMessageBox(L"�̹����ε����");
		return;
	}

	InitTile();

	CMainFrame*	pMainFrm = (CMainFrame*)AfxGetMainWnd();

	RECT		rcWindow;

	pMainFrm->GetWindowRect(&rcWindow);

	SetRect(&rcWindow, 0, 0, rcWindow.right - rcWindow.left
		, rcWindow.bottom - rcWindow.top);

	RECT		rcMainView;
	GetClientRect(&rcMainView);

	float		fRowFrm = float(rcWindow.bottom - rcMainView.bottom);
	float		fColFrm = float(rcWindow.right - rcMainView.right);

	pMainFrm->SetWindowPos(NULL, 0, 0, 800 + int(fColFrm), 600 + int(fRowFrm), SWP_NOZORDER);

	
}

void CMy140217View::OnDestroy()
{
	CScrollView::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	GET_SINGLE(CTextureMgr)->DestroyInstance();
	GET_SINGLE(CDevice)->DestroyInstance();

	for	(unsigned int i = 0; i < m_vecTile.size(); ++i)
	{
		delete m_vecTile[i];
		m_vecTile[i] = NULL;
	}
	m_vecTile.clear();
}

BOOL CMy140217View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return FALSE;
}

void CMy140217View::InitTile(void)
{
	m_vecTile.reserve(TILECNTX * TILECNTY);

	for (int y = 0; y < TILECNTY; ++y)
	{
		for (int x = 0; x < TILECNTX; ++x)
		{
			int	iIndex = y * TILECNTX + x;

			TILE*		pTile = new TILE;
			pTile->vPos = D3DXVECTOR3(x * float(TILESIZEX) + (y % 2) * (float(TILESIZEX) / 2.f), y * (float(TILESIZEY) / 2.0f), 0.f);
			pTile->vSize = D3DXVECTOR3(float(TILESIZEX), float(TILESIZEY), 0.f);
			pTile->byDrawId = 0;
			pTile->byOption = 0;
			pTile->byObject = 0;
			m_vecTile.push_back(pTile);
		}
	}
	
}
void CMy140217View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int		iIndex = 0;

	D3DXVECTOR2			vMousePoint = D3DXVECTOR2(float(point.x) + GetScrollPos(0), float(point.y) + GetScrollPos(1));

	for (unsigned int i = 0; i < m_vecTile.size(); ++i)
	{
		if(CollisionMouseToTile(vMousePoint, m_vecTile[i]))
		{
			iIndex = i; 
			break;
		}
	}	

	

	if(m_bCheck ==false)
	{
		m_vecTile[iIndex]->byDrawId = m_iSelDrawID;
		m_vecTile[iIndex]->byOption = 1;
	}
	else
		m_vecTile[iIndex]->byObject = m_iSelObjID;

	Invalidate(FALSE);

	CScrollView::OnLButtonDown(nFlags, point);
}

bool CMy140217View::CollisionMouseToTile(D3DXVECTOR2 vMousePos
						  , const TILE* pTileInfo)
{
	// y = ax + b;
	// a ?
	float		fGrad = (TILESIZEY / 2.f) / (TILESIZEX / 2.f);

	// b?
	// b = y - ax
	D3DXVECTOR2		vPoint[4];
	vPoint[0] = D3DXVECTOR2(pTileInfo->vPos.x, pTileInfo->vPos.y + TILESIZEY / 2.f);
	vPoint[1] = D3DXVECTOR2(pTileInfo->vPos.x + TILESIZEX / 2.f, pTileInfo->vPos.y);
	vPoint[2] = D3DXVECTOR2(pTileInfo->vPos.x, pTileInfo->vPos.y - TILESIZEY / 2.f);
	vPoint[3] = D3DXVECTOR2(pTileInfo->vPos.x - TILESIZEX / 2.f, pTileInfo->vPos.y);

	float		fB[4] = {vPoint[0].y - fGrad * vPoint[0].x
	, vPoint[1].y - -fGrad * vPoint[1].x
	, vPoint[2].y - fGrad * vPoint[2].x
	, vPoint[3].y - -fGrad * vPoint[3].x};

	// y = ax + b
	// y - ax - b = 0 ������
	// y - ax - b < 0 ������
	// y - ax - b > 0 ������

	if(vMousePos.y - fGrad * vMousePos.x - fB[0] < 0
		&& vMousePos.y - -fGrad * vMousePos.x - fB[1] < 0
		&& vMousePos.y - fGrad * vMousePos.x - fB[2] >= 0
		&& vMousePos.y - -fGrad * vMousePos.x - fB[3] >= 0)
	{
		return true;
	}
	return false;
}

void CMy140217View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(!(GetKeyState(VK_LBUTTON) & 0x8000))
		return;

	OnLButtonDown(nFlags, point);	

	CScrollView::OnMouseMove(nFlags, point);
}
