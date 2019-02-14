#pragma once

#include "Value.h"

class CShapeManager
{
public:
	CShapeManager();
	~CShapeManager();

private:
	static CShapeManager* m_pShapeInst;

public:
	static CShapeManager* GetInst()
	{
		if (!m_pShapeInst)
			m_pShapeInst = new CShapeManager;
		return m_pShapeInst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_pShapeInst);
	}

private : 
	// 바닥에 쌓인 도형을 표현한다.
	list<class CShape*> m_ShapeList;
	// 현재 나와있는 도형을 표현한다.
	class CShape* m_pCurShape;
	// 다음 나올 도형을 표현
	class CShape* m_pNextShape;

public :
	// 도형 만드는 메서드
	void Update();
	void Rander();
	class CShape* CreateRandomShape();
	class CShape* CreateShape(SHAPE_TYPE eType);
};

