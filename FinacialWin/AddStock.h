#pragma once


// AddStock ��Ԓ���K

class AddStock : public CDialogEx
{
	DECLARE_DYNAMIC(AddStock)

public:
	AddStock(CWnd* pParent = NULL);   // �˜ʽ�����ʽ
	virtual ~AddStock();

// ��Ԓ���K�Y��
	enum { IDD = IDD_FINACIALWIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧Ԯ

	DECLARE_MESSAGE_MAP()
};
