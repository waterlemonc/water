#pragma once
#include "WXD_TEST1_1.h"
#include "ClockEx.h"
#include "ClockBackground.h"
#include "ClockHourHand.h"
#include "ClockMinHand.h"
#include "ClockSecHand.h"

// CClockEx

class CClockEx : public CStatic
{
	DECLARE_DYNAMIC(CClockEx)

public:
	CClockEx();
	virtual ~CClockEx();

private:
	CClockBackground m_clockBK; //背景
	CClockHourHand m_clockHour; //时针
	CClockMinHand m_clockMin; //分针
	CClockSecHand m_clockSec; //秒针

	CRect m_rcClient; //客户区

	void DrawClock(CDC *pDC);

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void PreSubclassWindow();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


