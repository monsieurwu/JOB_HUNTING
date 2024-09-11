#include "stdafx.h"
#include "MusicPlayer.h"
#pragma comment(lib, "winmm.lib")
#include <tchar.h>
// ����������Ϣ�ĺ���
void HandleCommand(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
	TCHAR buf[256] = { 0 };
	TCHAR cmd[256] = { 0 };
	int i = 0;

    switch (idCtl)
    {
    case IDBTN_OPEN:
		mciSendString(TEXT("open D:\\01_�������뤫��.mp3 alias song"), NULL, 0, NULL);

		//MessageBox(hwndDlg, TEXT("��ã����磡"), TEXT("hello world!"), MB_OK);
        break;
	case IDBTN_PLAY:
		mciSendString(TEXT("play song"), NULL, 0, NULL);

		//MessageBox(hwndDlg, TEXT("��ã����磡"), TEXT("hello world!"), MB_OK);
		break;
	case IDBTN_STOP:
		mciSendString(TEXT("stop song"), NULL, 0, NULL);

		//MessageBox(hwndDlg, TEXT("��ã����磡"), TEXT("hello world!"), MB_OK);
		break;
	case IDBTN_STATUS:
		mciSendString(TEXT("status song mode"), buf, sizeof(buf), NULL);

		MessageBox(hwndDlg, buf, TEXT("����״̬"), MB_OK);
		break;
	case IDBTN_PAUSE:
		mciSendString(TEXT("pause song"), NULL, 0, NULL);

		//MessageBox(hwndDlg, TEXT("��ã����磡"), TEXT("hello world!"), MB_OK);
		break;
	case IDBTN_RESUME:
		mciSendString(TEXT("resume song"), NULL, 0, NULL);

		//MessageBox(hwndDlg, TEXT("��ã����磡"), TEXT("hello world!"), MB_OK);
		break;
	case IDBTN_GET_POS:
		mciSendString(TEXT("status song position"), buf, sizeof(buf), NULL);

		MessageBox(hwndDlg, buf, TEXT("��ǰ����λ��"), MB_OK);
		break;
	case IDBTN_BACK10:
		mciSendString(TEXT("status song position"), buf, sizeof(buf), NULL);
		i = _ttoi(buf) - 10000;
		_stprintf(cmd, TEXT("seek song to %i"), i);
		mciSendString(cmd, NULL, 0, NULL);
		mciSendString(TEXT("play song"), NULL, 0, NULL);
		break;
	case IDBTN_FORWARD10:
		mciSendString(TEXT("status song position"), buf, sizeof(buf), NULL);
		i = _ttoi(buf) + 10000;
		_stprintf(cmd, TEXT("seek song to %i"), i);
		mciSendString(cmd, NULL, 0, NULL);
		mciSendString(TEXT("play song"), NULL, 0, NULL);
		break;
	case IDBTN_TOTAL_TIME:
		mciSendString(TEXT("status song length"), buf, sizeof(buf), NULL);

		MessageBox(hwndDlg, buf, TEXT("��ʱ������λ���룩"), MB_OK);
		break;
	case IDBTN_VOL_LOW:
		mciSendString(TEXT("status song volume"), buf, sizeof(buf), NULL);
		i = _ttoi(buf) - 50;
		_stprintf(cmd, TEXT("setaudio song volume to %i"), i);
		mciSendString(cmd, NULL, 0, NULL);
		break;
	case IDBTN_VOL_HIGH:
		mciSendString(TEXT("status song volume"), buf, sizeof(buf), NULL);
		i = _ttoi(buf) + 50;
		_stprintf(cmd, TEXT("setaudio song volume to %i"), i);
		mciSendString(cmd, NULL, 0, NULL);
		break;
	case IDBTN_GET_VOL:
		mciSendString(TEXT("status song volume"), buf, sizeof(buf), NULL);

		MessageBox(hwndDlg, buf, TEXT("��ǰ������С��1-1000��"), MB_OK);
		break;
	case IDBTN_CLOSE:
		mciSendString(TEXT("close song"), NULL, 0, NULL);

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
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_MUSICPLAYER_DIALOG), NULL, DlgProc);
    return 0;
}
