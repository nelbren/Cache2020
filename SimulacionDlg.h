#if !defined(AFX_SIMULACIONDLG_H__E4A6DD57_4F33_446E_A43C_DC8AE4EC9C1E__INCLUDED_)
#define AFX_SIMULACIONDLG_H__E4A6DD57_4F33_446E_A43C_DC8AE4EC9C1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SimulacionDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSimulacionDlg dialog

class CSimulacionDlg : public CDialog
{
// Construction
public:
	CSimulacionDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSimulacionDlg)
	enum { IDD = IDD_SIMULACION_DLG };
	int		m_inSec;
	int		m_iAutomatico;
	int		m_iAutomatico_Sec;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimulacionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSimulacionDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioSecAutomatica();
	afx_msg void OnRadioManualSec();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CBrush m_pincelMarcos;
	COLORREF m_colorMarcos, m_colorTextos;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMULACIONDLG_H__E4A6DD57_4F33_446E_A43C_DC8AE4EC9C1E__INCLUDED_)
