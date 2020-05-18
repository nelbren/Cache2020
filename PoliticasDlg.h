#if !defined(AFX_POLITICASDLG_H__3C82506A_CE4D_4A01_B269_AAE25247D350__INCLUDED_)
#define AFX_POLITICASDLG_H__3C82506A_CE4D_4A01_B269_AAE25247D350__INCLUDED_

#include "Cache2003View.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PoliticasDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPoliticasDlg dialog

class CPoliticasDlg : public CDialog
{
// Construction
public:

	CPoliticasDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPoliticasDlg)
	enum { IDD = IDD_POLITICAS_DLG };
	int		m_iPAleatorio;
	int		m_iPDirecto;
	CString	m_snVias;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPoliticasDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPoliticasDlg)
	afx_msg void OnPolitDirecto();
	afx_msg void OnPolitAsociativo();
	afx_msg void OnPolitACojuntos();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CBrush m_pincelMarcos;
	COLORREF m_colorMarcos, m_colorTextos;


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLITICASDLG_H__3C82506A_CE4D_4A01_B269_AAE25247D350__INCLUDED_)
