#include "StdAfx.h"
#include "StageBack.h"


CStageBack::CStageBack(void)
{
}

CStageBack::CStageBack( const OBJINFO& Info ) :
CStageStatic(Info)
{

}


CStageBack::~CStageBack(void)
{
}

HRESULT CStageBack::Initialize()
{

	return S_OK;
}

SCENE CStageBack::Progress()
{

	return SCENE_NONPASS;
}

void CStageBack::Render()
{

}

void CStageBack::Release()
{

}

CObj* CStageBack::Clone()
{

	return new CStageBack(*this);
}
