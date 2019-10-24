#include "stdafx.h"
#include "ClockHourHand.h"


CClockHourHand::CClockHourHand(void)
{
	m_crMain = RGB(0, 255, 100);
	m_crOther = RGB(128, 125, 0);
}


CClockHourHand::~CClockHourHand(void)
{
}

void CClockHourHand::Draw(CDC* pDC)
{
	//初始化设备环境
	CPen penMain(PS_SOLID, 1, m_crMain), penOther(PS_SOLID, 1, m_crOther);
	CBrush brMain(m_crMain), brOther(m_crOther);
	CPen *pOldPen = pDC->SelectObject(&penOther);
	CBrush *pOldBrush = pDC->SelectObject(&brMain);
	
	//确定当前指针的弧度
	int nTime = (m_tmCur.GetHour() % 12) * 3600;
	nTime += m_tmCur.GetMinute() * 60;
	nTime += m_tmCur.GetSecond();
	double fRadian = 2 * PI * nTime / 3600 / 12; 
	//确定绘制菱形指针所需的四个角的坐标
	CPoint ptDiamond[4];
	for(int i=0; i<4; i++)
	{
		ptDiamond[i] = m_rcRegion.CenterPoint();
	}
	int nRadus = m_nRadius / 2;
	ptDiamond[0].Offset((int)(nRadus * sin(fRadian)), (int)(- nRadus * cos(fRadian)));
	fRadian += 0.5 * PI;
	nRadus = m_nRadius / 20;
	ptDiamond[1].Offset((int)(nRadus * sin(fRadian)), (int)(- nRadus * cos(fRadian)));
	fRadian += 0.5 * PI;
	nRadus = m_nRadius / 10;
	ptDiamond[2].Offset((int)(nRadus * sin(fRadian)), (int)(- nRadus * cos(fRadian)));
	fRadian += 0.5 * PI;
	nRadus = m_nRadius / 20;
	ptDiamond[3].Offset((int)(nRadus * sin(fRadian)), (int)(- nRadus * cos(fRadian)));
	//绘制菱形时针
	pDC->Polygon(ptDiamond, 4);
	
	//恢复设备环境
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);

}
