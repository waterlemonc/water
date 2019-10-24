#pragma once
#include "clockelement.h"
class CClockMinHand :
	public CClockElement
{
public:
	CClockMinHand(void);
	virtual ~CClockMinHand(void);
	virtual void Draw(CDC *pDC);
};

