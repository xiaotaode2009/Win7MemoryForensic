
// Win7MemoryForensic.h : Win7MemoryForensic 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif
#include "resource.h"       // 主符号
//#include "MemoryAnalysisQuick.h"
#include "MemoryAnalysis.h"


// CWin7MemoryForensicApp:
// 有关此类的实现，请参阅 Win7MemoryForensic.cpp
//

class CWin7MemoryForensicApp : public CWinAppEx
{
public:
	CWin7MemoryForensicApp();
// 重写
public:
	virtual BOOL InitInstance();
	CString path;
	//MemoryAnalysis memory_Analysis;
	//MemoryAnalysis memoryanalysis;
	
// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWin7MemoryForensicApp theApp;
