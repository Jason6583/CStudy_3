#pragma once

typedef struct AstarNode
{
	float		fCost;
	int			iIndex;
	AstarNode*	pParent;
}NODE;


typedef struct tagObjInfo
{
	D3DXVECTOR3		vPos;
	D3DXVECTOR3		vDir;
	D3DXVECTOR3		vLook;
	D3DXVECTOR3		vCenter;
	D3DXVECTOR3		vRect;
	D3DXMATRIX		matWorld;

	tagObjInfo(void) {}
	tagObjInfo(const tagObjInfo& Info) 
		:vPos(Info.vPos), vDir(Info.vDir), vLook(Info.vLook),vCenter(Info.vCenter),vRect(Info.vRect), matWorld(Info.matWorld) {}
}OBJINFO;

typedef struct tagInfo
{
	TCHAR			szName[128];
	int				iLevel;
	int				iAttack;
	int				iDefence;
	int				iGenderIdx;
	BYTE			byItem;
}INFO;


typedef struct  tagTexture
{
	LPDIRECT3DTEXTURE9		pTexture;
	D3DXIMAGE_INFO			ImgInfo;
}TEXINFO;

typedef struct tagTile
{
	D3DXVECTOR3			vPos;
	D3DXVECTOR3			vSize;
	BYTE				byDrawId;
	BYTE				byOption;
	BYTE                byObject;
}TILE;