
// WXD_TEST1_1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "WXD_TEST1_1.h"
#include "WXD_TEST1_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CWXD_TEST1_1Dlg 对话框



CWXD_TEST1_1Dlg::CWXD_TEST1_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWXD_TEST1_1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWXD_TEST1_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_CLOCK, m_Clock);
	DDX_Control(pDX, IDC_CLOCK, m_Clock);
}

BEGIN_MESSAGE_MAP(CWXD_TEST1_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
//	ON_STN_CLICKED(IDC_TIME, &CWXD_TEST1_1Dlg::OnStnClickedTime)
ON_WM_CTLCOLOR()
ON_STN_CLICKED(IDC_TIME, &CWXD_TEST1_1Dlg::OnStnClickedTime)
ON_STN_CLICKED(IDC_WEEK, &CWXD_TEST1_1Dlg::OnStnClickedWeek)
END_MESSAGE_MAP()


// CWXD_TEST1_1Dlg 消息处理程序

BOOL CWXD_TEST1_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	SetTimer(1, 1000, NULL);
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CWXD_TEST1_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CWXD_TEST1_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CRect rect;
		CPaintDC dc(this);
		GetClientRect(rect);
		dc.FillSolidRect(rect,RGB(0,0,0)); //设置为黑色背景
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CWXD_TEST1_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWXD_TEST1_1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//电子时钟显示
	CTime t = CTime::GetCurrentTime();
	CString time;
	time = t.Format("%H:%M:%S");
	SetDlgItemText(IDC_TIME, time);

	//显示周几
	CString weekstr;
	weekstr = t.Format("%w");
	CString week;
	week=weekstr == "0" ? "星期日" : weekstr == "1" ? "星期一" : weekstr == "2" ? "星期二" : weekstr == "3" ?"星期三" : weekstr == "4" ? "星期四" : weekstr == "5" ? "星期五" : weekstr == "6" ? "星期六" : "-1";
	SetDlgItemText(IDC_WEEK, week);

	//显示月份
	CString month;
	month = t.Format("%Y年%m月%d日");
	SetDlgItemText(IDC_MONTH, month);


	CDialogEx::OnTimer(nIDEvent);
}





HBRUSH CWXD_TEST1_1Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	//----------------------------------------------------------------------------

 

    // TODO:  在此更改 DC 的任何特性

	if (pWnd->GetDlgCtrlID() == IDC_TIME  || pWnd->GetDlgCtrlID() == IDC_WEEK || pWnd->GetDlgCtrlID() == IDC_MONTH)

    {

        pDC->SetTextColor(RGB(0,255 , 0));//设置字体颜色

        pDC->SetBkColor(RGB(0, 0, 0));//设置背景颜色


    }

    // TODO:  如果默认的不是所需画笔，则返回另一个画笔

    return hbr;

}


void CWXD_TEST1_1Dlg::OnStnClickedTime()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CWXD_TEST1_1Dlg::OnStnClickedWeek()
{
	// TODO: 在此添加控件通知处理程序代码
}
