// TiemposDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Cache2003.h"
#include "TiemposDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTiemposDlg dialog


CTiemposDlg::CTiemposDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTiemposDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTiemposDlg)
	m_iBasica = 0;
	m_iParalelo = 0;
	m_fTc = 0.0f;
	m_fTp = 0.0f;
	//}}AFX_DATA_INIT
}


void CTiemposDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTiemposDlg)
	DDX_Radio(pDX, IDC_RADIO_BASICA, m_iBasica);
	DDX_Radio(pDX, IDC_RADIO_PARALELO, m_iParalelo);
	DDX_Text(pDX, IDC_EDIT_TA_MC, m_fTc);
	DDX_Text(pDX, IDC_EDIT_TA_MP, m_fTp);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTiemposDlg, CDialog)
	//{{AFX_MSG_MAP(CTiemposDlg)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTiemposDlg message handlers

HBRUSH CTiemposDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_TRANSFERENCIA)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_ACCESO)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_CICLO)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}
	
	

	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CTiemposDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_colorMarcos = RGB(128, 128, 128);
	m_pincelMarcos.CreateSolidBrush( m_colorMarcos );

	m_colorTextos = RGB(128, 128, 192);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
