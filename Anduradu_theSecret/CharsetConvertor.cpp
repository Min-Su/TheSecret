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
	2바이트 이상의 문자를 문자를 저장하기 위해 wchar_t 변수를 사용한다.
	물론 char * 로 저장할수도 있다.
	wchar_t 는 typedef unsigned long (리눅스) 혹은 short(윈도우) 형이다.
	리눅스에서는 4바이트이고 윈도우에서는 2바이트이다.
	*/
	wchar_t* wchar_str;     //첫번째 단계(CString to wchar_t*)를 위한 변수
	char*    char_str;      //char* 형의 변수
	int      char_str_len;  //char* 형 변수의 길이를 위한 변수
 
	//1. CString to wchar_t* conversion
	wchar_str = path.GetBuffer(path.GetLength());
 
	//2. wchar_t* to char* conversion
	//char* 형에 대한길이를 구함
	char_str_len = WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, NULL, 0, NULL, NULL);
	char_str = new char[char_str_len];  //메모리 할당
	//wchar_t* to char* conversion
	WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, char_str, char_str_len, 0,0);  
 
	//Done.

	return char_str;
}

CString CharsetConvertor::convertCStringToChar_UNICODE(char* str) {
	int char_str_len;
	CString tmp;

	/* BSTR에 대해. 아주 좋은 내용임.
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