#pragma once
#include "Defines.h"

class CKeyMgr 
{
public: 
	DECLARE_SINGLETON(CKeyMgr);
private:
	// ������ ���� Ű�� ������ ������ ����.
	DWORD			m_dwKey;
public:
	void SetKeyCheck(void);
	DWORD GetKey(){return m_dwKey;}
	bool PushKey(DWORD dwKey);
	
private:
	CKeyMgr(void);
public:
	~CKeyMgr(void);
};
