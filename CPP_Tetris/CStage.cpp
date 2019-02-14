#include "CStage.h"

CStage::CStage()
{ 
}

CStage::~CStage()
{
}

bool CStage::Init()
{
	// 비어있는 틀 제작
	memset(m_Stage, 0, STAGE_WIDTH * STAGE_HEIGHT);

	return true;
}

// 비어있는 내부를 블록으로 감싸기.
void CStage::Render()
{
	// 2칸을 좀 더 추가하는 이유는 블록으로 감싸기 때문
	for (int i = 0; i < STAGE_HEIGHT + 1; ++i)
	{
		for (int j = 0; j < STAGE_WIDTH + 2; ++j)
		{
			if (i == 0 && (j == 0 || j == STAGE_WIDTH + 1))
				cout << "■";

			else if (j == 0)
				cout << "■";

			else if (i == STAGE_HEIGHT)
				cout << "■";

			else if (j == STAGE_WIDTH + 1)
				cout << "■";

			else
				cout << "  "; // 2바이트라 공백 두개
		}
		cout << endl;
	}
}
