#pragma once

typedef struct tagObjInfo
{
	D3DXVECTOR3	vPos;
	D3DXVECTOR3	vDir;
	D3DXVECTOR3	vLook;
	D3DXVECTOR3	vCenter;
	D3DXMATRIX	matWorld;

	tagObjInfo(){}
	 //원본객체를 복사 
	tagObjInfo(const tagObjInfo& Info) :
	vPos(Info.vPos), vDir(Info.vDir), vLook(Info.vLook), matWorld(Info.matWorld)
	{
	}
}OBJINFO;


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
