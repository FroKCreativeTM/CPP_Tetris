#pragma once

#include "Value.h"

class CStageManager
{
private:
	CStageManager();
	~CStageManager();

private : 
	static CStageManager* m_pStageInst;

public : 
	static CStageManager* GetInst()
	{
		if (!m_pStageInst)
			m_pStageInst = new CStageManager;
		return m_pStageInst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_pStageInst);
	}

private : 
	class CStage* m_pCurStage;

public : 
	bool Init();
	void Run();
};

