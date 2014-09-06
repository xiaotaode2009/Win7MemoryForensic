// ImageInformation.cpp : 实现文件
//

#include "stdafx.h"
#include "Win7MemoryForensic.h"
#include "ImageInformation.h"
#include "afxdialogex.h"


// ImageInformation 对话框

IMPLEMENT_DYNAMIC(ImageInformation, CDialogEx)

ImageInformation::ImageInformation(CWnd* pParent /*=NULL*/)
	: CDialogEx(ImageInformation::IDD, pParent)
{

}

ImageInformation::~ImageInformation()
{
}

void ImageInformation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ImageInformation, CDialogEx)
	ON_BN_CLICKED(IDOK, &ImageInformation::OnBnClickedOk)
END_MESSAGE_MAP()


// ImageInformation 消息处理程序


void ImageInformation::OnBnClickedOk()
{
	
	
	
}
