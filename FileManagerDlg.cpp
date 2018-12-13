
// FileManagerDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "FileManager.h"
#include "FileManagerDlg.h"
#include "afxdialogex.h"
#include "Move.h"
#include "Copy.h"

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


// CFileManagerDlg 대화 상자




CFileManagerDlg::CFileManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFileManagerDlg::IDD, pParent)
	, m_oroot(_T(""))
	, m_mroot(_T(""))
	, m_name(_T(""))
	, m_extension(_T(""))
	, m_addfname(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_oroot);
	DDX_Text(pDX, IDC_EDIT2, m_mroot);
	DDX_Text(pDX, IDC_EDIT3, m_name);
	DDX_Text(pDX, IDC_EDIT4, m_extension);
	DDX_Text(pDX, IDC_EDIT5, m_addfname);
}

BEGIN_MESSAGE_MAP(CFileManagerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CFileManagerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CFileManagerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CFileManagerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CFileManagerDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CFileManagerDlg 메시지 처리기

BOOL CFileManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CFileManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CFileManagerDlg::OnPaint()
{
	if (IsIconic())
	{
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
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CFileManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




BOOL CFileManagerDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	/* Esc키, Enter키 입력시 프로그램 종료 방지 */
	if ((pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE) || (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)) {
		return true;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

CString CFileManagerDlg::FolderBrowser(CString str) { // 폴더 다이얼로그 창
	CFolderPickerDialog dlg;
	dlg.DoModal();
	str = dlg.GetPathName();
	return str;
}

void CFileManagerDlg::mfStart() { // 파일 이동
	CMove move; // CMove 선언
	move.FileMove(m_oroot, m_mroot, m_name, m_extension, m_addfname); // 파일 이동 함수(Move.cpp)
}

void CFileManagerDlg::cfStart() { // 파일 복사
	CCopy copy; // CCopy 선언
	copy.FileCopy(m_oroot, m_mroot, m_name, m_extension, m_addfname); // 파일 복사 함수(Copy.cpp)
}

void CFileManagerDlg::OnBnClickedButton1() // 파일 검색 경로 선택
{
	UpdateData(true);
	m_oroot = FolderBrowser(m_oroot);
	UpdateData(false);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CFileManagerDlg::OnBnClickedButton2() // 파일 이동 경로 선택
{
	UpdateData(true);
	m_mroot = FolderBrowser(m_mroot);
	UpdateData(false);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CFileManagerDlg::OnBnClickedButton3() // 파일 이동 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);
	m_oroot = m_oroot.GetString();
	mfStart();
	UpdateData(false);
}


void CFileManagerDlg::OnBnClickedButton4() // 파일 복사 버튼
{
	UpdateData(true);
	m_oroot = m_oroot.GetString();
	cfStart();
	UpdateData(false);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
