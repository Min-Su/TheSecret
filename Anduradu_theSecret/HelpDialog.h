#pragma once


// HelpDialog ��ȭ �����Դϴ�.

class HelpDialog : public CDialogEx
{
	DECLARE_DYNAMIC(HelpDialog)

public:
	HelpDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~HelpDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

	afx_msg void OnBnClickedButtonExit();
};
