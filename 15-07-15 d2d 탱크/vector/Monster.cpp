#include "StdAfx.h"
#include "Monster.h"
#include "Player.h"

CMonster::CMonster(void) :
m_fSpeed(0),
m_fAngle(0),
m_fAngleBody(0)
{
}


CMonster::~CMonster(void)
{
	Release();
}

void CMonster::Initialize()
{
	m_Info.vPos = D3DXVECTOR3(200.f, 200.f, 0.f);
	m_vMoveDir  = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_vConPos	= D3DXVECTOR3(0.f, 0.f, 0.f);

	//왼쪽 위
	m_vOriPoint[0].x = m_Info.vPos.x - 30.f;
	m_vOriPoint[0].y = m_Info.vPos.y - 30.f;
	m_vOriPoint[0].z = 0.f;

	//오른쪽 위
	m_vOriPoint[1].x = m_Info.vPos.x + 30.f;
	m_vOriPoint[1].y = m_Info.vPos.y - 30.f;
	m_vOriPoint[1].z = 0.f;

	//오른쪽 아래
	m_vOriPoint[2].x = m_Info.vPos.x + 30.f;
	m_vOriPoint[2].y = m_Info.vPos.y + 30.f;
	m_vOriPoint[2].z = 0.f;

	//왼쪽 아래
	m_vOriPoint[3].x = m_Info.vPos.x - 30.f;
	m_vOriPoint[3].y = m_Info.vPos.y + 30.f;
	m_vOriPoint[3].z = 0.f;

	m_Info.vDir = D3DXVECTOR3(1.f, 1.f, 0.f);
	m_Info.vLook = D3DXVECTOR3(1.f, 0.f, 0.f);
	m_fSpeed = 2.f;


}

void CMonster::Progress()
{
	CPlayer* m_pPlayer;
	m_pPlayer = new CPlayer;
	
	D3DXVECTOR3 vPlayerPos = D3DXVECTOR3(m_pPlayer->GetInfo().vPos.x,m_pPlayer->GetInfo().vPos.y, 0.f);
	

	m_vConPos = D3DXVECTOR3(200.f, 200.f, 0.f);
	m_vConPos += m_vMoveDir;

	m_Info.vDir = vPlayerPos - m_Info.vPos;
	D3DXVec3Normalize(&m_Info.vDir, &m_Info.vDir);

	m_fAngle = acosf(D3DXVec3Dot(&m_Info.vDir,&m_Info.vLook));

	
	if (vPlayerPos.y > m_Info.vPos.y)
	{
		m_fAngle = 2 * D3DX_PI - m_fAngle;
	}

	m_vPoint = D3DXVECTOR2(100.f * cosf(m_fAngle) + m_Info.vPos.x
		, -100.f * sinf(m_fAngle) + m_Info.vPos.y);



	//몸통

	D3DXMATRIX	matScale; //크기
	D3DXMATRIX	matRotZ; //회전
	D3DXMATRIX	matTrans;//이동

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, m_fAngleBody);
	D3DXMatrixTranslation(&matTrans,m_Info.vPos.x, m_Info.vPos.y, m_Info.vPos.z);

	//크자이공부

	//크기 * 자전 * 이동 * 공전 * 부모
	m_Info.matWorld = matScale * matRotZ * matTrans;


	POINT ptTmp;

	for (int i = 0; i<4; i++)
	{
		m_vConPoint[i] = m_vOriPoint[i];
		m_vConPoint[i].x -= m_Info.vPos.x;
		m_vConPoint[i].y -= m_Info.vPos.y;

		D3DXVec3TransformCoord(&m_vConPoint[i], &m_vConPoint[i], &m_Info.matWorld);

		m_vConPoint[i] += m_vMoveDir;

		//D3DXVec3TransformCoord(); //이동값까지 가져옴
		//D3DXVec3TransformNormal(); //이동값 없이 회전값만 가져옴
	}


	m_Info.vPos += m_Info.vDir * m_fSpeed ;
}

void CMonster::Render( HDC hdc )
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

void CMonster::Release()
{

}
