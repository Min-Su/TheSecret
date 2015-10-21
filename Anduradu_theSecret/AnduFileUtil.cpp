#include "AnduFileUtil.h"


AnduFileUtil::AnduFileUtil(void)
{
}


AnduFileUtil::~AnduFileUtil(void)
{
}


bool AnduFileUtil::openFile(char* fileName)
{
	this->fileName = fileName;
	fd = open(fileName, O_RDWR | O_BINARY);

	if(fd == -1) {
		return false;
	}
	return true;
}

bool AnduFileUtil::encodeFile(int pos, const char* strInsertWord)
{
	int readByte = 0;
	int strLength = strlen(strInsertWord);
	char* buf = createCharBuf(strLength);

	pos = transEvenNum(pos);
	// ����ڰ� ������ ��ġ�� ���� ���� �ִ� ���ڸ� �����ϰ� ������ ���ڸ� �ִ´�.
	lseek(fd, pos, SEEK_SET);
	readByte = read(fd, buf, strLength);
	lseek(fd, pos, SEEK_SET);
	write(fd, strInsertWord, strLength);
	close(fd);

	// Ű ���� ����
	char* keyFileName = insertExtension(fileName, strlen(fileName));
	int keyFile = open(keyFileName, O_CREAT|O_APPEND|O_RDWR, 0644);	// ���� ��ȣȭ�� ���� Ű���� ����

	if(keyFile > 0) {	
		if(keyFileName != NULL) {
			for(int i = 0; i < readByte; i++) {
				buf[i] += 30;
			}
			lseek(keyFile, 0L, SEEK_END);
			write(keyFile, buf, readByte);
			close(keyFile);
		} else {	// Ű���� ���� ����
			return false;
		}
	} else {	// �۾� ����. ���� ������ �ٽ� �����ϰ� ����ڿ��� �˷��� �Ѵ�.
		lseek(fd, pos, SEEK_SET);
		write(fd, buf, readByte);
		close(fd);
		return false;
	}

	return true;
}

bool AnduFileUtil::decodeFile(int pos, char* strDeleteWord)
{
	char* keyFileName = insertExtension(this->fileName, strlen(this->fileName));
	int keyFile = open(keyFileName, O_RDWR);
	char* originContent;

	int readByte = 0;
	int strLength = strlen(strDeleteWord);
	char* buf = createCharBuf(strLength + 1);
	buf[strLength + 1] = '\0';

	// ���� ���� : ��й�ȣ�� �Էµ� ��ġ�� �̵�.
	pos = transEvenNum(pos);
	lseek(fd, pos, SEEK_SET);
	readByte = read(fd, buf, strLength);
	// ��й�ȣ�� ������ ���� ����.
	if(isSameString(strDeleteWord, buf)) {
		// Ű���Ͽ��� ���� ���� �о����
		originContent = createCharBuf(readByte + 1);
		originContent[strLength + 1] = '\0';
		lseek(keyFile, 0L, SEEK_SET);
		read(keyFile, originContent, readByte + 1);
		for(int i = 0; i < readByte; i++) {
			originContent[i] -= 30;
		}

		// ���� ���Ͽ� Ű���Ͽ��� �о�� ���� ���� ����
		lseek(fd, pos, SEEK_SET);
		write(fd, originContent, readByte);

		close(keyFile);
		unlink(keyFileName);
		close(fd);
		return true;
	} else {
		return false;
	}
}

bool AnduFileUtil::isSameString(char* str1, char* str2)
{
	int strLength1 = strlen(str1);
	int strLength2 = strlen(str2);

	if(strLength1 == strLength2) {
		for(int i = 0; i < strLength1; i++) {
			if(str1[i] != str2[i]) {
				return false;
			}
		}
		return true;
	}
}

char* AnduFileUtil::createCharBuf(int size)
{
	char* buf = (char*) malloc(sizeof(size) * sizeof(char));

	for(int i = 0; i < size; i++) {
		buf[i] = '\0';
	}

	return buf;
}

int AnduFileUtil::transEvenNum(int pos)
{
	int evenPos = pos;
	if(pos > 0) {
		if(evenPos % 2 == 1) {	// Ȧ��
			evenPos++;
		}
	}

	return evenPos;
}

char* AnduFileUtil::insertExtension(char* fileName, int fileNameLength)
{
	// .andu Ȯ���ڸ� ���̱� ���� �޸� �Ҵ�.
	char* convertedFileName = (char*) malloc(sizeof(char) * (fileNameLength + 6));
	strcpy(convertedFileName, fileName);
	convertedFileName[fileNameLength] = '.';
	convertedFileName[fileNameLength + 1] = 'a';
	convertedFileName[fileNameLength + 2] = 'n';
	convertedFileName[fileNameLength + 3] = 'd';
	convertedFileName[fileNameLength + 4] = 'u';
	convertedFileName[fileNameLength + 5] = '\0';
	return convertedFileName;
}