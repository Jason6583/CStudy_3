#pragma once
#include "Define.h"

class CObj
{
protected:
	OBJINFO		m_Info;
	TCHAR*		m_pObjKey;
	TCHAR*		m_pStateKey;
protected:
	SORTID		m_SortID;
protected://객체 애니메이션
	float		m_fFrame;
public:
	void Frame_Move(const float& fCnt, const float& fMax);

public:
	SORTID GetSortID()
	{
		return m_SortID;
	}

public:
	virtual HRESULT Initialize()PURE;
	virtual SCENE Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual CObj* Clone()PURE;
public:
	CObj(void);
	CObj(const OBJINFO& Info);
	virtual ~CObj(void);
};

