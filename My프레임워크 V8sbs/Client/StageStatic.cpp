#include "StdAfx.h"
#include "StageStatic.h"

CStageStatic::CStageStatic(void)
: m_fAngle(0.f)
{
}
CStageStatic::CStageStatic(const OBJINFO& Info)
: CObj(Info)
, m_fAngle(0.f)
{

}
CStageStatic::~CStageStatic(void)
{
}
