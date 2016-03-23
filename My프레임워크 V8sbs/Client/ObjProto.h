#pragma once

#include "Prototype.h"

#include "Obj.h"
// CObj를 부모로 가지는 객체들의 원형을 모아두는 클래스
class CObjProto
	: public CPrototype
{
protected:
	map<const TCHAR*, CObj*>			m_MapProto;

public: //getter
	CObj* GetProto(const TCHAR* pObjKey);
public:
	virtual HRESULT InitProtoInstance(void) PURE;	
	virtual void Release(void);
public:
	CObjProto(void);
	~CObjProto(void);
};
