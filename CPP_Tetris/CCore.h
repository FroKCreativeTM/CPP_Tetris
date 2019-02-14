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
	// �̱��� �ھ� ������
	static CCore* GetInst()
	{
		if (!m_pInst)
			m_pInst = new CCore;
		return m_pInst;
	}

	// �޸� ����
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}

private:
	HANDLE	m_hConsole; // �ܼ��� �ڵ鸵 �ϱ� ���� �ν��Ͻ�

public : 
	bool Init(); // �ʱ�ȭ �Լ�
	void Run(); // ���� ���� �Լ�
	void SetConsolePos(int x, int y);
};

