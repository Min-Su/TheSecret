
// Anduradu_theSecretDlg.cpp : 구현 파일
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


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CAnduradu_theSecretDlg 대화 상자




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


// CAnduradu_theSecretDlg 메시지 처리기

BOOL CAnduradu_theSecretDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL) {
		BOOL bNameValid;
		CString strAboutMenu;
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CAnduradu_theSecretDlg::OnPaint()
{
	if (IsIconic()) {
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	} else {
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CAnduradu_theSecretDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CAnduradu_theSecretDlg::OnBnClickedButtonFilesearch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog fileDlg(TRUE, _T("*.*"), _T("*.*"), OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("*.*"), this);  //모든 파일 보임
	if(fileDlg.DoModal() == IDOK) {
		m_Directory = fileDlg.GetPathName();
		UpdateData(FALSE);
	}
	//디렉토리 검색 창을 띄어서 경로를 입력받고 경로를 텍스트박스에 넣는다.
}



void CAnduradu_theSecretDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	HelpDialog messageDlg;  //MessageDlg 선언
	messageDlg.DoModal();  //Message_Dlg 를 생성
	//도움말
}


void CAnduradu_theSecretDlg::OnStatic()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CFont fnt;
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 18;
	lf.lfWeight = FW_BOLD;
	::lstrcpy(lf.lfFaceName, (LPCWSTR)"Tahoma");
	fnt.CreateFontIndirect(&lf);
	GetDlgItem(IDC_STATIC)->SetFont(&fnt);
	fnt.Detach();
	//레이블 폰트 변경?
}

/****
	도움말 다이얼로그 창 닫기.
****/
void CAnduradu_theSecretDlg::OnBnClickedButtonExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnDestroy(); //다이얼로그를 파괴하고
	OnOK(); //종료
	//종료버튼 명령
}

//암호 입력
void CAnduradu_theSecretDlg::OnBnClickedButtonPwinput()
{
	bool bOkay = PasswordCheck();
	passCheckMsg(bOkay);

	if(bOkay) {
		// 암호화 시작
		CString strPass;
		// 아래 구문 실행시 이미 메시지 박스가 떠있기 때문에 논리오류처리를 굳이 하지 않아도 된다.
		// 비밀번호 입력하고 메시지 박스가 떠있는 와중에 비밀번호를 지우는 경우, 공백을 읽어와 비밀번호로
		// 사용하게 된다. 나중에 이 부분이 메시지 박스와 별개로 돌게 되는 경우 고려해야 한다.
		GetDlgItemText(IDC_EDIT_PWCONFIRM, strPass);

		char* path = convertCharTo(m_Directory);
		char* pass = convertCharTo(strPass);
		if(myFileUtil.openFile(path)) {
			if(myFileUtil.encodeFile(0, pass)) {
				AfxMessageBox(L"파일을 암호화 하였습니다.");
			} else {
				AfxMessageBox(L"파일 암호화에 실패하였습니다.");
			}
		} else {
			AfxMessageBox(L"파일을 열 수 없습니다.");
		}
	}
}


//암호 해제
void CAnduradu_theSecretDlg::OnBnClickedButtonPwdelete()
{
	bool bOkay = PasswordCheck();
	passCheckMsg(bOkay);

	if(bOkay) {
		// 암호 해제 시작
		CString strPass;
		GetDlgItemText(IDC_EDIT_PWCONFIRM, strPass);

		char* path = convertCharTo(m_Directory);
		char* pass = convertCharTo(strPass);
		if(myFileUtil.openFile(path)) {
			if(myFileUtil.decodeFile(0, pass)) {
				AfxMessageBox(L"파일을 복구하였습니다.");
			} else {
				AfxMessageBox(L"파일 복구에 실패하였습니다.");
			}
		} else {
			AfxMessageBox(L"파일을 열 수 없습니다.");
		}
	}
}


//패스워드 비교 함수 (CString 비교)
bool CAnduradu_theSecretDlg::PasswordCheck() 
{
	CString str1;
	CString str2;

	GetDlgItemText(IDC_EDIT_PWINPUT, str1);
	GetDlgItemText(IDC_EDIT_PWCONFIRM, str2);
	
/*	ATL::CSimpleStringT<wchar_t, true>::PCXSTR pcxstr1 = str1.GetString();
	ATL::CSimpleStringT<wchar_t, true>::PCXSTR pcxstr2 = str2.GetString();
	return (*pcxstr1 == *pcxstr2) ? 0 : 1; */ 
	//밑에 if문과 똑같은 일을 하는 코드로써 다르게 PCXSTR을 이용하여 사용해봄.
	
	if(str1 == str2) {
		return true;
	} else {
		return false;
	}
}

void CAnduradu_theSecretDlg::passCheckMsg(bool bOkay)
{
	if (bOkay) {
		AfxMessageBox(_T("입력 된 암호가 일치합니다."));
	} else {
		AfxMessageBox(_T("입력 된 암호가 일치하지 않습니다. 다시 작성해주세요"));
	}
}

// 유니코드 환경에서 CString -> char*
char* CAnduradu_theSecretDlg::convertCharTo(CString str) {
	return (charConvertor.convertCharToCString_UNICODE(str));
}

// 유니코드 환경에서 char* -> CString
CString CAnduradu_theSecretDlg::convertCStringTo(char* str) {
	return (charConvertor.convertCStringToChar_UNICODE(str));
}