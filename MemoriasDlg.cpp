// MemoriasDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Cache2003.h"
#include "MemoriasDlg.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMemoriasDlg dialog


CMemoriasDlg::CMemoriasDlg(CWnd* pParent /*=NULL*/ )
	: CDialog(CMemoriasDlg::IDD, pParent)
{
	
	
	//{{AFX_DATA_INIT(CMemoriasDlg)
	m_inBloque = 1;
	m_inMC = 1;
	m_inMP = 1;
	m_lBytesTamBloque = 0;
	m_lBytesTamMC = 0;
	m_lKBytesTamBloque = 0;
	m_lKBytesTamMC = 0;
	m_lKBytesTamMP = 0;
	m_lMBytesTamBloque = 0;
	m_lMBytesTamMP = 0;
	m_lMBytesTamMC = 0;
	m_lBytesTamMP = 0;
	
	//}}AFX_DATA_INIT
	
}


void CMemoriasDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMemoriasDlg)
	DDX_Control(pDX, IDC_N_BLOQUE, m_Ctrl_Bloque);
	DDX_Control(pDX, IDC_N_MC, m_Ctrl_MC);
	DDX_Control(pDX, IDC_N_MP, m_Ctrl_MP);
	DDX_Text(pDX, IDC_N_BLOQUE, m_inBloque);
	DDV_MinMaxInt(pDX, m_inBloque, 0, 30);
	DDX_Text(pDX, IDC_N_MC, m_inMC);
	DDV_MinMaxInt(pDX, m_inMC, 0, 30);
	DDX_Text(pDX, IDC_N_MP, m_inMP);
	DDV_MinMaxInt(pDX, m_inMP, 0, 30);
	DDX_Text(pDX, IDC_BYTES_BLOQUE, m_lBytesTamBloque);
	DDX_Text(pDX, IDC_BYTES_MC, m_lBytesTamMC);
	DDX_Text(pDX, IDC_KBYTES_BLOQUE, m_lKBytesTamBloque);
	DDX_Text(pDX, IDC_KBYTES_MC, m_lKBytesTamMC);
	DDX_Text(pDX, IDC_KBYTES_MP, m_lKBytesTamMP);
	DDX_Text(pDX, IDC_MBYTES_BLOQUE, m_lMBytesTamBloque);
	DDX_Text(pDX, IDC_MBYTES_MP, m_lMBytesTamMP);
	DDX_Text(pDX, IDC_MBYTES_MC, m_lMBytesTamMC);
	DDX_Text(pDX, IDC_BYTES_MP, m_lBytesTamMP);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMemoriasDlg, CDialog)
	//{{AFX_MSG_MAP(CMemoriasDlg)
	ON_EN_CHANGE(IDC_N_MP, OnChangeNMp)
	ON_BN_CLICKED(IDC_INCRE_MP, OnIncreMp)
	ON_BN_CLICKED(IDC_DECRE_MP, OnDecreMp)
	ON_EN_CHANGE(IDC_N_MC, OnChangeNMc)
	ON_BN_CLICKED(IDC_INCRE_MC, OnIncreMc)
	ON_BN_CLICKED(IDC_DECRE_MC, OnDecreMc)
	ON_EN_CHANGE(IDC_N_BLOQUE, OnChangeNBloque)
	ON_BN_CLICKED(IDC_INCRE_BLOQUE, OnIncreBloque)
	ON_BN_CLICKED(IDC_DECRE_BLOQUE, OnDecreBloque)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMemoriasDlg message handlers

void CMemoriasDlg::OnChangeNMp() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	

	UpdateData(true);
		
		m_lBytesTamMP = (long) pow(2,m_inMP);
	 
		m_lKBytesTamMP = (long)ConvertKBytes( m_inMP);
		if (m_lKBytesTamMP <= 0)
		{
			GetDlgItem(IDC_STATIC_KBYTES_MP) -> ShowWindow(FALSE);
			GetDlgItem(IDC_KBYTES_MP) -> ShowWindow(FALSE);
		}
		else
		{
			GetDlgItem(IDC_STATIC_KBYTES_MP) -> ShowWindow(TRUE);
			GetDlgItem(IDC_KBYTES_MP) -> ShowWindow(TRUE);
		}
	 
		m_lMBytesTamMP = (long)ConvertMBytes( m_inMP);
	 
		if( m_lMBytesTamMP <= 0 )
		{
			GetDlgItem(IDC_STATIC_MBYTES_MP) -> ShowWindow(FALSE);
			GetDlgItem(IDC_MBYTES_MP) -> ShowWindow(FALSE);
		}
		else
		{
			GetDlgItem(IDC_STATIC_MBYTES_MP) -> ShowWindow(TRUE);
			GetDlgItem(IDC_MBYTES_MP) -> ShowWindow(TRUE);
		}
	
	UpdateData(false);
	 
	CString MensajeTexto2, MensajeTitulo;
	int DialogoTipo;
		
	DialogoTipo = MB_ICONEXCLAMATION;
	MensajeTexto2 = "Valor de MEMORIA PRINCIPAL invalido!!!.El valor de MEMORIA PRINCIPAL debe ser mayor que cero";
	MensajeTitulo = "ERROR"; 
	  		  
	UpdateData(true);
	if( m_inMP == 0 )
	{
		MessageBox(MensajeTexto2, MensajeTitulo, DialogoTipo);					   
		//m_inMP = 0;
		//m_lBytesTamMP = 1;
		UpdateData( false);
		OnChangeNBloque();
	}

		
}

double CMemoriasDlg::ConvertKBytes(int n)
{

    double KBytes; 
	int K = (int)pow(2, 10);
    int x = (int)pow(2, n);
	
	KBytes = x / K;

return KBytes;
}


double CMemoriasDlg::ConvertMBytes(int n)
{
	double MBytes; 
	int M = (int)pow(2, 20);
    int x = (int)pow(2, n);
	
	MBytes = x / M;

return MBytes;
}

void CMemoriasDlg::OnIncreMp() 
{
	// TODO: Add your control notification handler code here
	UpdateData( true );
	m_inMP++;
	UpdateData( false );
	OnChangeNMp();	
}

void CMemoriasDlg::OnDecreMp() 
{
	// TODO: Add your control notification handler code here
	UpdateData( true );
	m_inMP--;
	UpdateData( false );
	OnChangeNMp();
}

void CMemoriasDlg::OnChangeNMc() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
	UpdateData(true);
		
	
	 
		m_lBytesTamMC = (long) pow(2,m_inMC);
	 
		m_lKBytesTamMC = (long)ConvertKBytes( m_inMC);
		if (m_lKBytesTamMC <= 0)
		{
			GetDlgItem(IDC_STATIC_KBYTES_MC) -> ShowWindow(FALSE);
			GetDlgItem(IDC_KBYTES_MC) -> ShowWindow(FALSE);
		}
		else
		{
			GetDlgItem(IDC_STATIC_KBYTES_MC) -> ShowWindow(TRUE);
			GetDlgItem(IDC_KBYTES_MC) -> ShowWindow(TRUE);
		}
	 
		m_lMBytesTamMC = (long)ConvertMBytes( m_inMC);
	 
		if( m_lMBytesTamMC <= 0 )
		{
			GetDlgItem(IDC_STATIC_MBYTES_MC) -> ShowWindow(FALSE);
			GetDlgItem(IDC_MBYTES_MC) -> ShowWindow(FALSE);
		}
		else
		{
			GetDlgItem(IDC_STATIC_MBYTES_MC) -> ShowWindow(TRUE);
			GetDlgItem(IDC_MBYTES_MC) -> ShowWindow(TRUE);
		}
	
	UpdateData(false);
	
	CString MensajeTexto1, MensajeTexto2, MensajeTitulo;
	int DialogoTipo;

	DialogoTipo = MB_ICONEXCLAMATION;
	MensajeTexto1 = "Valor de MEMORIA CACHE invalido!!!.Tamaño de MEMORIA CACHE debe ser MENOR que el de MEMORIA PRINCIPAL";
    MensajeTexto2 = "Valor de MEMORIA CACHE invalido!!!.El valor de MEMORIA CACHE debe ser mayor que cero";
	MensajeTitulo = "ERROR"; 
	
 	  
	if( m_inMP < m_inMC )
	{
		MessageBox(MensajeTexto1, MensajeTitulo, DialogoTipo);					   
		m_inMC = 0;
		m_lBytesTamMC = 0;
		UpdateData( false);
		OnChangeNMc();
	}

	/*
	if( (m_inMP > 0) && (m_inMC == 0) )
	{
		MessageBox(MensajeTexto2, MensajeTitulo, DialogoTipo);					   
		m_inMC = 0;
		m_lBytesTamMC = 0;
		UpdateData( false);
		OnChangeNMc();
		
	}
	  */
}

void CMemoriasDlg::OnIncreMc() 
{
	// TODO: Add your control notification handler code here
	UpdateData( true );
	m_inMC++;
	UpdateData( false );
	OnChangeNMc();	
}

void CMemoriasDlg::OnDecreMc() 
{
	// TODO: Add your control notification handler code here
	UpdateData( true );
	m_inMC--;
	UpdateData( false );
	OnChangeNMc();	
}


void CMemoriasDlg::OnChangeNBloque() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(true);
		
		m_lBytesTamBloque = (long) pow(2,m_inBloque);
	 
		m_lKBytesTamBloque = (long)ConvertKBytes( m_inBloque);
		if (m_lKBytesTamBloque <= 0)
		{
			GetDlgItem(IDC_STATIC_KBYTES_BLOQUE) -> ShowWindow(FALSE);
			GetDlgItem(IDC_KBYTES_BLOQUE) -> ShowWindow(FALSE);
		}
		else
		{
			GetDlgItem(IDC_STATIC_KBYTES_BLOQUE) -> ShowWindow(TRUE);
			GetDlgItem(IDC_KBYTES_BLOQUE) -> ShowWindow(TRUE);
		}
	 
		m_lMBytesTamBloque = (long)ConvertMBytes( m_inBloque);
	 
		if( m_lMBytesTamBloque <= 0 )
		{
			GetDlgItem(IDC_STATIC_MBYTES_BLOQUE) -> ShowWindow(FALSE);
			GetDlgItem(IDC_MBYTES_BLOQUE) -> ShowWindow(FALSE);
		}
		else
		{
			GetDlgItem(IDC_STATIC_MBYTES_BLOQUE) -> ShowWindow(TRUE);
			GetDlgItem(IDC_MBYTES_BLOQUE) -> ShowWindow(TRUE);
		}
	
	UpdateData(false);
	
	CString MensajeTexto1, MensajeTexto2, MensajeTitulo;
	int DialogoTipo;
		
	DialogoTipo = MB_ICONEXCLAMATION;
	MensajeTexto1 = "Valor de BLOQUE invalido!!!.Tamaño de BLOQUE debe ser MENOR que el de MEMORIA CACHE";
    MensajeTexto2 = "Valor de BLOQUE invalido!!!.El valor de BLOQUE debe ser mayor que cero";
	MensajeTitulo = "ERROR"; 
	  		  
	if( m_inMC < m_inBloque )
	{
		MessageBox(MensajeTexto1, MensajeTitulo, DialogoTipo);					   
		m_inBloque = 0;
		m_lBytesTamBloque = 0;
		UpdateData( false);
		OnChangeNBloque();
	}
	
	/*
	if( (m_inMC > 0) && (m_inBloque == 0) )
	{
		MessageBox(MensajeTexto2, MensajeTitulo, DialogoTipo);					   
		m_inBloque = 0;
		m_lBytesTamBloque = 0;
		UpdateData( false);
		OnChangeNBloque();
	}
	  */
}

void CMemoriasDlg::OnIncreBloque() 
{
	// TODO: Add your control notification handler code here
	UpdateData( true );
	m_inBloque++;
	UpdateData( false );
	OnChangeNBloque();	
}

void CMemoriasDlg::OnDecreBloque() 
{
	// TODO: Add your control notification handler code here
	UpdateData( true );
	m_inBloque--;
	UpdateData( false );
	OnChangeNBloque();
}

BOOL CMemoriasDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	m_colorMarcos = RGB(128, 128, 128);
	m_pincelMarcos.CreateSolidBrush( m_colorMarcos );

	m_colorTextos = RGB(128, 128, 192);
	
	m_colorEdit = RGB(0, 0, 255);
	m_pincelEdit.CreateSolidBrush( m_colorEdit );

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


HBRUSH CMemoriasDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	//Marcos
	
	
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_MP)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_MC)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_BLQ)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}
	
	//Colorea texto edit
	if( pWnd->GetDlgCtrlID() == IDC_BYTES_MP)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_KBYTES_MP)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_MBYTES_MP)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_BYTES_MC)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_KBYTES_MC)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_MBYTES_MC)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_BYTES_BLOQUE)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_KBYTES_BLOQUE)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_MBYTES_BLOQUE)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
