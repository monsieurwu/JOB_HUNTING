#include "stdafx.h"
#include "Group_Box.h"
#include <tchar.h>

// 处理命令消息的函数
void HandleCommand(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
	UINT checkState = 0;
	TCHAR str[256] = { 0 };
	TCHAR strf[256] = { 0 };
	HWND h;
	TCHAR text[] = TEXT("GG");
    switch (idCtl)
    {
    case IDOK:
        MessageBox(hwndDlg, TEXT("已保存"), TEXT("hello world!"), MB_OK);
        break;
	case IDC_RADIO3:
	case IDC_RADIO4:
	case IDC_RADIO5:
	case IDC_RADIO6:
	case IDC_RADIO7:

	case IDC_CHECK3:
	case IDC_CHECK4:

	case IDC_CHECK5:
	case IDC_CHECK6:

		Button_GetText(hwndCtl, str, sizeof(str));
		checkState = Button_GetCheck(hwndCtl);
		if (checkState == BST_CHECKED)
		{
			_stprintf(strf, TEXT("[%s] 按钮被选中"), str);
			MessageBox(hwndDlg, strf, TEXT("确定被点击"), MB_ICONEXCLAMATION);

		}
		else
		{
			_stprintf(strf, TEXT("[%s] 按钮被取消"), str);
			MessageBox(hwndDlg, strf, TEXT("确定被点击"), MB_ICONEXCLAMATION);
		}



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
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_GROUP_BOX_DIALOG), NULL, DlgProc);
    return 0;
}
