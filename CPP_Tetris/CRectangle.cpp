#include "CRectangle.h"



CRectangle::CRectangle()
{
}


CRectangle::~CRectangle()
{
}

bool CRectangle::Init()
{
	if (!CShape::Init())
		return false;

	m_cShape[2][0] = '0'; //블럭이 0임
	m_cShape[2][1] = '0';
	m_cShape[3][0] = '0';
	m_cShape[3][1] = '0';
	// 대충 아래처럼 되는 것임
	// 1111
	// 1111
	// 1001
	// 1001
	
	m_iWigthCount = 2; // 크기가 2
	m_tPos.x = 4;
	m_tPos.y = 0;

	return true;
}
