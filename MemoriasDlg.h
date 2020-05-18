#if !defined(AFX_MEMORIASDLG_H__C67BDA74_90BA_4FAE_871B_C22E998A192D__INCLUDED_)
#define AFX_MEMORIASDLG_H__C67BDA74_90BA_4FAE_871B_C22E998A192D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MemoriasDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMemoriasDlg dialog

class CMemoriasDlg : public CDialog
{
// Construction
public:
	
	CMemoriasDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMemoriasDlg)
	enum { IDD = IDD_MEMORIAS_DLG };
	CEdit	m_Ctrl_Bloque;
	CEdit	m_Ctrl_MC;
	CEdit	m_Ctrl_MP;
	int		m_inBloque;
	int		m_inMC;
	int		m_inMP;
	long	m_lBytesTamBloque;
	long	m_lBytesTamMC;
	long	m_lKBytesTamBloque;
	long	m_lKBytesTamMC;
	long	m_lKBytesTamMP;
	long	m_lMBytesTamBloque;
	long	m_lMBytesTamMP;
	long	m_lMBytesTamMC;
	long	m_lBytesTamMP;
	//}}AFX_DATA

	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMemoriasDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	

	// Generated message map functions
	//{{AFX_MSG(CMemoriasDlg)
	afx_msg void OnChangeNMp();
	afx_msg void OnIncreMp();
	afx_msg void OnDecreMp();
	afx_msg void OnChangeNMc();
	afx_msg void OnIncreMc();
	afx_msg void OnDecreMc();
	afx_msg void OnChangeNBloque();
	afx_msg void OnIncreBloque();
	afx_msg void OnDecreBloque();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	double ConvertMBytes( int );
	double ConvertKBytes( int );


	CBrush m_pincelMarcos;
	COLORREF m_colorMarcos;

	CBrush m_pincelEdit;
	COLORREF m_colorEdit;

	COLORREF m_colorTextos;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEMORIASDLG_H__C67BDA74_90BA_4FAE_871B_C22E998A192D__INCLUDED_)
