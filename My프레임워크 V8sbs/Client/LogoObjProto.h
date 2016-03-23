#pragma once
#include "objproto.h"

class CLogoObjProto :
	public CObjProto
{
public:
	virtual HRESULT InitProtoInstance(void);

public:
	CLogoObjProto(void);
	~CLogoObjProto(void);
};
