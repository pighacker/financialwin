
// FinacialWinDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FinacialWin.h"
#include "FinacialWinDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CFinacialWinDlg 对话框

BEGIN_DHTML_EVENT_MAP(CFinacialWinDlg)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()


CFinacialWinDlg::CFinacialWinDlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CFinacialWinDlg::IDD, CFinacialWinDlg::IDH, pParent)
	, m_num_01(_T(""))
	, m_num_02(_T(""))
	, m_num_res(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFinacialWinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_num_01);
	//DDV_MaxChars(pDX, m_num_01, 32);
	DDX_Text(pDX, IDC_EDIT2, m_num_02);
	DDV_MaxChars(pDX, m_num_02, 32);
	DDX_Text(pDX, IDC_EDIT3, m_num_res);
	DDV_MaxChars(pDX, m_num_res, 32);
	DDX_Control(pDX, IDC_BUTTON1, m_but_01);
}

BEGIN_MESSAGE_MAP(CFinacialWinDlg, CDHtmlDialog)
	ON_WM_SYSCOMMAND()
	ON_EN_CHANGE(IDC_EDIT1, &CFinacialWinDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CFinacialWinDlg::OnClickedCount)
END_MESSAGE_MAP()


// CFinacialWinDlg 消息处理程序

BOOL CFinacialWinDlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFinacialWinDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDHtmlDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFinacialWinDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDHtmlDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CFinacialWinDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HRESULT CFinacialWinDlg::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;
}

HRESULT CFinacialWinDlg::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;
}


void CFinacialWinDlg::OnEnChangeEdit1()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDHtmlDialog::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
}


void CFinacialWinDlg::OnClickedCount()
{
	UpdateData(TRUE);
	char *str_num_01 = (LPSTR)(LPCTSTR)m_num_01;
	char *str_num_02 = (LPSTR)(LPCTSTR)m_num_02;
	char *str_num_res = (LPSTR)(LPCTSTR)m_num_res;

	int de_num_01 = atoi(str_num_01);
	int de_num_02 = atoi(str_num_02);
	int de_num_res = de_num_01 + de_num_02;

	printf("---By James--<%s:%d>--<%d+%d=%d>-\n",__FILE__,__LINE__,de_num_01,de_num_02,de_num_res);

	for(int i0=0;i0<strlen(str_num_01);i0++)
	{
		printf("---By James--<%s:%d>--<%c>-\n",__FILE__,__LINE__,str_num_01[i0]);
		if(str_num_01[i0]>'9' || str_num_01[i0]<'0')
		{
			printf("---By James--<%s:%d>--ERROR:%c-\n",__FILE__,__LINE__,str_num_01[i0]);
			return ;
		}
	}
	for(int i0=0;i0<strlen(str_num_02);i0++)
	{
		printf("---By James--<%s:%d>--<%c>-\n",__FILE__,__LINE__,str_num_02[i0]);
		if(str_num_02[i0]>'9' || str_num_02[i0]<'0')
		{
			printf("---By James--<%s:%d>--ERROR:%c-\n",__FILE__,__LINE__,str_num_02[i0]);
			return ;
		}
	}
	printf("---By James--<%s:%d>--<%d+%d=%d>-\n",__FILE__,__LINE__,de_num_01,de_num_02,de_num_res);
	de_num_01 = atoi(str_num_01);
	de_num_02 = atoi(str_num_02);
	de_num_res = de_num_01 + de_num_02;


	//sprintf("%d", de_num_res);
	//m_num_res = m_num_01 + m_num_02;
	
	m_num_res.Format(_T("%d"), de_num_res);


	printf("---By James--<%s:%d>--<%d+%d=%d>-\n",__FILE__,__LINE__,de_num_01,de_num_02,de_num_res);
	UpdateData(FALSE);
	// TODO: 在此加入控制項告知處理常式程式碼
}
