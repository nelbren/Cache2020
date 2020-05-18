// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Cache2003.h"

#include "MainFrm.h"
#include "Splash.h"
#include "Cache2003View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_VIEW_CONFIGURACION_BAR, OnUpdateViewConfiguracionBar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DATOS_BAR, OnUpdateViewDatosBar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SECUENCIAS_BAR, OnUpdateViewSecuenciasBar)
	ON_COMMAND(ID_VIEW_CONFIGURACION_BAR, OnViewConfiguracionBar)
	ON_COMMAND(ID_VIEW_DATOS_BAR, OnViewDatosBar)
	ON_COMMAND(ID_VIEW_SECUENCIAS_BAR, OnViewSecuenciasBar)
	//}}AFX_MSG_MAP
	// Global help commands
	ON_COMMAND(ID_HELP_FINDER, CFrameWnd::OnHelpFinder)
	ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
	ON_COMMAND(ID_CONTEXT_HELP, CFrameWnd::OnContextHelp)
	ON_COMMAND(ID_DEFAULT_HELP, CFrameWnd::OnHelpFinder) 
	ON_CBN_SELCHANGE(IDC_CBFORMATO, OnSelChangeWidth)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_SEPARATOR,
	ID_INDICADOR_ESC,
	ID_INDICADOR_TIPO_ESC,


	/*
	ID_SEPARATOR
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL, */

};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	
	//Agrega barra de herramientas de configuración
	/*
	if( !CreaConfiguracionBar())
	{
		TRACE0("Fallo al crear la barra de configuración");
		return -1;
	}
	*/
		CreaConfiguracionBar();
	
		

	int iTBCtlID;
	int i;
	
	/*
	//Crea una barra de herramientas de configuración
	if( !m_wndConfiguracionBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD |
		        WS_VISIBLE | CBRS_ALIGN_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | 
				CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
				!m_wndConfiguracionBar.LoadToolBar(IDR_TOOLBAR_CONFIGURACION))
	{
		TRACE0("Fallo al crear barra de herramientas de configuración\n");
		return -1;
	}
	  */
	
	//Crea una barra de herramientas de datos
	if( !m_wndDatosBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD |
		        CBRS_ALIGN_BOTTOM | CBRS_GRIPPER | CBRS_TOOLTIPS | 
				CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
				!m_wndDatosBar.LoadToolBar(IDR_TOOLBAR_DATOS))
	{
		TRACE0("Fallo al crear barra de herramientas de datos\n");
		return -1;
	}
	//Crea una barra de herramientas de datos
	if( !m_wndSecuenciasBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD |
		        CBRS_ALIGN_BOTTOM | CBRS_GRIPPER | CBRS_TOOLTIPS | 
				CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
				!m_wndSecuenciasBar.LoadToolBar(IDR_TOOLBAR_SECUENCIAS))
	{
		TRACE0("Fallo al crear barra de herramientas de secuencias\n");
		return -1;
	}


	//Encuentra el botón Opciones de la barra de herramientas de configuración
	iTBCtlID = m_wndConfiguracionBar.CommandToIndex(ID_CONFIGURACION_SIMULACION);
	if( iTBCtlID >= 0 )
	{
		//Recorre los botones y los establece que actuen como check
		for( i = iTBCtlID; i < (iTBCtlID + 8); i++)
		{
			m_wndConfiguracionBar.SetButtonStyle(i, TBBS_CHECKGROUP);
		}
	}

	//Encuentra el botón Agregar de la barra de herramientas de datos
	iTBCtlID = m_wndDatosBar.CommandToIndex(IDC_B_AGREGAR);
	if( iTBCtlID >= 0 )
	{
		//Recorre los botones y los establece que actuen como button
		for( i = iTBCtlID; i < (iTBCtlID + 7); i++)
		{
			m_wndDatosBar.SetButtonStyle(i, TBBS_BUTTON);
		}
	}

	//Encuentra el botón Agregar de la barra de herramientas de secuencias
	iTBCtlID = m_wndSecuenciasBar.CommandToIndex(IDC_B_AGREGAR_SEC);
	if( iTBCtlID >= 0 )
	{
		//Recorre los botones y los establece que actuen como button
		for( i = iTBCtlID; i < (iTBCtlID + 6); i++)
		{
			m_wndSecuenciasBar.SetButtonStyle(i, TBBS_BUTTON);
		}
	}





	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndConfiguracionBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndDatosBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndSecuenciasBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	DockControlBar(&m_wndConfiguracionBar);
	DockControlBar(&m_wndDatosBar);
	DockControlBar(&m_wndSecuenciasBar);
	// CG: The following line was added by the Splash Screen component.
	CSplashWnd::ShowSplashScreen(this);
	
	//Estilos y longitudes de barra de estados
	m_wndStatusBar.SetPaneInfo(0, ID_SEPARATOR, SBPS_STRETCH, 0);
	m_wndStatusBar.SetPaneInfo(1, ID_SEPARATOR, SBPS_POPOUT, 1);
	m_wndStatusBar.SetPaneInfo(2, ID_INDICADOR_ESC, SBPS_NORMAL, 105);
	m_wndStatusBar.SetPaneInfo(3, ID_INDICADOR_ESC, SBPS_NORMAL, 50);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////







void CMainFrame::OnUpdateViewConfiguracionBar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(((m_wndConfiguracionBar.GetStyle() & WS_VISIBLE) != 0));

}

void CMainFrame::OnUpdateViewDatosBar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(((m_wndDatosBar.GetStyle() & WS_VISIBLE) != 0));
}

void CMainFrame::OnUpdateViewSecuenciasBar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(((m_wndSecuenciasBar.GetStyle() & WS_VISIBLE) != 0));

}

void CMainFrame::OnViewConfiguracionBar() 
{
	// TODO: Add your command handler code here
	BOOL bVisible;

	bVisible = ((m_wndConfiguracionBar.GetStyle() & WS_VISIBLE) != 0);

	ShowControlBar( &m_wndConfiguracionBar, !bVisible, FALSE );
	RecalcLayout();
}

void CMainFrame::OnViewDatosBar() 
{
	// TODO: Add your command handler code here
	BOOL bVisible;

	bVisible = ((m_wndDatosBar.GetStyle() & WS_VISIBLE) != 0);

	ShowControlBar( &m_wndDatosBar, !bVisible, FALSE );
	RecalcLayout();

}

void CMainFrame::OnViewSecuenciasBar() 
{
	// TODO: Add your command handler code here
	BOOL bVisible;

	bVisible = ((m_wndSecuenciasBar.GetStyle() & WS_VISIBLE) != 0);

	ShowControlBar( &m_wndSecuenciasBar, !bVisible, FALSE );
	RecalcLayout();

}

BOOL CMainFrame::CreaConfiguracionBar()
{
	//Agrega barra de herramientas de configuración
	int iTBCtlID;
	int i;

	//Crea una barra de herramientas de configuración
	if( !m_wndConfiguracionBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD |
		        WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | 
				CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
				!m_wndConfiguracionBar.LoadToolBar(IDR_TOOLBAR_CONFIGURACION))
	{
		TRACE0("Fallo al crear barra de herramientas de configuración\n");
		return -1;
	}
	
	
	//Encuentra el botón Opciones de la barra de herramientas de configuración
	iTBCtlID = m_wndConfiguracionBar.CommandToIndex(ID_CONFIGURACION_SIMULACION);
	if( iTBCtlID >= 0 )
	{
		//Recorre los botones y los establece que actuen como check
		 for( i = iTBCtlID; i < (iTBCtlID + 8); i++)
		{
			m_wndConfiguracionBar.SetButtonStyle(i, TBBS_BUTTON);
		}
		
	}

	
	//Agrega el cuadro de diálogo
	int nWidth = 125;
	int nHeight = 125;

	

	//Configura el marcador del cuadro combiando
	m_wndConfiguracionBar.SetButtonInfo(9, IDC_CBFORMATO, TBBS_SEPARATOR, nWidth);

	//Obtiene la altura de la barra de configuración
	CRect rect;
	m_wndConfiguracionBar.GetItemRect(9, &rect);
	rect.bottom = rect.top + nHeight;
	
	//Crea el cuadro combiando
	m_CtrlBinario.Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL |
		CBS_DROPDOWNLIST, rect, &m_wndConfiguracionBar, IDC_CBFORMATO);
	
	//Llena el cuadro combiando
	CString szStyle;
	if( szStyle.LoadString(IDS_BINARIO))
	{
		m_CtrlBinario.AddString((LPCTSTR)szStyle);
	}
	if( szStyle.LoadString(IDS_OCTAL))
	{
		m_CtrlBinario.AddString((LPCTSTR)szStyle);
	}
	if( szStyle.LoadString(IDS_DECIMAL))
	{
		m_CtrlBinario.AddString((LPCTSTR)szStyle);
	}
	if( szStyle.LoadString(IDS_HEXADECIMAL))
	{
		m_CtrlBinario.AddString((LPCTSTR)szStyle);
	}

	
	//Inicializa el combo con formato binario
	 m_CtrlBinario.SetCurSel( 0);

	
	return 0;
 
		  
}


void CMainFrame::OnSelChangeWidth()
{
	int nIndex = m_CtrlBinario.GetCurSel();
	if( (nIndex == CB_ERR))
		return;
/*
char buff[7];
CString s_Index;
s_Index = _itoa( nIndex, buff, 10);
MessageBox("Indice = " + s_Index);
 */

	CMenu* m_pMenu;
	m_pMenu = GetMenu();
	
	switch(nIndex)
	{
		case 0:
		m_pMenu->CheckMenuItem( ID_FORMAT_BINARIO, MF_CHECKED );
		m_pMenu->CheckMenuItem( ID_FORMAT_OCTAL, MF_UNCHECKED);
		m_pMenu->CheckMenuItem( ID_FORMAT_DECIMAL, MF_UNCHECKED);
		m_pMenu->CheckMenuItem( ID_FORMAT_HEXADECIMAL, MF_UNCHECKED);
		break;
		
		case 1:
		m_pMenu->CheckMenuItem( ID_FORMAT_OCTAL, MF_CHECKED | MF_BYCOMMAND );
		m_pMenu->CheckMenuItem( ID_FORMAT_BINARIO, MF_UNCHECKED | MF_BYCOMMAND );
		m_pMenu->CheckMenuItem( ID_FORMAT_DECIMAL, MF_UNCHECKED | MF_BYCOMMAND);
		m_pMenu->CheckMenuItem( ID_FORMAT_HEXADECIMAL, MF_UNCHECKED | MF_BYCOMMAND);
		break;
		case 2:
		m_pMenu->CheckMenuItem( ID_FORMAT_DECIMAL, MF_CHECKED );
		m_pMenu->CheckMenuItem( ID_FORMAT_BINARIO, MF_UNCHECKED );
		m_pMenu->CheckMenuItem( ID_FORMAT_OCTAL, MF_UNCHECKED );
		m_pMenu->CheckMenuItem( ID_FORMAT_HEXADECIMAL, MF_UNCHECKED);
		break;
		case 3:
		m_pMenu->CheckMenuItem( ID_FORMAT_HEXADECIMAL, MF_CHECKED);
		m_pMenu->CheckMenuItem( ID_FORMAT_BINARIO, MF_UNCHECKED);
		m_pMenu->CheckMenuItem( ID_FORMAT_OCTAL, MF_UNCHECKED );
		m_pMenu->CheckMenuItem( ID_FORMAT_DECIMAL, MF_UNCHECKED );
		break;
	}


	/*
	HMENU hMenu;
	  
	switch(nIndex)
	{
		case 0:
		CheckMenuItem( hMenu, ID_FORMAT_BINARIO, MF_CHECKED );
		CheckMenuItem( hMenu, ID_FORMAT_OCTAL, MF_UNCHECKED);
		CheckMenuItem( hMenu, ID_FORMAT_DECIMAL, MF_UNCHECKED);
		CheckMenuItem( hMenu, ID_FORMAT_HEXADECIMAL, MF_UNCHECKED);
		break;
		
		case 1:
		CheckMenuItem( hMenu, ID_FORMAT_OCTAL, MF_CHECKED | MF_BYCOMMAND );
		CheckMenuItem( hMenu,ID_FORMAT_BINARIO, MF_UNCHECKED | MF_BYCOMMAND );
		CheckMenuItem( hMenu, ID_FORMAT_DECIMAL, MF_UNCHECKED | MF_BYCOMMAND);
		CheckMenuItem( hMenu,ID_FORMAT_HEXADECIMAL, MF_UNCHECKED | MF_BYCOMMAND);
		break;
		case 2:
		CheckMenuItem( hMenu,ID_FORMAT_DECIMAL, MF_CHECKED );
		CheckMenuItem( hMenu,ID_FORMAT_BINARIO, MF_UNCHECKED );
		CheckMenuItem( hMenu, ID_FORMAT_OCTAL, MF_UNCHECKED );
		CheckMenuItem( hMenu, ID_FORMAT_HEXADECIMAL, MF_UNCHECKED);
		break;
		case 3:
		CheckMenuItem( hMenu,ID_FORMAT_HEXADECIMAL, MF_CHECKED);
		CheckMenuItem( hMenu, ID_FORMAT_BINARIO, MF_UNCHECKED);
		CheckMenuItem( hMenu, ID_FORMAT_OCTAL, MF_UNCHECKED );
		CheckMenuItem( hMenu, ID_FORMAT_DECIMAL, MF_UNCHECKED );
		break;
	}

	 */

}

