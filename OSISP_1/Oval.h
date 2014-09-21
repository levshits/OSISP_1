#pragma once
#include "Instrument.h"
class Oval :
	public Instrument
{
private:
	Oval(){};
public:
	static Oval* GetInstance()
	{
		static Oval _self;
		return &_self;
	}
	virtual void Draw(int x, int y)
	{
		Ellipse(MemoryDC, x, y, previous_x, previous_y);
		BitBlt(DeviceDC, 0, 0, 700, 500, MemoryDC, 0, 0, SRCCOPY);

	}
	virtual void Display(int x, int y)
	{
		BitBlt(DeviceDC, 0, 0, 700, 500, MemoryDC, 0, 0, SRCCOPY);
		Ellipse(DeviceDC, x, y, previous_x, previous_y);
	}

};

