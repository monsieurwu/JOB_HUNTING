#include "stdafx.h"
#include "Timer.h"

#define TIMER_ID 1

VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR nTimerid, DWORD dwTime)
{
	// ������ִ�ж�ʱ������ʱҪִ�еĲ���
	MessageBox(NULL, TEXT("��ã����磡"), TEXT("��ʱ��"), MB_OK);
}

// ����������Ϣ�ĺ���
void HandleCommand(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
    switch (idCtl)
    {
    case IDOK:
        //MessageBox(hwndDlg, TEXT("��ã����磡"), TEXT("hello world!"), MB_OK);
		// ������ʱ����ָ����ʶ��Ϊ TIMER_ID��ÿ�� 1000���룬����һ�� TimerProc ����
		SetTimer(hwndDlg, TIMER_ID, 1000, TimerProc);
		break;
	case IDC_BUTTON1:
		// ���ٱ�ʶ��Ϊ TIMER_ID �Ķ�ʱ��
		KillTimer(hwndDlg, TIMER_ID);
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
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_TIMER_DIALOG), NULL, DlgProc);
    return 0;
}
