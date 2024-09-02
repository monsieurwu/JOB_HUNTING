#include "stdafx.h"
#include "Slider.h"
#include <Commctrl.h>
#include <tchar.h>

void HandleNotify(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
	int pos = 0;
	TCHAR data[256] = { 0 };

	switch (codeNotify)
	{
	case NM_RELEASEDCAPTURE:
		if (idCtl == IDC_SLIDER1) {
			pos = SendMessage(hwndCtl, TBM_GETPOS, 0, 0);
			_stprintf(data, TEXT("position: %d"), pos);
			MessageBox(hwndCtl, data, TEXT("��ʾ"), MB_OK);
		}
		break;
	default:
		break;
	}
}

// ����������Ϣ�ĺ���
void HandleCommand(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
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
INT_PTR CALLBACK DlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		HandleCommand(hwndDlg, (HWND)(lParam), (int)(LOWORD(wParam)), (UINT)HIWORD(wParam));
		return TRUE;
	case WM_NOTIFY:
		HandleNotify(hwndDlg, ((LPNMHDR)lParam)->hwndFrom, (int)LOWORD(wParam), ((LPNMHDR)lParam)->code);
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
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_SLIDER_DIALOG), NULL, DlgProc);
	return 0;
}
