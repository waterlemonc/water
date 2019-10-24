#include "stdafx.h"
#include "WXD_TEST1_1.h"
#include "ClockElement.h"

CClockElement::CClockElement(void)
{
	m_nRadius = 0;
	m_crMain = RGB(255,255,255);
	m_crOther = RGB(128,128,128);
}


CClockElement::~CClockElement(void)
{
}

void CClockElement::setRegion(LPRECT lprcRect)
{
	m_rcRegion = lprcRect;
	m_nRadius = m_rcRegion.Width()/2;
	if(m_rcRegion.Width() > m_rcRegion.Height())
	{
		m_nRadius = m_rcRegion.Height()/2;
	}
}

void CClockElement::SetTime(const CTime &tmCur)
{
	m_tmCur = tmCur;
}

void CClockElement::SetColor(COLORREF crMain, COLORREF crOther)
{
	m_crMain = crMain;
	m_crOther = crOther;
}
