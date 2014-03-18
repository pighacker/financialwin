// AddStock.cpp : 實作檔
//

#include "stdafx.h"
#include "FinacialWin.h"
#include "AddStock.h"
#include "afxdialogex.h"


// AddStock 對話方塊

IMPLEMENT_DYNAMIC(AddStock, CDialogEx)

AddStock::AddStock(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddStock::IDD, pParent)
{

}

AddStock::~AddStock()
{
}

void AddStock::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddStock, CDialogEx)
END_MESSAGE_MAP()


// AddStock 訊息處理常式
