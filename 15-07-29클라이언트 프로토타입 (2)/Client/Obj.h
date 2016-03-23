#pragma once
#include "Define.h"

class CObj
{
protected:
	OBJINFO		m_Info;
	TCHAR*		m_pObjKey;
	TCHAR*		m_pStateKey;
public:
	virtual HRESULT Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual CObj* Clone()PURE;
public:
	CObj(void);
	CObj(const OBJINFO& Info);
	virtual ~CObj(void);
};

