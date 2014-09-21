#include "stdafx.h"
#include "UI.h"
#include "windows.h"
#include "Instrument.h"
RECT rect = { 0, 0, 700, 500 };


UI::UI(HWND hWnd, HINSTANCE hInstance)
{
#define BUTTON_WIDTH  100
#define BUTTON_HEIGHT 30
	int margin = 10;
	
	HWND penButton = CreateWindowEx(NULL,L"BUTTON",L"PEN",
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, margin, BUTTON_WIDTH, BUTTON_HEIGHT, hWnd, (HMENU)UI_INSTRUMENTS_PEN, hInstance, NULL);
	margin += BUTTON_HEIGHT;
	HWND brushButton = CreateWindowEx(NULL, L"BUTTON", L"BRUSH",
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, margin, BUTTON_WIDTH, BUTTON_HEIGHT, hWnd, (HMENU)UI_INSTRUMENTS_BRUSH, hInstance, NULL);
	margin += BUTTON_HEIGHT;
	HWND PolygonButton = CreateWindowEx(NULL, L"BUTTON", L"Polygon",
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, margin, BUTTON_WIDTH, BUTTON_HEIGHT, hWnd, (HMENU)UI_INSTRUMENTS_POLYGON, hInstance, NULL);
	margin += BUTTON_HEIGHT;
	HWND ovalButton = CreateWindowEx(NULL, L"BUTTON", L"OVAL",
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, margin, BUTTON_WIDTH, BUTTON_HEIGHT, hWnd, (HMENU)UI_INSTRUMENTS_OVAL, hInstance, NULL);
	margin += BUTTON_HEIGHT;
	HWND triangleButton = CreateWindowEx(NULL, L"BUTTON", L"TRIANGLE",
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, margin, BUTTON_WIDTH, BUTTON_HEIGHT, hWnd, (HMENU)UI_INSTRUMENTS_TRIANGLE, hInstance, NULL);
	margin += BUTTON_HEIGHT;
	HWND textOutButton = CreateWindowEx(NULL, L"BUTTON", L"TEXT OUT",
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, margin, BUTTON_WIDTH, BUTTON_HEIGHT, hWnd, (HMENU)UI_INSTRUMENTS_TEXTOUT, hInstance, NULL);
	margin += BUTTON_HEIGHT;
	HWND grabeButton = CreateWindowEx(NULL, L"BUTTON", L"GRABE",
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, margin, BUTTON_WIDTH, BUTTON_HEIGHT, hWnd, (HMENU)UI_INSTRUMENTS_GRABE, hInstance, NULL);
	margin += BUTTON_HEIGHT;
	HWND zoomButton = CreateWindowEx(NULL, L"BUTTON", L"ZOOM",
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, margin, BUTTON_WIDTH, BUTTON_HEIGHT, hWnd, (HMENU)UI_INSTRUMENTS_ZOOM, hInstance, NULL);
	margin += BUTTON_HEIGHT;
	HWND colorButton = CreateWindowEx(NULL, L"BUTTON", L"COLOR",
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, margin, BUTTON_WIDTH, BUTTON_HEIGHT, hWnd, (HMENU)UI_INSTRUMENTS_ZOOM, hInstance, NULL);
	margin += BUTTON_HEIGHT;
	linewidthEdit = CreateWindowEx(NULL, L"EDIT", NULL,
		WS_VISIBLE | WS_CHILD, 10, margin, BUTTON_WIDTH, BUTTON_HEIGHT, hWnd, (HMENU)UI_SPINBOX_WIDTH, hInstance, NULL);
	
	GetClientRect(hWnd, &rect);
	HWND Canvas = CreateWindowEx(WS_EX_ACCEPTFILES, L"STATIC", NULL, WS_CHILD | WS_VISIBLE , 120, 20, rect.right-120, rect.bottom, hWnd, NULL, hInstance, NULL);
	GetClientRect(Canvas, &rect);
	Instrument::DeviceDC = GetDC(Canvas);
	Instrument::MemoryDC = CreateCompatibleDC(Instrument::DeviceDC);
	Instrument::Buffer = CreateCompatibleBitmap(Instrument::DeviceDC, rect.right, rect.bottom);
	SelectObject(Instrument::MemoryDC, Instrument::Buffer);
	static HBRUSH Brush = CreateSolidBrush(RGB(255, 255, 255));
	FillRect(Instrument::MemoryDC, &rect, Brush);
}

