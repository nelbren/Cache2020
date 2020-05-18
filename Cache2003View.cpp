// Cache2003View.cpp : implementation of the CCache2003View class
//

#include "stdafx.h"
#include "Cache2003.h"

#include "Datos.h"
#include "Secuencia.h"
#include "Parametros.h"

#include "SimulacionDlg.h"
#include "MemoriasDlg.h"
#include "DireccionDlg.h"
#include "PoliticasDlg.h"
#include "EscrituraDlg.h"
#include "TiemposDlg.h"
#include "EstadisticasDlg.h"
#include "DatosDlg.h"
#include "BuscarDlg.h"
#include "ColoresDlg.h"
#include "Cache2003Doc.h"
#include "Cache2003View.h"

#include "MainFrm.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCache2003View

IMPLEMENT_DYNCREATE(CCache2003View, CFormView)

BEGIN_MESSAGE_MAP(CCache2003View, CFormView)
	//{{AFX_MSG_MAP(CCache2003View)
	ON_COMMAND(ID_CONFIGURACION_MEMORIAS, OnConfiguracionMemorias)
	ON_COMMAND(ID_VER_DIRECCINDEMEMORIA, OnVerDireccindememoria)
	ON_COMMAND(ID_CONFIGURAR_POLTICAS, OnConfigurarPolticas)
	ON_COMMAND(ID_FORMAT_BINARIO, OnFormatoDatos)
	ON_BN_CLICKED(IDC_SIMULAR, OnSimular)
	ON_BN_CLICKED(IDC_CHECK_L_E, OnCheckLE)
	ON_BN_CLICKED(IDC_CHECK_CONT, OnCheckCont)
	ON_BN_CLICKED(IDC_BTN_LLENAR_MP, OnBtnLlenarMp)
	ON_BN_CLICKED(IDC_CHECK_EDAD, OnCheckEdad)
	ON_BN_CLICKED(IDC_CHECK_FREC, OnCheckFrec)
	ON_COMMAND(ID_CONFIGURAR_ACTUALIZA, OnConfigurarActualiza)
	ON_COMMAND(ID_CONFIGURAR_TIEMPOSACCESO, OnConfigurarTiemposacceso)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_VER_DIRECCINDEMEMORIA, OnUpdateVerDireccindememoria)
	ON_UPDATE_COMMAND_UI(IDD_CONTADOR_LINEAS, OnUpdateContadorLineas)
	ON_UPDATE_COMMAND_UI(IDD_TIPO_DATO_MP, OnUpdateTipoDato)
	ON_COMMAND(IDD_CONTADOR_LINEAS, OnContadorLineas)
	ON_COMMAND(IDD_TIPO_DATO_MP, OnTipoDato)
	ON_UPDATE_COMMAND_UI(IDD_TIPO_DATO_MC, OnUpdateTipoDatoMc)
	ON_COMMAND(IDD_TIPO_DATO_MC, OnTipoDatoMc)
	ON_COMMAND(ID_VER_INFORMEDESIMULACIN, OnVerInformedesimulacin)
	ON_UPDATE_COMMAND_UI(ID_VER_INFORMEDESIMULACIN, OnUpdateVerInformedesimulacin)
	ON_COMMAND(ID_INSERTAR_DATOS_MP, OnInsertarDatosMp)
	ON_EN_CHANGE(IDC_DATOSDLG_DIRECCION, OnChangeDatosdlgDireccion)
	ON_EN_CHANGE(IDC_DATOSDLG_DAT, OnChangeDatosdlgDat)
	ON_EN_CHANGE(IDC_DATOSDLG_TIP, OnChangeDatosdlgTip)
	ON_BN_CLICKED(IDC_B_PRIMERO, OnBPrimero)
	ON_BN_CLICKED(IDC_B_ULTIMO, OnBUltimo)
	ON_BN_CLICKED(IDC_B_ANTERIOR, OnBAnterior)
	ON_BN_CLICKED(IDC_B_SIGUIENTE, OnBSiguiente)
	ON_BN_CLICKED(IDC_B_AGREGAR, OnBAgregar)
	ON_BN_CLICKED(IDC_RADIO_ESC, OnRadioEsc)
	ON_BN_CLICKED(IDC_RADIO_LECT, OnRadioLect)
	ON_BN_CLICKED(IDC_B_EDITAR, OnBEditar)
	ON_BN_CLICKED(IDC_B_BUSCAR, OnBBuscar)
	ON_EN_CHANGE(IDC_EDIT_SECUENCIA, OnChangeEditSecuencia)
	ON_EN_CHANGE(IDC_EDIT_DIR_SEC, OnChangeEditDirSec)
	ON_BN_CLICKED(IDC_B_AGREGAR_SEC, OnBAgregarSec)
	ON_BN_CLICKED(IDC_B_EDITAR_SEC, OnBEditarSec)
	ON_BN_CLICKED(IDC_B_PRIMERO_SEC, OnBPrimeroSec)
	ON_BN_CLICKED(IDC_B_ANTERIOR_SEC, OnBAnteriorSec)
	ON_BN_CLICKED(IDC_B_SIGUIENTE_SEC, OnBSiguienteSec)
	ON_BN_CLICKED(IDC_B_ULTIMO_SEC, OnBUltimoSec)
	ON_COMMAND(ID_CONFIGURACION_SIMULACION, OnConfiguracionSimulacion)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_COMMAND(ID_FILE_PRINT_SEC, OnFilePrintSec)
	ON_WM_CTLCOLOR()
	ON_COMMAND(ID_SIMBOLOGIA, OnSimbologia)
	ON_UPDATE_COMMAND_UI(ID_SIMBOLOGIA, OnUpdateSimbologia)
	ON_COMMAND(ID_FORMAT_DECIMAL, OnFormatoDatos)
	ON_COMMAND(ID_FORMAT_HEXADECIMAL, OnFormatoDatos)
	ON_COMMAND(ID_FORMAT_OCTAL, OnFormatoDatos)
	ON_COMMAND(ID_HELP_CACHE2003, OnHelpCache2003)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCache2003View construction/destruction

CCache2003View::CCache2003View()
	: CFormView(CCache2003View::IDD)
{
	//{{AFX_DATA_INIT(CCache2003View)
	m_nMP = 0;
	m_nMC = 0;
	m_nBloque = 0;
	m_nVias = "2";
	m_iP_Emplazamiento = 1;
	m_iP_Reemplazamiento = 0;
	m_Dato = _T("");
	m_NPalabra = _T("");
	m_NBloque = _T("");
	m_NLinea = _T("");
	m_TamConjunto = 0;
	m_NPalabraBloque = _T("");
	m_PalabraConjunto = 0;
	m_TamMP = 0;
	m_TamBloque = 0;
	m_TamMC = 0;
	m_contAciertos = 0;
	m_contFallos = 0;
	m_nSim = 0;
	m_in_Bloques_MC = 0;
	m_in_Bloques_MP = 0;
	m_iw = 0;
	m_ini_Linea = -1;
	m_bChk_LectEsc = FALSE;
	m_bChk_Cont = FALSE;
	m_nBloqueConjunto = 0;
	m_NConjunto = _T("");
	m_nLineaConjunto = _T("");
	m_bChk_Edad = FALSE;
	m_bChk_Frec = FALSE;
	m_sMet_Emplaza = _T("");
	m_sMet_Reemplaza = _T("");
	m_iTip_Esc = 0;
	m_iAsignacion = 0;
	m_Dato_Escrito = _T("");
	m_iTipo_Dato = 0;
	m_sTipo = _T("");
	m_sDireccion = "0";
	m_sDato = _T("");
	m_iTipo = 1;
	m_sPosicion = _T("");
	m_iReg = 0;
	m_iLectura = 0;
	m_sSecuencia = "1";
	m_sDirSecuencia = _T("");
	m_sPosicionSec = _T("");
	m_iSec = 1;
	m_iAutomatico_Sec = 0;
	m_iAutomatico = 0;
	m_inSec = 20;
	m_iBasico = 0;
	m_iParalelo = 0;
	m_fTc = 0.0f;
	m_fTp = 0.0f;
	m_fTa = 0.0f;
	m_ppMP = NULL; 
	m_arrayDatosMPPtr =NULL;
	m_arrayDirMPPtr = NULL;
	m_arrayDatosMCPtr =NULL;
	m_arrayDirMCPtr = NULL;
	m_arrayTipoMPPtr =NULL;
	m_arrayTipoMCPtr = NULL;
	m_nEscrituras = 0;
	//}}AFX_DATA_INIT
	// TODO: add construction code here
   
   int m_niMP = 0;
   int m_niMC = 0;
   int m_niBloque = 0;
   
}

CCache2003View::~CCache2003View()
{
	
	//delete m_pDlgDireccion;
	/*
	if( (m_dlgDireccion.m_pEtiquetas ) || ( m_dlgDireccion.m_pLineas ) || (m_dlgDireccion.m_pPalabras) || (m_dlgDireccion.m_pnBits ))
	{
	  delete m_dlgDireccion.m_pEtiquetas;
	  delete m_dlgDireccion.m_pLineas;
	  delete m_dlgDireccion.m_pPalabras;
	  delete m_dlgDireccion.m_pnBits;	
	}

	 */
	
	if(m_ppMP )
	{
		for( int Fila = 0; Fila <= m_Fila; Fila++)
		{
			delete m_ppMP[Fila];
		}
		delete m_ppMP;
	}

	 /*
	 delete m_arrayDirMPPtr;
     delete m_arrayDatosMPPtr;
	 delete m_arrayTipoMPPtr;
	 delete m_arrayDirMCPtr;
	 delete m_arrayDatosMCPtr;
	 delete m_arrayTipoMCPtr
	*/
}

void CCache2003View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCache2003View)
	DDX_Control(pDX, IDC_REJILLA_MP, m_CtrlRejilla_MP);
	DDX_Text(pDX, IDC_N_MP, m_nMP);
	DDX_Control(pDX, IDC_REJILLA_MC, m_CtrlRejilla_MC);
	DDX_Text(pDX, IDC_N_MC, m_nMC);
	DDX_Text(pDX, IDC_N_BLOQUE, m_nBloque);
	DDX_Text(pDX, IDC_N_VIAS, m_nVias);
	DDX_Text(pDX, IDC_P_EMPLAZAMIENTO, m_iP_Emplazamiento);
	DDX_Text(pDX, IDC_P_REMPLAZAMIENTO, m_iP_Reemplazamiento);
	DDX_Text(pDX, IDC_EDIT_DATO, m_Dato);
	DDX_Text(pDX, IDC_EDIT_PALABRA, m_NPalabra);
	DDX_Text(pDX, IDC_EDIT_BLOQUE, m_NBloque);
	DDX_Text(pDX, IDC_EDIT_LINEA, m_NLinea);
	DDX_Text(pDX, IDC_EDIT_N_CONJ, m_TamConjunto);
	DDX_Text(pDX, IDC_EDIT_PALABRA_BLOQUE, m_NPalabraBloque);
	DDX_Text(pDX, IDC_EDIT_PALABRAS_CONJ, m_PalabraConjunto);
	DDX_Text(pDX, IDC_N_FILAS_MP, m_TamMP);
	DDX_Text(pDX, IDC_N_FILAS_BLOQUE, m_TamBloque);
	DDX_Text(pDX, IDC_N_FILAS_MC, m_TamMC);
	DDX_Text(pDX, IDC_EDIT_ACIERTOS, m_contAciertos);
	DDX_Text(pDX, IDC_EDIT_FALLOS, m_contFallos);
	DDX_Text(pDX, IDC_EDIT_SIMULACIONES, m_nSim);
	DDX_Text(pDX, IDC_EDIT_BLOQUES_MC, m_in_Bloques_MC);
	DDX_Text(pDX, IDC_EDIT_BLOQUES_MP, m_in_Bloques_MP);
	DDX_Text(pDX, IDC_EDIT_W, m_iw);
	DDX_Text(pDX, IDC_EDIT_INI_LINEA, m_ini_Linea);
	DDX_Check(pDX, IDC_CHECK_L_E, m_bChk_LectEsc);
	DDX_Check(pDX, IDC_CHECK_CONT, m_bChk_Cont);
	DDX_Text(pDX, IDC_EDIT_N_BLOQUES_CONJ, m_nBloqueConjunto);
	DDX_Text(pDX, IDC_EDIT_CONJ, m_NConjunto);
	DDX_Text(pDX, IDC_EDIT_N_LINEAS, m_nLineaConjunto);
	DDX_Check(pDX, IDC_CHECK_EDAD, m_bChk_Edad);
	DDX_Check(pDX, IDC_CHECK_FREC, m_bChk_Frec);
	DDX_Text(pDX, IDC_EDIT_MET_EMPLAZA, m_sMet_Emplaza);
	DDX_Text(pDX, IDC_EDIT_MET_REEMPLAZA, m_sMet_Reemplaza);
	DDX_Text(pDX, IDC_EDIT_TIP_ESC, m_iTip_Esc);
	DDX_Text(pDX, IDC_EDIT_ASIGNACION, m_iAsignacion);
	DDX_Text(pDX, IDC_EDIT_DATO_MC, m_Dato_Escrito);
	DDX_Text(pDX, IDC_EDIT_TIPO_DATO, m_iTipo_Dato);
	DDX_Text(pDX, IDC_EDIT_TIPO, m_sTipo);
	DDX_Text(pDX, IDC_DATOSDLG_DIRECCION, m_sDireccion);
	DDX_Text(pDX, IDC_DATOSDLG_DAT, m_sDato);
	DDV_MaxChars(pDX, m_sDato, 4);
	DDX_Text(pDX, IDC_DATOSDLG_TIP, m_iTipo);
	DDX_Text(pDX, IDC_STATIC_POSICION, m_sPosicion);
	DDX_Text(pDX, IDC_EDIT_REG, m_iReg);
	DDX_Radio(pDX, IDC_RADIO_LECT, m_iLectura);
	DDX_Text(pDX, IDC_EDIT_SECUENCIA, m_sSecuencia);
	DDX_Text(pDX, IDC_EDIT_DIR_SEC, m_sDirSecuencia);
	DDV_MaxChars(pDX, m_sDirSecuencia, 6);
	DDX_Text(pDX, IDC_STATIC_REG_SEC, m_sPosicionSec);
	DDX_Text(pDX, IDC_EDIT_SEC, m_iSec);
	DDX_Text(pDX, IDC_EDIT_AUTOMATICO_SEC, m_iAutomatico_Sec);
	DDX_Text(pDX, IDC_EDIT_AUTOMATICO, m_iAutomatico);
	DDX_Text(pDX, IDC_N_SECUENCIAS, m_inSec);
	DDX_Text(pDX, IDC_EDIT_T_BASICO, m_iBasico);
	DDX_Text(pDX, IDC_EDIT_T_PARALELO, m_iParalelo);
	DDX_Text(pDX, IDC_EDIT_T_TC, m_fTc);
	DDX_Text(pDX, IDC_EDIT_T_TP, m_fTp);
	DDX_Text(pDX, IDC_EDIT_TA, m_fTa);
	DDX_Text(pDX, IDC_EDIT_N_ESCRITURAS, m_nEscrituras);
	//}}AFX_DATA_MAP
}

BOOL CCache2003View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	/*
	if(!CCache2003View::PreCreateWindow(cs))
	{
		return FALSE;
	}

	cs.lpszClass = AfxRegisterWndClass(CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW,
		AfxGetApp()->LoadCursor(IDC_ARROW), ::CreateSolidBrush(RGB(255, 0, 0)));
	
	if( cs.lpszClass != NULL )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

	*/
	
	m_dlgDireccion.Create( IDD_DIRECCION_DLG, this);
	m_dlgEstadisticas.Create( IDD_ESTADISTICAS_DLG, this);
	m_dlgColores.Create( IDD_COLORES_DLG, this);

	m_dlgDireccion.ShowWindow( SW_SHOW );
	

	return CFormView::PreCreateWindow(cs);
}

void CCache2003View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit(true);
	
		
	((CEdit *)GetDlgItem(IDC_DATOSDLG_DAT))->SetFocus();

	
	m_IdFormatoDato = ID_FORMAT_BINARIO;
	CWnd *pVentanaPadre = GetParent();
	CMenu *pMenu  = pVentanaPadre->GetMenu();
	pMenu->CheckMenuItem(m_IdFormatoDato, MF_CHECKED | MF_BYCOMMAND );
	
		
	m_colorMarcos = RGB(0, 0,  160);
	m_colorAcierto = RGB(0, 255, 0);
	m_colorFallo = RGB( 255, 0, 0);
	m_colorTextos = RGB(128, 128, 192);
	m_colorTextoStatic = RGB(0, 0, 0);	 
	m_colorTextoEdit = RGB(0, 0, 255);
	
	/*
	CBrush m_pincelMarcos, m_pincelAcierto, m_pincelFallo;

	m_pincelMarcos.CreateSolidBrush( m_colorMarcos );
	m_pincelAcierto.CreateSolidBrush( m_colorAcierto );
	m_pincelFallo.CreateSolidBrush( m_colorFallo );
	  */
	

	//Puntero a la barra de estados
	CWnd *pMainWnd = AfxGetApp()->m_pMainWnd;
	CStatusBar *pStatusBar = (CStatusBar *)pMainWnd->GetDescendantWindow(AFX_IDW_STATUS_BAR);
	char str[30];
	
	switch(m_iTip_Esc)
	{
		case 0:
		//MessageBox("Politica de Actualización : Escritura Directa");
		wsprintf(str, "ESCRITURA DIRECTA");
		pStatusBar->SetPaneText(2, str);
		if( m_iAsignacion == 0)
		{
				//MessageBox("Con Asiganción en Escritura");
				wsprintf(str, "CON ASIG");
				pStatusBar->SetPaneText(3, str);
		}
		if( m_iAsignacion == 1)
		{
				//MessageBox("Sin Asiganción en Escritura");
				wsprintf(str, "SIN ASIG");
				pStatusBar->SetPaneText(3, str);
		}
		break;
		case 1:
			    //MessageBox("Politica de Actualización : Post-Escritura");
			    wsprintf(str, "POST-ESCRITURA");
			    pStatusBar->SetPaneText(2, str);
			    pStatusBar->SetPaneText(3,"");
		break;
	}




	int cont;
	int nSec;
	
	CCache2003Doc *pDoc = GetDocument();
	cont = pDoc->m_iOpenDoc;
	
	nSec = pDoc->ObtenerTotalSecuencias();
	m_inSec = nSec;


	if( cont != 30 )
	{

		//desactiva los CheckBox del CForm
	
		GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_FREC) -> EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_EDAD) -> EnableWindow(FALSE);
	
	
		GetDlgItem(IDC_SIMULAR) -> EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_LLENAR_MP) -> EnableWindow(TRUE);

		//desactiva los controles de edición de los datos
		GetDlgItem(IDC_DATOSDLG_DIRECCION)->EnableWindow(FALSE);
		GetDlgItem(IDC_DATOSDLG_DAT)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO_LECT)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO_ESC)->EnableWindow(FALSE);
		GetDlgItem(IDC_B_AGREGAR)->EnableWindow(FALSE);
		GetDlgItem(IDC_B_EDITAR)->EnableWindow(FALSE);
		GetDlgItem(IDC_B_BUSCAR)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_POSICION)->EnableWindow(FALSE);
		GetDlgItem(IDC_B_PRIMERO)->EnableWindow(FALSE);
		GetDlgItem(IDC_B_ANTERIOR)->EnableWindow(FALSE);
		GetDlgItem(IDC_B_SIGUIENTE)->EnableWindow(FALSE);
		GetDlgItem(IDC_B_ULTIMO)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_DIR)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_DAT)->EnableWindow(FALSE);

		

		//desactiva los controles de edición de las secuencias
		GetDlgItem(IDC_EDIT_SECUENCIA)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_DIR_SEC)->EnableWindow(FALSE);
		GetDlgItem(IDC_B_AGREGAR_SEC)->EnableWindow(FALSE);
		GetDlgItem(IDC_B_EDITAR_SEC)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_REG_SEC)->EnableWindow(FALSE);
		GetDlgItem(IDC_B_PRIMERO_SEC)->EnableWindow(FALSE);
		GetDlgItem(IDC_B_ANTERIOR_SEC)->EnableWindow(FALSE);
		GetDlgItem(IDC_B_SIGUIENTE_SEC)->EnableWindow(FALSE);
		GetDlgItem(IDC_B_ULTIMO_SEC)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_SECUENCIA)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_DIR_SEC)->EnableWindow(FALSE);
		
		//desactiva los controles edit del CFormView
		//GetDlgItem(IDC_EDIT_MET_EMPLAZA) -> ShowWindow(FALSE);
		//GetDlgItem(IDC_EDIT_MET_REEMPLAZA) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_DATO)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_TIPO)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_DATO_MC)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_SIMULACIONES)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_ACIERTOS)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_FALLOS)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_PALABRA)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_BLOQUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_PALABRA_BLOQUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_LINEA)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_CONJ)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_N_LINEAS)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_TA)->EnableWindow(FALSE);

		//desactiva los controles static del CFormView
		GetDlgItem(IDC_STATIC_DATO)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_DATO_MC)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_SIMULACIONES)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_ACIERTOS)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_FALLOS)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_PALABRA)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_BLOQUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_PALABRA_BLOQUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_LINEA)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_CONJ_MC)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_LINEA_CONJ)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_NS)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_TA)->EnableWindow(FALSE);

	
		m_Fila = 0;
		m_Col = 6;

		m_nSim = 0;
		m_contAciertos = 0;
		m_contFallos = 0;
		m_sSecuencia = "1";
	
		//Rejilla Memoria Principal
		TamCeldasNoFijas( m_Fila, m_Col);
	
		m_CtrlRejilla_MP.SetRow(0);
		m_CtrlRejilla_MP.SetCol(0);
		m_CtrlRejilla_MP.SetText("Dirección");
		m_CtrlRejilla_MP.SetCellBackColor(0x00666666);
		m_CtrlRejilla_MP.SetCellForeColor(0x0000FFFF);
		m_CtrlRejilla_MP.SetCellAlignment(4);
		m_CtrlRejilla_MP.Refresh();

		m_CtrlRejilla_MP.SetRow(0);
		m_CtrlRejilla_MP.SetCol(1);
		m_CtrlRejilla_MP.SetText("Datos");
		m_CtrlRejilla_MP.SetCellBackColor(0x00666666);
		m_CtrlRejilla_MP.SetCellForeColor(0x0000FFFF);
		m_CtrlRejilla_MP.SetCellAlignment(4);
		m_CtrlRejilla_MP.Refresh();

	
		m_CtrlRejilla_MP.SetColWidth(0, 1500);
		m_CtrlRejilla_MP.SetColWidth(1, 1850);
		//Tercera Cuarta Quinta y Sexta Columna de MP con ancho nulo 
	
	
		m_CtrlRejilla_MP.SetColWidth(2, 0);
		m_CtrlRejilla_MP.SetColWidth(3, 0);
		m_CtrlRejilla_MP.SetColWidth(4, 0);
		m_CtrlRejilla_MP.SetColWidth(5, 0);
    
		//Rejilla Memoria Cache
		TamCeldasNoFijas_MC( m_Fila, m_Col );
   	
	
	
		m_CtrlRejilla_MC.SetRow(0);
		m_CtrlRejilla_MC.SetCol(0);
		m_CtrlRejilla_MC.SetText("Dirección");
		m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
		m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
		m_CtrlRejilla_MC.SetCellAlignment(4);
		m_CtrlRejilla_MC.Refresh();

		m_CtrlRejilla_MC.SetRow(0);
		m_CtrlRejilla_MC.SetCol(1);
		m_CtrlRejilla_MC.SetText("Datos");
		m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
		m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
		m_CtrlRejilla_MC.SetCellAlignment(4);
		m_CtrlRejilla_MC.Refresh();
	
		m_CtrlRejilla_MC.SetColWidth(0, 1500);
		m_CtrlRejilla_MC.SetColWidth(1, 1850);
		//Tercera, Cuarta Quinta y Sexta Columna de MP con ancho nulo 
	
		m_CtrlRejilla_MC.SetColWidth(2, 0);
		m_CtrlRejilla_MC.SetColWidth(3, 0);
		m_CtrlRejilla_MC.SetColWidth(4, 0);
		m_CtrlRejilla_MC.SetColWidth(5, 0);
	
	}
	else
	{
	
		//desactiva los CheckBox del CForm
		
		GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_FREC) -> EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_EDAD) -> EnableWindow(FALSE);
	
		GetDlgItem(IDC_SIMULAR) -> EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_LLENAR_MP) -> EnableWindow(FALSE);

		//desactiva los controles de edición de los datos
		GetDlgItem(IDC_DATOSDLG_DIRECCION)->EnableWindow(FALSE);
		GetDlgItem(IDC_DATOSDLG_DAT)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIO_LECT)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIO_ESC)->EnableWindow(TRUE);
		GetDlgItem(IDC_B_AGREGAR)->EnableWindow(FALSE);
		GetDlgItem(IDC_B_EDITAR)->EnableWindow(TRUE);
		GetDlgItem(IDC_B_BUSCAR)->EnableWindow(TRUE);
		GetDlgItem(IDC_STATIC_POSICION)->EnableWindow(TRUE);
		GetDlgItem(IDC_B_PRIMERO)->EnableWindow(TRUE);
		GetDlgItem(IDC_B_ANTERIOR)->EnableWindow(TRUE);
		GetDlgItem(IDC_B_SIGUIENTE)->EnableWindow(TRUE);
		GetDlgItem(IDC_B_ULTIMO)->EnableWindow(TRUE);
		GetDlgItem(IDC_STATIC_DIR)->EnableWindow(TRUE);
		GetDlgItem(IDC_STATIC_DAT)->EnableWindow(TRUE);
		
		if(m_iAutomatico_Sec == 0)
		{	

			//desactiva los controles de edición de las secuencias
			GetDlgItem(IDC_EDIT_SECUENCIA)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_DIR_SEC)->EnableWindow(FALSE);
			GetDlgItem(IDC_B_AGREGAR_SEC)->EnableWindow(FALSE);
			GetDlgItem(IDC_B_EDITAR_SEC)->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_REG_SEC)->EnableWindow(FALSE);
			GetDlgItem(IDC_B_PRIMERO_SEC)->EnableWindow(FALSE);
			GetDlgItem(IDC_B_ANTERIOR_SEC)->EnableWindow(FALSE);
			GetDlgItem(IDC_B_SIGUIENTE_SEC)->EnableWindow(FALSE);
			GetDlgItem(IDC_B_ULTIMO_SEC)->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_SECUENCIA)->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_DIR_SEC)->EnableWindow(FALSE);
		}
		else
		{
			//desactiva los controles de edición de las secuencias
			GetDlgItem(IDC_EDIT_SECUENCIA)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_DIR_SEC)->EnableWindow(TRUE);
			GetDlgItem(IDC_B_AGREGAR_SEC)->EnableWindow(FALSE);
			GetDlgItem(IDC_B_EDITAR_SEC)->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_REG_SEC)->EnableWindow(TRUE);
			GetDlgItem(IDC_B_PRIMERO_SEC)->EnableWindow(TRUE);
			GetDlgItem(IDC_B_ANTERIOR_SEC)->EnableWindow(TRUE);
			GetDlgItem(IDC_B_SIGUIENTE_SEC)->EnableWindow(TRUE);
			GetDlgItem(IDC_B_ULTIMO_SEC)->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_SECUENCIA)->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_DIR_SEC)->EnableWindow(TRUE);
		}
		

		//desactiva los controles edit del CFormView
		//GetDlgItem(IDC_EDIT_MET_EMPLAZA) -> ShowWindow(FALSE);
		//GetDlgItem(IDC_EDIT_MET_REEMPLAZA) -> ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_DATO)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_TIPO)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_DATO_MC)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_SIMULACIONES)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_ACIERTOS)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_FALLOS)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_PALABRA)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_BLOQUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_PALABRA_BLOQUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_LINEA)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_CONJ)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_N_LINEAS)->EnableWindow(FALSE);
		//desactiva los controles static del CFormView
		GetDlgItem(IDC_STATIC_DATO)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_DATO_MC)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_SIMULACIONES)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_ACIERTOS)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_FALLOS)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_PALABRA)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_BLOQUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_PALABRA_BLOQUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_LINEA)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_CONJ_MC)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_LINEA_CONJ)->EnableWindow(FALSE);

		
	
		m_nSim = 0;
		m_contAciertos = 0;
		m_contFallos = 0;
		m_sSecuencia = "1";

	
		//Rejilla Memoria Principal
		//TamCeldasNoFijas( m_Fila, m_Col);
	
		m_CtrlRejilla_MP.SetRow(0);
		m_CtrlRejilla_MP.SetCol(0);
		m_CtrlRejilla_MP.SetText("Dirección");
		m_CtrlRejilla_MP.SetCellBackColor(0x00666666);
		m_CtrlRejilla_MP.SetCellForeColor(0x0000FFFF);
		m_CtrlRejilla_MP.SetCellAlignment(4);
		m_CtrlRejilla_MP.Refresh();

		m_CtrlRejilla_MP.SetRow(0);
		m_CtrlRejilla_MP.SetCol(1);
		m_CtrlRejilla_MP.SetText("Datos");
		m_CtrlRejilla_MP.SetCellBackColor(0x00666666);
		m_CtrlRejilla_MP.SetCellForeColor(0x0000FFFF);
		m_CtrlRejilla_MP.SetCellAlignment(4);
		m_CtrlRejilla_MP.Refresh();

		m_CtrlRejilla_MP.SetColWidth(0, 1500);
		m_CtrlRejilla_MP.SetColWidth(1, 1850);
		//Tercera Cuarta Quinta y Sexta Columna de MP con ancho nulo 
	
		/*
		m_CtrlRejilla_MP.SetColWidth(2, 0);
		m_CtrlRejilla_MP.SetColWidth(3, 0);
		m_CtrlRejilla_MP.SetColWidth(4, 0);
		m_CtrlRejilla_MP.SetColWidth(5, 0);
		*/
		//Rejilla Memoria Cache
		//TamCeldasNoFijas_MC( m_Fila, m_Col );
   	
		
		m_CtrlRejilla_MC.SetRow(0);
		m_CtrlRejilla_MC.SetCol(0);
		m_CtrlRejilla_MC.SetText("Dirección");
		m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
		m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
		m_CtrlRejilla_MC.SetCellAlignment(4);
		m_CtrlRejilla_MC.Refresh();

		m_CtrlRejilla_MC.SetRow(0);
		m_CtrlRejilla_MC.SetCol(1);
		m_CtrlRejilla_MC.SetText("Datos");
		m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
		m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
		m_CtrlRejilla_MC.SetCellAlignment(4);
		m_CtrlRejilla_MC.Refresh();
	
		m_CtrlRejilla_MC.SetColWidth(0, 1500);
		m_CtrlRejilla_MC.SetColWidth(1, 1850);
		//Tercera, Cuarta Quinta y Sexta Columna de MP con ancho nulo 
	/*	
		m_CtrlRejilla_MC.SetColWidth(2, 0);
		m_CtrlRejilla_MC.SetColWidth(3, 0);
		m_CtrlRejilla_MC.SetColWidth(4, 0);
		m_CtrlRejilla_MC.SetColWidth(5, 0);
	 */
	}
	
}	
	

/////////////////////////////////////////////////////////////////////////////
// CCache2003View printing

BOOL CCache2003View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	CCache2003Doc* pDoc = GetDocument();
	pInfo->SetMaxPage(pDoc->m_arregloDatos.GetUpperBound() / CCache2003Doc::nLinesPerPage + 1);
	
	return DoPreparePrinting(pInfo);
}

void CCache2003View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCache2003View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CCache2003View::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	int        i, nStart, nEnd, nHeight;
    int 	   espaciado = 0;
	CString    str;
    CPoint     point(720, -1440);
    CFont      font;
    TEXTMETRIC tm;

    pDC->SetMapMode(MM_TWIPS);
    CCache2003Doc* pDoc = GetDocument();
	m_nPage = pInfo->m_nCurPage; // en beneficio de PrintPageFooter
    nStart = (m_nPage - 1) * CCache2003Doc::nLinesPerPage;
    nEnd = nStart + CCache2003Doc::nLinesPerPage;
	// fuente de 14 puntos, tamaño fijo
	font.CreateFont(-280, 0, 0, 0, 400, FALSE, FALSE,
	                0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
	                CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
	                DEFAULT_PITCH | FF_MODERN, "Courier New");
	                // Courier New es una fuente TrueType 
    CFont* pOldFont = (CFont*) (pDC->SelectObject(&font));
    PrintPageHeader(pDC);
    pDC->GetTextMetrics(&tm);
    nHeight = tm.tmHeight + tm.tmExternalLeading;
    
	int i_Dir;
	int i_Dat;
	int i_Tip;
	int n = m_nMP;
	CString s_Dir;
	CString s_Dat;
	
	
	

	for (i = nStart; i < nEnd; i++) 
	{
           	
			m_pCurDatos = pDoc->ObtenerRegActual_par(i);
			LlenarVista();

		    if(m_pCurDatos)
			{
				
			   //se le da los valores predeterminados
				m_pCurDatos->SetDireccion(m_sDireccion);
				m_pCurDatos->SetDato(m_sDato);
				m_pCurDatos->SetTipo(m_iTipo);
			
				//se piden los nuevos valores
			
				i_Dir = atoi(m_sDireccion);
				i_Dat = atoi(m_sDato);
				i_Tip = m_iTipo -1;
				
				s_Dir = Bin(i_Dir, n);
				s_Dat = Bin(i_Dat, 16);
				//i_Dir = atoi(s_Dir);
				//i_Dat = atoi(s_Dat);
								
			 }
			
			if (i > pDoc->m_arregloDatos.GetUpperBound() - 1) 
			{
				break;
			}
        
			str.Format("%6d %16s %20s %12d", i + 1, s_Dir,	s_Dat, i_Tip);
			point.y -= nHeight;
			pDC->TextOut(point.x, point.y, str);
	}
	
	
	PrintPageFooter(pDC);
    
	pDC->SelectObject(pOldFont);

	
}

/////////////////////////////////////////////////////////////////////////////
// CCache2003View diagnostics

#ifdef _DEBUG
void CCache2003View::AssertValid() const
{
	CFormView::AssertValid();
}

void CCache2003View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CCache2003Doc* CCache2003View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCache2003Doc)));
	return (CCache2003Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCache2003View message handlers


void CCache2003View::OnConfiguracionMemorias() 
{
	// TODO: Add your command handler code here
	

	
	CMemoriasDlg dlgMemorias;
	CPoliticasDlg dlgPoliticas;	
	CSimulacionDlg dlgSimulacion;
    
	

	dlgMemorias.m_inMP = m_nMP; 
	dlgMemorias.m_inMC = m_nMC;
	dlgMemorias.m_inBloque = m_nBloque;
	dlgMemorias.m_lBytesTamMP = m_TamMP;
	dlgMemorias.m_lBytesTamMC = m_TamMC;
	dlgMemorias.m_lBytesTamBloque = m_TamBloque;
	dlgPoliticas.m_iPDirecto = m_iP_Emplazamiento;	
	dlgPoliticas.m_iPAleatorio = m_iP_Reemplazamiento; 
	dlgPoliticas.m_snVias = m_nVias;
	dlgSimulacion.m_iAutomatico = m_iAutomatico;

	UpdateData(false);
	
	


	if( (dlgMemorias.DoModal() == IDOK ) /*&& (dlgPoliticas.DoModal() == IDOK)*/)
	{
		
        		
		 LimpiarRejilla_MP();
		 LimpiarRejilla_MC();
		 LimpiarEdit();
		

		 if( dlgSimulacion.m_iAutomatico == 0)
		 {
			 GetDlgItem(IDC_BTN_LLENAR_MP) -> EnableWindow(TRUE);
			 GetDlgItem(IDC_SIMULAR) ->EnableWindow(FALSE);
		 }
		 else
		 {
			 GetDlgItem(IDC_BTN_LLENAR_MP) -> EnableWindow(FALSE);
			 GetDlgItem(IDC_SIMULAR) ->EnableWindow(TRUE);
		 }
		 
		
		


		for(int i = 0; i<= m_dlgDireccion.m_inEtiquetas; i++)
		{
			delete m_dlgDireccion.m_pEtiquetas;
			m_dlgDireccion.m_pEtiquetas = NULL;
		}
		for( i = 0; i<=m_dlgDireccion.m_inLineas; i++)
		{
			delete m_dlgDireccion.m_pLineas;
			m_dlgDireccion.m_pLineas = NULL;
		}
		for( i = 0; i<= m_dlgDireccion.m_inPalabras; i++)
		{
			delete m_dlgDireccion.m_pPalabras;
			m_dlgDireccion.m_pPalabras = NULL;
		}
		for( i = 0; i<=m_dlgDireccion.m_inConjuntos; i++)
		{
			delete m_dlgDireccion.m_pConjuntos;
			m_dlgDireccion.m_pConjuntos = NULL;
		}
		for( i = 0; i<=m_dlgDireccion.m_iTotalBits; i++)
		{
			delete m_dlgDireccion.m_pnBits;
			m_dlgDireccion.m_pnBits = NULL;
		}
		
		
		if(dlgMemorias.m_inMP > 15 || dlgMemorias.m_inMC > 15 || dlgMemorias.m_inBloque > 15)
		{
			AfxMessageBox("El tamaño de la memoria asignado es demasiado grande para la visualización del control rejilla.\nPor favor introduzca tamaños más pequeños de memoria.", MB_ICONSTOP, IDOK);
		 return;
		}


		
		//UpdateData(true);
		m_TamMP = dlgMemorias.m_lBytesTamMP;
		m_TamMC = dlgMemorias.m_lBytesTamMC;
		m_TamBloque = dlgMemorias.m_lBytesTamBloque;
		m_nMP = dlgMemorias.m_inMP;
		m_nMC = dlgMemorias.m_inMC;
		m_nBloque = dlgMemorias.m_inBloque;
		
		UpdateData(false);

			//Control de Excepción división entre cero
			TRY
			{
				if((m_nBloque == 0) || (m_nMP == 0) || (m_nMC == 0))
				{
					AfxThrowUserException();
				}

				UpdateData(true);
				m_in_Bloques_MP = m_TamMP/m_TamBloque;
				m_in_Bloques_MC = m_TamMC/m_TamBloque;
				UpdateData(false);
			}
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los tamaños de memoria introducidos no son válidos para la simulación.\nLos tamaños deben ser mayores que cero");
				OnConfiguracionMemorias();
			}
			
			END_CATCH
			
			//Control de Excepción Tamaños no apropiados
			TRY
			{
				if((m_nBloque > m_nMC) || (m_nMC > m_nMP))
				{
					AfxThrowUserException();
				}

				
			}
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los tamaños de memoria introducidos no son válidos para la simulación.\nPOSIBLES CAUSAS :\n1. El tamaño del Memoria Cache es mayor que el de Memoria Principal.\n2. El tamaño del Memoria Cache es mayor que el de Memoria Principal.");
				OnConfiguracionMemorias();
			}
			
			END_CATCH
		

		//Se actualizan los tamaños de los controles Active X
		TamCeldasNoFijas(m_TamMP, 6);
		TamCeldasNoFijas_MC(m_TamMC, 6);	
		//Columnas con ancho nulo 
	    m_CtrlRejilla_MP.SetColWidth(2, 0);
	    m_CtrlRejilla_MP.SetColWidth(3, 0);
		m_CtrlRejilla_MP.SetColWidth(4, 0);
		m_CtrlRejilla_MP.SetColWidth(5, 0);
		
		m_CtrlRejilla_MC.SetColWidth(2, 0);
		m_CtrlRejilla_MC.SetColWidth(3, 0);
		m_CtrlRejilla_MC.SetColWidth(4, 0);
		m_CtrlRejilla_MC.SetColWidth(5, 0);
		
		ResetDatos();
		/*
		LimpiarRejilla_MP();
		LimpiarRejilla_MC();
		LimpiarEdit();
		*/
		switch(dlgPoliticas.m_iPDirecto)
		{
		case 0:
			//MessageBox("Opción Directo");
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.Parche();
			m_dlgDireccion.DirDirecto( dlgMemorias.m_inMP, dlgMemorias.m_inMC, dlgMemorias.m_inBloque );
			m_dlgDireccion.UpdateData(false);
			m_dlgDireccion.OnChangeDEtiqueta();
			m_dlgDireccion.OnChangeDLinea();
			m_dlgDireccion.OnChangeDPalabra();
			m_dlgDireccion.OnChangeDTotalBits();		
			
			m_iP_Emplazamiento = dlgPoliticas.m_iPDirecto;
			m_sMet_Emplaza = "Directo";
			m_sMet_Reemplaza = "";
			UpdateData(false);

			UpdateData(false);
			break;
		
		case 1:
			//MessageBox("Opcion Asociativo");
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.Parche();
			m_dlgDireccion.DirAsociativo( dlgMemorias.m_inMP, dlgMemorias.m_inMC, dlgMemorias.m_inBloque );
			m_dlgDireccion.UpdateData(false);
			m_dlgDireccion.OnChangeDEtiqueta();
			m_dlgDireccion.OnChangeDLinea();
			m_dlgDireccion.OnChangeDPalabra();
			m_dlgDireccion.OnChangeDTotalBits();	
			
			m_iP_Emplazamiento = dlgPoliticas.m_iPDirecto;
			m_sMet_Emplaza = "Asociativo";

			UpdateData(false);
			break;

		case 2:
			//MessageBox("Opcion Asociativo por Conjuntos");
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.Parche();
			m_dlgDireccion.DirAConjuntos( dlgMemorias.m_inMP, dlgMemorias.m_inMC, dlgMemorias.m_inBloque, dlgPoliticas.m_snVias );
			m_dlgDireccion.UpdateData(false);
			m_dlgDireccion.OnChangeDEtiqueta();
			m_dlgDireccion.OnChangeDLinea();
			m_dlgDireccion.OnChangeDPalabra();
			m_dlgDireccion.OnChangeDTotalBits();		
			
			m_iP_Emplazamiento = dlgPoliticas.m_iPDirecto;
			m_nVias = dlgPoliticas.m_snVias;
			m_sMet_Emplaza = "Asociativo por Conjuntos";
			UpdateData(false);
			
			ColorearConjuntos(m_TamMC, m_TamBloque, m_nVias);
			break;
		
		default :
			MessageBox("ERROR.Opción no válida");
			break;
		
		 
		}
	
		
		switch(dlgPoliticas.m_iPAleatorio)
		{
		case 0:
						
			//MessageBox("Opción Aleatorio");
			
			m_iP_Reemplazamiento = dlgPoliticas.m_iPAleatorio;
			m_sMet_Reemplaza = "Aleatorio";
			UpdateData(false);
			break;
		  
		case 1:
			
				
			//MessageBox("Opcion Ultimo Reciente Usado");
			
			m_iP_Reemplazamiento = dlgPoliticas.m_iPAleatorio;
			m_sMet_Reemplaza = "LRU";
			UpdateData(false);
			break;
		  
		case 2:
			
			//MessageBox("Opcion Ultimo Frecuente Usado");
			
			m_iP_Reemplazamiento = dlgPoliticas.m_iPAleatorio;
			m_sMet_Reemplaza = "LFU";
			UpdateData(false);
			break;
		  
		case 3:
			
			//MessageBox("Opcion Primero Entra Primero Sale");
			
			m_iP_Reemplazamiento = dlgPoliticas.m_iPAleatorio;
			m_sMet_Reemplaza = "FIFO";
			UpdateData(false);
			break;
		
		default :
			//MessageBox("ERROR.Opción no válida");
			m_sMet_Reemplaza = " ";
			UpdateData(false);
			break;
		
		}

	 }

}

void CCache2003View::OnVerDireccindememoria() 
{
	// TODO: Add your command handler code here
	m_dlgDireccion.ShowWindow( SW_SHOW);
	
	//CCache2003View::PreCreateWindow( lpCreateStruct );
	
}


void CCache2003View::OnConfigurarPolticas() 
{
	// TODO: Add your command handler code here
	CPoliticasDlg dlgPoliticas;
	CMemoriasDlg  dlgMemorias;
	CSimulacionDlg dlgSimulacion;
	
	dlgMemorias.m_inMP = m_nMP; 
	dlgMemorias.m_inMC = m_nMC;
	dlgMemorias.m_inBloque = m_nBloque;
	dlgMemorias.m_lBytesTamMP = m_TamMP;
	dlgMemorias.m_lBytesTamMC = m_TamMC;
	dlgMemorias.m_lBytesTamBloque = m_TamBloque;
	dlgPoliticas.m_iPDirecto = m_iP_Emplazamiento;	
	dlgPoliticas.m_iPAleatorio = m_iP_Reemplazamiento;
	dlgPoliticas.m_snVias = m_nVias;
	dlgSimulacion.m_iAutomatico = m_iAutomatico;

	UpdateData(false);

	    if( (dlgPoliticas.DoModal() == IDOK ) /*&& ( dlgMemorias.DoModal() == IDOK)*/)
		{
		
ResetDatos();	
LimpiarRejilla_MP();
LimpiarRejilla_MC();
LimpiarEdit();
Primero();
			if( dlgSimulacion.m_iAutomatico == 0)
			{
			 GetDlgItem(IDC_BTN_LLENAR_MP) -> EnableWindow(TRUE);
			 GetDlgItem(IDC_SIMULAR) ->EnableWindow(FALSE);
			}
			else
			{
			 GetDlgItem(IDC_BTN_LLENAR_MP) -> EnableWindow(FALSE);
			 GetDlgItem(IDC_SIMULAR) ->EnableWindow(TRUE);
			}
			 


		for( int i = 0; i<= m_dlgDireccion.m_inEtiquetas; i++)
		{
			delete m_dlgDireccion.m_pEtiquetas;
			m_dlgDireccion.m_pEtiquetas = NULL;
		}
		for( i = 0; i<=m_dlgDireccion.m_inLineas; i++)
		{
			delete m_dlgDireccion.m_pLineas;
			m_dlgDireccion.m_pLineas = NULL;
		}
		for( i = 0; i<= m_dlgDireccion.m_inPalabras; i++)
		{
			delete m_dlgDireccion.m_pPalabras;
			m_dlgDireccion.m_pPalabras = NULL;
		}
		for( i = 0; i<=m_dlgDireccion.m_inConjuntos; i++)
		{
			delete m_dlgDireccion.m_pConjuntos;
			m_dlgDireccion.m_pConjuntos = NULL;
		}
		for( i = 0; i<=m_dlgDireccion.m_iTotalBits; i++)
		{
			delete m_dlgDireccion.m_pnBits;
			m_dlgDireccion.m_pnBits = NULL;
		}


		
		m_TamMP = dlgMemorias.m_lBytesTamMP;
		m_TamMC = dlgMemorias.m_lBytesTamMC;
		m_TamBloque = dlgMemorias.m_lBytesTamBloque;
		m_nMP = dlgMemorias.m_inMP;
		m_nMC = dlgMemorias.m_inMC;
		m_nBloque = dlgMemorias.m_inBloque;
		UpdateData(false);
		/*
		m_iP_Emplazamiento = dlgPoliticas.m_iPDirecto; 
	    m_iP_Reemplazamiento = dlgPoliticas.m_iPAleatorio;
	    m_nVias = dlgPoliticas.m_snVias; */ 
		

		
		//Se actualizan los tamaños de los controles Active X
		TamCeldasNoFijas(m_TamMP, 5);
		TamCeldasNoFijas_MC(m_TamMC,5);	
		//Tercera Columna con ancho nulo 
	    m_CtrlRejilla_MP.SetColWidth(2, 0);
	    m_CtrlRejilla_MP.SetColWidth(3, 0);
		m_CtrlRejilla_MP.SetColWidth(4, 0);
		m_CtrlRejilla_MP.SetColWidth(5, 0);

		m_CtrlRejilla_MC.SetColWidth(2, 0);
		m_CtrlRejilla_MC.SetColWidth(3, 0);
		m_CtrlRejilla_MC.SetColWidth(4, 0);
		m_CtrlRejilla_MC.SetColWidth(5, 0);
		
		switch(dlgPoliticas.m_iPDirecto)
		{
		case 0:
						
			//MessageBox("Opción Directo");
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.Parche();
			m_dlgDireccion.DirDirecto( dlgMemorias.m_inMP, dlgMemorias.m_inMC, dlgMemorias.m_inBloque );
			m_dlgDireccion.UpdateData(false);
			m_dlgDireccion.OnChangeDEtiqueta();
			m_dlgDireccion.OnChangeDLinea();
			m_dlgDireccion.OnChangeDPalabra();
			m_dlgDireccion.OnChangeDTotalBits();		
			
			m_iP_Emplazamiento = dlgPoliticas.m_iPDirecto;
			m_sMet_Emplaza = "Directo";
			dlgPoliticas.m_iPAleatorio = -1;
			UpdateData(false); 
			break;
		  
		case 1:
			
				
			//MessageBox("Opcion Asociativo");
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.Parche();
			m_dlgDireccion.DirAsociativo( dlgMemorias.m_inMP, dlgMemorias.m_inMC, dlgMemorias.m_inBloque );
			m_dlgDireccion.UpdateData(false);
			m_dlgDireccion.OnChangeDEtiqueta();
			m_dlgDireccion.OnChangeDLinea();
			m_dlgDireccion.OnChangeDPalabra();
			m_dlgDireccion.OnChangeDTotalBits();	
			
			m_iP_Emplazamiento = dlgPoliticas.m_iPDirecto;
			m_sMet_Emplaza = "Asociativo";
			UpdateData(false); 
			break;
		  
		case 2:
			
			//MessageBox("Opcion Asociativo por Conjuntos");
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.Parche();
			m_dlgDireccion.DirAConjuntos( dlgMemorias.m_inMP, dlgMemorias.m_inMC, dlgMemorias.m_inBloque, dlgPoliticas.m_snVias );
			m_dlgDireccion.UpdateData(false);
			m_dlgDireccion.OnChangeDEtiqueta();
			m_dlgDireccion.OnChangeDLinea();
			m_dlgDireccion.OnChangeDPalabra();
			m_dlgDireccion.OnChangeDTotalBits();		
			
			m_iP_Emplazamiento = dlgPoliticas.m_iPDirecto;
			m_nVias = dlgPoliticas.m_snVias;
			m_sMet_Emplaza = "Asociativo por Conjuntos";
			UpdateData(false); 
			
			ColorearConjuntos(m_TamMC, m_TamBloque, m_nVias);
			break;
		  
		default :
			//MessageBox("ERROR.Opción no válida");
			break;
		
		 
		}
	
		switch(dlgPoliticas.m_iPAleatorio)
		{
		case 0:
						
			//MessageBox("Opción Aleatorio");
			
			m_iP_Reemplazamiento = dlgPoliticas.m_iPAleatorio;
			m_sMet_Reemplaza = "Aleatorio";
			UpdateData(false);
			break;
		  
		case 1:
			
				
			//MessageBox("Opcion Menos Reciente Usado");
			
			m_iP_Reemplazamiento = dlgPoliticas.m_iPAleatorio;
			m_sMet_Reemplaza = "LRU";
			UpdateData(false);
			break;
		  
		case 2:
			
			//MessageBox("Opcion Menos Frecuente Usado");
			
			m_iP_Reemplazamiento = dlgPoliticas.m_iPAleatorio;
			m_sMet_Reemplaza = "LFU";
			UpdateData(false);
			break;
		  
		case 3:
			
			//MessageBox("Opcion Primero Entra Primero Sale");
			
			m_iP_Reemplazamiento = dlgPoliticas.m_iPAleatorio;
			m_sMet_Reemplaza = "FIFO";
			UpdateData(false);
			break;
		
		default :
			//MessageBox("ERROR.Opción no válida");
			m_sMet_Reemplaza = "";
			UpdateData(false);
			break;
		
		 
		}
/*
ResetDatos();	
LimpiarRejilla_MP();
LimpiarRejilla_MC();
LimpiarEdit();
*/	



	}
}


void CCache2003View::TamCeldasNoFijas(long nFilasFijas, long nColFijas)
{
	CClientDC dc(this);
	long XPixelsPorPulgada = dc.GetDeviceCaps(LOGPIXELSX);
	long YPixelsPorPulgada = dc.GetDeviceCaps(LOGPIXELSY);

	CRect rect;
	m_CtrlRejilla_MP.GetWindowRect( rect );

	long AnchoCtrlRej, AltoCtrlRej;
	long AnchoColFija, AltoFilaFija;

	AnchoColFija = m_CtrlRejilla_MP.GetColWidth(0);
	AltoFilaFija = m_CtrlRejilla_MP.GetRowHeight(0);

	AnchoCtrlRej = rect.right - rect.left;
	AltoCtrlRej = rect.bottom - rect.top;

	AnchoCtrlRej = AnchoCtrlRej * 1440/XPixelsPorPulgada - AnchoColFija - 50;
	AltoCtrlRej = AltoCtrlRej * 1440/YPixelsPorPulgada - AltoFilaFija - 50;

	long Filas, Columnas;

	if( nFilasFijas <= 1)
	{
		Filas = 1;
	}
	else
	{
		Filas = nFilasFijas + 1;
	}

	if( nColFijas <= 6 )
	{
		Columnas = 6;
	}
	else
	{
		Columnas = nColFijas + 1;
	}

	m_CtrlRejilla_MP.SetRows(Filas);
	m_CtrlRejilla_MP.SetCols(Columnas);


	for( int i = 1; i <= Filas -1; i++ )
	{
		m_CtrlRejilla_MP.SetRowHeight( i, (AltoCtrlRej - 255 )/14);
	}

	for( i = 1; i <= Columnas - 1; i++ )
	{
		m_CtrlRejilla_MP.SetColWidth( i, (AnchoCtrlRej - 255 )/1);
	}

	
}


void CCache2003View::OnFormatoDatos() 
{
	// TODO: Add your command handler code here
	m_IdFormatoDato = LOWORD( GetCurrentMessage()->wParam);
	
	 	
	static UINT uSeleccionAnterior = ID_FORMAT_BINARIO;
	
	CWnd *pVentanaPadre = GetParent();
	CMenu *pMenu = pVentanaPadre->GetMenu();
	
	pMenu->CheckMenuItem( uSeleccionAnterior, MF_UNCHECKED | MF_BYCOMMAND);
	pMenu->CheckMenuItem( m_IdFormatoDato, MF_CHECKED | MF_BYCOMMAND );

	uSeleccionAnterior = m_IdFormatoDato;

	CMainFrame *pMain = (CMainFrame*)AfxGetMainWnd();
  	
	if( pMenu->GetMenuState(ID_FORMAT_BINARIO, MF_BYCOMMAND) == MF_CHECKED)
	{
	   	pMain->m_CtrlBinario.SetCurSel(0);
	}
	if( pMenu->GetMenuState(ID_FORMAT_OCTAL, MF_BYCOMMAND) == MF_CHECKED)
	{
	   	pMain->m_CtrlBinario.SetCurSel(1);
	}
	if( pMenu->GetMenuState(ID_FORMAT_DECIMAL, MF_BYCOMMAND) == MF_CHECKED)
	{
	   	pMain->m_CtrlBinario.SetCurSel(2);
	}
	if( pMenu->GetMenuState(ID_FORMAT_HEXADECIMAL, MF_BYCOMMAND) == MF_CHECKED)
	{
	   	pMain->m_CtrlBinario.SetCurSel(3);
	}


}

void CCache2003View::MostrarMP()
{
	char sEtiqueta[8];
	
	int Fila;
	CPoliticasDlg dlgPoliticas;
	CMemoriasDlg dlgMemorias;


	m_CtrlRejilla_MP.SetRedraw(false);
	LimpiarRejilla_MP();
	
	
	if(dlgPoliticas.m_iPDirecto == 0)
	{
		m_CtrlRejilla_MP.SetRow(0);
		m_CtrlRejilla_MP.SetCol(0);
		m_CtrlRejilla_MP.SetText("Dirección");
		m_CtrlRejilla_MP.SetCellAlignment(4);
		
		
		m_CtrlRejilla_MP.SetRow(0);
		m_CtrlRejilla_MP.SetCol(1);
		m_CtrlRejilla_MP.SetText("Datos");
		m_CtrlRejilla_MP.SetCellAlignment(4);	
		
		
		TamCeldasNoFijas( m_TamMP, 4 );
		m_CtrlRejilla_MP.SetCol(0);
		
		for( Fila = 1; Fila <= m_TamMP; Fila++)
		{
			m_CtrlRejilla_MP.SetRow(Fila);
			sprintf(sEtiqueta,"%u",m_ppMP[Fila][0]);
			m_CtrlRejilla_MP.SetText(sEtiqueta);	
		    m_CtrlRejilla_MP.SetCellAlignment(4);
		}
	m_CtrlRejilla_MP.SetRedraw(true);
	}

}


void CCache2003View::LimpiarRejilla_MP()
{
	for( int i=0; i<m_TamMP; i++)
	{
		
		*(m_arrayDirMPPtr + i) = -1;
		*(m_arrayDatosMPPtr + i) = '\0';
		*(m_arrayTipoMPPtr + i) = '\0';	 
		
		m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,0),"");
		m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,1),"");
		m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"");
		
		ColorearMP(i+1, 0, 0x00000000, 0x00000000);
		ColorearMP(i+1, 1, 0x00000000, 0x00000000);
		ColorearMP(i+1, 2, 0x00000000, 0x00000000);
		
	
	}

}

void CCache2003View::LlenarMP()
{
	
	//Muestra controles
	GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(TRUE);
    GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(TRUE);
	
	if(m_TamMP > 0)
	{
		GetDlgItem(IDC_STATIC_POSICION) -> EnableWindow(TRUE);
		GetDlgItem(IDC_B_PRIMERO) -> EnableWindow(TRUE);
		GetDlgItem(IDC_B_ANTERIOR) -> EnableWindow(TRUE);
		GetDlgItem(IDC_B_SIGUIENTE) -> EnableWindow(TRUE);
		GetDlgItem(IDC_B_ULTIMO) -> EnableWindow(TRUE);
		GetDlgItem(IDC_DATOSDLG_DAT) -> EnableWindow(TRUE);	
		GetDlgItem(IDC_SIMULAR) -> EnableWindow(TRUE);	
		GetDlgItem(IDC_B_AGREGAR) ->EnableWindow(FALSE);

	}
	else
	{
		GetDlgItem(IDC_SIMULAR) -> EnableWindow(FALSE);
	}
	

	

  	
	AgregarPar();

	CCache2003Doc *pDoc = GetDocument();
	
	int total = pDoc->ObtenerTotalRegistros();

	for( int i = total; i>0; i--)
	{
		pDoc->EliminarRegistros(i);
		
	}

	total = pDoc->ObtenerTotalSecuencias();
			
	for( i = total; i>0; i--)
	{
		pDoc->EliminarSecuencia(i);
	}

	

	CWaitCursor CursorRelojDeArena;	
	m_CtrlRejilla_MP.SetColWidth(2, 0);
	m_CtrlRejilla_MC.SetColWidth(2, 0);
	
	
	
	srand( time(0) );
	
		
	m_arrayDatosMPPtr = new int[ m_TamMP];
	m_arrayDirMPPtr = new int[ m_TamMP ];
	m_arrayTipoMPPtr = new int[ m_TamMP ];
	
	
	 Primero();
	

		for(  i = 0; i< m_TamMP; i++)
		{	
	   
			*(m_arrayDatosMPPtr + i  )= 10 + rand() % 10000;
			*(m_arrayDirMPPtr + i ) = i;
			*(m_arrayTipoMPPtr + i  )= 1 + rand() % 2;
			if( *(m_arrayTipoMPPtr + i) == 2)
			{
				m_nEscrituras++;
				UpdateData(false);
			}
			
			LLenarObjetosDatos(i, *(m_arrayDirMPPtr + i), *(m_arrayDatosMPPtr + i), *(m_arrayTipoMPPtr + i));
			m_iReg++;
			//s_i = _itoa( i, buffer, 10);
			//MessageBox( " i = " + s_i); 
			

		}

	
		

	Primero();

	ImprimeFormatoMP(m_nMP, m_TamMP, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayTipoMPPtr);
	
	//Creación de dirección y datos de Memoria Cache
	m_arrayDirMCPtr = new int[ m_TamMC ];
	m_arrayDatosMCPtr = new int[ m_TamMC ];
	m_arrayTipoMCPtr = new int[ m_TamMC ];
	for(i= 0; i<m_TamMC; i++)
	{
		*(m_arrayDirMCPtr + i) = -1;
		*(m_arrayDatosMCPtr + i) = '\0';
		*(m_arrayTipoMCPtr + i) = '\0';
	}	
	
	  

	//Creación de arreglo de contadores para cada Linea
	m_contLineas = new int[ m_in_Bloques_MC ];
	m_contEdad = new int[ m_in_Bloques_MC ];
	m_contFrec = new int[ m_in_Bloques_MC ];
	
	for( i = 0; i<m_in_Bloques_MC; i++)
    {
		*(m_contLineas + i) = 0;
		*(m_contEdad + i) = 0;
		*(m_contFrec + i) = 0;
	}
	
	//Creación de arreglos de secuencias para simulación
		m_arrayDirSecMPPtr = new int[ m_inSec]; 
		m_arraySecMPPtr = new int[m_inSec];
	    
		for( i = 0; i<(m_inSec); i++)
		{
		
			*(m_arrayDirSecMPPtr + i) = 0;
			*(m_arraySecMPPtr + i) = i;
			
		}


	/*
	//int secuencias = pDoc->ObtenerTotalSecuencias();
	int secuencias = m_inSec;
	char buff[5];
	CString s_total;
	s_total = _itoa(secuencias, buff, 10);
	MessageBox("total = " + s_total);

	if( secuencias <= 1 )
	{

		MessageBox("entro");
		//Creación de arreglos de secuencias para simulación
		m_arrayDirSecMPPtr = new int[ m_inSec]; 
		m_arraySecMPPtr = new int[m_inSec];
	    
		for( i = 0; i<(m_inSec); i++)
		{
		
			*(m_arrayDirSecMPPtr + i) = 0;
			*(m_arraySecMPPtr + i) = i;
			
		}

	}
	 
	  */

}



int CCache2003View::GenID(int m_iRow, int m_iCol)
{
   int Contador = m_CtrlRejilla_MP.GetCols();

return (m_iCol + Contador*m_iRow);

}

CString CCache2003View::Bin(int n, int tam)
{
  char buffer0[20];
  int bit;
  CString binario;

	for (int i=tam-1; i>=0; i--) 
	{            
		bit = ((n >> i) & 1);            
		binario = binario + _itoa( bit, buffer0, 10);
	} 
return binario;

}

void CCache2003View::TamCeldasNoFijas_MC(long nFilasFijas, long nColFijas)
{
	CClientDC dc(this);
	long XPixelsPorPulgada = dc.GetDeviceCaps(LOGPIXELSX);
	long YPixelsPorPulgada = dc.GetDeviceCaps(LOGPIXELSY);

	CRect rect;
	m_CtrlRejilla_MC.GetWindowRect( rect );

	long AnchoCtrlRej, AltoCtrlRej;
	long AnchoColFija, AltoFilaFija;

	AnchoColFija = m_CtrlRejilla_MC.GetColWidth(0);
	AltoFilaFija = m_CtrlRejilla_MC.GetRowHeight(0);

	AnchoCtrlRej = rect.right - rect.left;
	AltoCtrlRej = rect.bottom - rect.top;

	AnchoCtrlRej = AnchoCtrlRej * 1440/XPixelsPorPulgada - AnchoColFija - 50;
	AltoCtrlRej = AltoCtrlRej * 1440/YPixelsPorPulgada - AltoFilaFija - 50;

	long Filas, Columnas;

	if( nFilasFijas <= 1)
	{
		Filas = 1;
	}
	else
	{
		Filas = nFilasFijas + 1;
	}

	if( nColFijas <= 6 )
	{
		Columnas = 6;
	}
	else
	{
		Columnas = nColFijas + 1;
	}

	m_CtrlRejilla_MC.SetRows(Filas);
	m_CtrlRejilla_MC.SetCols(Columnas);


	for( int i = 1; i <= Filas -1; i++ )
	{
		m_CtrlRejilla_MC.SetRowHeight( i, (AltoCtrlRej - 255 )/14);
	}

	for( i = 1; i <= Columnas - 1; i++ )
	{
		m_CtrlRejilla_MC.SetColWidth( i, (AnchoCtrlRej - 255 )/1);
	}


}


//Función SimulaDirecto_CAsig
//Función que realiza la simulación de comportamiento de Memoria Cache por el método Directo
//con asignación de escritura

void CCache2003View::SimulaDirecto_CAsig(int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr)
{
   int NPalabra, NBloque, NLinea, NPalabraBloque;
   int nLinea, nMP, nMC, nBloque, TamLinea;
   int Dato, Dir, Tipo, DatoEscrito, i, j; 
   int celda;
   int Acierto;
   int PosicionDato;
   
   
   Acierto = 0;
   
   /*
   char buf[6];
   CString s_contLineas, s_TamLinea, s_NLinea; */

    GetDlgItem(IDC_EDIT_MET_REEMPLAZA)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_REEMPLAZA)->EnableWindow(FALSE);

	
    GetDlgItem(IDC_STATIC_N_BLOQUES_CONJ) ->EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT_N_BLOQUES_CONJ) -> EnableWindow(FALSE);
    GetDlgItem(IDC_STATIC_N_CONJ) -> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_N_CONJ) -> EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_PALABRAS_CONJ) -> EnableWindow(FALSE);	
    GetDlgItem(IDC_EDIT_PALABRAS_CONJ) -> EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_CONJ_MC) -> EnableWindow(FALSE);	
    GetDlgItem(IDC_EDIT_CONJ) -> EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_LINEA_CONJ) -> EnableWindow(FALSE);	
    GetDlgItem(IDC_EDIT_N_LINEAS) -> EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);

	CDireccionDlg dlgDireccion;
   	CEscrituraDlg dlgEscritura;
   		
		if(m_iAutomatico_Sec == 1)
		{
			NPalabra = *(arrayDirSecMPPtr + nSim);
			
		}	
		else
		{	
			srand( time( 0 ));
			NPalabra = rand() % TamMP;
		}	
			
			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}

			
	
		
			
			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			
			
			nMP = dlgDireccion.ConvertBase2(TamMP);
			nMC = dlgDireccion.ConvertBase2(TamMC);
			nBloque = dlgDireccion.ConvertBase2(TamBloque);
			nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);   
	
			TamLinea = (int)pow(2, nLinea);
			 
   			NBloque = Truncar( NPalabra, TamBloque);
			NPalabraBloque = Sobrante( NPalabra, TamBloque);
			NLinea = NBloque % TamLinea;
	
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);

			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipos de datos correspondientes al bloque
			int *arregloTipoBloque = new int[ TamMP ];
			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';

			}

			

			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			m_NLinea = NLinea;
			
			

    
			//Identificación del Bloque en Memoria Principal
			
			for( i = 0; i<TamMP; i++)
			{
				
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					//Coloreado de celdas
					celda = 0;
					celda = i + 1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF); 
				   
				   
				   
				   }
				}
			

			}
		
								
			//Separación del Bloque encontrado en Memoria Principal
	
			
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];

			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j) = *(arregloTipoBloque + i);
					j++; 
				}
			}
	
			
	
	
		
			

			//Verificando Acierto o Fallo en Cache

			for( i = 0; i<TamMC; i++)
			{
				if(Dir == *(arrayDirMCPtr + i))
				{
					
					MessageBox("A C I E R T O!!! \nSe encontró la Palabra");
					contAciertos++;
					Acierto++;
					
					goto MC;
				}
	          
			}	  
					MessageBox("F A L L O!!!\nNo se encontró la Palabra");
					contFallos++;  
		  			/*
					s_contLineas = _itoa( *(contLineas + 1), buf, 5);
					s_TamLinea = _itoa( TamLinea, buf, 5);
					s_NLinea = _itoa( NLinea, buf, 5);
					MessageBox( "contLineas = " + s_contLineas + " TamLinea = " + s_TamLinea + " NLinea = " + s_NLinea );
					  */
					Contador( contLineas, TamLinea, NLinea, 3); 
				
					//AgregarPar();
							
//Introducción de Bloques a Memoria Cache 
MC:
									
			int Limite = NLinea*TamBloque;					
								
							
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite)
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							
														
							j++;
							Limite++;
							if( Acierto == 1)
							{
								ColorearMC( celda, 0, 0x0000FF00, 0x00000000); 
								ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 
								ColorearMC( celda, 2, 0x0000FF00, 0x00000000);
								ColorearMC( celda, 3, 0x0000FF00, 0x00000000);
							}
						    else
							{
								
								ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
								ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);

							}
						
										
						}
					} 
	      	
				}
			
						
				//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;
						PosicionDato = i;
						
						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
			
				}
				
				
			    

				
				 	

				//Impresión de contenido de arreglo de Memoria Cache			 
				
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);

				
//Introduccion de Bloques en MP

			   	
			
				
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	*(arrayDatosMPPtr + j) = *(arrayDatosMCPtr + PosicionDato);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
				ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

				
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}


					}
					else
					{
						nSim++;

						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						UpdateData(false);
					}
				}
				else
				{
					 nSim++;

					 m_contAciertos = contAciertos;
					 m_contFallos = contFallos;
					 m_nSim = nSim;
					 UpdateData(false);
				}

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);

				ImprimeFormatoSim(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea);

	   delete arrayDirBloque;
	   delete arrayDatBloque;
	   delete arrayTipoBloque;
	   delete arregloDirBloque;
	   delete arregloDatBloque;
	   delete arregloTipoBloque;

}


void CCache2003View::OnSimular()							   
{
	
	CCache2003Doc *pDoc = GetDocument();

	int total = pDoc->ObtenerTotalRegistros();
	if( total == 0 )
	{
		MessageBox( "No se puede simular. La memoria principal está vacía");
		return;
	}


	int total_sec = pDoc->ObtenerTotalSecuencias();
	if( total_sec > 0)
	{
	    GetDlgItem(IDC_STATIC_REG_SEC) -> EnableWindow(TRUE);
	    GetDlgItem(IDC_B_PRIMERO_SEC) -> EnableWindow(TRUE);
	    GetDlgItem(IDC_B_ANTERIOR_SEC) -> EnableWindow(TRUE);
	    GetDlgItem(IDC_B_SIGUIENTE_SEC) -> EnableWindow(TRUE);
	    GetDlgItem(IDC_B_ULTIMO_SEC) -> EnableWindow(TRUE);
	    GetDlgItem(IDC_EDIT_DIR_SEC) -> EnableWindow(TRUE);	
		GetDlgItem(IDC_SIMULAR) -> EnableWindow(TRUE);	
		GetDlgItem(IDC_B_AGREGAR) ->EnableWindow(FALSE);
	}



	//activa controles CFormView
	GetDlgItem(IDC_EDIT_DATO)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_TIPO)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_DATO_MC)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_SIMULACIONES)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_ACIERTOS)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_FALLOS)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_PALABRA)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_BLOQUE)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_PALABRA_BLOQUE)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_LINEA)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_CONJ)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_N_LINEAS)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_TA)->EnableWindow(TRUE);

	
	GetDlgItem(IDC_STATIC_DATO)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_DATO_MC)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_SIMULACIONES)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_ACIERTOS)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_FALLOS)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_PALABRA)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_BLOQUE)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_PALABRA_BLOQUE)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_LINEA)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_CONJ_MC)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_LINEA_CONJ)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_TA)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_NS)->EnableWindow(TRUE);

	GetDlgItem(IDC_BTN_LLENAR_MP) -> EnableWindow(FALSE);
	GetDlgItem(IDC_SIMULAR) -> EnableWindow(TRUE);
	
	//Repintado de celdas MP a su color original
	
	for(int i = 1; i<=m_TamMP; i++)
	{
		ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
		ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
		ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
		ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
		ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
		ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
	}
	
	//Repintado de celdas MC a su color original
	
	for(i = 1; i<=m_TamMC; i++)
	{
		ColorearMC( i, 0, 0x00CCCCCC, 0x00FF0000); 
		ColorearMC( i, 1, 0x00FFFFFF, 0x00FF0000);
		ColorearMC( i, 2, 0x00FFFFFF, 0x00FF0000);
		ColorearMC( i, 3, 0x00FFFFFF, 0x00FF0000);
		ColorearMC( i, 4, 0x00FFFFFF, 0x00FF0000);
		ColorearMC( i, 5, 0x00FFFFFF, 0x00FF0000);

	}


	
			
CEscrituraDlg dlgEscritura;
	

	switch(m_iP_Emplazamiento)
	{
		case 0:
			//MessageBox("M E T O D O    D I R E C T O");
			
			switch(m_iTip_Esc)
			{
				case 0:
					//MessageBox("Politica de Actualización : Escritura Directa");
					if( m_iAsignacion == 0)
					{
					
						SimulaDirecto_CAsig( m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_arrayDirSecMPPtr);
						//MessageBox("Con Asiganción en Escritura");
					}
					else
					{
						SimulaDirecto_SAsig( m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_arrayDirSecMPPtr);
						//MessageBox("Sin Asiganción en Escritura");

					}

				break;
				case 1:
					//MessageBox("Politica de Actualización : Post-Escritura");
					SimulaDirecto_Post( m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_arrayDirSecMPPtr);
				break;
			}

		
		break;
		
		case 1:
			//MessageBox("M E T O D O    A S O C I A T I V O"); 
			SimulaAsociativo(m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas);

		break;
			
		case 2:
			//MessageBox("M E T O D O    A S O C I A T I V O    P O R     C O N J U N T O S");
			SimulaAConjuntos( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_nVias);
			ColorearConjuntos(m_TamMC, m_TamBloque, m_nVias);
		break;
		
		default:
			
			//MessageBox("ERROR: El valor digitado no es una opción valida.");
		
		break;
	}

CalculoTa();
ActualizarEscrituras( m_nEscrituras, m_in_Bloques_MP, m_TamMP, m_iBasico, m_iParalelo, m_fTp, m_fTc, m_iTip_Esc, m_iAsignacion);
m_dlgEstadisticas.UpdateData(false);


	
}


//Función Trunca
//Función que devuelve el resultado entero de una división sin los decimales

int CCache2003View::Truncar(int dividendo, int divisor)
{
	int Cociente;
	Cociente = dividendo / divisor;

return Cociente;
}


//Función Sobrante
//Función que devuelve el residuo o sobrante de una división en forma de entero

int CCache2003View::Sobrante(int dividendo, int divisor)
{
    int Residuo;
	Residuo = dividendo % divisor;

return Residuo;

}
 


//Funcion ImprimeFormato
//Función que imprime la dirección y los datos en esa dirección


void CCache2003View::ImprimeFormatoMC(int n, int tam, int *arreglodir, int *arreglodatos, int *arreglotipo)
{
    char bufferDato[10];
	char bufferDireccion[10];
	int i;
	int i_Dato;
	int i_Direccion;
	int i_Tipo; 
	CString s_Dato;
	CString s_Direccion;
	
	CMenu *pMenu = GetParentFrame()->GetMenu();
	
	if( pMenu->GetMenuState(ID_FORMAT_DECIMAL, MF_BYCOMMAND) == MF_CHECKED)
	{

		for( i = 0; i < tam; i++)
		{
		
		i_Dato = *(arreglodatos + i); 
	    s_Dato = _itoa( i_Dato , bufferDato, 10);
		i_Direccion = *(arreglodir + i);
		s_Direccion = _itoa( i_Direccion  , bufferDireccion, 10);		
		i_Tipo = *(arreglotipo + i);
		
			if( *(arreglodir + i) == -1 )
			{
				m_CtrlRejilla_MC.SetTextArray(GenID(i + 1,0), NULL);
				m_CtrlRejilla_MC.SetTextArray(GenID(i + 1,1), NULL);
				m_CtrlRejilla_MC.SetTextArray(GenID(i + 1,2), NULL);
			}
			else
			{
				//Formato Decimal
				m_CtrlRejilla_MC.SetTextArray(GenID(i+1 ,0),s_Direccion);
				m_CtrlRejilla_MC.SetTextArray(GenID(i+1 ,1),s_Dato);
				//Formato Lectura Escritura
				switch(i_Tipo)
				{
					case 1:
						m_CtrlRejilla_MC.SetTextArray(GenID(i+1 ,2),"Lectura");
					break;
					case 2:
						m_CtrlRejilla_MC.SetTextArray(GenID(i+1 ,2),"Escritura");
					break;
				}

			}			
		}
		
				
	}	
	
	
	
	
	if( pMenu->GetMenuState(ID_FORMAT_BINARIO, MF_BYCOMMAND) == MF_CHECKED)
	{

		for( i = 0; i < tam; i++)
		{
		
		i_Dato = *(arreglodatos + i); 
	    s_Dato = _itoa( i_Dato , bufferDato, 10);
		i_Direccion = *(arreglodir + i);
		s_Direccion = _itoa( i_Direccion  , bufferDireccion, 10);		
		i_Tipo = *(arreglotipo + i);

			if( *(arreglodatos + i) == 0 )
			{
				m_CtrlRejilla_MC.SetTextArray(GenID(i + 1,0), NULL);
				m_CtrlRejilla_MC.SetTextArray(GenID(i + 1,1), NULL);
			}
			else
			{
		   		//Formato binario
				m_CtrlRejilla_MC.SetTextArray(GenID(i +1,0),Bin(i_Direccion, n));
				m_CtrlRejilla_MC.SetTextArray(GenID(i +1,1),Bin(i_Dato , 16));
				//Formato Lectura Escritura
				switch(i_Tipo)
				{
					case 1:
						m_CtrlRejilla_MC.SetTextArray(GenID(i+1 ,2),"Lectura");
					break;
					case 2:
						m_CtrlRejilla_MC.SetTextArray(GenID(i+1 ,2),"Escritura");
					break;
				}

			}
		}
	
	  
	}

	if( pMenu->GetMenuState(ID_FORMAT_OCTAL, MF_BYCOMMAND) == MF_CHECKED)
	{

		for( i = 0; i < tam; i++)
		{
		
		i_Dato = *(arreglodatos + i); 
	    s_Dato = _itoa( i_Dato , bufferDato, 10);
		i_Direccion = *(arreglodir + i);
		s_Direccion = _itoa( i_Direccion  , bufferDireccion, 10);		
		i_Tipo = *(arreglotipo + i);

			if( *(arreglodatos + i) == 0 )
			{
				m_CtrlRejilla_MC.SetTextArray(GenID(i + 1,0), NULL);
				m_CtrlRejilla_MC.SetTextArray(GenID(i + 1,1), NULL);
			}
			else
			{
				//Formato octal
				m_CtrlRejilla_MC.SetTextArray(GenID(i +1,0),Oct(i_Direccion));
				m_CtrlRejilla_MC.SetTextArray(GenID(i +1,1),Oct(i_Dato));
				m_CtrlRejilla_MC.SetColAlignment(0, 6);
				m_CtrlRejilla_MC.SetColAlignment(1, 6);
		
				//Formato Lectura Escritura
				switch(i_Tipo)
				{
					case 1:
						m_CtrlRejilla_MC.SetTextArray(GenID(i+1 ,2),"Lectura");
					break;
					case 2:
						m_CtrlRejilla_MC.SetTextArray(GenID(i+1 ,2),"Escritura");
					break;
				}

			}
		}
	}
	
	if( pMenu->GetMenuState(ID_FORMAT_HEXADECIMAL, MF_BYCOMMAND) == MF_CHECKED)
	{

		for( i = 0; i < tam; i++)
		{
		
		i_Dato = *(arreglodatos + i); 
	    s_Dato = _itoa( i_Dato , bufferDato, 10);
		i_Direccion = *(arreglodir + i);
		s_Direccion = _itoa( i_Direccion  , bufferDireccion, 10);		
		i_Tipo = *(arreglotipo + i);

		    if( *(arreglodatos + i) == 0 )
			{
				m_CtrlRejilla_MC.SetTextArray(GenID(i + 1,0), NULL);
				m_CtrlRejilla_MC.SetTextArray(GenID(i + 1,1), NULL);
			}
			else
			{

				//Formato hexadecimal
				m_CtrlRejilla_MC.SetTextArray(GenID(i +1,0),Hex(i_Direccion));
				m_CtrlRejilla_MC.SetTextArray(GenID(i +1,1),Hex(i_Dato));
				m_CtrlRejilla_MC.SetColAlignment(0, 6);
				m_CtrlRejilla_MC.SetColAlignment(1, 6);
		
				//Formato Lectura Escritura
				switch(i_Tipo)
				{
					case 1:
						m_CtrlRejilla_MC.SetTextArray(GenID(i+1 ,2),"Lectura");
					break;
					case 2:
						m_CtrlRejilla_MC.SetTextArray(GenID(i+1 ,2),"Escritura");
					break;
				}

			}
		}
	}


	
	
	
}




void CCache2003View::ImprimeFormatoMP(int n, int tam, int *arreglodir, int *arreglodatos, int *arreglotipo)
{
	char bufferDato[10];
	char bufferDireccion[10];
	int i;
	int i_Dato;
	int i_Direccion;
	int i_Tipo;
	CString s_Dato;
	CString s_Direccion;
	
	
	CMenu *pMenu = GetParentFrame()->GetMenu();
	
	if( pMenu->GetMenuState(ID_FORMAT_DECIMAL, MF_BYCOMMAND) == MF_CHECKED)
	{

		for( i = 0; i < tam; i++)
		{
		
		i_Dato = *(arreglodatos + i); 
	    s_Dato = _itoa( i_Dato , bufferDato, 10);
		i_Direccion = *(arreglodir + i);
		s_Direccion = _itoa( i_Direccion  , bufferDireccion, 10);		
		i_Tipo = *(arreglotipo + i);

		
		//Formato Decimal
		m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,0),s_Direccion);
	    m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,1),s_Dato);
		//Formato Lectura Escritura
		switch(i_Tipo)
		{
			case 1:
				m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Lectura");
			break;
			case 2:
				m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Escritura");
			break;
		}

		
		}
	}	
	
	if( pMenu->GetMenuState(ID_FORMAT_BINARIO, MF_BYCOMMAND) == MF_CHECKED)
	{

		for( i = 0; i < tam; i++)
		{
		
		i_Dato = *(arreglodatos + i); 
	    s_Dato = _itoa( i_Dato , bufferDato, 10);
		i_Direccion = *(arreglodir + i);
		s_Direccion = _itoa( i_Direccion  , bufferDireccion, 10);		
		i_Tipo = *(arreglotipo + i);
		
		//Formato Binario
		m_CtrlRejilla_MP.SetTextArray(GenID(i +1,0),Bin(i_Direccion, n));
	    m_CtrlRejilla_MP.SetTextArray(GenID(i +1,1),Bin(i_Dato , 16));
		//Formato Lectura Escritura
		switch(i_Tipo)
		{
			case 1:
				m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Lectura");
			break;
			case 2:
				m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Escritura");
			break;
		}

		}
	}

	if( pMenu->GetMenuState(ID_FORMAT_OCTAL, MF_BYCOMMAND) == MF_CHECKED)
	{

		for( i = 0; i < tam; i++)
		{
		
		i_Dato = *(arreglodatos + i); 
	    s_Dato = _itoa( i_Dato , bufferDato, 10);
		i_Direccion = *(arreglodir + i);
		s_Direccion = _itoa( i_Direccion  , bufferDireccion, 10);		
		i_Tipo = *(arreglotipo + i);
		
		//Formato Octal
		m_CtrlRejilla_MP.SetTextArray(GenID(i +1,0),Oct(i_Direccion));
	    m_CtrlRejilla_MP.SetTextArray(GenID(i +1,1),Oct(i_Dato));
		m_CtrlRejilla_MP.SetColAlignment(0, 6);
		m_CtrlRejilla_MP.SetColAlignment(1, 6);
		
		//Formato Lectura Escritura
		switch(i_Tipo)
		{
			case 1:
				m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Lectura");
			break;
			case 2:
				m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Escritura");
			break;
		}

		}
	}
	
	if( pMenu->GetMenuState(ID_FORMAT_HEXADECIMAL, MF_BYCOMMAND) == MF_CHECKED)
	{

		for( i = 0; i < tam; i++)
		{
		
		i_Dato = *(arreglodatos + i); 
	    s_Dato = _itoa( i_Dato , bufferDato, 10);
		i_Direccion = *(arreglodir + i);
		s_Direccion = _itoa( i_Direccion  , bufferDireccion, 10);		
		i_Tipo = *(arreglotipo + i);
		
		//Formato Hexadecimal
		m_CtrlRejilla_MP.SetTextArray(GenID(i +1,0),Hex(i_Direccion));
	    m_CtrlRejilla_MP.SetTextArray(GenID(i +1,1),Hex(i_Dato));
		m_CtrlRejilla_MP.SetColAlignment(0, 6);
		m_CtrlRejilla_MP.SetColAlignment(1, 6);
		

		//Formato Lectura Escritura
		switch(i_Tipo)
		{
			case 1:
				m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Lectura");
			break;
			case 2:
				m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Escritura");
			break;
		}

		}
	}

	

}

void CCache2003View::ColorearMP(int fil, int col, int fondo, int fuente)
{
    m_CtrlRejilla_MP.SetRow(fil);
	m_CtrlRejilla_MP.SetCol(col);
	m_CtrlRejilla_MP.SetCellBackColor(fondo);
	m_CtrlRejilla_MP.SetCellForeColor(fuente);
	m_CtrlRejilla_MP.Refresh();

}

void CCache2003View::ColorearMC(int fil, int col, int fondo, int fuente)
{
	m_CtrlRejilla_MC.SetRow(fil);
	m_CtrlRejilla_MC.SetCol(col);
	m_CtrlRejilla_MC.SetCellBackColor(fondo);
	m_CtrlRejilla_MC.SetCellForeColor(fuente);
	m_CtrlRejilla_MC.Refresh();

}


//Función SimulaAsociativo
//Función que escoge política de reemplazamiento en  la simulación de comportamiento de Memoria Cache

void CCache2003View::SimulaAsociativo(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas)
{
   	
	GetDlgItem(IDC_STATIC_N_BLOQUES_CONJ) ->EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT_N_BLOQUES_CONJ) -> EnableWindow(FALSE);
    GetDlgItem(IDC_STATIC_N_CONJ) -> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_N_CONJ) -> EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_PALABRAS_CONJ) -> EnableWindow(FALSE);	
    GetDlgItem(IDC_EDIT_PALABRAS_CONJ) -> EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_CONJ_MC) -> EnableWindow(FALSE);	
    GetDlgItem(IDC_EDIT_CONJ) -> EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_LINEA_CONJ) -> EnableWindow(FALSE);	
    GetDlgItem(IDC_EDIT_N_LINEAS) -> EnableWindow(FALSE);

	switch (m_iP_Reemplazamiento)
	{
	case 0:
		//MessageBox("POLITICA DE SUSTITUCION : A L E A T O R I O"); 
		switch(m_iTip_Esc)
		{
			case 0:
				//MessageBox("Politica de Actualización : Escritura Directa");
				if( m_iAsignacion == 0)
				{

					A_Aleatorio_CAsig( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_arrayDirSecMPPtr);
					//MessageBox("Con Asiganción en Escritura");
				}
				else
				{
					A_Aleatorio_SAsig( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_arrayDirSecMPPtr);
					//MessageBox("Sin Asiganción en Escritura");
				}
		    break;
	        case 1:
	            //MessageBox("Politica de Actualización : Post-Escritura");
	            A_Aleatorio_Post( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_arrayDirSecMPPtr);
	        break;
		}
				
	break;	
	case 1:
		//MessageBox("POLITICA DE SUSTITUCION : L R U");
		switch(m_iTip_Esc)
		{
			case 0:
				//MessageBox("Politica de Actualización : Escritura Directa");
				if( m_iAsignacion == 0)
				{

					A_LRU_CAsig( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_contEdad, m_arrayDirSecMPPtr);
					//MessageBox("Con Asiganción en Escritura");
				}
				else
				{
					A_LRU_SAsig( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_contEdad, m_arrayDirSecMPPtr);
					//MessageBox("Sin Asiganción en Escritura");
				}
		    break;
	        case 1:
	            //MessageBox("Politica de Actualización : Post-Escritura");
	            A_LRU_Post( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_contEdad, m_arrayDirSecMPPtr);
	        break;
		}

		break;
	case 2:
		//MessageBox("POLITICA DE SUSTITUCION : L F U");
		
		switch(m_iTip_Esc)
		{
			case 0:
				//MessageBox("Politica de Actualización : Escritura Directa");
				if( m_iAsignacion == 0)
				{

					A_LFU_CAsig( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_contFrec, m_arrayDirSecMPPtr);
					//MessageBox("Con Asiganción en Escritura");
				}
				else
				{
					A_LFU_SAsig( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_contFrec, m_arrayDirSecMPPtr);
					//MessageBox("Sin Asiganción en Escritura");
				}
		    break;
	        case 1:
	            //MessageBox("Politica de Actualización : Post-Escritura");
	            A_LFU_Post( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_contFrec, m_arrayDirSecMPPtr);
	        break;
		}


		
		break;
	case 3:
		//MessageBox("POLITICA DE SUSTITUCION : F I F O");
		
		switch(m_iTip_Esc)
		{
			case 0:
				//MessageBox("Politica de Actualización : Escritura Directa");
				if( m_iAsignacion == 0)
				{

					A_FIFO_CAsig( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_arrayDirSecMPPtr);
					//MessageBox("Con Asiganción en Escritura");
				}
				else
				{
					A_FIFO_SAsig( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_arrayDirSecMPPtr);
					//MessageBox("Sin Asiganción en Escritura");
				}
		    break;
	        case 1:
	            //MessageBox("Politica de Actualización : Post-Escritura");
	            A_FIFO_Post( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_arrayDirSecMPPtr);
	        break;
		}


		break;
	default:
		//MessageBox("ERROR: El valor digitado no es una opción valida.");
	    break;
	}

}


//Función A_Aleatorio_CAsig
//Función que realiza la sustitución aleatorio de Memoria Cache 
//por Método Asociativo con asignacion de escritura 

void CCache2003View::A_Aleatorio_CAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr)
{

	int NPalabra, NBloque, NPalabraBloque, NLinea;
	int nLinea, nMP, nMC, nBloque, TamLinea;
	int Dato, DatoEscrito, Dir, Tipo, i, j, Limite; 
	int celda;
    int Acierto;
	int PosicionDatoMP;
	
	NLinea = Ini_Linea;
	
	Acierto = 0;
	PosicionDatoMP = 0;
	CDireccionDlg dlgDireccion;
	 
    
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);

	 	   	
			     
	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			//Validación de dirección
			if( Dato == 0 )
			{
				MessageBox("ERROR.No se encuentra dato en la dirección requerida.\nEdite el dato o la secuencia para continuar con la simulación.");
				return;
			}
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}

			
			

			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			
			



			nMP = dlgDireccion.ConvertBase2(TamMP);
			nMC = dlgDireccion.ConvertBase2(TamMC);
			nBloque = dlgDireccion.ConvertBase2(TamBloque);
			nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);
			
			TamLinea = (int)pow(2, nLinea);
			
			NBloque = Truncar( NPalabra, TamBloque);
			NPalabraBloque = Sobrante( NPalabra, TamBloque);
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);

			
			//Arreglo temporal para buscar direcciones correspondientes al bloque en MP
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MP
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];


			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];
			
			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';

			}

									
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			
						    
			//Identificación del Bloque en Memoria Principal
			
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000); 
					
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF);
				   
				   PosicionDatoMP = i;
				   
				   }

				
				}
			}
		
				
			//Separación del Bloque encontrado en Memoria Principal
			//Bloque de Direcciones y Datos a traspasar a Cache...  
			
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];


			j = 0;
			
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);

					j++; 
				}
			}
	
			//ImprimeFormato( nMP, TamBloque, arrayDirBloque, arrayDatBloque);
	
	
		
			
			//Verificando Acierto o Fallo en Cache

			
			for( i = 0; i<TamMC; i++)
			{
				if(Dir == *(arrayDirMCPtr + i))
				{
										
					//Identificación del Bloque en Memoria Cache
					int NBloqueMC = Truncar(i, TamBloque);
					
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{
						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);

							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
					
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
				   			ColorearMC( celda, 2, 0x0000FF00, 0x00000000);
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000);

						}
					}
					
					m_NLinea = NBloqueMC;
					
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
					
				}
				
	          
			}	  
					MessageBox("F A L L O!!! \nNo se encontró la Palabra");
					contFallos++;   
				
			//Llenado en orden de bloques en Memoria Cache cuando está vacía
		 
	        	
			if( *(arrayDatosMCPtr + (w)*TamBloque ) == '\0')
			{
				NLinea++;
				m_NLinea = NLinea;
				
			}

			else
			{
				srand( time( 0) );
				NLinea = rand() % TamLinea;
				m_NLinea = NLinea;
				
			}
			
			//Introducción de Bloques a Memoria Cache 
				
				Limite = NLinea*TamBloque;			  			
					
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite)
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      	
				
				}
			
				Contador( contLineas, TamLinea, NLinea, 3);
				//AgregarPar();
			//Introduccion de Bloques en MP

			
							
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

			
		


Salir:	
			
			//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;
						
						
						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

						
				
			if(w < TamLinea)
			{ 
				w++;
			}
			else
			{
				w = TamLinea;
			}
													
				//Impresión de contenido de arreglo de Memoria Cache			 
				
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
		
		

				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}
				
				

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);

		

		ImprimeFormatoSim(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea);

		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;
}

//Función A_LRU_CAsig ( Sustituye el bloque que lleva más tiempo sin haber sido utilizado )
//Simula la Politica de sustitución Least Recently Use en Memoria Cache Método Asociativo
//con asignación de escritura

void CCache2003View::A_LRU_CAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contEdad, int *arrayDirSecMPPtr)
{
	int NPalabra, NBloque, NLinea, NPalabraBloque;
	int nLinea, nMP, nMC, nBloque, TamLinea;
	int Dir, Dato, DatoEscrito, Tipo, i, j, Limite; 
	int celda;
	int Acierto;
	int PosicionDatoMP;

	NLinea = Ini_Linea;  
	
	Acierto = 0;
	PosicionDatoMP = 0;

	CDireccionDlg dlgDireccion;
	 
    
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_EDAD) -> EnableWindow(TRUE);


	nMP = dlgDireccion.ConvertBase2(TamMP);
	nMC = dlgDireccion.ConvertBase2(TamMC);
	nBloque = dlgDireccion.ConvertBase2(TamBloque);
	nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);

	TamLinea = (int)pow(2, nLinea);
	
	
	

		//Comienzo Simulación
	 
	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}

			

			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			

			
			
			NBloque = Truncar( NPalabra, TamBloque);
			NPalabraBloque = Sobrante( NPalabra, TamBloque);
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			//UpdateData(false);

			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			

			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

						
			
			    
			//Identificación del Bloque en Memoria Principal
			
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);

					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF); 
				   
				   PosicionDatoMP = i;
				   
				   }


				}
			}
		
			
				
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];

			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);
					j++; 
				}
			}
	
				
			//Verificando Acierto o Fallo en Cache
									
			
			for( i = 0; i<TamMC; i++)
			{
				
				//Identificación del Bloque en Memoria Cache
				int NBloqueMC = Truncar(i, TamBloque);
				
				
				if(Dir == *(arrayDirMCPtr + i))
				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					            		
					
					
					int NLineaAcierto;
					NLineaAcierto = i/TamBloque;
					m_NLinea = NLineaAcierto;
					
					
					 
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
				
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
							ColorearMC( celda, 2, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000); 		
							ColorearMC( celda, 4, 0x0000FF00, 0x00000000); 
						}
					}

      			

					
					int contActual;
					
					for( j = 0; j<TamLinea; j++)
					{
						if( NLineaAcierto == j) 
						{ 
							contActual = *(contEdad + j);
						    						     
						}	
						
					}
					for(j = 0; j<TamLinea; j++)
					{
						if(*(contEdad + j)  <  contActual )
						{ 
							++*(contEdad + j);
						}
					   
						if( NLineaAcierto == j)
						{
						*(contEdad + j ) = 0;
						}
					 					 	
					}
					
					
								
					
					ImprimeContadores( contEdad, TamLinea, 4);
					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					
					MessageBox("F A L L O!!!\nNo se encontró la Palabra");
					contFallos++;   
				
			//Llenado de bloques en Memoria Cache cuando está vacía
            		 

			
			
			if( *(arrayDatosMCPtr + (w)*TamBloque ) == '\0')
			{
				NLinea++;
				m_NLinea = NLinea;
				
				
				for( i = 0; i<TamLinea; i++)
				{



					if( i == NLinea )
					{
					   *(contEdad + NLinea) = 0;
	                   				
					}	
					else
					{
						++*(contEdad + i); 
					 					    
					}
				 				
				}
                
				ImprimeContadores(contEdad, TamLinea, 4);

			}
			else   //Llenado cuando esta llena la Cache
			{
				for(i = 0; i<TamLinea; i++)
				{
					
					if( *(contEdad + i) == (TamLinea - 1))
					{
					   NLinea = i;
					   m_NLinea = NLinea;
					   
					}
				
				}
			    
				ImprimeContadores( contEdad, TamLinea, 4);
			}
			
			//Introducción de Bloques a Memoria Cache 
				
				Limite = NLinea*TamBloque;			  			
					
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite)
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);

							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 4, 0x000000FF, 0x00FFFFFF);
						}
					} 
	      	
				
				}
			
				Contador( contLineas, TamLinea, NLinea, 3);

			
			//Introduccion de Bloques en MP
						   	
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;


					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);


			//AgregarPar();


Salir:	
			
			//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;
						
						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
							
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
							
						}
					}
				}

			
			if(w < TamLinea -1 )
			{ 
				w++;
			}
			else
			{
				w = TamLinea - 1 ;
			}
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}
				
				
			  				
				//Impresión de contenido de arreglo de Memoria Cache			 
				
               	ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);
				
		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;

		

		ImprimeFormatoSim(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea);
}




//Función A_LFU_CAsig ( Sustituye el bloque que haya sido menos utilizado )
//Simula la Politica de sustitución Least Frecuently Use en Memoria Cache Método Asociativo
//con asignacion de escritura

void CCache2003View::A_LFU_CAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contFrec, int *arrayDirSecMPPtr)
{
 int NPalabra, NBloque, NLinea, NPalabraBloque;
 int nLinea, nMP, nMC, nBloque, TamLinea;
 int Dir, Dato, DatoEscrito, Tipo, i, j, Limite; 
 int posMayor = 0;
 int posMenor = 0;
 int celda;
 int Acierto;
 int PosicionDatoMP;

 NLinea = Ini_Linea;  
 
 Acierto = 0;
 PosicionDatoMP = 0;	

	CDireccionDlg dlgDireccion;
	 
    
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_FREC) -> EnableWindow(TRUE);


	nMP = dlgDireccion.ConvertBase2(TamMP);
	nMC = dlgDireccion.ConvertBase2(TamMC);
	nBloque = dlgDireccion.ConvertBase2(TamBloque);
	nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);

	TamLinea = (int)pow(2, nLinea);
			

	
	
	//Comienzo Simulación
	
	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			
			
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}


			
			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			

			
			NBloque = Truncar( NPalabra, TamBloque);
			NPalabraBloque = Sobrante( NPalabra, TamBloque);
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			
			//UpdateData(false);

			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			
						
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0'; 
				*(arregloTipoBloque + i)= '\0';


			}

				
			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';

			}

			
						    
			//Identificación del Bloque en Memoria Principal
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					
					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF);
				   
				   PosicionDatoMP = i;
				   }


				}
			}
		
			
	
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];

			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);

					j++; 
				}
			}
	
			
			
						
			//Verificando Acierto o Fallo en Cache

						
			
			for( i = 0; i<TamMC; i++)
			{
				int NBloqueMC = Truncar(i, TamBloque);


				if(Dir == *(arrayDirMCPtr + i))
				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					            		
					NLinea = i/TamBloque;
					m_NLinea = NLinea;
					
					
					
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
				
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
							ColorearMC( celda, 2, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000); 
							ColorearMC( celda, 5, 0x0000FF00, 0x00000000);
						}
					}



					m_NLinea = NLinea;
					

					
					for( i = 0; i<TamLinea; i++)
					{
					    if( i == NLinea )
						{
							++*(contFrec + i);
						}		
					}
					
							
					ImprimeContadores( contFrec, TamLinea, 5);
					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!! \nNose encontró la Palabra");
					contFallos++;   
				
			
			//Llenado de bloques en Memoria Cache cuando está vacía
            		
			if( *(arrayDatosMCPtr + (w)*TamBloque ) == '\0')
			{
				NLinea++;

				int Menor = *(contFrec + 0);

				for(i = 0; i<TamLinea; i++)
				{
										
					if( *(contFrec + i) < Menor)
					{
						Menor = *(contFrec + i);
						NLinea = i;
					}
				    								
				}						
						
					
								
				++*(contFrec + NLinea);
				m_NLinea = NLinea;
				
				ImprimeContadores(contFrec, TamLinea, 5);	                   				
			}	
				 
					 					    
			else   //Llenado cuando esta llena la Cache
			{
				
				int Mayor = 0;
				for( i= 0; i<TamLinea; i++)
				{
					if( *(contFrec + i) > Mayor)
					{
						Mayor = *(contFrec + i);
						posMayor = i;
					}
	            		
				}
				
				
				
				int Menor = *(contFrec + posMayor);
                 
				for(i = 0; i<TamLinea; i++)
				{
										
					if( *(contFrec + i) < Menor)
					{
						Menor = *(contFrec + i);
						posMenor = i;
						NLinea = posMenor;
					}
					else
					{
						NLinea = posMenor;
					}
					
				 } 
				
				++*(contFrec + NLinea);
				ImprimeContadores( contFrec, TamLinea, 5);
			}
			
			//Introducción de Bloques a Memoria Cache 
				
				Limite = NLinea*TamBloque;			  			
					
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite)
						{
							celda = 0;
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 5, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      	
				
				}
			
			   Contador( contLineas, TamLinea, NLinea, 3);

			//Introduccion de Bloques en MP
					   	
										
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

			
			//AgregarPar();


Salir:	
			
			//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;

						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

			
				
			
			if(w < TamLinea -1)
			{ 
				w++;
			}
			else
			{
				w = 0;
			}
				

												
				//Impresión de contenido de arreglo de Memoria Cache			 
				
                ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);

				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}
				
				

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);

				ImprimeFormatoSim(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea);
			
		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;
		
			

}

//Función A_FIFO_CAsig ( Sustituye los bloques en forma First In First Out )
//Simula la Politica de sustitución Aleatoria en Memoria Cache por Método Asociativo
//con asignacion de escritura

void CCache2003View::A_FIFO_CAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr)
{
 int NPalabra, NBloque, NLinea, NPalabraBloque;
 int nLinea, nMP, nMC, nBloque, TamLinea;
 int Dir, Dato, DatoEscrito, Tipo, i, j, Limite; 
 int posMayor = 0;
 int posMenor = 0;
 int celda;
 int Acierto;   
 int PosicionDatoMP;

 NLinea = Ini_Linea;  
 
 Acierto = 0;
 PosicionDatoMP = 0;	
    
    CDireccionDlg dlgDireccion;
	 
    
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);


	nMP = dlgDireccion.ConvertBase2(TamMP);
	nMC = dlgDireccion.ConvertBase2(TamMC);
	nBloque = dlgDireccion.ConvertBase2(TamBloque);
	nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);

	TamLinea = (int)pow(2, nLinea);
			

	
	
	//Comienzo Simulación
	
	
	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}

			

			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			

			
			
			NBloque = Truncar( NPalabra, TamBloque);
			NPalabraBloque = Sobrante( NPalabra, TamBloque);
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			


						
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

					
			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';

			}

			
			
			    
			//Identificación del Bloque en Memoria Principal
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					
					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF);
				   
				   PosicionDatoMP = i;
				   }


				}
			}
		
			//ImprimeFormato( nMP, TamMP, arregloDirBloque, arregloDatBloque);
	
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];

			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);
					
					j++; 
				}
			}
	
			
									
			//Verificando Acierto o Fallo en Cache

						
			
			for( i = 0; i<TamMC; i++)
			{
				int NBloqueMC = Truncar(i, TamBloque);


				if(Dir == *(arrayDirMCPtr + i))
				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					            		
					NLinea = i/TamBloque;
					m_NLinea = NLinea;
					
					
					
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);

							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
				
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
							ColorearMC( celda, 2, 0x0000FF00, 0x00000000); 
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000);
						}
					}



					m_NLinea = NLinea;
					

					
					ImprimeContadores( contLineas, TamLinea, 3);
					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!! \nNose encontró la Palabra");
					contFallos++;   
				
			//Llenado de bloques en Memoria Cache cuando está vacía
            		 
			
			
			if( *(arrayDatosMCPtr + (w)*TamBloque ) == '\0')
			{
				NLinea++;

				int Menor = *(contLineas + 0);

				for(i = 0; i<TamLinea; i++)
				{
										
					if( *(contLineas + i) < Menor)
					{
						Menor = *(contLineas + i);
						NLinea = i;
					}
				    								
				}						
						
					
								
				++*(contLineas + NLinea);
				m_NLinea = NLinea;
				
				ImprimeContadores(contLineas, TamLinea, 3);	                   				
			}	
				 
					 					    
			else   //Llenado cuando esta llena la Cache
			{
				
				int Mayor = 0;
				for( i= 0; i<TamLinea; i++)
				{
					if( *(contLineas + i) > Mayor)
					{
						Mayor = *(contLineas + i);
						posMayor = i;
					}
	            		
				}
				
				
				
				int Menor = *(contLineas + posMayor);
                 
				for(i = 0; i<TamLinea; i++)
				{
										
					if( *(contLineas + i) < Menor)
					{
						Menor = *(contLineas + i);
						posMenor = i;
						NLinea = posMenor;
					}
					else
					{
						NLinea = posMenor;
					}
					
				 } 
				
				++*(contLineas + NLinea);
				ImprimeContadores( contLineas, TamLinea, 3);
			}
			
			//Introducción de Bloques a Memoria Cache 
				
				Limite = NLinea*TamBloque;			  			
					
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite)
						{
							celda = 0;
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);

							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
						}
					} 
	      	
				
				}
			
			  
			//Introduccion de Bloques en MP
				
							
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

			//AgregarPar();

Salir:	
			
			//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;

						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

				
			if(w < TamLinea -1)
			{ 
				w++;
			}
			else
			{
				w = 0;
			}
				

												
				//Impresión de contenido de arreglo de Memoria Cache			 
				
                ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);

				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}
				
				

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);

				ImprimeFormatoSim(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea);
			
		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;

		
	
		

}


//Funcion ImprimeContadores
//Función que imprime el arreglo dinámico donde se almacenan los contadores
//de cada Linea de Cache

void CCache2003View::ImprimeContadores(int *contLineas, int tam, int col)
{
	
	int i, j;
	char buffer_contador[5];
    CString s_contador;

   				
	for(i=0; i<tam; i++ )
	{
			for(j=0; j<tam; j++)
			{
				s_contador = _itoa( *(contLineas + j), buffer_contador, 10);
				m_CtrlRejilla_MC.SetTextArray(GenID((j*m_TamBloque)+ 1 ,col),s_contador);
				
			}
	  
	}

  
}



void CCache2003View::OnCheckLE() 
{
	 // TODO: Add your control notification handler code here
	 
	UpdateData(true);
		
	if(m_bChk_LectEsc == TRUE)
	{
	  //Se actualizan los tamaños de los controles Active X
	 //Tercera Columna con ancho 500 
	 m_CtrlRejilla_MP.SetColWidth(2, 1000);
	 
	m_CtrlRejilla_MP.SetRow(0);
	m_CtrlRejilla_MP.SetCol(2);
	m_CtrlRejilla_MP.SetText("Lec/Esc");
	m_CtrlRejilla_MP.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MP.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MP.SetCellAlignment(4);
	m_CtrlRejilla_MP.Refresh();

	 
	}
	else if(m_bChk_LectEsc == FALSE )
	{
	//Se actualizan los tamaños de los controles Active X
	//Tercera Columna con ancho nulo 
	m_CtrlRejilla_MP.SetColWidth(2, 0);
	
	m_CtrlRejilla_MP.SetRow(0);
	m_CtrlRejilla_MP.SetCol(2);
	m_CtrlRejilla_MP.SetText(" ");
	m_CtrlRejilla_MP.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MP.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MP.SetCellAlignment(4);
	m_CtrlRejilla_MP.Refresh();


	
	}
	
	UpdateData(true);
	
	if(m_bChk_LectEsc == TRUE)
	{
	  //Se actualizan los tamaños de los controles Active X
	 //Tercera Columna con ancho 500 
	 m_CtrlRejilla_MC.SetColWidth(2, 1000);
	 
	m_CtrlRejilla_MC.SetRow(0);
	m_CtrlRejilla_MC.SetCol(2);
	m_CtrlRejilla_MC.SetText("Lec/Esc");
	m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MC.SetCellAlignment(4);
	m_CtrlRejilla_MC.Refresh();

	 
	}
	else if(m_bChk_LectEsc == FALSE )
	{
	//Se actualizan los tamaños de los controles Active X
	//Tercera Columna con ancho nulo 
	m_CtrlRejilla_MC.SetColWidth(2, 0);
	
	m_CtrlRejilla_MC.SetRow(0);
	m_CtrlRejilla_MC.SetCol(2);
	m_CtrlRejilla_MC.SetText(" ");
	m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MC.SetCellAlignment(4);
	m_CtrlRejilla_MC.Refresh();


	
	}

}

void CCache2003View::OnCheckCont() 
{
		
	// TODO: Add your control notification handler code here
	UpdateData(true);
		
	if(m_bChk_Cont == TRUE)
	{
	 //Tercera Columna con ancho nulo 
	 m_CtrlRejilla_MC.SetColWidth(3, 1000);
	 
	 m_CtrlRejilla_MC.SetRow(0);
	 m_CtrlRejilla_MC.SetCol(3);
	 m_CtrlRejilla_MC.SetText("Fallos");
	 m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
	 m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
	 m_CtrlRejilla_MC.SetCellAlignment(4);
	 m_CtrlRejilla_MC.Refresh();

	 
	 
	}
	else if(m_bChk_Cont == FALSE )
	{
	//Tercera Columna con ancho nulo 
	m_CtrlRejilla_MC.SetColWidth(3, 0);
	
	m_CtrlRejilla_MC.SetRow(0);
	m_CtrlRejilla_MC.SetCol(3);
	m_CtrlRejilla_MC.SetText(" ");
	m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MC.SetCellAlignment(4);
	m_CtrlRejilla_MC.Refresh();
	
	}

	

}


//Función SimulaAConjuntos
//Función que escoge política de reemplazamiento en  la simulación de comportamiento de Memoria Cache

void CCache2003View::SimulaAConjuntos(int Ini_Linea, int w,  int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, CString sVias)
{
  	
    GetDlgItem(IDC_STATIC_N_BLOQUES_CONJ) ->EnableWindow(TRUE);
    GetDlgItem(IDC_EDIT_N_BLOQUES_CONJ) -> EnableWindow(TRUE);
    GetDlgItem(IDC_STATIC_N_CONJ) -> EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_N_CONJ) -> EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_PALABRAS_CONJ) -> EnableWindow(TRUE);	
    GetDlgItem(IDC_EDIT_PALABRAS_CONJ) -> EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_CONJ_MC) -> EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_LINEA_CONJ) -> EnableWindow(TRUE);	
    GetDlgItem(IDC_EDIT_N_LINEAS) -> EnableWindow(TRUE);

	switch (m_iP_Reemplazamiento)
	{
	case 0:
		//MessageBox("POLITICA DE SUSTITUCION : A L E A T O R I O"); 
		switch(m_iTip_Esc)
		{
			case 0:
				//MessageBox("Politica de Actualización : Escritura Directa");
				if( m_iAsignacion == 0)
				{

					AC_Aleatorio_CAsig( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_nVias, m_arrayDirSecMPPtr);
					//MessageBox("Con Asiganción en Escritura");
				}
				else
				{
					AC_Aleatorio_SAsig( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_nVias, m_arrayDirSecMPPtr);
					//MessageBox("Sin Asiganción en Escritura");
				}
		    break;
	        case 1:
	            //MessageBox("Politica de Actualización : Post-Escritura");
	            AC_Aleatorio_Post( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_nVias, m_arrayDirSecMPPtr);
	        break;
		}

			
		break;
	case 1:
		//MessageBox("POLITICA DE SUSTITUCION : L R U");
		
		switch(m_iTip_Esc)
		{
			case 0:
				//MessageBox("Politica de Actualización : Escritura Directa");
				if( m_iAsignacion == 0)
				{

					AC_LRU_CAsig( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_contEdad, m_nVias, m_arrayDirSecMPPtr);
					//MessageBox("Con Asiganción en Escritura");
				}
				else
				{
					AC_LRU_SAsig( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_contEdad, m_nVias, m_arrayDirSecMPPtr);
					//MessageBox("Sin Asiganción en Escritura");
				}
		    break;
	        case 1:
	            //MessageBox("Politica de Actualización : Post-Escritura");
	            AC_LRU_Post( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_contEdad, m_nVias, m_arrayDirSecMPPtr);
	        break;
		}

		break;
	case 2:
		//MessageBox("POLITICA DE SUSTITUCION : L F U");
		
		switch(m_iTip_Esc)
		{
			case 0:
				//MessageBox("Politica de Actualización : Escritura Directa");
				if( m_iAsignacion == 0)
				{

					AC_LFU_CAsig( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_contFrec, m_nVias, m_arrayDirSecMPPtr);
					//MessageBox("Con Asiganción en Escritura");
				}
				else
				{
					AC_LFU_SAsig( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_contFrec, m_nVias, m_arrayDirSecMPPtr);
					//MessageBox("Sin Asiganción en Escritura");
				}
		    break;
	        case 1:
	            //MessageBox("Politica de Actualización : Post-Escritura");
	            AC_LFU_Post( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_contFrec, m_nVias, m_arrayDirSecMPPtr);
	        break;
		}


		
		break;
	case 3:
		//MessageBox("POLITICA DE SUSTITUCION : F I F O");
		
		switch(m_iTip_Esc)
		{
			case 0:
				//MessageBox("Politica de Actualización : Escritura Directa");
				if( m_iAsignacion == 0)
				{

					AC_FIFO_CAsig( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_nVias, m_arrayDirSecMPPtr);
					//MessageBox("Con Asiganción en Escritura");
				}
				else
				{
					AC_FIFO_SAsig( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_nVias, m_arrayDirSecMPPtr);
					//MessageBox("Sin Asiganción en Escritura");
				}
		    break;
	        case 1:
	            //MessageBox("Politica de Actualización : Post-Escritura");
	            AC_FIFO_Post( m_ini_Linea, m_iw, m_nSim, m_contAciertos, m_contFallos, m_TamMP, m_TamMC, m_TamBloque, m_arrayTipoMPPtr, m_arrayTipoMCPtr, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_contLineas, m_nVias, m_arrayDirSecMPPtr);
	        break;
		}
		
		break;
    	default:
		//MessageBox("ERROR: El valor digitado no es una opción valida.");
	    break;
	}

}


//Función AC_Aleatorio_CAsig
//Función que realiza la sustitución aleatorio de Memoria Cache 
//por Método Asociativo por Conjuntos y con asignación de escritura 

void CCache2003View::AC_Aleatorio_CAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, CString sVias, int *arrayDirSecMPPtr)
{

int NPalabra, NBloque, NLinea, NPalabraBloque, NConjunto, NVia, NPalabraConjunto, NBloqueConjunto;
int nLinea, nMP, nMC, nBloque, nConjunto, TamLinea, TamConjunto;
int Dir, Dato, DatoEscrito, Tipo, Limite, i, j; 
int Vias, celda;
int contMC = 0;
int contLinea = 0;
int Limite2;
int Acierto;
int PosicionDatoMP;



CDireccionDlg dlgDireccion;

Vias = atoi(sVias);

	  

NLinea = Ini_Linea;
PosicionDatoMP = 0;
Acierto = 0;

GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);

	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}

			

			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			
			
			

			nMP = dlgDireccion.ConvertBase2(TamMP);
			nMC = dlgDireccion.ConvertBase2(TamMC);
			nBloque = dlgDireccion.ConvertBase2(TamBloque);
			nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);   
	        nConjunto = dlgDireccion.ConvertBase2(Vias);
			

			//Control de Excepción de números fraccionarios
			
			TRY
			{
				
				if(TamBloque*Vias > TamMC )
				{
					AfxThrowUserException();
				}

				TamLinea = (int)pow(2, nLinea);
				TamConjunto = TamMC/(TamBloque*Vias);
				
				NBloque = Truncar( NPalabra, TamBloque);
				NPalabraBloque = Sobrante( NPalabra, TamBloque);
				NConjunto = NBloque % TamConjunto;
				NPalabraConjunto = Vias*TamBloque; 
				NBloqueConjunto = NPalabraConjunto/TamBloque;
			 			 			
			}
		
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los datos introducidos no son válidos para la simulación.\nProbablemente el número de vías por conjunto sea muy grande");
				OnConfigurarPolticas();
				//OnSimular();
				return; 
			}
			
			END_CATCH

			
						
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			
			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			
			

			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			m_TamConjunto = TamConjunto;
			m_PalabraConjunto = NPalabraConjunto;
			m_nBloqueConjunto = NBloqueConjunto;
			m_NConjunto = NConjunto;
			
			
			/*
			Dato seleccionado Aleatoriamente ...."<<Dato;
			El dato corresponde a la palabra : "<<NPalabra;
			El numero de Bloque en MP correspondiente es : "<<NBloque;
			El numero de Palabra en Bloque es : "<<NPalabraBloque;
			El numero de Lineas en Cache es : "<<TamLinea;
			El numero de Conjuntos en Cache son : "<<TamConjunto;
			El numero de Palabras por conjunto es : "<<Vias*TamBloque;
			El numero de Conjunto correspondiente a Cache es : "<<NConjunto;
			
    		*/
			
			//Identificación del Bloque en Memoria Principal
			
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);

					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					//Colorea las celdas del dato
				   
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				    ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				    ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF); 
				   
				   	PosicionDatoMP = i;
				   }

				}
			}
		
				
			//Separación del Bloque encontrado en Memoria Principal
	
			
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];


			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);
					j++; 
				}
			}
	
						
			//Verificando Acierto o Fallo en Cache

			for( i = 0; i<TamMC; i++)
			{
				if(Dir == *(arrayDirMCPtr + i))
				{
					//Identificación del Bloque en Memoria Cache
					int NBloqueMC = Truncar(i, TamBloque);
						 //Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);

							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
					
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
				   			ColorearMC( celda, 2, 0x0000FF00, 0x00000000);
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000);

						
						}
					}
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					
                    NVia = (i/TamBloque) % Vias; 
					contAciertos++;
					m_NLinea = NBloqueMC;
					
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!!\nNo se encontró la Palabra");
					contFallos++;  
		  
		
				  
			//Llenado en orden de bloques en Memoria Cache cuando está vacía
			
					

			NLinea = NConjunto*Vias;
					
			if( *(arrayDatosMCPtr + NLinea*TamBloque) == '\0')
			{
					
				Limite = NLinea*TamBloque;
				NVia = 0;
					
					for(j=0; j<TamMC; j++)
					{		 		  
						for(i=0; i<TamBloque; i++)
						{
							if(j == Limite) 
							{
								celda = j + 1;
								*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
								*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
								*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
								j++;
								Limite++;
								ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
								ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							}
						} 
	      													
					}
					
					m_NLinea = NLinea;
					
					
			}
						
			 
			
			else
			{
			
				//Contador de Lineas en Cache
				
				Limite2 = (NLinea*TamBloque + Vias*TamBloque); 
				
				for(i= 0; i<Limite2; i++)
				{
										
					if(*(arrayDatosMCPtr + i) != '\0')
					{
                       contLinea = Truncar(i, TamBloque);
					   contLinea++;
					   
					}
				}

				//Verificando si la MC esta llena
				contMC =0;

				for(i=0; i<TamMC; i++)
				{
					if(*(arrayDatosMCPtr + i) != '\0')
					{
						contMC++;
					}
				}
				
								
					 

				if((contMC != TamMC) && ( Limite2 > contLinea*TamBloque + 1))
				{
					
					//Proceso de LLenado de Cache...";

					NLinea = contLinea;
					NVia = contLinea;
                    contLinea = 0;
					
					
					NVia = NLinea  % Vias;
					
							   
                    				    
				}
				//Caso en que se aplican métodos de reemplazamiento
				else
				{
					//Proceso Aleatorio...
					
					srand(time(0));
					NVia = rand() % Vias;
				    
					NLinea = NVia + NConjunto*Vias;
					
													
				
				}

				
				
				Limite = NLinea*TamBloque;
						
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite) 
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      													
				}
				m_NLinea = NLinea;
				
			}
								
		
		
			Contador( contLineas, TamLinea, NLinea, 3);		
			           			
			//Introduccion de Bloques en MP

							
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

    
				
		//AgregarPar();
					
			
Salir:
								
			//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;
						
						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

			
			m_nLineaConjunto = NVia;
			
				

				
				//Impresión de contenido de arreglo de Memoria Cache			 
		
		
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}


				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);

		
		ImprimeFormatoSim_Conj(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea, NConjunto, NVia);

		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;

	
				  
}


//Función AC_LRU_CAsig
//Función que realiza la sustitución aleatorio de Memoria Cache 
//por Método Asociativo por Conjuntos con asignación de escritura

void CCache2003View::AC_LRU_CAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contEdad, CString sVias, int *arrayDirSecMPPtr)
{

int NPalabra, NBloque, NLinea, NPalabraBloque, NConjunto, NVia, NPalabraConjunto, NBloqueConjunto;
int nLinea, nMP, nMC, nBloque, nConjunto, TamLinea, TamConjunto;
int Dir, Dato, DatoEscrito, Tipo, Limite, i, j; 

int contMC = 0;
int contLinea = 0;
int Limite2;
int Vias, celda;
int NLineaInferior = 0;
int NLineaSuperior = 0;  
int Acierto;
int PosicionDatoMP;

CDireccionDlg dlgDireccion;


Vias = atoi(sVias);
	  

NLinea = Ini_Linea;
Acierto = 0;
PosicionDatoMP = 0;

GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_EDAD) -> EnableWindow(TRUE);


nMP = dlgDireccion.ConvertBase2(TamMP);
nMC = dlgDireccion.ConvertBase2(TamMC);
nBloque = dlgDireccion.ConvertBase2(TamBloque);
nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);   
nConjunto = dlgDireccion.ConvertBase2(Vias);
			

TamLinea = (int)pow(2, nLinea);
TamConjunto = TamMC/(TamBloque*Vias);
	


  	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
				
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}

			

			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
				
			//Control de Excepción de números fraccionarios
			
			TRY
			{
				
				if(TamBloque*Vias > TamMC )
				{
					AfxThrowUserException();
				}

				TamLinea = (int)pow(2, nLinea);
				TamConjunto = TamMC/(TamBloque*Vias);
				
				NBloque = Truncar( NPalabra, TamBloque);
				NPalabraBloque = Sobrante( NPalabra, TamBloque);
				NConjunto = NBloque % TamConjunto;
				NPalabraConjunto = Vias*TamBloque; 
				NBloqueConjunto = NPalabraConjunto/TamBloque;
			 			 			
			}
		
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los datos introducidos no son válidos para la simulación.\nProbablemente el número de vías por conjunto sea muy grande");
				OnConfigurarPolticas();
				//OnSimular();
				return; 
			}
			
			END_CATCH

 						
			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			
			
			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

				

			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			m_TamConjunto = TamConjunto;
			m_PalabraConjunto = NPalabraConjunto;
			m_nBloqueConjunto = NBloqueConjunto;
			m_NConjunto = NConjunto;
			
		  /*
			Dato seleccionado Aleatoriamente ...."<<Dato;
			El dato corresponde a la palabra : "<<NPalabra;
			El numero de Bloque en MP correspondiente es : "<<NBloque;
			El numero de Palabra en Bloque es : "<<NPalabraBloque;
			El numero de Lineas en Cache es : "<<TamLinea;
			El numero de Conjuntos en Cache son : "<<TamConjunto;
			El numero de Palabras por conjunto es : "<<Vias*TamBloque;
			El numero de Conjunto correspondiente a Cache es : "<<NConjunto;
			
    		*/
			
			//Identificación del Bloque en Memoria Principal
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					
					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000); 		

					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);
				   
				   PosicionDatoMP = i;
				   
				   }

				}
			}
		
			
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];

			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);
					j++; 
				}
			}
	
				
		
			//Verificando Acierto o Fallo en Cache

			for( i = 0; i<TamMC; i++)
			{
				if(Dir == *(arrayDirMCPtr + i))	 

				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					
                    
					int NLineaAcierto;
					NLineaAcierto = i/TamBloque;
					m_NLinea = NLineaAcierto;
					
					NVia = NLineaAcierto % Vias;
					

					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(Dir == *(arrayDirMCPtr + i))
						{
							//Identificación del Bloque en Memoria Cache
							int NBloqueMC = Truncar(i, TamBloque);
							 //Colorea Acierto
							for( i = 0; i<TamMC; i++)
							{

								if(NBloqueMC == Truncar(i, TamBloque))
								{
									*(arregloDirBloqueMC + i) = i;
									*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
									*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);
									//Coloreado de celdas
									celda = 0;
									celda = i + 1;
					
									ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
									ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
				   					ColorearMC( celda, 2, 0x0000FF00, 0x00000000);  
									ColorearMC( celda, 3, 0x0000FF00, 0x00000000);
									ColorearMC( celda, 4, 0x0000FF00, 0x00000000);

								}
							}
						}
					
					}
					

					NLineaInferior = NConjunto*Vias;
					NLineaSuperior = Vias + NConjunto*Vias;

															
					               
					int contActual;

					for( j = NLineaInferior; j<NLineaSuperior; j++)
					{
						if( NLineaAcierto == j)
						{
							contActual = *(contEdad + j);
						}
					}

					for( j = NLineaInferior; j<NLineaSuperior; j++)
					{
						if(*(contEdad + j) < contActual )
						{
							++*(contEdad + j);
						}

						if( NLineaAcierto == j)
						{
							*(contEdad + j)= 0;
						}
					}

					ImprimeContadores( contEdad, TamLinea, 4);

					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!!\nNo se encontró la Palabra");
					contFallos++;  
		  
		
			
			//Llenado en orden de bloques en Memoria Cache cuando está vacía
			
					
			NLineaInferior = NConjunto*Vias;
			NLineaSuperior = Vias + NConjunto*Vias;

			NLinea = NLineaInferior;
					
			if( *(arrayDatosMCPtr + NLinea*TamBloque) == '\0')
			{
				
				 
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
					   if( i == NLinea)
					   {
						   *(contEdad + NLinea) = 0;
					   }
					   else
					   {
						   ++*(contEdad + i);
					   }
					}

					ImprimeContadores(contEdad, TamLinea, 4);

				 	
								
				Limite = NLinea*TamBloque;
					
				NVia = 0;
				
					for(j=0; j<TamMC; j++)
					{		 		  
						for(i=0; i<TamBloque; i++)
						{
							if(j == Limite) 
							{
								celda = j + 1;
								*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
								*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
								*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
								j++;
								Limite++;
								ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 4, 0x000000FF, 0x00FFFFFF);
							}
						} 
	      													
					}
					
					m_NLinea = NLinea;
					UpdateData(false);
					
			}
						
			 
			//Si no está vacía
			else
			{
			
				//Contador de Lineas en Cache
				
				
				Limite2 = (NLinea*TamBloque + Vias*TamBloque); 
				
				for(i= 0; i<Limite2; i++)
				{
										
					if(*(arrayDatosMCPtr + i) != '\0')
					{
                       contLinea = Truncar(i, TamBloque);
					   contLinea++;
					   		   
					   
					}
				}

				//Verificando si la MC esta llena
				contMC =0;

				for(i=0; i<TamMC; i++)
				{
					if(*(arrayDatosMCPtr + i) != '\0')
					{
						contMC++;
					}
				}
				
								
				
				 

					if((contMC != TamMC) && ( Limite2 > contLinea*TamBloque + 1) && (*(arrayDatosMCPtr + NLineaSuperior*TamBloque-1) == '\0'))
					{
					
						//Proceso de LLenado de Cache...\n\n";

						NLinea = contLinea;
						NVia = contLinea;
						contLinea = 0;
					
						NVia = NLinea  % Vias;

						NLineaInferior = NConjunto*Vias;
						NLineaSuperior = Vias + NConjunto*Vias;
										
					
						for(i= NLineaInferior; i<NLineaSuperior; i++)
						{
						   if( i == NLinea)
						   {
							   *(contEdad + NLinea) = 0;
						   }
						   else
						   {
							   ++*(contEdad + i);
						   }
						}

						ImprimeContadores(contEdad, TamLinea, 4);

											
						   
				}
				//Caso en que se aplican métodos de reemplazamiento
				else
				{
					//Proceso LRU...\n\n";
										
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
						if( *(contEdad + i) == (Vias - 1))
						{
							NLinea = i;
							
						}

					}

					ImprimeContadores( contEdad, TamLinea, 4);

					
					
					NVia = NLinea % Vias;
					
													
				
				}

				
				
				Limite = NLinea*TamBloque;
						
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite) 
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 4, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      													
				}
				m_NLinea =NLinea;
				UpdateData(false);
			}
								
					
			Contador( contLineas, TamLinea, NLinea, 3);
		
			//Introduccion de Bloques en MP

			   	
						
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);



//AgregarPar();						
			
Salir:
				//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;

						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

			
				
				m_nLineaConjunto = NVia;
								
				 
				if(w< TamLinea - 1)
				{
					w++;
				}
				else
				{
					w = TamLinea - 1;
				}
				
				//Impresión de contenido de arreglo de Memoria Cache			 
				
				
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}


				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);
			
		
		
		
		ImprimeFormatoSim_Conj(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea, NConjunto, NVia);

		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;

		
		
}



//Función AC_LFU_CAsig
//Función que realiza la sustitución aleatorio de Memoria Cache 
//por Método Asociativo por Conjuntos con asignación de escritura 

void CCache2003View::AC_LFU_CAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contFrec, CString sVias, int *arrayDirSecMPPtr)
{

int NPalabra, NBloque, NLinea, NPalabraBloque, NConjunto, NVia, NPalabraConjunto, NBloqueConjunto;
int nLinea, nMP, nMC, nBloque, nConjunto, TamLinea, TamConjunto;
int Dir, Dato, DatoEscrito, Tipo, Limite, i, j; 
int celda, Vias; 
int posMayor = 0;
int posMenor = 0;
int Acierto;
int PosicionDatoMP;
Vias = atoi(sVias);

int contMC = 0;
int contLinea = 0;
int Limite2;

int NLineaInferior = 0;
int NLineaSuperior = 0;  


NLinea = Ini_Linea;  
Acierto = 0;
PosicionDatoMP = 0;

GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_FREC) -> EnableWindow(TRUE);	        

CDireccionDlg dlgDireccion;

nMP = dlgDireccion.ConvertBase2(TamMP);
nMC = dlgDireccion.ConvertBase2(TamMC);
nBloque = dlgDireccion.ConvertBase2(TamBloque);
nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);   
nConjunto = dlgDireccion.ConvertBase2(Vias);
			

TamLinea = (int)pow(2, nLinea);
TamConjunto = TamMC/(TamBloque*Vias);
	

	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}

			

			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			
			//Control de Excepción de números fraccionarios
			
			TRY
			{
				
				if(TamBloque*Vias > TamMC )
				{
					AfxThrowUserException();
				}

				TamLinea = (int)pow(2, nLinea);
				TamConjunto = TamMC/(TamBloque*Vias);
				
				NBloque = Truncar( NPalabra, TamBloque);
				NPalabraBloque = Sobrante( NPalabra, TamBloque);
				NConjunto = NBloque % TamConjunto;
				NPalabraConjunto = Vias*TamBloque; 
				NBloqueConjunto = NPalabraConjunto/TamBloque;
			 			 			
			}
		
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los datos introducidos no son válidos para la simulación.\nProbablemente el número de vías por conjunto sea muy grande");
				OnConfigurarPolticas();
				//OnSimular();
				return; 
			}
			
			END_CATCH

									
 			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			
			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			m_TamConjunto = TamConjunto;
			m_PalabraConjunto = NPalabraConjunto;
			m_nBloqueConjunto = NBloqueConjunto;
			m_NConjunto = NConjunto;
						
			/*
			Dato seleccionado Aleatoriamente ...."<<Dato;
			El dato corresponde a la palabra : "<<NPalabra;
			El numero de Bloque en MP correspondiente es : "<<NBloque;
			El numero de Palabra en Bloque es : "<<NPalabraBloque;
			El numero de Lineas en Cache es : "<<TamLinea;
			El numero de Conjuntos en Cache son : "<<TamConjunto;
			El numero de Palabras por conjunto es : "<<Vias*TamBloque;
			El numero de Conjunto correspondiente a Cache es : "<<NConjunto;
			
    	  */

	//Identificación del Bloque en Memoria Principal
	
	for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF); 
				   
				   PosicionDatoMP = i;
				   }

				}
			}
		
				
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];
			
			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);

					j++; 
				}
			}
	
				
			//Verificando Acierto o Fallo en Cache

			for( i = 0; i<TamMC; i++)
			{
				
				int NBloqueMC = Truncar(i, TamBloque);

				if(Dir == *(arrayDirMCPtr + i))
				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					                    
					NLinea = (i/TamBloque);
					m_NLinea = NLinea;
					
					NVia = NLinea % Vias; 
					
					
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);
							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
				
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
							ColorearMC( celda, 2, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000); 		
							ColorearMC( celda, 5, 0x0000FF00, 0x00000000);
						}
					}



					NLineaInferior = NConjunto*Vias;
					NLineaSuperior = Vias + NConjunto*Vias;
                    
                
					for( i = NLineaInferior; i<NLineaSuperior; i++)
					{
						if( NLinea == i)
						{
							++*(contFrec + i);
						}

					}

					ImprimeContadores( contFrec, TamLinea, 5);

					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!!\nNo se encontro la Palabra");
					contFallos++;  
		  
		
			

			//Llenado en orden de bloques en Memoria Cache cuando está vacía
			
					
			NLineaInferior = NConjunto*Vias;
			NLineaSuperior = Vias + NConjunto*Vias;
            
			
			NLinea = NLineaInferior;
					
			if( *(arrayDatosMCPtr + NLinea*TamBloque) == '\0')
			{
			     
					 int Menor = *(contFrec + NLinea);
					 
					 for(i= NLineaInferior; i<NLineaSuperior; i++)
					 {
					   if( *(contFrec + i)< Menor )
					   {
						   Menor = *(contFrec + i);
						   NLinea = i;
					   }
					 }

					
					 ++*(contFrec + NLinea);
					 ImprimeContadores(contFrec, TamLinea, 5);

				 	
								
				Limite = NLinea*TamBloque;
					
				NVia = 0;
				
					for(j=0; j<TamMC; j++)
					{		 		  
						for(i=0; i<TamBloque; i++)
						{
							if(j == Limite) 
							{
								celda = j + 1;
								*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
								*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
								*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
								j++;
								
								Limite++;
								ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 5, 0x000000FF, 0x00FFFFFF);

							}
						} 
	      													
					}
					
					m_NLinea = NLinea;
					
					
			}
						
			 
			
			else
			{
			
				//Contador de Lineas en Cache
				
				
				Limite2 = (NLinea*TamBloque + Vias*TamBloque); 
				
				for(i= 0; i<Limite2; i++)
				{
										
					if(*(arrayDatosMCPtr + i) != '\0')
					{
                       contLinea = Truncar(i, TamBloque);
					   contLinea++;
					   		   
					}
				}

				//Verificando si la MC esta llena
				contMC =0;

				for(i=0; i<TamMC; i++)
				{
					if(*(arrayDatosMCPtr + i) != '\0')
					{
						contMC++;
					}
				}
				
								
				
				 

					if((contMC != TamMC) && ( Limite2 > contLinea*TamBloque + 1) && (*(arrayDatosMCPtr + NLineaSuperior*TamBloque-1) == '\0'))
					{
					
						//Proceso de LLenado de Cache...\n\n";

						NLinea = contLinea;
						NVia = contLinea;
						contLinea = 0;
					
						NVia = NLinea  % Vias;
					
					    NLinea = NVia + NConjunto*Vias;
					   
					    ++*(contFrec + NLinea);
                        ImprimeContadores(contFrec, TamLinea, 5);
					
					}
						
				
				//Caso en que se aplican métodos de reemplazamiento
				else
				{
					//Proceso LFU...\n\n";
										
					int Mayor =0;
										
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
						if( *(contFrec + i) > Mayor)
						{
							Mayor = *(contFrec + i);
							posMayor = i;
							
						}

					}

					int Menor = *(contFrec + posMayor);
										
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
						if( *(contFrec + i) < Menor)
						{
							Menor = *(contFrec + i);
							posMenor = i;
							NLinea = posMenor;
							
						}

					}

										
					++*(contFrec + NLinea);
					ImprimeContadores( contFrec, TamLinea, 5);

					
					
					NVia = NLinea % Vias;
					
													
				
				}

				
				
				Limite = NLinea*TamBloque;
						
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite) 
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 5, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      													
				}
				m_NLinea = NLinea;
				
			}
								
		
			Contador( contLineas, TamLinea, NLinea, 3);
					
			
			//Introduccion de Bloques en MP
						   	
					
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);


           			
			    
	//AgregarPar();			
	
					
			
Salir:
								
				//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;

						
						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

			
				m_nLineaConjunto = NVia;
				
				
				
				
				if(w< TamLinea - 1)
				{
					w++;
				}
				else
				{
					w = TamLinea - 1;
				}
				
				//Impresión de contenido de arreglo de Memoria Cache			 
				
				
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}


				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);


		
		ImprimeFormatoSim_Conj(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea, NConjunto, NVia);
		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;

				
  
}


//Función AC_FIFO_CAsig
//Función que realiza la sustitución aleatorio de Memoria Cache 
//por Método Asociativo por Conjuntos y con asignacion de escritura 

void CCache2003View::AC_FIFO_CAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, CString sVias, int *arrayDirSecMPPtr)
{
int NPalabra, NBloque, NLinea, NPalabraBloque, NConjunto, NVia, NPalabraConjunto, NBloqueConjunto;
int nLinea, nMP, nMC, nBloque, nConjunto, TamLinea, TamConjunto;
int Dir, Dato, DatoEscrito, Tipo, Limite, i, j; 
int celda, Vias; 
int posMayor = 0;
int posMenor = 0;
int Acierto;
int PosicionDatoMP;

Vias = atoi(sVias);

int contMC = 0;
int contLinea = 0;
int Limite2;


int NLineaInferior = 0;
int NLineaSuperior = 0;  



NLinea = Ini_Linea;  
PosicionDatoMP = 0;
Acierto = 0;

GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);



CDireccionDlg dlgDireccion;

nMP = dlgDireccion.ConvertBase2(TamMP);
nMC = dlgDireccion.ConvertBase2(TamMC);
nBloque = dlgDireccion.ConvertBase2(TamBloque);
nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);   
nConjunto = dlgDireccion.ConvertBase2(Vias);
			

TamLinea = (int)pow(2, nLinea);
TamConjunto = TamMC/(TamBloque*Vias);
	

	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
		
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}


			
			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
						
			
			//Control de Excepción de números fraccionarios
			
			TRY
			{
				
				if(TamBloque*Vias > TamMC )
				{
					AfxThrowUserException();
				}

				TamLinea = (int)pow(2, nLinea);
				TamConjunto = TamMC/(TamBloque*Vias);
				
				NBloque = Truncar( NPalabra, TamBloque);
				NPalabraBloque = Sobrante( NPalabra, TamBloque);
				NConjunto = NBloque % TamConjunto;
				NPalabraConjunto = Vias*TamBloque; 
				NBloqueConjunto = NPalabraConjunto/TamBloque;
			 			 			
			}
		
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los datos introducidos no son válidos para la simulación.\nProbablemente el número de vías por conjunto sea muy grande");
				OnConfigurarPolticas();
				//OnSimular();
				return; 
			}
			
			END_CATCH

						
 			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			
			
			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			m_TamConjunto = TamConjunto;
			m_PalabraConjunto = NPalabraConjunto;
			m_nBloqueConjunto = NBloqueConjunto;
			m_NConjunto = NConjunto;
						
			/*
			Dato seleccionado Aleatoriamente ...."<<Dato;
			El dato corresponde a la palabra : "<<NPalabra;
			El numero de Bloque en MP correspondiente es : "<<NBloque;
			El numero de Palabra en Bloque es : "<<NPalabraBloque;
			El numero de Lineas en Cache es : "<<TamLinea;
			El numero de Conjuntos en Cache son : "<<TamConjunto;
			El numero de Palabras por conjunto es : "<<Vias*TamBloque;
			El numero de Conjunto correspondiente a Cache es : "<<NConjunto;
			
    	  */

	//Identificación del Bloque en Memoria Principal
	
	for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);

					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
				
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF); 
				   
				   PosicionDatoMP = i;
				   }

				}
			}
		
			
	
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];
			
			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);

					j++; 
				}
			}
	
			
	
			//Verificando Acierto o Fallo en Cache

			for( i = 0; i<TamMC; i++)
			{
				
				int NBloqueMC = Truncar(i, TamBloque);

				if(Dir == *(arrayDirMCPtr + i))
				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					                    
					NLinea = (i/TamBloque);
					m_NLinea = NLinea;
					
					NVia = NLinea % Vias; 
					
					
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);

							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
				
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
							ColorearMC( celda, 2, 0x0000FF00, 0x00000000); 
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000);
						}
					}



					NLineaInferior = NConjunto*Vias;
					NLineaSuperior = Vias + NConjunto*Vias;
                    
                
					
					ImprimeContadores( contLineas, TamLinea, 3);

					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!!\nNo se encontro la Palabra");
					contFallos++;  
		  
		
			

			//Llenado en orden de bloques en Memoria Cache cuando está vacía
			
					
			NLineaInferior = NConjunto*Vias;
			NLineaSuperior = Vias + NConjunto*Vias;
            	
			
			NLinea = NLineaInferior;
					
			if( *(arrayDatosMCPtr + NLinea*TamBloque) == '\0')
			{
			     
					 int Menor = *(contLineas + NLinea);
					 
					 for(i= NLineaInferior; i<NLineaSuperior; i++)
					 {
					   if( *(contLineas + i)< Menor )
					   {
						   Menor = *(contLineas + i);
						   NLinea = i;
					   }
					 }

					
					 ++*(contLineas + NLinea);
					 ImprimeContadores(contLineas, TamLinea, 3);

				 
								
				Limite = NLinea*TamBloque;
					
				NVia = 0;
				
					for(j=0; j<TamMC; j++)
					{		 		  
						for(i=0; i<TamBloque; i++)
						{
							if(j == Limite) 
							{
								celda = j + 1;
								*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
								*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
								*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
								j++;
								Limite++;
								ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							 }
						} 
	      													
					}
					
					m_NLinea = NLinea;
					UpdateData(false);
					
			}
						
			 
			
			else
			{
			
				//Contador de Lineas en Cache
				
				
				Limite2 = (NLinea*TamBloque + Vias*TamBloque); 
				
				for(i= 0; i<Limite2; i++)
				{
										
					if(*(arrayDatosMCPtr + i) != '\0')
					{
                       contLinea = Truncar(i, TamBloque);
					   contLinea++;
					   		   
					  
					}
				}

				//Verificando si la MC esta llena
				contMC =0;

				for(i=0; i<TamMC; i++)
				{
					if(*(arrayDatosMCPtr + i) != '\0')
					{
						contMC++;
					}
				}
				
								
					if((contMC != TamMC) && ( Limite2 > contLinea*TamBloque + 1) && (*(arrayDatosMCPtr + NLineaSuperior*TamBloque-1) == '\0'))
					{
					
						//Proceso de LLenado de Cache...\n\n";

						NLinea = contLinea;
						NVia = contLinea;
						contLinea = 0;
					
						NVia = NLinea  % Vias;
					
					    NLinea = NVia + NConjunto*Vias;
					   
					    ++*(contLineas + NLinea);
                        ImprimeContadores(contLineas, TamLinea, 3);
					
					}
						
				
				//Caso en que se aplican métodos de reemplazamiento
				else
				{
					//Proceso LFU...\n\n";
										
					int Mayor =0;
										
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
						if( *(contLineas + i) > Mayor)
						{
							Mayor = *(contLineas + i);
							posMayor = i;
							
						}

					}

					int Menor = *(contLineas + posMayor);
										
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
						if( *(contLineas + i) < Menor)
						{
							Menor = *(contLineas + i);
							posMenor = i;
							NLinea = posMenor;
							
						}

					}

										
					++*(contLineas + NLinea);
					ImprimeContadores( contLineas, TamLinea, 3);

					
					
					NVia = NLinea % Vias;
					
													
				
				}

				
				
				Limite = NLinea*TamBloque;
						
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite) 
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      													
				}
				m_NLinea = NLinea;
				
			}
								
			
			
			//Introduccion de Bloques en MP
						   	
						
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en MP
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);



					
//AgregarPar();			           			
			    
				

					
			
Salir:
								
				//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;

						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

				m_nLineaConjunto = NVia;
							
				
				
				if(w< TamLinea - 1)
				{
					w++;
				}
				else
				{
					w = TamLinea - 1;
				}
				
				//Impresión de contenido de arreglo de Memoria Cache			 
				
				
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}


				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);
			
		

		ImprimeFormatoSim_Conj(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea, NConjunto, NVia);

		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;

		



}


void CCache2003View::ColorearConjuntos(int TamMC, int TamBloque, CString Vias)
{
	int TamConjunto;
	int NPalabrasConjunto;
	int nVias;
	int i, j;
	int Limite2, Limite1;
	char buffer_contador[5];
    CString s_contador;

	/*
    char buffercelda1[5];
    CString s_celda1;
	 */
	
	nVias = atoi(Vias);
	
	NPalabrasConjunto = nVias*TamBloque;
	
		//Control de Excepción división entre cero
			TRY
			{
				if((NPalabrasConjunto == 0))
				{
					AfxThrowUserException();
				}

				TamConjunto = TamMC/NPalabrasConjunto;	
			}
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los tamaños de memoria introducidos no son válidos para la simulación.\nLos tamaños deben ser mayores que cero");
				OnConfiguracionMemorias();
			}
			
			END_CATCH

	
	if( TamConjunto != 1)	
	{
			for( i = 1; i<= TamConjunto; i++)
			{
			    Limite1	= i*NPalabrasConjunto;
				Limite2 = i*NPalabrasConjunto + NPalabrasConjunto;
				
				for( j = Limite1 + 1; j<= Limite2 ; j++)
				{
					   /*
				   		s_celda1 = _itoa( Limite1, buffercelda1, 10);
					    MessageBox(" Limite1 = " + s_celda1);	
						s_celda1 = _itoa( Limite2, buffercelda1, 10);
					    MessageBox(" Limite2 = " + s_celda1);
						*/
					    if((i % 2) != 0)
						{
							s_contador = _itoa( j, buffer_contador, 10);
							m_CtrlRejilla_MC.SetRow(j);
							m_CtrlRejilla_MC.SetCol(1);
							m_CtrlRejilla_MC.SetCellBackColor(0x00CCCCCC);
							m_CtrlRejilla_MC.SetCol(2);
							m_CtrlRejilla_MC.SetCellBackColor(0x00CCCCCC);
							m_CtrlRejilla_MC.SetCol(3);
							m_CtrlRejilla_MC.SetCellBackColor(0x00CCCCCC);
							m_CtrlRejilla_MC.SetCol(4);
							m_CtrlRejilla_MC.SetCellBackColor(0x00CCCCCC);
							m_CtrlRejilla_MC.SetCol(5);
							m_CtrlRejilla_MC.SetCellBackColor(0x00CCCCCC);
													
							m_CtrlRejilla_MC.Refresh();
							/*
							s_celda1 = _itoa( Limite1, buffercelda1, 10);
					        MessageBox(" Limite1 = " + s_celda1);	
							s_celda1 = _itoa( Limite2, buffercelda1, 10);
					        MessageBox(" Limite2 = " + s_celda1);
							*/
						 }
				}
			
				
			}


	}
}

void CCache2003View::Contador(int *contLineas, int TamLinea, int NLinea, int col)
{
   	for( int i = 0; i<TamLinea; i++)
	{
	    if( i == NLinea )
		{
			++*(contLineas + i);
		}		
	}

	ImprimeContadores( contLineas, TamLinea, col);
}

void CCache2003View::OnBtnLlenarMp() 
{
	// TODO: Add your control notification handler code here
	LlenarMP();	
	

}



CString CCache2003View::Hex(int n)
{
  char buffer1[20];
  char buffer2[20];
		
	CString hexadecimal;
	long hexa_long;
	CString hexa;
   	
	hexadecimal = _itoa( n, buffer1, 10);
	hexa_long = strtol(hexadecimal, NULL, 10);
	sprintf(buffer2, "%lX", hexa_long);

	hexa = buffer2;
	 
return hexa;

}

CString CCache2003View::Oct(int n)
{
   char buffer1[20];
   char buffer2[20];
		
	CString octal;
	long octal_long;
	CString oct;
   	
	octal = _itoa( n, buffer1, 10);
	octal_long = strtol(octal, NULL, 10);
	sprintf(buffer2, "%lo", octal_long);

	oct = buffer2;
	 
return oct;

}

void CCache2003View::OnCheckEdad() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
		
	if(m_bChk_Edad == TRUE)
	{
	 //Tercera Columna con ancho nulo 
	 m_CtrlRejilla_MC.SetColWidth(4, 1000);
	 
	 m_CtrlRejilla_MC.SetRow(0);
	 m_CtrlRejilla_MC.SetCol(4);
	 m_CtrlRejilla_MC.SetText("Edad");
	 m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
	 m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
	 m_CtrlRejilla_MC.SetCellAlignment(4);
	 m_CtrlRejilla_MC.Refresh();

	 
	 
	}
	else if(m_bChk_Edad == FALSE )
	{
	//Tercera Columna con ancho nulo 
	m_CtrlRejilla_MC.SetColWidth(4, 0);
	
	m_CtrlRejilla_MC.SetRow(0);
	m_CtrlRejilla_MC.SetCol(4);
	m_CtrlRejilla_MC.SetText(" ");
	m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MC.SetCellAlignment(4);
	m_CtrlRejilla_MC.Refresh();
	
	}

	

}

void CCache2003View::OnCheckFrec() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
		
	if(m_bChk_Frec == TRUE)
	{
	 //Tercera Columna con ancho nulo 
	 m_CtrlRejilla_MC.SetColWidth(5, 1000);
	 
	 m_CtrlRejilla_MC.SetRow(0);
	 m_CtrlRejilla_MC.SetCol(5);
	 m_CtrlRejilla_MC.SetText("Frec");
	 m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
	 m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
	 m_CtrlRejilla_MC.SetCellAlignment(4);
	 m_CtrlRejilla_MC.Refresh();

	 
	 
	}
	else if(m_bChk_Frec == FALSE )
	{
	//Tercera Columna con ancho nulo 
	m_CtrlRejilla_MC.SetColWidth(5, 0);
	
	m_CtrlRejilla_MC.SetRow(0);
	m_CtrlRejilla_MC.SetCol(5);
	m_CtrlRejilla_MC.SetText(" ");
	m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MC.SetCellAlignment(4);
	m_CtrlRejilla_MC.Refresh();
	
	}


}




void CCache2003View::OnConfigurarActualiza() 
{
	// TODO: Add your command handler code here
		
	CEscrituraDlg 	dlgEscritura;
    CSimulacionDlg dlgSimulacion;

	dlgEscritura.m_iEsc_Directa = m_iTip_Esc; 
	dlgEscritura.m_iCon_Asignacion = m_iAsignacion;
	dlgSimulacion.m_iAutomatico = m_iAutomatico;
	UpdateData(false);

	//Puntero a la barra de estados
	CWnd *pMainWnd = AfxGetApp()->m_pMainWnd;
	CStatusBar *pStatusBar = (CStatusBar *)pMainWnd->GetDescendantWindow(AFX_IDW_STATUS_BAR);
	char str[30];
	
	
	if( dlgEscritura.DoModal() == IDOK )
	{
		
			ResetDatos();
			LimpiarRejilla_MP();
			LimpiarRejilla_MC();
			LimpiarEdit();
			
			Primero();
			if( dlgSimulacion.m_iAutomatico == 0)
			{
			 GetDlgItem(IDC_BTN_LLENAR_MP) -> EnableWindow(TRUE);
			 GetDlgItem(IDC_SIMULAR) ->EnableWindow(FALSE);
			}
			 else
			{
			 GetDlgItem(IDC_BTN_LLENAR_MP) -> EnableWindow(FALSE);
			 GetDlgItem(IDC_SIMULAR) ->EnableWindow(TRUE);
			}
		 



		switch(dlgEscritura.m_iEsc_Directa)
			{
			case 0:
				//MessageBox("Politica de Actualización : Escritura Directa");
				wsprintf(str, "ESCRITURA DIRECTA");
				pStatusBar->SetPaneText(2, str);
				if( dlgEscritura.m_iCon_Asignacion == 0)
				{
					
					//MessageBox("Con Asiganción en Escritura");
					wsprintf(str, "CON ASIG");
					pStatusBar->SetPaneText(3, str);
				}
				if( dlgEscritura.m_iCon_Asignacion == 1)
				{
					//MessageBox("Sin Asiganción en Escritura");
					wsprintf(str, "SIN ASIG");
					pStatusBar->SetPaneText(3, str);
				}

			break;
			case 1:
				 //MessageBox("Politica de Actualización : Post-Escritura");
				 wsprintf(str, "POST-ESCRITURA");
				pStatusBar->SetPaneText(2, str);
				pStatusBar->SetPaneText(3,"");
			break;
			}

	   }
	
	 m_iTip_Esc = dlgEscritura.m_iEsc_Directa; 
	 m_iAsignacion = dlgEscritura.m_iCon_Asignacion;
	 UpdateData(false);


}

void CCache2003View::EscrituraMP(int Dir, int NBloque, int TamMP, int TamBloque, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayTipoMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *arrayTipoMCPtr)
{
   //Identifica y deposita el Bloque en MP 
	int celda;
	
	for(int j=0; j<TamMP; j++)
	{		 		  
			if(NBloque == Truncar(j, TamBloque))
			{
				celda = 0;
				celda = j + 1;
											
				*(arrayDirMPPtr + j) =  *(arrayDirMCPtr + j);
				*(arrayDatosMPPtr + j) = *(arrayDatosMCPtr + j);
				*(arrayTipoMPPtr + j) = *(arrayTipoMCPtr + j);
							
				ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
				ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
				ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
			}
			 
			//Colorea las celdas del dato
			if(Dir == *(arrayDirMPPtr + j))
			{
				ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
			}
	}


}

//Función SimulaDirecto_SAsig
//Función que realiza la simulación de comportamiento de Memoria Cache por el método Directo
//sin asignación de escritura

void CCache2003View::SimulaDirecto_SAsig(int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr)
{
   int NPalabra, NBloque, NLinea, NPalabraBloque;
   int nLinea, nMP, nMC, nBloque, TamLinea;
   int Dato, Dir, Tipo, DatoEscrito, i, j; 
   int celda;
   int Acierto;
   int PosicionDato;
   
   Acierto = 0;
   
	
	GetDlgItem(IDC_EDIT_MET_REEMPLAZA)->EnableWindow(FALSE);


    GetDlgItem(IDC_STATIC_N_BLOQUES_CONJ) ->EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT_N_BLOQUES_CONJ) -> EnableWindow(FALSE);
    GetDlgItem(IDC_STATIC_N_CONJ) -> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_N_CONJ) -> EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_PALABRAS_CONJ) -> EnableWindow(FALSE);	
    GetDlgItem(IDC_EDIT_PALABRAS_CONJ) -> EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_CONJ_MC) -> EnableWindow(FALSE);	
    GetDlgItem(IDC_EDIT_CONJ) -> EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_LINEA_CONJ) -> EnableWindow(FALSE);	
    GetDlgItem(IDC_EDIT_N_LINEAS) -> EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);

	CDireccionDlg dlgDireccion;
   	  
	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}

			
			

			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			

			
			nMP = dlgDireccion.ConvertBase2(TamMP);
			nMC = dlgDireccion.ConvertBase2(TamMC);
			nBloque = dlgDireccion.ConvertBase2(TamBloque);
			nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);   
	
			TamLinea = (int)pow(2, nLinea);
			 
   
   

		
			NBloque = Truncar( NPalabra, TamBloque);
			NPalabraBloque = Sobrante( NPalabra, TamBloque);
			NLinea = NBloque % TamLinea;
	
			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);

			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipos de datos correspondientes al bloque
			int *arregloTipoBloque = new int[ TamMP ];
			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';

			}

			

			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			m_NLinea = NLinea;
			

			

    
			//Identificación del Bloque en Memoria Principal
			
			for( i = 0; i<TamMP; i++)
			{
				
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					//Coloreado de celdas
					celda = 0;
					celda = i + 1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF); 
				   
				    //Introduce el dato escrito en cache
					*(arrayDatosMPPtr + i) = DatoEscrito;
				    PosicionDato = i;

				   
				   
				   }
				}
			

			}
		
					
			//Separación del Bloque encontrado en Memoria Principal
	
			
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];

			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j) = *(arregloTipoBloque + i);
					j++; 
				}
			}
	
			
	
	
		
			

			//Verificando Acierto o Fallo en Cache

			for( i = 0; i<TamMC; i++)
			{
				if(Dir == *(arrayDirMCPtr + i))
				{
					
					MessageBox("A C I E R T O!!! \nSe encontró la Palabra");
					contAciertos++;
					Acierto++;
					GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
				    GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);
					goto MC;
				}
	          
			}	  
					MessageBox("F A L L O!!!\nNo se encontró la Palabra");
					contFallos++;  
		  			Contador( contLineas, TamLinea, NLinea, 3); 
				
					//AgregarPar();
							
//Introducción de Bloques a Memoria Cache 
MC:
			
		int Limite = NLinea*TamBloque;					
		if( Tipo == 1)
		{	
			
				GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
				GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);


				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite)
						{
							celda = j + 1;
							
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							
														
							j++;
							Limite++;
							if( Acierto == 1)
							{
								ColorearMC( celda, 0, 0x0000FF00, 0x00000000); 
								ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 
								ColorearMC( celda, 2, 0x0000FF00, 0x00000000);
								ColorearMC( celda, 3, 0x0000FF00, 0x00000000);
							}
						    else
							{
								
								ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
								ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);

							}
						
										
						}
					} 
	      	
				}
			
			   //Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						
						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
			
				}	
		
			
								
			 	

			//Impresión de contenido de arreglo de Memoria Cache			 
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);

			//Introduccion de Bloques en MP

			   	
				//Identifica y deposita el Bloque en MP 
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			

			

		
		
		}//Fin del if
		else
		{	
	   
			   	GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(FALSE);
				GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(FALSE);
				m_NLinea = "0";
				UpdateData(false);

				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite)
						{
							celda = j + 1;
																					
							j++;
							Limite++;
							if( Acierto == 1)
							{
								ColorearMC( celda, 0, 0x0000FF00, 0x00000000); 
								ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 
								ColorearMC( celda, 2, 0x0000FF00, 0x00000000);
								ColorearMC( celda, 3, 0x0000FF00, 0x00000000);
							}
						    
										
						}
					} 
	      	
				}
			
			   //Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						
						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						
					}
			
				}	
		
			


			
								
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0)	
			{
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDato);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			} 	
		
		}//Fin del else
			

				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
				ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);


				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}


					}
					else
					{
						nSim++;

						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						UpdateData(false);
					}
				}
				else
				{
					 nSim++;

					 m_contAciertos = contAciertos;
					 m_contFallos = contFallos;
					 m_nSim = nSim;
					 UpdateData(false);
				}

				

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);

 				ImprimeFormatoSim(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea);

				
	   delete arrayDirBloque;
	   delete arrayDatBloque;
	   delete arrayTipoBloque;
	   delete arregloDirBloque;
	   delete arregloDatBloque;
	   delete arregloTipoBloque;


}


//Función A_Aleatorio_SAsig
//Función que realiza la sustitución aleatorio de Memoria Cache 
//por Método Asociativo sin asignacion de escritura 

void CCache2003View::A_Aleatorio_SAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr)
{
    int NPalabra, NBloque, NPalabraBloque, NLinea;
	int nLinea, nMP, nMC, nBloque, TamLinea;
	int Dato, DatoEscrito, Dir, Tipo, i, j, Limite; 
	int celda;
    int Acierto;
	
	int PosicionDatoMP;
	
	NLinea = Ini_Linea;

	Acierto = 0;
	
	PosicionDatoMP = 0;
	CDireccionDlg dlgDireccion;
	 
    
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);

	 	   	
			     
	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}


		
			
			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			
			



			nMP = dlgDireccion.ConvertBase2(TamMP);
			nMC = dlgDireccion.ConvertBase2(TamMC);
			nBloque = dlgDireccion.ConvertBase2(TamBloque);
			nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);
			
			TamLinea = (int)pow(2, nLinea);
			
			NBloque = Truncar( NPalabra, TamBloque);
			NPalabraBloque = Sobrante( NPalabra, TamBloque);
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);

			
			
			//Arreglo temporal para buscar direcciones correspondientes al bloque en MP
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MP
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];
			

			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';

			}

			
						    
			//Identificación del Bloque en Memoria Principal
			
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000); 
					
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF);
				   
				   PosicionDatoMP = i;
				   }

				
				}
			}
		
				
			//Separación del Bloque encontrado en Memoria Principal
			//Bloque de Direcciones y Datos a traspasar a Cache...  
			
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];


			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);

					j++; 
				}
			}
	
					
			
			//Verificando Acierto o Fallo en Cache

			
			for( i = 0; i<TamMC; i++)
			{
				if(Dir == *(arrayDirMCPtr + i))
				{
										
					//Identificación del Bloque en Memoria Cache
					int NBloqueMC = Truncar(i, TamBloque);
					
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{
						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);

							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
					
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
				   			ColorearMC( celda, 2, 0x0000FF00, 0x00000000);
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000);

						}
					}
					
					m_NLinea = NBloqueMC;
					UpdateData(false);
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					w--;
					contAciertos++;
					Acierto++;
					GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
				    GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);
					goto Salir;
					
				}
	          
			}	  
					MessageBox("F A L L O!!! \nNo se encontró la Palabra");
					contFallos++;   
				
			
		 
	  if(Tipo == 1)
	  { 	   
			
		  //Habilita controles
		  GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
		  GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);
		  
		  //Muestra controles
		    GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(TRUE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(TRUE);  	

		  
		  //Llenado en orden de bloques en Memoria Cache cuando está vacía

		  if( *(arrayDatosMCPtr + (w)*TamBloque ) == '\0')
			{
				NLinea++;
				m_NLinea = NLinea;
				
			}

			else
			{
				srand( time( 0) );
				NLinea = rand() % TamLinea;
				m_NLinea = NLinea;
				
			}
			
			//Introducción de Bloques a Memoria Cache 
				
				Limite = NLinea*TamBloque;			  			
					
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite)
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      	
				
				}
			
								
				Contador( contLineas, TamLinea, NLinea, 3);
				
			//Introduccion de Bloques en MP

			   	
						
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

	  }//Fin del if
	  
	  else
	  {
			//Deshabilita controles
		    GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(FALSE);  
			
			//Esconde controles
		    GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(FALSE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(FALSE);  	

			
			m_NLinea = "0";
			UpdateData(false);

		
		
			//Introduccion de Bloques en MP

							
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

	  
	  
	  }//Fin del else

	
	  //AgregarPar();

Salir:	
			
			//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;
						
						
						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

						
				
			if(w < TamLinea)
			{ 
				w++;
			}
			else
			{
				w = TamLinea;
			}
													
				//Impresión de contenido de arreglo de Memoria Cache			 
				
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}
				
				

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);

		
		ImprimeFormatoSim(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea);

		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;

}

//Función A_LRU_SAsig ( Sustituye el bloque que lleva más tiempo sin haber sido utilizado )
//Simula la Politica de sustitución Least Recently Use en Memoria Cache Método Asociativo
//sin asignación de escritura

void CCache2003View::A_LRU_SAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contEdad, int *arrayDirSecMPPtr)
{
    int NPalabra, NBloque, NLinea, NPalabraBloque;
	int nLinea, nMP, nMC, nBloque, TamLinea;
	int Dir, Dato, DatoEscrito, Tipo, i, j, Limite; 
	int celda;
	int Acierto;
	int PosicionDatoMP;

	NLinea = Ini_Linea;  
	
	Acierto = 0;
	PosicionDatoMP = 0;

	CDireccionDlg dlgDireccion;
	 
    
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_EDAD) -> EnableWindow(TRUE);


	nMP = dlgDireccion.ConvertBase2(TamMP);
	nMC = dlgDireccion.ConvertBase2(TamMC);
	nBloque = dlgDireccion.ConvertBase2(TamBloque);
	nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);

	TamLinea = (int)pow(2, nLinea);
	
	
	

		//Comienzo Simulación
	 
	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}

			

			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			

			
			
			NBloque = Truncar( NPalabra, TamBloque);
			NPalabraBloque = Sobrante( NPalabra, TamBloque);
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			
			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			
			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			
						
			    
			//Identificación del Bloque en Memoria Principal
			
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);

					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF); 
				   
				   PosicionDatoMP = i;
				   
				   }


				}
			}
		
			
			
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];

			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);
					j++; 
				}
			}
	
				
			//Verificando Acierto o Fallo en Cache
									
			
			for( i = 0; i<TamMC; i++)
			{
				
				//Identificación del Bloque en Memoria Cache
				int NBloqueMC = Truncar(i, TamBloque);
				
				
				if(Dir == *(arrayDirMCPtr + i))
				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					            		
					
					
					int NLineaAcierto;
					NLineaAcierto = i/TamBloque;
					m_NLinea = NLineaAcierto;
					
					GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
					GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);  
			

					 
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
				
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
							ColorearMC( celda, 2, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000); 		
							ColorearMC( celda, 4, 0x0000FF00, 0x00000000); 
						}
					}

      			

					
					int contActual;
					
					for( j = 0; j<TamLinea; j++)
					{
						if( NLineaAcierto == j) 
						{ 
							contActual = *(contEdad + j);
						    						     
						}	
						
					}
					for(j = 0; j<TamLinea; j++)
					{
						if(*(contEdad + j)  <  contActual )
						{ 
							++*(contEdad + j);
						}
					   
						if( NLineaAcierto == j)
						{
						*(contEdad + j ) = 0;
						}
					 					 	
					}
					
					
								
					
					ImprimeContadores( contEdad, TamLinea, 4);
					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					
					MessageBox("F A L L O!!!\nNo se encontró la Palabra");
					contFallos++;   
				
	if( Tipo == 1)
	{	
			
		    //Habilita controles
			GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);  
			
			//Muestra controles
		    GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(TRUE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(TRUE);

			//Llenado de bloques en Memoria Cache cuando está vacía
			if( *(arrayDatosMCPtr + (w)*TamBloque ) == '\0')
			{
				NLinea++;
				m_NLinea = NLinea;
				
				
				for( i = 0; i<TamLinea; i++)
				{



					if( i == NLinea )
					{
					   *(contEdad + NLinea) = 0;
	                   				
					}	
					else
					{
						++*(contEdad + i); 
					 					    
					}
				 				
				}
                
				ImprimeContadores(contEdad, TamLinea, 4);

			}
			else   //Llenado cuando esta llena la Cache
			{
				for(i = 0; i<TamLinea; i++)
				{
					
					if( *(contEdad + i) == (TamLinea - 1))
					{
					   NLinea = i;
					   m_NLinea = NLinea;
					   
					}
				
				}
			    
				ImprimeContadores( contEdad, TamLinea, 4);
			}
			
			//Introducción de Bloques a Memoria Cache 
				
				Limite = NLinea*TamBloque;			  			
					
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite)
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);

							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 4, 0x000000FF, 0x00FFFFFF);
						}
					} 
	      	
				
				}
			
				Contador( contLineas, TamLinea, NLinea, 3);

				//Introduccion de Bloques en MP

			   	
				
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;


					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

	}//Fin del if de Tipo

	else
	{
			
			//Deshabilita controles
		    GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(FALSE);  
			
			//Esconde controles
		    GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(FALSE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(FALSE);
			
			m_NLinea = "0";
			UpdateData(false);

		
		
			//Introduccion de Bloques en MP
						   	
							
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;


					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);



	}//Fin del else	de Tipo

	//AgregarPar();

Salir:	
			
			//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;
						
						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
							
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
							
						}
					}
				}

			
			if(w < TamLinea - 1 )
			{ 
				w++;
			}
			else
			{
				w = TamLinea - 1 ;
			}
				
			  				
				//Impresión de contenido de arreglo de Memoria Cache			 
				
               	ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}
				
				

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);
			
		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;

		

		ImprimeFormatoSim(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea);
}

//Función A_FIFO_SAsig ( Sustituye los bloques en forma First In First Out )
//Simula la Politica de sustitución Aleatoria en Memoria Cache por Método Asociativo
//sin asignacion de escritura

void CCache2003View::A_FIFO_SAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr)
{
 int NPalabra, NBloque, NLinea, NPalabraBloque;
 int nLinea, nMP, nMC, nBloque, TamLinea;
 int Dir, Dato, DatoEscrito, Tipo, i, j, Limite; 
 int posMayor = 0;
 int posMenor = 0;
 int celda;
 int Acierto;   
 int PosicionDatoMP;

 NLinea = Ini_Linea;  
 
 Acierto = 0;
 PosicionDatoMP = 0;	
    
    CDireccionDlg dlgDireccion;
	 
    
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);


	nMP = dlgDireccion.ConvertBase2(TamMP);
	nMC = dlgDireccion.ConvertBase2(TamMC);
	nBloque = dlgDireccion.ConvertBase2(TamBloque);
	nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);

	TamLinea = (int)pow(2, nLinea);
			

	
	
	//Comienzo Simulación
	
	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}

			

			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			

			
			
			NBloque = Truncar( NPalabra, TamBloque);
			NPalabraBloque = Sobrante( NPalabra, TamBloque);
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			

						
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];


			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];
			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			}

					
			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';

			}

			
						    
			//Identificación del Bloque en Memoria Principal
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					
					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF);
				   
				   PosicionDatoMP = i;
				   }


				}
			}
		
			
	
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];

			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);
					
					j++; 
				}
			}
	
			
			
						
			//Verificando Acierto o Fallo en Cache

						
			
			for( i = 0; i<TamMC; i++)
			{
				int NBloqueMC = Truncar(i, TamBloque);


				if(Dir == *(arrayDirMCPtr + i))
				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					            		
					NLinea = i/TamBloque;
					m_NLinea = NLinea;
					
					GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
				    GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);
					
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);

							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
				
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
							ColorearMC( celda, 2, 0x0000FF00, 0x00000000); 
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000);
						}
					}



					m_NLinea = NLinea;
					

					
					ImprimeContadores( contLineas, TamLinea, 3);
					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!! \nNose encontró la Palabra");
					contFallos++;   
				
			
	 if(Tipo == 1)
	 {
			
			//Habilita controles
			GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);
			
			//Muestra controles
		    GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(TRUE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(TRUE);
			
			
			//Llenado de bloques en Memoria Cache cuando está vacía
           	if( *(arrayDatosMCPtr + (w)*TamBloque ) == '\0')
			{
				NLinea++;

				int Menor = *(contLineas + 0);

				for(i = 0; i<TamLinea; i++)
				{
										
					if( *(contLineas + i) < Menor)
					{
						Menor = *(contLineas + i);
						NLinea = i;
					}
				    								
				}						
						
					
								
				++*(contLineas + NLinea);
				m_NLinea = NLinea;
				
				ImprimeContadores(contLineas, TamLinea, 3);	                   				
			}	
				 
					 					    
			else   //Llenado cuando esta llena la Cache
			{
				
				int Mayor = 0;
				for( i= 0; i<TamLinea; i++)
				{
					if( *(contLineas + i) > Mayor)
					{
						Mayor = *(contLineas + i);
						posMayor = i;
					}
	            		
				}
				
				
				
				int Menor = *(contLineas + posMayor);
                 
				for(i = 0; i<TamLinea; i++)
				{
										
					if( *(contLineas + i) < Menor)
					{
						Menor = *(contLineas + i);
						posMenor = i;
						NLinea = posMenor;
					}
					else
					{
						NLinea = posMenor;
					}
					
				 } 
				
				++*(contLineas + NLinea);
				ImprimeContadores( contLineas, TamLinea, 3);
			}
			
			//Introducción de Bloques a Memoria Cache 
				
				Limite = NLinea*TamBloque;			  			
					
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite)
						{
							celda = 0;
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);

							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
						}
					} 
	      	
				
				}
			
			  

			//Introduccion de Bloques en MP
					
							
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);
	  
	}//Fin del if Tipo

	else
	{
			
			//Desabilita controles 
		    GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(FALSE);
			
			//Esconde controles
		    GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(FALSE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(FALSE);
			
			m_NLinea = "0";
			UpdateData(false);
			
			
										
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(m_nMP, m_TamMC, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

	}//Fin del else Tipo

	//AgregarPar();

Salir:	
			
			//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;

						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

			
			if(w < TamLinea -1)
			{ 
				w++;
			}
			else
			{
				w = 0;
			}
				

												
				//Impresión de contenido de arreglo de Memoria Cache			 
				
                ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);

				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}
				
				

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);

				ImprimeFormatoSim(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea);
			
		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;

		
	
		

}

//Función A_LFU_SAsig ( Sustituye el bloque que haya sido menos utilizado )
//Simula la Politica de sustitución Least Frecuently Use en Memoria Cache Método Asociativo
//sin asignacion de escritura

void CCache2003View::A_LFU_SAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contFrec, int *arrayDirSecMPPtr)
{
 int NPalabra, NBloque, NLinea, NPalabraBloque;
 int nLinea, nMP, nMC, nBloque, TamLinea;
 int Dir, Dato, DatoEscrito, Tipo, i, j, Limite; 
 int posMayor = 0;
 int posMenor = 0;
 int celda;
 int Acierto;
 int PosicionDatoMP;

 NLinea = Ini_Linea;  
 
 Acierto = 0;
 PosicionDatoMP = 0;	

	CDireccionDlg dlgDireccion;
	 
    
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_FREC) -> EnableWindow(TRUE);


	nMP = dlgDireccion.ConvertBase2(TamMP);
	nMC = dlgDireccion.ConvertBase2(TamMC);
	nBloque = dlgDireccion.ConvertBase2(TamBloque);
	nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);

	TamLinea = (int)pow(2, nLinea);
			

	
	
	//Comienzo Simulación
	
	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}

			
			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			

			
			NBloque = Truncar( NPalabra, TamBloque);
			NPalabraBloque = Sobrante( NPalabra, TamBloque);
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			
			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			


			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			

						
			
		
			    
			//Identificación del Bloque en Memoria Principal
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					
					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF);
				   
				   PosicionDatoMP = i;
				   }


				}
			}
		
			//ImprimeFormato( nMP, TamMP, arregloDirBloque, arregloDatBloque);
	
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];

			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);

					j++; 
				}
			}
	
			
			
						
			//Verificando Acierto o Fallo en Cache

						
			
			for( i = 0; i<TamMC; i++)
			{
				int NBloqueMC = Truncar(i, TamBloque);


				if(Dir == *(arrayDirMCPtr + i))
				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					            		
					NLinea = i/TamBloque;
					m_NLinea = NLinea;
					
					GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
					GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);  
			

					
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
				
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
							ColorearMC( celda, 2, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000); 
							ColorearMC( celda, 5, 0x0000FF00, 0x00000000);
						}
					}



					m_NLinea = NLinea;
					

					
					for( i = 0; i<TamLinea; i++)
					{
					    if( i == NLinea )
						{
							++*(contFrec + i);
						}		
					}
					
							
					ImprimeContadores( contFrec, TamLinea, 5);
					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!! \nNose encontró la Palabra");
					contFallos++;   
				
			
	if( Tipo == 1)
	{
		
		//Habilita controles
		GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
		GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);  
		
		//Muestra controles
		    GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(TRUE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(TRUE);
		
		//Llenado de bloques en Memoria Cache cuando está vacía
            		
			if( *(arrayDatosMCPtr + (w)*TamBloque ) == '\0')
			{
				NLinea++;

				int Menor = *(contFrec + 0);

				for(i = 0; i<TamLinea; i++)
				{
										
					if( *(contFrec + i) < Menor)
					{
						Menor = *(contFrec + i);
						NLinea = i;
					}
				    								
				}						
						
					
								
				++*(contFrec + NLinea);
				m_NLinea = NLinea;
				
				ImprimeContadores(contFrec, TamLinea, 5);	                   				
			}	
				 
					 					    
			else   //Llenado cuando esta llena la Cache
			{
				
				int Mayor = 0;
				for( i= 0; i<TamLinea; i++)
				{
					if( *(contFrec + i) > Mayor)
					{
						Mayor = *(contFrec + i);
						posMayor = i;
					}
	            		
				}
				
				
				
				int Menor = *(contFrec + posMayor);
                 
				for(i = 0; i<TamLinea; i++)
				{
										
					if( *(contFrec + i) < Menor)
					{
						Menor = *(contFrec + i);
						posMenor = i;
						NLinea = posMenor;
					}
					else
					{
						NLinea = posMenor;
					}
					
				 } 
				
				++*(contFrec + NLinea);
				ImprimeContadores( contFrec, TamLinea, 5);
			}
			
			//Introducción de Bloques a Memoria Cache 
				
				Limite = NLinea*TamBloque;			  			
					
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite)
						{
							celda = 0;
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 5, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      	
				
				}
			
			   Contador( contLineas, TamLinea, NLinea, 3);

			//Introduccion de Bloques en MP
						   	
									
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);
	 
	 }//Fin del if de Tipo
	 
	 else
	 {
			//Deshabilita controles
			GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(FALSE);  
			
			//Esconde controles
		    GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(FALSE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(FALSE);
			
			m_NLinea = "0";
			UpdateData(false);
  
			
			//Introduccion de Bloques en MP
						   	
										
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);


	 }//Fin del else de tipo

	//AgregarPar();


Salir:	
			
			//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;

						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

			
					
			if(w < TamLinea -1)
			{ 
				w++;
			}
			else
			{
				w = 0;
			}
				
			if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}
				
				
												
				//Impresión de contenido de arreglo de Memoria Cache			 
				
                ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);

				

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);

				ImprimeFormatoSim(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea);
			
		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;
		

}

//Función AC_Aleatorio_SAsig
//Función que realiza la sustitución aleatorio de Memoria Cache 
//por Método Asociativo por Conjuntos y sin asignación de escritura 

void CCache2003View::AC_Aleatorio_SAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, CString sVias, int *arrayDirSecMPPtr)
{
int NPalabra, NBloque, NLinea, NPalabraBloque, NConjunto, NVia, NPalabraConjunto, NBloqueConjunto;
int nLinea, nMP, nMC, nBloque, nConjunto, TamLinea, TamConjunto;
int Dir, Dato, DatoEscrito, Tipo, Limite, i, j; 
int Vias, celda;
int contMC = 0;
int contLinea = 0;
int Limite2;
int Acierto;
int PosicionDatoMP;

CDireccionDlg dlgDireccion;

Vias = atoi(sVias);
	  

NLinea = Ini_Linea;
PosicionDatoMP = 0;
Acierto = 0;

GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);

	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}


			
			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			
			
			

			nMP = dlgDireccion.ConvertBase2(TamMP);
			nMC = dlgDireccion.ConvertBase2(TamMC);
			nBloque = dlgDireccion.ConvertBase2(TamBloque);
			nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);   
	        nConjunto = dlgDireccion.ConvertBase2(Vias);
			

			//Control de Excepción de números fraccionarios
			
			TRY
			{
				
				if(TamBloque*Vias > TamMC )
				{
					AfxThrowUserException();
				}

				TamLinea = (int)pow(2, nLinea);
				TamConjunto = TamMC/(TamBloque*Vias);
				
				NBloque = Truncar( NPalabra, TamBloque);
				NPalabraBloque = Sobrante( NPalabra, TamBloque);
				NConjunto = NBloque % TamConjunto;
				NPalabraConjunto = Vias*TamBloque; 
				NBloqueConjunto = NPalabraConjunto/TamBloque;
			 			 			
			}
		
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los datos introducidos no son válidos para la simulación.\nProbablemente el número de vías por conjunto sea muy grande");
				OnConfigurarPolticas();
				//OnSimular();
				return; 
			}
			
			END_CATCH


			
			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			
			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			m_TamConjunto = TamConjunto;
			m_PalabraConjunto = NPalabraConjunto;
			m_nBloqueConjunto = NBloqueConjunto;
			m_NConjunto = NConjunto;
			
			
			/*
			Dato seleccionado Aleatoriamente ...."<<Dato;
			El dato corresponde a la palabra : "<<NPalabra;
			El numero de Bloque en MP correspondiente es : "<<NBloque;
			El numero de Palabra en Bloque es : "<<NPalabraBloque;
			El numero de Lineas en Cache es : "<<TamLinea;
			El numero de Conjuntos en Cache son : "<<TamConjunto;
			El numero de Palabras por conjunto es : "<<Vias*TamBloque;
			El numero de Conjunto correspondiente a Cache es : "<<NConjunto;
			
    		*/
			
			//Identificación del Bloque en Memoria Principal
			
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);

					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					//Colorea las celdas del dato
				   
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				    ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				    ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF); 
				   
				   	PosicionDatoMP = i;
				   }

				}
			}
		
				
			//Separación del Bloque encontrado en Memoria Principal
	
			
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];


			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);
					j++; 
				}
			}
	
			//ImprimeFormato( nMP, TamBloque, arrayDirBloque, arrayDatBloque);
			
			
			//Verificando Acierto o Fallo en Cache

			for( i = 0; i<TamMC; i++)
			{
				if(Dir == *(arrayDirMCPtr + i))
				{
					//Identificación del Bloque en Memoria Cache
					int NBloqueMC = Truncar(i, TamBloque);
						 //Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);

							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
					
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
				   			ColorearMC( celda, 2, 0x0000FF00, 0x00000000);
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000);

						
						}
					}
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					
                    NVia = (i/TamBloque) % Vias; 
					contAciertos++;
					m_NLinea = NBloqueMC;
					
					Acierto++;
					GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
				    GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!!\nNo se encontró la Palabra");
					contFallos++;  
		  
		
			
	if(Tipo == 1 )
	{	
			
            //Habilita controles 		
 		    GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->EnableWindow(TRUE);
			GetDlgItem(IDC_EDIT_CONJ) ->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->EnableWindow(TRUE);
			

			//Muestra controles
		    GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(TRUE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(TRUE);
			
			
			//Llenado en orden de bloques en Memoria Cache cuando está vacía
			
			NLinea = NConjunto*Vias;
					
			if( *(arrayDatosMCPtr + NLinea*TamBloque) == '\0')
			{
					
				Limite = NLinea*TamBloque;
				NVia = 0;
					
					for(j=0; j<TamMC; j++)
					{		 		  
						for(i=0; i<TamBloque; i++)
						{
							if(j == Limite) 
							{
								celda = j + 1;
								*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
								*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
								*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
								j++;
								Limite++;
								ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
								ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							}
						} 
	      													
					}
					
					m_NLinea = NLinea;
					
					
			}
						
			 
			
			else
			{
			
				//Contador de Lineas en Cache
				
				Limite2 = (NLinea*TamBloque + Vias*TamBloque); 
				
				for(i= 0; i<Limite2; i++)
				{
										
					if(*(arrayDatosMCPtr + i) != '\0')
					{
                       contLinea = Truncar(i, TamBloque);
					   contLinea++;
					   
					}
				}

				//Verificando si la MC esta llena
				contMC =0;

				for(i=0; i<TamMC; i++)
				{
					if(*(arrayDatosMCPtr + i) != '\0')
					{
						contMC++;
					}
				}
				
								
							 

				if((contMC != TamMC) && ( Limite2 > contLinea*TamBloque + 1))
				{
					
					//Proceso de LLenado de Cache...";

					NLinea = contLinea;
					NVia = contLinea;
                    contLinea = 0;
					
					
					NVia = NLinea  % Vias;
					
						   
                   			    
				}
				//Caso en que se aplican métodos de reemplazamiento
				else
				{
					//Proceso Aleatorio...
					
					srand(time(0));
					NVia = rand() % Vias;
				    
					NLinea = NVia + NConjunto*Vias;
					
													
				
				}

				
				
				Limite = NLinea*TamBloque;
						
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite) 
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      													
				}
				m_NLinea = NLinea;
				
			}
								
		
		
			Contador( contLineas, TamLinea, NLinea, 3);		
			           			
			//Introduccion de Bloques en MP

									
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

     }//Fin del if de Tipo
	 
	 else
	 {
		 
	 		//Deshabilita controles
		    GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(FALSE);  
			GetDlgItem(IDC_EDIT_N_LINEAS) ->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_CONJ) ->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->EnableWindow(FALSE);
		
			//Esconde controles
		    GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(FALSE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(FALSE);

			m_NLinea = "0";
			UpdateData(false);

					           			
			//Introduccion de Bloques en MP
			
				
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);


	 }//Fin del else de Tipo
				

	//AgregarPar();				
			
Salir:
								
			//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;
						
						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

			
			m_nLineaConjunto = NVia;
			
				

				
				//Impresión de contenido de arreglo de Memoria Cache			 
		
		
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);

		

		ImprimeFormatoSim_Conj(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea, NConjunto, NVia);
		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;

	
	

}

//Función AC_FIFO_SAsig
//Función que realiza la sustitución aleatorio de Memoria Cache 
//por Método Asociativo por Conjuntos y sin asignacion de escritura 

void CCache2003View::AC_FIFO_SAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, CString sVias, int *arrayDirSecMPPtr)
{
int NPalabra, NBloque, NLinea, NPalabraBloque, NConjunto, NVia, NPalabraConjunto, NBloqueConjunto;
int nLinea, nMP, nMC, nBloque, nConjunto, TamLinea, TamConjunto;
int Dir, Dato, DatoEscrito, Tipo, Limite, i, j; 
int celda, Vias; 
int posMayor = 0;
int posMenor = 0;
int Acierto;
int PosicionDatoMP;

Vias = atoi(sVias);

int contMC = 0;
int contLinea = 0;
int Limite2;


int NLineaInferior = 0;
int NLineaSuperior = 0;  



NLinea = Ini_Linea;  
PosicionDatoMP = 0;
Acierto = 0;

GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);



CDireccionDlg dlgDireccion;

nMP = dlgDireccion.ConvertBase2(TamMP);
nMC = dlgDireccion.ConvertBase2(TamMC);
nBloque = dlgDireccion.ConvertBase2(TamBloque);
nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);   
nConjunto = dlgDireccion.ConvertBase2(Vias);
			

TamLinea = (int)pow(2, nLinea);
TamConjunto = TamMC/(TamBloque*Vias);
	

	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}


		    
			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			
			 //Control de Excepción de números fraccionarios
			
			TRY
			{
				
				if(TamBloque*Vias > TamMC )
				{
					AfxThrowUserException();
				}

				TamLinea = (int)pow(2, nLinea);
				TamConjunto = TamMC/(TamBloque*Vias);
				
				NBloque = Truncar( NPalabra, TamBloque);
				NPalabraBloque = Sobrante( NPalabra, TamBloque);
				NConjunto = NBloque % TamConjunto;
				NPalabraConjunto = Vias*TamBloque; 
				NBloqueConjunto = NPalabraConjunto/TamBloque;
			 			 			
			}
		
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los datos introducidos no son válidos para la simulación.\nProbablemente el número de vías por conjunto sea muy grande");
				OnConfigurarPolticas();
				//OnSimular();
				return; 
			}
			
			END_CATCH

			 			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			
			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			m_TamConjunto = TamConjunto;
			m_PalabraConjunto = NPalabraConjunto;
			m_nBloqueConjunto = NBloqueConjunto;
			m_NConjunto = NConjunto;
						
			/*
			Dato seleccionado Aleatoriamente ...."<<Dato;
			El dato corresponde a la palabra : "<<NPalabra;
			El numero de Bloque en MP correspondiente es : "<<NBloque;
			El numero de Palabra en Bloque es : "<<NPalabraBloque;
			El numero de Lineas en Cache es : "<<TamLinea;
			El numero de Conjuntos en Cache son : "<<TamConjunto;
			El numero de Palabras por conjunto es : "<<Vias*TamBloque;
			El numero de Conjunto correspondiente a Cache es : "<<NConjunto;
			
    	  */

	//Identificación del Bloque en Memoria Principal
	
	for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);

					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
				
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF); 
				   
				   PosicionDatoMP = i;
				   }

				}
			}
		
			
	
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];
			
			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);

					j++; 
				}
			}
	
			
	
			//Verificando Acierto o Fallo en Cache

			for( i = 0; i<TamMC; i++)
			{
				
				int NBloqueMC = Truncar(i, TamBloque);

				if(Dir == *(arrayDirMCPtr + i))
				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					                    
					NLinea = (i/TamBloque);
					m_NLinea = NLinea;
					
					NVia = NLinea % Vias; 
					GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
					GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);

					
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);

							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
				
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
							ColorearMC( celda, 2, 0x0000FF00, 0x00000000); 
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000);
						}
					}



					NLineaInferior = NConjunto*Vias;
					NLineaSuperior = Vias + NConjunto*Vias;
                    
                
										
					ImprimeContadores( contLineas, TamLinea, 3);

					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!!\nNo se encontro la Palabra");
					contFallos++;  
		  
		
			
	 if(Tipo == 1 )
	 {
			
		    //Habilita controles
		    GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->EnableWindow(TRUE);
			GetDlgItem(IDC_EDIT_CONJ) ->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->EnableWindow(TRUE);		 
		    
			//Muestra controles
		    GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(TRUE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(TRUE);
			
			
			//Llenado en orden de bloques en Memoria Cache cuando está vacía
						
			NLineaInferior = NConjunto*Vias;
			NLineaSuperior = Vias + NConjunto*Vias;
            	
			
			NLinea = NLineaInferior;
					
			if( *(arrayDatosMCPtr + NLinea*TamBloque) == '\0')
			{
			     
					 int Menor = *(contLineas + NLinea);
					 
					 for(i= NLineaInferior; i<NLineaSuperior; i++)
					 {
					   if( *(contLineas + i)< Menor )
					   {
						   Menor = *(contLineas + i);
						   NLinea = i;
					   }
					 }

					
					 ++*(contLineas + NLinea);
					 ImprimeContadores(contLineas, TamLinea, 3);

				 	
								
				Limite = NLinea*TamBloque;
					
				NVia = 0;
				
					for(j=0; j<TamMC; j++)
					{		 		  
						for(i=0; i<TamBloque; i++)
						{
							if(j == Limite) 
							{
								celda = j + 1;
								*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
								*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
								*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
								j++;
								Limite++;
								ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							 }
						} 
	      													
					}
					
					m_NLinea = NLinea;
					
					
			}
						
			 
			
			else
			{
			
				//Contador de Lineas en Cache
				
				
				Limite2 = (NLinea*TamBloque + Vias*TamBloque); 
				
				for(i= 0; i<Limite2; i++)
				{
										
					if(*(arrayDatosMCPtr + i) != '\0')
					{
                       contLinea = Truncar(i, TamBloque);
					   contLinea++;
					   		   
					   
					}
				}

				//Verificando si la MC esta llena
				contMC =0;

				for(i=0; i<TamMC; i++)
				{
					if(*(arrayDatosMCPtr + i) != '\0')
					{
						contMC++;
					}
				}
				
								
								 

					if((contMC != TamMC) && ( Limite2 > contLinea*TamBloque + 1) && (*(arrayDatosMCPtr + NLineaSuperior*TamBloque-1) == '\0'))
					{
					
						//Proceso de LLenado de Cache...\n\n";

						NLinea = contLinea;
						NVia = contLinea;
						contLinea = 0;
					
						NVia = NLinea  % Vias;
					
					    NLinea = NVia + NConjunto*Vias;
					   
					    ++*(contLineas + NLinea);
                        ImprimeContadores(contLineas, TamLinea, 3);
					
					}
						
				
				//Caso en que se aplican métodos de reemplazamiento
				else
				{
					//Proceso LFU...\n\n";
										
					int Mayor =0;
										
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
						if( *(contLineas + i) > Mayor)
						{
							Mayor = *(contLineas + i);
							posMayor = i;
							
						}

					}

					int Menor = *(contLineas + posMayor);
										
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
						if( *(contLineas + i) < Menor)
						{
							Menor = *(contLineas + i);
							posMenor = i;
							NLinea = posMenor;
							
						}

					}

										
					++*(contLineas + NLinea);
					ImprimeContadores( contLineas, TamLinea, 3);

					
					
					NVia = NLinea % Vias;
					
													
				
				}

				
				
				Limite = NLinea*TamBloque;
						
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite) 
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      													
				}
				m_NLinea = NLinea;
				
			}
								
			
			
			//Introduccion de Bloques en MP
					   	
			
				
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en MP
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

	  }//Fin del if de Tipo

	  else
	  {

		    //Deshabilita controles
		    GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(FALSE);  
			GetDlgItem(IDC_EDIT_N_LINEAS) ->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_CONJ) ->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->EnableWindow(FALSE);
		
			//Esconde controles
		    GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(FALSE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(FALSE);
			
		    m_NLinea = "0";
			UpdateData(false); 
		  
		  //Introduccion de Bloques en MP
						   	
						
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en MP
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);
	  
	  
	  }//Fin del else de Tipo

	//AgregarPar();				
		
Salir:
								
				//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;

						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

				m_nLineaConjunto = NVia;
				
				
				
				
				if(w< TamLinea - 1)
				{
					w++;
				}
				else
				{
					w = TamLinea - 1;
				}
				
				//Impresión de contenido de arreglo de Memoria Cache			 
				
				
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}


				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);
			
		
		ImprimeFormatoSim_Conj(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea, NConjunto, NVia);

		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;

		


}

//Función AC_LFU_SAsig
//Función que realiza la sustitución aleatorio de Memoria Cache 
//por Método Asociativo por Conjuntos sin asignación de escritura 

void CCache2003View::AC_LFU_SAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contFrec, CString sVias, int *arrayDirSecMPPtr)
{

int NPalabra, NBloque, NLinea, NPalabraBloque, NConjunto, NVia, NPalabraConjunto, NBloqueConjunto;
int nLinea, nMP, nMC, nBloque, nConjunto, TamLinea, TamConjunto;
int Dir, Dato, DatoEscrito, Tipo, Limite, i, j; 
int celda, Vias; 
int posMayor = 0;
int posMenor = 0;
int Acierto;
int PosicionDatoMP;
Vias = atoi(sVias);

int contMC = 0;
int contLinea = 0;
int Limite2;

int NLineaInferior = 0;
int NLineaSuperior = 0;  


NLinea = Ini_Linea;  
Acierto = 0;
PosicionDatoMP = 0;

GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_FREC) -> EnableWindow(TRUE);	        

CDireccionDlg dlgDireccion;

nMP = dlgDireccion.ConvertBase2(TamMP);
nMC = dlgDireccion.ConvertBase2(TamMC);
nBloque = dlgDireccion.ConvertBase2(TamBloque);
nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);   
nConjunto = dlgDireccion.ConvertBase2(Vias);
			

TamLinea = (int)pow(2, nLinea);
TamConjunto = TamMC/(TamBloque*Vias);
	

	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}


			
			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			
			 //Control de Excepción de números fraccionarios
			
			TRY
			{
				
				if(TamBloque*Vias > TamMC )
				{
					AfxThrowUserException();
				}

				TamLinea = (int)pow(2, nLinea);
				TamConjunto = TamMC/(TamBloque*Vias);
				
				NBloque = Truncar( NPalabra, TamBloque);
				NPalabraBloque = Sobrante( NPalabra, TamBloque);
				NConjunto = NBloque % TamConjunto;
				NPalabraConjunto = Vias*TamBloque; 
				NBloqueConjunto = NPalabraConjunto/TamBloque;
			 			 			
			}
		
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los datos introducidos no son válidos para la simulación.\nProbablemente el número de vías por conjunto sea muy grande");
				OnConfigurarPolticas();
				//OnSimular();
				return; 
			}
			
			END_CATCH

				
 			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			


			
			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			m_TamConjunto = TamConjunto;
			m_PalabraConjunto = NPalabraConjunto;
			m_nBloqueConjunto = NBloqueConjunto;
			m_NConjunto = NConjunto;
						
			/*
			Dato seleccionado Aleatoriamente ...."<<Dato;
			El dato corresponde a la palabra : "<<NPalabra;
			El numero de Bloque en MP correspondiente es : "<<NBloque;
			El numero de Palabra en Bloque es : "<<NPalabraBloque;
			El numero de Lineas en Cache es : "<<TamLinea;
			El numero de Conjuntos en Cache son : "<<TamConjunto;
			El numero de Palabras por conjunto es : "<<Vias*TamBloque;
			El numero de Conjunto correspondiente a Cache es : "<<NConjunto;
			
    	  */

	//Identificación del Bloque en Memoria Principal
	
	for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF); 
				   
				   PosicionDatoMP = i;
				   }

				}
			}
		
			
	
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];
			
			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);

					j++; 
				}
			}
	
				
			//Verificando Acierto o Fallo en Cache

			for( i = 0; i<TamMC; i++)
			{
				
				int NBloqueMC = Truncar(i, TamBloque);

				if(Dir == *(arrayDirMCPtr + i))
				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					                    
					NLinea = (i/TamBloque);
					m_NLinea = NLinea;
					
					NVia = NLinea % Vias; 
					GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
					GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);


					
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);
							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
				
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
							ColorearMC( celda, 2, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000); 		
							ColorearMC( celda, 5, 0x0000FF00, 0x00000000);
						}
					}



					NLineaInferior = NConjunto*Vias;
					NLineaSuperior = Vias + NConjunto*Vias;
                    
                
					for( i = NLineaInferior; i<NLineaSuperior; i++)
					{
						if( NLinea == i)
						{
							++*(contFrec + i);
						}

					}

					ImprimeContadores( contFrec, TamLinea, 5);

					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!!\nNo se encontro la Palabra");
					contFallos++;  
		  
		
	if(Tipo == 1 )
	{	

			
		    //Habilita controles
		    GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->EnableWindow(TRUE);
			GetDlgItem(IDC_EDIT_CONJ) ->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->EnableWindow(TRUE);

		    //Muestra controles
		    GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(TRUE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(TRUE);
			

			//Llenado en orden de bloques en Memoria Cache cuando está vacía
						
			NLineaInferior = NConjunto*Vias;
			NLineaSuperior = Vias + NConjunto*Vias;
            	
			
			NLinea = NLineaInferior;
					
			if( *(arrayDatosMCPtr + NLinea*TamBloque) == '\0')
			{
			    	 int Menor = *(contFrec + NLinea);
					 
					 for(i= NLineaInferior; i<NLineaSuperior; i++)
					 {
					   if( *(contFrec + i)< Menor )
					   {
						   Menor = *(contFrec + i);
						   NLinea = i;
					   }
					 }

					
					 ++*(contFrec + NLinea);
					 ImprimeContadores(contFrec, TamLinea, 5);

				 	
								
				Limite = NLinea*TamBloque;
					
				NVia = 0;
				
					for(j=0; j<TamMC; j++)
					{		 		  
						for(i=0; i<TamBloque; i++)
						{
							if(j == Limite) 
							{
								celda = j + 1;
								*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
								*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
								*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
								j++;
								
								Limite++;
								ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 5, 0x000000FF, 0x00FFFFFF);

							}
						} 
	      													
					}
					
					m_NLinea = NLinea;
					
					
			}
						
			 
			
			else
			{
			
				//Contador de Lineas en Cache
				
				
				Limite2 = (NLinea*TamBloque + Vias*TamBloque); 
				
				for(i= 0; i<Limite2; i++)
				{
										
					if(*(arrayDatosMCPtr + i) != '\0')
					{
                       contLinea = Truncar(i, TamBloque);
					   contLinea++;
					   		   
					   
					}
				}

				//Verificando si la MC esta llena
				contMC =0;

				for(i=0; i<TamMC; i++)
				{
					if(*(arrayDatosMCPtr + i) != '\0')
					{
						contMC++;
					}
				}
				
								
								 

					if((contMC != TamMC) && ( Limite2 > contLinea*TamBloque + 1) && (*(arrayDatosMCPtr + NLineaSuperior*TamBloque-1) == '\0'))
					{
					
						//Proceso de LLenado de Cache...\n\n";

						NLinea = contLinea;
						NVia = contLinea;
						contLinea = 0;
					
						NVia = NLinea  % Vias;
					
					    NLinea = NVia + NConjunto*Vias;
					   
					    ++*(contFrec + NLinea);
                        ImprimeContadores(contFrec, TamLinea, 5);
					
					}
						
				
				//Caso en que se aplican métodos de reemplazamiento
				else
				{
					//Proceso LFU...\n\n";
										
					int Mayor =0;
										
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
						if( *(contFrec + i) > Mayor)
						{
							Mayor = *(contFrec + i);
							posMayor = i;
							
						}

					}

					int Menor = *(contFrec + posMayor);
										
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
						if( *(contFrec + i) < Menor)
						{
							Menor = *(contFrec + i);
							posMenor = i;
							NLinea = posMenor;
							
						}

					}

										
					++*(contFrec + NLinea);
					ImprimeContadores( contFrec, TamLinea, 5);

					
					
					NVia = NLinea % Vias;
					
													
				
				}

				
				
				Limite = NLinea*TamBloque;
						
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite) 
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 5, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      													
				}
				m_NLinea = NLinea;
				
			}
								
		
			Contador( contLineas, TamLinea, NLinea, 3);
					
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);


     }//Fin del if de Tipo
	 
	 else
	 {
		    
		    //Deshabilita controles
		    GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(FALSE);  
			GetDlgItem(IDC_EDIT_N_LINEAS) ->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_CONJ) ->EnableWindow(FALSE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->EnableWindow(FALSE);
		
			//Esconde controles
		    GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(FALSE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(FALSE);
  
			m_NLinea = "0";
			UpdateData(false); 
		  
		    //Introduccion de Bloques en MP
						   	
			
		  //Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);
	 }//Fin del else de Tipo
			    
				
//AgregarPar();
					
			
Salir:
								
				//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;

						
						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

			
				m_nLineaConjunto = NVia;
								
				
				if(w< TamLinea - 1)
				{
					w++;
				}
				else
				{
					w = TamLinea - 1;
				}
				
				//Impresión de contenido de arreglo de Memoria Cache			 
				
				
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);

		

		ImprimeFormatoSim_Conj(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea, NConjunto, NVia);
		
		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;

			

}

//Función AC_LRU_SAsig
//Función que realiza la sustitución aleatorio de Memoria Cache 
//por Método Asociativo por Conjuntos sin asignación de escritura

void CCache2003View::AC_LRU_SAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contEdad, CString sVias, int *arrayDirSecMPPtr)
{

int NPalabra, NBloque, NLinea, NPalabraBloque, NConjunto, NVia, NPalabraConjunto, NBloqueConjunto;
int nLinea, nMP, nMC, nBloque, nConjunto, TamLinea, TamConjunto;
int Dir, Dato, DatoEscrito, Tipo, Limite, i, j; 

int contMC = 0;
int contLinea = 0;
int Limite2;
int Vias, celda;
int NLineaInferior = 0;
int NLineaSuperior = 0;  
int Acierto;
int PosicionDatoMP;

CDireccionDlg dlgDireccion;


Vias = atoi(sVias);
	  

NLinea = Ini_Linea;
Acierto = 0;
PosicionDatoMP = 0;

GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_EDAD) -> EnableWindow(TRUE);


nMP = dlgDireccion.ConvertBase2(TamMP);
nMC = dlgDireccion.ConvertBase2(TamMC);
nBloque = dlgDireccion.ConvertBase2(TamBloque);
nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);   
nConjunto = dlgDireccion.ConvertBase2(Vias);
			

TamLinea = (int)pow(2, nLinea);
TamConjunto = TamMC/(TamBloque*Vias);
	

	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
  
					
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}

			
			

			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			
			
			//Control de Excepción de números fraccionarios
			
			TRY
			{
				
				if(TamBloque*Vias > TamMC )
				{
					AfxThrowUserException();
				}

				TamLinea = (int)pow(2, nLinea);
				TamConjunto = TamMC/(TamBloque*Vias);
				
				NBloque = Truncar( NPalabra, TamBloque);
				NPalabraBloque = Sobrante( NPalabra, TamBloque);
				NConjunto = NBloque % TamConjunto;
				NPalabraConjunto = Vias*TamBloque; 
				NBloqueConjunto = NPalabraConjunto/TamBloque;
			 			 			
			}
		
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los datos introducidos no son válidos para la simulación.\nProbablemente el número de vías por conjunto sea muy grande");
				OnConfigurarPolticas();
				//OnSimular();
				return; 
			}
			
			END_CATCH

 						
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);

			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			

			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			m_TamConjunto = TamConjunto;
			m_PalabraConjunto = NPalabraConjunto;
			m_nBloqueConjunto = NBloqueConjunto;
			m_NConjunto = NConjunto;
			

		  /*
			Dato seleccionado Aleatoriamente ...."<<Dato;
			El dato corresponde a la palabra : "<<NPalabra;
			El numero de Bloque en MP correspondiente es : "<<NBloque;
			El numero de Palabra en Bloque es : "<<NPalabraBloque;
			El numero de Lineas en Cache es : "<<TamLinea;
			El numero de Conjuntos en Cache son : "<<TamConjunto;
			El numero de Palabras por conjunto es : "<<Vias*TamBloque;
			El numero de Conjunto correspondiente a Cache es : "<<NConjunto;
			
    		*/
			
			//Identificación del Bloque en Memoria Principal
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					
					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000); 		

					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);
				   
				   PosicionDatoMP = i;
				   
				   }

				}
			}
		
			
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];

			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);
					j++; 
				}
			}
	
				
		
			//Verificando Acierto o Fallo en Cache

			for( i = 0; i<TamMC; i++)
			{
				if(Dir == *(arrayDirMCPtr + i))	 

				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					
                   
					int NLineaAcierto;
					NLineaAcierto = i/TamBloque;
					m_NLinea = NLineaAcierto;
					
					NVia = NLineaAcierto % Vias;
					GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
					GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);



					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(Dir == *(arrayDirMCPtr + i))
						{
							//Identificación del Bloque en Memoria Cache
							int NBloqueMC = Truncar(i, TamBloque);
							 //Colorea Acierto
							for( i = 0; i<TamMC; i++)
							{

								if(NBloqueMC == Truncar(i, TamBloque))
								{
									*(arregloDirBloqueMC + i) = i;
									*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
									*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);
									//Coloreado de celdas
									celda = 0;
									celda = i + 1;
					
									ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
									ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
				   					ColorearMC( celda, 2, 0x0000FF00, 0x00000000);  
									ColorearMC( celda, 3, 0x0000FF00, 0x00000000);
									ColorearMC( celda, 4, 0x0000FF00, 0x00000000);

								}
							}
						}
					
					}
					

					NLineaInferior = NConjunto*Vias;
					NLineaSuperior = Vias + NConjunto*Vias;

					
                
					int contActual;

					for( j = NLineaInferior; j<NLineaSuperior; j++)
					{
						if( NLineaAcierto == j)
						{
							contActual = *(contEdad + j);
						}
					}

					for( j = NLineaInferior; j<NLineaSuperior; j++)
					{
						if(*(contEdad + j) < contActual )
						{
							++*(contEdad + j);
						}

						if( NLineaAcierto == j)
						{
							*(contEdad + j)= 0;
						}
					}

					ImprimeContadores( contEdad, TamLinea, 4);

					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!!\nNo se encontró la Palabra");
					contFallos++;  
		  
		
			
	if(Tipo == 1)
	{
			
		    //Habilita controles
		    GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(TRUE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->EnableWindow(TRUE);
			GetDlgItem(IDC_EDIT_CONJ) ->EnableWindow(TRUE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->EnableWindow(TRUE);

			//Muestra controles
		    GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(TRUE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(TRUE);
			GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(TRUE);
			
			//Llenado en orden de bloques en Memoria Cache cuando está vacía
			NLineaInferior = NConjunto*Vias;
			NLineaSuperior = Vias + NConjunto*Vias;
            	

			NLinea = NLineaInferior;
					
			if( *(arrayDatosMCPtr + NLinea*TamBloque) == '\0')
			{
				
				 	for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
					   if( i == NLinea)
					   {
						   *(contEdad + NLinea) = 0;
					   }
					   else
					   {
						   ++*(contEdad + i);
					   }
					}

					ImprimeContadores(contEdad, TamLinea, 4);

				 	
								
				Limite = NLinea*TamBloque;
					
				NVia = 0;
				
					for(j=0; j<TamMC; j++)
					{		 		  
						for(i=0; i<TamBloque; i++)
						{
							if(j == Limite) 
							{
								celda = j + 1;
								*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
								*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
								*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
								j++;
								Limite++;
								ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 4, 0x000000FF, 0x00FFFFFF);
							}
						} 
	      													
					}
					
					m_NLinea = NLinea;
					
					
			}
						
			 
			//Si no está vacía
			else
			{
			
				//Contador de Lineas en Cache
				
				
				Limite2 = (NLinea*TamBloque + Vias*TamBloque); 
				
				for(i= 0; i<Limite2; i++)
				{
										
					if(*(arrayDatosMCPtr + i) != '\0')
					{
                       contLinea = Truncar(i, TamBloque);
					   contLinea++;
					   		   
					 
					}
				}

				//Verificando si la MC esta llena
				contMC =0;

				for(i=0; i<TamMC; i++)
				{
					if(*(arrayDatosMCPtr + i) != '\0')
					{
						contMC++;
					}
				}
				
								
				 

					if((contMC != TamMC) && ( Limite2 > contLinea*TamBloque + 1) && (*(arrayDatosMCPtr + NLineaSuperior*TamBloque-1) == '\0'))
					{
					
						//Proceso de LLenado de Cache...\n\n";

						NLinea = contLinea;
						NVia = contLinea;
						contLinea = 0;
					
						NVia = NLinea  % Vias;

						NLineaInferior = NConjunto*Vias;
						NLineaSuperior = Vias + NConjunto*Vias;
										
					
						for(i= NLineaInferior; i<NLineaSuperior; i++)
						{
						   if( i == NLinea)
						   {
							   *(contEdad + NLinea) = 0;
						   }
						   else
						   {
							   ++*(contEdad + i);
						   }
						}

						ImprimeContadores(contEdad, TamLinea, 4);

											
							    
				}
				//Caso en que se aplican métodos de reemplazamiento
				else
				{
					//Proceso LRU...\n\n";
										
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
						if( *(contEdad + i) == (Vias - 1))
						{
							NLinea = i;
							
						}

					}

					ImprimeContadores( contEdad, TamLinea, 4);

					
					
					NVia = NLinea % Vias;
					
													
				
				}

				
				
				Limite = NLinea*TamBloque;
						
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite) 
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 4, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      													
				}
				m_NLinea =NLinea;
				UpdateData(false);
			}
								
					
			Contador( contLineas, TamLinea, NLinea, 3);
		
			//Introduccion de Bloques en MP
				
							
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

	 }//Fin del if de Tipo

	 else
	 {

		//Deshabilita controles
		GetDlgItem(IDC_EDIT_LINEA) ->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_LINEA) ->EnableWindow(FALSE);  
		GetDlgItem(IDC_EDIT_N_LINEAS) ->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_LINEA_CONJ) ->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_CONJ) ->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_CONJ_MC) ->EnableWindow(FALSE);
		
		//Esconde controles
		    GetDlgItem(IDC_EDIT_LINEA) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA) ->ShowWindow(FALSE);
            GetDlgItem(IDC_EDIT_N_LINEAS) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_LINEA_CONJ) ->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT_CONJ) ->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_CONJ_MC) ->ShowWindow(FALSE);
 
		 m_NLinea = "0";
		 UpdateData(false); 
		 
		 
		 
		 //Introduccion de Bloques en MP
		 
				
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{		 		  
					if(NBloque == Truncar(j, TamBloque))
					{
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  j;
							*(arrayDatosMPPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloque + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
								
													
					}
					 
	      			//Colorea celdas del dato escrito y Actualiza el dato escrito en MP 
				   if(Dir == *(arrayDirMPPtr + j))
				   {
				   	
					//Introduce el dato escrito en cache
					*(arrayDatosMPPtr + j) = DatoEscrito;
   
					*(arrayDatosMPPtr + j) = *(arrayDatosMPPtr + PosicionDatoMP);
				    ColorearMP( celda, 0, 0x00FF0000, 0x00FFF000);  
				    ColorearMP( celda, 1, 0x00FF0000, 0x00FFF000);   
				    ColorearMP( celda, 2, 0x00FF0000, 0x00FFF000); 
				   		   
				   }


				}
			
			}	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);



	 }//Fin del else de Tipo

//AgregarPar();						
			
Salir:
				//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;

						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

			
				
				m_nLineaConjunto = NVia;
								
				 
				if(w< TamLinea - 1)
				{
					w++;
				}
				else
				{
					w = TamLinea - 1;
				}
				
				//Impresión de contenido de arreglo de Memoria Cache			 
				
				
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}


				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);
			
		
		
		ImprimeFormatoSim_Conj(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea, NConjunto, NVia);

		
		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;

		
		
}

//Función SimulaDirecto_Post
//Función que realiza la simulación de comportamiento de Memoria Cache por el método Directo
//con política de post-escritura

void CCache2003View::SimulaDirecto_Post(int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr)
{
   int NPalabra, NBloque, NLinea, NPalabraBloque;
   int nLinea, nMP, nMC, nBloque, TamLinea;
   int Dato, Dir, Tipo, DatoEscrito, i, j, k; 
   int celda;
   int Acierto;
   int PosicionDato, PosicionDatoMP;
   int NBloqueMC = 0;

   
   Acierto = 0;
   
    
    GetDlgItem(IDC_EDIT_MET_REEMPLAZA)->EnableWindow(FALSE);

	
    GetDlgItem(IDC_STATIC_N_BLOQUES_CONJ) ->EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT_N_BLOQUES_CONJ) -> EnableWindow(FALSE);
    GetDlgItem(IDC_STATIC_N_CONJ) -> EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_N_CONJ) -> EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_PALABRAS_CONJ) -> EnableWindow(FALSE);	
    GetDlgItem(IDC_EDIT_PALABRAS_CONJ) -> EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_CONJ_MC) -> EnableWindow(FALSE);	
    GetDlgItem(IDC_EDIT_CONJ) -> EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_LINEA_CONJ) -> EnableWindow(FALSE);	
    GetDlgItem(IDC_EDIT_N_LINEAS) -> EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);

	CDireccionDlg dlgDireccion;
   	CEscrituraDlg dlgEscritura;
   
			
	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
			

			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}

			
			
			
			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			UpdateData(false);
			
			nMP = dlgDireccion.ConvertBase2(TamMP);
			nMC = dlgDireccion.ConvertBase2(TamMC);
			nBloque = dlgDireccion.ConvertBase2(TamBloque);
			nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);   
	
			TamLinea = (int)pow(2, nLinea);
			   			   					
			NBloque = Truncar( NPalabra, TamBloque);
			NPalabraBloque = Sobrante( NPalabra, TamBloque);
			NLinea = NBloque % TamLinea;
		  	
			 ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);

			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipos de datos correspondientes al bloque
			int *arregloTipoBloque = new int[ TamMP ];
			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';

			}

			
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			m_NLinea = NLinea;
			

			


    
			//Identificación del Bloque en Memoria Principal
			
			for( i = 0; i<TamMP; i++)
			{
				
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					//Coloreado de celdas
					celda = 0;
					celda = i + 1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF); 
				   
				   PosicionDatoMP = i;
				   
				   }
				}
			

			}
		
			
			
			//Separación del Bloque encontrado en Memoria Principal
						
			//Creación de Arreglo temporal para colocar el bloque encontrado en MP
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];
			
			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j) = *(arregloTipoBloque + i);
					j++; 
				}
			}
			
			
			//Separación del Bloque encontrado en Memoria Cache
			
			//Creación de Arreglo temporal para colocar el bloque encontrado en MC
			int *arrayDirBloqueMC = new int[ TamBloque ];
			int *arrayDatBloqueMC = new int[ TamBloque ];
			int *arrayTipoBloqueMC = new int[ TamBloque ];
			
	        	  

	

			//Verificando Acierto o Fallo en Cache

			for( i = 0; i<TamMC; i++)
			{
				if(Dir == *(arrayDirMCPtr + i))
				{
					
					MessageBox("A C I E R T O!!! \nSe encontró la Palabra");
					contAciertos++;
					Acierto++;
					
					goto MC;
				}
	          
			}	  
				
			MessageBox("F A L L O!!!\nNo se encontró la Palabra");
			contFallos++;  
		  			
			Contador( contLineas, TamLinea, NLinea, 3);  	
	
			
	  //Gestion Post_Escritura

	  for( k =0; k<TamLinea; k++)
	  {
		if( (*(contLineas + k) != 0) && (*(contLineas + k) != 1) )
		{

					

			
			for( i= 0; i<TamMC; i++)
			{
				
				if( *(arrayDirMCPtr + i) == *(arrayDirMCPtr + NLinea*TamBloque))
				{
				   NBloqueMC = Truncar(i, TamBloque);
					
					for(j = 0; j<TamBloque; j++)
					{
						if( NBloqueMC == Truncar(i, TamBloque))
						{
							*(arrayDirBloqueMC + j ) = *(arrayDirMCPtr + i);
							*(arrayDatBloqueMC + j ) = *(arrayDatosMCPtr + i);
							*(arrayTipoBloqueMC + j) = *(arrayTipoMCPtr + i);
						 	i++;
							
					  	}
					}
				}
			}
			
		
		
			//Introduccion de Bloques en MP
  								
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{	
					

					if(*(arrayDirMPPtr + j) == *(arrayDirBloqueMC + i))
					{
							
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  *(arrayDirBloqueMC + i);
							*(arrayDatosMPPtr + j) = *(arrayDatBloqueMC + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloqueMC + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
																				
					}
					
				}
			
			}	
		

		
				
		
		}//primer if
	  }//for


 			
			
	 
	
		ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

		//AgregarPar();
		
//Introducción de Bloques a Memoria Cache 
MC:
									
			int Limite = NLinea*TamBloque;					
								
							
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite)
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							
														
							j++;
							Limite++;
							if( Acierto == 1)
							{
								ColorearMC( celda, 0, 0x0000FF00, 0x00000000); 
								ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 
								ColorearMC( celda, 2, 0x0000FF00, 0x00000000);
								ColorearMC( celda, 3, 0x0000FF00, 0x00000000);
							}
						    else
							{
								
								ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
								ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);

							}
						
										
						}
					} 
	      	
				}
			
						
				//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;
						PosicionDato = i;
						
						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
			
				}
				
				
 
				//Impresión de contenido de arreglo de Memoria Cache			 
				
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);

				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}


					}
					else
					{
						nSim++;

						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						UpdateData(false);
					}
				}
				else
				{
					 nSim++;

					 m_contAciertos = contAciertos;
					 m_contFallos = contFallos;
					 m_nSim = nSim;
					 UpdateData(false);
				}

				

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);

				ImprimeFormatoSim(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea);
	   		
	   delete arrayDirBloque;
	   delete arrayDatBloque;
	   delete arrayTipoBloque;
	   delete arregloDirBloque;
	   delete arregloDatBloque;
	   delete arregloTipoBloque;
	   delete arrayDirBloqueMC;
	   delete arrayDatBloqueMC;
	   delete arrayTipoBloqueMC;

}

//Función A_Aleatorio_Post
//Función que realiza la sustitución aleatorio de Memoria Cache 
//por Método Asociativo y politica de post-escritura 

void CCache2003View::A_Aleatorio_Post(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr)
{
	int NPalabra, NBloque, NPalabraBloque, NLinea;
	int nLinea, nMP, nMC, nBloque, TamLinea;
	int Dato, DatoEscrito, Dir, Tipo, i, j, k, Limite; 
	int celda;
    int Acierto;
	int PosicionDatoMP;
	int NBloqueMC;
	
	
	NLinea = Ini_Linea;
	
	Acierto = 0;
	PosicionDatoMP = 0;
	CDireccionDlg dlgDireccion;
	 
    
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);

	 	   	
			     
	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}

			

			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			
			



			nMP = dlgDireccion.ConvertBase2(TamMP);
			nMC = dlgDireccion.ConvertBase2(TamMC);
			nBloque = dlgDireccion.ConvertBase2(TamBloque);
			nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);
			
			TamLinea = (int)pow(2, nLinea);
			
			NBloque = Truncar( NPalabra, TamBloque);
			NPalabraBloque = Sobrante( NPalabra, TamBloque);
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			
			
			
			//Arreglo temporal para buscar direcciones correspondientes al bloque en MP
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MP
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];


			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];
			


			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			}

			
			for(i=0; i<TamMP; i++)
			{
				
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			
			    
			//Identificación del Bloque en Memoria Principal
			
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000); 
					
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF);
				   
				   PosicionDatoMP = i;
				   }

				
				}
			}
		
				
			//Separación del Bloque encontrado en Memoria Principal
			//Bloque de Direcciones y Datos a traspasar a Cache...  
			
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];


			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);

					j++; 
				}
			}
	
			//Separación del Bloque encontrado en Memoria Cache
			
			//Creación de Arreglo temporal para colocar el bloque encontrado en MC
			int *arrayDirBloqueMC = new int[ TamBloque ];
			int *arrayDatBloqueMC = new int[ TamBloque ];
			int *arrayTipoBloqueMC = new int[ TamBloque ];
			
	        
	
	
		
			
			//Verificando Acierto o Fallo en Cache

			
			for( i = 0; i<TamMC; i++)
			{
				if(Dir == *(arrayDirMCPtr + i))
				{
										
					//Identificación del Bloque en Memoria Cache
					int NBloqueMC = Truncar(i, TamBloque);
					
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{
						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);

							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
					
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
				   			ColorearMC( celda, 2, 0x0000FF00, 0x00000000);
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000);

						}
					}
					
					m_NLinea = NBloqueMC;
					UpdateData(false);
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
					
				}
	          
			}	  
					MessageBox("F A L L O!!! \nNo se encontró la Palabra");
					contFallos++;   
	
										
			//Llenado en orden de bloques en Memoria Cache cuando está vacía
		 
	        	
			if( *(arrayDatosMCPtr + (w)*TamBloque ) == '\0')
			{
				NLinea++;
				m_NLinea = NLinea;
				
			}

			else
			{
				srand( time( 0) );
				NLinea = rand() % TamLinea;
				m_NLinea = NLinea;
				
			}
			
	
	Contador( contLineas, TamLinea, NLinea, 3);	
	
	//Gestion Post_Escritura

	  for( k =0; k<TamLinea; k++)
	  {
		if( (*(contLineas + k) != 0) && (*(contLineas + k) != 1) )
		{

					

			
			for( i= 0; i<TamMC; i++)
			{
				
				if( *(arrayDirMCPtr + i) == *(arrayDirMCPtr + NLinea*TamBloque))
				{
				   NBloqueMC = Truncar(i, TamBloque);
					
					for(j = 0; j<TamBloque; j++)
					{
						if( NBloqueMC == Truncar(i, TamBloque))
						{
							*(arrayDirBloqueMC + j ) = *(arrayDirMCPtr + i);
							*(arrayDatBloqueMC + j ) = *(arrayDatosMCPtr + i);
							*(arrayTipoBloqueMC + j) = *(arrayTipoMCPtr + i);
						 	i++;
							
							
					  	}
					}
				}
			}
			
		
		
			//Introduccion de Bloques en MP
  			
					
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{	
					

					if(*(arrayDirMPPtr + j) == *(arrayDirBloqueMC + i))
					{
							

							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  *(arrayDirBloqueMC + i);
							*(arrayDatosMPPtr + j) = *(arrayDatBloqueMC + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloqueMC + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
																				
					}
					
				}
			
			}	
		

		
				
		
		}//primer if
	  }//for





			//Introducción de Bloques a Memoria Cache 
				
				Limite = NLinea*TamBloque;			  			
					
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite)
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      	
				
				}
			
					
			

			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

			AgregarPar();


Salir:	
			
			//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;
						
						
						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

						
				
			if(w < TamLinea)
			{ 
				w++;
			}
			else
			{
				w = TamLinea;
			}
													
				//Impresión de contenido de arreglo de Memoria Cache			 
				
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}
				
				

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);
				

		

		ImprimeFormatoSim(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea);


		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;
		delete arrayDirBloqueMC;
		delete arrayDatBloqueMC;
		delete arrayTipoBloqueMC;
}


//Función A_FIFO_Post ( Sustituye los bloques en forma First In First Out )
//Simula la Politica de sustitución Aleatoria en Memoria Cache por Método Asociativo
//politica de post-escritura

void CCache2003View::A_FIFO_Post(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr)
{
 int NPalabra, NBloque, NLinea, NPalabraBloque;
 int nLinea, nMP, nMC, nBloque, TamLinea;
 int Dir, Dato, DatoEscrito, Tipo, i, j, k, Limite; 
 int posMayor = 0;
 int posMenor = 0;
 int celda;
 int Acierto;   
 int PosicionDatoMP;
 int NBloqueMC;

 NLinea = Ini_Linea;  
 
 Acierto = 0;
 PosicionDatoMP = 0;	
    
    CDireccionDlg dlgDireccion;
	 
    
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);


	nMP = dlgDireccion.ConvertBase2(TamMP);
	nMC = dlgDireccion.ConvertBase2(TamMC);
	nBloque = dlgDireccion.ConvertBase2(TamBloque);
	nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);

	TamLinea = (int)pow(2, nLinea);
			

	
	
	//Comienzo Simulación
	
	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}

			

			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			
			
			
			NBloque = Truncar( NPalabra, TamBloque);
			NPalabraBloque = Sobrante( NPalabra, TamBloque);
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			

						
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];



			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			}

			
			
			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			
						    
			//Identificación del Bloque en Memoria Principal
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					
					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF);
				   
				   PosicionDatoMP = i;
				   }


				}
			}
		
			
	
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];

			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);
					
					j++; 
				}
			}
	
			
			//Separación del Bloque encontrado en Memoria Cache
			
			//Creación de Arreglo temporal para colocar el bloque encontrado en MC
			int *arrayDirBloqueMC = new int[ TamBloque ];
			int *arrayDatBloqueMC = new int[ TamBloque ];
			int *arrayTipoBloqueMC = new int[ TamBloque ];
			
	        
		
						
			//Verificando Acierto o Fallo en Cache

						
			
			for( i = 0; i<TamMC; i++)
			{
				int NBloqueMC = Truncar(i, TamBloque);


				if(Dir == *(arrayDirMCPtr + i))
				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					            		
					NLinea = i/TamBloque;
					m_NLinea = NLinea;
					
					
					
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);

							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
				
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
							ColorearMC( celda, 2, 0x0000FF00, 0x00000000); 
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000);
						}
					}



					m_NLinea = NLinea;
					UpdateData(false);

									
					ImprimeContadores( contLineas, TamLinea, 3);
					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!! \nNo se encontró la Palabra");
					contFallos++;   
				
			//Llenado de bloques en Memoria Cache cuando está vacía
            		 
			
			
			if( *(arrayDatosMCPtr + (w)*TamBloque ) == '\0')
			{
				NLinea++;

				int Menor = *(contLineas + 0);

				for(i = 0; i<TamLinea; i++)
				{
										
					if( *(contLineas + i) < Menor)
					{
						Menor = *(contLineas + i);
						NLinea = i;
					}
				    								
				}						
						
					
								
				++*(contLineas + NLinea);
				m_NLinea = NLinea;
				
				ImprimeContadores(contLineas, TamLinea, 3);	                   				
			}	
				 
					 					    
			else   //Llenado cuando esta llena la Cache
			{
				
				int Mayor = 0;
				for( i= 0; i<TamLinea; i++)
				{
					if( *(contLineas + i) > Mayor)
					{
						Mayor = *(contLineas + i);
						posMayor = i;
					}
	            		
				}
				
				
				
				int Menor = *(contLineas + posMayor);
                 
				for(i = 0; i<TamLinea; i++)
				{
										
					if( *(contLineas + i) < Menor)
					{
						Menor = *(contLineas + i);
						posMenor = i;
						NLinea = posMenor;
					}
					else
					{
						NLinea = posMenor;
					}
					
				 } 
				
				++*(contLineas + NLinea);
				ImprimeContadores( contLineas, TamLinea, 3);
			}
			
			
	//Gestion Post_Escritura

	  for( k =0; k<TamLinea; k++)
	  {
		if( (*(contLineas + k) != 0) && (*(contLineas + k) != 1) )
		{

					

			
			for( i= 0; i<TamMC; i++)
			{
				
				if( *(arrayDirMCPtr + i) == *(arrayDirMCPtr + NLinea*TamBloque))
				{
				   NBloqueMC = Truncar(i, TamBloque);
					
			
					for(j = 0; j<TamBloque; j++)
					{
						if( NBloqueMC == Truncar(i, TamBloque))
						{
							*(arrayDirBloqueMC + j ) = *(arrayDirMCPtr + i);
							*(arrayDatBloqueMC + j ) = *(arrayDatosMCPtr + i);
							*(arrayTipoBloqueMC + j) = *(arrayTipoMCPtr + i);
						 	i++;
							
							
					  	}
					}
				}
			}
			
		
		
			//Introduccion de Bloques en MP
  			
					
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{	
					

					if(*(arrayDirMPPtr + j) == *(arrayDirBloqueMC + i))
					{
							
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  *(arrayDirBloqueMC + i);
							*(arrayDatosMPPtr + j) = *(arrayDatBloqueMC + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloqueMC + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
																				
					}
					
				}
			
			}	
		

		
				
		
		}//primer if
	  }//for




			
			
			//Introducción de Bloques a Memoria Cache 
				
				Limite = NLinea*TamBloque;			  			
					
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite)
						{
							celda = 0;
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);

							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
						}
					} 
	      	
				
				}
			
			  

			
			ImprimeFormatoMC(m_nMP, m_TamMC, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

			//AgregarPar();

Salir:	
			
			//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;

						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

						
				
			if(w < TamLinea -1)
			{ 
				w++;
			}
			else
			{
				w = 0;
			}
				

												
				//Impresión de contenido de arreglo de Memoria Cache			 
				
                ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);

				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}
				
				

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);

				ImprimeFormatoSim(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea);
			
		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;
		delete arrayDirBloqueMC;
		delete arrayDatBloqueMC;
		delete arrayTipoBloqueMC;

		
	

}

//Función A_LFU_Post ( Sustituye el bloque que haya sido menos utilizado )
//Simula la Politica de sustitución Least Frecuently Use en Memoria Cache Método Asociativo
//política de post-escritura

void CCache2003View::A_LFU_Post(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contFrec, int *arrayDirSecMPPtr)
{
 int NPalabra, NBloque, NLinea, NPalabraBloque;
 int nLinea, nMP, nMC, nBloque, TamLinea;
 int Dir, Dato, DatoEscrito, Tipo, i, j, k, Limite; 
 int posMayor = 0;
 int posMenor = 0;
 int celda;
 int Acierto;
 int PosicionDatoMP;
 int NBloqueMC;

 NLinea = Ini_Linea;  
 
 Acierto = 0;
 PosicionDatoMP = 0;	

	CDireccionDlg dlgDireccion;
	
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_FREC) -> EnableWindow(TRUE);


	nMP = dlgDireccion.ConvertBase2(TamMP);
	nMC = dlgDireccion.ConvertBase2(TamMC);
	nBloque = dlgDireccion.ConvertBase2(TamBloque);
	nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);

	TamLinea = (int)pow(2, nLinea);
			

	
	
	//Comienzo Simulación
	
	
	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}


			


			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			

			
			NBloque = Truncar( NPalabra, TamBloque);
			NPalabraBloque = Sobrante( NPalabra, TamBloque);
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			

						
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			
						    
			//Identificación del Bloque en Memoria Principal
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					
					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF);
				   
				   PosicionDatoMP = i;
				   }


				}
			}
		
			
	
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];

			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);

					j++; 
				}
			}
	
			
			 //Separación del Bloque encontrado en Memoria Cache
			
			//Creación de Arreglo temporal para colocar el bloque encontrado en MC
			int *arrayDirBloqueMC = new int[ TamBloque ];
			int *arrayDatBloqueMC = new int[ TamBloque ];
			int *arrayTipoBloqueMC = new int[ TamBloque ];
			
	        
						
			//Verificando Acierto o Fallo en Cache

						
			
			for( i = 0; i<TamMC; i++)
			{
				int NBloqueMC = Truncar(i, TamBloque);


				if(Dir == *(arrayDirMCPtr + i))
				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					            		
					NLinea = i/TamBloque;
					m_NLinea = NLinea;
					
					
					
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
				
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
							ColorearMC( celda, 2, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000); 
							ColorearMC( celda, 5, 0x0000FF00, 0x00000000);
						}
					}



					m_NLinea = NLinea;
					

					
					for( i = 0; i<TamLinea; i++)
					{
					    if( i == NLinea )
						{
							++*(contFrec + i);
						}		
					}
					
							
					ImprimeContadores( contFrec, TamLinea, 5);
					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!! \nNose encontró la Palabra");
					contFallos++;   
				
			
			//Llenado de bloques en Memoria Cache cuando está vacía
            		
			if( *(arrayDatosMCPtr + (w)*TamBloque ) == '\0')
			{
				NLinea++;

				int Menor = *(contFrec + 0);

				for(i = 0; i<TamLinea; i++)
				{
										
					if( *(contFrec + i) < Menor)
					{
						Menor = *(contFrec + i);
						NLinea = i;
					}
				    								
				}						
						
					
								
				++*(contFrec + NLinea);
				m_NLinea = NLinea;
				
				ImprimeContadores(contFrec, TamLinea, 5);	                   				
			}	
				 
					 					    
			else   //Llenado cuando esta llena la Cache
			{
				
				int Mayor = 0;
				for( i= 0; i<TamLinea; i++)
				{
					if( *(contFrec + i) > Mayor)
					{
						Mayor = *(contFrec + i);
						posMayor = i;
					}
	            		
				}
				
				
				
				int Menor = *(contFrec + posMayor);
                 
				for(i = 0; i<TamLinea; i++)
				{
										
					if( *(contFrec + i) < Menor)
					{
						Menor = *(contFrec + i);
						posMenor = i;
						NLinea = posMenor;
					}
					else
					{
						NLinea = posMenor;
					}
					
				 } 
				
				++*(contFrec + NLinea);
				ImprimeContadores( contFrec, TamLinea, 5);
			}
			
			
			Contador( contLineas, TamLinea, NLinea, 3);
			
	//Gestion Post_Escritura

	  for( k =0; k<TamLinea; k++)
	  {
		if( (*(contLineas + k) != 0) && (*(contLineas + k) != 1) )
		{

					

			
			for( i= 0; i<TamMC; i++)
			{
				
				if( *(arrayDirMCPtr + i) == *(arrayDirMCPtr + NLinea*TamBloque))
				{
				   NBloqueMC = Truncar(i, TamBloque);
					
			
					for(j = 0; j<TamBloque; j++)
					{
						if( NBloqueMC == Truncar(i, TamBloque))
						{
							*(arrayDirBloqueMC + j ) = *(arrayDirMCPtr + i);
							*(arrayDatBloqueMC + j ) = *(arrayDatosMCPtr + i);
							*(arrayTipoBloqueMC + j) = *(arrayTipoMCPtr + i);
						 	i++;
							
							
					  	}
					}
				}
			}
			
		
		
			//Introduccion de Bloques en MP
  			
					
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{	
					

					if(*(arrayDirMPPtr + j) == *(arrayDirBloqueMC + i))
					{
							
							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  *(arrayDirBloqueMC + i);
							*(arrayDatosMPPtr + j) = *(arrayDatBloqueMC + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloqueMC + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
																				
					}
					
				}
			
			}	
		

		
				
		
		}//primer if
	  }//for



			
			//Introducción de Bloques a Memoria Cache 
				
				Limite = NLinea*TamBloque;			  			
					
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite)
						{
							celda = 0;
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 5, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      	
				
				}
			
			   
						   
			
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

			
			//AgregarPar();


Salir:	
			
			//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;

						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

			
							
			if(w < TamLinea -1)
			{ 
				w++;
			}
			else
			{
				w = 0;
			}
				

												
				//Impresión de contenido de arreglo de Memoria Cache			 
				
                ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);

				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}
				
				

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);

				ImprimeFormatoSim(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea);
			
		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;
		delete arrayDirBloqueMC;
		delete arrayDatBloqueMC;
		delete arrayTipoBloqueMC;
			

}

//Función A_LRU_Post ( Sustituye el bloque que lleva más tiempo sin haber sido utilizado )
//Simula la Politica de sustitución Least Recently Use en Memoria Cache Método Asociativo
//política de post-escritura

void CCache2003View::A_LRU_Post(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contEdad, int *arrayDirSecMPPtr)
{
	int NPalabra, NBloque, NLinea, NPalabraBloque;
	int nLinea, nMP, nMC, nBloque, TamLinea;
	int Dir, Dato, DatoEscrito, Tipo, i, j, k, Limite; 
	int celda;
	int Acierto;
	int PosicionDatoMP;
	int NBloqueMC;

	NLinea = Ini_Linea;  
	
	Acierto = 0;
	PosicionDatoMP = 0;

	CDireccionDlg dlgDireccion;
	 
    
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_EDAD) -> EnableWindow(TRUE);


	nMP = dlgDireccion.ConvertBase2(TamMP);
	nMC = dlgDireccion.ConvertBase2(TamMC);
	nBloque = dlgDireccion.ConvertBase2(TamBloque);
	nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);

	TamLinea = (int)pow(2, nLinea);
	
	
	

		//Comienzo Simulación
	 
	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}

			

			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			

			
			
			NBloque = Truncar( NPalabra, TamBloque);
			NPalabraBloque = Sobrante( NPalabra, TamBloque);
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			
			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			
			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			
						
			    
			//Identificación del Bloque en Memoria Principal
			
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);

					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF); 
				   
				   PosicionDatoMP = i;
				   
				   }


				}
			}
		
			
			
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];

			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);
					j++; 
				}
			}
	
			
			//Separación del Bloque encontrado en Memoria Cache
			
			//Creación de Arreglo temporal para colocar el bloque encontrado en MC
			int *arrayDirBloqueMC = new int[ TamBloque ];
			int *arrayDatBloqueMC = new int[ TamBloque ];
			int *arrayTipoBloqueMC = new int[ TamBloque ];
			
	        

			//Verificando Acierto o Fallo en Cache
									
			
			for( i = 0; i<TamMC; i++)
			{
				
				//Identificación del Bloque en Memoria Cache
				int NBloqueMC = Truncar(i, TamBloque);
				
				
				if(Dir == *(arrayDirMCPtr + i))
				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					            		
					
					
					int NLineaAcierto;
					NLineaAcierto = i/TamBloque;
					m_NLinea = NLineaAcierto;
										
					 
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
				
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
							ColorearMC( celda, 2, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000); 		
							ColorearMC( celda, 4, 0x0000FF00, 0x00000000); 
						}
					}

      			

					
					int contActual;
					
					for( j = 0; j<TamLinea; j++)
					{
						if( NLineaAcierto == j) 
						{ 
							contActual = *(contEdad + j);
						    						     
						}	
						
					}
					for(j = 0; j<TamLinea; j++)
					{
						if(*(contEdad + j)  <  contActual )
						{ 
							++*(contEdad + j);
						}
					   
						if( NLineaAcierto == j)
						{
						*(contEdad + j ) = 0;
						}
					 					 	
					}
					
					
								
					
					ImprimeContadores( contEdad, TamLinea, 4);
					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					
					MessageBox("F A L L O!!!\nNo se encontró la Palabra");
					contFallos++;   
				
			//Llenado de bloques en Memoria Cache cuando está vacía
            	
			
			if( *(arrayDatosMCPtr + (w)*TamBloque ) == '\0')
			{
				NLinea++;
				m_NLinea = NLinea;
				
				
				for( i = 0; i<TamLinea; i++)
				{



					if( i == NLinea )
					{
					   *(contEdad + NLinea) = 0;
	                   				
					}	
					else
					{
						++*(contEdad + i); 
					 					    
					}
				 				
				}
                
				ImprimeContadores(contEdad, TamLinea, 4);

			}
			else   //Llenado cuando esta llena la Cache
			{
				for(i = 0; i<TamLinea; i++)
				{
					
					if( *(contEdad + i) == (TamLinea - 1))
					{
					   NLinea = i;
					   m_NLinea = NLinea;
					   
					}
				
				}
			    
				ImprimeContadores( contEdad, TamLinea, 4);
			}
			
			Contador( contLineas, TamLinea, NLinea, 3);

			//Gestion Post_Escritura

	  for( k =0; k<TamLinea; k++)
	  {
		if( (*(contLineas + k) != 0) && (*(contLineas + k) != 1) )
		{

					

			
			for( i= 0; i<TamMC; i++)
			{
				
				if( *(arrayDirMCPtr + i) == *(arrayDirMCPtr + NLinea*TamBloque))
				{
				   NBloqueMC = Truncar(i, TamBloque);
					
			
					for(j = 0; j<TamBloque; j++)
					{
						if( NBloqueMC == Truncar(i, TamBloque))
						{
							*(arrayDirBloqueMC + j ) = *(arrayDirMCPtr + i);
							*(arrayDatBloqueMC + j ) = *(arrayDatosMCPtr + i);
							*(arrayTipoBloqueMC + j) = *(arrayTipoMCPtr + i);
						 	i++;
							
							
					  	}
					}
				}
			}
			
		
		
			//Introduccion de Bloques en MP
  			
					
			//Identifica y deposita el Bloque en MP 
			if( Acierto == 0) 	
			{	
				i=0;
				for(j=0; j<TamMP; j++)
				{	
					

					if(*(arrayDirMPPtr + j) == *(arrayDirBloqueMC + i))
					{
							

							celda = 0;
							celda = j + 1;
														
							*(arrayDirMPPtr + j) =  *(arrayDirBloqueMC + i);
							*(arrayDatosMPPtr + j) = *(arrayDatBloqueMC + i);
							*(arrayTipoMPPtr + j) = *(arrayTipoBloqueMC + i);
							
							i++;			 

							ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
							ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
																				
					}
					
				}
			
			}	
		

		
				
		
		}//primer if
	  }//for



			
			
			//Introducción de Bloques a Memoria Cache 
				
				Limite = NLinea*TamBloque;			  			
					
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite)
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);

							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 4, 0x000000FF, 0x00FFFFFF);
						}
					} 
	      	
				
				}
			
				

				
			ImprimeFormatoMC(m_nMP, m_TamMC, m_arrayDirMCPtr, m_arrayDatosMCPtr, m_arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);


			//AgregarPar();


Salir:	
			
			//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;
						
						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
							
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
							
						}
					}
				}

			
			if(w < TamLinea -1 )
			{ 
				w++;
			}
			else
			{
				w = TamLinea - 1 ;
			}
				
			  				
				//Impresión de contenido de arreglo de Memoria Cache			 
				
               	ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}
				
				

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);
			
		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;
		delete arrayDirBloqueMC;
		delete arrayDatBloqueMC;
		delete arrayTipoBloqueMC;

		

		ImprimeFormatoSim(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea);
}

//Función AC_Aleatorio_Post
//Función que realiza la sustitución aleatorio de Memoria Cache 
//por Método Asociativo por Conjuntos y política de  post-escritura 

void CCache2003View::AC_Aleatorio_Post(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, CString sVias, int *arrayDirSecMPPtr)
{

int NPalabra, NBloque, NLinea, NPalabraBloque, NConjunto, NVia, NPalabraConjunto, NBloqueConjunto;
int nLinea, nMP, nMC, nBloque, nConjunto, TamLinea, TamConjunto;
int Dir, Dato, DatoEscrito, Tipo, Limite, i, j, k; 
int Vias, celda;
int contMC = 0;
int contLinea = 0;
int Limite2;
int Acierto;
int PosicionDatoMP;
int NBloqueMC;

CDireccionDlg dlgDireccion;

Vias = atoi(sVias);
	  

NLinea = Ini_Linea;
PosicionDatoMP = 0;
Acierto = 0;

GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);

	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}


			

			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
					
			

			nMP = dlgDireccion.ConvertBase2(TamMP);
			nMC = dlgDireccion.ConvertBase2(TamMC);
			nBloque = dlgDireccion.ConvertBase2(TamBloque);
			nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);   
	        nConjunto = dlgDireccion.ConvertBase2(Vias);
			
			//Control de Excepción de números fraccionarios
			
			TRY
			{
				
				if(TamBloque*Vias > TamMC )
				{
					AfxThrowUserException();
				}

				TamLinea = (int)pow(2, nLinea);
				TamConjunto = TamMC/(TamBloque*Vias);
				
				NBloque = Truncar( NPalabra, TamBloque);
				NPalabraBloque = Sobrante( NPalabra, TamBloque);
				NConjunto = NBloque % TamConjunto;
				NPalabraConjunto = Vias*TamBloque; 
				NBloqueConjunto = NPalabraConjunto/TamBloque;
			 			 			
			}
		
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los datos introducidos no son válidos para la simulación.\nProbablemente el número de vías por conjunto sea muy grande");
				OnConfigurarPolticas();
				//OnSimular();
				return; 
			}
			
			END_CATCH


			

			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			
			
			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			

			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			m_TamConjunto = TamConjunto;
			m_PalabraConjunto = NPalabraConjunto;
			m_nBloqueConjunto = NBloqueConjunto;
			m_NConjunto = NConjunto;
			

			/*
			Dato seleccionado Aleatoriamente ...."<<Dato;
			El dato corresponde a la palabra : "<<NPalabra;
			El numero de Bloque en MP correspondiente es : "<<NBloque;
			El numero de Palabra en Bloque es : "<<NPalabraBloque;
			El numero de Lineas en Cache es : "<<TamLinea;
			El numero de Conjuntos en Cache son : "<<TamConjunto;
			El numero de Palabras por conjunto es : "<<Vias*TamBloque;
			El numero de Conjunto correspondiente a Cache es : "<<NConjunto;
			
    		*/
			
			//Identificación del Bloque en Memoria Principal
			
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);

					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					//Colorea las celdas del dato
				   
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				    ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				    ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF); 
				   
				   	PosicionDatoMP = i;
				   }

				}
			}
		
			
			
			//Separación del Bloque encontrado en Memoria Principal
						
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];


			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);
					j++; 
				}
			}
	
			//Separación del Bloque encontrado en Memoria Cache
			
			//Creación de Arreglo temporal para colocar el bloque encontrado en MC
			int *arrayDirBloqueMC = new int[ TamBloque ];
			int *arrayDatBloqueMC = new int[ TamBloque ];
			int *arrayTipoBloqueMC = new int[ TamBloque ];
			
	        
			
			
			//Verificando Acierto o Fallo en Cache

			for( i = 0; i<TamMC; i++)
			{
				if(Dir == *(arrayDirMCPtr + i))
				{
					//Identificación del Bloque en Memoria Cache
					int NBloqueMC = Truncar(i, TamBloque);
						 //Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);

							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
					
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
				   			ColorearMC( celda, 2, 0x0000FF00, 0x00000000);
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000);

						
						}
					}
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					
                    NVia = (i/TamBloque) % Vias; 
					contAciertos++;
					m_NLinea = NBloqueMC;
					
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!!\nNo se encontró la Palabra");
					contFallos++;  
		  
							
				  
			//Llenado en orden de bloques en Memoria Cache cuando está vacía
						
			NLinea = NConjunto*Vias;
					
	if( *(arrayDatosMCPtr + NLinea*TamBloque) == '\0')
	{
					
				Limite = NLinea*TamBloque;
				NVia = 0;
					
					for(j=0; j<TamMC; j++)
					{		 		  
						for(i=0; i<TamBloque; i++)
						{
							if(j == Limite) 
							{
								celda = j + 1;
								*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
								*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
								*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
								j++;
								Limite++;
								ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
								ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							}
						} 
	      													
					}
					
					m_NLinea = NLinea;
					
					Contador( contLineas, TamLinea, NLinea, 3);
	
	}//Fin del if
	else
	{
			
				//Contador de Lineas en Cache
				
				Limite2 = (NLinea*TamBloque + Vias*TamBloque); 
				
				for(i= 0; i<Limite2; i++)
				{
										
					if(*(arrayDatosMCPtr + i) != '\0')
					{
                       contLinea = Truncar(i, TamBloque);
					   contLinea++;
					   
					}
				}

				//Verificando si la MC esta llena
				contMC =0;

				for(i=0; i<TamMC; i++)
				{
					if(*(arrayDatosMCPtr + i) != '\0')
					{
						contMC++;
					}
				}
				
								
				
				 

				if((contMC != TamMC) && ( Limite2 > contLinea*TamBloque + 1))
				{
					
					//Proceso de LLenado de Cache...";

					NLinea = contLinea;
					NVia = contLinea;
                    contLinea = 0;
					
					
					NVia = NLinea  % Vias;
					
							   
                    
				    
				}
				//Caso en que se aplican métodos de reemplazamiento
				else
				{
					//Proceso Aleatorio...
					
					srand(time(0));
					NVia = rand() % Vias;
				    
					NLinea = NVia + NConjunto*Vias;
					
													
				
				}

				Contador( contLineas, TamLinea, NLinea, 3);
				
				//Gestion Post_Escritura

				for( k =0; k<TamLinea; k++)
				{
					if( (*(contLineas + k) != 0) && (*(contLineas + k) != 1) )
					{

					

			
							for( i= 0; i<TamMC; i++)
							{
								
								if( *(arrayDirMCPtr + i) == *(arrayDirMCPtr + NLinea*TamBloque))
								{
									NBloqueMC = Truncar(i, TamBloque);
									
			
									for(j = 0; j<TamBloque; j++)
									{
										if( NBloqueMC == Truncar(i, TamBloque))
										{
											*(arrayDirBloqueMC + j ) = *(arrayDirMCPtr + i);
											*(arrayDatBloqueMC + j ) = *(arrayDatosMCPtr + i);
											*(arrayTipoBloqueMC + j) = *(arrayTipoMCPtr + i);
						 					i++;
											
							
					  					}
									}
								}
						}
			
		
		
						//Introduccion de Bloques en MP
  											
						//Identifica y deposita el Bloque en MP 
						if( Acierto == 0) 	
						{	
								i=0;
							for(j=0; j<TamMP; j++)
							{	
					

									if(*(arrayDirMPPtr + j) == *(arrayDirBloqueMC + i))
									{
										
											celda = 0;
											celda = j + 1;
														
											*(arrayDirMPPtr + j) =  *(arrayDirBloqueMC + i);
											*(arrayDatosMPPtr + j) = *(arrayDatBloqueMC + i);
											*(arrayTipoMPPtr + j) = *(arrayTipoBloqueMC + i);
							
											i++;			 

											ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
											ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
											ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
																				
									}
					
							}
			
						}	
		

		
				
		
					}//fin primer if
				}//fin for



				//Introduccion Bloques en MC
				
				
				Limite = NLinea*TamBloque;
						
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite) 
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      													
				}
				m_NLinea = NLinea;
				
	}//Fin del else
								
		
		
			
			           			
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);

    
				
			//AgregarPar();
					
			
Salir:
								
			//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;
						
						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

			
			m_nLineaConjunto = NVia;
			
				

				
				//Impresión de contenido de arreglo de Memoria Cache			 
		
		
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}

				

				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);


		

		ImprimeFormatoSim_Conj(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea, NConjunto, NVia);
		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;
		delete arrayDirBloqueMC;
		delete arrayDatBloqueMC;
		delete arrayTipoBloqueMC;
	
	

}

//Función AC_FIFO_Post
//Función que realiza la sustitución aleatorio de Memoria Cache 
//por Método Asociativo por Conjuntos y política de post_escritura 

void CCache2003View::AC_FIFO_Post(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, CString sVias, int *arrayDirSecMPPtr)
{
int NPalabra, NBloque, NLinea, NPalabraBloque, NConjunto, NVia, NPalabraConjunto, NBloqueConjunto;
int nLinea, nMP, nMC, nBloque, nConjunto, TamLinea, TamConjunto;
int Dir, Dato, DatoEscrito, Tipo, Limite, i, j, k; 
int celda, Vias; 
int posMayor = 0;
int posMenor = 0;
int Acierto;
int PosicionDatoMP;
int NBloqueMC;

Vias = atoi(sVias);

int contMC = 0;
int contLinea = 0;
int Limite2;


int NLineaInferior = 0;
int NLineaSuperior = 0;  



NLinea = Ini_Linea;  
PosicionDatoMP = 0;
Acierto = 0;

GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);



CDireccionDlg dlgDireccion;

nMP = dlgDireccion.ConvertBase2(TamMP);
nMC = dlgDireccion.ConvertBase2(TamMC);
nBloque = dlgDireccion.ConvertBase2(TamBloque);
nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);   
nConjunto = dlgDireccion.ConvertBase2(Vias);
			

TamLinea = (int)pow(2, nLinea);
TamConjunto = TamMC/(TamBloque*Vias);
	

	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
		
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - 10;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}


			
			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			
			 //Control de Excepción de números fraccionarios
			
			TRY
			{
				
				if(TamBloque*Vias > TamMC )
				{
					AfxThrowUserException();
				}

				TamLinea = (int)pow(2, nLinea);
				TamConjunto = TamMC/(TamBloque*Vias);
				
				NBloque = Truncar( NPalabra, TamBloque);
				NPalabraBloque = Sobrante( NPalabra, TamBloque);
				NConjunto = NBloque % TamConjunto;
				NPalabraConjunto = Vias*TamBloque; 
				NBloqueConjunto = NPalabraConjunto/TamBloque;
			 			 			
			}
		
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los datos introducidos no son válidos para la simulación.\nProbablemente el número de vías por conjunto sea muy grande");
				OnConfigurarPolticas();
				//OnSimular();
				return; 
			}
			
			END_CATCH


						
 			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			
			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			
				
		
			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			m_TamConjunto = TamConjunto;
			m_PalabraConjunto = NPalabraConjunto;
			m_nBloqueConjunto = NBloqueConjunto;
			m_NConjunto = NConjunto;
						
			/*
			Dato seleccionado Aleatoriamente ...."<<Dato;
			El dato corresponde a la palabra : "<<NPalabra;
			El numero de Bloque en MP correspondiente es : "<<NBloque;
			El numero de Palabra en Bloque es : "<<NPalabraBloque;
			El numero de Lineas en Cache es : "<<TamLinea;
			El numero de Conjuntos en Cache son : "<<TamConjunto;
			El numero de Palabras por conjunto es : "<<Vias*TamBloque;
			El numero de Conjunto correspondiente a Cache es : "<<NConjunto;
			
    	  */

	//Identificación del Bloque en Memoria Principal
	
	for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);

					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
				
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF); 
				   
				   PosicionDatoMP = i;
				   }

				}
			}
		
			
	
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];
			
			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);

					j++; 
				}
			}
	
			
			//Separación del Bloque encontrado en Memoria Cache
			
			//Creación de Arreglo temporal para colocar el bloque encontrado en MC
			int *arrayDirBloqueMC = new int[ TamBloque ];
			int *arrayDatBloqueMC = new int[ TamBloque ];
			int *arrayTipoBloqueMC = new int[ TamBloque ];
			
	        
			//Verificando Acierto o Fallo en Cache

			for( i = 0; i<TamMC; i++)
			{
				
				int NBloqueMC = Truncar(i, TamBloque);

				if(Dir == *(arrayDirMCPtr + i))
				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					                    
					NLinea = (i/TamBloque);
					m_NLinea = NLinea;
					
					NVia = NLinea % Vias; 
					
					
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);

							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
				
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
							ColorearMC( celda, 2, 0x0000FF00, 0x00000000); 
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000);
						}
					}



					NLineaInferior = NConjunto*Vias;
					NLineaSuperior = Vias + NConjunto*Vias;
                    
                					
					ImprimeContadores( contLineas, TamLinea, 3);

					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!!\nNo se encontro la Palabra");
					contFallos++;  
		  
		
			

			//Llenado en orden de bloques en Memoria Cache cuando está vacía
			
					
			NLineaInferior = NConjunto*Vias;
			NLineaSuperior = Vias + NConjunto*Vias;
            	
			
			NLinea = NLineaInferior;
					
	if( *(arrayDatosMCPtr + NLinea*TamBloque) == '\0')
	{
			     
					 int Menor = *(contLineas + NLinea);
					 
					 for(i= NLineaInferior; i<NLineaSuperior; i++)
					 {
					   if( *(contLineas + i)< Menor )
					   {
						   Menor = *(contLineas + i);
						   NLinea = i;
					   }
					 }

					
					 ++*(contLineas + NLinea);
					 ImprimeContadores(contLineas, TamLinea, 3);

				 
								
				Limite = NLinea*TamBloque;
					
				NVia = 0;
				
					for(j=0; j<TamMC; j++)
					{		 		  
						for(i=0; i<TamBloque; i++)
						{
							if(j == Limite) 
							{
								celda = j + 1;
								*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
								*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
								*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
								j++;
								Limite++;
								ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							 }
						} 
	      													
					}
					
					m_NLinea = NLinea;
					
					
	}
						
	else
	{
			
				//Contador de Lineas en Cache
				
				
				Limite2 = (NLinea*TamBloque + Vias*TamBloque); 
				
				for(i= 0; i<Limite2; i++)
				{
										
					if(*(arrayDatosMCPtr + i) != '\0')
					{
                       contLinea = Truncar(i, TamBloque);
					   contLinea++;
					   		   
					  
					}
				}

				//Verificando si la MC esta llena
				contMC =0;

				for(i=0; i<TamMC; i++)
				{
					if(*(arrayDatosMCPtr + i) != '\0')
					{
						contMC++;
					}
				}
				
								
								 

					if((contMC != TamMC) && ( Limite2 > contLinea*TamBloque + 1) && (*(arrayDatosMCPtr + NLineaSuperior*TamBloque-1) == '\0'))
					{
					
						//Proceso de LLenado de Cache...\n\n";

						NLinea = contLinea;
						NVia = contLinea;
						contLinea = 0;
					
						NVia = NLinea  % Vias;
					
					    NLinea = NVia + NConjunto*Vias;
					   
					    ++*(contLineas + NLinea);
                        ImprimeContadores(contLineas, TamLinea, 3);
					
					}
						
				
				//Caso en que se aplican métodos de reemplazamiento
				else
				{
					//Proceso LFU...\n\n";
										
					int Mayor =0;
										
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
						if( *(contLineas + i) > Mayor)
						{
							Mayor = *(contLineas + i);
							posMayor = i;
							
						}

					}

					int Menor = *(contLineas + posMayor);
										
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
						if( *(contLineas + i) < Menor)
						{
							Menor = *(contLineas + i);
							posMenor = i;
							NLinea = posMenor;
							
						}

					}

										
					++*(contLineas + NLinea);
					ImprimeContadores( contLineas, TamLinea, 3);

					
					
					NVia = NLinea % Vias;
					
													
				
				}

				//Gestion Post_Escritura
				for( k =0; k<TamLinea; k++)
				{
					if( (*(contLineas + k) != 0) && (*(contLineas + k) != 1) )
					{

						for( i= 0; i<TamMC; i++)
						{
							
							if( *(arrayDirMCPtr + i) == *(arrayDirMCPtr + NLinea*TamBloque))
							{
								NBloqueMC = Truncar(i, TamBloque);
								
								for(j = 0; j<TamBloque; j++)
								{
									if( NBloqueMC == Truncar(i, TamBloque))
									{
										*(arrayDirBloqueMC + j ) = *(arrayDirMCPtr + i);
										*(arrayDatBloqueMC + j ) = *(arrayDatosMCPtr + i);
										*(arrayTipoBloqueMC + j) = *(arrayTipoMCPtr + i);
						 				i++;
										
							
					  				}
								}
							}
						}
			
		
		
						//Introduccion de Bloques en MP
  											
						//Identifica y deposita el Bloque en MP 
						if( Acierto == 0) 	
						{	
							i=0;
							for(j=0; j<TamMP; j++)
							{	
					

									if(*(arrayDirMPPtr + j) == *(arrayDirBloqueMC + i))
									{
										
										celda = 0;
										celda = j + 1;
														
										*(arrayDirMPPtr + j) =  *(arrayDirBloqueMC + i);
										*(arrayDatosMPPtr + j) = *(arrayDatBloqueMC + i);
										*(arrayTipoMPPtr + j) = *(arrayTipoBloqueMC + i);
							
										i++;			 

										ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
										ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
										ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
																				
									}
					
								}
			
							}	
		

		
				
		
					}//primer if
				}//for

	  




				
				//Introduce bloques a Cache
				
				Limite = NLinea*TamBloque;
						
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite) 
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      													
				}
				m_NLinea = NLinea;
				UpdateData(false);
	}
								
							
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);



	//AgregarPar();
			
Salir:
								
				//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;

						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

				m_nLineaConjunto = NVia;
				
				
				
				
				if(w< TamLinea - 1)
				{
					w++;
				}
				else
				{
					w = TamLinea - 1;
				}
				
				//Impresión de contenido de arreglo de Memoria Cache			 
				
				
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}


				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);


		

		ImprimeFormatoSim_Conj(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea, NConjunto, NVia);

		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;
		delete arrayDirBloqueMC;
		delete arrayDatBloqueMC;
		delete arrayTipoBloqueMC;

		//Informe( contAciertos, contFallos, k);


}


//Función AC_LFU_Post
//Función que realiza la sustitución aleatorio de Memoria Cache 
//por Método Asociativo por Conjuntos con política de post-escritura 

void CCache2003View::AC_LFU_Post(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contFrec, CString sVias, int *arrayDirSecMPPtr)
{
int NPalabra, NBloque, NLinea, NPalabraBloque, NConjunto, NVia, NPalabraConjunto, NBloqueConjunto;
int nLinea, nMP, nMC, nBloque, nConjunto, TamLinea, TamConjunto;
int Dir, Dato, DatoEscrito, Tipo, Limite, i, j, k; 
int celda, Vias; 
int posMayor = 0;
int posMenor = 0;
int Acierto;
int PosicionDatoMP;
int NBloqueMC;

Vias = atoi(sVias);

int contMC = 0;
int contLinea = 0;
int Limite2;

int NLineaInferior = 0;
int NLineaSuperior = 0;  


NLinea = Ini_Linea;  
Acierto = 0;
PosicionDatoMP = 0;

GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_FREC) -> EnableWindow(TRUE);	        

CDireccionDlg dlgDireccion;

nMP = dlgDireccion.ConvertBase2(TamMP);
nMC = dlgDireccion.ConvertBase2(TamMC);
nBloque = dlgDireccion.ConvertBase2(TamBloque);
nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);   
nConjunto = dlgDireccion.ConvertBase2(Vias);
			

TamLinea = (int)pow(2, nLinea);
TamConjunto = TamMC/(TamBloque*Vias);
	

	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	

			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - 10;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}


			
			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			
			//Control de Excepción de números fraccionarios
			
			TRY
			{
				
				if(TamBloque*Vias > TamMC )
				{
					AfxThrowUserException();
				}

				TamLinea = (int)pow(2, nLinea);
				TamConjunto = TamMC/(TamBloque*Vias);
				
				NBloque = Truncar( NPalabra, TamBloque);
				NPalabraBloque = Sobrante( NPalabra, TamBloque);
				NConjunto = NBloque % TamConjunto;
				NPalabraConjunto = Vias*TamBloque; 
				NBloqueConjunto = NPalabraConjunto/TamBloque;
			 			 			
			}
		
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los datos introducidos no son válidos para la simulación.\nProbablemente el número de vías por conjunto sea muy grande");
				OnConfigurarPolticas();
				//OnSimular();
				return; 
			}
			
			END_CATCH


		
			
 			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			
			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			
			

			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			m_TamConjunto = TamConjunto;
			m_PalabraConjunto = NPalabraConjunto;
			m_nBloqueConjunto = NBloqueConjunto;
			m_NConjunto = NConjunto;
			
			
			/*
			Dato seleccionado Aleatoriamente ...."<<Dato;
			El dato corresponde a la palabra : "<<NPalabra;
			El numero de Bloque en MP correspondiente es : "<<NBloque;
			El numero de Palabra en Bloque es : "<<NPalabraBloque;
			El numero de Lineas en Cache es : "<<TamLinea;
			El numero de Conjuntos en Cache son : "<<TamConjunto;
			El numero de Palabras por conjunto es : "<<Vias*TamBloque;
			El numero de Conjunto correspondiente a Cache es : "<<NConjunto;
			
    	  */

	//Identificación del Bloque en Memoria Principal
	
	for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000);
					
					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 2, 0x0000FFFF, 0x000000FF); 
				   
				   PosicionDatoMP = i;
				   }

				}
			}
		
				
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];
			
			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);

					j++; 
				}
			}
	
			//Separación del Bloque encontrado en Memoria Cache
			
			//Creación de Arreglo temporal para colocar el bloque encontrado en MC
			int *arrayDirBloqueMC = new int[ TamBloque ];
			int *arrayDatBloqueMC = new int[ TamBloque ];
			int *arrayTipoBloqueMC = new int[ TamBloque ];
			

	
			//Verificando Acierto o Fallo en Cache

			for( i = 0; i<TamMC; i++)
			{
				
				int NBloqueMC = Truncar(i, TamBloque);

				if(Dir == *(arrayDirMCPtr + i))
				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					                    
					NLinea = (i/TamBloque);
					m_NLinea = NLinea;
					
					NVia = NLinea % Vias; 
					
					
					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(NBloqueMC == Truncar(i, TamBloque))
						{
							*(arregloDirBloqueMC + i) = i;
							*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
							*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);
							//Coloreado de celdas
							celda = 0;
							celda = i + 1;
				
							ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
							ColorearMC( celda, 2, 0x0000FF00, 0x00000000);  
							ColorearMC( celda, 3, 0x0000FF00, 0x00000000); 		
							ColorearMC( celda, 5, 0x0000FF00, 0x00000000);
						}
					}



					NLineaInferior = NConjunto*Vias;
					NLineaSuperior = Vias + NConjunto*Vias;
                    
                
					for( i = NLineaInferior; i<NLineaSuperior; i++)
					{
						if( NLinea == i)
						{
							++*(contFrec + i);
						}

					}

					ImprimeContadores( contFrec, TamLinea, 5);

					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!!\nNo se encontro la Palabra");
					contFallos++;  
		  
		
			

			//Llenado en orden de bloques en Memoria Cache cuando está vacía
			
					
			NLineaInferior = NConjunto*Vias;
			NLineaSuperior = Vias + NConjunto*Vias;
            	
			
			NLinea = NLineaInferior;
					
	if( *(arrayDatosMCPtr + NLinea*TamBloque) == '\0')
	{
			    
				 Contador( contLineas, TamLinea, NLinea, 3);

				 
					 int Menor = *(contFrec + NLinea);
					 
					 for(i= NLineaInferior; i<NLineaSuperior; i++)
					 {
					   if( *(contFrec + i)< Menor )
					   {
						   Menor = *(contFrec + i);
						   NLinea = i;
					   }
					 }

					
					 ++*(contFrec + NLinea);
					 ImprimeContadores(contFrec, TamLinea, 5);

				 	
								
				Limite = NLinea*TamBloque;
					
				NVia = 0;
				
					for(j=0; j<TamMC; j++)
					{		 		  
						for(i=0; i<TamBloque; i++)
						{
							if(j == Limite) 
							{
								celda = j + 1;
								*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
								*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
								*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
								j++;
								
								Limite++;
								ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 5, 0x000000FF, 0x00FFFFFF);

							}
						} 
	      													
					}
					
					m_NLinea = NLinea;
					
					
	} //Fin del if
						
			 
			
	else
	{
			
				//Contador de Lineas en Cache
				
				
				Limite2 = (NLinea*TamBloque + Vias*TamBloque); 
				
				for(i= 0; i<Limite2; i++)
				{
										
					if(*(arrayDatosMCPtr + i) != '\0')
					{
                       contLinea = Truncar(i, TamBloque);
					   contLinea++;
					   		   
					   
					}
				}

				//Verificando si la MC esta llena
				contMC =0;

				for(i=0; i<TamMC; i++)
				{
					if(*(arrayDatosMCPtr + i) != '\0')
					{
						contMC++;
					}
				}
				
								
				
				 

					if((contMC != TamMC) && ( Limite2 > contLinea*TamBloque + 1) && (*(arrayDatosMCPtr + NLineaSuperior*TamBloque-1) == '\0'))
					{
					
						//Proceso de LLenado de Cache...\n\n";

						NLinea = contLinea;
						NVia = contLinea;
						contLinea = 0;
					
						NVia = NLinea  % Vias;
					
					    NLinea = NVia + NConjunto*Vias;
					   
					    ++*(contFrec + NLinea);
                        ImprimeContadores(contFrec, TamLinea, 5);
					
					}
						
				
				//Caso en que se aplican métodos de reemplazamiento
				else
				{
					//Proceso LFU...\n\n";
										
					int Mayor =0;
										
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
						if( *(contFrec + i) > Mayor)
						{
							Mayor = *(contFrec + i);
							posMayor = i;
							
						}

					}

					int Menor = *(contFrec + posMayor);
										
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
						if( *(contFrec + i) < Menor)
						{
							Menor = *(contFrec + i);
							posMenor = i;
							NLinea = posMenor;
							
						}

					}

										
					++*(contFrec + NLinea);
					ImprimeContadores( contFrec, TamLinea, 5);

					
					
					NVia = NLinea % Vias;
					
													
				
				}

				Contador( contLineas, TamLinea, NLinea, 3);

				 //Gestion Post_Escritura
				for( k =0; k<TamLinea; k++)
				{
					if( (*(contLineas + k) != 0) && (*(contLineas + k) != 1) )
					{

						for( i= 0; i<TamMC; i++)
						{
							
							if( *(arrayDirMCPtr + i) == *(arrayDirMCPtr + NLinea*TamBloque))
							{
								NBloqueMC = Truncar(i, TamBloque);
								
								for(j = 0; j<TamBloque; j++)
								{
									if( NBloqueMC == Truncar(i, TamBloque))
									{
										*(arrayDirBloqueMC + j ) = *(arrayDirMCPtr + i);
										*(arrayDatBloqueMC + j ) = *(arrayDatosMCPtr + i);
										*(arrayTipoBloqueMC + j) = *(arrayTipoMCPtr + i);
						 				i++;
										
							
					  				}
								}
							}
						}
			
		
		
						//Introduccion de Bloques en MP
  											
						//Identifica y deposita el Bloque en MP 
						if( Acierto == 0) 	
						{	
							i=0;
							for(j=0; j<TamMP; j++)
							{	
					

									if(*(arrayDirMPPtr + j) == *(arrayDirBloqueMC + i))
									{
										
										celda = 0;
										celda = j + 1;
														
										*(arrayDirMPPtr + j) =  *(arrayDirBloqueMC + i);
										*(arrayDatosMPPtr + j) = *(arrayDatBloqueMC + i);
										*(arrayTipoMPPtr + j) = *(arrayTipoBloqueMC + i);
							
										i++;			 

										ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
										ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
										ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
																				
									}
					
								}
			
							}	
		

		
				
		
					}//primer if
				}//for

	  

				
				
				Limite = NLinea*TamBloque;
						
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite) 
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 5, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      													
				}
				m_NLinea = NLinea;
				
			
			
			
			
	}//Fin del else	
				
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);


           			
			    
//AgregarPar();				

					
			
Salir:
								
				//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;

						
						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

			
				m_nLineaConjunto = NVia;
				
							
				
				if(w< TamLinea - 1)
				{
					w++;
				}
				else
				{
					w = TamLinea - 1;
				}
				
				//Impresión de contenido de arreglo de Memoria Cache			 
				
				
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}


				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);

		

		ImprimeFormatoSim_Conj(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea, NConjunto, NVia);
		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;
		delete arrayDirBloqueMC;
		delete arrayDatBloqueMC;
		delete arrayTipoBloqueMC;

		
		

}

//Función AC_LRU_Post
//Función que realiza la sustitución aleatorio de Memoria Cache 
//por Método Asociativo por Conjuntos con política de post-escritura

void CCache2003View::AC_LRU_Post(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contEdad, CString sVias, int *arrayDirSecMPPtr)
{
int NPalabra, NBloque, NLinea, NPalabraBloque, NConjunto, NVia, NPalabraConjunto, NBloqueConjunto;
int nLinea, nMP, nMC, nBloque, nConjunto, TamLinea, TamConjunto;
int Dir, Dato, DatoEscrito, Tipo, Limite, i, j, k; 

int contMC = 0;
int contLinea = 0;
int Limite2;
int Vias, celda;
int NLineaInferior = 0;
int NLineaSuperior = 0;  
int Acierto;
int PosicionDatoMP;
int NBloqueMC;

CDireccionDlg dlgDireccion;

Vias = atoi(sVias);
	  
NLinea = Ini_Linea;
Acierto = 0;
PosicionDatoMP = 0;

GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(TRUE);
GetDlgItem(IDC_CHECK_EDAD) -> EnableWindow(TRUE);


nMP = dlgDireccion.ConvertBase2(TamMP);
nMC = dlgDireccion.ConvertBase2(TamMC);
nBloque = dlgDireccion.ConvertBase2(TamBloque);
nLinea = dlgDireccion.ConvertBase2(TamMC) - dlgDireccion.ConvertBase2( TamBloque);   
nConjunto = dlgDireccion.ConvertBase2(Vias);
			

TamLinea = (int)pow(2, nLinea);
TamConjunto = TamMC/(TamBloque*Vias);
	


  	if(m_iAutomatico_Sec == 1)
	{
		NPalabra = *(arrayDirSecMPPtr + nSim);
	
	}	
	else
	{	
		srand( time( 0 ));
		NPalabra = rand() % TamMP;
	}	



			Dato = *(arrayDatosMPPtr + NPalabra); 
			Dir = *(arrayDirMPPtr + NPalabra);
			Tipo = *(arrayTipoMPPtr + NPalabra);
	
					
			//Genera Dato que se va a escribir en MC
			if( Tipo == 2 )
			{
				DatoEscrito = Dato - rangoEscritura;
				if( DatoEscrito < 0 )
				{
					DatoEscrito = Dato + rangoEscritura;
				}
				m_iTipo_Dato = 2;
				m_sTipo = "Esc";
				UpdateData(false);
			}
			else
			{
				DatoEscrito = Dato;
				m_iTipo_Dato = 1;
				m_sTipo = "Lec";
				UpdateData(false);
			}


			
			//Conversion de datos Enteros a Cadenas
			char bufferDato[5];
			char bufferDatoEscrito[5];
			CString s_Dato;
			CString s_DatoEscrito;
			s_Dato = _itoa( Dato  , bufferDato, 10);
			s_DatoEscrito = _itoa( DatoEscrito  , bufferDatoEscrito, 10);
			m_Dato_Escrito = DatoEscrito;
			
			//Control de Excepción de números fraccionarios
			
			TRY
			{
				
				if(TamBloque*Vias > TamMC )
				{
					AfxThrowUserException();
				}

				TamLinea = (int)pow(2, nLinea);
				TamConjunto = TamMC/(TamBloque*Vias);
				
				NBloque = Truncar( NPalabra, TamBloque);
				NPalabraBloque = Sobrante( NPalabra, TamBloque);
				NConjunto = NBloque % TamConjunto;
				NPalabraConjunto = Vias*TamBloque; 
				NBloqueConjunto = NPalabraConjunto/TamBloque;
			 			 			
			}
		
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los datos introducidos no son válidos para la simulación.\nProbablemente el número de vías por conjunto sea muy grande");
				OnConfigurarPolticas();
				//OnSimular();
				return; 
			}
			
			END_CATCH


			 	
			
			
			
			ActualizarDatosDir(nMP, Dato, DatoEscrito, Dir, m_sTipo);
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.OnChangeEditDireccion();
			m_dlgDireccion.UpdateData(false);
			
			
			
			//Arreglo temporal para buscar direcciones correspondientes al bloque
			int *arregloDirBloque = new int[ TamMP ];
			//Arreglo temporal para buscar datos correspondientes al bloque
			int *arregloDatBloque = new int[ TamMP ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MP
			int *arregloTipoBloque = new int[ TamMP ];

			//Arreglo temporal para buscar direcciones correspondientes al bloque en MC
			int *arregloDirBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar datos correspondientes al bloque	en MC
			int *arregloDatBloqueMC = new int[ TamMC ];
			//Arreglo temporal para buscar tipo de datos correspondientes al bloque	en MC
			int *arregloTipoBloqueMC = new int[ TamMC ];

			
			for(i=0; i<TamMP; i++)
			{
				*(arregloDirBloque + i) = '\0';
				*(arregloDatBloque + i)= '\0';
				*(arregloTipoBloque + i)= '\0';
			
			}

			
			for(i=0; i<TamMC; i++)
			{
				*(arregloDirBloqueMC + i) = '\0';
				*(arregloDatBloqueMC + i)= '\0';
				*(arregloTipoBloqueMC + i)= '\0';
			}

			
			m_Dato = Dato;
			m_NPalabra =NPalabra;
			m_NBloque = NBloque;
			m_NPalabraBloque = NPalabraBloque;
			m_TamConjunto = TamConjunto;
			m_PalabraConjunto = NPalabraConjunto;
			m_nBloqueConjunto = NBloqueConjunto;
			m_NConjunto = NConjunto;
			
		  /*
			Dato seleccionado Aleatoriamente ...."<<Dato;
			El dato corresponde a la palabra : "<<NPalabra;
			El numero de Bloque en MP correspondiente es : "<<NBloque;
			El numero de Palabra en Bloque es : "<<NPalabraBloque;
			El numero de Lineas en Cache es : "<<TamLinea;
			El numero de Conjuntos en Cache son : "<<TamConjunto;
			El numero de Palabras por conjunto es : "<<Vias*TamBloque;
			El numero de Conjunto correspondiente a Cache es : "<<NConjunto;
			
    		*/
			
			//Identificación del Bloque en Memoria Principal
			for( i = 0; i<TamMP; i++)
			{
				if(NBloque == Truncar(i, TamBloque))
				{
					*(arregloDirBloque + i) = i;
					*(arregloDatBloque + i) = *(arrayDatosMPPtr + i);
					*(arregloTipoBloque + i) = *(arrayTipoMPPtr + i);
					
					//Coloreado de celdas
					celda = 0;
					celda = i +1;
					
					ColorearMP( celda, 0, 0x0000FFFF, 0x00000000);  
					ColorearMP( celda, 1, 0x0000FFFF, 0x00000000); 				    
				   	ColorearMP( celda, 2, 0x0000FFFF, 0x00000000); 		

					//Colorea las celdas del dato
				   if(Dir == *(arrayDirMPPtr + i))
				   {
				   ColorearMP( celda, 0, 0x0000FFFF, 0x000000FF);  
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);   
				   ColorearMP( celda, 1, 0x0000FFFF, 0x000000FF);
				   
				   PosicionDatoMP = i;
				   
				   }

				}
			}
		
			
			//Separación del Bloque encontrado en Memoria Principal
	
			//Creación de Arreglo temporal para colocar el bloque encontrado
	
			int *arrayDirBloque = new int[ TamBloque ];
			int *arrayDatBloque = new int[ TamBloque ];
			int *arrayTipoBloque = new int[ TamBloque ];

			j = 0;
			for( i= 0; i<TamMP; i++)
			{
				if( NBloque == Truncar(i, TamBloque))
				{
					*(arrayDirBloque + j ) = *(arregloDirBloque + i);
					*(arrayDatBloque + j ) = *(arregloDatBloque + i);
					*(arrayTipoBloque + j ) = *(arregloTipoBloque + i);
					j++; 
				}
			}
	
				
			//Separación del Bloque encontrado en Memoria Cache
			
			//Creación de Arreglo temporal para colocar el bloque encontrado en MC
			int *arrayDirBloqueMC = new int[ TamBloque ];
			int *arrayDatBloqueMC = new int[ TamBloque ];
			int *arrayTipoBloqueMC = new int[ TamBloque ];
			
		
			//Verificando Acierto o Fallo en Cache

			for( i = 0; i<TamMC; i++)
			{
				if(Dir == *(arrayDirMCPtr + i))	 

				{
					MessageBox("A C I E R T O!!!\nSe encontró la Palabra");
					
                   
					int NLineaAcierto;
					NLineaAcierto = i/TamBloque;
					m_NLinea = NLineaAcierto;
					
					NVia = NLineaAcierto % Vias;
					

					//Colorea Acierto
					for( i = 0; i<TamMC; i++)
					{

						if(Dir == *(arrayDirMCPtr + i))
						{
							//Identificación del Bloque en Memoria Cache
							int NBloqueMC = Truncar(i, TamBloque);
							 //Colorea Acierto
							for( i = 0; i<TamMC; i++)
							{

								if(NBloqueMC == Truncar(i, TamBloque))
								{
									*(arregloDirBloqueMC + i) = i;
									*(arregloDatBloqueMC + i) = *(arrayDatosMCPtr + i);
									*(arregloTipoBloqueMC + i) = *(arrayTipoMCPtr + i);
									//Coloreado de celdas
									celda = 0;
									celda = i + 1;
					
									ColorearMC( celda, 0, 0x0000FF00, 0x00000000);  
									ColorearMC( celda, 1, 0x0000FF00, 0x00000000); 				    
				   					ColorearMC( celda, 2, 0x0000FF00, 0x00000000);  
									ColorearMC( celda, 3, 0x0000FF00, 0x00000000);
									ColorearMC( celda, 4, 0x0000FF00, 0x00000000);

								}
							}
						}
					
					}
					

					NLineaInferior = NConjunto*Vias;
					NLineaSuperior = Vias + NConjunto*Vias;

										
					              
					int contActual;

					for( j = NLineaInferior; j<NLineaSuperior; j++)
					{
						if( NLineaAcierto == j)
						{
							contActual = *(contEdad + j);
						}
					}

					for( j = NLineaInferior; j<NLineaSuperior; j++)
					{
						if(*(contEdad + j) < contActual )
						{
							++*(contEdad + j);
						}

						if( NLineaAcierto == j)
						{
							*(contEdad + j)= 0;
						}
					}

					ImprimeContadores( contEdad, TamLinea, 4);

					w--;
					contAciertos++;
					Acierto++;
					goto Salir;
				}
	          
			}	  
					MessageBox("F A L L O!!!\nNo se encontró la Palabra");
					contFallos++;  
		  
		
			
			//Llenado en orden de bloques en Memoria Cache cuando está vacía
			
					
			NLineaInferior = NConjunto*Vias;
			NLineaSuperior = Vias + NConjunto*Vias;


			NLinea = NLineaInferior;
					
	if( *(arrayDatosMCPtr + NLinea*TamBloque) == '\0')
	{
				 Contador( contLineas, TamLinea, NLinea, 3);

				 
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
					   if( i == NLinea)
					   {
						   *(contEdad + NLinea) = 0;
					   }
					   else
					   {
						   ++*(contEdad + i);
					   }
					}

					ImprimeContadores(contEdad, TamLinea, 4);

				 	
								
				Limite = NLinea*TamBloque;
					
				NVia = 0;
				
					for(j=0; j<TamMC; j++)
					{		 		  
						for(i=0; i<TamBloque; i++)
						{
							if(j == Limite) 
							{
								celda = j + 1;
								*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
								*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
								*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
								j++;
								Limite++;
								ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							    ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
								ColorearMC( celda, 4, 0x000000FF, 0x00FFFFFF);
							}
						} 
	      													
					}
					
					m_NLinea = NLinea;
					
					
	}//fin del if
						
			 
	//Si no está vacía
	else
	{
			
				//Contador de Lineas en Cache
				
				
				Limite2 = (NLinea*TamBloque + Vias*TamBloque); 
				
				for(i= 0; i<Limite2; i++)
				{
										
					if(*(arrayDatosMCPtr + i) != '\0')
					{
                       contLinea = Truncar(i, TamBloque);
					   contLinea++;
					   		   
					 }
				}

				//Verificando si la MC esta llena
				contMC =0;

				for(i=0; i<TamMC; i++)
				{
					if(*(arrayDatosMCPtr + i) != '\0')
					{
						contMC++;
					}
				}
				
								
			 

					if((contMC != TamMC) && ( Limite2 > contLinea*TamBloque + 1) && (*(arrayDatosMCPtr + NLineaSuperior*TamBloque-1) == '\0'))
					{
					
						//Proceso de LLenado de Cache...\n\n";

						NLinea = contLinea;
						NVia = contLinea;
						contLinea = 0;
					
						NVia = NLinea  % Vias;

						NLineaInferior = NConjunto*Vias;
						NLineaSuperior = Vias + NConjunto*Vias;
								
					
					
						for(i= NLineaInferior; i<NLineaSuperior; i++)
						{
						   if( i == NLinea)
						   {
							   *(contEdad + NLinea) = 0;
						   }
						   else
						   {
							   ++*(contEdad + i);
						   }
						}

						ImprimeContadores(contEdad, TamLinea, 4);

					
					
						
				    
				}
				//Caso en que se aplican métodos de reemplazamiento
				else
				{
					//Proceso LRU...\n\n";
										
					for(i= NLineaInferior; i<NLineaSuperior; i++)
					{
						if( *(contEdad + i) == (Vias - 1))
						{
							NLinea = i;
							
						}

					}

					ImprimeContadores( contEdad, TamLinea, 4);

					
					
					NVia = NLinea % Vias;
					
													
				
				}
				
				Contador( contLineas, TamLinea, NLinea, 3);

				
				 //Gestion Post_Escritura
				for( k =0; k<TamLinea; k++)
				{
					if( (*(contLineas + k) != 0) && (*(contLineas + k) != 1) )
					{

						for( i= 0; i<TamMC; i++)
						{
							
							if( *(arrayDirMCPtr + i) == *(arrayDirMCPtr + NLinea*TamBloque))
							{
								NBloqueMC = Truncar(i, TamBloque);
								
								for(j = 0; j<TamBloque; j++)
								{
									if( NBloqueMC == Truncar(i, TamBloque))
									{
										*(arrayDirBloqueMC + j ) = *(arrayDirMCPtr + i);
										*(arrayDatBloqueMC + j ) = *(arrayDatosMCPtr + i);
										*(arrayTipoBloqueMC + j) = *(arrayTipoMCPtr + i);
						 				i++;
										
					  				}
								}
							}
						}
			
		
		
						//Introduccion de Bloques en MP
  											
						//Identifica y deposita el Bloque en MP 
						if( Acierto == 0) 	
						{	
							i=0;
							for(j=0; j<TamMP; j++)
							{	
					

									if(*(arrayDirMPPtr + j) == *(arrayDirBloqueMC + i))
									{
										
										celda = 0;
										celda = j + 1;
														
										*(arrayDirMPPtr + j) =  *(arrayDirBloqueMC + i);
										*(arrayDatosMPPtr + j) = *(arrayDatBloqueMC + i);
										*(arrayTipoMPPtr + j) = *(arrayTipoBloqueMC + i);
							
										i++;			 

										ColorearMP( celda, 0, 0x00FF0000, 0x00FFFFFF); 
										ColorearMP( celda, 1, 0x00FF0000, 0x00FFFFFF); 
										ColorearMP( celda, 2, 0x00FF0000, 0x00FFFFFF);
																				
									}
					
								}
			
							}	
		

		
				
		
					}//primer if
				}//for

				//Introduce bloques a MC

				Limite = NLinea*TamBloque;
						
				for(j=0; j<TamMC; j++)
				{		 		  
					for(i=0; i<TamBloque; i++)
					{
						if(j == Limite) 
						{
							celda = j + 1;
							*(arrayDirMCPtr + j) =  *(arrayDirBloque + i);
							*(arrayDatosMCPtr + j) = *(arrayDatBloque + i);
							*(arrayTipoMCPtr + j) = *(arrayTipoBloque + i);
							j++;
							Limite++;
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFFFF); 
							ColorearMC( celda, 3, 0x000000FF, 0x00FFFFFF);
							ColorearMC( celda, 4, 0x000000FF, 0x00FFFFFF);

						}
					} 
	      													
				}
				m_NLinea =NLinea;
				
	}//fin del else
								
					
			ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
			ImprimeFormatoMP(nMP, TamMP, arrayDirMPPtr, arrayDatosMPPtr, arrayTipoMPPtr);



AgregarPar();						
			
Salir:
				//Colorea la celda del dato seleccionado en Cache
				for( i = 0; i<TamMC; i++)
				{
					celda = i + 1;
					if(Dir == *(arrayDirMCPtr + i))
					{
						
						//Introduce el dato escrito en cache
						*(arrayDatosMCPtr + i) = DatoEscrito;

						if( Acierto == 0)
						{
							ColorearMC( celda, 0, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 1, 0x000000FF, 0x00FFFF00);  
							ColorearMC( celda, 2, 0x000000FF, 0x00FFFF00);  
						}
						else
						{
							ColorearMC( celda, 0, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 1, 0x0000FF00, 0x000000FF);  
							ColorearMC( celda, 2, 0x0000FF00, 0x000000FF);
					
						}
					}
				}

			
				
				m_nLineaConjunto = NVia;
				
				
				 
				if(w< TamLinea - 1)
				{
					w++;
				}
				else
				{
					w = TamLinea - 1;
				}
				
				//Impresión de contenido de arreglo de Memoria Cache			 
				
				
				ImprimeFormatoMC(nMP, TamMC, arrayDirMCPtr, arrayDatosMCPtr, arrayTipoMCPtr);
		
				if(m_iAutomatico_Sec == 1)
				{
					if( nSim == (m_inSec - 1))
					{
						AfxMessageBox("El número de simulaciones programadas ha llegado al límite.\nEl programa realizará la secuencia programada desde el principio nuevamente.\nOprima ACEPTAR para continuar.", MB_OK | MB_ICONINFORMATION);
						m_nSim = 0;
						m_contAciertos = 0;
						m_contFallos = 0;
						m_iw = 0;
						m_ini_Linea = -1;
						UpdateData(false);
						LimpiarRejilla_MC();
						for(int i = 1; i<=m_TamMP; i++)
						{
							ColorearMP( i, 0, 0x00CCCCCC, 0x00FF0000); 
							ColorearMP( i, 1, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 2, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 3, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 4, 0x00FFFFFF, 0x00FF0000);
							ColorearMP( i, 5, 0x00FFFFFF, 0x00FF0000);
						}

					}	
					else
					{
						 nSim++;
					
						m_contAciertos = contAciertos;
						m_contFallos = contFallos;
						m_nSim = nSim;
						m_iw = w;
						m_NLinea = NLinea;
						m_ini_Linea	= NLinea;
						UpdateData(false);
					}
				}
				else
				{
					nSim++;
					
					m_contAciertos = contAciertos;
					m_contFallos = contFallos;
					m_nSim = nSim;
					m_iw = w;
					m_NLinea = NLinea;
					m_ini_Linea	= NLinea;
					UpdateData(false);

					 
				}


				ActualizarDatosChart(contAciertos, contFallos, nSim);
				m_dlgEstadisticas.UpdateData(true);
				m_dlgEstadisticas.OnChangeEditAciertos();
				m_dlgEstadisticas.OnChangeEditFallos();
				m_dlgEstadisticas.OnChangeEditSimulaciones();
				m_dlgEstadisticas.UpdateData(false);

		

		ImprimeFormatoSim_Conj(nMP, Dato, DatoEscrito, NPalabra, NBloque, NPalabraBloque, NLinea, NConjunto, NVia);
		
		delete arrayDirBloque;
		delete arrayDatBloque;
		delete arrayTipoBloque;
		delete arregloDirBloque;
		delete arregloDatBloque;
		delete arregloTipoBloque;
		delete arregloDirBloqueMC;
		delete arregloDatBloqueMC;
		delete arregloTipoBloqueMC;
		delete arrayDirBloqueMC;
		delete arrayDatBloqueMC;
		delete arrayTipoBloqueMC;

		
		
}

void CCache2003View::ActualizarDatosDir(int n, int dato, int dato_esc, int dir, CString tipo)
{
	
			
	CString s_dato;
	CString s_dato_esc;
	CString s_dir;

	s_dato = Bin(dato, 16);
	s_dato_esc = Bin(dato_esc, 16);
	s_dir = Bin(dir, n);
	/*
	dato = atoi(s_dato);
	dato_esc = atoi(s_dato_esc);
	dir = atoi(s_dir);

	m_dlgDireccion.UpdateData(true);
	m_dlgDireccion.m_iDato = dato;
	m_dlgDireccion.m_iDato_Esc = dato_esc;
	m_dlgDireccion.m_iDireccion = dir;
	m_dlgDireccion.m_sDireccion = s_dir;
	m_dlgDireccion.m_sTipo = tipo;
	m_dlgDireccion.UpdateData(false);
  	  */

	m_dlgDireccion.UpdateData(true);
	m_dlgDireccion.m_sDato = s_dato;
	m_dlgDireccion.m_sDato_Esc = s_dato_esc;
	m_dlgDireccion.m_iDireccion = dir;
	m_dlgDireccion.m_sDireccion = s_dir;
	m_dlgDireccion.m_sTipo = tipo;
	m_dlgDireccion.UpdateData(false);

}

void CCache2003View::OnConfigurarTiemposacceso() 
{
	
	// TODO: Add your command handler code here
	CTiemposDlg dlgTiempos;
    CEscrituraDlg dlgEscritura;
	CEstadisticasDlg dlgEstadisticas;
	
	dlgTiempos.m_iParalelo = m_iParalelo; 
	dlgTiempos.m_iBasica = m_iBasico;
	dlgTiempos.m_fTp = m_fTp;
	dlgTiempos.m_fTc = m_fTc;
	dlgEscritura.m_iEsc_Directa = m_iTip_Esc;	
	dlgEscritura.m_iCon_Asignacion = m_iAsignacion; 
	UpdateData(false);

		
	
	if( dlgTiempos.DoModal() == IDOK)
	{
		m_iParalelo = dlgTiempos.m_iParalelo; 
		m_iBasico = dlgTiempos.m_iBasica;
		m_fTp = dlgTiempos.m_fTp;
		m_fTc = dlgTiempos.m_fTc; 
		m_iTip_Esc = dlgEscritura.m_iEsc_Directa;	
		m_iAsignacion = dlgEscritura.m_iCon_Asignacion; 
		UpdateData(false);
		
		/*
		dlgEstadisticas.m_iParalelo = dlgTiempos.m_iParalelo;
		dlgEstadisticas.m_iBasico = dlgTiempos.m_iBasica;
		dlgEstadisticas.m_fTp = dlgTiempos.m_fTp;
		dlgEstadisticas.m_fTc = dlgTiempos.m_fTc;
		dlgEstadisticas.m_iTip_Esc = dlgEscritura.m_iEsc_Directa;
		dlgEstadisticas.m_iAsignacion = dlgEscritura.m_iCon_Asignacion;
		UpdateData(false);
		  */
		

	}//fin del if DoModal()

	


}
	   
void CCache2003View::ImprimeFormatoSim(int n, int Dato, int DatoEscrito, int NPalabra, int NBloque, int NPalabraBloque, int NLinea)
{
	

	CString s_DatoSelect;
	CString s_DatoEscrito;
	CString s_NPalabra;
	CString s_NBloque;
	CString s_NPalabraBloque;
	CString s_NLinea;
	char bufferDato[10];

	
	
	CMenu *pMenu = GetParentFrame()->GetMenu();
	
	if( pMenu->GetMenuState(ID_FORMAT_DECIMAL, MF_BYCOMMAND) == MF_CHECKED)
	{
	   		   
		
		

		s_DatoSelect = _itoa( Dato , bufferDato, 10);
		s_DatoEscrito = _itoa( DatoEscrito , bufferDato, 10);
		s_NPalabra = _itoa( NPalabra , bufferDato, 10);
		s_NBloque  =  _itoa( NBloque , bufferDato, 10);
		s_NPalabraBloque = _itoa( NPalabraBloque , bufferDato, 10);
		s_NLinea = _itoa( NLinea , bufferDato, 10);
		
		
		m_Dato = s_DatoSelect;
		m_Dato_Escrito = s_DatoEscrito;
		m_NPalabra = s_NPalabra;
		m_NBloque = s_NBloque;
		m_NPalabraBloque = s_NPalabraBloque;
		m_NLinea = s_NLinea;
		
		UpdateData(false);
		 
	}


	
	if( pMenu->GetMenuState(ID_FORMAT_BINARIO, MF_BYCOMMAND) == MF_CHECKED)
	{
	   		   
		
		s_DatoSelect = Bin(Dato, 16);
		s_DatoEscrito = Bin(DatoEscrito, 16);
		s_NPalabra = Bin(NPalabra, n);
		s_NBloque  =  Bin(NBloque, 14);
		s_NPalabraBloque = Bin(NPalabraBloque, 10);
		s_NLinea = Bin(NLinea, 10);
		
		
		m_Dato = s_DatoSelect;
		m_Dato_Escrito = s_DatoEscrito;
		m_NPalabra = s_NPalabra;
		m_NBloque = s_NBloque;
		m_NPalabraBloque = s_NPalabraBloque;
		m_NLinea = s_NLinea;
		
		UpdateData(false);
		 
	}

	if( pMenu->GetMenuState(ID_FORMAT_OCTAL, MF_BYCOMMAND) == MF_CHECKED)
	{
		

		s_DatoSelect = Oct(Dato);
		s_DatoEscrito = Oct(DatoEscrito);
		s_NPalabra = Oct(NPalabra);
		s_NBloque  =  Oct(NBloque);
		s_NPalabraBloque = Oct(NPalabraBloque);
		s_NLinea = Oct(NLinea);
		

		
		m_Dato = s_DatoSelect;
		m_Dato_Escrito = s_DatoEscrito;
		m_NPalabra = s_NPalabra;
		m_NBloque = s_NBloque;
		m_NPalabraBloque = s_NPalabraBloque;
		m_NLinea = s_NLinea;
		
		UpdateData(false);
		
	}
	
	if( pMenu->GetMenuState(ID_FORMAT_HEXADECIMAL, MF_BYCOMMAND) == MF_CHECKED)
	{
		
		s_DatoSelect = Hex(Dato);
		s_DatoEscrito = Hex(DatoEscrito);
		s_NPalabra = Hex(NPalabra);
		s_NBloque  =  Hex(NBloque);
		s_NPalabraBloque = Hex(NPalabraBloque);
		s_NLinea = Hex(NLinea);
		

		
		m_Dato = s_DatoSelect;
		m_Dato_Escrito = s_DatoEscrito;
		m_NPalabra = s_NPalabra;
		m_NBloque = s_NBloque;
		m_NPalabraBloque = s_NPalabraBloque;
		m_NLinea = s_NLinea;
		UpdateData(false);

		
	}



}

void CCache2003View::ImprimeFormatoSim_Conj(int n, int Dato, int DatoEscrito, int NPalabra, int NBloque, int NPalabraBloque, int NLinea, int NConjunto, int NVia)
{
	
	CString s_DatoSelect;
	CString s_DatoEscrito;
	CString s_NPalabra;
	CString s_NBloque;
	CString s_NPalabraBloque;
	CString s_NLinea;
	CString s_NConjunto;
	CString s_nLineaConjunto;
	char bufferDato[10];
	

	CMenu *pMenu = GetParentFrame()->GetMenu();
	
	if( pMenu->GetMenuState(ID_FORMAT_DECIMAL, MF_BYCOMMAND) == MF_CHECKED)
	{
	   		   
		
		s_DatoSelect = _itoa( Dato , bufferDato, 10);
		s_DatoEscrito = _itoa( DatoEscrito , bufferDato, 10);
		s_NPalabra = _itoa( NPalabra , bufferDato, 10);
		s_NBloque  =  _itoa( NBloque , bufferDato, 10);
		s_NPalabraBloque = _itoa( NPalabraBloque , bufferDato, 10);
		s_NLinea = _itoa( NLinea , bufferDato, 10);
		s_NConjunto = _itoa( NConjunto , bufferDato, 10);
		s_nLineaConjunto = _itoa( NVia , bufferDato, 10);
		
		m_Dato = s_DatoSelect;
		m_Dato_Escrito = s_DatoEscrito;
		m_NPalabra = s_NPalabra;
		m_NBloque = s_NBloque;
		m_NPalabraBloque = s_NPalabraBloque;
		m_NLinea = s_NLinea;
		m_NConjunto = s_NConjunto;
		m_nLineaConjunto = s_nLineaConjunto;
		UpdateData(false);
		 
	}


	if( pMenu->GetMenuState(ID_FORMAT_BINARIO, MF_BYCOMMAND) == MF_CHECKED)
	{
	   		   
		

		s_DatoSelect = Bin(Dato, 16);
		s_DatoEscrito = Bin(DatoEscrito, 16);
		s_NPalabra = Bin(NPalabra, n);
		s_NBloque  =  Bin(NBloque, 14);
		s_NPalabraBloque = Bin(NPalabraBloque, 10);
		s_NLinea = Bin(NLinea, 10);
		s_NConjunto = Bin(NConjunto, 8);
		s_nLineaConjunto = Bin( NVia, 8);

		
		m_Dato = s_DatoSelect;
		m_Dato_Escrito = s_DatoEscrito;
		m_NPalabra = s_NPalabra;
		m_NBloque = s_NBloque;
		m_NPalabraBloque = s_NPalabraBloque;
		m_NLinea = s_NLinea;
		m_NConjunto = s_NConjunto;
		m_nLineaConjunto = s_nLineaConjunto;
		UpdateData(false);
		 
	}

	if( pMenu->GetMenuState(ID_FORMAT_OCTAL, MF_BYCOMMAND) == MF_CHECKED)
	{
		
		s_DatoSelect = Oct(Dato);
		s_DatoEscrito = Oct(DatoEscrito);
		s_NPalabra = Oct(NPalabra);
		s_NBloque  =  Oct(NBloque);
		s_NPalabraBloque = Oct(NPalabraBloque);
		s_NLinea = Oct(NLinea);
		s_NConjunto = Oct(NConjunto);
		s_nLineaConjunto = Oct( NVia);

		
		m_Dato = s_DatoSelect;
		m_Dato_Escrito = s_DatoEscrito;
		m_NPalabra = s_NPalabra;
		m_NBloque = s_NBloque;
		m_NPalabraBloque = s_NPalabraBloque;
		m_NLinea = s_NLinea;
		m_NConjunto = s_NConjunto;
		m_nLineaConjunto = s_nLineaConjunto;
		UpdateData(false);
		
	}
	
	if( pMenu->GetMenuState(ID_FORMAT_HEXADECIMAL, MF_BYCOMMAND) == MF_CHECKED)
	{
		
		s_DatoSelect = Hex(Dato);
		s_DatoEscrito = Hex(DatoEscrito);
		s_NPalabra = Hex(NPalabra);
		s_NBloque  =  Hex(NBloque);
		s_NPalabraBloque = Hex(NPalabraBloque);
		s_NLinea = Hex(NLinea);
		s_NConjunto = Hex(NConjunto);
		s_nLineaConjunto = Hex( NVia);

		
		m_Dato = s_DatoSelect;
		m_Dato_Escrito = s_DatoEscrito;
		m_NPalabra = s_NPalabra;
		m_NBloque = s_NBloque;
		m_NPalabraBloque = s_NPalabraBloque;
		m_NLinea = s_NLinea;
		m_NConjunto = s_NConjunto;
		m_nLineaConjunto = s_nLineaConjunto;
		UpdateData(false);

		
	}


}

void CCache2003View::OnEditCopy() 
{
	
CString TextoSelec, TextoSalida, TextoCabecera;

  
  if( m_CtrlRejilla_MP.GetCol() != m_CtrlRejilla_MP.GetColSel() || m_CtrlRejilla_MP.GetRow() != m_CtrlRejilla_MP.GetRowSel()  )
  {
		
	  	// Filas y columnas seleccionadas
		long FilaIni = m_CtrlRejilla_MP.GetRow();
		long ColIni = m_CtrlRejilla_MP.GetCol();
		long FilaFin = m_CtrlRejilla_MP.GetRowSel();
		long ColFin = m_CtrlRejilla_MP.GetColSel();
  
		

	    // Almacenar el contenido de las celdas seleccionadas para MP
		TextoSelec = m_CtrlRejilla_MP.GetClip();
				
		// Formar la nueva cabecera
		TextoSalida = "";
		m_CtrlRejilla_MP.SetRow(0); // fila actual
		long Contador;
									/*
		for ( long Contador = ColIni; Contador <= ColFin; Contador++ )
		{
			
						
			m_CtrlRejilla_MP.SetCol(Contador); // columna actual
			//TextoCabecera = "";
			for (int Pos = 0; Pos < (m_CtrlRejilla_MP.GetText()).GetLength(); Pos++)
			{
			// Si el carácter actual no es un retorno de carro
			if ( (m_CtrlRejilla_MP.GetText())[Pos] != '\xA' )
			{
				//TextoCabecera = TextoCabecera + (m_CtrlRejilla_MP.GetText())[Pos];
			}
			else if ( Pos != 0 )
			{
				//TextoCabecera = TextoCabecera + " ";
			}
			}
			// Añadir a la variable de salida la cabecera de esta columna
			//TextoSalida = TextoSalida + "\t" + TextoCabecera;
		}
		//TextoSalida = TextoSalida + "\n";
		  */
		// Añadir a la variable de salida la cabecera de la primera
		// línea seleccionada
		m_CtrlRejilla_MP.SetCol(0);
		m_CtrlRejilla_MP.SetRow(FilaIni);
		TextoSalida = TextoSalida + m_CtrlRejilla_MP.GetText() + "\t";
		// Copiar el texto seleccionado en la variable de salida
		for ( Contador = 0; Contador < TextoSelec.GetLength(); Contador++ )
		{
			// Si el carácter actual no es un retorno de carro
			if ( TextoSelec[(int)Contador] != '\xD' ) // si no es un CR
			TextoSalida = TextoSalida + TextoSelec[(int)Contador];
			else // si el carácter actual es un retorno de carro
			{
			// Siguiente fila
			m_CtrlRejilla_MP.SetRow(m_CtrlRejilla_MP.GetRow() + 1);
			// Añadir un \n y la cabecera de la fila actual
			TextoSalida = TextoSalida + "\n" + m_CtrlRejilla_MP.GetText()+ "\t";
			
			
			}
		}
  
  
  		// Copiar el contenido de la variable de salida en el portapapeles
		// ===============================================================
		// Asignar un bloque de memoria global iniciado a cero
		HGLOBAL hBloqMemGlo = GlobalAlloc(GHND, (DWORD)TextoSalida.GetLength()+1);
		if ( !hBloqMemGlo )
		{
			AfxMessageBox("No se puede asignar memoria" );
			return;
		}
		// Fijar el bloque para obtener un puntero
		LPSTR lpBloqMemGlo = (LPSTR)GlobalLock(hBloqMemGlo);
		// Copiar la cadena de caracteres en el bloque
		memcpy(lpBloqMemGlo, TextoSalida, TextoSalida.GetLength());
		// Liberar el bloque
		GlobalUnlock(hBloqMemGlo);
		// Abrir el portapapeles
		if ( !OpenClipboard() )
		{
			AfxMessageBox("No se puede abrir el portapapeles" );
			return;
		}
		// Vaciar el portapapeles
		EmptyClipboard();
		// Darle al portapapeles el handle del bloque de memoria
		SetClipboardData( CF_TEXT, hBloqMemGlo );
		// Cerrar el portapapeles
		CloseClipboard();

  
  }

  
  if( m_CtrlRejilla_MC.GetCol() != m_CtrlRejilla_MC.GetColSel() || m_CtrlRejilla_MC.GetRow() != m_CtrlRejilla_MC.GetRowSel() )
  {

  		 // Filas y columnas seleccionadas
		long FilaIni = m_CtrlRejilla_MC.GetRow();
		long ColIni = m_CtrlRejilla_MC.GetCol();
		long FilaFin = m_CtrlRejilla_MC.GetRowSel();
		long ColFin = m_CtrlRejilla_MC.GetColSel();
  

		// Almacenar el contenido de las celdas seleccionadas	para MC
		TextoSelec = m_CtrlRejilla_MC.GetClip();
		// Formar la nueva cabecera
		TextoSalida = "";
		m_CtrlRejilla_MC.SetRow(0); // fila actual
		long Contador;
		/*
		for ( long Contador = ColIni; Contador <= ColFin; Contador++ )
		{
			m_CtrlRejilla_MC.SetCol(Contador); // columna actual
			TextoCabecera = "";
			for (int Pos = 0; Pos < (m_CtrlRejilla_MC.GetText()).GetLength(); Pos++)
			{
			// Si el carácter actual no es un retorno de carro
			if ( (m_CtrlRejilla_MC.GetText())[Pos] != '\xA' )
				TextoCabecera = TextoCabecera + (m_CtrlRejilla_MC.GetText())[Pos];
			else if ( Pos != 0 )
				TextoCabecera = TextoCabecera + " ";
			}
			// Añadir a la variable de salida la cabecera de esta columna
			TextoSalida = TextoSalida + "\t" + TextoCabecera;
		}
		TextoSalida = TextoSalida + "\n";

  */
		// Añadir a la variable de salida la cabecera de la primera
		// línea seleccionada
		m_CtrlRejilla_MC.SetCol(0);
		m_CtrlRejilla_MC.SetRow(FilaIni);
		TextoSalida = TextoSalida + m_CtrlRejilla_MC.GetText() + "\t";

		
		// Copiar el texto seleccionado en la variable de salida
		for ( Contador = 0; Contador < TextoSelec.GetLength(); Contador++ )
		{
			// Si el carácter actual no es un retorno de carro
			if ( TextoSelec[(int)Contador] != '\xD' ) // si no es un CR
			TextoSalida = TextoSalida + TextoSelec[(int)Contador];
			else // si el carácter actual es un retorno de carro
			{
			// Siguiente fila
			m_CtrlRejilla_MC.SetRow(m_CtrlRejilla_MC.GetRow() + 1);
			// Añadir un \n y la cabecera de la fila actual
			TextoSalida = TextoSalida + "\n" + m_CtrlRejilla_MC.GetText() + "\t";
			}
		}
  
  
  

		// Copiar el contenido de la variable de salida en el portapapeles
		// ===============================================================
		// Asignar un bloque de memoria global iniciado a cero
		HGLOBAL hBloqMemGlo = GlobalAlloc(GHND, (DWORD)TextoSalida.GetLength()+1);
		 if ( !hBloqMemGlo )
		{
			AfxMessageBox("No se puede asignar memoria" );
			return;
		}
		// Fijar el bloque para obtener un puntero
		LPSTR lpBloqMemGlo = (LPSTR)GlobalLock(hBloqMemGlo);
		// Copiar la cadena de caracteres en el bloque
		memcpy(lpBloqMemGlo, TextoSalida, TextoSalida.GetLength());
		// Liberar el bloque
		GlobalUnlock(hBloqMemGlo);
		// Abrir el portapapeles
		if ( !OpenClipboard() )
		{
			AfxMessageBox("No se puede abrir el portapapeles" );
			return;
		}
		// Vaciar el portapapeles
		EmptyClipboard();
		// Darle al portapapeles el handle del bloque de memoria
		SetClipboardData( CF_TEXT, hBloqMemGlo );
		// Cerrar el portapapeles
		CloseClipboard();
  }

  
}

void CCache2003View::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//Habilitar/inhabilitar "Copiar" sis hay/no hay seleccionado un rango
   
	pCmdUI->Enable( m_CtrlRejilla_MP.GetRow() != m_CtrlRejilla_MP.GetRowSel() || 
	                m_CtrlRejilla_MP.GetCol() != m_CtrlRejilla_MP.GetColSel() ||
					m_CtrlRejilla_MC.GetRow() != m_CtrlRejilla_MC.GetRowSel() || 
	                m_CtrlRejilla_MC.GetCol() != m_CtrlRejilla_MC.GetColSel());
}


void CCache2003View::OnEditPaste() 
{
	// TODO: Add your command handler code here
	/*
	CString BloqueCopia;
	OpenClipboard();

	if( IsClipboardFormatAvailable( CF_TEXT))
	{
		HGLOBAL hBloqPorta = GetClipboardData(CF_TEXT);
		LPSTR lpBloqPorta = (LPSTR)GlobalLock(hBloqPorta);

		BloqueCopia = lpBloqPorta;
		
		GlobalUnlock( hBloqPorta);
	}

	CloseClipboard();
	
	
	BloqueCopia.TrimLeft();
	BloqueCopia.TrimRight(); 
	

	MessageBox(BloqueCopia);
	
	
	

	long PosicionFila = m_CtrlRejilla_MC.GetRow();
	int  NCaracteres = BloqueCopia.GetLength();
	int  Espacios = 0;
	int  Contador = 0;
	int PosicionEspacio = 0;
	int PosicionSalto = 0;
		
	char buffercelda[100];
	CString s_PosicionFila;
	CString s_Residuo;
	CString s_NCaracteres;
	CString s_PosicionEspacio;
	CString s_PosicionSalto;
	CString s_Contador;
	CString Palabra;
	
		
	s_NCaracteres = _itoa( NCaracteres  , buffercelda, 10);
	MessageBox(" Número Caracteres = " + s_NCaracteres);
	
	
	//Encuentra el número de espacios vacios en BloqueCopia
	for( int i = 0; i< NCaracteres; i++)
	{
		 if( (BloqueCopia[i] == '\t') || (BloqueCopia[i] == '\xA'))
		 {	 
			
			 PosicionEspacio = BloqueCopia.Find('\t');
			 PosicionSalto = BloqueCopia.Find('\xA');

			 s_PosicionEspacio = _itoa( PosicionEspacio  , buffercelda, 10);
			 MessageBox(" PosicionEspacio = " + s_PosicionEspacio);
			 
			 s_PosicionSalto = _itoa( PosicionSalto  , buffercelda, 10);
			 MessageBox(" PosicionSalto = " + s_PosicionSalto);
			
			 
			 MessageBox(" BloqueCopia = " + BloqueCopia);
			
			 Palabra = BloqueCopia.Left(PosicionEspacio);
			 
			 //Si encuentra un retorno salta a la otra fila
			 
			 if(BloqueCopia[i] == '\xA')
			 {
					PosicionFila++;
					MessageBox("Aumento la fila");
			 }

			
			 if( BloqueCopia[i + 1] != '\t')
			 {
				MessageBox(" Palabra = " + Palabra);
				
				int Residuo	= (Contador + 3) % 3;
				s_Residuo = _itoa( Residuo  , buffercelda, 10);
				MessageBox(" Residuo = " + s_Residuo);

				switch(Residuo)
				{
				case 0:

					m_CtrlRejilla_MC.SetRow(PosicionFila);
					m_CtrlRejilla_MC.SetCol(0);
					m_CtrlRejilla_MC.SetTextArray(GenID(PosicionFila ,0),Palabra);
					//PosicionFila++;
					break;
				case 1:
					
					m_CtrlRejilla_MC.SetRow(PosicionFila);
					m_CtrlRejilla_MC.SetCol(1);
					m_CtrlRejilla_MC.SetTextArray(GenID(PosicionFila ,1),Palabra);
					//PosicionFila++;
					break;
										
				case 2:
				   
					m_CtrlRejilla_MC.SetRow(PosicionFila);
					m_CtrlRejilla_MC.SetCol(2);
					m_CtrlRejilla_MC.SetTextArray(GenID(PosicionFila ,2),Palabra);
					//PosicionFila++;												}	
					break;
				}

								
				if(PosicionEspacio < NCaracteres)
				{
					BloqueCopia = BloqueCopia.Mid((PosicionEspacio + 1), NCaracteres); 
					Contador++;
					s_Contador = _itoa( Contador  , buffercelda, 10);
					MessageBox(" Contador = " + s_Contador);

					s_PosicionFila = _itoa( PosicionFila  , buffercelda, 10);
					MessageBox(" PosicionFila = " + s_PosicionFila);

				}
				
				


			}//fin del if segundo
			
		 }//fin del if primero
		 

	 }//fin del for
	  */
	
}
void CCache2003View::OnUpdateVerDireccindememoria(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( m_dlgDireccion.IsWindowVisible() == false );
}

void CCache2003View::OnUpdateContadorLineas(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( m_CtrlRejilla_MC.GetColWidth(3) == 0 );
}

void CCache2003View::OnUpdateTipoDato(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( m_CtrlRejilla_MP.GetColWidth(2) == 0 );


}

void CCache2003View::OnContadorLineas() 
{
	// TODO: Add your command handler code here
	 m_CtrlRejilla_MC.SetColWidth(3, 1000);
	 
	 m_CtrlRejilla_MC.SetRow(0);
	 m_CtrlRejilla_MC.SetCol(3);
	 m_CtrlRejilla_MC.SetText("Cont. Fallos");
	 m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
	 m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
	 m_CtrlRejilla_MC.SetCellAlignment(4);
	 m_CtrlRejilla_MC.Refresh();
	 GetDlgItem(IDC_CHECK_CONT) ->EnableWindow(TRUE);
	 m_bChk_Cont = TRUE;
	 UpdateData(false);

}

void CCache2003View::OnTipoDato() 
{
	// TODO: Add your command handler code here
	 m_CtrlRejilla_MP.SetColWidth(2, 1000);
	 
	m_CtrlRejilla_MP.SetRow(0);
	m_CtrlRejilla_MP.SetCol(2);
	m_CtrlRejilla_MP.SetText("Lec/Esc");
	m_CtrlRejilla_MP.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MP.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MP.SetCellAlignment(4);
	m_CtrlRejilla_MP.Refresh();
	GetDlgItem(IDC_CHECK_L_E) ->EnableWindow(TRUE);
	m_bChk_LectEsc = TRUE;
	UpdateData(false);


}

void CCache2003View::OnUpdateTipoDatoMc(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( m_CtrlRejilla_MC.GetColWidth(2) == 0 );

}

void CCache2003View::OnTipoDatoMc() 
{
	// TODO: Add your command handler code here
	m_CtrlRejilla_MC.SetColWidth(2, 1000);
	 
	m_CtrlRejilla_MC.SetRow(0);
	m_CtrlRejilla_MC.SetCol(2);
	m_CtrlRejilla_MC.SetText("Lec/Esc");
	m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MC.SetCellAlignment(4);
	m_CtrlRejilla_MC.Refresh();
	GetDlgItem(IDC_CHECK_L_E) ->EnableWindow(TRUE);
	m_bChk_LectEsc = TRUE;
	UpdateData(false);


}

void CCache2003View::OnVerInformedesimulacin() 
{
	// TODO: Add your command handler code here
	m_dlgEstadisticas.ShowWindow( SW_SHOW );
	m_dlgEstadisticas.CalculoTa_Stats();
}

void CCache2003View::ActualizarDatosChart(int aciertos, int fallos, int simulaciones)
{
	m_dlgEstadisticas.UpdateData(true);
	m_dlgEstadisticas.m_iAciertos = aciertos;
	m_dlgEstadisticas.m_iFallos = fallos;
	m_dlgEstadisticas.m_iSimulaciones = simulaciones;
	
	m_dlgEstadisticas.UpdateData(false);
}

void CCache2003View::OnUpdateVerInformedesimulacin(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( m_dlgEstadisticas.IsWindowVisible() == false );
}

void CCache2003View::OnInsertarDatosMp() 
{
	// TODO: Add your command handler code here
	
	
	
}

void CCache2003View::LlenarVista()
{

/*
char buffer[5];
CString s_Tipo;
CString s_Lectura;	
 */
	CCache2003Doc* pDoc = GetDocument();
	if( pDoc)
	{
	
		m_sPosicion.Format("Registro %d de %d", pDoc->ObtenerCurRegistroNbr(), 
			pDoc->ObtenerTotalRegistros());
	}

	if( m_pCurDatos)
	{
		m_sDireccion = m_pCurDatos->GetDireccion();
		m_sDato = m_pCurDatos->GetDato();
		m_iTipo = m_pCurDatos->GetTipo();
		UpdateData( false);
		/*
		s_Tipo = _itoa( m_iTipo, buffer, 10);
		MessageBox("Tipo = " + s_Tipo);
		  */
		if( m_iTipo == 1)
		{
			m_iLectura = 0;
			UpdateData(false);
			/*
			s_Lectura = _itoa( m_iLectura, buffer, 10);
			MessageBox("radio_Lectura = " + s_Lectura);
			  */
			
		}
		else
		{
			m_iLectura = 1;
			UpdateData(false);
			/*
			s_Lectura = _itoa( m_iLectura, buffer, 10);
			MessageBox("radio_Lectura = " + s_Lectura);
			  */
			
		}
	
	
	}




}

void CCache2003View::Primero()
{
	CCache2003Doc *pDoc = GetDocument();
	if( pDoc)
	{
		m_pCurDatos = pDoc->ObtienePrimero();
		if( m_pCurDatos )
		{
			LlenarVista();
		}
	}

	//Validacion
	CambiaDato();
	if(m_sDato == "")
	{
	   GetDlgItem(IDC_B_AGREGAR) -> EnableWindow(TRUE);	
	   GetDlgItem(IDC_B_EDITAR) -> EnableWindow(FALSE);

	}
	else
	{
	   GetDlgItem(IDC_B_AGREGAR) -> EnableWindow(FALSE);
	   GetDlgItem(IDC_B_EDITAR) -> EnableWindow(TRUE);
	}



}

void CCache2003View::Ultimo()
{
   
	
	CCache2003Doc *pDoc = GetDocument();
	int total;
	
	//Validación de último
	total = pDoc->ObtenerTotalRegistros();
	if(total == 0)
	{
		MessageBox("No se ha introducido ningún dato a la memoria principal.\nNo existen registros");
		return;
	}
	
	
	if( pDoc)
	{
		m_pCurDatos = pDoc->ObtieneUltimo();
		if( m_pCurDatos)
		{
			LlenarVista();
		}
	}
	//Validacion
	CambiaDato();
	if(m_sDato == "")
	{
	   GetDlgItem(IDC_B_AGREGAR) -> EnableWindow(TRUE);
	   GetDlgItem(IDC_B_EDITAR) -> EnableWindow(FALSE);

	}
	else
	{
	   GetDlgItem(IDC_B_AGREGAR) -> EnableWindow(FALSE);
	   GetDlgItem(IDC_B_EDITAR) -> EnableWindow(TRUE);
	}

  
}

void CCache2003View::Anterior()
{
   CCache2003Doc *pDoc = GetDocument();
	if( pDoc)
	{
		m_pCurDatos = pDoc->ObtieneAnterior();
		if( m_pCurDatos)
		{
			LlenarVista();
		}
	}


	//Validacion
	CambiaDato();
	if(m_sDato == "")
	{
	   GetDlgItem(IDC_B_AGREGAR) -> EnableWindow(TRUE);
	   GetDlgItem(IDC_B_EDITAR) -> EnableWindow(FALSE);

	}
	else
	{
	   GetDlgItem(IDC_B_AGREGAR) -> EnableWindow(FALSE);
	   GetDlgItem(IDC_B_EDITAR) -> EnableWindow(TRUE);

	}

}

void CCache2003View::Siguiente()
{
   	int totalReg;
	char buff[5];

	CCache2003Doc *pDoc = GetDocument();
		
	if( pDoc)
	{
		m_pCurDatos = pDoc->ObtieneSiguiente();
		if( m_pCurDatos)
		{
			LlenarVista();
		}

		totalReg = pDoc->ObtenerTotalRegistros();
	}

	


	//Validacion
	CambiaDato();
	if(m_sDato == "")
	{
	   GetDlgItem(IDC_B_AGREGAR) -> EnableWindow(TRUE);
	   GetDlgItem(IDC_B_EDITAR) -> EnableWindow(FALSE);
	   m_sDireccion = _itoa( totalReg, buff, 10);
	   UpdateData(false);
	}
	else
	{
	   GetDlgItem(IDC_B_AGREGAR) -> EnableWindow(FALSE);
	   GetDlgItem(IDC_B_EDITAR) -> EnableWindow(TRUE);
	}


}

void CCache2003View::CambiaDireccion()
{
	
	
	UpdateData(TRUE);
	if(m_pCurDatos)
		m_pCurDatos->SetDireccion(m_sDireccion);

	CCache2003Doc *pDoc = GetDocument();
	
	if(pDoc)
		pDoc->SetModifiedFlag();

	
	

}

void CCache2003View::CambiaDato()
{
	
	UpdateData(TRUE);
	if(m_pCurDatos)
		m_pCurDatos->SetDato(m_sDato);
	
	CCache2003Doc *pDoc = GetDocument();
	
	if(pDoc)
		pDoc->SetModifiedFlag();
	
	 

}

void CCache2003View::CambiaTipo()
{
   	
	UpdateData(TRUE);
	if(m_pCurDatos)
		m_pCurDatos->SetTipo(m_iTipo);

	
	CCache2003Doc *pDoc = GetDocument();
	
	if(pDoc)
		pDoc->SetModifiedFlag();
	
	

}

void CCache2003View::PonerNuevoDato()
{
	 Primero();
}

void CCache2003View::Agregar()
{
   
GetDlgItem(IDC_DATOSDLG_DIRECCION)->EnableWindow(TRUE);

GetDlgItem(IDC_B_PRIMERO)->EnableWindow(TRUE);
GetDlgItem(IDC_B_ANTERIOR)->EnableWindow(TRUE);
GetDlgItem(IDC_B_SIGUIENTE)->EnableWindow(TRUE);
GetDlgItem(IDC_B_ULTIMO)->EnableWindow(TRUE);




if( m_TamMP > m_iReg)
{

	char bufferDireccion[10];
	int i_Dato;
	int i_Direccion;
	int n = m_nMP;
	int i = m_iReg;
	CString sReg;
	i_Direccion = m_iReg;
	i_Dato = atoi(m_sDato);
	
	/*
	CString s_i;
	s_i = _itoa(m_iReg, bufferDireccion, 10);
	MessageBox( "i "+ s_i);
	  */
		//Validaciones
	if((i_Dato >= 10000) || (i_Dato < 0))
	{
		AfxMessageBox("El dato introducido no es válido.\nLa acción será cancelada.", MB_OK, MB_ICONSTOP);  
		m_sDato = "";
		UpdateData(false);
		((CEdit *)GetDlgItem(IDC_DATOSDLG_DAT))->SetFocus();
		return;

	}
	
	if((i_Direccion > m_TamMP ) || (i_Direccion < 0))
	{
		AfxMessageBox("La memoria principal se ha sobrecargado.\nLa acción será cancelada.", MB_OK, MB_ICONSTOP);  
		m_sDireccion = "";
		UpdateData(false);
		((CEdit *)GetDlgItem(IDC_DATOSDLG_DIRECCION))->SetFocus();
		return;

	}
	
	m_sDireccion = _itoa( m_iReg, bufferDireccion, 10);	 	
	UpdateData(false);	
	
	i_Direccion++;
	
	sReg = _itoa( i_Direccion , bufferDireccion, 10);
	
	i_Direccion--;
	
	CambiaDireccion();	
	
	
	CMenu *pMenu = GetParentFrame()->GetMenu();
	
	if( pMenu->GetMenuState(ID_FORMAT_DECIMAL, MF_BYCOMMAND) == MF_CHECKED)
	{

		//Formato Decimal
		m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,0),m_sDireccion);
	    m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,1),m_sDato);
		//Formato Lectura Escritura
		switch(m_iTipo)
		{
			case 1:
				m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Lectura");
			break;
			case 2:
				m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Escritura");
				m_nEscrituras++;
				UpdateData(false);
			break;
		}

		m_iReg++;
		UpdateData(false);

	}
	
	
	if( pMenu->GetMenuState(ID_FORMAT_BINARIO, MF_BYCOMMAND) == MF_CHECKED)
	{

		 		
		//Formato Binario
		m_CtrlRejilla_MP.SetTextArray(GenID(i +1,0),Bin(i_Direccion, n));
	    m_CtrlRejilla_MP.SetTextArray(GenID(i +1,1),Bin(i_Dato , 16));
		//Formato Lectura Escritura
		switch(m_iTipo)
		{
			case 1:
				m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Lectura");
			break;
			case 2:
				m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Escritura");
				m_nEscrituras++;
				UpdateData(false);

			break;
		}

		 m_iReg++;
		 UpdateData(false);
		 
	}

	if( pMenu->GetMenuState(ID_FORMAT_OCTAL, MF_BYCOMMAND) == MF_CHECKED)
	{
		
		//Formato Octal
		m_CtrlRejilla_MP.SetTextArray(GenID(i +1,0),Oct(i_Direccion));
	    m_CtrlRejilla_MP.SetTextArray(GenID(i +1,1),Oct(i_Dato));
		m_CtrlRejilla_MP.SetColAlignment(0, 6);
		m_CtrlRejilla_MP.SetColAlignment(1, 6);
		
		//Formato Lectura Escritura
		switch(m_iTipo)
		{
			case 1:
				m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Lectura");
			break;
			case 2:
				m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Escritura");
				m_nEscrituras++;
				UpdateData(false);

			break;
		}

		m_iReg++;
		UpdateData(false);

	}
	
	if( pMenu->GetMenuState(ID_FORMAT_HEXADECIMAL, MF_BYCOMMAND) == MF_CHECKED)
	{

		
		//Formato Hexadecimal
		m_CtrlRejilla_MP.SetTextArray(GenID(i +1,0),Hex(i_Direccion));
	    m_CtrlRejilla_MP.SetTextArray(GenID(i +1,1),Hex(i_Dato));
		m_CtrlRejilla_MP.SetColAlignment(0, 6);
		m_CtrlRejilla_MP.SetColAlignment(1, 6);
		

		//Formato Lectura Escritura
		switch(m_iTipo)
		{
			case 1:
				m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Lectura");
			break;
			case 2:
				m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Escritura");
				m_nEscrituras++;
				UpdateData(false);

			break;
		}
		m_iReg++;
		UpdateData(false);

		
	}

	
		
	CCache2003Doc *pDoc = GetDocument();
	
	//Validacion
	
	int total;
	total = pDoc->ObtenerTotalRegistros();
	if( total > m_iReg )
	{
		MessageBox("La memoria principal ya está llena.\nNo esposible agregar más datos");
		Ultimo();
		return;
	}
	


/*
char buffer[5];
CString s_celda;
CString s_Tipo;
s_celda = _itoa( *(m_arrayDirMPPtr + 1)  , buffer, 10);
MessageBox(" arrayDirMP = " + s_celda);
*/	
	
	if(pDoc)
	{
		
		DescargarObjetosDatos();
		//Se crea el nuevo objeto dato y se une al arreglo
		m_pCurDatos = pDoc->AgregarRegistros();
		
		if(m_pCurDatos)
		{
			//se le da los valores predeterminados
			m_pCurDatos->SetDireccion(sReg);
			m_pCurDatos->SetDato("");
			m_pCurDatos->SetTipo(1);
			
			//se piden los nuevos valores
			LlenarVista();
			

		}
		else
			MessageBox("No hay suficiente memoria");
	}

}//fin del primer if
else
{
	MessageBox("La capacidad de la memoria principal está a su límite.\nEl dato no fue insertado a la memoria principal");
	Ultimo();
	//GetDlgItem(IDC_DATOSDLG_DAT)->EnableWindow(FALSE);
}

  
}

void CCache2003View::OnChangeDatosdlgDireccion() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CambiaDireccion();
}

void CCache2003View::OnChangeDatosdlgDat() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CambiaDato();
}

void CCache2003View::OnChangeDatosdlgTip() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CambiaTipo();
	/*
	switch(m_iLectura)
	{
	case 0:
		OnRadioLect();
		break;
	case 1:
		OnRadioEsc();
		break;
	} 
	*/

}

void CCache2003View::LLenarObjetosDatos(int reg, int dir, int dat, int tip)
{
	
	char buffer[5];
	CString s_array_dir;
	CString s_array_dat;
	int i_array_tip;

	s_array_dir = _itoa( *(m_arrayDirMPPtr + reg)  , buffer, 10);
	s_array_dat = _itoa( *(m_arrayDatosMPPtr + reg)  , buffer, 10);
	i_array_tip = *(m_arrayTipoMPPtr + reg);
	
	
  	UpdateData(TRUE);
	if(m_pCurDatos)
	{
		m_pCurDatos->SetDireccion(s_array_dir);
		m_pCurDatos->SetDato(s_array_dat);
		m_pCurDatos->SetTipo(i_array_tip);
	}
	
	
	CCache2003Doc *pDoc = GetDocument();
		
	if(pDoc)
	{
		

		DescargarObjetosDatos();
		
		//Se crea el nuevo objeto dato y se une al arreglo
		m_pCurDatos = pDoc->AgregarRegistros();
		if(m_pCurDatos)
		{
			//se le da los valores predeterminados
			m_pCurDatos->SetDireccion("");
			m_pCurDatos->SetDato("");
			m_pCurDatos->SetTipo(1);
			
			//se piden los nuevos valores
			LlenarVista();
			
		}
		else
			MessageBox("No hay suficiente memoria");
	}

}


void CCache2003View::OnBPrimero() 
{
	// TODO: Add your control notification handler code here
	Primero();
}

void CCache2003View::OnBUltimo() 
{
	// TODO: Add your control notification handler code here
	Ultimo();
}

void CCache2003View::OnBAnterior() 
{
	// TODO: Add your control notification handler code here
	Anterior();
}

void CCache2003View::OnBSiguiente() 
{
	// TODO: Add your control notification handler code here
	CCache2003Doc *pDoc = GetDocument();
	
	int actual;
	actual = pDoc->ObtenerCurRegistroNbr();
	if( actual >= m_TamMP )
	{
		MessageBox("El límite de espacio de memoria principal ha llegado a su límite.\nNo es posible agregar más datos");
		Ultimo();
		return;
	}
	
	Siguiente();
}

void CCache2003View::OnBAgregar() 
{
	// TODO: Add your control notification handler code here
	Agregar();
}

void CCache2003View::OnRadioEsc() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(true);
	m_iTipo = 2;
	m_iLectura = 1;
	UpdateData(false);	
	CambiaTipo();
 
/*
char buffer[5];
CString s_Tipo;
CString s_Lectura;
s_Lectura = _itoa( m_iLectura, buffer, 10);
MessageBox("radio_Lectura = " + s_Lectura);
  */
}

void CCache2003View::OnRadioLect() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(true);
	m_iTipo = 1;
	m_iLectura = 0;
	UpdateData(false); 
	CambiaTipo();
 
/*
char buffer[5];
CString s_Tipo;
CString s_Lectura;
s_Lectura = _itoa( m_iLectura, buffer, 10);
MessageBox("radio_Lectura = " + s_Lectura);
  */
}				



void CCache2003View::OnBEditar() 
{
	// TODO: Add your control notification handler code here
	Editar();
}

void CCache2003View::Editar()
{

GetDlgItem(IDC_DATOSDLG_DIRECCION) -> EnableWindow(FALSE);
GetDlgItem(IDC_DATOSDLG_DAT) -> EnableWindow(TRUE);

GetDlgItem(IDC_DATOSDLG_DIRECCION)->EnableWindow(TRUE);
GetDlgItem(IDC_B_PRIMERO)->EnableWindow(TRUE);
GetDlgItem(IDC_B_ANTERIOR)->EnableWindow(TRUE);
GetDlgItem(IDC_B_SIGUIENTE)->EnableWindow(TRUE);
GetDlgItem(IDC_B_ULTIMO)->EnableWindow(TRUE);

	
	char buffer[5];
	CString s_i;
	CString s_valor;
	
	int i_Dato;
	int i_Direccion;
	int n = m_nMP;
	int i;
	int respuesta; 

	CCache2003Doc *pDoc = GetDocument();
	i = pDoc->ObtenerCurRegistroNbr();

	CMenu *pMenu = GetParentFrame()->GetMenu();

	if( m_TamMP >= i)
	{

	

	i--;

	s_i = _itoa( i, buffer, 10);
	respuesta = AfxMessageBox("La dirección "+ s_i +" tiene un dato.\n¿Desea reemplazarlo?", MB_ICONINFORMATION | MB_OKCANCEL);
	switch(respuesta)
	{
	case IDOK:
	

		i_Direccion = atoi(m_sDireccion);
		i_Dato = atoi(m_sDato);
	
		CambiaDireccion();
	
		if( pMenu->GetMenuState(ID_FORMAT_DECIMAL, MF_BYCOMMAND) == MF_CHECKED)
		{

			//Formato Decimal
			m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,0),m_sDireccion);
			m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,1),m_sDato);
			//Formato Lectura Escritura
			switch(m_iTipo)
			{
				case 1:
					m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Lectura");
					m_nEscrituras--;
					UpdateData(false);

				break;
				case 2:
					m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Escritura");
					m_nEscrituras++;
					UpdateData(false);

				break;
			}

		
		
		}
	
	
		if( pMenu->GetMenuState(ID_FORMAT_BINARIO, MF_BYCOMMAND) == MF_CHECKED)
		{

		 		
			//Formato Binario
			m_CtrlRejilla_MP.SetTextArray(GenID(i +1,0),Bin(i_Direccion, n));
			m_CtrlRejilla_MP.SetTextArray(GenID(i +1,1),Bin(i_Dato , 16));
			//Formato Lectura Escritura
			switch(m_iTipo)
			{
				case 1:
					m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Lectura");
					m_nEscrituras--;
					UpdateData(false);

				break;
				case 2:
					m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Escritura");
					m_nEscrituras++;
					UpdateData(false);

				break;
			}

				 
		}

		if( pMenu->GetMenuState(ID_FORMAT_OCTAL, MF_BYCOMMAND) == MF_CHECKED)
		{
		
			//Formato Octal
			m_CtrlRejilla_MP.SetTextArray(GenID(i +1,0),Oct(i_Direccion));
			m_CtrlRejilla_MP.SetTextArray(GenID(i +1,1),Oct(i_Dato));
			m_CtrlRejilla_MP.SetColAlignment(0, 6);
			m_CtrlRejilla_MP.SetColAlignment(1, 6);
		
			//Formato Lectura Escritura
			switch(m_iTipo)
			{
				case 1:
					m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Lectura");
					m_nEscrituras--;
					UpdateData(false);

				break;
				case 2:
					m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Escritura");
					m_nEscrituras++;
					UpdateData(false);

				break;
			}

		
		}
	
		if( pMenu->GetMenuState(ID_FORMAT_HEXADECIMAL, MF_BYCOMMAND) == MF_CHECKED)
		{

		
			//Formato Hexadecimal
			m_CtrlRejilla_MP.SetTextArray(GenID(i +1,0),Hex(i_Direccion));
			m_CtrlRejilla_MP.SetTextArray(GenID(i +1,1),Hex(i_Dato));
			m_CtrlRejilla_MP.SetColAlignment(0, 6);
			m_CtrlRejilla_MP.SetColAlignment(1, 6);
		

			//Formato Lectura Escritura
			switch(m_iTipo)
			{
				case 1:
					m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Lectura");
					m_nEscrituras--;
				break;
				case 2:
					m_CtrlRejilla_MP.SetTextArray(GenID(i+1 ,2),"Escritura");
					m_nEscrituras++;
				break;
			}
		
		
		}

	

		if(pDoc)
		{
			DescargarObjetosDatos();
			//Se crea el nuevo objeto dato y se une al arreglo
			pDoc->EditarRegistros();
			
			
			if(m_pCurDatos)
			{
				
				//se le da los valores predeterminados
				m_pCurDatos->SetDireccion(m_sDireccion);
				m_pCurDatos->SetDato(m_sDato);
				m_pCurDatos->SetTipo(m_iTipo);
			
			//se piden los nuevos valores
				
				LlenarVista();
				
				i;
				pDoc->m_iPosicion = i;	
												
			}
			else
				MessageBox("No hay suficiente memoria");
				  }
   	      break;
	case IDCANCEL:
		   break;
  }//fin del switch

}//fin del primer if

else
{
	MessageBox("No hay espacio en la memoria principal");
} 

}

void CCache2003View::PosicionActual()
{
	CCache2003Doc *pDoc = GetDocument();
	m_pCurDatos = pDoc->ObtenerRegistroActual();
	LlenarVista();

}

void CCache2003View::OnBBuscar() 
{
	// TODO: Add your control notification handler code here
	
	CString dir, dat;
	CBuscarDlg m_dlgBuscar;
	
	dat = " ";
	if(m_dlgBuscar.DoModal() == IDOK)
	{
		dir = m_dlgBuscar.m_sDireccion;
		CCache2003Doc *pDoc = GetDocument();
		if(pDoc)
		{
			m_pCurDatos = pDoc->BuscarRegistro(dir);
			LlenarVista();
		}
	}

}

void CCache2003View::DescargarObjetosDatos()
{
	
	
	CCache2003Doc* pDoc = GetDocument(); 
	int pos = pDoc ->m_iPosicion;  
	
			   

/*
char buffer[5];
CString s_celda;
CString s_Tipo;
s_celda = _itoa( pos  , buffer, 10);
MessageBox(" Posicion = " + s_celda);
*/	
	
	if(pDoc)
	{
	  
		if( m_pCurDatos)
		{
			UpdateData(true);
			m_sDireccion = m_pCurDatos->GetDireccion();
			m_sDato = m_pCurDatos->GetDato();
			m_iTipo = m_pCurDatos->GetTipo();
			/*
			s_Tipo = _itoa(m_iTipo, buffer, 10);
			MessageBox("Dir :" + m_sDireccion);
			MessageBox("Dat : " + m_sDato);
			MessageBox( "Tipo : " + s_Tipo);  
			*/
			
			*(m_arrayDirMPPtr + pos) = atoi(m_sDireccion);
			*(m_arrayDatosMPPtr + pos ) = atoi(m_sDato);
			*(m_arrayTipoMPPtr + pos) = m_iTipo;
			UpdateData( false);
			
			
				 
		}

		
  	 }

}




void CCache2003View::ResetDatos()
{
	/*
	CCache2003Doc *pDoc = GetDocument();
	int total = pDoc->ObtenerTotalRegistros();

	
	for( int i = total; i>=0; i--)
	{
		pDoc->EliminarRegistros(i);
			
	}
	*/
	
	//Genera los tamaños de las memorias
	m_arrayDirMPPtr = new int[ m_TamMP ];
	m_arrayDatosMPPtr = new int[ m_TamMP ];
	m_arrayTipoMPPtr = new int[ m_TamMP ];
	
			
	//Creación de dirección y datos de Memoria Cache
	m_arrayDirMCPtr = new int[ m_TamMC ];
	m_arrayDatosMCPtr = new int[ m_TamMC ];
	m_arrayTipoMCPtr = new int[ m_TamMC ];
	for(int i= 0; i<m_TamMC; i++)
	{
		*(m_arrayDirMCPtr + i) = -1;
		*(m_arrayDatosMCPtr + i) = '\0';
		*(m_arrayTipoMCPtr + i) = '\0';	 
		
	}	
	
	  

	//Creación de arreglo de contadores para cada Linea
	m_contLineas = new int[ m_in_Bloques_MC ];
	m_contEdad = new int[ m_in_Bloques_MC ];
	m_contFrec = new int[ m_in_Bloques_MC ];
	
	for( i = 0; i<m_in_Bloques_MC; i++)
    {
		*(m_contLineas + i) = 0;
		*(m_contEdad + i) = 0;
		*(m_contFrec + i) = 0;
	}
   
	
	//Creación de arreglos de secuencias para simulación
	
	m_arrayDirSecMPPtr = new int[ m_inSec]; 
	m_arraySecMPPtr = new int[m_inSec ];
	
	for( i = 0; i<(m_inSec); i++)
    {
		*(m_arrayDirSecMPPtr + i) = 0;
		*(m_arraySecMPPtr + i) = 0;
		
	}
	
	
}	

void CCache2003View::LlenarVistaSec()
{
	CCache2003Doc* pDoc = GetDocument();
	if( pDoc)
	{
	
		m_sPosicionSec.Format("Registro %d de %d", pDoc->ObtenerCurSecuenciaNbr(), 
			pDoc->ObtenerTotalSecuencias());
	}

	if( m_pCurSecuencia)
	{
		m_sSecuencia = m_pCurSecuencia->GetSecuencia();
		m_sDirSecuencia = m_pCurSecuencia->GetDirSecuencia();
	
	}

	UpdateData( false);


}

void CCache2003View::PrimeroSec()
{
	CCache2003Doc *pDoc = GetDocument();
	if( pDoc)
	{
		m_pCurSecuencia = pDoc->ObtienePrimeroSec();
		if( m_pCurSecuencia )
		{
			LlenarVistaSec();
		}
	}

	//Validar botones Secuencia
	CambiaDirSecuencia();
	if(m_sDirSecuencia == "")
	{
	   GetDlgItem(IDC_B_AGREGAR_SEC) -> EnableWindow(TRUE);
	   GetDlgItem(IDC_B_EDITAR_SEC) -> EnableWindow(FALSE);

	}
	else
	{
	   GetDlgItem(IDC_B_AGREGAR_SEC) -> EnableWindow(FALSE);
	   GetDlgItem(IDC_B_EDITAR_SEC) -> EnableWindow(TRUE);

	}

}

void CCache2003View::AnteriorSec()
{
   	CCache2003Doc *pDoc = GetDocument();
	if( pDoc)
	{
		m_pCurSecuencia = pDoc->ObtieneAnteriorSec();
		if( m_pCurSecuencia )
		{
			LlenarVistaSec();
		}
	}

	CambiaDirSecuencia();
	if(m_sDirSecuencia == "")
	{
	   GetDlgItem(IDC_B_AGREGAR_SEC) -> EnableWindow(TRUE);
	   GetDlgItem(IDC_B_EDITAR_SEC) -> EnableWindow(FALSE);

	}
	else
	{
	   GetDlgItem(IDC_B_AGREGAR_SEC) -> EnableWindow(FALSE);
	   GetDlgItem(IDC_B_EDITAR_SEC) -> EnableWindow(TRUE);

	}


}

void CCache2003View::SiguienteSec()
{
	
	int totalReg;
	char buff[5];

	CCache2003Doc *pDoc = GetDocument();
	
	
	if( pDoc)
	{
		m_pCurSecuencia = pDoc->ObtieneSiguienteSec();
		if( m_pCurSecuencia )
		{
			LlenarVistaSec();
		}

		totalReg = pDoc->ObtenerTotalSecuencias();
		totalReg++;
	}

	//Validar botones Secuencia
	CambiaDirSecuencia();
	if(m_sDirSecuencia == "")
	{
	   GetDlgItem(IDC_B_AGREGAR_SEC) -> EnableWindow(TRUE);
	   GetDlgItem(IDC_B_EDITAR_SEC) -> EnableWindow(FALSE);
	   m_sSecuencia = _itoa( totalReg, buff, 10);
	   UpdateData(false);

	}
	else
	{
	   GetDlgItem(IDC_B_AGREGAR_SEC) -> EnableWindow(FALSE);
	   GetDlgItem(IDC_B_EDITAR_SEC) -> EnableWindow(TRUE);

	}


}

void CCache2003View::UltimoSec()
{
	
	CCache2003Doc *pDoc = GetDocument();
	int total;
	
	//Validación de último
	total = pDoc->ObtenerTotalSecuencias();
	if(total == 0)
	{
		MessageBox("No se ha programado ninguna secuencia.\nNo existen registros");
		return;
	}

	if( pDoc)
	{
		m_pCurSecuencia = pDoc->ObtieneUltimoSec();
		if( m_pCurSecuencia )
		{
			LlenarVistaSec();
		}
	}
	
	//Validar botones Secuencia
	CambiaDirSecuencia();
	if(m_sDirSecuencia == "")
	{
	   GetDlgItem(IDC_B_AGREGAR_SEC) -> EnableWindow(TRUE);
	   GetDlgItem(IDC_B_EDITAR_SEC) -> EnableWindow(FALSE);

	}
	else
	{
	   GetDlgItem(IDC_B_AGREGAR_SEC) -> EnableWindow(FALSE);
	   GetDlgItem(IDC_B_EDITAR_SEC) -> EnableWindow(TRUE);

	}


}


void CCache2003View::CambiaSecuencia()
{
   UpdateData(TRUE);
	if(m_pCurSecuencia)
		m_pCurSecuencia->SetSecuencia(m_sSecuencia);

	
	CCache2003Doc *pDoc = GetDocument();
	if(pDoc)
		pDoc->SetModifiedFlag();  
	
}

void CCache2003View::CambiaDirSecuencia()
{
   UpdateData(TRUE);
	if(m_pCurSecuencia)
		m_pCurSecuencia->SetDirSecuencia(m_sDirSecuencia);

	
	CCache2003Doc *pDoc = GetDocument();
	
	if(pDoc)
		pDoc->SetModifiedFlag();
	
}

void CCache2003View::PonerNuevoSec()
{
	PrimeroSec();
}
 

void CCache2003View::OnChangeEditSecuencia() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CambiaSecuencia();
}

void CCache2003View::OnChangeEditDirSec() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CambiaDirSecuencia();

}

void CCache2003View::OnBAgregarSec() 
{
	// TODO: Add your control notification handler code here
	AgregarSec();
}

void CCache2003View::AgregarSec()
{
	
GetDlgItem(IDC_EDIT_DIR_SEC)->EnableWindow(TRUE);

	
GetDlgItem(IDC_B_PRIMERO_SEC)->EnableWindow(TRUE);
GetDlgItem(IDC_B_ANTERIOR_SEC)->EnableWindow(TRUE);
GetDlgItem(IDC_B_SIGUIENTE_SEC)->EnableWindow(TRUE);
GetDlgItem(IDC_B_ULTIMO_SEC)->EnableWindow(TRUE);

   	char bufferSecuencia[10];	
	CString s_Sec;
	
	int i_Sec = m_iSec;
	int i_DirSecuencia;
	
	m_sSecuencia = _itoa( m_iSec, bufferSecuencia, 10);
	UpdateData(false);	
	
	i_DirSecuencia = atoi(m_sDirSecuencia);
	
	//Validaciones
	if((i_DirSecuencia >= m_TamMP) || (i_DirSecuencia < 0))
	{
		AfxMessageBox("ERROR. Fuera de rango.\nLa dirección introducida no se encuentra en la memoria principal.\nLa acción será cancelada.", MB_OK, MB_ICONSTOP);  
		m_sDirSecuencia = "";
		UpdateData(false);
		((CEdit *)GetDlgItem(IDC_EDIT_DIR_SEC))->SetFocus();
		return;

	}
	
	
	i_Sec++;
	
	s_Sec =  _itoa( i_Sec, bufferSecuencia, 10);

	
	 m_iSec++;
	 UpdateData(false),
	
		 CambiaSecuencia();	
	
	
	CCache2003Doc *pDoc = GetDocument();
	
	int total;
	total = pDoc->ObtenerTotalSecuencias();
	if( total >= m_inSec )
	{
		MessageBox("El límite de secuencias establecida ha llegado a su límite.\nNo es posible agregar más secuencias");
		UltimoSec();
		return;
	}
	
	if(pDoc)
	{
		
		DescargarObjetosSecuencia();
		//Se crea el nuevo objeto dato y se une al arreglo
		m_pCurSecuencia = pDoc->AgregarSecuencia();
		
		if(m_pCurSecuencia)
		{
			//se le da los valores predeterminados
			m_pCurSecuencia->SetSecuencia(s_Sec);
			m_pCurSecuencia->SetDirSecuencia("");
			
			
			//se piden los nuevos valores
			LlenarVistaSec();
			pDoc->SetModifiedFlag();

		}
	}
}

void CCache2003View::EditarSec()
{

GetDlgItem(IDC_EDIT_SECUENCIA) -> EnableWindow(FALSE);
GetDlgItem(IDC_EDIT_DIR_SEC) -> EnableWindow(TRUE);

GetDlgItem(IDC_B_PRIMERO_SEC)->EnableWindow(TRUE);
GetDlgItem(IDC_B_ANTERIOR_SEC)->EnableWindow(TRUE);
GetDlgItem(IDC_B_SIGUIENTE_SEC)->EnableWindow(TRUE);
GetDlgItem(IDC_B_ULTIMO_SEC)->EnableWindow(TRUE);


CCache2003Doc *pDoc = GetDocument();
	
int i = pDoc->ObtenerCurSecuenciaNbr();


int respuesta;

respuesta = AfxMessageBox("El número de secuencia "+ m_sSecuencia +" tiene una dirección de memoria.\n¿Desea reemplazarlo?", MB_ICONINFORMATION | MB_OKCANCEL);
switch(respuesta)
{
case IDOK:
	 

		if(pDoc)
		{
			DescargarObjetosSecuencia();
			//Se crea el nuevo objeto dato y se une al arreglo
			pDoc->EditarSecuencia();
			
			
			if(m_pCurSecuencia)
			{
				
				//se le da los valores predeterminados
				m_pCurSecuencia->SetSecuencia(m_sSecuencia);
				m_pCurSecuencia->SetDirSecuencia(m_sDirSecuencia);
							
			//se piden los nuevos valores
				
				LlenarVistaSec();
				i;
				pDoc->m_iPosicionSec = i;
				
			}
		}
    break;
case IDCANCEL:
	break;

}//fin del switch

}

void CCache2003View::PosicionActualSec()
{
	CCache2003Doc *pDoc = GetDocument();
	m_pCurSecuencia = pDoc->ObtenerSecuenciaActual();
	LlenarVistaSec();


}

void CCache2003View::OnBEditarSec() 
{
	// TODO: Add your control notification handler code here
	EditarSec();
}

void CCache2003View::OnBPrimeroSec() 
{
	// TODO: Add your control notification handler code here
	PrimeroSec();
}

void CCache2003View::OnBAnteriorSec() 
{
	// TODO: Add your control notification handler code here
	AnteriorSec();
}

void CCache2003View::OnBSiguienteSec() 
{
	// TODO: Add your control notification handler code here
	CCache2003Doc *pDoc = GetDocument();
	
	int actual;
	actual = pDoc->ObtenerCurSecuenciaNbr();
	if( actual >= m_inSec )
	{
		MessageBox("El límite de secuencias programadas ha llegado a su límite.\nNo es posible agregar más secuencias");
		UltimoSec();
		return;
	}

	SiguienteSec();
}

void CCache2003View::OnBUltimoSec() 
{
	// TODO: Add your control notification handler code here
	CCache2003Doc *pDoc = GetDocument();

	
	int actual;
	actual = pDoc->ObtenerCurSecuenciaNbr();
	if( actual >= m_inSec )
	{
		MessageBox("El límite de secuencias establecida ha llegado a su límite.\nNo es posible agregar más secuencias");
		UltimoSec();
		return;
	}

	
	UltimoSec();
}

void CCache2003View::Eliminar()
{
			
	   CCache2003Doc *pDoc = GetDocument();
	   pDoc->EliminarRegistros(pDoc->m_iPosicion);


}

void CCache2003View::PonerNuevoPar()
{
	 UltimoPar();
}

void CCache2003View::PrimeroPar()
{
	CCache2003Doc *pDoc = GetDocument();
	if( pDoc)
	{
		m_pCurParametro = pDoc->ObtienePrimeroPar();
		if( m_pCurParametro )
		{
			LlenarVistaPar();
		}
	}

}

void CCache2003View::LlenarVistaPar()
{
	if( m_pCurParametro)
	{
		m_nMP = m_pCurParametro->GetnMP();
		m_nMC = m_pCurParametro->GetnMC();
		m_nBloque = m_pCurParametro->GetnBloque();
		m_nVias = m_pCurParametro->GetnVias();
		m_iP_Emplazamiento = m_pCurParametro->GetP_Emplazamiento();
		m_iP_Reemplazamiento = m_pCurParametro->GetP_Reemplazamiento();
		m_TamMP = m_pCurParametro->GetTamMP();
		m_TamMC = m_pCurParametro->GetTamMC();
		m_TamBloque = m_pCurParametro->GetTamBloque();
		m_sMet_Emplaza = m_pCurParametro->GetMet_Emplaza();
		m_sMet_Reemplaza = m_pCurParametro->GetMet_Reemplaza();
		m_iTip_Esc = m_pCurParametro->GetTip_Esc();
		m_iAsignacion = m_pCurParametro->GetAsignacion();
		m_in_Bloques_MP = m_pCurParametro->GetnBloques_MP();
		m_in_Bloques_MC = m_pCurParametro->GetnBloques_MC();
		m_nBloqueConjunto = m_pCurParametro->GetnBloqueConjunto();
		
		m_fTc = m_pCurParametro->GetTc();
		m_fTp = m_pCurParametro->GetTp();
		m_iParalelo = m_pCurParametro->GetParalelo();
		m_iBasico = m_pCurParametro->GetBasico();
		m_iAutomatico_Sec = m_pCurParametro->GetAutomatico_Sec();
		m_iAutomatico = m_pCurParametro->GetAutomatico();
		m_inSec = m_pCurParametro->GetnSec();
		m_nEscrituras = m_pCurParametro->GetnEscrituras();
		UpdateData( false);


	}

	



}

void CCache2003View::AgregarPar()
{
	CambiaParametros();
	
	CCache2003Doc *pDoc = GetDocument();
		
	if(pDoc)
	{
		//Se crea el nuevo objeto dato y se une al arreglo
		m_pCurParametro = pDoc->AgregarParametros();
		if(m_pCurParametro)
		{
			//se le da los valores predeterminados
			m_pCurParametro->SetnMP(m_nMP);
			m_pCurParametro->SetnMC(m_nMC);
			m_pCurParametro->SetnBloque(m_nBloque);
			m_pCurParametro->SetnVias(m_nVias);
			m_pCurParametro->SetP_Emplazamiento(m_iP_Emplazamiento);
			m_pCurParametro->SetP_Reemplazamiento(m_iP_Reemplazamiento);
			m_pCurParametro->SetTamMP(m_TamMP);
			m_pCurParametro->SetTamMC(m_TamMC);
			m_pCurParametro->SetTamBloque(m_TamBloque);
			m_pCurParametro->SetMet_Emplaza(m_sMet_Emplaza);
			m_pCurParametro->SetMet_Reemplaza(m_sMet_Reemplaza);
			m_pCurParametro->SetAsignacion(m_iAsignacion);
			m_pCurParametro->SetTipo_Esc(m_iTip_Esc);
			m_pCurParametro->SetnBloques_MP(m_in_Bloques_MP);
			m_pCurParametro->SetnBloques_MC(m_in_Bloques_MC);
			m_pCurParametro->SetnBloqueConjunto(m_nBloqueConjunto);
			
			m_pCurParametro->SetTc(m_fTc);
			m_pCurParametro->SetTp(m_fTp);
			m_pCurParametro->SetParalelo(m_iParalelo);
			m_pCurParametro->SetBasico(m_iBasico);
			m_pCurParametro->SetAutomatico_Sec(m_iAutomatico_Sec);
			m_pCurParametro->SetAutomatico(m_iAutomatico);
			m_pCurParametro->SetnSec(m_inSec);
			m_pCurParametro->SetnEscrituras(m_nEscrituras);

			 		
			//se piden los nuevos valores
			LlenarVistaPar();
			UltimoPar();
			
		}
		else
			MessageBox("No hay suficiente memoria");
	}

}

void CCache2003View::CambiaParametros()
{
	UpdateData(TRUE);
	if(m_pCurParametro)
	{
		m_pCurParametro->SetnMP(m_nMP);
		m_pCurParametro->SetnMC(m_nMC);
		m_pCurParametro->SetnBloque(m_nBloque);
		m_pCurParametro->SetnVias(m_nVias);
		m_pCurParametro->SetP_Emplazamiento(m_iP_Emplazamiento);
		m_pCurParametro->SetP_Reemplazamiento(m_iP_Reemplazamiento);
		m_pCurParametro->SetTamMP(m_TamMP);
		m_pCurParametro->SetTamMC(m_TamMC);
		m_pCurParametro->SetTamBloque(m_TamBloque);
		m_pCurParametro->SetMet_Emplaza(m_sMet_Emplaza);
		m_pCurParametro->SetMet_Reemplaza(m_sMet_Reemplaza);
		m_pCurParametro->SetAsignacion(m_iAsignacion);
		m_pCurParametro->SetTipo_Esc(m_iTip_Esc);
		m_pCurParametro->SetnBloques_MP(m_in_Bloques_MP);
		m_pCurParametro->SetnBloques_MP(m_in_Bloques_MC);
		m_pCurParametro->SetnBloqueConjunto(m_nBloqueConjunto);
		

	}

	/*
	CCache2003Doc *pDoc = GetDocument();
	
	if(pDoc)
		pDoc->SetModifiedFlag();
	  */

}



void CCache2003View::OnConfiguracionSimulacion() 
{
	// TODO: Add your command handler code here
	CSimulacionDlg  dlgSimulacion;
		 	    
	dlgSimulacion.m_iAutomatico = m_iAutomatico; 
	dlgSimulacion.m_iAutomatico_Sec= m_iAutomatico_Sec;
	dlgSimulacion.m_inSec = m_inSec;
	UpdateData(false);

	

	
	
	if( dlgSimulacion.DoModal() == IDOK )
	{
		
			ResetDatos();
			LimpiarRejilla_MP();
			LimpiarRejilla_MC();
			LimpiarEdit();
			GetDlgItem(IDC_BTN_LLENAR_MP) -> EnableWindow(TRUE);
			GetDlgItem(IDC_SIMULAR) ->EnableWindow(FALSE);
			
			
			CCache2003Doc *pDoc = GetDocument();

			int total = pDoc->ObtenerTotalRegistros();

			for( int i = total; i>=0; i--)
			{
				pDoc->EliminarRegistros(i);
			}
			
			Primero();
			
			total = pDoc->ObtenerTotalSecuencias();
			
			for( i = total; i>=0; i--)
			{
				pDoc->EliminarSecuencia(i);
				
			}
			
			PrimeroSec();

			
		switch(dlgSimulacion.m_iAutomatico)
		{
			case 0:
				//MessageBox("Generación automatica de datos");
				GetDlgItem(IDC_DATOSDLG_DIRECCION)->EnableWindow(FALSE);
				GetDlgItem(IDC_DATOSDLG_DAT)->EnableWindow(TRUE);
				GetDlgItem(IDC_RADIO_LECT)->EnableWindow(TRUE);
				GetDlgItem(IDC_RADIO_ESC)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_AGREGAR)->EnableWindow(FALSE);
				GetDlgItem(IDC_B_EDITAR)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_BUSCAR)->EnableWindow(TRUE);
				GetDlgItem(IDC_STATIC_POSICION)->EnableWindow(FALSE);
				GetDlgItem(IDC_B_PRIMERO)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_ANTERIOR)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_SIGUIENTE)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_ULTIMO)->EnableWindow(TRUE);
				GetDlgItem(IDC_STATIC_DIR)->EnableWindow(TRUE);
				GetDlgItem(IDC_STATIC_DAT)->EnableWindow(TRUE);

				GetDlgItem(IDC_BTN_LLENAR_MP) -> EnableWindow(TRUE);
				GetDlgItem(IDC_SIMULAR) -> EnableWindow(FALSE);

			
			break;
			case 1:
				 //MessageBox("Introducción de datos manualmente");
				GetDlgItem(IDC_DATOSDLG_DIRECCION)->EnableWindow(FALSE);
				GetDlgItem(IDC_DATOSDLG_DAT)->EnableWindow(TRUE);
				GetDlgItem(IDC_RADIO_LECT)->EnableWindow(TRUE);
				GetDlgItem(IDC_RADIO_ESC)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_AGREGAR)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_EDITAR)->EnableWindow(FALSE);
				GetDlgItem(IDC_B_BUSCAR)->EnableWindow(TRUE);
				GetDlgItem(IDC_STATIC_POSICION)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_PRIMERO)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_ANTERIOR)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_SIGUIENTE)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_ULTIMO)->EnableWindow(TRUE);
				GetDlgItem(IDC_STATIC_DIR)->EnableWindow(TRUE);
				GetDlgItem(IDC_STATIC_DAT)->EnableWindow(TRUE);

				GetDlgItem(IDC_BTN_LLENAR_MP) -> EnableWindow(FALSE);
				GetDlgItem(IDC_SIMULAR) -> EnableWindow(TRUE);


			break;
		}

	   	 
	   switch(dlgSimulacion.m_iAutomatico_Sec)
	   {
			case 0:
				//MessageBox("Generación automatica de secuencias");
				GetDlgItem(IDC_EDIT_SECUENCIA)->EnableWindow(FALSE);
				GetDlgItem(IDC_EDIT_DIR_SEC)->EnableWindow(FALSE);
				GetDlgItem(IDC_B_AGREGAR_SEC)->EnableWindow(FALSE);
				GetDlgItem(IDC_B_EDITAR_SEC)->EnableWindow(FALSE);
				GetDlgItem(IDC_STATIC_REG_SEC)->EnableWindow(FALSE);
				GetDlgItem(IDC_B_PRIMERO_SEC)->EnableWindow(FALSE);
				GetDlgItem(IDC_B_ANTERIOR_SEC)->EnableWindow(FALSE);
				GetDlgItem(IDC_B_SIGUIENTE_SEC)->EnableWindow(FALSE);
				GetDlgItem(IDC_B_ULTIMO_SEC)->EnableWindow(FALSE);
				GetDlgItem(IDC_STATIC_SECUENCIA)->EnableWindow(FALSE);
				GetDlgItem(IDC_STATIC_DIR_SEC)->EnableWindow(FALSE);


			
			break;
			case 1:
				 //MessageBox("Introducción de secuencias manualmente");
				GetDlgItem(IDC_EDIT_SECUENCIA)->EnableWindow(FALSE);
				GetDlgItem(IDC_EDIT_DIR_SEC)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_AGREGAR_SEC)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_EDITAR_SEC)->EnableWindow(FALSE);
				GetDlgItem(IDC_STATIC_REG_SEC)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_PRIMERO_SEC)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_ANTERIOR_SEC)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_SIGUIENTE_SEC)->EnableWindow(TRUE);
				GetDlgItem(IDC_B_ULTIMO_SEC)->EnableWindow(TRUE);
				GetDlgItem(IDC_STATIC_SECUENCIA)->EnableWindow(TRUE);
				GetDlgItem(IDC_STATIC_DIR_SEC)->EnableWindow(TRUE);
				if( dlgSimulacion.m_inSec <= 0 )
				{
					MessageBox("El número de simulaciones debe ser mayor que cero");
					OnConfiguracionSimulacion();
					return;
				}



			break;
		}
	
		
	 m_iAutomatico = dlgSimulacion.m_iAutomatico; 
	 m_iAutomatico_Sec = dlgSimulacion.m_iAutomatico_Sec;
	 m_inSec = dlgSimulacion.m_inSec;
	 UpdateData(false);
	
	 ResetDatos();

	 
	}

}

void CCache2003View::DescargarObjetosSecuencia()
{
   CCache2003Doc* pDoc = GetDocument(); 
	int pos = pDoc ->m_iPosicionSec;  
	
	
/*

char buffer[5];
CString s_celda;
s_celda = _itoa( pos  , buffer, 10);
MessageBox(" Posicion = " + s_celda);
	
*/	
	if(pDoc)
	{
	  
		if( m_pCurSecuencia)
		{
			m_sSecuencia = m_pCurSecuencia->GetSecuencia();
			m_sDirSecuencia = m_pCurSecuencia->GetDirSecuencia();
			
			/*
			MessageBox(m_sDireccion);
			MessageBox(m_sDato);
			  */
			*(m_arraySecMPPtr + pos) = atoi(m_sSecuencia);
			*(m_arrayDirSecMPPtr + pos ) = atoi(m_sDirSecuencia);
			UpdateData( false);
			/*
			//Prueba
			 for(int i = 0; i<m_TamMP; i++)
			 {
				s_celda = _itoa( *(m_arrayDirMPPtr + i)  , buffer, 10);
				MessageBox("  Direcciones = " + s_celda);
				s_celda = _itoa( *(m_arrayDatosMPPtr + i)  , buffer, 10);
				MessageBox("  Datos= " + s_celda);
			 }
			  */
				 
		}

		
  	 }


}

void CCache2003View::LlenarObjetosSecuencia(int reg, int sec, int dirsec)
{
	char buffer[5];
	CString s_array_sec;
	CString s_array_dirsec;
	
	s_array_sec = _itoa( *(m_arraySecMPPtr + reg)  , buffer, 10);
	s_array_dirsec = _itoa( *(m_arrayDirSecMPPtr + reg)  , buffer, 10);
	

  	UpdateData(TRUE);
	if(m_pCurSecuencia)
		m_pCurSecuencia->SetSecuencia(s_array_sec);
		m_pCurSecuencia->SetDirSecuencia(s_array_dirsec);
			
	
	CCache2003Doc *pDoc = GetDocument();
		
	if(pDoc)
	{
		//Se crea el nuevo objeto dato y se une al arreglo
		m_pCurSecuencia = pDoc->AgregarSecuencia();
		if(m_pCurSecuencia)
		{
			//se le da los valores predeterminados
			m_pCurSecuencia->SetSecuencia("");
			m_pCurSecuencia->SetDirSecuencia("");
						
			//se piden los nuevos valores
			LlenarVistaSec();
			DescargarObjetosSecuencia();
		}
		else
			MessageBox("No hay suficiente memoria");
	}


}

void CCache2003View::LimpiarRejilla_MC()
{
	
	for( int i=0; i<m_TamMC; i++)
	{
		
		*(m_arrayDirMCPtr + i) = -1;
		*(m_arrayDatosMCPtr + i) = '\0';
		*(m_arrayTipoMCPtr + i) = '\0';	 

		m_CtrlRejilla_MC.SetTextArray(GenID(i+1 ,0),"");
		m_CtrlRejilla_MC.SetTextArray(GenID(i+1 ,1),"");
		m_CtrlRejilla_MC.SetTextArray(GenID(i+1 ,2),"");
		m_CtrlRejilla_MC.SetTextArray(GenID(i+1 ,3),"");
		m_CtrlRejilla_MC.SetTextArray(GenID(i+1 ,4),"");
		m_CtrlRejilla_MC.SetTextArray(GenID(i+1 ,5),"");

		ColorearMC(i+1, 0, 0x00000000, 0x00000000);
		ColorearMC(i+1, 1, 0x00000000, 0x00000000);
		ColorearMC(i+1, 2, 0x00000000, 0x00000000);
		ColorearMC(i+1, 3, 0x00000000, 0x00000000);
		ColorearMC(i+1, 4, 0x00000000, 0x00000000);
		ColorearMC(i+1, 5, 0x00000000, 0x00000000);
		
	
	}
	
	for( i = 0; i<m_in_Bloques_MC; i++)
	{
		      *(m_contLineas + i) = 0;
			  *(m_contEdad + i) = 0;
		      *(m_contFrec + i) = 0;
	}
}

void CCache2003View::UltimoPar()
{
	CCache2003Doc *pDoc = GetDocument();
	if( pDoc)
	{
		m_pCurParametro = pDoc->ObtieneUltimoPar();
		if( m_pCurParametro )
		{
			LlenarVistaPar();
		}
	}

}

void CCache2003View::LimpiarEdit()
{
	//m_nMP = 0;
	//m_nMC = 0;
	//m_nBloque = 0;
	//m_nVias = "2";
	//m_iP_Emplazamiento = 1;
	//m_iP_Reemplazamiento = 0;
	m_Dato = _T("");
	m_NPalabra = _T("");
	m_NBloque = _T("");
	m_NLinea = _T("");
	m_TamConjunto = 0;
	m_NPalabraBloque = _T("");
	m_PalabraConjunto = 0;
	//m_TamMP = 0;
	//m_TamBloque = 0;
	//m_TamMC = 0;
	m_contAciertos = 0;
	m_contFallos = 0;
	m_nSim = 0;
	//m_in_Bloques_MC = 0;
	//m_in_Bloques_MP = 0;
	m_iw = 0;
	m_ini_Linea = -1;
	m_bChk_LectEsc = FALSE;
	m_bChk_Cont = FALSE;
	//m_nBloqueConjunto = 0;
	m_NConjunto = _T("");
	m_nLineaConjunto = _T("");
	m_bChk_Edad = FALSE;
	m_bChk_Frec = FALSE;
	//m_sMet_Emplaza = _T("");
	//m_sMet_Reemplaza = _T("");
	//m_iTip_Esc = 0;
	//m_iAsignacion = 0;
	m_Dato_Escrito = _T("");
	m_iTipo_Dato = 0;
	m_sTipo = _T("");
	m_sDireccion = "0";
	m_sDato = _T("");
	m_iTipo = 1;
	m_sPosicion = _T("");
	m_iReg = 0;
	m_iLectura = 0;
	m_sSecuencia = "1";
	m_sDirSecuencia = _T("");
	m_sPosicionSec = _T("");
	m_iSec = 1;
	//m_iAutomatico_Sec = 0;
	//m_iAutomatico = 0;
	//m_inSec = 0;

	m_ppMP = NULL; 
	m_arrayDatosMPPtr =NULL;
	m_arrayDirMPPtr = NULL;
	m_arrayDatosMCPtr =NULL;
	m_arrayDirMCPtr = NULL;
	m_arrayTipoMPPtr =NULL;
	m_arrayTipoMCPtr = NULL;
	
	m_nEscrituras = 0;
	m_iBasico = 0;
	m_iParalelo = 0;
	m_fTc = 0.0f;
	m_fTp = 0.0f;
	m_fTa = 0.0f;

	UpdateData(false);
}

void CCache2003View::GeneraTamMP()
{
   CMemoriasDlg dlgMemorias;
   CPoliticasDlg dlgPoliticas;	
	
    
	dlgMemorias.m_inMP = m_nMP; 
	dlgMemorias.m_inMC = m_nMC;
	dlgMemorias.m_inBloque = m_nBloque;
	dlgMemorias.m_lBytesTamMP = m_TamMP;
	dlgMemorias.m_lBytesTamMC = m_TamMC;
	dlgMemorias.m_lBytesTamBloque = m_TamBloque;
	dlgPoliticas.m_iPDirecto = m_iP_Emplazamiento;	
	dlgPoliticas.m_iPAleatorio = m_iP_Reemplazamiento; 
	dlgPoliticas.m_snVias = m_nVias;
	

	UpdateData(false);
	
	

		for(int i = 0; i<= m_dlgDireccion.m_inEtiquetas; i++)
		{
			delete m_dlgDireccion.m_pEtiquetas;
			m_dlgDireccion.m_pEtiquetas = NULL;
		}
		for( i = 0; i<=m_dlgDireccion.m_inLineas; i++)
		{
			delete m_dlgDireccion.m_pLineas;
			m_dlgDireccion.m_pLineas = NULL;
		}
		for( i = 0; i<= m_dlgDireccion.m_inPalabras; i++)
		{
			delete m_dlgDireccion.m_pPalabras;
			m_dlgDireccion.m_pPalabras = NULL;
		}
		for( i = 0; i<=m_dlgDireccion.m_inConjuntos; i++)
		{
			delete m_dlgDireccion.m_pConjuntos;
			m_dlgDireccion.m_pConjuntos = NULL;
		}
		for( i = 0; i<=m_dlgDireccion.m_iTotalBits; i++)
		{
			delete m_dlgDireccion.m_pnBits;
			m_dlgDireccion.m_pnBits = NULL;
		}
		
		
		
		//UpdateData(true);
		m_TamMP = dlgMemorias.m_lBytesTamMP;
		m_TamMC = dlgMemorias.m_lBytesTamMC;
		m_TamBloque = dlgMemorias.m_lBytesTamBloque;
		m_nMP = dlgMemorias.m_inMP;
		m_nMC = dlgMemorias.m_inMC;
		m_nBloque = dlgMemorias.m_inBloque;
		
		UpdateData(false);

			//Control de Excepción división entre cero
			TRY
			{
				if((m_nBloque == 0) || (m_nMP == 0) || (m_nMC == 0))
				{
					AfxThrowUserException();
				}

				UpdateData(true);
				m_in_Bloques_MP = m_TamMP/m_TamBloque;
				m_in_Bloques_MC = m_TamMC/m_TamBloque;
				UpdateData(false);
			}
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los tamaños de memoria introducidos no son válidos para la simulación.\nLos tamaños deben ser mayores que cero");
				OnConfiguracionMemorias();
			}
			
			END_CATCH
			
			//Control de Excepción Tamaños no apropiados
			TRY
			{
				if((m_nBloque > m_nMC) || (m_nMC > m_nMP))
				{
					AfxThrowUserException();
				}

				
			}
			CATCH(CUserException, e )
			{
				AfxMessageBox("ERROR: Los tamaños de memoria introducidos no son válidos para la simulación.\nPOSIBLES CAUSAS :\n1. El tamaño del Memoria Cache es mayor que el de Memoria Principal.\n2. El tamaño del Memoria Cache es mayor que el de Memoria Principal.");
				OnConfiguracionMemorias();
			}
			
			END_CATCH
			



		//Se actualizan los tamaños de los controles Active X
		TamCeldasNoFijas(m_TamMP, 6);
		TamCeldasNoFijas_MC(m_TamMC, 6);	
		//Columnas con ancho nulo 
	    m_CtrlRejilla_MP.SetColWidth(2, 0);
	    m_CtrlRejilla_MP.SetColWidth(3, 0);
		m_CtrlRejilla_MP.SetColWidth(4, 0);
		m_CtrlRejilla_MP.SetColWidth(5, 0);
		
		m_CtrlRejilla_MC.SetColWidth(2, 0);
		m_CtrlRejilla_MC.SetColWidth(3, 0);
		m_CtrlRejilla_MC.SetColWidth(4, 0);
		m_CtrlRejilla_MC.SetColWidth(5, 0);
		
		
		
		ResetDatos();
		
		
		switch(dlgPoliticas.m_iPDirecto)
		{
		case 0:
			//MessageBox("Opción Directo");
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.Parche();
			m_dlgDireccion.DirDirecto( dlgMemorias.m_inMP, dlgMemorias.m_inMC, dlgMemorias.m_inBloque );
			m_dlgDireccion.UpdateData(false);
			m_dlgDireccion.OnChangeDEtiqueta();
			m_dlgDireccion.OnChangeDLinea();
			m_dlgDireccion.OnChangeDPalabra();
			m_dlgDireccion.OnChangeDTotalBits();		
			
			m_iP_Emplazamiento = dlgPoliticas.m_iPDirecto;
			m_sMet_Emplaza = "Directo";
			m_sMet_Reemplaza = "";
			UpdateData(false);

			UpdateData(false);
			break;
		
		case 1:
			//MessageBox("Opcion Asociativo");
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.Parche();
			m_dlgDireccion.DirAsociativo( dlgMemorias.m_inMP, dlgMemorias.m_inMC, dlgMemorias.m_inBloque );
			m_dlgDireccion.UpdateData(false);
			m_dlgDireccion.OnChangeDEtiqueta();
			m_dlgDireccion.OnChangeDLinea();
			m_dlgDireccion.OnChangeDPalabra();
			m_dlgDireccion.OnChangeDTotalBits();	
			
			m_iP_Emplazamiento = dlgPoliticas.m_iPDirecto;
			m_sMet_Emplaza = "Asociativo";

			UpdateData(false);
			break;

		case 2:
			//MessageBox("Opcion Asociativo por Conjuntos");
			m_dlgDireccion.UpdateData(true);
			m_dlgDireccion.Parche();
			m_dlgDireccion.DirAConjuntos( dlgMemorias.m_inMP, dlgMemorias.m_inMC, dlgMemorias.m_inBloque, dlgPoliticas.m_snVias );
			m_dlgDireccion.UpdateData(false);
			m_dlgDireccion.OnChangeDEtiqueta();
			m_dlgDireccion.OnChangeDLinea();
			m_dlgDireccion.OnChangeDPalabra();
			m_dlgDireccion.OnChangeDTotalBits();		
			
			m_iP_Emplazamiento = dlgPoliticas.m_iPDirecto;
			m_nVias = dlgPoliticas.m_snVias;
			m_sMet_Emplaza = "Asociativo por Conjuntos";
			UpdateData(false);
			
			ColorearConjuntos(m_TamMC, m_TamBloque, m_nVias);
			break;
		
		default :
			MessageBox("ERROR.Opción no válida");
			break;
		
		 
		}
	
		
		switch(dlgPoliticas.m_iPAleatorio)
		{
		case 0:
						
			//MessageBox("Opción Aleatorio");
			
			m_iP_Reemplazamiento = dlgPoliticas.m_iPAleatorio;
			m_sMet_Reemplaza = "Aleatorio";
			UpdateData(false);
			break;
		  
		case 1:
			
				
			//MessageBox("Opcion Ultimo Reciente Usado");
			
			m_iP_Reemplazamiento = dlgPoliticas.m_iPAleatorio;
			m_sMet_Reemplaza = "LRU";
			UpdateData(false);
			break;
		  
		case 2:
			
			//MessageBox("Opcion Ultimo Frecuente Usado");
			
			m_iP_Reemplazamiento = dlgPoliticas.m_iPAleatorio;
			m_sMet_Reemplaza = "LFU";
			UpdateData(false);
			break;
		  
		case 3:
			
			//MessageBox("Opcion Primero Entra Primero Sale");
			
			m_iP_Reemplazamiento = dlgPoliticas.m_iPAleatorio;
			m_sMet_Reemplaza = "FIFO";
			UpdateData(false);
			break;
		
		default :
			//MessageBox("ERROR.Opción no válida");
			m_sMet_Reemplaza = " ";
			UpdateData(false);
			break;
		
		} 

		



}

void CCache2003View::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GetDocument()->IsModified());
}

void CCache2003View::PrintPageHeader(CDC *pDC)
{
	CString str;

    CPoint point(0, 0);
	pDC->TextOut(point.x, point.y, "Información Memoria Principal" );
	point += CSize(720, -720);
	str.Format("%6.6s %16.6s %20.6s %12.6s",
	           "Registro", "Direc.", "Datos", "Tipo");
    pDC->TextOut(point.x, point.y, str);


}

void CCache2003View::PrintPageFooter(CDC *pDC)
{
    CString str;

	CPoint point(0, -14400); // Se mueve 10 pulgadas hacia abajo
    CCache2003Doc* pDoc = GetDocument();
	str.Format("Documento %s", (LPCSTR) pDoc->GetTitle());
	pDC->TextOut(point.x, point.y, str);
	str.Format("Pág. %d", m_nPage);
	CSize size = pDC->GetTextExtent(str);
	point.x += 11000 - size.cx;
	pDC->TextOut(point.x, point.y, str); // alineado a la derecha
	CPoint point1(0, -14000);
	str.Format("Tipo : 0- Lectura     1- Escritura");
	pDC->TextOut(point1.x, point1.y, str);

}

void CCache2003View::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	pDC->SetMapMode(MM_LOENGLISH);

	//CFormView::OnPrepareDC(pDC, pInfo);
}

void CCache2003View::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
	/*
	int espaciado, i, j;

	CCache2003Doc* pDoc = GetDocument();
	
	j = pDoc->m_arregloDatos.GetUpperBound();
	
	if( pDoc )
	{
		pDoc->ObtienePrimero();

		for (i = 0; i < j; i++) 
		{
			if (i > pDoc->m_arregloDatos.GetUpperBound()) 
			{
				break;
			}
        
			LlenarVista();

			pDC->TextOut(500, espaciado+400,"DIRECCION    DATOS/INST     TIPO ");
			pDC->TextOut(500,espaciado+600, m_sDireccion);
			pDC->TextOut(500,espaciado+700, m_sDato);
			if( m_iTipo == 1)
			{
				pDC->TextOut(500,espaciado+800, "Lectura");
			}
			else
			{
				pDC->TextOut(500, espaciado+800, "Escritura");
			}

			espaciado = espaciado + 400;
			m_pCurDatos = pDoc->ObtieneSiguiente();

	    }
	}
	*/
}

void CCache2003View::LlenarMP_OpenDoc()
{
	if(m_TamMP > 0)
	{
		GetDlgItem(IDC_STATIC_POSICION) -> EnableWindow(TRUE);
		GetDlgItem(IDC_B_PRIMERO) -> EnableWindow(TRUE);
		GetDlgItem(IDC_B_ANTERIOR) -> EnableWindow(TRUE);
		GetDlgItem(IDC_B_SIGUIENTE) -> EnableWindow(TRUE);
		GetDlgItem(IDC_B_ULTIMO) -> EnableWindow(TRUE);
		GetDlgItem(IDC_DATOSDLG_DAT) -> EnableWindow(TRUE);	
		GetDlgItem(IDC_SIMULAR) -> EnableWindow(TRUE);	
		GetDlgItem(IDC_B_AGREGAR) ->EnableWindow(FALSE);

	}
	else
	{
		GetDlgItem(IDC_SIMULAR) -> EnableWindow(FALSE);
	}
	
	
	
	
	
	CCache2003Doc *pDoc = GetDocument();
	
	int total = pDoc->ObtenerTotalRegistros();


	AgregarPar();

	
	CWaitCursor CursorRelojDeArena;	
	m_CtrlRejilla_MP.SetColWidth(2, 0);
	m_CtrlRejilla_MC.SetColWidth(2, 0);
	
	
	
	srand( time(0) );
	
		
	m_arrayDatosMPPtr = new int[ m_TamMP];
	m_arrayDirMPPtr = new int[ m_TamMP ];
	m_arrayTipoMPPtr = new int[ m_TamMP ];
	
	

	for(int i = 0 ; i< m_TamMP; i++)
	{	
	 	
			
		*(m_arrayDatosMPPtr + i  )= atoi(m_sDato);
		*(m_arrayDirMPPtr + i ) = atoi(m_sDireccion);
		*(m_arrayTipoMPPtr + i  )= m_iTipo;
		 m_iReg++;

		Siguiente();
		
	}					

		
	
	
	Primero(); 
	

	ImprimeFormatoMP(m_nMP, m_TamMP, m_arrayDirMPPtr, m_arrayDatosMPPtr, m_arrayTipoMPPtr);
	
	//Creación de dirección y datos de Memoria Cache
	m_arrayDirMCPtr = new int[ m_TamMC ];
	m_arrayDatosMCPtr = new int[ m_TamMC ];
	m_arrayTipoMCPtr = new int[ m_TamMC ];
	for(i= 0; i<m_TamMC; i++)
	{
		*(m_arrayDirMCPtr + i) = -1;
		*(m_arrayDatosMCPtr + i) = '\0';
		*(m_arrayTipoMCPtr + i) = '\0';
	}	
	
	  

	//Creación de arreglo de contadores para cada Linea
	m_contLineas = new int[ m_in_Bloques_MC ];
	m_contEdad = new int[ m_in_Bloques_MC ];
	m_contFrec = new int[ m_in_Bloques_MC ];
	
	for( i = 0; i<m_in_Bloques_MC; i++)
    {
		*(m_contLineas + i) = 0;
		*(m_contEdad + i) = 0;
		*(m_contFrec + i) = 0;
	}

	
	
	//Creación de arreglos de secuencias para simulación
	PrimeroSec();
	m_arrayDirSecMPPtr = new int[ m_inSec]; 
	m_arraySecMPPtr = new int[m_inSec];
	
	for( i = 0; i<(m_inSec); i++)
    {
		*(m_arraySecMPPtr + i  )= atoi(m_sSecuencia);
		*(m_arrayDirSecMPPtr + i ) = atoi(m_sDirSecuencia);
		SiguienteSec();
	
	}

	PrimeroSec();

}


void CCache2003View::PrintSec()
{
   	int espacio = 0;
	int numSec = 1;
	CCache2003Doc *pDoc = GetDocument();
	
	CPrintDialog dlgPrint(FALSE,PD_ALLPAGES,this);

	if(dlgPrint.DoModal()==IDOK)
	{
		CDC dcPrint;
		dcPrint.Attach(dlgPrint.GetPrinterDC());
		DOCINFO myPrintJob;
		myPrintJob.cbSize=sizeof(myPrintJob);
		myPrintJob.lpszDocName="myPrintJob";
		myPrintJob.lpszOutput=NULL;
		myPrintJob.lpszDatatype=NULL;
		myPrintJob.fwType=NULL;
		if(dcPrint.StartDoc(&myPrintJob)>=0)
		{
			
			dcPrint.StartPage();
			
			if(pDoc)
			{
				m_pCurSecuencia = pDoc->ObtienePrimeroSec();
		    
				for(int i=0;i<(pDoc->ObtenerTotalSecuencias());i++)
				{
					
					LlenarVistaSec();
					 
					
					if( espacio <= 5800)
					{
											
						if( (numSec >= 0) && (numSec <=50))
						{	
							if( numSec == 1)
							{
								espacio = 0;
								dcPrint.TextOut(500, espacio + 500, "Secuencia");
								dcPrint.TextOut(1000, espacio + 500, "Dirección");
								dcPrint.TextOut(500, espacio + 300, "Informe de Secuencias Programadas");
								dcPrint.TextOut(500, espacio + 6000, "Documento " + pDoc->GetTitle());
							}
							
							dcPrint.TextOut(500,espacio+700, m_sSecuencia);
							dcPrint.TextOut(1000,espacio+700, m_sDirSecuencia);
							espacio = espacio+100;
							m_pCurSecuencia = pDoc->ObtieneSiguienteSec();
						}
						if( (numSec >50) && (numSec <= 100))
						{
							if(numSec == 51)
							{
								espacio = 0;
								dcPrint.TextOut(2000, espacio + 500, "Dirección");
								dcPrint.TextOut(2500, espacio + 500, "Secuencia");

							}
							dcPrint.TextOut(2000,espacio+700, m_sSecuencia);
							dcPrint.TextOut(2500,espacio+700, m_sDirSecuencia);
							espacio = espacio+100;
							m_pCurSecuencia = pDoc->ObtieneSiguienteSec();
						}
						if( (numSec > 100) && (numSec <=150))
						{
							if(numSec == 101)
							{
								espacio = 0;
								dcPrint.TextOut(3500, espacio + 500, "Dirección");
								dcPrint.TextOut(4000, espacio + 500, "Secuencia");

							}
							dcPrint.TextOut(3500,espacio+700, m_sSecuencia);
							dcPrint.TextOut(4000,espacio+700, m_sDirSecuencia);
							espacio = espacio+100;
							m_pCurSecuencia = pDoc->ObtieneSiguienteSec();
						}
						
						numSec++;


					}
				}//fin de for
			}//fin de pDoc
			
			dcPrint.EndPage();
			dcPrint.EndDoc();
		}
	
		dcPrint.DeleteDC();
	}
	

}

void CCache2003View::OnFilePrintSec() 
{
	// TODO: Add your command handler code here
	PrintSec();
}

void CCache2003View::CalculoTa()
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
			
	
	dlgTiempos.m_iParalelo = m_iParalelo; 
	dlgTiempos.m_iBasica = m_iBasico;
	dlgTiempos.m_fTp = m_fTp;
	dlgTiempos.m_fTc = m_fTc;
	dlgEscritura.m_iEsc_Directa = m_iTip_Esc;	
	dlgEscritura.m_iCon_Asignacion = m_iAsignacion; 
	UpdateData(false);

	Tacceso = m_contAciertos*m_fTc + m_contFallos*m_fTp;
	Tpenalizacion = m_fTp;
	
	if( m_nSim>0)
	{
			Porcentaje_Esc = (float)m_nEscrituras/m_TamMP;
			Porcentaje_Lect = (1- Porcentaje_Esc);
			Prob_modificado = (float)1/m_in_Bloques_MP;
			TasaFallo =  (float)m_contFallos/m_nSim;
			TasaAcierto = (float)m_contAciertos/m_nSim;
	}


	
	
	   switch(dlgTiempos.m_iBasica)
	   {
	   case 0:
		   if(dlgTiempos.m_iParalelo == 0)
		   {
			   Tacierto = TasaAcierto*m_fTc;	
			   m_fTa = Tacierto + TasaFallo*Tpenalizacion;
		   	   UpdateData(false);
			   
		   }
	   	   else
		   {
			   Tacierto = m_fTc;
			   m_fTa = Tacierto + TasaFallo*Tpenalizacion;
		   	   UpdateData(false);
		   }
	   break;   
	   case 1:
		   
		   
		   if(dlgTiempos.m_iParalelo == 0)
		   {
			   Tacierto = TasaAcierto*m_fTc;
			   
			   switch(dlgEscritura.m_iEsc_Directa)
			   {
			   case 0:
				   if(dlgEscritura.m_iCon_Asignacion == 0)
				   {
					   //Con asignación en escritura
					   m_fTa = Tacierto + TasaFallo*Tpenalizacion + Porcentaje_Esc*(m_fTp - m_fTc);
				   	   UpdateData(false);
				   }
				   else
				   {
					   //Sin asignación en escritura
					  m_fTa = Tacierto + TasaFallo*Tpenalizacion + Porcentaje_Lect*(m_fTp- m_fTc);
				      UpdateData(false);
				   }	 
				break;
			   case 1:
					  m_fTa = Tacierto + TasaFallo*Tpenalizacion + Prob_modificado*TasaFallo*Tpenalizacion;
					  UpdateData(false);
				break;
			   } //fin del switch
		   } //fin del if
		   else
		   {
			   Tacierto = m_fTc;

		   	   switch(dlgEscritura.m_iEsc_Directa)
			   {
			   case 0:
				   if(dlgEscritura.m_iCon_Asignacion == 0)
				   {
					   //Con asignación en escritura
					   m_fTa = Tacierto + TasaFallo*Tpenalizacion + Porcentaje_Esc*(m_fTp - m_fTc);
				   	   UpdateData(false);
				   }
				   else
				   {
					   //Sin asignación en escritura
					  m_fTa = Tacierto + TasaFallo*Tpenalizacion + Porcentaje_Lect*(m_fTp- m_fTc);
				      UpdateData(false);
				   }	 
				break;
			   case 1:
					  m_fTa = Tacierto + TasaFallo*Tpenalizacion + Prob_modificado*TasaFallo*Tpenalizacion;
					  UpdateData(false);
				break;
			   }//fin del switch
		   		   
		   }//fin del else

		   break;
	   }//fin del switch m_Basica
	
	m_iParalelo = dlgTiempos.m_iParalelo; 
	m_iBasico = dlgTiempos.m_iBasica;
	m_fTp = dlgTiempos.m_fTp;
	m_fTc = dlgTiempos.m_fTc; 
	m_iTip_Esc = dlgEscritura.m_iEsc_Directa;	
	m_iAsignacion = dlgEscritura.m_iCon_Asignacion; 
	UpdateData(false);


}

void CCache2003View::ActualizarEscrituras(int nEsc, int nBloques, int tamMP, int formula, int transf, float tp, float tc, int tipo, int asignacion)
{
	UpdateData( true);
	m_dlgEstadisticas.m_nEscrituras = nEsc;
	m_dlgEstadisticas.m_in_Bloques_MP = nBloques;
	m_dlgEstadisticas.m_Tam_MP = tamMP;
	m_dlgEstadisticas.m_iBasico = formula;
	m_dlgEstadisticas.m_iParalelo = transf;
	m_dlgEstadisticas.m_fTp = tp;
	m_dlgEstadisticas.m_fTc = tc;
	m_dlgEstadisticas.m_iTip_Esc = tipo;
	m_dlgEstadisticas.m_iAsignacion = asignacion;
	UpdateData( false);
}


HBRUSH CCache2003View::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
		//Color de las etiquetas Static
/*	
	if( nCtlColor == CTLCOLOR_STATIC )
	{
		pDC->SetBkColor(m_colorMarcos);
		pDC->SetTextColor( m_colorTexto);
		return (HBRUSH)m_pincelMarcos.GetSafeHandle();
	}
	
	*/
	//Color de los controles edit fijos
	



	if( pWnd->GetDlgCtrlID() == IDC_STATIC_FILAS)
	{
		//pDC->SetBkColor(m_colorMarcos);
		pDC->SetTextColor(m_colorTextos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_N_BLOQUES)
	{
		//pDC->SetBkColor(m_colorMarcos);
		pDC->SetTextColor(m_colorTextos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_N_CONJUNTOS)
	{
		//pDC->SetBkColor(m_colorMarcos);
		pDC->SetTextColor(m_colorTextos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_UBICACIONES)
	{
		//pDC->SetBkColor(m_colorMarcos);
		pDC->SetTextColor(m_colorTextos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_EDICION)
	{
		//pDC->SetBkColor(m_colorMarcos);
		pDC->SetTextColor(m_colorTextos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_SECUENCIAS)
	{
		//pDC->SetBkColor(m_colorMarcos);
		pDC->SetTextColor(m_colorTextos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_DATOS_SIMULACION)
	{
		//pDC->SetBkColor(m_colorMarcos);
		pDC->SetTextColor(m_colorTextos);
		//return (HBRUSH)m_pincelMarcos.GetSafeHandle();
	}
	
	

	if( pWnd->GetDlgCtrlID() == IDC_EDIT_COLOR_VERDE)
	{
		pDC->SetBkColor(m_colorAcierto);
		return (HBRUSH)m_pincelAcierto.GetSafeHandle();
	}
	
	
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_COLOR_ROJO)
	{
		pDC->SetBkColor(m_colorFallo);
		return (HBRUSH)m_pincelFallo.GetSafeHandle();
	}
	

	if( pWnd->GetDlgCtrlID() == IDC_MC)
	{
		pDC->SetTextColor(m_colorMarcos);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_MP)
	{
		pDC->SetTextColor(m_colorMarcos);
		
	}
	
	

 	 
	
	//Colorea los textos de los static
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_MP)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_MC)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_BLQ)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_PALABRAS_CONJ)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_MP2)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_MC2)
	{
		pDC->SetTextColor(m_colorTextoStatic);
	}
	
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_N_BLOQUES_CONJ)
	{
		pDC->SetTextColor(m_colorTextoStatic);
	}
				
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_N_CONJ)
	{
		pDC->SetTextColor(m_colorTextoStatic);
	}
		
	  
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_DATO)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_DATO_MC)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_SIMULACIONES)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_ACIERTOS)
	{
		pDC->SetTextColor(m_colorAcierto);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_FALLOS)
	{
		pDC->SetTextColor(m_colorFallo);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_PALABRA)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_PALABRA_BLOQUE)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}

	if( pWnd->GetDlgCtrlID() == IDC_STATIC_BLOQUE)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_LINEA)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_CONJ_MC)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_LINEA_CONJ)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_NS)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_TA)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_EMPLAZA)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_STATIC_REEMPLAZA)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}

	
   	/*
	
	 //Colorea los check
	if( pWnd->GetDlgCtrlID() == IDC_CHECK_L_E)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_CHECK_CONT)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_CHECK_EDAD)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_CHECK_FREC)
	{
		pDC->SetTextColor(m_colorTextoStatic);
		
	}

  	*/
	/*
	//Colorea botones
	if( pWnd->GetDlgCtrlID() == IDC_BTN_LLENAR_MP)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_SIMULAR)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	
	  */

	
	//Colorea los textos de los edit
	if( pWnd->GetDlgCtrlID() == IDC_N_FILAS_MP)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_N_FILAS_MC)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_N_FILAS_BLOQUE)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_PALABRAS_CONJ)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_BLOQUES_MP)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_BLOQUES_MC)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_N_BLOQUES_CONJ)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}

	if( pWnd->GetDlgCtrlID() == IDC_EDIT_N_CONJ)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	


	if( pWnd->GetDlgCtrlID() == IDC_EDIT_DATO)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_DATO_MC)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_SIMULACIONES)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_ACIERTOS)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_FALLOS)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_PALABRA)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_PALABRA_BLOQUE)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}

	if( pWnd->GetDlgCtrlID() == IDC_EDIT_BLOQUE)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_LINEA)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_CONJ)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	} 
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_N_LINEAS)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_TIPO)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_TA)
	{
		pDC->SetTextColor(m_colorTextoEdit);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_MET_EMPLAZA)
	{
		pDC->SetTextColor(m_colorMarcos);
		
	}
	if( pWnd->GetDlgCtrlID() == IDC_EDIT_MET_REEMPLAZA)
	{
		pDC->SetTextColor(m_colorMarcos);
		
	}
	 
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CCache2003View::OnSimbologia() 
{
	// TODO: Add your command handler code here
	m_dlgColores.ShowWindow( SW_SHOW );

}


void CCache2003View::OnUpdateSimbologia(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( m_dlgColores.IsWindowVisible() == false );
}

void CCache2003View::Nuevo()
{
	
	m_inSec = 20;
 

	m_IdFormatoDato = ID_FORMAT_BINARIO;
	CWnd *pVentanaPadre = GetParent();
	CMenu *pMenu  = pVentanaPadre->GetMenu();
	pMenu->CheckMenuItem(m_IdFormatoDato, MF_CHECKED | MF_BYCOMMAND );
	
		
	m_colorMarcos = RGB(0, 0,  160);
	m_colorAcierto = RGB(0, 255, 0);
	m_colorFallo = RGB( 255, 0, 0);
	m_colorTextos = RGB(128, 128, 192);
	m_colorTextoStatic = RGB(0, 0, 0);	 
	m_colorTextoEdit = RGB(0, 0, 255);
	
	/*
	CBrush m_pincelMarcos, m_pincelAcierto, m_pincelFallo;

	m_pincelMarcos.CreateSolidBrush( m_colorMarcos );
	m_pincelAcierto.CreateSolidBrush( m_colorAcierto );
	m_pincelFallo.CreateSolidBrush( m_colorFallo );
	  */




	int cont;
	CCache2003Doc *pDoc = GetDocument();
	cont = pDoc->m_iOpenDoc;

if( cont != 30 )
{

	//desactiva los CheckBox del CForm
	
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK_FREC) -> EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK_EDAD) -> EnableWindow(FALSE);
	
	
	GetDlgItem(IDC_SIMULAR) -> EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_LLENAR_MP) -> EnableWindow(TRUE);

	//desactiva los controles de edición de los datos
	GetDlgItem(IDC_DATOSDLG_DIRECCION)->EnableWindow(FALSE);
	GetDlgItem(IDC_DATOSDLG_DAT)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO_LECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO_ESC)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_AGREGAR)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_EDITAR)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_BUSCAR)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_POSICION)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_PRIMERO)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_ANTERIOR)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_SIGUIENTE)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_ULTIMO)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_DIR)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_DAT)->EnableWindow(FALSE);





	//desactiva los controles de edición de las secuencias
	GetDlgItem(IDC_EDIT_SECUENCIA)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_DIR_SEC)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_AGREGAR_SEC)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_EDITAR_SEC)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_REG_SEC)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_PRIMERO_SEC)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_ANTERIOR_SEC)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_SIGUIENTE_SEC)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_ULTIMO_SEC)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_SECUENCIA)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_DIR_SEC)->EnableWindow(FALSE);




	//desactiva los controles edit del CFormView
	//GetDlgItem(IDC_EDIT_MET_EMPLAZA) -> ShowWindow(FALSE);
	//GetDlgItem(IDC_EDIT_MET_REEMPLAZA) -> ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_DATO)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_TIPO)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_DATO_MC)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_SIMULACIONES)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_ACIERTOS)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_FALLOS)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_PALABRA)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_BLOQUE)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_PALABRA_BLOQUE)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_LINEA)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_CONJ)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_N_LINEAS)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_TA)->EnableWindow(FALSE);

	//desactiva los controles static del CFormView
	GetDlgItem(IDC_STATIC_DATO)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_DATO_MC)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_SIMULACIONES)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_ACIERTOS)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_FALLOS)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_PALABRA)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_BLOQUE)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_PALABRA_BLOQUE)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_LINEA)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_CONJ_MC)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_LINEA_CONJ)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_NS)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_TA)->EnableWindow(FALSE);


	
	m_Fila = 0;
	m_Col = 6;

	m_nSim = 0;
	m_contAciertos = 0;
	m_contFallos = 0;
	m_sSecuencia = "1";
	
	//Rejilla Memoria Principal
	TamCeldasNoFijas( m_Fila, m_Col);
	
	m_CtrlRejilla_MP.SetRow(0);
	m_CtrlRejilla_MP.SetCol(0);
	m_CtrlRejilla_MP.SetText("Dirección");
	m_CtrlRejilla_MP.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MP.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MP.SetCellAlignment(4);
	m_CtrlRejilla_MP.Refresh();

	m_CtrlRejilla_MP.SetRow(0);
	m_CtrlRejilla_MP.SetCol(1);
	m_CtrlRejilla_MP.SetText("Datos");
	m_CtrlRejilla_MP.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MP.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MP.SetCellAlignment(4);
	m_CtrlRejilla_MP.Refresh();

	
	m_CtrlRejilla_MP.SetColWidth(0, 1500);
	m_CtrlRejilla_MP.SetColWidth(1, 1850);
	//Tercera Cuarta Quinta y Sexta Columna de MP con ancho nulo 
	
	
	m_CtrlRejilla_MP.SetColWidth(2, 0);
	m_CtrlRejilla_MP.SetColWidth(3, 0);
	m_CtrlRejilla_MP.SetColWidth(4, 0);
	m_CtrlRejilla_MP.SetColWidth(5, 0);
    
	//Rejilla Memoria Cache
	TamCeldasNoFijas_MC( m_Fila, m_Col );
   	
	
	
	m_CtrlRejilla_MC.SetRow(0);
	m_CtrlRejilla_MC.SetCol(0);
	m_CtrlRejilla_MC.SetText("Dirección");
	m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MC.SetCellAlignment(4);
	m_CtrlRejilla_MC.Refresh();

	m_CtrlRejilla_MC.SetRow(0);
	m_CtrlRejilla_MC.SetCol(1);
	m_CtrlRejilla_MC.SetText("Datos");
	m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MC.SetCellAlignment(4);
	m_CtrlRejilla_MC.Refresh();
	
	m_CtrlRejilla_MC.SetColWidth(0, 1500);
	m_CtrlRejilla_MC.SetColWidth(1, 1850);
	//Tercera, Cuarta Quinta y Sexta Columna de MP con ancho nulo 
	
	m_CtrlRejilla_MC.SetColWidth(2, 0);
	m_CtrlRejilla_MC.SetColWidth(3, 0);
	m_CtrlRejilla_MC.SetColWidth(4, 0);
	m_CtrlRejilla_MC.SetColWidth(5, 0);
	
}
else
{
	
	//desactiva los CheckBox del CForm
		
	GetDlgItem(IDC_CHECK_CONT) -> EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK_L_E) -> EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK_FREC) -> EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK_EDAD) -> EnableWindow(FALSE);
	
	
	GetDlgItem(IDC_SIMULAR) -> EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_LLENAR_MP) -> EnableWindow(FALSE);

	//desactiva los controles de edición de los datos
	GetDlgItem(IDC_DATOSDLG_DIRECCION)->EnableWindow(FALSE);
	GetDlgItem(IDC_DATOSDLG_DAT)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO_LECT)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO_ESC)->EnableWindow(TRUE);
	GetDlgItem(IDC_B_AGREGAR)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_EDITAR)->EnableWindow(TRUE);
	GetDlgItem(IDC_B_BUSCAR)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_POSICION)->EnableWindow(TRUE);
	GetDlgItem(IDC_B_PRIMERO)->EnableWindow(TRUE);
	GetDlgItem(IDC_B_ANTERIOR)->EnableWindow(TRUE);
	GetDlgItem(IDC_B_SIGUIENTE)->EnableWindow(TRUE);
	GetDlgItem(IDC_B_ULTIMO)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_DIR)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC_DAT)->EnableWindow(TRUE);





	//desactiva los controles de edición de las secuencias
	GetDlgItem(IDC_EDIT_SECUENCIA)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_DIR_SEC)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_AGREGAR_SEC)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_EDITAR_SEC)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_REG_SEC)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_PRIMERO_SEC)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_ANTERIOR_SEC)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_SIGUIENTE_SEC)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_ULTIMO_SEC)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_SECUENCIA)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_DIR_SEC)->EnableWindow(FALSE);




	//desactiva los controles edit del CFormView
	//GetDlgItem(IDC_EDIT_MET_EMPLAZA) -> ShowWindow(FALSE);
	//GetDlgItem(IDC_EDIT_MET_REEMPLAZA) -> ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_DATO)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_TIPO)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_DATO_MC)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_SIMULACIONES)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_ACIERTOS)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_FALLOS)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_PALABRA)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_BLOQUE)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_PALABRA_BLOQUE)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_LINEA)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_CONJ)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_N_LINEAS)->EnableWindow(FALSE);
	//desactiva los controles static del CFormView
	GetDlgItem(IDC_STATIC_DATO)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_DATO_MC)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_SIMULACIONES)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_ACIERTOS)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_FALLOS)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_PALABRA)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_BLOQUE)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_PALABRA_BLOQUE)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_LINEA)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_CONJ_MC)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_LINEA_CONJ)->EnableWindow(FALSE);



	
	
	m_nSim = 0;
	m_contAciertos = 0;
	m_contFallos = 0;
	m_sSecuencia = "1";

	
	//Rejilla Memoria Principal
	//TamCeldasNoFijas( m_Fila, m_Col);
	
	m_CtrlRejilla_MP.SetRow(0);
	m_CtrlRejilla_MP.SetCol(0);
	m_CtrlRejilla_MP.SetText("Dirección");
	m_CtrlRejilla_MP.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MP.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MP.SetCellAlignment(4);
	m_CtrlRejilla_MP.Refresh();

	m_CtrlRejilla_MP.SetRow(0);
	m_CtrlRejilla_MP.SetCol(1);
	m_CtrlRejilla_MP.SetText("Datos");
	m_CtrlRejilla_MP.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MP.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MP.SetCellAlignment(4);
	m_CtrlRejilla_MP.Refresh();

	
	m_CtrlRejilla_MP.SetColWidth(0, 1500);
	m_CtrlRejilla_MP.SetColWidth(1, 1850);
	//Tercera Cuarta Quinta y Sexta Columna de MP con ancho nulo 
	
	/*
	m_CtrlRejilla_MP.SetColWidth(2, 0);
	m_CtrlRejilla_MP.SetColWidth(3, 0);
	m_CtrlRejilla_MP.SetColWidth(4, 0);
	m_CtrlRejilla_MP.SetColWidth(5, 0);
     */
	//Rejilla Memoria Cache
	//TamCeldasNoFijas_MC( m_Fila, m_Col );
   	
	
	
	m_CtrlRejilla_MC.SetRow(0);
	m_CtrlRejilla_MC.SetCol(0);
	m_CtrlRejilla_MC.SetText("Dirección");
	m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MC.SetCellAlignment(4);
	m_CtrlRejilla_MC.Refresh();

	m_CtrlRejilla_MC.SetRow(0);
	m_CtrlRejilla_MC.SetCol(1);
	m_CtrlRejilla_MC.SetText("Datos");
	m_CtrlRejilla_MC.SetCellBackColor(0x00666666);
	m_CtrlRejilla_MC.SetCellForeColor(0x0000FFFF);
	m_CtrlRejilla_MC.SetCellAlignment(4);
	m_CtrlRejilla_MC.Refresh();
	
	m_CtrlRejilla_MC.SetColWidth(0, 1500);
	m_CtrlRejilla_MC.SetColWidth(1, 1850);
	//Tercera, Cuarta Quinta y Sexta Columna de MP con ancho nulo 
/*	
	m_CtrlRejilla_MC.SetColWidth(2, 0);
	m_CtrlRejilla_MC.SetColWidth(3, 0);
	m_CtrlRejilla_MC.SetColWidth(4, 0);
	m_CtrlRejilla_MC.SetColWidth(5, 0);
	 */
  
	

	}
}

void CCache2003View::OnHelpCache2003() 
{
	// TODO: Add your command handler code here
	WinExec("notepad.exe", SW_SHOW);
}
