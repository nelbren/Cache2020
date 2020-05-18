// SimulacionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Cache2003.h"
#include "SimulacionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSimulacionDlg dialog


CSimulacionDlg::CSimulacionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSimulacionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSimulacionDlg)
	m_inSec = 20;
	m_iAutomatico = 0;
	m_iAutomatico_Sec = 0;
	//}}AFX_DATA_INIT
}


void CSimulacionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSimulacionDlg)
	DDX_Text(pDX, IDC_EDIT_N_SEC, m_inSec);
	DDX_Radio(pDX, IDC_RADIO_AUTOMATICO, m_iAutomatico);
	DDX_Radio(pDX, IDC_RADIO_SEC_AUTOMATICA, m_iAutomatico_Sec);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSimulacionDlg, CDialog)
	//{{AFX_MSG_MAP(CSimulacionDlg)
	ON_BN_CLICKED(IDC_RADIO_SEC_AUTOMATICA, OnRadioSecAutomatica)
	ON_BN_CLICKED(IDC_RADIO_MANUAL_SEC, OnRadioManualSec)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimulacionDlg message handlers

BOOL CSimulacionDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	
	switch(m_iAutomatico_Sec)
	{
	case 0:
		OnRadioSecAutomatica(); 
 		break;
	case 1:
		OnRadioManualSec();
		break;
	
	}

	m_colorMarcos = RGB(128, 128, 128);
	m_pincelMarcos.CreateSolidBrush( m_colorMarcos );

	m_colorTextos = RGB(128, 128, 192);




	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSimulacionDlg::OnRadioSecAutomatica() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_STATIC_N_SEC) -> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_N_SEC) -> EnableWindow(FALSE);

}

void CSimulacionDlg::OnRadioManualSec() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_STATIC_N_SEC) -> EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_N_SEC) -> EnableWindow(TRUE);
}


HBRUSH CSimulacionDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_MP)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}

	if( pWnd->GetDlgCtrlID() == IDC_STATIC_SEC)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}

	// TODO: Return a different brush if the default is not desired
	return hbr;
}
