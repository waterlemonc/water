
// WXD_TEST1_1Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "ClockEx.h"


// CWXD_TEST1_1Dlg 对话框
class CWXD_TEST1_1Dlg : public CDialogEx
{
// 构造
public:
	CWXD_TEST1_1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_WXD_TEST1_1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	CStatic m_Clock;
	CClockEx m_Clock;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnStnClickedTime();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnStnClickedTime();
	afx_msg void OnStnClickedWeek();
};
