//#pragma once
#include "afxcmn.h"
#include "MemoryAnalysis.h"
#include "afxdialogex.h"
#include "Process.h"
#include "Win7MemoryForensic.h"
#include "AddressTranslation.h"

// ResultProcess 对话框

class ResultProcess : public CDialogEx
{
	DECLARE_DYNAMIC(ResultProcess)
public:
  
public:
	ResultProcess(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ResultProcess();
   // MemoryAnalysis memory_Analysis;

// 对话框数据
	enum { IDD = IDD_DIALOG_PROCESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonShow();
	virtual BOOL OnInitDialog();
	CListCtrl m_ListCtrProcesses;
	//MemoryAnalysis memory_Analysis;
	afx_msg void OnBnClickedButtonEnsure();
	afx_msg void OnBnClickedButtonAddresstranslation();
	afx_msg void OnBnClickedButtonLoadmoduel();
	afx_msg void OnEnChangeLoadmoduel2();
	afx_msg void OnLvnItemchangedListLoadmoduel(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl loadModuel;
};
