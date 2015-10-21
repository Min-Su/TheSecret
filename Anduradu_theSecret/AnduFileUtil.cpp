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
	// 사용자가 지정한 위치로 가서 원래 있던 글자를 저장하고 껴넣을 글자를 넣는다.
	lseek(fd, pos, SEEK_SET);
	readByte = read(fd, buf, strLength);
	lseek(fd, pos, SEEK_SET);
	write(fd, strInsertWord, strLength);
	close(fd);

	// 키 파일 생성
	char* keyFileName = insertExtension(fileName, strlen(fileName));
	int keyFile = open(keyFileName, O_CREAT|O_APPEND|O_RDWR, 0644);	// 파일 암호화를 위한 키파일 생성

	if(keyFile > 0) {	
		if(keyFileName != NULL) {
			for(int i = 0; i < readByte; i++) {
				buf[i] += 30;
			}
			lseek(keyFile, 0L, SEEK_END);
			write(keyFile, buf, readByte);
			close(keyFile);
		} else {	// 키파일 생성 실패
			return false;
		}
	} else {	// 작업 실패. 원본 파일을 다시 복구하고 사용자에게 알려야 한다.
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

	// 원본 파일 : 비밀번호가 입력된 위치로 이동.
	pos = transEvenNum(pos);
	lseek(fd, pos, SEEK_SET);
	readByte = read(fd, buf, strLength);
	// 비밀번호가 맞으면 복구 실행.
	if(isSameString(strDeleteWord, buf)) {
		// 키파일에서 원본 내용 읽어오기
		originContent = createCharBuf(readByte + 1);
		originContent[strLength + 1] = '\0';
		lseek(keyFile, 0L, SEEK_SET);
		read(keyFile, originContent, readByte + 1);
		for(int i = 0; i < readByte; i++) {
			originContent[i] -= 30;
		}

		// 원본 파일에 키파일에서 읽어온 원본 내용 적기
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
		if(evenPos % 2 == 1) {	// 홀수
			evenPos++;
		}
	}

	return evenPos;
}

char* AnduFileUtil::insertExtension(char* fileName, int fileNameLength)
{
	// .andu 확장자를 붙이기 위한 메모리 할당.
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