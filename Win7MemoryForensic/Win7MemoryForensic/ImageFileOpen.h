#pragma once


// ImageFileOpen 对话框

class ImageFileOpen : public CDialogEx
{
	DECLARE_DYNAMIC(ImageFileOpen)

public:
	ImageFileOpen(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ImageFileOpen();

// 对话框数据
	enum { IDD = IDD_DIALOG_OPEN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
