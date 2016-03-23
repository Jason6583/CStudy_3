#pragma once

const int WINSIZEX = 800;
const int WINSIZEY = 600;

const int TILECNTX = 20;
const int TILECNTY = 40;
const int TILESIZEX = 130;
const int TILESIZEY = 68;

const int ITEM_EAR		= 0x01; // 0000 0001
const int ITEM_GOLD		= 0x02; // 0000 0010
const int ITEM_MENTAL	= 0x04; 

enum WINMODE
{
	WINMODE_FULL,
	WINMODE_WIN
};

enum TEXTYPE
{
	TEXTYPE_SINGLE,
	TEXTYPE_MULTI
};

enum SCENE
{
	SCENE_LOGO,
	SCENE_STAGE,
	
};