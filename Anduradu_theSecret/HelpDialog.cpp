// HelpDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Anduradu_theSecret.h"
#include "HelpDialog.h"
#include "afxdialogex.h"


// HelpDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(HelpDialog, CDialogEx)

HelpDialog::HelpDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(HelpDialog::IDD, pParent)
{

}

HelpDialog::~HelpDialog()
{
}

void HelpDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HelpDialog, CDialogEx)
END_MESSAGE_MAP()


// HelpDialog �޽��� ó�����Դϴ�.
void HelpDialog::OnBnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnDestroy(); 
    OnOK();//����
}