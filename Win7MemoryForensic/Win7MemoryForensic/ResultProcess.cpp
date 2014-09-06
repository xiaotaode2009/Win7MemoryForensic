// ResultProcess.cpp : 实现文件
#include "stdafx.h"
#include "ResultProcess.h"

//#include "MemoryAnalysisQuick.h"
// ResultProcess 对话框

IMPLEMENT_DYNAMIC(ResultProcess, CDialogEx)

ResultProcess::ResultProcess(CWnd* pParent /*=NULL*/)
	: CDialogEx(ResultProcess::IDD, pParent)
{
	
}

ResultProcess::~ResultProcess()
{
}

void ResultProcess::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CTRL_PROCESS, m_ListCtrProcesses);
	DDX_Control(pDX, IDC_LIST_LOADMODUEL, loadModuel);
}


BEGIN_MESSAGE_MAP(ResultProcess, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SHOW, &ResultProcess::OnBnClickedButtonShow)
	ON_BN_CLICKED(IDC_BUTTON_ENSURE, &ResultProcess::OnBnClickedButtonEnsure)
	ON_BN_CLICKED(IDC_BUTTON_ADDRESSTRANSLATION, &ResultProcess::OnBnClickedButtonAddresstranslation)
	ON_BN_CLICKED(IDC_BUTTON_LOADMODUEL, &ResultProcess::OnBnClickedButtonLoadmoduel)
END_MESSAGE_MAP()


// ResultProcess 消息处理程序


void ResultProcess::OnBnClickedButtonShow()
{
	//MessageBox(_T("xiaotao"));
	int nIndex=0;
	CString strCount;
	//strCount.Format("%d",nIndex+1);
	//m_ListCtrProcesses.InsertItem(nIndex,_T("AA"));
	//m_ListCtrProcesses.SetItemText(nIndex,0,_T("AA"));
	//m_ListCtrProcesses.SetItemText(nIndex,1,_T("AA"));
	//m_ListCtrProcesses.SetItemText(nIndex,2,_T("AA"));
	//m_ListCtrProcesses.SetItemText(nIndex,3,_T("AA"));
	//m_ListCtrProcesses.SetItemText(nIndex,4,_T("AA"));
	
	char *path = theApp.path.GetBuffer(theApp.path.GetLength());
	MessageBox(path);
	static MemoryAnalysis memory_Analysis = MemoryAnalysis(path);
	
	//theApp.memory_Analysis = MemoryAnalysis(path);
	//MemoryAnalysis memory_Analysis = theApp.memory_Analysis;

	memory_Analysis.Eprocess_inti();

	//memory_Analysis.Moduel_inti(0x7ffdf000,0x1d4ec000);
	//char* name = (LPSTR)(LPCTSTR)memory_Analysis.moduel_array.GetAt(1).path;

    // MessageBox(name);	
	//theApp.memoryanalysis = memory_Analysis;
	//MemoryAnalysisQuick quickAnalysis;
	//quickAnalysis.EprocessInit();
	CString tmpPid;
	CString tmpPPid;
	CString tmpCR3;
	CString tmpPeb;
	PROCESS tmpProcess;
	MessageBox(path);
	for (int nIndex=0;nIndex<memory_Analysis.process_array.GetCount();nIndex++)
	//for (int nIndex=0;nIndex<quickAnalysis.process_array.GetCount();nIndex++)
	{
		//memory_Analysis.Open_Image();
		CString strCount;//计数
		strCount.Format("%d",nIndex+1);
		tmpProcess=memory_Analysis.process_array.GetAt(nIndex);
		//tmpProcess=quickAnalysis.process_array.GetAt(nIndex);
		tmpPid.Format("%x",tmpProcess.Pid);
		tmpPPid.Format("%x",tmpProcess.PPid);
		tmpCR3.Format("%x",tmpProcess.DirectoryTableBase);
		tmpPeb.Format("%x",tmpProcess.Peb);
		m_ListCtrProcesses.InsertItem(nIndex,strCount);
		m_ListCtrProcesses.SetItemText(nIndex,0,strCount);
		m_ListCtrProcesses.SetItemText(nIndex,1,tmpPid);
		m_ListCtrProcesses.SetItemText(nIndex,2,tmpPPid);
		m_ListCtrProcesses.SetItemText(nIndex,3,tmpProcess.strName);
		m_ListCtrProcesses.SetItemText(nIndex,4,tmpCR3);
		m_ListCtrProcesses.SetItemText(nIndex,5,tmpPeb);

	}
	UpdateData(FALSE);
	GetDlgItem(IDC_BUTTON_SHOW)->EnableWindow(FALSE);

}


BOOL ResultProcess::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	/*char *path = theApp.path.GetBuffer(theApp.path.GetLength());
	MessageBox(path);
	this->memory_Analysis  = MemoryAnalysis(path);
	memory_Analysis.Eprocess_inti();*/
	m_ListCtrProcesses.SetExtendedStyle(LVS_LIST|LVS_EX_FLATSB|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE);
	m_ListCtrProcesses.InsertColumn(0,_T("Num"),LVCFMT_LEFT,60,0);
	m_ListCtrProcesses.InsertColumn(1,_T("Pid"),LVCFMT_LEFT,60,1);
	m_ListCtrProcesses.InsertColumn(2,_T("PPid"),LVCFMT_LEFT,60,2);
	m_ListCtrProcesses.InsertColumn(3,_T("ProcessName"),LVCFMT_LEFT,100,3);
	m_ListCtrProcesses.InsertColumn(4,_T("CR3"),LVCFMT_LEFT,100,4);
	m_ListCtrProcesses.InsertColumn(5,_T("Peb"),LVCFMT_LEFT,100,4);
	m_ListCtrProcesses.InsertColumn(6,_T("CreateTime"),LVCFMT_LEFT,100,4);
	loadModuel.InsertColumn(0,_T("Num"),LVCFMT_LEFT,60,0);
	loadModuel.InsertColumn(1,_T("Bse"),LVCFMT_LEFT,60,1);
	loadModuel.InsertColumn(2,_T("Size"),LVCFMT_LEFT,60,2);
	loadModuel.InsertColumn(4,_T("Name"),LVCFMT_LEFT,100,3);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
void ResultProcess::OnBnClickedButtonEnsure()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void ResultProcess::OnBnClickedButtonAddresstranslation()
{
	AddressTranslation address_translation;
	address_translation.DoModal();
}



void ResultProcess::OnBnClickedButtonLoadmoduel()
{
	// TODO: 在此添加控件通知处理程序代码
	CString PEB ;
	CString DTB;
	AddressTranslation  add;
	GetDlgItemText(IDC_EDIT_LOADMODUEL,PEB);
	GetDlgItemText(IDC_LOADMODUEL2,DTB);
    uint32_t peb_Virtual = add.StringToHex((LPSTR)(LPCTSTR)PEB);
    uint32_t dtb_Virtual = add.StringToHex((LPSTR)(LPCTSTR)DTB);
	int nIndex=0;
	char *path = theApp.path.GetBuffer(theApp.path.GetLength());
    MemoryAnalysis memory_Analysis = MemoryAnalysis(path);
	memory_Analysis.Moduel_inti(peb_Virtual,dtb_Virtual);
	Moduel tmpModuel;
	CString base;
	CString size;
	for (int nIndex=0;nIndex<memory_Analysis.moduel_array.GetCount()-1;nIndex++)
	{
		//memory_Analysis.Open_Image();
		CString strCount;//计数
		strCount.Format("%d",nIndex+1);
		tmpModuel = memory_Analysis.moduel_array.GetAt(nIndex);
		//tmpProcess=quickAnalysis.process_array.GetAt(nIndex);
		base.Format("%d",tmpModuel.base);
		size.Format("%d",tmpModuel.size);
		loadModuel.InsertItem(nIndex,strCount);
		loadModuel.SetItemText(nIndex,0,strCount);
		loadModuel.SetItemText(nIndex,1,base);
		loadModuel.SetItemText(nIndex,2,size);
		loadModuel.SetItemText(nIndex,3,tmpModuel.path);

	}
	UpdateData(FALSE);


}


