#include "stdafx.h"
#include "First_Woo_Project.h"

// ����������Ϣ�ĺ���
void HandleCommand(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
	int iLength;
	TCHAR pszBuffer[256] = { 0 };
    switch (idCtl)
    {
    case IDOK:
        MessageBox(hwndDlg, TEXT("��ã����磡"), TEXT("hello world!"), MB_OK);
        break;
	case IDC_BUTTON1:
		HWND hwndbtn1;
		hwndbtn1 = GetDlgItem(hwndDlg, IDC_BUTTON1);
		//SetWindowText(hwndbtn1, TEXT("ȡ��"));
		//MessageBox(NULL, TEXT("BUTTON��"), TEXT("BUTTON"), MB_OK);
		//SetWindowText(hwndbtn1, TEXT("CANCEL"));
		iLength = GetWindowText(hwndbtn1, pszBuffer, sizeof(pszBuffer));
		MessageBox(NULL, pszBuffer, TEXT("Get the text"), MB_OK);
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
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_FIRST_WOO_PROJECT_DIALOG), NULL, DlgProc);
    return 0;
}
