#pragma once

#define DECLARE_SINGLETON(type)\
	static type** GetInstance(void)\
	{\
		static type*	pInstance = new type;\
		if(pInstance == NULL)\
			pInstance = new type;\
		return &pInstance;\
	}\
	static void DestroyInstance(void)\
	{\
		type**	ppInstance = GetInstance();\
		if(*ppInstance != NULL)\
		{\
			delete *ppInstance;\
			*ppInstance = NULL;\
		}\
	}
#define GET_SINGLE(type) (*type::GetInstance())
#define DESTROY_SINGLE(type) (*type::GetInstance())->DestroyInstance()
#define ERR_MSG(hWnd, sz) MessageBox(hWnd, sz, L"system err", MB_OK)
#define SELF_DELETE(p) if(p){delete p; p=NULL;}
#define PUSH_KEY(key) GET_SINGLE(CKeyMgr)->PushKey(key)