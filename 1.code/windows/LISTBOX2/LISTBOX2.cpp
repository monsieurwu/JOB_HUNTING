#include "stdafx.h"
#include "LISTBOX2.h"
#include<tchar.h>

// 处理命令消息的函数
void HandleCommand(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
	int i;
	TCHAR str[256] = { 0 };
	TCHAR str2[256] = { 0 };
	TCHAR str3[256] = { 0 };
	TCHAR str4[256] = { 0 };

    switch (idCtl)
    {
    case IDC_BUTTON1:
	{
		HWND hwndList = GetDlgItem(hwndDlg, IDC_LIST1);
		i = ListBox_GetCurSel(hwndList);
		ListBox_GetText(hwndList, i, str);
		_stprintf(str2, TEXT("选择了列表框的第%d项： %s"), i, str);
		MessageBox(hwndDlg, str2, TEXT("LIST 按钮"), MB_OK);
		break;
	}
	case IDC_BUTTON2:
	{
		HWND hwndBox = GetDlgItem(hwndDlg, IDC_COMBO1);
		i = ComboBox_GetCurSel(hwndBox);
		ComboBox_GetLBText(hwndBox, i, str3);
		_stprintf(str4, TEXT("选择了列表框的第%d项： %s"), i, str3);
		MessageBox(hwndDlg, str4, TEXT("BOX 按钮"), MB_OK);
		break;
	}
	case IDC_LIST1:
		if (codeNotify == LBN_DBLCLK)
		{
			//控件是列表框 而双击的也是列表框时 就不需要获取列表框的句柄了 就是 hwndCtl 可以直接使用传入的
			i = ListBox_GetCurSel(hwndCtl);
			ListBox_GetText(hwndCtl, i, str);
			_stprintf(str2, TEXT("选择了列表框的第%d项： %s"), i, str);
			MessageBox(hwndDlg, str2, TEXT("双击组合框"), MB_OK);
			break;
		}
		
	case IDC_COMBO1:
		if (codeNotify == CBN_SELENDOK) {
			i = ComboBox_GetCurSel(hwndCtl);
			ComboBox_GetLBText(hwndCtl, i, str3);
			_stprintf(str4, TEXT("选择了列表框的第%d项： %s"), i, str3);
			MessageBox(hwndDlg, str4, TEXT("BOX 按钮"), MB_OK);
		}
		break;
	default:
        break;
    }
}

// 处理窗口消息的窗口过程
INT_PTR CALLBACK DlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HWND h;
    switch (uMsg)
    {
    case WM_INITDIALOG:
		h = GetDlgItem(hwndDlg, IDC_LIST1);
		ListBox_AddString(h, TEXT("小丽"));
		ListBox_AddString(h, TEXT("小红"));
		ListBox_AddString(h, TEXT("小芳"));
		ListBox_AddString(h, TEXT("小娟"));
		ListBox_SetCurSel(h, 0);
		h = GetDlgItem(hwndDlg, IDC_COMBO1);
		ComboBox_AddString(h, TEXT("中文"));
		ComboBox_AddString(h, TEXT("日语"));
		ComboBox_AddString(h, TEXT("英语"));
		ComboBox_AddString(h, TEXT("法语"));
		ComboBox_SetCurSel(h, 0);

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
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_LISTBOX2_DIALOG), NULL, DlgProc);
    return 0;
}
