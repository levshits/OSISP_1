#pragma once
#include "Instrument.h"

	class Brush :
		public Instrument
	{
	private:
		Brush(){};
	public:
		static Brush* GetInstance()
		{
			static Brush _self;
			return &_self;
		}
		virtual void Draw(int x, int y)
		{
			MoveToEx(MemoryDC, previous_x, previous_y, NULL);
			LineTo(MemoryDC, x, y);
			previous_x = x;
			previous_y = y;
			BitBlt(DeviceDC, canvasRect.left, canvasRect.top, canvasRect.right, canvasRect.bottom, MemoryDC, canvasRect.left, canvasRect.top, SRCCOPY);
		}
		virtual void Display(int x, int y)
		{
			Draw(x, y);
		}

	};


