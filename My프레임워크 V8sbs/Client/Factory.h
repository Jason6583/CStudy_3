#pragma once

#include "Defines.h"

template <typename T, typename T1>
class CFactory
{
public:
	T* CreateInstance(void)
	{
		T*		pInstance = new T1;
		pInstance->Initialize();
		return pInstance;
	}
public:
	CFactory(void) {}
	~CFactory(void) {}
};
