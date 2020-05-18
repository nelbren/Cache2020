// ColoresDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Cache2003.h"
#include "ColoresDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColoresDlg dialog


CColoresDlg::CColoresDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CColoresDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CColoresDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CColoresDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColoresDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CColoresDlg, CDialog)
	//{{AFX_MSG_MAP(CColoresDlg)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColoresDlg message handlers

HBRUSH CColoresDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	//Color de controles edit de muestra

	if( pWnd->GetDlgCtrlID() == IDC_EDIT_OCRE)
	{
		pDC->SetBkColor(m_colorEtiquetas);
		return (HBRUSH)m_pincelEtiquetas.GetSafeHandle();
	}

	 if( pWnd->GetDlgCtrlID() == IDC_EDIT_NARANJA)
	{
		pDC->SetBkColor(m_colorLineas);
		return (HBRUSH)m_pincelLineas.GetSafeHandle();
	}

	if( pWnd->GetDlgCtrlID() == IDC_EDIT_ROSADO)
	{
		pDC->SetBkColor(m_colorConjuntos);
		return (HBRUSH)m_pincelConjuntos.GetSafeHandle();
	}

	if( pWnd->GetDlgCtrlID() == IDC_EDIT_MOSTAZA)
	{
		pDC->SetBkColor(m_colorPalabras);
		return (HBRUSH)m_pincelPalabras.GetSafeHandle();
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_AMARILLO)
	{
		pDC->SetBkColor(m_colorAmarillo_MP);
		return (HBRUSH)m_pincelAmarillo_MP.GetSafeHandle();
	}

	 if( pWnd->GetDlgCtrlID() == IDC_EDIT_AZUL)
	{
		pDC->SetBkColor(m_colorAzul_MP);
		return (HBRUSH)m_pincelAzul_MP.GetSafeHandle();
	}

	if( pWnd->GetDlgCtrlID() == IDC_EDIT_GRIS)
	{
		pDC->SetBkColor(m_colorImpar);
		return (HBRUSH)m_pincelImpar.GetSafeHandle();
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_ROJO)
	{
		 pDC->SetBkColor(m_colorFallo);
		return (HBRUSH)m_pincelFallo.GetSafeHandle();
	   	
	}

	if( pWnd->GetDlgCtrlID() == IDC_EDIT_ROJO2)
	{
		 pDC->SetBkColor(m_colorFallo);
		return (HBRUSH)m_pincelFallo.GetSafeHandle();
	   	
	}
	
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_CELESTE)
	{
		 pDC->SetBkColor(m_colorCeleste);
		return (HBRUSH)m_pincelCeleste.GetSafeHandle();
	   	
	}



	if( pWnd->GetDlgCtrlID() == IDC_EDIT_VERDE)
	{
		 pDC->SetBkColor(m_colorAcierto);
		 return (HBRUSH)m_pincelAcierto.GetSafeHandle();
	}

	//Colorea textos
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_CELESTE)
	{
		pDC->SetTextColor(m_colorCeleste);
		

	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_ROJO2)
	{
		pDC->SetTextColor(m_colorFallo);
		

	}
	/*
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_SELECT_BUSCA)
	{
		pDC->SetTextColor(RGB(255,0,0));
		pDC->SetBkColor(m_colorAmarillo_MP);
		return (HBRUSH)m_pincelAmarillo_MP.GetSafeHandle();

	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_SELECT_ENCONTRADO)
	{
		pDC->SetTextColor(RGB(0,255,255));
		pDC->SetBkColor(m_colorAzul_MP);
		return (HBRUSH)m_pincelAzul_MP.GetSafeHandle();

	}
	
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_SELECT_ACIERTO)
	{
		pDC->SetTextColor(RGB(255,0,0));
		pDC->SetBkColor(m_colorAcierto);
		return (HBRUSH)m_pincelAcierto.GetSafeHandle();


	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_SELECT_FALLO)
	{
		pDC->SetTextColor(RGB(0,255,255));
		pDC->SetBkColor(m_colorFallo);
		return (HBRUSH)m_pincelFallo.GetSafeHandle();
	   		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_SELECT_CONJUNTO_PAR)
	{
		pDC->SetTextColor(RGB(0,255,255));
		pDC->SetBkColor(m_colorPar);
		return (HBRUSH)m_pincelPar.GetSafeHandle();

	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_SELECT_CONJUNTO_IMPAR)
	{
		pDC->SetTextColor(RGB(0,255,255));
		pDC->SetBkColor(m_colorImpar);
		return (HBRUSH)m_pincelImpar.GetSafeHandle();

	}
	 */
	//Marcos
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_DIR)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}
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
	
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_TEXTOS)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CColoresDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_colorEtiquetas = RGB(128, 0, 0);
	m_colorLineas = RGB(255, 128, 0);
	m_colorPalabras = RGB( 255, 200, 0);
	m_colorConjuntos = RGB( 255, 0, 255);
    m_colorAmarillo_MP = RGB(255, 255, 0);
	m_colorAzul_MP = RGB(0, 0, 255);
	m_colorImpar = RGB(192, 192, 192);
	m_colorAcierto = RGB(0, 255, 0);
	m_colorFallo = RGB(255, 0, 0);
	m_colorPar = RGB(255, 255, 255);
	m_colorCeleste = RGB(0, 255, 255);
	m_colorMarcos = RGB(128, 128, 128);
	m_colorTextos = RGB(128, 128, 192);
	
	m_pincelEtiquetas.CreateSolidBrush( m_colorEtiquetas );
	m_pincelLineas.CreateSolidBrush( m_colorLineas );
	m_pincelPalabras.CreateSolidBrush( m_colorPalabras );
	m_pincelConjuntos.CreateSolidBrush( m_colorConjuntos );
	m_pincelAmarillo_MP.CreateSolidBrush( m_colorAmarillo_MP );
   	m_pincelAzul_MP.CreateSolidBrush( m_colorAzul_MP );
	m_pincelImpar.CreateSolidBrush( m_colorImpar );
	m_pincelAcierto.CreateSolidBrush( m_colorAcierto );
	m_pincelFallo.CreateSolidBrush( m_colorFallo );
	m_pincelPar.CreateSolidBrush( m_colorPar);
	m_pincelCeleste.CreateSolidBrush(m_colorCeleste);
	m_pincelMarcos.CreateSolidBrush( m_colorMarcos);

	GetDlgItem(IDOK)-> ShowWindow(FALSE);





	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
