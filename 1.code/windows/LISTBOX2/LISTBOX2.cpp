#include "stdafx.h"
#include "LISTBOX2.h"
#include<tchar.h>

// ����������Ϣ�ĺ���
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
		_stprintf(str2, TEXT("ѡ�����б��ĵ�%d� %s"), i, str);
		MessageBox(hwndDlg, str2, TEXT("LIST ��ť"), MB_OK);
		break;
	}
	case IDC_BUTTON2:
	{
		HWND hwndBox = GetDlgItem(hwndDlg, IDC_COMBO1);
		i = ComboBox_GetCurSel(hwndBox);
		ComboBox_GetLBText(hwndBox, i, str3);
		_stprintf(str4, TEXT("ѡ�����б��ĵ�%d� %s"), i, str3);
		MessageBox(hwndDlg, str4, TEXT("BOX ��ť"), MB_OK);
		break;
	}
	case IDC_LIST1:
		if (codeNotify == LBN_DBLCLK)
		{
			//�ؼ����б�� ��˫����Ҳ���б��ʱ �Ͳ���Ҫ��ȡ�б��ľ���� ���� hwndCtl ����ֱ��ʹ�ô����
			i = ListBox_GetCurSel(hwndCtl);
			ListBox_GetText(hwndCtl, i, str);
			_stprintf(str2, TEXT("ѡ�����б��ĵ�%d� %s"), i, str);
			MessageBox(hwndDlg, str2, TEXT("˫����Ͽ�"), MB_OK);
			break;
		}
		
	case IDC_COMBO1:
		if (codeNotify == CBN_SELENDOK) {
			i = ComboBox_GetCurSel(hwndCtl);
			ComboBox_GetLBText(hwndCtl, i, str3);
			_stprintf(str4, TEXT("ѡ�����б��ĵ�%d� %s"), i, str3);
			MessageBox(hwndDlg, str4, TEXT("BOX ��ť"), MB_OK);
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
		ListBox_AddString(h, TEXT("С��"));
		ListBox_AddString(h, TEXT("С��"));
		ListBox_AddString(h, TEXT("С��"));
		ListBox_AddString(h, TEXT("С��"));
		ListBox_SetCurSel(h, 0);
		h = GetDlgItem(hwndDlg, IDC_COMBO1);
		ComboBox_AddString(h, TEXT("����"));
		ComboBox_AddString(h, TEXT("����"));
		ComboBox_AddString(h, TEXT("Ӣ��"));
		ComboBox_AddString(h, TEXT("����"));
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

// �������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //�����Ի��򴰿ڣ����ô��ڹ��̺���Ϊ DlgProc
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_LISTBOX2_DIALOG), NULL, DlgProc);
    return 0;
}
