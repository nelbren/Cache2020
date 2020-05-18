// EstadisticasDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Cache2003.h"
#include "TiemposDlg.h"
#include "EscrituraDlg.h"
#include "EstadisticasDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEstadisticasDlg dialog


CEstadisticasDlg::CEstadisticasDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEstadisticasDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEstadisticasDlg)
	m_iAciertos = 0;
	m_iFallos = 0;
	m_iSimulaciones = 0;
	m_iBasico = 0;
	m_iParalelo = 0;
	m_fTc = 0.0f;
	m_fTp = 0.0f;
	m_nEscrituras = 0;
	m_fTasaPenaliza = 0.0f;
	m_fTasaFallos = 0.0f;
	m_fTasaAciertos = 0.0f;
	m_fTAccesoMedio = 0.0f;
	m_fProb_Modificado = 0.0f;
	m_fPor_Esc = 0.0f;
	m_fPor_Lect = 0.0f;
	m_iAsignacion = 0;
	m_iTip_Esc = 0;
	m_in_Bloques_MP = 0;
	m_fTa = 0.0f;
	m_Tam_MP = 0;
	m_fTacierto = 0.0f;
	//}}AFX_DATA_INIT
}


void CEstadisticasDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEstadisticasDlg)
	DDX_Control(pDX, IDC_MSCHART, m_CtrlChart);
	DDX_Text(pDX, IDC_EDIT_ACIERTOS, m_iAciertos);
	DDX_Text(pDX, IDC_EDIT_FALLOS, m_iFallos);
	DDX_Text(pDX, IDC_EDIT_SIMULACIONES, m_iSimulaciones);
	DDX_Text(pDX, IDC_EDIT_T_BASICO, m_iBasico);
	DDX_Text(pDX, IDC_EDIT_T_PARALELO, m_iParalelo);
	DDX_Text(pDX, IDC_EDIT_T_TC, m_fTc);
	DDX_Text(pDX, IDC_EDIT_T_TP, m_fTp);
	DDX_Text(pDX, IDC_EDIT_N_ESC, m_nEscrituras);
	DDX_Text(pDX, IDC_EDIT_TASA_PENALIZACION, m_fTasaPenaliza);
	DDX_Text(pDX, IDC_EDIT_TASA_FALLOS, m_fTasaFallos);
	DDX_Text(pDX, IDC_EDIT_TASA_ACIERTOS, m_fTasaAciertos);
	DDX_Text(pDX, IDC_EDIT_TMA, m_fTAccesoMedio);
	DDX_Text(pDX, IDC_EDIT_PROB_MOD, m_fProb_Modificado);
	DDX_Text(pDX, IDC_EDIT_POR_ESCRITURA, m_fPor_Esc);
	DDX_Text(pDX, IDC_EDIT_POR_LECTURA, m_fPor_Lect);
	DDX_Text(pDX, IDC_EDIT_ASIGNACION, m_iAsignacion);
	DDX_Text(pDX, IDC_EDIT_TIPO_ESC, m_iTip_Esc);
	DDX_Text(pDX, IDC_EDIT_N_BLOQUES_MP, m_in_Bloques_MP);
	DDX_Text(pDX, IDC_EDIT_TACCESO, m_fTa);
	DDX_Text(pDX, IDC_EDIT_TAM_MP, m_Tam_MP);
	DDX_Text(pDX, IDC_EDIT_T_ACIERTO, m_fTacierto);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEstadisticasDlg, CDialog)
	//{{AFX_MSG_MAP(CEstadisticasDlg)
	ON_EN_CHANGE(IDC_EDIT_ACIERTOS, OnChangeEditAciertos)
	ON_EN_CHANGE(IDC_EDIT_FALLOS, OnChangeEditFallos)
	ON_EN_CHANGE(IDC_EDIT_SIMULACIONES, OnChangeEditSimulaciones)
	ON_EN_CHANGE(IDC_EDIT_N_ESC, OnChangeEditNEsc)
	ON_BN_CLICKED(IDC_B_DETALLES, OnBDetalles)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEstadisticasDlg message handlers

void CEstadisticasDlg::OnChangeEditAciertos() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	COleSafeArray  arreglo;
	DWORD num_elementos[] = {1, 3};

	arreglo.Create( VT_R8, 2, num_elementos);

	
	long indice[2];
	double val;
	
	
	
	for( indice[0] = 0; indice[0]<1; indice[0]++ )
	{
		
		for( indice[1]= 0; indice[1]<3; indice[1]++)
		{
			if( indice[1] == 0)
			{
				UpdateData( true );
				val = m_iFallos;
				arreglo.PutElement(indice, &val);
			}
			if( indice[1] == 1)
			{
			   	UpdateData( true);
				val = m_iAciertos;
				arreglo.PutElement(indice, &val);
			}
			if( indice[1] == 3)
			{
			   	UpdateData( true);
				val = m_iSimulaciones;
				arreglo.PutElement(indice, &val);
			}
		}
	}
	
		
	
	m_CtrlChart.SetChartData(arreglo.Detach());
	//m_CtrlChart.Refresh;
}

void CEstadisticasDlg::OnChangeEditFallos() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	COleSafeArray  arreglo;
	DWORD num_elementos[] = {1, 3};

	arreglo.Create( VT_R8, 2, num_elementos);

	
	long indice[2];
	double val;
	
	
	
	for( indice[0] = 0; indice[0]<1; indice[0]++ )
	{
		
		for( indice[1]= 0; indice[1]<3; indice[1]++)
		{
			if( indice[1] == 0)
			{
				UpdateData( true );
				val = m_iFallos;
				arreglo.PutElement(indice, &val);
			}
			if( indice[1] == 1)
			{
			   	UpdateData( true);
				val = m_iAciertos;
				arreglo.PutElement(indice, &val);
			}
			if( indice[1] == 2)
			{
			   	UpdateData( true);
				val = m_iSimulaciones;
				arreglo.PutElement(indice, &val);
			}
		}
	}
	
		
	
	m_CtrlChart.SetChartData(arreglo.Detach());
	m_CtrlChart.Refresh();
}

BOOL CEstadisticasDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	

	m_colorMarcos = RGB(128, 128, 128);
	m_pincelMarcos.CreateSolidBrush( m_colorMarcos );
	m_colorEdit = RGB(0, 0, 255);
	m_colorTextos = RGB( 128, 128, 192);

		//Oculta los static
		GetDlgItem(IDC_STATIC_ACIERTOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_FALLOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TOTAL) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TASA_ACIERTOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TASA_FALLOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TASA_PENALIZA) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_LECT) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_ESC) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TACCESO) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TACCESO_MEDIO) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_PROB_MOD) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TACIERTO) -> ShowWindow(FALSE);
		//Oculta los Edit
		GetDlgItem(IDC_EDIT_ACIERTOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_FALLOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_SIMULACIONES) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TASA_ACIERTOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TASA_FALLOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TASA_PENALIZACION) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_POR_LECTURA) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_POR_ESCRITURA) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TACCESO) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TMA) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_PROB_MOD) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_T_ACIERTO) -> ShowWindow(FALSE);

		//Oculta marcos
		GetDlgItem(IDC_STATIC_INFORME) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TASAS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TIEMPOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_PORCENTAJES) -> ShowWindow(FALSE);
		


//Genera Gráfica		
	COleSafeArray  arreglo;
	DWORD num_elementos[] = {1, 3};

	arreglo.Create( VT_R8, 2, num_elementos);

	
	long indice[2];
	double val;
	
	
	
	for( indice[0] = 0; indice[0]<1; indice[0]++ )
	{
		
		for( indice[1]= 0; indice[1]<3; indice[1]++)
		{
			if( indice[1] == 0)
			{
				UpdateData( true );
				val = m_iFallos;
				arreglo.PutElement(indice, &val);
			}
			if( indice[1] == 1)
			{
			   	UpdateData( true);
				val = m_iAciertos;
				arreglo.PutElement(indice, &val);
			}
			if( indice[1] == 2)
			{
			   	UpdateData( true);
				val = m_iSimulaciones;
				arreglo.PutElement(indice, &val);
			}
		}
	}
	
		
	
	m_CtrlChart.SetChartData(arreglo.Detach());
	m_CtrlChart.Refresh();
	// TODO: Add extra initialization here

	CalculoTa_Stats();	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEstadisticasDlg::OnChangeEditSimulaciones() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	COleSafeArray  arreglo;
	DWORD num_elementos[] = {1, 3};

	arreglo.Create( VT_R8, 2, num_elementos);

	
	long indice[2];
	double val;
	
	
	
	for( indice[0] = 0; indice[0]<1; indice[0]++ )
	{
		
		for( indice[1]= 0; indice[1]<3; indice[1]++)
		{
			if( indice[1] == 0)
			{
				UpdateData( true );
				val = m_iFallos;
				arreglo.PutElement(indice, &val);
			}
			if( indice[1] == 1)
			{
			   	UpdateData( true);
				val = m_iAciertos;
				arreglo.PutElement(indice, &val);
			}
			if( indice[1] == 2)
			{
			   	UpdateData( true);
				val = m_iSimulaciones;
				arreglo.PutElement(indice, &val);
			}
		}
	}
	
		
	
	m_CtrlChart.SetChartData(arreglo.Detach());
	m_CtrlChart.Refresh();
}

void CEstadisticasDlg::CalculoTa_Stats()
{
	CTiemposDlg dlgTiempos;
    CEscrituraDlg dlgEscritura;
	float Tacierto = 0;	
	float TFallo = 0;
	float TasaAcierto = 0;
	float TasaFallo = 0;
	float Tpenalizacion = 0;
    float Porcentaje_Esc = 0;
	float Porcentaje_Lect = 0;
	float Prob_modificado = 0;
	float Tacceso = 0;
	
	
	/*
	char buffer[5];
	CString s_float;
	s_float = _gcvt(m_fTa, 2, buffer);
	MessageBox("Ta = " + s_float); 
	  */
			UpdateData(true);
			m_fPor_Esc = Porcentaje_Esc;
			m_fPor_Lect = Porcentaje_Lect;
			m_fProb_Modificado = Prob_modificado;
			m_fTasaFallos =  TasaFallo;
			m_fTasaAciertos = TasaAcierto;
			m_fTasaPenaliza = Tpenalizacion;
			m_fTacierto = Tacierto;
			UpdateData(false);		
	/*
	char buff[10];
	CString s_Tam_MP;
	s_Tam_MP = _itoa( m_Tam_MP, buff, 10);
	MessageBox("tamMP " + s_Tam_MP );
	  */

	Tpenalizacion = m_fTp;


	if( m_iSimulaciones>0)
	{
			
			Porcentaje_Esc = (float)m_nEscrituras/m_Tam_MP;
			Porcentaje_Lect = 1- Porcentaje_Esc;
			Prob_modificado = (float)1/m_in_Bloques_MP;
			TasaFallo =  (float)m_iFallos/m_iSimulaciones;
			TasaAcierto = (float)m_iAciertos/m_iSimulaciones;

		
	   switch(m_iBasico)
	   {
	   case 0:
		   
		   if(m_iParalelo == 0)
		   {
			   Tacceso = m_iAciertos*m_fTc + m_iFallos*m_fTp;
			   Tacierto = TasaAcierto*m_fTc;	
			   m_fTAccesoMedio = Tacierto + TasaFallo*Tpenalizacion;
		   	   m_fTa = Tacceso;
			   m_fTacierto = Tacierto;
			   UpdateData(false);
			   
			   
		   }
	   	   else
		   {
			   Tacceso = m_fTc + m_iFallos*m_fTp;
			   Tacierto = m_fTc;
			   m_fTAccesoMedio = Tacierto + TasaFallo*Tpenalizacion;
		   	   m_fTa = Tacceso;
			   m_fTacierto = Tacierto;
			   UpdateData(false);
		   }
	   break;   
	   case 1:
		   
		   
		   if(m_iParalelo == 0)
		   {
			   Tacceso = m_iAciertos*m_fTc + m_iFallos*m_fTp;
			   Tacierto = TasaAcierto*m_fTc;
			   
			   switch(m_iTip_Esc)
			   {
			   case 0:
				   if(m_iAsignacion == 0)
				   {
					   //Con asignación en escritura
					   m_fTAccesoMedio = Tacierto + TasaFallo*Tpenalizacion + Porcentaje_Esc*(m_fTp - m_fTc);
				   	   m_fTa = Tacceso;
					   m_fTacierto = Tacierto;
					   UpdateData(false);
				   }
				   else
				   {
					   //Sin asignación en escritura
					  m_fTAccesoMedio = Tacierto + TasaFallo*Tpenalizacion + Porcentaje_Lect*(m_fTp- m_fTc);
				      m_fTa = Tacceso;
					  m_fTacierto = Tacierto;
					  UpdateData(false);
				   }	 
				break;
			   case 1:
					  m_fTAccesoMedio = Tacierto + TasaFallo*Tpenalizacion + Prob_modificado*TasaFallo*Tpenalizacion;
					  m_fTa = Tacceso;
					  m_fTacierto = Tacierto;
					  UpdateData(false);
				break;
			   } //fin del switch
		   } //fin del if
		   else
		   {
			   Tacceso = m_fTc + m_iFallos*m_fTp;
			   Tacierto = m_fTc;

		   	   switch(m_iTip_Esc)
			   {
			   case 0:
				   if(m_iAsignacion == 0)
				   {
					   //Con asignación en escritura
					   m_fTAccesoMedio = Tacierto + TasaFallo*Tpenalizacion + Porcentaje_Esc*(m_fTp - m_fTc);
				   	   m_fTa = Tacceso;
					   m_fTacierto = Tacierto;
					   UpdateData(false);
				   }
				   else
				   {
					   //Sin asignación en escritura
					  m_fTAccesoMedio = Tacierto + TasaFallo*Tpenalizacion + Porcentaje_Lect*(m_fTp- m_fTc);
				      m_fTa = Tacceso;
					  m_fTacierto = Tacierto;
					  UpdateData(false);
				   }	 
				break;
			   case 1:
					  m_fTAccesoMedio = Tacierto + TasaFallo*Tpenalizacion + Prob_modificado*TasaFallo*Tpenalizacion;
					  m_fTa = Tacceso;
					  m_fTacierto = Tacierto;
					  UpdateData(false);
				break;
			   }//fin del switch
		   		   
		   }//fin del else

		   break;
	   }//fin del switch m_Basica
	
			m_fPor_Esc = Porcentaje_Esc;
			m_fPor_Lect = Porcentaje_Lect;
			m_fProb_Modificado = Prob_modificado;
			m_fTasaFallos =  TasaFallo;
			m_fTasaAciertos = TasaAcierto;
			m_fTasaPenaliza = Tpenalizacion;
			UpdateData(false);	



	}//fin del if >0
			
				

			

}

void CEstadisticasDlg::OnChangeEditNEsc() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CEstadisticasDlg::OnBDetalles() 
{
	// TODO: Add your control notification handler code here
	
	int tamCadena;
	char buf[20];
	tamCadena = GetDlgItemText(IDC_B_DETALLES, buf, 20);
	
	CalculoTa_Stats();
	if( tamCadena == 12) 
	{
		//Muestra los static
		GetDlgItem(IDC_STATIC_ACIERTOS) -> ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_FALLOS) -> ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_TOTAL) -> ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_TASA_ACIERTOS) -> ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_TASA_FALLOS) -> ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_TASA_PENALIZA) -> ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_LECT) -> ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_ESC) -> ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_TACCESO) -> ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_TACCESO_MEDIO) -> ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_PROB_MOD) -> ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_TACIERTO) -> ShowWindow(TRUE);
		
		//Muestra los Edit
		GetDlgItem(IDC_EDIT_ACIERTOS) -> ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_FALLOS) -> ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_SIMULACIONES) -> ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_TASA_ACIERTOS) -> ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_TASA_FALLOS) -> ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_TASA_PENALIZACION) -> ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_POR_LECTURA) -> ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_POR_ESCRITURA) -> ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_TACCESO) -> ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_TMA) -> ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_PROB_MOD) -> ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_T_ACIERTO) -> ShowWindow(TRUE);

		//Muestra marcos
		GetDlgItem(IDC_STATIC_INFORME) -> ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_TASAS) -> ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_TIEMPOS) -> ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_PORCENTAJES) -> ShowWindow(TRUE);

		SetDlgItemText(IDC_B_DETALLES, "Ocultar Detalles");
	}
	else
	{
		//Oculta los static
		GetDlgItem(IDC_STATIC_ACIERTOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_FALLOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TOTAL) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TASA_ACIERTOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TASA_FALLOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TASA_PENALIZA) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_LECT) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_ESC) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TACCESO) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TACCESO_MEDIO) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_PROB_MOD) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TACIERTO) -> ShowWindow(FALSE);
		//Oculta los Edit
		GetDlgItem(IDC_EDIT_ACIERTOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_FALLOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_SIMULACIONES) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TASA_ACIERTOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TASA_FALLOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TASA_PENALIZACION) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_POR_LECTURA) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_POR_ESCRITURA) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TACCESO) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TMA) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_PROB_MOD) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_T_ACIERTO) -> ShowWindow(FALSE);

		//Oculta marcos
		GetDlgItem(IDC_STATIC_INFORME) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TASAS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TIEMPOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_PORCENTAJES) -> ShowWindow(FALSE);
		
		SetDlgItemText(IDC_B_DETALLES, "Ver Detalles");

	}

	
}

void CEstadisticasDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();

		//Oculta los static
		GetDlgItem(IDC_STATIC_ACIERTOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_FALLOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TOTAL) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TASA_ACIERTOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TASA_FALLOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TASA_PENALIZA) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_LECT) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_ESC) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TACCESO) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TACCESO_MEDIO) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_PROB_MOD) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TACIERTO) -> ShowWindow(FALSE);
		//Oculta los Edit
		GetDlgItem(IDC_EDIT_ACIERTOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_FALLOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_SIMULACIONES) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TASA_ACIERTOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TASA_FALLOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TASA_PENALIZACION) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_POR_LECTURA) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_POR_ESCRITURA) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TACCESO) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TMA) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_PROB_MOD) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_T_ACIERTO) -> ShowWindow(FALSE);

		//Oculta marcos
		GetDlgItem(IDC_STATIC_INFORME) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TASAS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TIEMPOS) -> ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_PORCENTAJES) -> ShowWindow(FALSE);
		
		SetDlgItemText(IDC_B_DETALLES, "Ver Detalles");

		

}

HBRUSH CEstadisticasDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	//Marcos
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_INFORME)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_TASAS)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_TIEMPOS)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_PORCENTAJES)
	{
		pDC->SetTextColor(m_colorTextos);
		//pDC->SetBkColor(m_colorMarcos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();

	}
	
	//Colorea texto edit
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_FALLOS)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_ACIERTOS)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_SIMULACIONES)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_TASA_FALLOS)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_TASA_ACIERTOS)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_PROB_MOD)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_POR_LECTURA)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_POR_ESCRITURA)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_TACCESO)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_TMA)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_TASA_PENALIZACION)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_T_ACIERTO)
	{
		pDC->SetTextColor(m_colorEdit);
		
	}





	// TODO: Return a different brush if the default is not desired
	return hbr;
}
