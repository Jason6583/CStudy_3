#pragma once
#include "stdafx.h"
using namespace std;

typedef struct tagInfo
{
	D3DXVECTOR3  vPos;  //��ġ
	D3DXVECTOR3  vDir;  //���⺤��
	D3DXVECTOR3  vLook; //0���� �ٶ󺸴� ���⺤��
	D3DXMATRIX   matWorld;
}INFO;

extern HWND g_hWnd;

