#pragma once

#include "Value.h"

class CShape
{
public :
	CShape();
	virtual ~CShape();

protected : 
	char	m_cShape[4][4];
	POSITION m_tPos;
	POSITION m_tPivot; // 도형 회전할 때 기준점
	int m_iWigthCount; // 가로 몇 칸짜리

public : 
	void SetPosition(int x, int y)
	{
		m_tPos.x = x;
		m_tPos.y = y;
	}

	void SetPosition(const POSITION& tPos)
	{
		m_tPos = tPos;
	}

	POSITION GetPosition() const
	{
		return m_tPos;
	}

	POSITION GetPivor() const
	{
		return m_tPivot;
	}

public : 
	virtual bool Init();
	void Render();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
};

