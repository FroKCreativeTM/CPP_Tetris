#include "CCore.h"
#include "CStageManager.h"
#include "CShapeManager.h"

CCore* CCore::m_pInst = NULL;

CCore::CCore()
{
	srand((unsigned int)time(0));
}

CCore::~CCore()
{
	CShapeManager::DestroyInst();
	CStageManager::DestroyInst();
}

bool CCore::Init()
{
	// �ܼ�â �ڵ� ����
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // ��� �ڵ鸵 ǥ��

	if (m_hConsole == INVALID_HANDLE_VALUE)
		return false; // �ڵ鸵 �Ұ��� ���� ��ȯ

	// �������� �����ڸ� �ʱ�ȭ!
	if (!CStageManager::GetInst()->Init())
		return false;

	return true;
}

void CCore::Run()
{
	while (true)
	{
		system("cls");
		CShapeManager::GetInst()->Update();
		CStageManager::GetInst()->Run();
		CShapeManager::GetInst()->Rander();

		Sleep(1000); // �ʴ� �� �� ���ư���
	}
}

void CCore::SetConsolePos(int x, int y)
{
	// COORD�� short������ �Ǿ��ִ� x, y
	// 2����Ʈ¥�� ���� ���� ������ ���ϱ� 2�� �� �� (�� ��Ʈ���� ������ �� ĭ�� 2����Ʈ�̴�.)
	COORD pos = { x * 2,y }; 
	SetConsoleCursorPosition(m_hConsole, pos);
}
