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
	// 콘솔창 핸들 생성
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 출력 핸들링 표준

	if (m_hConsole == INVALID_HANDLE_VALUE)
		return false; // 핸들링 불가시 거짓 반환

	// 스테이지 관리자를 초기화!
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

		Sleep(1000); // 초당 한 번 돌아가게
	}
}

void CCore::SetConsolePos(int x, int y)
{
	// COORD는 short형으로 되어있는 x, y
	// 2바이트짜리 벽을 쓰기 때문에 곱하기 2를 한 것 (이 테트리스 구조상 한 칸이 2바이트이다.)
	COORD pos = { x * 2,y }; 
	SetConsoleCursorPosition(m_hConsole, pos);
}
