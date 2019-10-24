#pragma once
#include "Clockelement.h"
class CClockHourHand :
	public CClockElement
{
public:
	CClockHourHand();
	virtual ~CClockHourHand();
	virtual void Draw(CDC *pDC);
};

