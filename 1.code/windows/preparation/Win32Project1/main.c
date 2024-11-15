#include <windows.h>
/*科岩成果第一个win32程序 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdshow)
{
	MessageBox(NULL, TEXT("你好，世界!"), TEXT("hello world!"), MB_OK);
	MessageBox(NULL, TEXT("你好，世界!"), TEXT("hello world!"), MB_OK);
	MessageBox(NULL, TEXT("你好，世界!"), TEXT("hello world!"), MB_OK);
	return 0;
}