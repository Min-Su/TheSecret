
// Anduradu_theSecretDlg.h : 헤더 파일
//

#pragma once

#include "AnduFileUtil.h"
#include "CharsetConvertor.h"


// CAnduradu_theSecretDlg 대화 상자
class CAnduradu_theSecretDlg : public CDialogEx
{
// 생성입니다.
public:
	CAnduradu_theSecretDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ANDURADU_THESECRET_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
		HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	//****** 사용자 정의 ******//
private :
	AnduFileUtil myFileUtil;
	CharsetConvertor charConvertor;

public:
	// 멤버 변수
	CString m_Directory;
	CBitmap m_background;

	// 사용자 정의 메서드
	bool PasswordCheck();
	void passCheckMsg(bool);

	char* convertCharTo(CString str);
	CString convertCStringTo(char* str);

	// 이벤트
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButtonFilesearch();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnStatic();
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnBnClickedButtonPwinput();
	afx_msg void OnBnClickedButtonPwdelete();
};
