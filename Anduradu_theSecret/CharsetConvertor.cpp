#include "StdAfx.h"
#include "CharsetConvertor.h"


CharsetConvertor::CharsetConvertor(void)
{
}


CharsetConvertor::~CharsetConvertor(void)
{
}


char* CharsetConvertor::convertCharToCString_UNICODE(CString path) {
	/* [ wchar_t ]
	2����Ʈ �̻��� ���ڸ� ���ڸ� �����ϱ� ���� wchar_t ������ ����Ѵ�.
	���� char * �� �����Ҽ��� �ִ�.
	wchar_t �� typedef unsigned long (������) Ȥ�� short(������) ���̴�.
	������������ 4����Ʈ�̰� �����쿡���� 2����Ʈ�̴�.
	*/
	wchar_t* wchar_str;     //ù��° �ܰ�(CString to wchar_t*)�� ���� ����
	char*    char_str;      //char* ���� ����
	int      char_str_len;  //char* �� ������ ���̸� ���� ����
 
	//1. CString to wchar_t* conversion
	wchar_str = path.GetBuffer(path.GetLength());
 
	//2. wchar_t* to char* conversion
	//char* ���� ���ѱ��̸� ����
	char_str_len = WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, NULL, 0, NULL, NULL);
	char_str = new char[char_str_len];  //�޸� �Ҵ�
	//wchar_t* to char* conversion
	WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, char_str, char_str_len, 0,0);  
 
	//Done.

	return char_str;
}

CString CharsetConvertor::convertCStringToChar_UNICODE(char* str) {
	int char_str_len;
	CString tmp;

	/* BSTR�� ����. ���� ���� ������.
	http://wwww7.com/bbs/skin/ggambo6210_board/print.php?id=Study&no=93
	*/
	BSTR buf;

	/* 1. char* to wchar_t* conversion */
	char_str_len = MultiByteToWideChar(CP_ACP, 0, str, strlen(str), NULL, NULL);
	buf = SysAllocStringLen(NULL, char_str_len);
	MultiByteToWideChar(CP_ACP, 0, str, strlen(str), buf, char_str_len);

	/* 2. wchar_t* to CString conversion */
	tmp.Format(_T("%s"), buf);

	return tmp;
}