#pragma once
#include "Define.h"

class CTimeMgr
{
public:
	DECLARE_SINGLETON(CTimeMgr);
private:
	LARGE_INTEGER	m_FrameTime;
	LARGE_INTEGER	m_FixTime;
	LARGE_INTEGER	m_LastTime;
	LARGE_INTEGER	m_CpuTick;

	float			m_fTime;
	
	//1초에 cpu가 카운팅 하는 숫자
	//QueryPerformanceFrequency()
	//현재 cpu 가 카운팅 한 숫자 
	//QueryPerformanceCounter()
public:
	void InitTimeMgr();
	void SetTime();
	
public:
	float GetTime()const 
	{
		return m_fTime;
	}

private:
	CTimeMgr(void);
public:
	~CTimeMgr(void);
};

