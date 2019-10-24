// ClockEx.cpp : 实现文件
//

#include "stdafx.h"
#include "WXD_TEST1_1.h"
#include "ClockEx.h"

// CClockEx

IMPLEMENT_DYNAMIC(CClockEx, CStatic)

CClockEx::CClockEx()
{

}

CClockEx::~CClockEx()
{
}


BEGIN_MESSAGE_MAP(CClockEx, CStatic)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CClockEx 消息处理程序




void CClockEx::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Invalidate(FALSE);
	CStatic::OnTimer(nIDEvent);
}


void CClockEx::PreSubclassWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	GetClientRect(m_rcClient); //获取当前客户区域
	m_clockBK.setRegion(m_rcClient);
	m_clockHour.setRegion(m_rcClient);
	m_clockSec.setRegion(m_rcClient);
	m_clockMin.setRegion(m_rcClient);

	SetTimer(1, 100, NULL);	 //每100毫秒刷新一次

	CStatic::PreSubclassWindow();
}


void CClockEx::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// TODO: 在此处添加消息处理程序代码
	CDC	 dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap	bmp;
	bmp.CreateCompatibleBitmap(&dc, m_rcClient.Width(), m_rcClient.Height());
	dcMem.SelectObject(&bmp);
	DrawClock(&dcMem);	//绘制时钟
	dc.BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(), &dcMem, 0, 0, SRCCOPY);

	// Do not call CStatic::OnPaint() for painting messages
}
void CClockEx::DrawClock(CDC *pDC)
{
	CTime tmCur = CTime::GetCurrentTime();
	m_clockBK.SetTime(tmCur);
	m_clockHour.SetTime(tmCur);
	m_clockMin.SetTime(tmCur);
	m_clockSec.SetTime(tmCur);

	
	m_clockBK.Draw(pDC);
	m_clockHour.Draw(pDC);
	m_clockMin.Draw(pDC);
	m_clockSec.Draw(pDC);

	// 不为绘图消息调用 CStatic::OnPaint()
}


void CClockEx::OnSize(UINT nType, int cx, int cy)
{
	CStatic::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	GetClientRect(m_rcClient);
	m_clockBK.setRegion(m_rcClient);
	m_clockHour.setRegion(m_rcClient);
}
