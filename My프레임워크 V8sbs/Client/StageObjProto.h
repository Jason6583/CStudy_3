#pragma once

#include "objproto.h"

class CStageObjProto :
	public CObjProto
{
public:
	virtual HRESULT InitProtoInstance(void);
public:
	CStageObjProto(void);
	~CStageObjProto(void);
};
