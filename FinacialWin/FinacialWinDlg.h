
// FinacialWinDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CFinacialWinDlg 对话框
class CFinacialWinDlg : public CDHtmlDialog
{
// 构造
public:
	CFinacialWinDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_FINACIALWIN_DIALOG, IDH = IDR_HTML_FINACIALWIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
