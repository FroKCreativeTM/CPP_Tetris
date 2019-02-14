#include "Shape.h"
#include "CCore.h"

CShape::CShape()
{
	m_iWigthCount = 0;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			m_cShape[i][j] = '1'; // 1을 빈공간으로 하자.
		}
	}
}


CShape::~CShape()
{
}

bool CShape::Init()
{
	m_tPivot.x = 0;
	m_tPivot.y = 3;

	return false;
}

void CShape::Render()
{
	for (int i = 0; i < 4; ++i)
	{	
		// 콘솔창에 출력할 좌표를 설정한 후 출력한다.
		CCore::GetInst()->SetConsolePos(m_tPos.x, m_tPos.y - (3 - i));

		for (int j = 0; j < 4; ++j)
		{
			if (m_cShape[i][j] == '0')
				cout << "■";

			else
				cout << "  ";
		}
		cout << endl;
	}
}

void CShape::MoveDown()
{
	if (m_tPos.y == STAGE_HEIGHT - 1)
		return;

	--m_tPos.y;
}

void CShape::MoveLeft()
{
	if (m_tPos.x == 0)
		return;

	--m_tPos.x;
}

void CShape::MoveRight()
{
	if (m_tPos.x + m_iWigthCount == STAGE_WIDTH)
		return;

	++m_tPos.x;
}
