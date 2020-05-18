// EscrituraDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Cache2003.h"
#include "EscrituraDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEscrituraDlg dialog


CEscrituraDlg::CEscrituraDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEscrituraDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEscrituraDlg)
	m_iEsc_Directa = 0;
	m_iCon_Asignacion = 0;
	//}}AFX_DATA_INIT
}


void CEscrituraDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEscrituraDlg)
	DDX_Radio(pDX, IDC_ESC_DIRECTA, m_iEsc_Directa);
	DDX_Radio(pDX, IDC_CON_ASIGNACION, m_iCon_Asignacion);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEscrituraDlg, CDialog)
	//{{AFX_MSG_MAP(CEscrituraDlg)
	ON_BN_CLICKED(IDC_ESC_DIRECTA, OnEscDirecta)
	ON_BN_CLICKED(IDC_ESC_POST, OnEscPost)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEscrituraDlg message handlers

BOOL CEscrituraDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	
	UpdateData(false);
	
	switch(m_iEsc_Directa)
	{
	case 0:
		OnEscDirecta();
		break;
	case 1:
		OnEscPost();
		break;
	
	}
	
	m_colorMarcos = RGB(128, 128, 128);
	m_pincelMarcos.CreateSolidBrush( m_colorMarcos );

	m_colorTextos = RGB(128, 128, 192);

	
return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE

}

void CEscrituraDlg::OnEscDirecta() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_CON_ASIGNACION) ->EnableWindow(TRUE);
	GetDlgItem(IDC_SIN_ASIGNACION) -> EnableWindow(TRUE);
	
	
}

void CEscrituraDlg::OnEscPost() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_CON_ASIGNACION) ->EnableWindow(FALSE);
	GetDlgItem(IDC_SIN_ASIGNACION) -> EnableWindow(FALSE);
}

HBRUSH CEscrituraDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_POLITICAS)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_TIPO)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}

	// TODO: Return a different brush if the default is not desired
	return hbr;
}
