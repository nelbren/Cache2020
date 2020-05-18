// PoliticasDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Cache2003.h"
#include "PoliticasDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPoliticasDlg dialog


CPoliticasDlg::CPoliticasDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPoliticasDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPoliticasDlg)
	m_iPAleatorio = 0;
	m_iPDirecto = 1;
	m_snVias = "2";
	//}}AFX_DATA_INIT
	
}


void CPoliticasDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPoliticasDlg)
	DDX_Radio(pDX, IDC_POLIT_ALEATORIO, m_iPAleatorio);
	DDX_Radio(pDX, IDC_POLIT_DIRECTO, m_iPDirecto);
	DDX_CBString(pDX, IDC_N_VIAS, m_snVias);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPoliticasDlg, CDialog)
	//{{AFX_MSG_MAP(CPoliticasDlg)
	ON_BN_CLICKED(IDC_POLIT_DIRECTO, OnPolitDirecto)
	ON_BN_CLICKED(IDC_POLIT_ASOCIATIVO, OnPolitAsociativo)
	ON_BN_CLICKED(IDC_POLIT_A_COJUNTOS, OnPolitACojuntos)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPoliticasDlg message handlers


void CPoliticasDlg::OnPolitDirecto() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_POLIT_ALEATORIO) ->EnableWindow(FALSE);
	GetDlgItem(IDC_POLIT_LRU) -> EnableWindow(FALSE);
	GetDlgItem(IDC_POLIT_LFU) -> EnableWindow(FALSE);
	GetDlgItem(IDC_POLIT_FIFO) -> EnableWindow(FALSE);
	GetDlgItem(IDC_N_VIAS) -> EnableWindow(FALSE);	
	
}

void CPoliticasDlg::OnPolitAsociativo() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_POLIT_ALEATORIO) ->EnableWindow(TRUE);
	GetDlgItem(IDC_POLIT_LRU) -> EnableWindow(TRUE);
	GetDlgItem(IDC_POLIT_LFU) -> EnableWindow(TRUE);
	GetDlgItem(IDC_POLIT_FIFO) -> EnableWindow(TRUE);
	GetDlgItem(IDC_N_VIAS) -> EnableWindow(FALSE);	
}

void CPoliticasDlg::OnPolitACojuntos() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_POLIT_ALEATORIO) ->EnableWindow(TRUE);
	GetDlgItem(IDC_POLIT_LRU) -> EnableWindow(TRUE);
	GetDlgItem(IDC_POLIT_LFU) -> EnableWindow(TRUE);
	GetDlgItem(IDC_POLIT_FIFO) -> EnableWindow(TRUE);
	GetDlgItem(IDC_N_VIAS) -> EnableWindow(TRUE);	
}

BOOL CPoliticasDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	
	switch(m_iPDirecto)
	{
	case 0:
		OnPolitDirecto();
		m_iPAleatorio = -1;
		
		break;
	case 1:
		OnPolitAsociativo();
		break;
	case 2:
		OnPolitACojuntos();
		break;
	}
	
	m_colorMarcos = RGB(128, 128, 128);
	m_colorTextos = RGB(128, 128, 192);
	m_pincelMarcos.CreateSolidBrush( m_colorMarcos );

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CPoliticasDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_EMPLAZA)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_REEMPLAZA)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}
	

	// TODO: Return a different brush if the default is not desired
	return hbr;
}
