#include "stdafx.h"
#include "Save_Open.h"
#include <shlobj.h>
void GetDirPath(HWND hwndDlg)
{
	TCHAR path[MAX_PATH] = { 0 };       //定义数组用于保存文件夹路径

	BROWSEINFO browseInfo = { 0 };      //定义BROWSEINFO 结构
	browseInfo.hwndOwner = hwndDlg;     //父窗口句柄

										//打开文件夹选择对话框，返回一个创建于系统分配内存的LPITEMIDLIST类型的变量
	LPITEMIDLIST pidl = SHBrowseForFolder(&browseInfo);
	if (pidl != NULL)
	{
		SHGetPathFromIDList(pidl, path);                //将文件夹的ID列表路径转换为字符串路径
		CoTaskMemFree(pidl);                            //释放系统分配的内存
		MessageBox(NULL, path, TEXT("选择的文件夹路径"), MB_OK);
	}
}

void OpenFile(HWND hwndDlg)
{
	TCHAR path[MAX_PATH] = { 0 };     //定义数组用于保存文件路径

	OPENFILENAME ofn;                 //定义OPENFILENAME结构
	ZeroMemory(&ofn, sizeof(ofn));    //将结构体中的属性清0
	ofn.lStructSize = sizeof(ofn);    //结构体大小
	ofn.hwndOwner = hwndDlg;          //父窗口句柄
	ofn.lpstrFile = path;             //指向保存文件路径的数组
	ofn.nMaxFile = sizeof(path);      //保存文件路径的数组大小
	ofn.lpstrFilter = TEXT("头文件.h\0*.h\0All\0*.*\0");//过滤后缀名
	if (GetOpenFileName(&ofn)) {      //如果选择了文件，则弹出消息框
		MessageBox(NULL, path, TEXT("打开路径"), MB_OK);
		//获取文件路径后，一般会 open--->read 它
	}
}

void SaveAsFile(HWND hwndDlg)
{
	TCHAR path[MAX_PATH] = { 0 };     //定义数组用于保存文件路径

	OPENFILENAME ofn;                 //定义OPENFILENAME结构
	ZeroMemory(&ofn, sizeof(ofn));    //将结构体中的属性清0
	ofn.lStructSize = sizeof(ofn);    //结构体大小
	ofn.hwndOwner = hwndDlg;          //父窗口句柄
	ofn.lpstrFile = path;             //指向保存文件路径的数组
	ofn.nMaxFile = sizeof(path);      //保存文件路径的数组大小
	ofn.lpstrFilter = TEXT("头文件.h\0*.h\0All\0*.*\0");//过滤后缀名

	if (GetSaveFileName(&ofn)) {      //如果填写了文件名，则弹出消息框
		MessageBox(NULL, path, TEXT("另存为的路径"), MB_OK);
		//获取文件路径后，一般会 open--->write 它
	}
}
// 处理命令消息的函数
void HandleCommand(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
    switch (idCtl)
    {
    case IDOK:
        //MessageBox(hwndDlg, TEXT("你好，世界！"), TEXT("hello world!"), MB_OK);
		GetDirPath(hwndDlg);
		break;
	case IDC_BUTTON1:
		OpenFile(hwndDlg);
		break;
	case IDC_BUTTON2:
		SaveAsFile(hwndDlg);
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
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_SAVE_OPEN_DIALOG), NULL, DlgProc);
    return 0;
}
