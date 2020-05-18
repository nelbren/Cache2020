#if !defined(AFX_COLORESDLG_H__D8C88C38_3126_452B_A2CC_FEFF03F2FD6E__INCLUDED_)
#define AFX_COLORESDLG_H__D8C88C38_3126_452B_A2CC_FEFF03F2FD6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColoresDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColoresDlg dialog

class CColoresDlg : public CDialog
{
// Construction
public:
	CColoresDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CColoresDlg)
	enum { IDD = IDD_COLORES_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColoresDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
    CBrush m_pincelEtiquetas, m_pincelLineas, m_pincelPalabras;
	CBrush m_pincelConjuntos, m_pincelAmarillo_MP, m_pincelAzul_MP;
	CBrush m_pincelPar, m_pincelImpar, m_pincelAcierto, m_pincelFallo;
	CBrush m_pincelMarcos, m_pincelCeleste;
	
	//CFont m_Fuente;
	COLORREF m_colorEtiquetas, m_colorLineas, m_colorPalabras;
	COLORREF m_colorConjuntos, m_colorAmarillo_MP, m_colorAzul_MP;
	COLORREF m_colorPar, m_colorImpar, m_colorAcierto, m_colorFallo;
	COLORREF m_colorMarcos, m_colorCeleste, m_colorTextos;

	
	
	
	protected:

	// Generated message map functions
	//{{AFX_MSG(CColoresDlg)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORESDLG_H__D8C88C38_3126_452B_A2CC_FEFF03F2FD6E__INCLUDED_)
