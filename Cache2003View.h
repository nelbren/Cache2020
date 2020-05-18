// Cache2003View.h : interface of the CCache2003View class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
//{{AFX_INCLUDES()
#include "msflexgrid.h"
//}}AFX_INCLUDES
#include "MyCug.h"

#if !defined(AFX_CACHE2003VIEW_H__B5315F23_2545_4867_980D_A4A3B5CA834F__INCLUDED_)
#define AFX_CACHE2003VIEW_H__B5315F23_2545_4867_980D_A4A3B5CA834F__INCLUDED_

#include "Datos.h"
#include "Secuencia.h"
#include "Parametros.h"
#include "DireccionDlg.h"	// Added by ClassView
#include "MemoriasDlg.h"	// Added by ClassView
#include "PoliticasDlg.h"	//Added by ClassView
#include "LineasDlg.h"	//Added by ClassView
#include "EstadisticasDlg.h"	// Added by ClassView

#include "Cache2003Doc.h"	//Aded by ClassDoc
#include "DatosDlg.h"	// Added by ClassView




#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



#include "ColoresDlg.h"	// Added by ClassView
#include "MainFrm.h"	// Added by ClassView
class CCache2003View : public CFormView
{
public: // create from serialization only
	CCache2003View();
	DECLARE_DYNCREATE(CCache2003View)

	CBrush m_pincelMarcos, m_pincelAcierto, m_pincelFallo;
	COLORREF m_colorMarcos, m_colorAcierto, m_colorFallo, m_colorTextos, m_colorTextoStatic, m_colorTextoEdit;

public:
	//{{AFX_DATA(CCache2003View)
	enum { IDD = IDD_CACHE2003_FORM };
	CMSFlexGrid	m_CtrlRejilla_MP;
	int		m_nMP;
	CMSFlexGrid	m_CtrlRejilla_MC;
	int		m_nMC;
	int		m_nBloque;
	CString	m_nVias;
	int		m_iP_Emplazamiento;
	int		m_iP_Reemplazamiento;
	CString	m_Dato;
	CString	m_NPalabra;
	CString	m_NBloque;
	CString	m_NLinea;
	int		m_TamConjunto;
	CString	m_NPalabraBloque;
	int		m_PalabraConjunto;
	int		m_TamMP;
	int		m_TamBloque;
	int		m_TamMC;
	int		m_contAciertos;
	int		m_contFallos;
	int		m_nSim;
	int		m_in_Bloques_MC;
	int		m_in_Bloques_MP;
	int		m_iw;
	int		m_ini_Linea;
	BOOL	m_bChk_LectEsc;
	BOOL	m_bChk_Cont;
	int		m_nBloqueConjunto;
	CString	m_NConjunto;
	CString	m_nLineaConjunto;
	BOOL	m_bChk_Edad;
	BOOL	m_bChk_Frec;
	CString	m_sMet_Emplaza;
	CString	m_sMet_Reemplaza;
	int		m_iTip_Esc;
	int		m_iAsignacion;
	CString		m_Dato_Escrito;
	int		m_iTipo_Dato;
	CString	m_sTipo;
	CString	m_sDireccion;
	CString	m_sDato;
	int		m_iTipo;
	CString	m_sPosicion;
	int		m_iReg;
	int		m_iLectura;
	CString		m_sSecuencia;
	CString		m_sDirSecuencia;
	CString	m_sPosicionSec;
	int		m_iSec;
	int		m_iAutomatico_Sec;
	int		m_iAutomatico;
	int		m_inSec;
	int		m_iBasico;
	int		m_iParalelo;
	float	m_fTc;
	float	m_fTp;
	float	m_fTa;
	int		m_nEscrituras;
	//}}AFX_DATA
	//CDireccionDlg *m_pDlgDireccion;



// Attributes
public:
	CCache2003Doc* GetDocument();
	
// Operations
private:
	
	int *m_contFrec;
	int *m_contEdad;
	int *m_arraySecMPPtr;
	int *m_arrayDirSecMPPtr;
	int *m_arrayTipoMCPtr;
	int *m_arrayTipoMPPtr;
	int *m_arrayDatosMCPtr;
	int *m_arrayDatosMPPtr;
	int *m_arrayDirMCPtr;
	int *m_arrayDirMPPtr;
	
	CString Oct( int n);
	CString Hex( int n);
	void Contador( int *contLineas, int TamLinea, int NLinea, int col);
	void ColorearConjuntos( int TamMC, int TamBloque, CString Vias);
	void AC_FIFO_CAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, CString sVias, int *arrayDirSecMPPtr);
	void AC_LFU_CAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contFrec, CString sVias, int *arrayDirSecMPPtr);
	void AC_LRU_CAsig( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contEdad, CString sVias, int *arrayDirSecMPPtr);
	void AC_Aleatorio_CAsig( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP,  int TamMC, int TamBloque,  int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, CString sVias, int *arrayDirSecMPPtr);
	void SimulaAConjuntos( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, CString sVias);
	int *m_contLineas;
	void ImprimeContadores(int *contLineas, int tam, int col);
	void A_FIFO_CAsig( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr);
	void A_LFU_CAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contFrec, int *arrayDirSecMPPtr);
	void A_LRU_CAsig( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contEdad, int *arayDirSecMPPtr);
	void A_Aleatorio_CAsig( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr);
	void SimulaAsociativo( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas);
	void ColorearMC(int fil, int col, int fondo, int fuente);
	void ColorearMP( int fil, int col, int fondo, int fuente);
	
	void ImprimeFormatoMP(int n,  int tam, int *arreglodir, int *arreglodatos, int *arreglotipo);
	void ImprimeFormatoMC(int n, int tam, int *arreglodir, int *arreglodatos, int *arreglotipo);
	int Sobrante( int dividendo, int divisor);
	int Truncar( int dividendo, int divisor);
	
	void SimulaDirecto_CAsig( int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr);
		
	CString Bin(int n, int tam);
	int GenID(int m_iRow, int m_iCol);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCache2003View)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL
	public:
		enum { rangoEscritura = 5000 };
		
	
// Implementation
public:
	void Nuevo();
	CColoresDlg m_dlgColores;
	void ActualizarEscrituras(int nEsc, int nBloques, int tamMP, int formula, int transf, float tp, float tc, int tipo, int asignacion);
	void CalculoTa();
	void PrintSec();
	
	void LlenarMP_OpenDoc();
	int m_nPage;
	void GeneraTamMP();
	void LimpiarEdit();
	void UltimoPar();
	void LimpiarRejilla_MC();
	void LimpiarRejilla_MP();

	void LlenarObjetosSecuencia(int, int, int);
	void DescargarObjetosSecuencia();
	
	void CambiaParametros();
	void AgregarPar();
	void LlenarVistaPar();
	void PrimeroPar();
	void PonerNuevoPar();
	void Eliminar();
	void PosicionActualSec();
	void EditarSec();
	void AgregarSec();
	void PonerNuevoSec();
	void CambiaDirSecuencia();
	void CambiaSecuencia();
	void UltimoSec();
	void SiguienteSec();
	void AnteriorSec();
	void PrimeroSec();
	
	void LlenarVistaSec();
	void ResetDatos();
	void DescargarObjetosDatos( );
	void PosicionActual();
	void Editar();
	void LLenarObjetosDatos(int, int, int, int);
	void Agregar();
	void PonerNuevoDato();
	void CambiaTipo();
	void CambiaDato();
	void CambiaDireccion();
	void Siguiente();
	void Anterior();
	void Ultimo();
	void Primero();
	void LlenarVista();
	CSecuencia* m_pCurSecuencia;
	CDatos*  m_pCurDatos;
	CParametros* m_pCurParametro;
	CEstadisticasDlg m_dlgEstadisticas;

private:
	void ActualizarDatosChart( int aciertos, int fallos, int simulaciones);
	void ImprimeFormatoSim_Conj(int n, int Dato, int DatoEscrito, int NPalabra, int NBloque, int NBloquePalabra, int NLinea, int NConjunto, int NVia);
	void ImprimeFormatoSim( int n, int Dato, int DatoEscrito, int NPalabra, int NBloque, int NPalabraBloque, int NLinea);
	void ActualizarDatosDir( int, int, int, int, CString);
	void AC_LRU_Post( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contEdad, CString sVias, int *arrayDirSecMPPtr);
	void AC_LFU_Post(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contFrec, CString sVias, int *arrayDirSecMPPtr);
	void AC_FIFO_Post(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, CString sVias, int *arrayDirSecMPPtr);
	void AC_Aleatorio_Post( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP,  int TamMC, int TamBloque,  int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, CString sVias, int *arrayDirSecMPPtr);
	void A_LRU_Post( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contEdad, int *arrayDirSecMPPtr);
	void A_LFU_Post(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contFrec, int *arrayDirSecMPPtr);
	void A_FIFO_Post( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr);
	void A_Aleatorio_Post( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr);
	void SimulaDirecto_Post ( int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr);
	void AC_LRU_SAsig( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contEdad, CString sVias, int *arrayDirSecMPPtr);
	void AC_LFU_SAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contFrec, CString sVias, int *arrayDirSecMPPtr);
	void AC_FIFO_SAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, CString sVias, int *arrayDirSecMPPtr);
	void AC_Aleatorio_SAsig( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP,  int TamMC, int TamBloque,  int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, CString sVias,int *arrayDirSecMPPtr);
	void A_LFU_SAsig(int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contFrec, int *arrayDirSecMPPtr);
	void A_FIFO_SAsig( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr);
	void A_LRU_SAsig( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *contEdad, int *arrayDirSecMPPtr);
	void A_Aleatorio_SAsig( int Ini_Linea, int w, int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr);
	void SimulaDirecto_SAsig( int nSim, int contAciertos, int contFallos, int TamMP, int TamMC, int TamBloque, int *arrayTipoMPPtr, int *arrayTipoMCPtr, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *contLineas, int *arrayDirSecMPPtr);
	void EscrituraMP( int Dir, int NBloque, int TamMP, int TamBloque, int *arrayDirMPPtr, int *arrayDatosMPPtr, int *arrayTipoMPPtr, int *arrayDirMCPtr, int *arrayDatosMCPtr, int *arrayTipoMCPtr);
	void LlenarMP();
	
	void MostrarMP();
	void TamCeldasNoFijas(long, long);
	void TamCeldasNoFijas_MC( long nFilasFijas, long nColFijas);

	UINT m_IdFormatoDato;
	CDireccionDlg m_dlgDireccion;

public:
	virtual ~CCache2003View();

	
#ifdef _DEBUG 
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	

protected:
	MyCug m_grid;

	int m_Col;
	int m_Fila;
	long **m_ppMP;

	// Generated message map functions	
	//{{AFX_MSG(CCache2003View)
	afx_msg void OnConfiguracionMemorias();
	afx_msg void OnVerDireccindememoria();
	afx_msg void OnConfigurarPolticas();
	afx_msg void OnFormatoDatos();
	afx_msg void OnSimular();
	afx_msg void OnCheckLE();
	afx_msg void OnCheckCont();
	afx_msg void OnBtnLlenarMp();
	afx_msg void OnCheckEdad();
	afx_msg void OnCheckFrec();
	afx_msg void OnConfigurarActualiza();
	afx_msg void OnConfigurarTiemposacceso();
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateVerDireccindememoria(CCmdUI* pCmdUI);
	afx_msg void OnUpdateContadorLineas(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTipoDato(CCmdUI* pCmdUI);
	afx_msg void OnContadorLineas();
	afx_msg void OnTipoDato();
	afx_msg void OnUpdateTipoDatoMc(CCmdUI* pCmdUI);
	afx_msg void OnTipoDatoMc();
	afx_msg void OnVerInformedesimulacin();
	afx_msg void OnUpdateVerInformedesimulacin(CCmdUI* pCmdUI);
	afx_msg void OnInsertarDatosMp();
	afx_msg void OnChangeDatosdlgDireccion();
	afx_msg void OnChangeDatosdlgDat();
	afx_msg void OnChangeDatosdlgTip();
	afx_msg void OnBPrimero();
	afx_msg void OnBUltimo();
	afx_msg void OnBAnterior();
	afx_msg void OnBSiguiente();
	afx_msg void OnBAgregar();
	afx_msg void OnRadioEsc();
	afx_msg void OnRadioLect();
	afx_msg void OnBEditar();
	afx_msg void OnBBuscar();
	afx_msg void OnChangeEditSecuencia();
	afx_msg void OnChangeEditDirSec();
	afx_msg void OnBAgregarSec();
	afx_msg void OnBEditarSec();
	afx_msg void OnBPrimeroSec();
	afx_msg void OnBAnteriorSec();
	afx_msg void OnBSiguienteSec();
	afx_msg void OnBUltimoSec();
	afx_msg void OnConfiguracionSimulacion();
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	afx_msg void OnFilePrintSec();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSimbologia();
	afx_msg void OnUpdateSimbologia(CCmdUI* pCmdUI);
	afx_msg void OnHelpCache2003();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void PrintPageFooter( CDC* pDC);
	void PrintPageHeader( CDC* pDC);
};

#ifndef _DEBUG  // debug version in Cache2003View.cpp
inline CCache2003Doc* CCache2003View::GetDocument()
   { return (CCache2003Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CACHE2003VIEW_H__B5315F23_2545_4867_980D_A4A3B5CA834F__INCLUDED_)
