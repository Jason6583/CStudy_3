#include "StdAfx.h"
#include "Obj.h"
#include "Include.h"

CObj::CObj(void) :
m_fFrame(0.f)
{
}

CObj::CObj( const OBJINFO& Info ) :
m_Info(Info),
m_fFrame(0.f)
{

}


CObj::~CObj(void)
{
}

void CObj::Frame_Move( const float& fCnt, const float& fMax )
{
	m_fFrame += fCnt * GET_SINGLE(CTimeMgr)->GetTime(); //cnt 넣어준만큼 늘어남
	
	if (m_fFrame > fMax)
	{
		m_fFrame = 0.f;
	}


}
