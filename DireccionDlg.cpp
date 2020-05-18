// DireccionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Cache2003.h"
#include "MemoriasDlg.h"
#include "PoliticasDlg.h"
#include "DireccionDlg.h"
#include "Cache2003View.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDireccionDlg dialog


CDireccionDlg::CDireccionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDireccionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDireccionDlg)
	m_inConjuntos = 0;
	m_inEtiquetas = 0;
	m_inLineas = 0;
	m_inPalabras = 0;
	m_iTotalBits = 0;
	m_sDato = _T("");
	m_sDato_Esc = _T("");
	m_sTipo = _T("");
	m_inMP = 0;
	m_inMC = 0;
	m_inBloque = 0;
	m_snVias = _T("");
	m_iDireccion = 0;
	m_sDireccion = _T("");
	//}}AFX_DATA_INIT
	
	//Create(IDD);

	m_pEtiquetas = NULL;	
	m_pLineas = NULL;
	m_pPalabras = NULL;
	m_pConjuntos = NULL;
	m_pnBits = NULL;
	
}

void CDireccionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDireccionDlg)
	DDX_Text(pDX, IDC_D_CONJUNTO, m_inConjuntos);
	DDX_Text(pDX, IDC_D_ETIQUETA, m_inEtiquetas);
	DDX_Text(pDX, IDC_D_LINEA, m_inLineas);
	DDX_Text(pDX, IDC_D_PALABRA, m_inPalabras);
	DDX_Text(pDX, IDC_D_TOTAL_BITS, m_iTotalBits);
	DDX_Text(pDX, IDC_EDIT_DATO, m_sDato);
	DDX_Text(pDX, IDC_EDIT_DATO_ESC, m_sDato_Esc);
	DDX_Text(pDX, IDC_EDIT_TIPO, m_sTipo);
	DDX_Text(pDX, IDC_EDIT_N_MP, m_inMP);
	DDX_Text(pDX, IDC_EDIT_N_MC, m_inMC);
	DDX_Text(pDX, IDC_EDIT_N_BLOQUE, m_inBloque);
	DDX_Text(pDX, IDC_EDIT_N_VIAS, m_snVias);
	DDX_Text(pDX, IDC_EDIT_DIRECCION, m_iDireccion);
	DDX_Text(pDX, IDC_EDIT_DIRECCION2, m_sDireccion);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDireccionDlg, CDialog)
	//{{AFX_MSG_MAP(CDireccionDlg)
	ON_EN_CHANGE(IDC_D_ETIQUETA, OnChangeDEtiqueta)
	ON_WM_HSCROLL()
	ON_WM_CTLCOLOR()
	ON_EN_CHANGE(IDC_D_LINEA, OnChangeDLinea)
	ON_EN_CHANGE(IDC_D_PALABRA, OnChangeDPalabra)
	ON_EN_CHANGE(IDC_D_TOTAL_BITS, OnChangeDTotalBits)
	ON_EN_CHANGE(IDC_D_CONJUNTO, OnChangeDConjunto)
	ON_EN_CHANGE(IDC_EDIT_DIRECCION, OnChangeEditDireccion)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDireccionDlg message handlers

//Función DirDirecto
//Función que calcula la dirección en bits de la Memoria Principal
//por el METODO DIRECTO imprime el número de bits de etiqueta, línea y palabra

void CDireccionDlg::DirDirecto(int inMP, int inMC, int inBloque)
{
	
	GetDlgItem(IDC_STATIC_D_CONJUNTO) ->EnableWindow(FALSE);
    GetDlgItem(IDC_D_CONJUNTO) -> EnableWindow(FALSE);
    GetDlgItem(IDC_STATIC_D_LINEA) ->EnableWindow(TRUE);
    GetDlgItem(IDC_D_LINEA) -> EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_COLOR_ROSADO) ->EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT_COLOR_NARANJA) -> EnableWindow(TRUE);


	
	int Etiqueta, Linea, Palabra;
	int Total;
	
	Palabra = inBloque;
	Linea = inMC - inBloque;
	Etiqueta = (inMP - inBloque) - Linea;
	Total = Etiqueta + Linea + Palabra;

	UpdateData(true);
    
	m_inEtiquetas = Etiqueta;
	m_inLineas = Linea;
	m_inPalabras = Palabra;
	m_inConjuntos = 0;
	m_iTotalBits = Total;
	
	

}

void CDireccionDlg::DirAsociativo(int inMP, int inMC, int inBloque)
{
	
	
	GetDlgItem(IDC_STATIC_D_CONJUNTO) ->EnableWindow(FALSE);
    GetDlgItem(IDC_D_CONJUNTO) -> EnableWindow(FALSE);
    GetDlgItem(IDC_STATIC_D_LINEA) ->EnableWindow(FALSE);
    GetDlgItem(IDC_D_LINEA) -> EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT_COLOR_ROSADO) ->EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT_COLOR_NARANJA) -> EnableWindow(FALSE);
    

	
	int Etiqueta, Palabra;
	int Total;
	Palabra = inBloque;
	Etiqueta = (inMP - inBloque);
	Total = Etiqueta + Palabra;
	
	UpdateData(true);
    
	m_inEtiquetas = Etiqueta;
	m_inLineas = 0;
	m_inPalabras = Palabra;
	m_inConjuntos = 0;
	m_iTotalBits = Total;
	
	UpdateData( false );

	
}

void CDireccionDlg::DirAConjuntos(int inMP, int inMC, int inBloque, CString snVias)
{
	
	GetDlgItem(IDC_STATIC_D_LINEA) ->EnableWindow(FALSE);
    GetDlgItem(IDC_D_LINEA) -> EnableWindow(FALSE);
    GetDlgItem(IDC_STATIC_D_CONJUNTO) ->EnableWindow(TRUE);
    GetDlgItem(IDC_D_CONJUNTO) -> EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_COLOR_NARANJA) ->EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT_COLOR_ROSADO) -> EnableWindow(TRUE);

	int Etiqueta, Linea, Conjunto, Palabra;
	int Total;
	int inVias = atoi(snVias);
	
	Palabra = inBloque;
	Linea = inMC - inBloque;
	Conjunto = Linea - ConvertBase2(inVias);
	Etiqueta = inMP - Conjunto - Palabra;
	Total = Etiqueta + Conjunto + Palabra;

	UpdateData ( true );
	
	m_inEtiquetas = Etiqueta;
	m_inLineas = 0;
	m_inPalabras = Palabra;
	m_inConjuntos = Conjunto;
	m_iTotalBits = Total;
	
	UpdateData( false );
}







void CDireccionDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	

	BYTE Pos = GetScrollPos(SB_HORZ);
	
	
	CWnd::OnHScroll( nSBCode, nPos, pScrollBar );

	switch(nSBCode)
	{
	case SB_LINELEFT:
		ScrollWindow(-5, 0);
		Pos--;
		break;

	case SB_LINERIGHT:
		ScrollWindow(5,0);
		Pos++;
		break;
	
	case SB_THUMBTRACK:
		ScrollWindow(-5,0);
		Pos = nPos;
		 
		break;

	}

	
	
	if(Pos<0 || Pos>100)
		Pos = 0;
	
	SetScrollPos(SB_HORZ, Pos);
	UpdateWindow();
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


BOOL CDireccionDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	Parche();
		
	m_colorEtiquetas = RGB(128, 0, 0);
	m_colorLineas = RGB(255, 128, 0);
	m_colorPalabras = RGB( 255, 200, 0);
	m_colorConjuntos = RGB( 255, 0, 255);
    m_colorParche = RGB(200, 200, 170);
	m_colorEdit = RGB(255, 255, 180);

	
	m_pincelEtiquetas.CreateSolidBrush( m_colorEtiquetas );
	m_pincelLineas.CreateSolidBrush( m_colorLineas );
	m_pincelPalabras.CreateSolidBrush( m_colorPalabras );
	m_pincelConjuntos.CreateSolidBrush( m_colorConjuntos );
	m_pincelParche.CreateSolidBrush( m_colorParche );
   	m_pincelEdit.CreateSolidBrush( m_colorEdit );

	CMemoriasDlg dlgMemorias;
	CPoliticasDlg dlgPoliticas;	
	//CCache2003View  dlgCache;
	

	
/*
char buffercelda1[5];
CString s_celda1;
s_celda1 = _itoa( m_inMP  , buffercelda1, 10);
MessageBox(" m_nMP = " + s_celda1);
 */	

	/*
	UpdateData(true);
	m_inMP = dlgCache.m_nMP;
	UpdateData(false);
	  
		
	UpdateData(true);
	m_nMP = dlgCache.m_nMP;
	
	//dlgMemorias.m_inMC = m_nMC;
	//dlgMemorias.m_inBloque = m_nBloque;
	UpdateData(false);
	  			  

	switch(dlgPoliticas.m_iPDirecto)
		{
		case 0:
						
			MessageBox("Opción Directo");
			UpdateData(true);
			Parche();
			DirDirecto( dlgMemorias.m_inMP, dlgMemorias.m_inMC, dlgMemorias.m_inBloque );
			UpdateData(false);
			OnChangeDEtiqueta();
			OnChangeDLinea();
			OnChangeDPalabra();
			OnChangeDTotalBits();		
			
			
			break;
		  
		case 1:
			
				
			MessageBox("Opcion Asociativo");
			UpdateData(true);
			Parche();
			DirAsociativo( dlgMemorias.m_inMP, dlgMemorias.m_inMC, dlgMemorias.m_inBloque );
			UpdateData(false);
			OnChangeDEtiqueta();
			OnChangeDLinea();
			OnChangeDPalabra();
			OnChangeDTotalBits();	
			
			
			break;
		  
		case 2:
			
			MessageBox("Opcion Asociativo por Conjuntos");
			UpdateData(true);
			Parche();
			DirAConjuntos( dlgMemorias.m_inMP, dlgMemorias.m_inMC, dlgMemorias.m_inBloque, dlgPoliticas.m_snVias );
			UpdateData(false);
			OnChangeDEtiqueta();
			OnChangeDLinea();
			OnChangeDPalabra();
			OnChangeDTotalBits();		
			
			
					
			break;
		  
		default :
			MessageBox("ERROR.Opción no válida");
			break;
		
		 
		}
			   */
   	  
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CDireccionDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	//Color de el Cuadro de Dialogo
	if( nCtlColor == CTLCOLOR_DLG )
	{
		pDC->SetBkColor(m_colorParche);
		return (HBRUSH)m_pincelParche.GetSafeHandle();
	}
	
	//Color de las etiquetas Static
	if( nCtlColor == CTLCOLOR_STATIC )
	{
		pDC->SetBkColor(m_colorParche);
		pDC->SetTextColor( RGB(0,0,0));
		return (HBRUSH)m_pincelParche.GetSafeHandle();
	}

	
	//Color de los controles edit fijos
	
	if( pWnd->GetDlgCtrlID() == IDC_D_ETIQUETA)
	{
		pDC->SetBkColor(m_colorEdit);
		pDC->SetTextColor(RGB(255,0,0));
		return (HBRUSH)m_pincelEdit.GetSafeHandle();
	}

	 if( pWnd->GetDlgCtrlID() == IDC_D_LINEA)
	{
		pDC->SetBkColor(m_colorEdit);
		pDC->SetTextColor(RGB(255,0,0));
		return (HBRUSH)m_pincelEdit.GetSafeHandle();
	}

	 if( pWnd->GetDlgCtrlID() == IDC_D_PALABRA)
	{
		pDC->SetBkColor(m_colorEdit);
		pDC->SetTextColor(RGB(255,0,0));
		return (HBRUSH)m_pincelEdit.GetSafeHandle();
	}

	if( pWnd->GetDlgCtrlID() == IDC_D_CONJUNTO)
	{
		pDC->SetBkColor(m_colorEdit);
		pDC->SetTextColor(RGB(255,0,0));
		return (HBRUSH)m_pincelEdit.GetSafeHandle();
	}

	if( pWnd->GetDlgCtrlID() == IDC_D_TOTAL_BITS)
	{
		pDC->SetBkColor(m_colorEdit);
		pDC->SetTextColor(RGB(255,0,0));
		return (HBRUSH)m_pincelEdit.GetSafeHandle();
	}

	 if( pWnd->GetDlgCtrlID() == IDC_EDIT_DATO)
	{
		pDC->SetBkColor(m_colorEdit);
		pDC->SetTextColor(RGB(255,0,0));
		return (HBRUSH)m_pincelEdit.GetSafeHandle();
	}

	 if( pWnd->GetDlgCtrlID() == IDC_EDIT_DATO_ESC)
	{
		pDC->SetBkColor(m_colorEdit);
		pDC->SetTextColor(RGB(255,0,0));
		return (HBRUSH)m_pincelEdit.GetSafeHandle();
	}

	if( pWnd->GetDlgCtrlID() == IDC_EDIT_TIPO)
	{
		pDC->SetBkColor(m_colorEdit);
		pDC->SetTextColor(RGB(255,0,0));
		return (HBRUSH)m_pincelEdit.GetSafeHandle();
	}




	//Color de los controles edit de la direccion de memoria

	if( pWnd->GetDlgCtrlID() == IDC_N_BITS1)
	{
		pDC->SetBkColor( m_colorEtiquetas );
		
		return (HBRUSH)m_pincelEtiquetas.GetSafeHandle();
	}
	if( pWnd->GetDlgCtrlID() == IDC_N_BITS2)
	{
		pDC->SetBkColor( m_colorLineas );
		
		return (HBRUSH)m_pincelLineas.GetSafeHandle();
	}
	
	if( pWnd->GetDlgCtrlID() == IDC_N_BITS3)
	{
		pDC->SetBkColor( m_colorPalabras );
		
		return (HBRUSH)m_pincelPalabras.GetSafeHandle();
	}
	
	if( pWnd->GetDlgCtrlID() == IDC_N_BITS4)
	{
		pDC->SetBkColor( m_colorConjuntos );
		
		return (HBRUSH)m_pincelConjuntos.GetSafeHandle();
	}

	if( pWnd->GetDlgCtrlID() == IDC_N_BITS6)
	{
		pDC->SetBkColor( m_colorParche );
		return (HBRUSH)m_pincelParche.GetSafeHandle();
	}
	
	
	//Color de controles edit de muestra

	if( pWnd->GetDlgCtrlID() == IDC_EDIT_COLOR_OCRE)
	{
		pDC->SetBkColor(m_colorEtiquetas);
		return (HBRUSH)m_pincelEtiquetas.GetSafeHandle();
	}

	 if( pWnd->GetDlgCtrlID() == IDC_EDIT_COLOR_NARANJA)
	{
		pDC->SetBkColor(m_colorLineas);
		return (HBRUSH)m_pincelLineas.GetSafeHandle();
	}

	 if( pWnd->GetDlgCtrlID() == IDC_EDIT_COLOR_ROSADO)
	{
		pDC->SetBkColor(m_colorConjuntos);
		return (HBRUSH)m_pincelConjuntos.GetSafeHandle();
	}

	if( pWnd->GetDlgCtrlID() == IDC_EDIT_COLOR_MOSTAZA)
	{
		pDC->SetBkColor(m_colorPalabras);
		return (HBRUSH)m_pincelPalabras.GetSafeHandle();
	}

	
	return hbr;
	
}


void CDireccionDlg::OnChangeDEtiqueta() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
	CString sCantidad;
	GetDlgItemText( IDC_D_ETIQUETA, sCantidad );
	if( sCantidad == "")
	{
		return;
	}
	UpdateData( TRUE );
	
    

	for( int i = 1; i<= m_inEtiquetas; i++)
	{
			
		 	
		if( m_inEtiquetas >= i)
		{
			CRect r(40+5+i*15, 80+20, 40+5+15+i*15, 80+15+20);
			::MapDialogRect( GetSafeHwnd(), &r);
			m_pEtiquetas = new CEdit;
			m_pEtiquetas->Create( WS_CHILD|WS_VISIBLE|WS_DLGFRAME, r, this, IDC_N_BITS1);
		
		   	/*
			m_pEtiquetas->SetFocus();
		    SetDlgItemText(IDC_N_BITS1, "5");
		   	  */
		   /*
		   CEdit *pRespuesta;
		   pRespuesta = (CEdit *) GetDlgItem(IDC_N_BITS1);
		   pRespuesta->SetFocus();
		   SetDlgItemText(IDC_N_BITS1, "5");	
			*/
		}
			
		
	}
		 	


}



			


void CDireccionDlg::OnChangeDLinea() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString sCantidad;
	GetDlgItemText( IDC_D_LINEA, sCantidad );
	if( sCantidad == "")
	{
		return;
	}
	UpdateData( TRUE );
	
    
	int Inicio = m_inEtiquetas; 
	

	for( int i = 1; i<= m_inLineas; i++)
	{
			
	   	if( m_inLineas >= i)
		{
			CRect r(Inicio*15 + 40+5+i*15, 80+20, Inicio*15 +40+5+15+i*15, 80+15+20);
			::MapDialogRect( GetSafeHwnd(), &r);
			m_pLineas = new CEdit;
			m_pLineas->Create( WS_CHILD|WS_VISIBLE|WS_DLGFRAME, r, this, IDC_N_BITS2);
		}
			
		
	}
	
}


void CDireccionDlg::OnChangeDConjunto() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString sCantidad;
	GetDlgItemText( IDC_D_CONJUNTO, sCantidad );
	if( sCantidad == "")
	{
		return;
	}
	UpdateData( TRUE );
	
    
	int Inicio = m_inEtiquetas ;
	/*
	char buffer2[10];
	CString string_i;
	string_i = _itoa( Inicio, buffer2, 10);
	MessageBox(string_i);
	*/

	for( int i = 1; i<= m_inConjuntos; i++)
	{
			
				
		if( m_inConjuntos >= i)
		{
			CRect r(Inicio*15+40+5+i*15, 80+20, Inicio*15+40+5+15+i*15, 80+15+20);
			::MapDialogRect( GetSafeHwnd(), &r);
			m_pConjuntos = new CEdit;
			m_pConjuntos->Create( WS_CHILD|WS_VISIBLE|WS_DLGFRAME, r, this, IDC_N_BITS4);
		}
			
		
	}
	
}


void CDireccionDlg::OnChangeDPalabra() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString sCantidad;
	GetDlgItemText( IDC_D_PALABRA, sCantidad );
	if( sCantidad == "")
	{
		return;
	}
	UpdateData( true );
	
    
	int Inicio = 0;
	
	
	if( m_inLineas > 0 )
	{	
		Inicio = m_inEtiquetas + m_inLineas;
		OnChangeDLinea();
	}
	else
	{
		Inicio = m_inEtiquetas + m_inConjuntos;
		OnChangeDConjunto();
	}
		
	
	

	for( int i = 1; i<= m_inPalabras; i++)
	{
				
		if( m_inPalabras >= i)
		{
			CRect r(Inicio*15+40+5+i*15, 80+20, Inicio*15+40+5+15+i*15, 80+15+20);
			::MapDialogRect( GetSafeHwnd(), &r);
			m_pLineas = new CEdit;
			m_pLineas->Create( WS_CHILD|WS_VISIBLE|WS_DLGFRAME, r, this, IDC_N_BITS3);
		}
			
		
	}
		
}



void CDireccionDlg::OnChangeDTotalBits() 
{
	
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	

	CString sCantidad;
	GetDlgItemText( IDC_D_TOTAL_BITS, sCantidad );
	if( sCantidad == "")
	{
		return;
	}
	UpdateData( TRUE );
	
    char buffer[20];
	CString string_i;

	for( int i = 1; i<= m_iTotalBits; i++)
	{
		//Convierte entero a String	
		string_i = _itoa( i, buffer, 10);	
	
		
		
		if( m_iTotalBits >= i)
		{
			CRect r(40+5+i*15, 95+20, 40+5+15+i*15, 95+15+20);
			::MapDialogRect( GetSafeHwnd(), &r);
			m_pnBits = new CButton;
			m_pnBits->Create( string_i, WS_CHILD|WS_VISIBLE|WS_TABSTOP, r, this, IDC_N_BITS5);
		}
			
		
	}
		 	
}

	



int CDireccionDlg::ConvertBase2(int num)
{
	int i;
	
	for( i = 0; i<num; i++)
	{
		if( pow(2, i) == num )
			break;
	}
	
	return i;
}


void CDireccionDlg::Parche()
{
   CRect r(60, 78+5, 282+60-12, 126+5);
   ::MapDialogRect( GetSafeHwnd(), &r);
   m_pParche = new CEdit;
   m_pParche->Create( WS_CHILD|WS_VISIBLE |WS_DISABLED, r, this, IDC_N_BITS6);
   //m_pParche->Create( WS_CHILD|WS_VISIBLE|WS_DLGFRAME, r, this, IDC_N_BITS6); 
}

void CDireccionDlg::OnChangeEditDireccion() 
{
		
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	//CCache2003View dlgCache;
	
	CString sDir;
	GetDlgItemText( IDC_EDIT_DIRECCION, sDir );
	if( sDir == "")
	{
		return;
	}
	UpdateData( TRUE );
	
   	CString n_binario;
	
	
	for( int i = 1; i<= m_iTotalBits; i++)
	{
		 		  		 
			n_binario = m_sDireccion[i-1];
		
				if( m_iTotalBits >= i)
				{
					CRect r(40+5+i*15, 65+20, 40+5+15+i*15, 65+15+20);
					::MapDialogRect( GetSafeHwnd(), &r);
					m_pDireccion = new CButton;
					m_pDireccion->Create( n_binario, WS_CHILD|WS_VISIBLE|WS_TABSTOP, r, this, IDC_N_BITS7);
				}
			
		
	}

 
}

