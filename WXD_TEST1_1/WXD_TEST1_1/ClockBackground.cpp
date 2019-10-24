#include "stdafx.h"
#include "WXD_TEST1_1.h"
#include "ClockBackground.h"


CClockBackground::CClockBackground(void)
{
	//时钟背景颜色
	m_crMain = RGB(0,255,0);
	m_crOther = RGB(0,128,0);
}


CClockBackground::~CClockBackground(void)
{
}

void CClockBackground::Draw(CDC *pDC)
{
	//准备设备环境
	CPen penMain(PS_SOLID, 1, m_crMain), penOther(PS_SOLID, 1, m_crOther);
	CBrush brMain(m_crMain), brOther(m_crOther);
	CPen *pOldPen = pDC->SelectObject(&penOther);
	CBrush *pOldBrush = pDC->SelectObject(&brMain);

	CPoint ptCenter = m_rcRegion.CenterPoint();
	int nRadius = m_nRadius - 8;
	for(int i=0; i<60; i++)
	{
		CPoint ptEnd = ptCenter;
		ptEnd.Offset((int)(nRadius * sin(2 * PI * (i % 60) / 60)),
			(int)(-nRadius * cos(2 * PI * (i % 60) / 60)));
		CRect rcDot(-2, -2, 2, 2);
		rcDot.OffsetRect(ptEnd);
		pDC->Ellipse(rcDot);
	}
	//绘制12个小方框，表示12个正点
	pDC->SelectObject(&penMain);
	pOldBrush = pDC->SelectObject(&brOther);
	for(int i=0; i<12; i++)
	{
		CPoint ptEnd = ptCenter;
		double fRadian = 2 * PI * (i % 12) / 12;
		ptEnd.Offset((int)(nRadius * sin(fRadian)),	(int)(-nRadius * cos(fRadian)));
		CRect rcDot(-3, -3, 3, 3);
		rcDot.OffsetRect(ptEnd);
		pDC->Rectangle(rcDot);
	}

	//还原设备环境
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);

}
