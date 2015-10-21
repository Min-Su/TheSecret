
// Anduradu_theSecretDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Anduradu_theSecret.h"
#include "Anduradu_theSecretDlg.h"
#include "afxdialogex.h"
#include "HelpDialog.h"
#include "CharsetConvertor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAnduradu_theSecretDlg ��ȭ ����




CAnduradu_theSecretDlg::CAnduradu_theSecretDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAnduradu_theSecretDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnduradu_theSecretDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DIRECTORY, m_Directory);
}

BEGIN_MESSAGE_MAP(CAnduradu_theSecretDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_FILESEARCH, &CAnduradu_theSecretDlg::OnBnClickedButtonFilesearch)
	ON_BN_CLICKED(IDC_BUTTON_HELP, &CAnduradu_theSecretDlg::OnBnClickedButton4)
	ON_COMMAND(IDC_STATIC, &CAnduradu_theSecretDlg::OnStatic)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CAnduradu_theSecretDlg::OnBnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_PWINPUT, &CAnduradu_theSecretDlg::OnBnClickedButtonPwinput)
	ON_BN_CLICKED(IDC_BUTTON_PWDELETE, &CAnduradu_theSecretDlg::OnBnClickedButtonPwdelete)
END_MESSAGE_MAP()


// CAnduradu_theSecretDlg �޽��� ó����

BOOL CAnduradu_theSecretDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL) {
		BOOL bNameValid;
		CString strAboutMenu;
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CAnduradu_theSecretDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX) {
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	} else {
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CAnduradu_theSecretDlg::OnPaint()
{
	if (IsIconic()) {
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	} else {
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CAnduradu_theSecretDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CAnduradu_theSecretDlg::OnBnClickedButtonFilesearch()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CFileDialog fileDlg(TRUE, _T("*.*"), _T("*.*"), OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("*.*"), this);  //��� ���� ����
	if(fileDlg.DoModal() == IDOK) {
		m_Directory = fileDlg.GetPathName();
		UpdateData(FALSE);
	}
	//���丮 �˻� â�� �� ��θ� �Է¹ް� ��θ� �ؽ�Ʈ�ڽ��� �ִ´�.
}



void CAnduradu_theSecretDlg::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	HelpDialog messageDlg;  //MessageDlg ����
	messageDlg.DoModal();  //Message_Dlg �� ����
	//����
}


void CAnduradu_theSecretDlg::OnStatic()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CFont fnt;
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 18;
	lf.lfWeight = FW_BOLD;
	::lstrcpy(lf.lfFaceName, (LPCWSTR)"Tahoma");
	fnt.CreateFontIndirect(&lf);
	GetDlgItem(IDC_STATIC)->SetFont(&fnt);
	fnt.Detach();
	//���̺� ��Ʈ ����?
}

/****
	���� ���̾�α� â �ݱ�.
****/
void CAnduradu_theSecretDlg::OnBnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnDestroy(); //���̾�α׸� �ı��ϰ�
	OnOK(); //����
	//�����ư ���
}

//��ȣ �Է�
void CAnduradu_theSecretDlg::OnBnClickedButtonPwinput()
{
	bool bOkay = PasswordCheck();
	passCheckMsg(bOkay);

	if(bOkay) {
		// ��ȣȭ ����
		CString strPass;
		// �Ʒ� ���� ����� �̹� �޽��� �ڽ��� ���ֱ� ������ ������ó���� ���� ���� �ʾƵ� �ȴ�.
		// ��й�ȣ �Է��ϰ� �޽��� �ڽ��� ���ִ� ���߿� ��й�ȣ�� ����� ���, ������ �о�� ��й�ȣ��
		// ����ϰ� �ȴ�. ���߿� �� �κ��� �޽��� �ڽ��� ������ ���� �Ǵ� ��� ����ؾ� �Ѵ�.
		GetDlgItemText(IDC_EDIT_PWCONFIRM, strPass);

		char* path = convertCharTo(m_Directory);
		char* pass = convertCharTo(strPass);
		if(myFileUtil.openFile(path)) {
			if(myFileUtil.encodeFile(0, pass)) {
				AfxMessageBox(L"������ ��ȣȭ �Ͽ����ϴ�.");
			} else {
				AfxMessageBox(L"���� ��ȣȭ�� �����Ͽ����ϴ�.");
			}
		} else {
			AfxMessageBox(L"������ �� �� �����ϴ�.");
		}
	}
}


//��ȣ ����
void CAnduradu_theSecretDlg::OnBnClickedButtonPwdelete()
{
	bool bOkay = PasswordCheck();
	passCheckMsg(bOkay);

	if(bOkay) {
		// ��ȣ ���� ����
		CString strPass;
		GetDlgItemText(IDC_EDIT_PWCONFIRM, strPass);

		char* path = convertCharTo(m_Directory);
		char* pass = convertCharTo(strPass);
		if(myFileUtil.openFile(path)) {
			if(myFileUtil.decodeFile(0, pass)) {
				AfxMessageBox(L"������ �����Ͽ����ϴ�.");
			} else {
				AfxMessageBox(L"���� ������ �����Ͽ����ϴ�.");
			}
		} else {
			AfxMessageBox(L"������ �� �� �����ϴ�.");
		}
	}
}


//�н����� �� �Լ� (CString ��)
bool CAnduradu_theSecretDlg::PasswordCheck() 
{
	CString str1;
	CString str2;

	GetDlgItemText(IDC_EDIT_PWINPUT, str1);
	GetDlgItemText(IDC_EDIT_PWCONFIRM, str2);
	
/*	ATL::CSimpleStringT<wchar_t, true>::PCXSTR pcxstr1 = str1.GetString();
	ATL::CSimpleStringT<wchar_t, true>::PCXSTR pcxstr2 = str2.GetString();
	return (*pcxstr1 == *pcxstr2) ? 0 : 1; */ 
	//�ؿ� if���� �Ȱ��� ���� �ϴ� �ڵ�ν� �ٸ��� PCXSTR�� �̿��Ͽ� ����غ�.
	
	if(str1 == str2) {
		return true;
	} else {
		return false;
	}
}

void CAnduradu_theSecretDlg::passCheckMsg(bool bOkay)
{
	if (bOkay) {
		AfxMessageBox(_T("�Է� �� ��ȣ�� ��ġ�մϴ�."));
	} else {
		AfxMessageBox(_T("�Է� �� ��ȣ�� ��ġ���� �ʽ��ϴ�. �ٽ� �ۼ����ּ���"));
	}
}

// �����ڵ� ȯ�濡�� CString -> char*
char* CAnduradu_theSecretDlg::convertCharTo(CString str) {
	return (charConvertor.convertCharToCString_UNICODE(str));
}

// �����ڵ� ȯ�濡�� char* -> CString
CString CAnduradu_theSecretDlg::convertCStringTo(char* str) {
	return (charConvertor.convertCStringToChar_UNICODE(str));
}