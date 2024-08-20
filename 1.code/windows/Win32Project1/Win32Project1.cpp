#include "stdafx.h"
#include "Win32Project1.h"
#include <tchar.h>

// ����������Ϣ�ĺ���
void HandleCommand(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
	int i;
	TCHAR str[256] = { 0 };
	TCHAR strf[256] = { 0 };
	switch (idCtl)
	{
	case IDC_BUTTON1:
	{
	HWND hwndList = GetDlgItem(hwndDlg, IDC_LIST1);
	i = ListBox_GetCurSel(hwndList);
	ListBox_GetText(hwndList, i, str);
	_stprintf(strf, TEXT("ѡ�����б��ĵ�%d�%s"), i, str);
	MessageBox(hwndDlg, strf, TEXT("List Button"), MB_OK);
	break;
	}
	case IDC_LIST1:
		if (codeNotify == LBN_DBLCLK) {
			i = ListBox_GetCurSel(hwndCtl);
			ListBox_GetText(hwndCtl, i, str);
			_stprintf(strf, TEXT("ѡ������Ͽ�ĵ�%d�%s"), i, str);
			MessageBox(hwndCtl, strf, TEXT("ѡ������Ͽ�"), MB_OK);
		
		}
	break;

	default:
        break;
    }
}

// ��������Ϣ�Ĵ��ڹ���
INT_PTR CALLBACK DlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HWND h;
    switch (uMsg)
    {
		
    case WM_INITDIALOG:
		h = GetDlgItem(hwndDlg, IDC_LIST1);
		ListBox_AddString(h, TEXT("XIAOLI"));
		ListBox_AddString(h, TEXT("XIAOHONG"));
		ListBox_AddString(h, TEXT("XIAOLFANG"));
		ListBox_AddString(h, TEXT("XIAOJUAN"));
		ListBox_SetCurSel(h, 3);

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

// �������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //�����Ի��򴰿ڣ����ô��ڹ��̺���Ϊ DlgProc
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_WIN32PROJECT1_DIALOG), NULL, DlgProc);
    return 0;
}
