#include "stdafx.h"
#include "UI.h"
#include "windows.h"
#include <Commctrl.h>
#include "Instrument.h"
#include "Resource.h"
#pragma comment(lib, "COMCTL32.lib")
UI::UI(HWND hWnd, HINSTANCE hInstance)
{
#define BUTTON_WIDTH  110
#define BUTTON_HEIGHT 30
	int margin = 100;
	
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
	HWND penColorButton = CreateWindowEx(NULL, L"BUTTON", L"PEN COLOR",
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, margin, BUTTON_WIDTH, BUTTON_HEIGHT, hWnd, (HMENU)UI_INSTRUMENTS_PENCOLOR, hInstance, NULL);
	margin += BUTTON_HEIGHT;
	HWND brushColorButton = CreateWindowEx(NULL, L"BUTTON", L"BRUSH COLOR",
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, margin, BUTTON_WIDTH, BUTTON_HEIGHT, hWnd, (HMENU)UI_INSTRUMENTS_BRUSHCOLOR, hInstance, NULL);
	margin += BUTTON_HEIGHT;
	linewidthEdit = CreateWindowEx(NULL, L"EDIT", NULL,
		WS_VISIBLE | WS_CHILD, 10, margin, BUTTON_WIDTH, BUTTON_HEIGHT, hWnd, (HMENU)UI_SPINBOX_WIDTH, hInstance, NULL);
	RECT rect = { 0, 0, 0, 0 };
	INITCOMMONCONTROLSEX InitCtrlEx;

	InitCtrlEx.dwSize = sizeof(INITCOMMONCONTROLSEX);
	InitCtrlEx.dwICC = ICC_BAR_CLASSES;
	InitCommonControlsEx(&InitCtrlEx);
	const int NUMBUTTONS = 3;
	TBBUTTON tbrButtons[NUMBUTTONS];

	tbrButtons[0].iBitmap = 0;
	tbrButtons[0].idCommand = UI_INSTRUMENTS_PEN;
	tbrButtons[0].fsState = TBSTATE_ENABLED;
	tbrButtons[0].fsStyle = TBSTYLE_BUTTON;
	tbrButtons[0].dwData = 0L;
	tbrButtons[0].iBitmap = 0;
	tbrButtons[0].iString = 0;

	tbrButtons[1].iBitmap = 1;
	tbrButtons[1].idCommand = UI_INSTRUMENTS_POLYGON;
	tbrButtons[1].fsState = TBSTATE_ENABLED;
	tbrButtons[1].fsStyle = TBSTYLE_BUTTON;
	tbrButtons[1].dwData = 0L;
	tbrButtons[1].iString = 0;

	tbrButtons[2].iBitmap = 2;
	tbrButtons[2].idCommand = UI_INSTRUMENTS_OVAL;
	tbrButtons[2].fsState = TBSTATE_ENABLED;
	tbrButtons[2].fsStyle = TBSTYLE_BUTTON;
	tbrButtons[2].dwData = 0L;
	tbrButtons[2].iString = 0;

	HWND hWndToolbar = CreateToolbarEx(hWnd,
		WS_VISIBLE | WS_CHILD | WS_BORDER,
		IDB_INSTRUMENTS,
		NUMBUTTONS,
		hInstance,
		IDB_INSTRUMENTS,
		tbrButtons,
		NUMBUTTONS,
		16, 16, 16, 16,
		sizeof(TBBUTTON));
	GetClientRect(hWnd, &rect);
	HWND Canvas = CreateWindowEx(WS_EX_ACCEPTFILES, L"STATIC", NULL, WS_CHILD | WS_VISIBLE , 130, 30, rect.right - 150, rect.bottom-30, hWnd, NULL, hInstance, NULL);
	GetClientRect(Canvas, &rect);
	Instrument::canvasRect = rect;
	Instrument::DeviceDC = GetDC(Canvas);
	Instrument::MemoryDC = CreateCompatibleDC(Instrument::DeviceDC);
	Instrument::Buffer = CreateCompatibleBitmap(Instrument::DeviceDC, rect.right, rect.bottom);
	SelectObject(Instrument::MemoryDC, Instrument::Buffer);
	static HBRUSH Brush = CreateSolidBrush(RGB(255, 255, 255));
	FillRect(Instrument::MemoryDC, &rect, Brush);
}

