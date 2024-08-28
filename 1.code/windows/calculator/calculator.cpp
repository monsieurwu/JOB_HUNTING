#include "stdafx.h"
#include "calculator.h"
BOOL b;
int value1, value2;
// 处理命令消息的函数
void HandleCommand(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
    switch (idCtl)
    {
    case IDC_BUTTON1:
		BOOL b;
		int value1;
		
		value1 = GetDlgItemInt(hwndDlg, IDC_EDIT1, &b, TRUE);
		value2 = GetDlgItemInt(hwndDlg, IDC_EDIT2, &b, TRUE);
		SetDlgItemInt(hwndDlg, IDC_STATIC2, value1 + value2, TRUE);


        break;
    default:
        break;
    }
}

// 处理窗口消息的窗口过程
INT_PTR CALLBACK DlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        return TRUE;
    case WM_COMMAND:
        HandleCommand(hwndDlg, (HWND)(lParam), (int)(LOWORD(wParam)), (UINT)HIWORD(wParam));
        return TRUE;
    case WM_CLOSE:
        EndDialog(hwndDlg, 0);
        return TRUE;
    }
    return FALSE;
}

// 程序入口
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //创建对话框窗口，设置窗口过程函数为 DlgProc
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_CALCULATOR_DIALOG), NULL, DlgProc);
    return 0;
}
