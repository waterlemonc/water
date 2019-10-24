#pragma once
#include "Clockelement.h"
class CClockSecHand :
	public CClockElement
{
public:
	CClockSecHand(void);
	virtual ~CClockSecHand(void);
	virtual void Draw(CDC *pDC);
};

