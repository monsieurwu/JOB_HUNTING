#include "stdafx.h"
#include "calculator.h"
BOOL b;
int value1, value2;
// ����������Ϣ�ĺ���
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
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_CALCULATOR_DIALOG), NULL, DlgProc);
    return 0;
}
