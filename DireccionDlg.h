#if !defined(AFX_DIRECCIONDLG_H__EC82E6DF_F886_4095_BDD2_47D8C1E1A934__INCLUDED_)
#define AFX_DIRECCIONDLG_H__EC82E6DF_F886_4095_BDD2_47D8C1E1A934__INCLUDED_

#include "MemoriasDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DireccionDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDireccionDlg dialog

class CDireccionDlg : public CDialog
{
// Construction
public:
	
	CDireccionDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDireccionDlg)
	enum { IDD = IDD_DIRECCION_DLG };
	int		m_inConjuntos;
	int		m_inEtiquetas;
	int		m_inLineas;
	int		m_inPalabras;
	int		m_iTotalBits;
	CString m_sDato;
	CString m_sDato_Esc;
	CString	m_sTipo;
	int		m_inMP;
	int		m_inMC;
	int		m_inBloque;
	CString	m_snVias;
	int		m_iDireccion;
	CString	m_sDireccion;
	//}}AFX_DATA
	
	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDireccionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	CEdit *m_pEtiquetas;
	CEdit *m_pLineas;
	CEdit *m_pPalabras;
	CEdit *m_pConjuntos;
	CEdit *m_pParche;
	CButton *m_pnBits;
	CButton *m_pDireccion;
	

	// Generated message map functions
	//{{AFX_MSG(CDireccionDlg)
	afx_msg void OnChangeDEtiqueta();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnChangeDLinea();
	afx_msg void OnChangeDPalabra();
	afx_msg void OnChangeDTotalBits();
	afx_msg void OnChangeDConjunto();
	afx_msg void OnChangeEditDireccion();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	
			
	void Parche();
	
	int ConvertBase2( int );
	void DirDirecto( int, int, int);
	void DirAConjuntos( int, int, int, CString );
	void DirAsociativo( int, int, int );

private:	

	COLORREF m_colorEdit;
	CBrush m_pincelEdit;
	
	CBrush m_pincelEtiquetas, m_pincelLineas, m_pincelPalabras, m_pincelConjuntos,m_pincelParche;
	CFont m_FuenteDireccion;
	COLORREF m_colorEtiquetas, m_colorLineas, m_colorPalabras, m_colorConjuntos, m_colorParche;



};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIRECCIONDLG_H__EC82E6DF_F886_4095_BDD2_47D8C1E1A934__INCLUDED_)
