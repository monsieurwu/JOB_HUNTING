#include "stdafx.h"
#include "Save_Open.h"
#include <shlobj.h>
void GetDirPath(HWND hwndDlg)
{
	TCHAR path[MAX_PATH] = { 0 };       //�����������ڱ����ļ���·��

	BROWSEINFO browseInfo = { 0 };      //����BROWSEINFO �ṹ
	browseInfo.hwndOwner = hwndDlg;     //�����ھ��

										//���ļ���ѡ��Ի��򣬷���һ��������ϵͳ�����ڴ��LPITEMIDLIST���͵ı���
	LPITEMIDLIST pidl = SHBrowseForFolder(&browseInfo);
	if (pidl != NULL)
	{
		SHGetPathFromIDList(pidl, path);                //���ļ��е�ID�б�·��ת��Ϊ�ַ���·��
		CoTaskMemFree(pidl);                            //�ͷ�ϵͳ������ڴ�
		MessageBox(NULL, path, TEXT("ѡ����ļ���·��"), MB_OK);
	}
}

void OpenFile(HWND hwndDlg)
{
	TCHAR path[MAX_PATH] = { 0 };     //�����������ڱ����ļ�·��

	OPENFILENAME ofn;                 //����OPENFILENAME�ṹ
	ZeroMemory(&ofn, sizeof(ofn));    //���ṹ���е�������0
	ofn.lStructSize = sizeof(ofn);    //�ṹ���С
	ofn.hwndOwner = hwndDlg;          //�����ھ��
	ofn.lpstrFile = path;             //ָ�򱣴��ļ�·��������
	ofn.nMaxFile = sizeof(path);      //�����ļ�·���������С
	ofn.lpstrFilter = TEXT("ͷ�ļ�.h\0*.h\0All\0*.*\0");//���˺�׺��
	if (GetOpenFileName(&ofn)) {      //���ѡ�����ļ����򵯳���Ϣ��
		MessageBox(NULL, path, TEXT("��·��"), MB_OK);
		//��ȡ�ļ�·����һ��� open--->read ��
	}
}

void SaveAsFile(HWND hwndDlg)
{
	TCHAR path[MAX_PATH] = { 0 };     //�����������ڱ����ļ�·��

	OPENFILENAME ofn;                 //����OPENFILENAME�ṹ
	ZeroMemory(&ofn, sizeof(ofn));    //���ṹ���е�������0
	ofn.lStructSize = sizeof(ofn);    //�ṹ���С
	ofn.hwndOwner = hwndDlg;          //�����ھ��
	ofn.lpstrFile = path;             //ָ�򱣴��ļ�·��������
	ofn.nMaxFile = sizeof(path);      //�����ļ�·���������С
	ofn.lpstrFilter = TEXT("ͷ�ļ�.h\0*.h\0All\0*.*\0");//���˺�׺��

	if (GetSaveFileName(&ofn)) {      //�����д���ļ������򵯳���Ϣ��
		MessageBox(NULL, path, TEXT("���Ϊ��·��"), MB_OK);
		//��ȡ�ļ�·����һ��� open--->write ��
	}
}
// ����������Ϣ�ĺ���
void HandleCommand(HWND hwndDlg, HWND hwndCtl, int idCtl, UINT codeNotify)
{
    switch (idCtl)
    {
    case IDOK:
        //MessageBox(hwndDlg, TEXT("��ã����磡"), TEXT("hello world!"), MB_OK);
		GetDirPath(hwndDlg);
		break;
	case IDC_BUTTON1:
		OpenFile(hwndDlg);
		break;
	case IDC_BUTTON2:
		SaveAsFile(hwndDlg);
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
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_SAVE_OPEN_DIALOG), NULL, DlgProc);
    return 0;
}
