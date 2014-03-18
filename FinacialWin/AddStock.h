#pragma once


// AddStock 對話方塊

class AddStock : public CDialogEx
{
	DECLARE_DYNAMIC(AddStock)

public:
	AddStock(CWnd* pParent = NULL);   // 標準建構函式
	virtual ~AddStock();

// 對話方塊資料
	enum { IDD = IDD_FINACIALWIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
};
