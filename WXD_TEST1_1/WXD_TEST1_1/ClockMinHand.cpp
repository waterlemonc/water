#include "stdafx.h"
#include "ClockMinHand.h"


CClockMinHand::CClockMinHand(void)
{
	//定义默认颜色
	m_crMain = RGB(0,255,100);
	m_crOther = RGB(128,128,0);
}


CClockMinHand::~CClockMinHand(void)
{
}

void CClockMinHand::Draw(CDC *pDC)
{
	//初始化环境设备
	CPen penMain(PS_SOLID,1,m_crMain), penOther(PS_SOLID,1,m_crOther);
	CBrush brMain(m_crMain), brOther(m_crOther);
	CPen *pOldpen = pDC->SelectObject(&penOther);
	CBrush *pOldBrush = pDC->SelectObject(&brMain);

	//确定分针所在位置的弧度
	int nTime = m_tmCur.GetMinute()*60;
	nTime += m_tmCur.GetSecond();
	double fRadian = 2*PI*nTime/3600;
	CPoint ptDiamond[4];
	for(int i=0; i<4; i++)
	{
		ptDiamond[i] = m_rcRegion.CenterPoint();
	}
	int nRadus = m_nRadius/1.5;
	ptDiamond[0].Offset((int)(nRadus * sin(fRadian)), (int)(-nRadus * cos(fRadian)) );
	fRadian += 0.5*PI;
	nRadus = m_nRadius/20;
	ptDiamond[1].Offset((int)(nRadus * sin(fRadian)), (int)(-nRadus * cos(fRadian)) );
	fRadian += 0.5 * PI;
	nRadus = m_nRadius/10;
	ptDiamond[2].Offset((int)(nRadus * sin(fRadian)), (int)(-nRadus * cos(fRadian)) );
	fRadian += 0.5*PI;
	nRadus = m_nRadius/20;
	ptDiamond[3].Offset((int)(nRadus * sin(fRadian)), (int)(-nRadus * cos(fRadian)) );
	 //绘制菱形分针
	pDC->Polygon(ptDiamond, 4);
	//恢复环境设备
	pDC->SelectObject(pOldpen);
	pDC->SelectObject(pOldBrush);
}
