// ImageFileOpen.cpp : 实现文件
//

#include "stdafx.h"
#include "Win7MemoryForensic.h"
#include "ImageFileOpen.h"
#include "afxdialogex.h"


// ImageFileOpen 对话框

IMPLEMENT_DYNAMIC(ImageFileOpen, CDialogEx)

ImageFileOpen::ImageFileOpen(CWnd* pParent /*=NULL*/)
	: CDialogEx(ImageFileOpen::IDD, pParent)
{

}

ImageFileOpen::~ImageFileOpen()
{
}

void ImageFileOpen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ImageFileOpen, CDialogEx)
END_MESSAGE_MAP()


// ImageFileOpen 消息处理程序
