#pragma once

#include "Prototype.h"

#include "Obj.h"
// CObj�� �θ�� ������ ��ü���� ������ ��Ƶδ� Ŭ����
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
