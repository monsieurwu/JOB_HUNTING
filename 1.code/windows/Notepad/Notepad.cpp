#include "stdafx.h"
#include "Notepad.h"
#include "Command.h"

void ShowVersion(HWND hwndDlg) {
	MessageBox(hwndDlg, TEXT("\
��Ʒ������ʷ\n \
<---------------------------------->\n \
V1.0\n \
�׸��汾��ʵ�����ı��ļ��Ĵ򿪡����桢���Ϊ����\n \
		"), TEXT("�汾��V1.0"), MB_OK);
}

struct NotePad npad;
// ����������Ϣ�ĺ���
void HandleCommand(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
    switch (idCtl)
    {
    case ID_MENU_OPEN:
        //MessageBox(hwndDlg, TEXT("��ã����磡"), TEXT("hello world!"), MB_OK);
		OpenFile(&npad);//��ָ�벻���ṹ��ĺô��ǽ�ʡ�ռ�
		break;
	case ID_MENU_SAVE:
		//MessageBox(hwndDlg, TEXT("��ã����磡"), TEXT("hello world!"), MB_OK);
		SaveFile(&npad);//��ָ�벻���ṹ��ĺô��ǽ�ʡ�ռ�
		break;
	case ID_MENU_SAVE_AS:
		//MessageBox(hwndDlg, TEXT("��ã����磡"), TEXT("hello world!"), MB_OK);
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

// ��������Ϣ�Ĵ��ڹ���
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

// �������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //�����Ի��򴰿ڣ����ô��ڹ��̺���Ϊ DlgProc
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_NOTEPAD_DIALOG), NULL, DlgProc);
    return 0;
}
