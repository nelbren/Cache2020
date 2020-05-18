#if !defined(AFX_DATOSDLG_H__BAD9CBC1_204F_412B_A68C_590E14E27EB5__INCLUDED_)
#define AFX_DATOSDLG_H__BAD9CBC1_204F_412B_A68C_590E14E27EB5__INCLUDED_

#include "Cache2003View.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DatosDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDatosDlg dialog

class CDatosDlg : public CDialog
{
// Construction
public:
			
	CDatosDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDatosDlg)
	enum { IDD = IDD_DATOS_DLG };
	CString	m_sDireccion;
	CString	m_sDato;
	int		m_iTipo;
	CString	m_sPosicion;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDatosDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDatosDlg)
	afx_msg void OnChangeEditDireccion();
	afx_msg void OnChangeEditDato();
	afx_msg void OnRadioLectura();
	afx_msg void OnRadioEscritura();
	afx_msg void OnBPrimero();
	afx_msg void OnBSiguiente();
	afx_msg void OnBUltimo();
	afx_msg void OnBAnterior();
	afx_msg void OnBAgregar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	//CDatos* m_pCurDatos;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATOSDLG_H__BAD9CBC1_204F_412B_A68C_590E14E27EB5__INCLUDED_)
