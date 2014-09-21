#pragma once
#include "Instrument.h"
class Polygon :
	public Instrument
{
private:
	Polygon(){};
public:
	static Polygon* GetInstance()
	{
		static Polygon _self;
		return &_self;
	}
	virtual void Draw(int x, int y)
		{
		Rectangle(MemoryDC, x, y, previous_x, previous_y);
			BitBlt(DeviceDC, 0, 0, 700, 500, MemoryDC, 0, 0, SRCCOPY);
			//previous_x = x;
			//previous_y = y;
			//InvalidateRect(Canvas, NULL, false);
		}
		virtual void Display(int x, int y)
		{
			BitBlt(DeviceDC, 0, 0, 700, 500, MemoryDC, 0, 0, SRCCOPY);
			Rectangle(DeviceDC, x, y, previous_x, previous_y);
		}

};

