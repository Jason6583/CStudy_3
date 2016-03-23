#pragma once
#include "Define.h"

class CPrototype;
class CSceneObj
{
protected:
	CPrototype*	m_pPrototype;
public:
	virtual HRESULT Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	CSceneObj(void);
	virtual ~CSceneObj(void);
};

