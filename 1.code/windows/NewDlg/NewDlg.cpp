#include "stdafx.h"
#include "NewDlg.h"

void HandleCommandDlg1(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
	switch (idCtl)
	{
	case IDOK:
		MessageBox(hwndDlg, TEXT("你好，世界！"), TEXT("hello world!"), MB_OK);
		break;
	default:
		break;
	}
}

// 处理窗口消息的窗口过程
INT_PTR CALLBACK DlgProcDlg1(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		HandleCommandDlg1(hwndDlg, (HWND)(lParam), (int)(LOWORD(wParam)), (UINT)HIWORD(wParam));
		return TRUE;
	case WM_CLOSE:
		EndDialog(hwndDlg, 0);
		return TRUE;
	}
	return FALSE;
}
// 处理命令消息的函数
void HandleCommand(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
    switch (idCtl)
    {
    case IDOK:
		DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG1), hwndDlg, DlgProcDlg1);
        //MessageBox(hwndDlg, TEXT("你好，世界！"), TEXT("hello world!"), MB_OK);
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
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_NEWDLG_DIALOG), NULL, DlgProc);
    return 0;
}
