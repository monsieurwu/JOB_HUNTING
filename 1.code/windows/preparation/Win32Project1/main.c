#include <windows.h>
/*���ҳɹ���һ��win32���� */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdshow)
{
	MessageBox(NULL, TEXT("��ã�����!"), TEXT("hello world!"), MB_OK);
	MessageBox(NULL, TEXT("��ã�����!"), TEXT("hello world!"), MB_OK);
	MessageBox(NULL, TEXT("��ã�����!"), TEXT("hello world!"), MB_OK);
	return 0;
}