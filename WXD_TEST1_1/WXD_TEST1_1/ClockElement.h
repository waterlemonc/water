#pragma once
#include "MATH.h"
#define PI 3.14159265
class CClockElement
{
public:
	void SetColor(COLORREF crMain, COLORREF crOther); //设置颜色
	void setRegion(LPRECT lprcRect); //设置绘图区域
	void SetTime(const CTime &tmCur); //设置时间
	virtual void Draw(CDC *PDC) = 0; //绘图函数
	CClockElement();
	virtual ~CClockElement();
	
protected:
	COLORREF m_crMain; //主要颜色
	COLORREF m_crOther; 
	CTime m_tmCur; //当前时刻
	CRect m_rcRegion; //绘图区域
	int m_nRadius; //时钟半径
};

