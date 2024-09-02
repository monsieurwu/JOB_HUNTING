#include "stdafx.h"
#include "NewDlg.h"

void HandleCommandDlg1(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
	switch (idCtl)
	{
	case IDOK:
		MessageBox(hwndDlg, TEXT("��ã����磡"), TEXT("hello world!"), MB_OK);
		break;
	default:
		break;
	}
}

// ��������Ϣ�Ĵ��ڹ���
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
// ����������Ϣ�ĺ���
void HandleCommand(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
    switch (idCtl)
    {
    case IDOK:
		DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG1), hwndDlg, DlgProcDlg1);
        //MessageBox(hwndDlg, TEXT("��ã����磡"), TEXT("hello world!"), MB_OK);
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
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_NEWDLG_DIALOG), NULL, DlgProc);
    return 0;
}
