#pragma once

typedef struct tagInfo
{
	TCHAR	szName[128];
	int		nLevel;
	int		nAttack;
	int		nDefence;
	int		nGenderIdx;
	BYTE	byItem;
}INFO;


typedef struct tagTexture
{
	LPDIRECT3DTEXTURE9 pTexture;
	D3DXIMAGE_INFO		ImgInfo;

}TEXINFO;

typedef struct tagTile
{
	D3DXVECTOR3	vPos;
	D3DXVECTOR3	vSize;
	BYTE		byDrawId;
	BYTE		byOption;

}TILE;
