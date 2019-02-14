#include "CShapeManager.h"
#include "CRectangle.h"

CShapeManager* CShapeManager::m_pShapeInst = NULL;

CShapeManager::CShapeManager():
	m_pCurShape(NULL),
	m_pNextShape(NULL)
{
	m_pCurShape = CreateRandomShape();
}


CShapeManager::~CShapeManager()
{
	list<CShape*>::iterator iterEnd = m_ShapeList.end();
	for (list<CShape*>::iterator iter = m_ShapeList.begin(); iter != iterEnd;
		++iter)
	{
		SAFE_DELETE(*iter);
	}

	SAFE_DELETE(m_pCurShape);
	SAFE_DELETE(m_pNextShape);
}

void CShapeManager::Update()
{
	m_pCurShape->MoveDown();
}

void CShapeManager::Rander()
{
	list<CShape*>::iterator iterEnd = m_ShapeList.end();
	for (list<CShape*>::iterator iter = m_ShapeList.begin(); iter != iterEnd;
		++iter)
	{
		(*iter)->Render();
	}
	m_pCurShape->Render();
}

CShape* CShapeManager::CreateRandomShape()
{
	int iType = rand() % ST_END; // 도형 중 하나가 무조건 선택되도록

	return CreateShape((SHAPE_TYPE)iType);
}

CShape* CShapeManager::CreateShape(SHAPE_TYPE eType)
{
	CShape* pShape = NULL;

	switch (eType)
	{
	case ST_RECT:
		pShape = new CRectangle;
		break;
	case ST_END:
		break;
	}

	// 초기화 실패시
	if (!pShape->Init())
	{
		SAFE_DELETE(pShape);
		return NULL;
	}

	// 초기화 성공시 리턴
	return pShape;
}
