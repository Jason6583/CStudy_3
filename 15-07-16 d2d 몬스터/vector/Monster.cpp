#include "StdAfx.h"
#include "Monster.h"


CMonster::CMonster(void) : 
m_fAngle(0)
{
}


CMonster::~CMonster(void)
{
	Release();
}


void CMonster::Initialize()
{
	m_Info.vPos = D3DXVECTOR3(600.f, 100.f, 0.f);

	//왼쪽위
	m_vOriPoint[0].x = m_Info.vPos.x - 50.f;
	m_vOriPoint[0].y = m_Info.vPos.y - 50.f;
	m_vOriPoint[0].z = 0.f;

	//오,위
	m_vOriPoint[1].x = m_Info.vPos.x + 50.f;
	m_vOriPoint[1].y = m_Info.vPos.y - 50.f;
	m_vOriPoint[1].z = 0.f;

	//오,아
	m_vOriPoint[2].x = m_Info.vPos.x + 50.f;
	m_vOriPoint[2].y = m_Info.vPos.y + 50.f;
	m_vOriPoint[2].z = 0.f;

	//왼,아
	m_vOriPoint[3].x = m_Info.vPos.x - 50.f;
	m_vOriPoint[3].y = m_Info.vPos.y + 50.f;
	m_vOriPoint[3].z = 0.f;

	D3DXMatrixIdentity(&m_Info.matWorld);

	m_Info.vDir = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_Info.vLook = D3DXVECTOR3(1.0f, 0.f, 0.f);


}

void CMonster::Progress()
{
	D3DXMATRIX matTrans;
	D3DXMATRIX matRotZ;

	GetAngle();
	
	m_Info.vPos+= m_Info.vDir;
	D3DXMatrixRotationZ(&matRotZ,m_fAngle);
	D3DXMatrixTranslation(&matTrans, m_Info.vPos.x, m_Info.vPos.y, m_Info.vPos.z);

	m_Info.matWorld = matRotZ * matTrans;

	for (int i = 0; i<4; i++)
	{
		m_ConPoint[i] = m_vOriPoint[i];
		m_ConPoint[i] -= D3DXVECTOR3(600.f, 100.f, 0.f);
		D3DXVec3TransformCoord(&m_ConPoint[i], &m_ConPoint[i], &m_Info.matWorld);


	}

}

void CMonster::Render( HDC hdc )
{

	Rectangle(hdc,m_ConPoint[2].x - 10.f , m_ConPoint[2].y - 10.f
		, m_ConPoint[2].x + 10.f , m_ConPoint[2].y +10.f);
	Rectangle(hdc,m_ConPoint[1].x - 10.f , m_ConPoint[1].y - 10.f
		, m_ConPoint[1].x + 10.f , m_ConPoint[1].y +10.f);


	MoveToEx(hdc, m_ConPoint[0].x , m_ConPoint[0].y, NULL);
	LineTo(hdc, m_ConPoint[1].x , m_ConPoint[1].y);
	LineTo(hdc, m_ConPoint[2].x , m_ConPoint[2].y);
	LineTo(hdc, m_ConPoint[3].x , m_ConPoint[3].y);
	LineTo(hdc, m_ConPoint[0].x , m_ConPoint[0].y);




}

void CMonster::Release()
{

}

void CMonster::GetAngle()
{
	const INFO* pPlayerInfo= m_pPlayer->GetInfo();

	m_Info.vDir = pPlayerInfo->vPos - m_Info.vPos;//플레이어를 바라보는 벡터
	
	D3DXVec3Normalize(&m_Info.vDir, &m_Info.vDir);

	m_fAngle = acosf(D3DXVec3Dot(&m_Info.vDir, &m_Info.vLook));

	if (pPlayerInfo->vPos.y < m_Info.vPos.y)
	{
		m_fAngle = 2 * D3DX_PI - m_fAngle;
	}


}