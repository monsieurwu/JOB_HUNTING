#include "stdafx.h"
#include "Text.h"
#include <tchar.h>

// ����������Ϣ�ĺ���
void HandleCommand(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
	//TCHAR buf[256] = { 0 };
	//TCHAR buf2[512] = { 0 };
    switch (idCtl)
    {
    case IDOK:
		/*
		TCHAR buf[256];
		TCHAR buf2[512];
		int cnt;
		cnt = GetDlgItemText(hwndDlg, IDC_EDIT2, buf, sizeof(buf));
		_stprintf(buf2, TEXT("Get %d word:%s"), cnt, buf);
        MessageBox(hwndDlg, buf2, TEXT("read text"), MB_OK);
		*/

		/*
		LPCTSTR s;
		s = TEXT("I'm fine");
		SetDlgItemText(hwndDlg, IDC_EDIT2, s);
		*/

		/*
		BOOL b;
		int value;
		TCHAR buf[256];

		value = GetDlgItemInt(hwndDlg, IDC_EDIT2, &b, TRUE);
		if (b) {
			_stprintf(buf, TEXT("input number:%d"), value);
			MessageBox(hwndDlg, buf, TEXT("read text"), MB_OK);
		}
		else {
			MessageBox(hwndDlg, TEXT("input is not a number"), TEXT("read text"), MB_OK);
		}
		*/

		int i;
		i = -123;
		SetDlgItemInt(hwndDlg, IDC_EDIT2, i, TRUE);
        break;
    default:
        break;
    }
}

// ��������Ϣ�Ĵ��ڹ���
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

// �������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //�����Ի��򴰿ڣ����ô��ڹ��̺���Ϊ DlgProc
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_TEXT_DIALOG), NULL, DlgProc);
    return 0;
}
