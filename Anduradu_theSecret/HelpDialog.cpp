// HelpDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Anduradu_theSecret.h"
#include "HelpDialog.h"
#include "afxdialogex.h"


// HelpDialog 대화 상자입니다.

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


// HelpDialog 메시지 처리기입니다.
void HelpDialog::OnBnClickedButtonExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnDestroy(); 
    OnOK();//종료
}