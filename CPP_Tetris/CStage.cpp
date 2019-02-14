#include "CStage.h"

CStage::CStage()
{ 
}

CStage::~CStage()
{
}

bool CStage::Init()
{
	// ����ִ� Ʋ ����
	memset(m_Stage, 0, STAGE_WIDTH * STAGE_HEIGHT);

	return true;
}

// ����ִ� ���θ� ������� ���α�.
void CStage::Render()
{
	// 2ĭ�� �� �� �߰��ϴ� ������ ������� ���α� ����
	for (int i = 0; i < STAGE_HEIGHT + 1; ++i)
	{
		for (int j = 0; j < STAGE_WIDTH + 2; ++j)
		{
			if (i == 0 && (j == 0 || j == STAGE_WIDTH + 1))
				cout << "��";

			else if (j == 0)
				cout << "��";

			else if (i == STAGE_HEIGHT)
				cout << "��";

			else if (j == STAGE_WIDTH + 1)
				cout << "��";

			else
				cout << "  "; // 2����Ʈ�� ���� �ΰ�
		}
		cout << endl;
	}
}
