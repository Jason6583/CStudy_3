#include "StdAfx.h"
#include "Player.h"


CPlayer::CPlayer(void):
m_fSpeed(0),
m_fAngle(0),
m_fAngleBody(0)
{

}


CPlayer::~CPlayer(void)
{
	Release();
}

void CPlayer::Initialize()
{
	m_Info.vPos = D3DXVECTOR3(400.f, 300.f, 0.f);
	m_vMoveDir  = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_vConPos   = D3DXVECTOR3(0.f, 0.f, 0.f);

	//���� ��
	m_vOriPoint[0].x = m_Info.vPos.x - 50.f;
	m_vOriPoint[0].y = m_Info.vPos.y - 50.f;
	m_vOriPoint[0].z = 0.f;

	//������ ��
	m_vOriPoint[1].x = m_Info.vPos.x + 50.f;
	m_vOriPoint[1].y = m_Info.vPos.y - 50.f;
	m_vOriPoint[1].z = 0.f;

	//������ �Ʒ�
	m_vOriPoint[2].x = m_Info.vPos.x + 50.f;
	m_vOriPoint[2].y = m_Info.vPos.y + 50.f;
	m_vOriPoint[2].z = 0.f;

	//���� �Ʒ�
	m_vOriPoint[3].x = m_Info.vPos.x - 50.f;
	m_vOriPoint[3].y = m_Info.vPos.y + 50.f;
	m_vOriPoint[3].z = 0.f;


	m_Info.vDir = D3DXVECTOR3(1.f, 1.f, 0.f);
	m_Info.vLook = D3DXVECTOR3(1.f, 0.f,0.f);
	m_fSpeed = 3.f;

	


}

void CPlayer::Progress()
{
	POINT ptMouse;
	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd,&ptMouse);

	KeyCheck();

	D3DXVECTOR3 vMousePos = D3DXVECTOR3(ptMouse.x,ptMouse.y,0.f);

	//����
	m_vConPos = D3DXVECTOR3(400.f, 300.f, 0.f);
	m_vConPos += m_vMoveDir;

	m_Info.vDir = vMousePos - m_vConPos; //���콺�� �ٶ󺸴� ����
	D3DXVec3Normalize(&m_Info.vDir,&m_Info.vDir);

	m_fAngle = acosf(D3DXVec3Dot(&m_Info.vDir,&m_Info.vLook));

	if (vMousePos.y > m_vConPos.y)
	{
		m_fAngle = 2 * D3DX_PI - m_fAngle;
	}

	m_vPoint = D3DXVECTOR2(100.f * cosf(m_fAngle) + m_vConPos.x , -100.f * sinf(m_fAngle) + m_vConPos.y);

	//����

	D3DXMATRIX	matScale; //ũ��
	D3DXMATRIX	matRotZ; //ȸ��
	D3DXMATRIX	matTrans;//�̵�

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, m_fAngleBody);
	D3DXMatrixTranslation(&matTrans,m_Info.vPos.x, m_Info.vPos.y, m_Info.vPos.z);
	
	//ũ���̰���

	//ũ�� * ���� * �̵� * ���� * �θ�
	m_Info.matWorld = matScale * matRotZ * matTrans;

	POINT ptTmp;

	for (int i = 0; i<4; i++)
	{
		m_vConPoint[i] = m_vOriPoint[i];
		m_vConPoint[i].x -= m_Info.vPos.x;
		m_vConPoint[i].y -= m_Info.vPos.y;

		D3DXVec3TransformCoord(&m_vConPoint[i], &m_vConPoint[i], &m_Info.matWorld);

		m_vConPoint[i] += m_vMoveDir;

		//D3DXVec3TransformCoord(); //�̵������� ������
		//D3DXVec3TransformNormal(); //�̵��� ���� ȸ������ ������
	}


}

void CPlayer::Render( HDC hdc )
{
	Rectangle(hdc, m_vConPoint[2].x - 10.f, m_vConPoint[2].y - 10.f , m_vConPoint[2].x + 10.f , m_vConPoint[2].y + 10.f);
	Rectangle(hdc, m_vConPoint[1].x - 10.f, m_vConPoint[1].y - 10.f , m_vConPoint[1].x + 10.f , m_vConPoint[1].y + 10.f);

	MoveToEx(hdc, m_vConPoint[0].x , m_vConPoint[0].y, NULL);
	LineTo(hdc, m_vConPoint[1].x, m_vConPoint[1].y);
	LineTo(hdc, m_vConPoint[2].x, m_vConPoint[2].y);
	LineTo(hdc, m_vConPoint[3].x, m_vConPoint[3].y);
	LineTo(hdc, m_vConPoint[0].x, m_vConPoint[0].y);


	MoveToEx(hdc, m_vConPos.x, m_vConPos.y, NULL);
	LineTo(	hdc, m_vPoint.x, m_vPoint.y);



}

void CPlayer::Release()
{

}

void CPlayer::KeyCheck()
{
	if (GetKeyState('A')&0x8000)
	{
		m_fAngleBody -= D3DXToRadian(5.0f);
	}
	if (GetKeyState('D')&0x8000)
	{
		m_fAngleBody += D3DXToRadian(5.0f);
	}
	if (GetKeyState('W')&0x8000)
	{
		D3DXVECTOR3 vTmp;
		
		D3DXVec3TransformNormal(&vTmp, &m_Info.vLook, &m_Info.matWorld);

		m_vMoveDir += vTmp * m_fSpeed;
	}


}
