#pragma once

#include "Value.h"

class CCore
{
private :
	CCore();
	~CCore();

private : 
	static CCore* m_pInst;

public : 
	// 싱글톤 코어 디자인
	static CCore* GetInst()
	{
		if (!m_pInst)
			m_pInst = new CCore;
		return m_pInst;
	}

	// 메모리 해제
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}

private:
	HANDLE	m_hConsole; // 콘솔을 핸들링 하기 위한 인스턴스

public : 
	bool Init(); // 초기화 함수
	void Run(); // 게임 실행 함수
	void SetConsolePos(int x, int y);
};

