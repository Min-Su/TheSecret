#pragma once
class CharsetConvertor
{
public:
	CharsetConvertor(void);
	~CharsetConvertor(void);

	/* �����ڵ� <-> �Ƚ�C ������ ���� ��ȯ */
	char* convertCharToCString_UNICODE(CString);
	CString convertCStringToChar_UNICODE(char*);
};

