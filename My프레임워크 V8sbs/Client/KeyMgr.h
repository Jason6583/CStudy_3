#pragma once
#include "Defines.h"

class CKeyMgr 
{
public: 
	DECLARE_SINGLETON(CKeyMgr);
private:
	// 유저가 누른 키의 정보를 저장할 변수.
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
