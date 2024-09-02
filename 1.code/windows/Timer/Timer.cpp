#include "stdafx.h"
#include "Timer.h"

#define TIMER_ID 1

VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR nTimerid, DWORD dwTime)
{
	// 在这里执行定时器触发时要执行的操作
	MessageBox(NULL, TEXT("你好，世界！"), TEXT("定时器"), MB_OK);
}

// 处理命令消息的函数
void HandleCommand(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
    switch (idCtl)
    {
    case IDOK:
        //MessageBox(hwndDlg, TEXT("你好，世界！"), TEXT("hello world!"), MB_OK);
		// 创建定时器，指定标识符为 TIMER_ID，每隔 1000毫秒，调用一次 TimerProc 函数
		SetTimer(hwndDlg, TIMER_ID, 1000, TimerProc);
		break;
	case IDC_BUTTON1:
		// 销毁标识符为 TIMER_ID 的定时器
		KillTimer(hwndDlg, TIMER_ID);
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
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_TIMER_DIALOG), NULL, DlgProc);
    return 0;
}
