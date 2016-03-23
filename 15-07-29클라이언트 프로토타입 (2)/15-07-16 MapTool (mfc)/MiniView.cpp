// MiniView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "15-07-16 MapTool (mfc).h"
#include "MiniView.h"
#include "MainFrm.h"
#include "Device.h"
#include "15-07-16 MapTool (mfc)View.h"
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


// CMiniView 그리기입니다.

void CMiniView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.


	GET_SINGLE(CDevice)->Render_Begin();

	for(int i = 0; i<40; ++i)
	{
		for (int j =0; j<20; ++j)
		{
			int nIndex =  (i + GetScrollPos(1)/(TILESIZEY/2)) * TILECNTX + ( j + (GetScrollPos(0)/(TILESIZEX)));

			if (nIndex >= TILECNTX * TILECNTY || nIndex < 0)
			{
				continue;
			}

			const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"BackGround",L"Tile"
				,(*m_pVecTile)[nIndex]->byDrawId);

			if(pTexInfo == NULL)
				return;

			D3DXMATRIX matWorld;
			D3DXMATRIX matTrans;
			D3DXMATRIX matScale;

			D3DXMatrixScaling(&matScale,0.3f,0.3f,1.0f);
			D3DXMatrixTranslation(&matTrans,(*m_pVecTile)[nIndex]->vPos.x * 0.3f , (*m_pVecTile)[nIndex]->vPos.y * 0.3f , (*m_pVecTile)[nIndex]->vPos.z);

			//크자이공부
			matWorld = matScale * matTrans;

			GET_SINGLE(CDevice)->GetSprite()->SetTransform(&matWorld);
			GET_SINGLE(CDevice)->GetSprite()->Draw(pTexInfo->pTexture, NULL, &D3DXVECTOR3(65, 34,0),NULL,D3DCOLOR_ARGB(255,255,255,255));
		}
	}



	GET_SINGLE(CDevice)->Render_End(m_hWnd);
	
	
}

// CMiniView 진단입니다.

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


// CMiniView 메시지 처리기입니다.


void CMiniView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();

	m_pVecTile = &(pMainFrm->m_pMainView->m_vecTile);




}


void CMiniView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();

	

	CView::OnLButtonDown(nFlags, point);
}
