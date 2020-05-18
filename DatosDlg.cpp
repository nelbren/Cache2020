// DatosDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Cache2003.h"


#include "Datos.h"

#include "Cache2003View.h"
#include "DatosDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDatosDlg dialog


CDatosDlg::CDatosDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDatosDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDatosDlg)
	m_sDireccion = _T("");
	m_sDato = _T("");
	m_iTipo = 1;
	m_sPosicion = _T("");
	//}}AFX_DATA_INIT

}


void CDatosDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDatosDlg)
	DDX_Text(pDX, IDC_EDIT_DIRECCION, m_sDireccion);
	DDX_Text(pDX, IDC_EDIT_DATO, m_sDato);
	DDX_Radio(pDX, IDC_RADIO_LECTURA, m_iTipo);
	DDX_Text(pDX, IDC_STATIC_REGISTRO, m_sPosicion);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDatosDlg, CDialog)
	//{{AFX_MSG_MAP(CDatosDlg)
	ON_EN_CHANGE(IDC_EDIT_DIRECCION, OnChangeEditDireccion)
	ON_EN_CHANGE(IDC_EDIT_DATO, OnChangeEditDato)
	ON_BN_CLICKED(IDC_RADIO_LECTURA, OnRadioLectura)
	ON_BN_CLICKED(IDC_RADIO_ESCRITURA, OnRadioEscritura)
	ON_BN_CLICKED(IDC_B_PRIMERO, OnBPrimero)
	ON_BN_CLICKED(IDC_B_SIGUIENTE, OnBSiguiente)
	ON_BN_CLICKED(IDC_B_ULTIMO, OnBUltimo)
	ON_BN_CLICKED(IDC_B_ANTERIOR, OnBAnterior)
	ON_BN_CLICKED(IDC_B_AGREGAR, OnBAgregar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDatosDlg message handlers

void CDatosDlg::OnChangeEditDireccion() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	/*
	CCache2003View	dlgCacheView;
	dlgCacheView.CambiaDireccion();
	  */
}

void CDatosDlg::OnChangeEditDato() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	/*
	CCache2003View	dlgCacheView;
	dlgCacheView.CambiaDato(); */

}

void CDatosDlg::OnRadioLectura() 
{
	// TODO: Add your control notification handler code here
	/*CCache2003View	dlgCacheView;
	dlgCacheView.CambiaTipo(); */
}

void CDatosDlg::OnRadioEscritura() 
{
	// TODO: Add your control notification handler code here
	/*
	CCache2003View	dlgCacheView;
	dlgCacheView.CambiaTipo();	*/

}

void CDatosDlg::OnBPrimero() 
{
	// TODO: Add your control notification handler code here
/*	
	CCache2003View	dlgCacheView;
	dlgCacheView.Primero();
*/							  
	
}

void CDatosDlg::OnBSiguiente() 
{
	// TODO: Add your control notification handler code here
	/*
	CCache2003View	dlgCacheView;
	dlgCacheView.Siguiente();
	*/
}

void CDatosDlg::OnBUltimo() 
{
	// TODO: Add your control notification handler code here
	/*
	CCache2003View	dlgCacheView;
	dlgCacheView.Ultimo();
	  */
}

void CDatosDlg::OnBAnterior() 
{
	// TODO: Add your control notification handler code here
	/*
	CCache2003View	dlgCacheView;
	dlgCacheView.Anterior();
	  */
}

void CDatosDlg::OnBAgregar() 
{
	// TODO: Add your control notification handler code here
	
	//(CCache2003View	dlgCacheView;
/*	
	dlgCacheView.UpdateData(true);
	dlgCacheView.m_sDireccion = m_sDireccion;
	dlgCacheView.m_sDato = m_sDato;
	dlgCacheView.m_iTipo = m_iTipo;
	dlgCacheView.UpdateData(false);
  */
	

}
