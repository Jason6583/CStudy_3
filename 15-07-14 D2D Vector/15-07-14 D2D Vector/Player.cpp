#include "StdAfx.h"
#include "Player.h"


CPlayer::CPlayer(void) :
m_fSpeed(0.f),
m_fAngle(0.f)
{
}


CPlayer::~CPlayer(void)
{
}

void CPlayer::Initialize()
{
	m_tInfo.vPos = D3DXVECTOR3(400.f,300.f,0.f);
	m_tInfo.vDir = D3DXVECTOR3(1.f, 1.f , 0.f);
	m_tInfo.vLook = D3DXVECTOR3(1.f, 0.f, 0.f); //오른쪽을 바라볼수있는 방향벡터
	

	m_fSpeed = 3.f;

}

void CPlayer::Progress()
{
	POINT ptMouse;
	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd,&ptMouse);

	D3DXVECTOR3 vMousePos= D3DXVECTOR3(ptMouse.x, ptMouse.y, 0.f);

	//플레이어가 마우스를 바라보는 방향벡터를 구한다 
	m_tInfo.vDir = vMousePos - m_tInfo.vPos;

	////방향벡터의 크기를 구해봅시다.
	//float fLength = sqrtf(m_tInfo.vDir.x * m_tInfo.vDir.x + m_tInfo.vDir.y * m_tInfo.vDir.y);

	////방향벡터의 각 원소의 방향벡터의 크기로 나누어서 
	////구한 방향벡터의 길이를 1로 만든다.
	//m_tInfo.vDir.x /= fLength;
	//m_tInfo.vDir.y /= fLength;
	//m_tInfo.vDir.z /= fLength;

	D3DXVec3Normalize(&m_tInfo.vDir,&m_tInfo.vDir);



	//m_fAngle = acosf(m_tInfo.vDir.x * m_tInfo.vLook.x + m_tInfo.vDir.y * m_tInfo.vLook.y); //내적구하기 

	m_fAngle = acosf(D3DXVec3Dot(&m_tInfo.vDir,&m_tInfo.vLook));


	if (vMousePos.y > m_tInfo.vPos.y)
	{
		m_fAngle = 2* D3DX_PI - m_fAngle;
	}

	m_vPoint = D3DXVECTOR2(100.f * cosf(m_fAngle) + m_tInfo.vPos.x , -100.f * sinf(m_fAngle) * m_tInfo.vPos.y);


	m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;



}

void CPlayer::Render( HDC hdc )
{
	Rectangle(hdc, m_tInfo.vPos.x - 50, m_tInfo.vPos.y - 50, 
		m_tInfo.vPos.x + 50, m_tInfo.vPos.y + 50);

	MoveToEx(hdc, m_tInfo.vPos.x, m_tInfo.vPos.y, NULL);
	LineTo(hdc, m_vPoint.x, m_vPoint.y);
}

void CPlayer::Release()
{

}
