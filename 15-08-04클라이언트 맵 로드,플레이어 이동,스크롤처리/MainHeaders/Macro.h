#pragma once

#define DECLARE_SINGLETON(type)public :		\
	static type** GetInstance(void)			\
	{										\
		static type* pInstance = new type;	\
				if(pInstance == NULL)		\
					pInstance = new type;	\
				return &pInstance;			\
	}										\
	static void DestroyInstance()			\
	{										\
		type** ppInstance = GetInstance();	\
		if(*ppInstance != NULL)				\
		{									\
			delete *ppInstance;				\
			*ppInstance = NULL;				\
		}									\
	}

#define GET_SINGLE(type) (*type::GetInstance())
#define	ERR_MSG(hWnd,sz) MessageBox(hWnd,sz,L"system err",MB_OK)
#define DESTROY_SINGLE(type) (*type::GetInstance())->DestroyInstance();
