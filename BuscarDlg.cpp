// BuscarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Cache2003.h"
#include "BuscarDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBuscarDlg dialog


CBuscarDlg::CBuscarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBuscarDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBuscarDlg)
	m_sDireccion = _T("");
	//}}AFX_DATA_INIT
}


void CBuscarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBuscarDlg)
	DDX_Text(pDX, IDC_EDIT_DIR, m_sDireccion);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBuscarDlg, CDialog)
	//{{AFX_MSG_MAP(CBuscarDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBuscarDlg message handlers
