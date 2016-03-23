#pragma once

#include "Defines.h"

class CTimeMgr
{
public:
	DECLARE_SINGLETON(CTimeMgr);
private:
	LARGE_INTEGER			m_FrameTime;
	LARGE_INTEGER			m_FixTime;
	LARGE_INTEGER			m_LastTime;
	LARGE_INTEGER			m_CpuTick;
	float					m_fTime;
public:
	void InitTimeMgr(void);
	void SetTime(void);
public:
	float GetTime(void) const {
		return m_fTime;}

private:
	CTimeMgr(void);
public:
	~CTimeMgr(void);
};
