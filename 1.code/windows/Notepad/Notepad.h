#pragma once

#include "resource.h"

struct NotePad {
	TCHAR FilePath[MAX_PATH];
	HWND hwndDlg;
	HWND hwndEdit;
	HWND hwndStatic;
};
