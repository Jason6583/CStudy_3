#pragma once
#include "stdafx.h"
using namespace std;

typedef struct tagInfo
{
	D3DXVECTOR3  vPos;  //위치
	D3DXVECTOR3  vDir;  //방향벡터
	D3DXVECTOR3  vLook; //0도를 바라보는 방향벡터
	D3DXMATRIX   matWorld; //4*4행렬
}INFO;

extern HWND g_hWnd;

