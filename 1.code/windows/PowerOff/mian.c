#include <windows.h>

/* 关机函数，不用知道每行有什么用 */
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
    int ret = MessageBox(NULL, TEXT(" 兄弟，三连 支持了吗？"), TEXT("摸着良心选"), MB_YESNO | MB_ICONQUESTION);

    if (ret == IDYES) {
        int ret2 = MessageBox(NULL, TEXT("你没骗我吧!"), TEXT("要说实话哟!"), MB_OK | MB_ICONWARNING);
        if (ret2 == IDOK)
            MessageBox(NULL, TEXT("开始格式化C盘!"), TEXT("骗人了吧!"), MB_OK);
    }
    else {
        int ret3 = MessageBox(NULL, TEXT("真的不三连下？"), TEXT("再选一次"), MB_OKCANCEL | MB_ICONQUESTION);
        if (ret3 == IDCANCEL) {
            goto REPEAT;
        }
        else {
            MessageBox(NULL, TEXT("准备关机....."), TEXT("晚安"), MB_OK);
            MessageBox(NULL, TEXT("哈哈，吓坏了吧？\n这次不开玩笑了"), TEXT("再来一次"), MB_OK);
            //powerOffWindows();
        }
    }
    return 0;
}