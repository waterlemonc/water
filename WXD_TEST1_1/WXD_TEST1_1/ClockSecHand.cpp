#include "stdafx.h"
#include "ClockSecHand.h"


CClockSecHand::CClockSecHand(void)
{
	//ÃëÕëÑÕÉ«
	m_crMain = RGB(0, 200, 200);
	m_crOther = RGB(0, 200, 200);
}


CClockSecHand::~CClockSecHand(void)
{

}

void CClockSecHand::Draw(CDC *pDC)
{
	int nTime = m_tmCur.GetSecond();

	CPoint ptStart = m_rcRegion.CenterPoint();
	CPoint ptEnd = ptStart;
	int nRadius = m_nRadius -10;
	ptEnd.Offset((int)(nRadius * sin(2 * PI *nTime / 60)), (int)(-nRadius * cos(2 * PI * nTime / 60)) );
	CPen penMain(PS_SOLID, 1, m_crMain);
	CPen *pOldPen = pDC->SelectObject(&penMain);
	pDC->MoveTo(ptStart);
	pDC->LineTo(ptEnd);
	pDC->SelectObject(pOldPen);
}
