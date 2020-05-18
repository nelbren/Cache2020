// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__9E5CCA37_2C17_4D5A_99F8_AB42A44A748C__INCLUDED_)
#define AFX_MAINFRM_H__9E5CCA37_2C17_4D5A_99F8_AB42A44A748C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL CreaConfiguracionBar();
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	afx_msg void OnSelChangeWidth();
	CToolBar m_wndSecuenciasBar;
	CToolBar m_wndDatosBar;
	CToolBar m_wndConfiguracionBar;
public:	
	CComboBox m_CtrlBinario;

	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnUpdateViewConfiguracionBar(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewDatosBar(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewSecuenciasBar(CCmdUI* pCmdUI);
	afx_msg void OnViewConfiguracionBar();
	afx_msg void OnViewDatosBar();
	afx_msg void OnViewSecuenciasBar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__9E5CCA37_2C17_4D5A_99F8_AB42A44A748C__INCLUDED_)
