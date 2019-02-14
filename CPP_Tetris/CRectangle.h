#pragma once
#include "Shape.h"
#include "Value.h"

class CRectangle :
	public CShape
{
public:
	CRectangle();
	~CRectangle();

public : 
	bool Init();
};

