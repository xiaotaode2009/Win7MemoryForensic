
// Win7MemoryForensic.h : Win7MemoryForensic Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif
#include "resource.h"       // ������
//#include "MemoryAnalysisQuick.h"
#include "MemoryAnalysis.h"


// CWin7MemoryForensicApp:
// �йش����ʵ�֣������ Win7MemoryForensic.cpp
//

class CWin7MemoryForensicApp : public CWinAppEx
{
public:
	CWin7MemoryForensicApp();
// ��д
public:
	virtual BOOL InitInstance();
	CString path;
	//MemoryAnalysis memory_Analysis;
	//MemoryAnalysis memoryanalysis;
	
// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWin7MemoryForensicApp theApp;
