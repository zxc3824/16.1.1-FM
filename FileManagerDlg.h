
// FileManagerDlg.h : ��� ����
//

#pragma once


// CFileManagerDlg ��ȭ ����
class CFileManagerDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CFileManagerDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FILEMANAGER_DIALOG };

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
