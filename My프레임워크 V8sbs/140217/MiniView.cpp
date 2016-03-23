// MiniView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "140217.h"
#include "MiniView.h"
#include "MainFrm.h"
#include "Device.h"

#include "140217View.h"
#include "TextureMgr.h"


// CMiniView

IMPLEMENT_DYNCREATE(CMiniView, CView)

CMiniView::CMiniView()
{

}

CMiniView::~CMiniView()
{
}

BEGIN_MESSAGE_MAP(CMiniView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CMiniView �׸����Դϴ�.

void CMiniView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
	GET_SINGLE(CDevice)->Render_Begin();

	for	(int i = 0; i < 40; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			int		iIndex = (i + GetScrollPos(1) / (TILESIZEY / 2)) * TILECNTX + (j + (GetScrollPos(0) / TILESIZEX));

			if(iIndex >= TILECNTX * TILECNTY
				|| iIndex < 0)
				continue;

			const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"BackGround", L"Tile", (*m_pVecTile)[iIndex]->byDrawId);
			if(pTexInfo == NULL)
				return;

			D3DXMATRIX		matWorld;
			D3DXMATRIX		matTrans;
			D3DXMATRIX		matScale;

			D3DXMatrixScaling(&matScale, 0.3f, 0.3f, 1.f);
			D3DXMatrixTranslation(&matTrans, (*m_pVecTile)[iIndex]->vPos.x * 0.3f
				, (*m_pVecTile)[iIndex]->vPos.y * 0.3f, (*m_pVecTile)[iIndex]->vPos.z);

			matWorld = matScale * matTrans;

			GET_SINGLE(CDevice)->GetSprite()->SetTransform(&matWorld);
			GET_SINGLE(CDevice)->GetSprite()->Draw(pTexInfo->pTexture
				, NULL, &D3DXVECTOR3(65, 34, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
	}	

	GET_SINGLE(CDevice)->Render_End(m_hWnd);
}


// CMiniView �����Դϴ�.

#ifdef _DEBUG
void CMiniView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CMiniView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMiniView �޽��� ó�����Դϴ�.

void CMiniView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMainFrame*		pMainFrm = (CMainFrame*)AfxGetMainWnd();


	CView::OnLButtonDown(nFlags, point);
}

void CMiniView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CMainFrame*		pMainFrm = (CMainFrame*)AfxGetMainWnd();

	m_pVecTile = &(pMainFrm->m_pMainView->m_vecTile);


	
}
