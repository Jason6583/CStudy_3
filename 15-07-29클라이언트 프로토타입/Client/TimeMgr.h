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
	
	//1�ʿ� cpu�� ī���� �ϴ� ����
	//QueryPerformanceFrequency()
	//���� cpu �� ī���� �� ���� 
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

