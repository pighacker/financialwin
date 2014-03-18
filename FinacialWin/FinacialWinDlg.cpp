
// FinacialWinDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FinacialWin.h"
#include "FinacialWinDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CFinacialWinDlg �Ի���

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


// CFinacialWinDlg ��Ϣ�������

BOOL CFinacialWinDlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFinacialWinDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDHtmlDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	// TODO:  ����@�� RICHEDIT ����헣�����헌�����
	// ���ʹ˸�֪������������ CDHtmlDialog::OnInitDialog()
	// ��ʽ�ͺ��� CRichEditCtrl().SetEventMask()
	// ׌���� ENM_CHANGE ��� ORed �������֡�

	// TODO:  �ڴ˼������헸�֪̎��ʽ��ʽ�a
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
	// TODO: �ڴ˼������헸�֪̎��ʽ��ʽ�a
}
