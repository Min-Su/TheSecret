#pragma once

/****
���� ���� ��Ʈ����, �����ϱ� ����� �����ϴ� Ŭ����.
��Ÿ ���� ���õ� �޼��带 ����. 
****/

#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

class AnduFileUtil
{
private :
	// ���� ��ũ����
	int fd;
	// �Էµ� ������ ���
	char* fileName;

	// ���ڿ� �� �޼���
	bool isSameString(char* str1, char* str2);
	// ���ڿ� ���� ���� ����
	char* createCharBuf(int size);
	// �ѱ�ó�� 2����Ʈ ���ڿ��� ������ Ȧ�� ������ �ɰ� ��� ������ ����Ƿ�
	// �׻� ¦�������� ��ġ �̵��Ѵ�. �̸� ���� üũ �Լ�. ¦���� ���� ��ȯ.
	int transEvenNum(int pos);

	// �� ���α׷����� ����� Ű���� Ȯ���ڸ� �߰��Ѵ�. (.andu)
	char* insertExtension(char* fileName, int fileNameLength);

public:
	AnduFileUtil(void);
	~AnduFileUtil(void);

	// true�� ��� ���� ���� ����, false�̸� ����.
	bool openFile(char* fileName);

	// ���Ͽ� Ư�� ���ڿ��� ���־ ������ ��Ʈ����.
	// ���Ͽ� ������ ���ڿ��� ��ġ, ������ ���ڿ��� �޴´�.
	bool encodeFile(int pos, const char* strInsertWord);

	// ���Ͽ��� Ư�� ��ġ�� Ư�� ���ڸ� �����Ѵ�.
	// ���Ͽ��� ������ ���ڿ��� ��ġ, ������ ���ڿ��� �޴´�.
	// �����ϸ� true, �ش� ��ġ�� ������� �ϴ� ���ڿ��� �ƴϸ� false.
	bool decodeFile(int pos, char* strDeleteWord);
};

