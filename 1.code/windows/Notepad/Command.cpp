#include "Command.h"
#include "stdafx.h"
#include "Notepad.h"
#include <stdio.h>
#include <tchar.h>

char buffer[10 * 1024 * 1024] = { 0 };//10MB
TCHAR wBuffer[10 * 1024 * 1024] = { 0 };//10MB

long get_file_size(FILE *file) {
	long size = 0;

	// 将文件指针移动到文件末尾
	if (fseek(file, 0, SEEK_END) == 0) {
		// 获取文件指针当前位置，即文件大小
		size = ftell(file);

		// 将文件指针恢复到原始位置（可选）
		fseek(file, 0, SEEK_SET);
	}
	else {
		// 处理错误，例如文件不存在或无法访问
		perror("Error getting file size");
	}

	return size;
}
//需要把这个文件内容输入到编辑框里
long LoadFileToEdit(TCHAR* FilePath, HWND hwndedit) 
{
	char file_name[MAX_PATH];
	
	//需要把TCHAR转为char
	WideCharToMultiByte(CP_UTF8, 0, FilePath, -1, file_name, sizeof(file_name), NULL, NULL);
	FILE *file = fopen(file_name, "rb");//r只能读字符串 b可以读换行符
	//打开文本文件用于读操作 文件必须存在
	if (file == NULL) {
		MessageBox(NULL, TEXT("打开文件失败"), TEXT("提示"), MB_ICONEXCLAMATION);
		fclose(file);
		return -1;
	}
	//按字节读写
	//需要获取文件的大小 在文件定位里面讲过

	long fileSize = get_file_size(file);
	if (fileSize == -1) {
		MessageBox(NULL, TEXT("获取文件大小失败"), TEXT("提示"), MB_ICONEXCLAMATION);
		fclose(file);
		return -1;
	}


	size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);//从file读取fileSize大小的内容到buffer里
	//然后再把它展示到文本编辑框里 内容注意 需要宽字符
	MultiByteToWideChar(CP_UTF8, 0, buffer, -1, wBuffer, sizeof(wBuffer));
	SetWindowText(hwndedit, wBuffer);

	fclose(file);
	return fileSize;
}


void OpenFile(struct NotePad* np)
{
	TCHAR path[MAX_PATH] = { 0 };     //定义数组用于保存文件路径
	TCHAR text[32] = { 0 };
	long fileSize;
	OPENFILENAME ofn;                 //定义OPENFILENAME结构
	ZeroMemory(&ofn, sizeof(ofn));    //将结构体中的属性清0
	ofn.lStructSize = sizeof(ofn);    //结构体大小
	ofn.hwndOwner = np->hwndDlg;          //父窗口句柄
	ofn.lpstrFile = path;             //指向保存文件路径的数组
	ofn.nMaxFile = sizeof(path);      //保存文件路径的数组大小
	ofn.lpstrFilter = TEXT("txt文本文档\0*.txt\0All\0*.*\0");//过滤后缀名
	if (GetOpenFileName(&ofn)) {      //如果选择了文件，则弹出消息框
		//MessageBox(NULL, path, TEXT("打开路径"), MB_OK);
		_tcscpy(np->FilePath, path);
		//获取文件路径后，一般会 open--->read 它
		fileSize = LoadFileToEdit(path, np->hwndEdit);
		if (fileSize != -1) {
			_stprintf(text, TEXT("文件大小：%ld 字节"), fileSize);
			SetWindowText(np->hwndStatic, text);
		}
	}
}

void SaveEditToFile(HWND hwndEdit, TCHAR* FilePath)
{
	GetWindowText(hwndEdit, wBuffer, sizeof(wBuffer));

	char file_name[MAX_PATH];

	//需要把TCHAR转为char
	int used_buffer_size = WideCharToMultiByte(CP_UTF8, 0, wBuffer, -1, buffer, sizeof(buffer), NULL, NULL);//返回值就是窄字符所占空间
	
	WideCharToMultiByte(CP_UTF8, 0, FilePath, -1, file_name, sizeof(file_name), NULL, NULL);
	FILE *file = fopen(file_name, "wb");
	//打开文本文件用于读操作 文件必须存在
	if (file == NULL) {
		MessageBox(hwndEdit, TEXT("打开文件失败"), TEXT("提示"), MB_ICONEXCLAMATION);
		fclose(file);
		return;
	}

	fwrite(buffer, sizeof(used_buffer_size), used_buffer_size - 1, file);
	fclose(file);
}

void SaveFile(struct NotePad* np)
{
	SaveEditToFile(np->hwndEdit, np->FilePath);

}

void SaveAsFile(struct NotePad* np)
{
	TCHAR path[MAX_PATH] = { 0 };     //定义数组用于保存文件路径

	OPENFILENAME ofn;                 //定义OPENFILENAME结构
	ZeroMemory(&ofn, sizeof(ofn));    //将结构体中的属性清0
	ofn.lStructSize = sizeof(ofn);    //结构体大小
	ofn.hwndOwner = np->hwndDlg;          //父窗口句柄
	ofn.lpstrFile = path;             //指向保存文件路径的数组
	ofn.nMaxFile = sizeof(path);      //保存文件路径的数组大小
	ofn.lpstrFilter = TEXT("txt文本文档\0*.txt\0All\0*.*\0");//过滤后缀名

	if (GetSaveFileName(&ofn)) {      //如果填写了文件名，则弹出消息框
		MessageBox(NULL, path, TEXT("另存为的路径"), MB_OK);
		_tcscat(path, TEXT(".txt"));
		//获取文件路径后，一般会 open--->write 它
		SaveEditToFile(np->hwndEdit, path);
	}
}