
// FinacialWinDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CFinacialWinDlg �Ի���
class CFinacialWinDlg : public CDHtmlDialog
{
// ����
public:
	CFinacialWinDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_FINACIALWIN_DIALOG, IDH = IDR_HTML_FINACIALWIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString m_num_01;
	CString m_num_02;
	CString m_num_res;
	CButton m_but_01;
	afx_msg void OnClickedCount();
};
