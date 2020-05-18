#if !defined(AFX_BUSCARDLG_H__AC7696FB_6744_44AC_A898_806AB5CF836B__INCLUDED_)
#define AFX_BUSCARDLG_H__AC7696FB_6744_44AC_A898_806AB5CF836B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BuscarDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBuscarDlg dialog

class CBuscarDlg : public CDialog
{
// Construction
public:
	CBuscarDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBuscarDlg)
	enum { IDD = IDD_DLG_BUSCAR };
	CString	m_sDireccion;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBuscarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBuscarDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUSCARDLG_H__AC7696FB_6744_44AC_A898_806AB5CF836B__INCLUDED_)
