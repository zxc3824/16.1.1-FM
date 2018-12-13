
// FileManagerDlg.h : 헤더 파일
//

#pragma once


// CFileManagerDlg 대화 상자
class CFileManagerDlg : public CDialogEx
{
// 생성입니다.
public:
	CFileManagerDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FILEMANAGER_DIALOG };

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
private:
	CString m_oroot;
	CString m_mroot;
	CString m_name;
	CString m_extension;
	CString m_addfname;
public:
	CString FolderBrowser(CString);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void mfStart();
	void cfStart();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
