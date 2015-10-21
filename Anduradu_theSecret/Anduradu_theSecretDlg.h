
// Anduradu_theSecretDlg.h : ��� ����
//

#pragma once

#include "AnduFileUtil.h"
#include "CharsetConvertor.h"


// CAnduradu_theSecretDlg ��ȭ ����
class CAnduradu_theSecretDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CAnduradu_theSecretDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ANDURADU_THESECRET_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
		HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	//****** ����� ���� ******//
private :
	AnduFileUtil myFileUtil;
	CharsetConvertor charConvertor;

public:
	// ��� ����
	CString m_Directory;
	CBitmap m_background;

	// ����� ���� �޼���
	bool PasswordCheck();
	void passCheckMsg(bool);

	char* convertCharTo(CString str);
	CString convertCStringTo(char* str);

	// �̺�Ʈ
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
