#include "StdAfx.h"
#include "TimeMgr.h"


CTimeMgr::CTimeMgr(void) :
m_fTime(0.f)
{
}


CTimeMgr::~CTimeMgr(void)
{
}

void CTimeMgr::InitTimeMgr()
{
	QueryPerformanceCounter(&m_FrameTime);
	QueryPerformanceCounter(&m_FixTime);
	QueryPerformanceCounter(&m_LastTime);
	QueryPerformanceFrequency(&m_CpuTick);
}

void CTimeMgr::SetTime()
{
	QueryPerformanceCounter(&m_FrameTime);

	if (m_FrameTime.QuadPart - m_LastTime.QuadPart > m_CpuTick.QuadPart)//지난시간과 현재시간의 차이를 구해서 비교 
	{
		QueryPerformanceFrequency(&m_CpuTick);
		m_LastTime.QuadPart = m_FrameTime.QuadPart;
	}
	m_fTime = float(m_FrameTime.QuadPart - m_FixTime.QuadPart) / m_CpuTick.QuadPart;

	m_FixTime  = m_FrameTime; 
}
