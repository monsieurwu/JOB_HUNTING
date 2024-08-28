#include <windows.h>

/* �ػ�����������֪��ÿ����ʲô�� */
void powerOffWindows()
{
    HANDLE hToken;
    TOKEN_PRIVILEGES tkp;
    OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken);
    LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
    tkp.PrivilegeCount = 1;
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    AdjustTokenPrivileges(hToken, FALSE, &tkp, NULL, NULL, NULL);
    ExitWindowsEx(EWX_POWEROFF | EWX_FORCE, SHTDN_REASON_MAJOR_APPLICATION);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
REPEAT:
    int ret = MessageBox(NULL, TEXT(" �ֵܣ����� ֧������"), TEXT("��������ѡ"), MB_YESNO | MB_ICONQUESTION);

    if (ret == IDYES) {
        int ret2 = MessageBox(NULL, TEXT("��ûƭ�Ұ�!"), TEXT("Ҫ˵ʵ��Ӵ!"), MB_OK | MB_ICONWARNING);
        if (ret2 == IDOK)
            MessageBox(NULL, TEXT("��ʼ��ʽ��C��!"), TEXT("ƭ���˰�!"), MB_OK);
    }
    else {
        int ret3 = MessageBox(NULL, TEXT("��Ĳ������£�"), TEXT("��ѡһ��"), MB_OKCANCEL | MB_ICONQUESTION);
        if (ret3 == IDCANCEL) {
            goto REPEAT;
        }
        else {
            MessageBox(NULL, TEXT("׼���ػ�....."), TEXT("��"), MB_OK);
            MessageBox(NULL, TEXT("�������Ż��˰ɣ�\n��β�����Ц��"), TEXT("����һ��"), MB_OK);
            //powerOffWindows();
        }
    }
    return 0;
}