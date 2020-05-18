#if !defined(AFX_TIEMPOSDLG_H__7BB6A6F0_5FA0_4F70_BAB2_9586E2F24121__INCLUDED_)
#define AFX_TIEMPOSDLG_H__7BB6A6F0_5FA0_4F70_BAB2_9586E2F24121__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TiemposDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTiemposDlg dialog

class CTiemposDlg : public CDialog
{
// Construction
public:
	CTiemposDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTiemposDlg)
	enum { IDD = IDD_TIEMPOS };
	int		m_iBasica;
	int		m_iParalelo;
	float	m_fTc;
	float	m_fTp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTiemposDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTiemposDlg)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


private:
   CBrush m_pincelMarcos;
	COLORREF m_colorMarcos, m_colorTextos;


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIEMPOSDLG_H__7BB6A6F0_5FA0_4F70_BAB2_9586E2F24121__INCLUDED_)
