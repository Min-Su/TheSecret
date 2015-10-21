#pragma once
class CharsetConvertor
{
public:
	CharsetConvertor(void);
	~CharsetConvertor(void);

	/* 유니코드 <-> 안시C 사이의 문자 변환 */
	char* convertCharToCString_UNICODE(CString);
	CString convertCStringToChar_UNICODE(char*);
};

