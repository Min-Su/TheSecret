#pragma once

/****
파일 포맷 깨트리기, 복구하기 기능을 제공하는 클래스.
기타 파일 관련된 메서드를 제공. 
****/

#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

class AnduFileUtil
{
private :
	// 파일 디스크립터
	int fd;
	// 입력된 파일의 경로
	char* fileName;

	// 문자열 비교 메서드
	bool isSameString(char* str1, char* str2);
	// 문자열 담을 버퍼 생성
	char* createCharBuf(int size);
	// 한글처럼 2바이트 문자열이 들어오면 홀수 단위로 쪼갤 경우 문제가 생기므로
	// 항상 짝수단위로 위치 이동한다. 이를 위한 체크 함수. 짝수로 수를 변환.
	int transEvenNum(int pos);

	// 이 프로그램에서 사용할 키파일 확장자를 추가한다. (.andu)
	char* insertExtension(char* fileName, int fileNameLength);

public:
	AnduFileUtil(void);
	~AnduFileUtil(void);

	// true인 경우 파일 열기 성공, false이면 실패.
	bool openFile(char* fileName);

	// 파일에 특정 문자열을 껴넣어서 포맷을 깨트린다.
	// 파일에 껴넣을 문자열의 위치, 껴넣을 문자열을 받는다.
	bool encodeFile(int pos, const char* strInsertWord);

	// 파일에서 특정 위치의 특정 문자를 제거한다.
	// 파일에서 삭제할 문자열의 위치, 삭제할 문자열을 받는다.
	// 성공하면 true, 해당 위치에 지우고자 하는 문자열이 아니면 false.
	bool decodeFile(int pos, char* strDeleteWord);
};

