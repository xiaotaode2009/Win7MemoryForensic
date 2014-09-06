
// Win7MemoryForensicView.h : CWin7MemoryForensicView 类的接口
//

#pragma once


class CWin7MemoryForensicView : public CView
{
protected: // 仅从序列化创建
	CWin7MemoryForensicView();
	DECLARE_DYNCREATE(CWin7MemoryForensicView)

// 特性
public:
	CWin7MemoryForensicDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWin7MemoryForensicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Win7MemoryForensicView.cpp 中的调试版本
inline CWin7MemoryForensicDoc* CWin7MemoryForensicView::GetDocument() const
   { return reinterpret_cast<CWin7MemoryForensicDoc*>(m_pDocument); }
#endif

