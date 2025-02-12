#include "stdafx.h"
#include "Notepad.h"
#include "Command.h"

void ShowVersion(HWND hwndDlg) {
	MessageBox(hwndDlg, TEXT("\
作品更新历史\n \
<---------------------------------->\n \
V1.0\n \
首个版本，实现了文本文件的打开、保存、另存为功能\n \
		"), TEXT("版本号V1.0"), MB_OK);
}

struct NotePad npad;
// 处理命令消息的函数
void HandleCommand(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
    switch (idCtl)
    {
    case ID_MENU_OPEN:
        //MessageBox(hwndDlg, TEXT("你好，世界！"), TEXT("hello world!"), MB_OK);
		OpenFile(&npad);//传指针不传结构体的好处是节省空间
		break;
	case ID_MENU_SAVE:
		//MessageBox(hwndDlg, TEXT("你好，世界！"), TEXT("hello world!"), MB_OK);
		SaveFile(&npad);//传指针不传结构体的好处是节省空间
		break;
	case ID_MENU_SAVE_AS:
		//MessageBox(hwndDlg, TEXT("你好，世界！"), TEXT("hello world!"), MB_OK);
		SaveAsFile(&npad);
		break;
	case ID_MENU_QUIT:
		EndDialog(hwndDlg, 0);
		break;
	case ID_MENU_ABOUT:
		ShowVersion(hwndDlg);
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
		npad.hwndDlg = hwndDlg;
		npad.hwndEdit = GetDlgItem(hwndDlg, IDC_EDIT1);
		npad.hwndStatic = GetDlgItem(hwndDlg, IDC_STATIC);

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
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_NOTEPAD_DIALOG), NULL, DlgProc);
    return 0;
}
