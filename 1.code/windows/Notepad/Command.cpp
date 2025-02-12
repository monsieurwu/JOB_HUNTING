#include "Command.h"
#include "stdafx.h"
#include "Notepad.h"
#include <stdio.h>
#include <tchar.h>

char buffer[10 * 1024 * 1024] = { 0 };//10MB
TCHAR wBuffer[10 * 1024 * 1024] = { 0 };//10MB

long get_file_size(FILE *file) {
	long size = 0;

	// ���ļ�ָ���ƶ����ļ�ĩβ
	if (fseek(file, 0, SEEK_END) == 0) {
		// ��ȡ�ļ�ָ�뵱ǰλ�ã����ļ���С
		size = ftell(file);

		// ���ļ�ָ��ָ���ԭʼλ�ã���ѡ��
		fseek(file, 0, SEEK_SET);
	}
	else {
		// ������������ļ������ڻ��޷�����
		perror("Error getting file size");
	}

	return size;
}
//��Ҫ������ļ��������뵽�༭����
long LoadFileToEdit(TCHAR* FilePath, HWND hwndedit) 
{
	char file_name[MAX_PATH];
	
	//��Ҫ��TCHARתΪchar
	WideCharToMultiByte(CP_UTF8, 0, FilePath, -1, file_name, sizeof(file_name), NULL, NULL);
	FILE *file = fopen(file_name, "rb");//rֻ�ܶ��ַ��� b���Զ����з�
	//���ı��ļ����ڶ����� �ļ��������
	if (file == NULL) {
		MessageBox(NULL, TEXT("���ļ�ʧ��"), TEXT("��ʾ"), MB_ICONEXCLAMATION);
		fclose(file);
		return -1;
	}
	//���ֽڶ�д
	//��Ҫ��ȡ�ļ��Ĵ�С ���ļ���λ���潲��

	long fileSize = get_file_size(file);
	if (fileSize == -1) {
		MessageBox(NULL, TEXT("��ȡ�ļ���Сʧ��"), TEXT("��ʾ"), MB_ICONEXCLAMATION);
		fclose(file);
		return -1;
	}


	size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);//��file��ȡfileSize��С�����ݵ�buffer��
	//Ȼ���ٰ���չʾ���ı��༭���� ����ע�� ��Ҫ���ַ�
	MultiByteToWideChar(CP_UTF8, 0, buffer, -1, wBuffer, sizeof(wBuffer));
	SetWindowText(hwndedit, wBuffer);

	fclose(file);
	return fileSize;
}


void OpenFile(struct NotePad* np)
{
	TCHAR path[MAX_PATH] = { 0 };     //�����������ڱ����ļ�·��
	TCHAR text[32] = { 0 };
	long fileSize;
	OPENFILENAME ofn;                 //����OPENFILENAME�ṹ
	ZeroMemory(&ofn, sizeof(ofn));    //���ṹ���е�������0
	ofn.lStructSize = sizeof(ofn);    //�ṹ���С
	ofn.hwndOwner = np->hwndDlg;          //�����ھ��
	ofn.lpstrFile = path;             //ָ�򱣴��ļ�·��������
	ofn.nMaxFile = sizeof(path);      //�����ļ�·���������С
	ofn.lpstrFilter = TEXT("txt�ı��ĵ�\0*.txt\0All\0*.*\0");//���˺�׺��
	if (GetOpenFileName(&ofn)) {      //���ѡ�����ļ����򵯳���Ϣ��
		//MessageBox(NULL, path, TEXT("��·��"), MB_OK);
		_tcscpy(np->FilePath, path);
		//��ȡ�ļ�·����һ��� open--->read ��
		fileSize = LoadFileToEdit(path, np->hwndEdit);
		if (fileSize != -1) {
			_stprintf(text, TEXT("�ļ���С��%ld �ֽ�"), fileSize);
			SetWindowText(np->hwndStatic, text);
		}
	}
}

void SaveEditToFile(HWND hwndEdit, TCHAR* FilePath)
{
	GetWindowText(hwndEdit, wBuffer, sizeof(wBuffer));

	char file_name[MAX_PATH];

	//��Ҫ��TCHARתΪchar
	int used_buffer_size = WideCharToMultiByte(CP_UTF8, 0, wBuffer, -1, buffer, sizeof(buffer), NULL, NULL);//����ֵ����խ�ַ���ռ�ռ�
	
	WideCharToMultiByte(CP_UTF8, 0, FilePath, -1, file_name, sizeof(file_name), NULL, NULL);
	FILE *file = fopen(file_name, "wb");
	//���ı��ļ����ڶ����� �ļ��������
	if (file == NULL) {
		MessageBox(hwndEdit, TEXT("���ļ�ʧ��"), TEXT("��ʾ"), MB_ICONEXCLAMATION);
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
	TCHAR path[MAX_PATH] = { 0 };     //�����������ڱ����ļ�·��

	OPENFILENAME ofn;                 //����OPENFILENAME�ṹ
	ZeroMemory(&ofn, sizeof(ofn));    //���ṹ���е�������0
	ofn.lStructSize = sizeof(ofn);    //�ṹ���С
	ofn.hwndOwner = np->hwndDlg;          //�����ھ��
	ofn.lpstrFile = path;             //ָ�򱣴��ļ�·��������
	ofn.nMaxFile = sizeof(path);      //�����ļ�·���������С
	ofn.lpstrFilter = TEXT("txt�ı��ĵ�\0*.txt\0All\0*.*\0");//���˺�׺��

	if (GetSaveFileName(&ofn)) {      //�����д���ļ������򵯳���Ϣ��
		MessageBox(NULL, path, TEXT("���Ϊ��·��"), MB_OK);
		_tcscat(path, TEXT(".txt"));
		//��ȡ�ļ�·����һ��� open--->write ��
		SaveEditToFile(np->hwndEdit, path);
	}
}