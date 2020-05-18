#if !defined(AFX_ESCRITURADLG_H__AC8AED0E_0043_40EA_BD6C_CF5BF3CE95E7__INCLUDED_)
#define AFX_ESCRITURADLG_H__AC8AED0E_0043_40EA_BD6C_CF5BF3CE95E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EscrituraDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEscrituraDlg dialog

class CEscrituraDlg : public CDialog
{
// Construction
public:
	CEscrituraDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEscrituraDlg)
	enum { IDD = IDD_ESCRITURA_DLG };
	int		m_iEsc_Directa;
	int		m_iCon_Asignacion;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEscrituraDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL OnInitDialog();

	// Generated message map functions
	//{{AFX_MSG(CEscrituraDlg)
	afx_msg void OnEscDirecta();
	afx_msg void OnEscPost();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CBrush m_pincelMarcos;
	COLORREF m_colorMarcos, m_colorTextos;


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ESCRITURADLG_H__AC8AED0E_0043_40EA_BD6C_CF5BF3CE95E7__INCLUDED_)
