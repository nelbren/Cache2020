//{{AFX_INCLUDES()
#include "mschart.h"
//}}AFX_INCLUDES
#if !defined(AFX_ESTADISTICASDLG_H__C1DCAC0B_45EA_4922_B54A_F1DA9B602B56__INCLUDED_)
#define AFX_ESTADISTICASDLG_H__C1DCAC0B_45EA_4922_B54A_F1DA9B602B56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EstadisticasDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEstadisticasDlg dialog

class CEstadisticasDlg : public CDialog
{
// Construction
public:
	CEstadisticasDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEstadisticasDlg)
	enum { IDD = IDD_ESTADISTICAS_DLG };
	CMSChart	m_CtrlChart;
	int		m_iAciertos;
	int		m_iFallos;
	int		m_iSimulaciones;
	int		m_iBasico;
	int		m_iParalelo;
	float	m_fTc;
	float	m_fTp;
	int		m_nEscrituras;
	float	m_fTasaPenaliza;
	float	m_fTasaFallos;
	float	m_fTasaAciertos;
	float	m_fTAccesoMedio;
	float	m_fProb_Modificado;
	float	m_fPor_Esc;
	float	m_fPor_Lect;
	int		m_iAsignacion;
	int		m_iTip_Esc;
	int		m_in_Bloques_MP;
	float	m_fTa;
	int		m_Tam_MP;
	float	m_fTacierto;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEstadisticasDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	void CalculoTa_Stats();

	// Generated message map functions
	//{{AFX_MSG(CEstadisticasDlg)
	afx_msg void OnChangeEditAciertos();
	afx_msg void OnChangeEditFallos();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEditSimulaciones();
	afx_msg void OnChangeEditNEsc();
	afx_msg void OnBDetalles();
	virtual void OnOK();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CBrush m_pincelMarcos;
	COLORREF m_colorMarcos, m_colorEdit, m_colorTextos;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ESTADISTICASDLG_H__C1DCAC0B_45EA_4922_B54A_F1DA9B602B56__INCLUDED_)
