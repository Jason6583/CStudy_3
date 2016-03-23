#include "StdAfx.h"
#include "KeyMgr.h"

CKeyMgr::CKeyMgr(void)
: m_dwKey(0)
{
}

CKeyMgr::~CKeyMgr(void)
{
}

bool CKeyMgr::PushKey(DWORD dwKey)
{
	if(m_dwKey & dwKey)
		return true;
	return false;
}


void CKeyMgr::SetKeyCheck(void)
{
	m_dwKey = 0x00000000;

	if(GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_dwKey |= KEY_LEFT;
	}
	if(GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_dwKey |= KEY_RIGHT;
	}
	if(GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_dwKey |= KEY_UP;
	}
	if(GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_dwKey |= KEY_DOWN;
	}
	if(GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		m_dwKey |= KEY_SPACE;
	}
	if(GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		m_dwKey |= KEY_RETURN;
	}
	if(GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		m_dwKey |= KEY_LBUTTON;
	}

	if(GetAsyncKeyState(VK_RBUTTON) & 0x8000)
	{
		m_dwKey |= KEY_RBUTTON;
	}

	
	if(GetAsyncKeyState(VK_F5) & 0x8000)
	{
		m_dwKey |= KEY_F5;
	}

}