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
	// �ٴڿ� ���� ������ ǥ���Ѵ�.
	list<class CShape*> m_ShapeList;
	// ���� �����ִ� ������ ǥ���Ѵ�.
	class CShape* m_pCurShape;
	// ���� ���� ������ ǥ��
	class CShape* m_pNextShape;

public :
	// ���� ����� �޼���
	void Update();
	void Rander();
	class CShape* CreateRandomShape();
	class CShape* CreateShape(SHAPE_TYPE eType);
};

