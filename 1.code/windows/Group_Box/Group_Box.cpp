#include "stdafx.h"
#include "Group_Box.h"
#include <tchar.h>

// ����������Ϣ�ĺ���
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
        MessageBox(hwndDlg, TEXT("�ѱ���"), TEXT("hello world!"), MB_OK);
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
			_stprintf(strf, TEXT("[%s] ��ť��ѡ��"), str);
			MessageBox(hwndDlg, strf, TEXT("ȷ�������"), MB_ICONEXCLAMATION);

		}
		else
		{
			_stprintf(strf, TEXT("[%s] ��ť��ȡ��"), str);
			MessageBox(hwndDlg, strf, TEXT("ȷ�������"), MB_ICONEXCLAMATION);
		}



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
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_GROUP_BOX_DIALOG), NULL, DlgProc);
    return 0;
}
