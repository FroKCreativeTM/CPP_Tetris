#include "CStageManager.h"
#include "CStage.h"

CStageManager* CStageManager::m_pStageInst = NULL;

CStageManager::CStageManager()
	:m_pCurStage(NULL)
{
}

CStageManager::~CStageManager()
{
}

bool CStageManager::Init()
{
	// 기본 스테이지를 생성
	m_pCurStage = new CStage;

	if (!m_pCurStage->Init())
		return false;

	return true;
}

void CStageManager::Run()
{
	m_pCurStage->Render();
}
