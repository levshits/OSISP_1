#pragma once
#include "Instrument.h"
class Pen :	public Instrument
{
private:
	Pen(){};
public:
	static Pen* GetInstance()
	{
		static Pen _self;
		return &_self;
	}
	virtual void Draw(int x, int y)
	{
		MoveToEx(MemoryDC, previous_x, previous_y, NULL);
		LineTo(MemoryDC, x, y);
		previous_x = x;
		previous_y = y;
		BitBlt(DeviceDC, 0, 0, 700, 500, MemoryDC, 0, 0, SRCCOPY);
		//InvalidateRect(Canvas, NULL, false);
	}
	virtual void Display(int x, int y)
	{
		Draw(x, y);
	}
};

