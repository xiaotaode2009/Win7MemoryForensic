#pragma once


// ImageInformation 对话框

class ImageInformation : public CDialogEx
{
	DECLARE_DYNAMIC(ImageInformation)

public:
	ImageInformation(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ImageInformation();

// 对话框数据
	enum { IDD = IDD_DIALOG_IMAGEINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
