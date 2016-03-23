#pragma once

#include "Defines.h"

class CObj
{
protected:
	OBJINFO			m_Info;
protected:
	TCHAR*			m_pObjKey;
	TCHAR*			m_pStateKey;
protected:
	SORTID			m_SortID;

protected: // 객체 애니메이션
	float			m_fFrame;
	static D3DXVECTOR2 m_vScroll;
public:
	void Frame_Move(const float& fCnt
				, const float& fMax);
public: //getter
	SORTID GetSortID(void) {
		return m_SortID;}
	RECT  GetRect();
public:
	int GetTileIndex(const D3DXVECTOR3& vPos);
	bool CollisionMouseToTile(D3DXVECTOR3 vPos
		, const TILE* pTileInfo);
public:
	virtual HRESULT Initialize(void)PURE;
	virtual SCENE Progress(void)PURE;
	virtual void Render(void)PURE;
	virtual void Release(void)PURE;
	virtual CObj* Clone(void)PURE;
public:
	CObj(void);
	CObj(const OBJINFO& Info);
	virtual ~CObj(void);
};
