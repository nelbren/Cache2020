// Cache2003Doc.cpp : implementation of the CCache2003Doc class
//

#include "stdafx.h"
#include "Cache2003.h"


#include "Datos.h"
#include "Secuencia.h"
#include "Parametros.h"
#include "Cache2003View.h"
#include "Cache2003Doc.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCache2003Doc

IMPLEMENT_DYNCREATE(CCache2003Doc, CDocument)

BEGIN_MESSAGE_MAP(CCache2003Doc, CDocument)
	//{{AFX_MSG_MAP(CCache2003Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCache2003Doc construction/destruction

CCache2003Doc::CCache2003Doc()
{
	// TODO: add one-time construction code here

}

CCache2003Doc::~CCache2003Doc()
{
}

BOOL CCache2003Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	
	static int conta = 0;
	char Nuevo[13];
	CFileStatus EstadoFi;
	do
	{
		wsprintf( Nuevo, "Simulacion%02d", conta);
		conta++;
	}
	while (CFile::GetStatus(Nuevo, EstadoFi));
	SetTitle( Nuevo );
	
		
	if( !AgregarRegistros() || !AgregarSecuencia() || !AgregarParametros())
		return FALSE;
	
	
	
	POSITION pos = GetFirstViewPosition();
	CCache2003View* pView = (CCache2003View*)GetNextView(pos); 
	
	//CCache2003View* pView = (CCache2003View*)m_viewList.GetHead();

	
	if( pView )
	{
		
		pView->PonerNuevoDato();
		pView->PonerNuevoSec();
		pView->PonerNuevoPar();
		pView->Nuevo();
		
		pView->LimpiarEdit(); 
		pView->LimpiarRejilla_MP();
		pView->LimpiarRejilla_MC();
			
	}
	
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCache2003Doc serialization

void CCache2003Doc::Serialize(CArchive& ar)
{
	
	m_arregloDatos.Serialize( ar );
	m_arregloSecuencia.Serialize( ar );
	m_arregloParametros.Serialize( ar );
	
/*
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
*/
}

/////////////////////////////////////////////////////////////////////////////
// CCache2003Doc diagnostics

#ifdef _DEBUG
void CCache2003Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCache2003Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCache2003Doc commands

CDatos* CCache2003Doc::AgregarRegistros()
{
   CDatos *pDato = new CDatos();
	
    try
	{
		m_arregloDatos.Add(pDato);
		SetModifiedFlag();
		m_iPosicion = (m_arregloDatos.GetSize() - 1);

	}
	catch (CMemoryException* perr)
	{
		AfxMessageBox("Fuera de memoria", MB_ICONSTOP | MB_OK);
		if( pDato)
		{
			delete pDato;
			pDato = NULL;
		}
		perr->Delete();
	}
	return pDato;

}

int CCache2003Doc::ObtenerTotalRegistros()
{
	  return m_arregloDatos.GetSize()-1;
}

int CCache2003Doc::ObtenerCurRegistroNbr()
{
	 return (m_iPosicion + 1);
}


CDatos* CCache2003Doc::ObtenerRegistroActual()
{
	if (m_iPosicion >= 0)
	{
		return (CDatos*)m_arregloDatos[m_iPosicion];
	}
	else
	{
		return NULL;
	}

}

CDatos* CCache2003Doc::ObtienePrimero()
{
	if(m_arregloDatos.GetSize() > 0)
	{
		m_iPosicion = 0;
		return (CDatos*)m_arregloDatos[0];
	}
	else
	{
		return NULL;
	}
}

CDatos* CCache2003Doc::ObtieneSiguiente()
{
   if( ++m_iPosicion < m_arregloDatos.GetSize())
   {
		return (CDatos*)m_arregloDatos[m_iPosicion];
   }
   else
   {
		m_iPosicion = m_arregloDatos.GetSize() - 1;
		return (CDatos*)m_arregloDatos[m_iPosicion];

   }

}

CDatos* CCache2003Doc::ObtieneAnterior()
{
	if(m_arregloDatos.GetSize() > 0)
	{
		if( --m_iPosicion < 0)
		{
			m_iPosicion = 0;
		}
		return (CDatos*)m_arregloDatos[m_iPosicion];
	}
	else
	{
		return NULL;
	}

}

CDatos* CCache2003Doc::ObtieneUltimo()
{
	if( m_arregloDatos.GetSize() > 0)
	{
		 m_iPosicion = (m_arregloDatos.GetSize() - 2);
		 
		 return (CDatos*)m_arregloDatos[m_iPosicion];
	 }
	 else
	 {
		 return NULL;
	 }

}

void CCache2003Doc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	int liContador = m_arregloDatos.GetSize();
	int liPos;

	if( liContador )
	{
		for( liPos = 0; liPos < liContador; liPos++)
					delete m_arregloDatos[ liPos ];
		m_arregloDatos.RemoveAll();
	}

	liContador = m_arregloSecuencia.GetSize();
	
	if( liContador )
	{
		for( liPos = 0; liPos < liContador; liPos++)
					delete m_arregloSecuencia[ liPos ];
		m_arregloSecuencia.RemoveAll();
	}

	liContador = m_arregloParametros.GetSize();
	
	if( liContador )
	{
		for( liPos = 0; liPos < liContador; liPos++)
					delete m_arregloParametros[ liPos ];
		m_arregloParametros.RemoveAll();
	}

	CDocument::DeleteContents();
}

BOOL CCache2003Doc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	
	POSITION pos = GetFirstViewPosition();
	CCache2003View* pView = (CCache2003View*)GetNextView(pos);
	
	m_iOpenDoc = 30;

	if( pView )
	{
		pView->PonerNuevoDato();
		pView->PonerNuevoSec();
		pView->PonerNuevoPar();
		pView->GeneraTamMP();
		pView->LimpiarRejilla_MP();
		pView->LimpiarRejilla_MC();
		pView->LlenarMP_OpenDoc();
		
	}
	
	return TRUE;
}

CDatos* CCache2003Doc::EditarRegistros()
{
	

  /*
    CObject* pObjeto;
	CDatos *pDato = new CDatos();
    
	CString s_pos;
	char buffer[10];
	s_pos = _itoa( m_iPosicion, buffer, 10);
	AfxMessageBox("pos  " + s_pos);
	

	
    if( ( pObjeto = m_arregloDatos.GetAt( m_iPosicion ) ) != NULL )
    {
       
	  
	   m_arregloDatos.SetAt( m_iPosicion, pDato);  // Replace element 0.
       delete pObjeto; // Delete the original element at 0.
       AfxMessageBox("Entro al if"); 	  	  	  	  	  
	}
	*/

	//Elimina el ultimo registro
	int iLongitud = m_arregloDatos.GetSize()-1;//recoje la longitud de el arreglo
	if(iLongitud)
	{
			
		delete m_arregloDatos[iLongitud]; //elimina los nodos 1 por 1

		m_arregloDatos.RemoveAt(iLongitud);//renueva el arreglo
		
		
		POSITION pos = GetFirstViewPosition();
		CCache2003View *pView = (CCache2003View*)GetNextView(pos);
		
		if(iLongitud-1 == m_iPosicion)
		{
			m_iPosicion--;
		}
		pView->PosicionActual();  
		SetModifiedFlag();	
	}

   	//Repite función agregar
	
	CDatos *pDato = new CDatos();
	try
	{
		m_arregloDatos.Add(pDato);
		SetModifiedFlag();
		m_iPosicion = (m_arregloDatos.GetSize() - 1);

	}
	catch (CMemoryException* perr)
	{
		AfxMessageBox("Fuera de memoria", MB_ICONSTOP | MB_OK);
		if( pDato)
		{
			delete pDato;
			pDato = NULL;
		}
		perr->Delete();
	}
	return pDato;


}

CDatos* CCache2003Doc::BuscarRegistro(CString dir)
{
  int pos, iLongitud, band;
  CDatos *Reg;
	iLongitud = m_arregloDatos.GetSize();
	band = 0;
	for(pos=0; pos<iLongitud; pos++)
	{
		Reg = (CDatos*)m_arregloDatos[pos];
		if(dir == Reg->GetDireccion())
		{
			band=1;
			break;
		}
	}
	if(band)
	{
		m_iPosicion = pos;
	}
	else
	{
		AfxMessageBox("Registro no encontrado!");
	}
	return (CDatos*)m_arregloDatos[m_iPosicion];

}

CSecuencia* CCache2003Doc::AgregarSecuencia()
{
	CSecuencia *pSec = new CSecuencia();
	try
	{
		m_arregloSecuencia.Add(pSec);
		SetModifiedFlag();
		m_iPosicionSec = (m_arregloSecuencia.GetSize() - 1);

	}
	catch (CMemoryException* perr)
	{
		AfxMessageBox("Fuera de memoria", MB_ICONSTOP | MB_OK);
		if( pSec)
		{
			delete pSec;
			pSec = NULL;
		}
		perr->Delete();
	}
	return pSec;

}

int CCache2003Doc::ObtenerTotalSecuencias()
{
	return m_arregloSecuencia.GetSize() -1;
}


int CCache2003Doc::ObtenerCurSecuenciaNbr()
{
	
	return (m_iPosicionSec + 1);
		
}

CSecuencia* CCache2003Doc::ObtenerSecuenciaActual()
{
	
	if (m_iPosicionSec >= 0)
	{
		return (CSecuencia*)m_arregloSecuencia[m_iPosicionSec];
	}
	else
	{
		return NULL;
	}


}

CSecuencia* CCache2003Doc::ObtienePrimeroSec()
{
	if(m_arregloSecuencia.GetSize() > 0)
	{
		m_iPosicionSec = 0;
		return (CSecuencia*)m_arregloSecuencia[0];
	}
	else
	{
		return NULL;
	}

}

CSecuencia* CCache2003Doc::ObtieneAnteriorSec()
{
	if(m_arregloSecuencia.GetSize() > 0)
	{
		if( --m_iPosicionSec < 0)
		{
			m_iPosicionSec = 0;
		}
		return (CSecuencia*)m_arregloSecuencia[m_iPosicionSec];
	}
	else
	{
		return NULL;
	}

}

CSecuencia* CCache2003Doc::ObtieneSiguienteSec()
{
   if( ++m_iPosicionSec < m_arregloSecuencia.GetSize())
   {
		return (CSecuencia*)m_arregloSecuencia[m_iPosicionSec];
   }
   else
   {
		m_iPosicionSec = m_arregloSecuencia.GetSize() - 1;
		return (CSecuencia*)m_arregloSecuencia[m_iPosicionSec];

   }

}

CSecuencia* CCache2003Doc::ObtieneUltimoSec()
{
	if( m_arregloSecuencia.GetSize() > 0)
	{
		 m_iPosicionSec = (m_arregloSecuencia.GetSize() - 2);
		 
		 return (CSecuencia*)m_arregloSecuencia[m_iPosicionSec];
	 }
	 else
	 {
		 return NULL;
	 }

}

CSecuencia* CCache2003Doc::EditarSecuencia()
{
	int iLongitud = m_arregloSecuencia.GetSize()-1;//recoje la longitud de el arreglo
	if(iLongitud)
	{
			
		delete m_arregloSecuencia[iLongitud]; //elimina los nodos 1 por 1

		m_arregloSecuencia.RemoveAt(iLongitud);//renueva el arreglo
		
		POSITION pos = GetFirstViewPosition();
		CCache2003View *pView = (CCache2003View*)GetNextView(pos);
		if(iLongitud-1 == m_iPosicionSec)
		{
			m_iPosicionSec--;
		}
		pView->PosicionActualSec();
		SetModifiedFlag();	
	}

   	//Repite función agregar
	
	CSecuencia *pSec = new CSecuencia();
	try
	{
		m_arregloSecuencia.Add(pSec);
		SetModifiedFlag();
		m_iPosicionSec = (m_arregloSecuencia.GetSize() - 1);

	}
	catch (CMemoryException* perr)
	{
		AfxMessageBox("Fuera de memoria", MB_ICONSTOP | MB_OK);
		if( pSec)
		{
			delete pSec;
			pSec = NULL;
		}
		perr->Delete();
	}
	return pSec;


}

void CCache2003Doc::EliminarRegistros( int pos)
{
/*    
char buffer[5];
CString s_pos;
CString s_tam; */
	m_iPosicion = pos-1;
	int iLongitud = m_arregloDatos.GetSize() - 1;//recoje la longitud de el arreglo
	
	//s_tam = _itoa( iLongitud  , buffer, 10);
	//AfxMessageBox(" Longitud del arreglo = " + s_tam);
	if(iLongitud> 0 )
	{
			
		delete m_arregloDatos[m_iPosicion];//elimina los nodos 1 por 1

		m_arregloDatos.RemoveAt(m_iPosicion);//renueva el arreglo
		
		//s_pos = _itoa( m_iPosicion  , buffer, 10);
		//AfxMessageBox(" Eliminada Posicion = " + s_pos);
	  
		
		POSITION pos = GetFirstViewPosition();
		CCache2003View *pView = (CCache2003View*)GetNextView(pos);
		if(iLongitud-1 == m_iPosicion)
		{
			m_iPosicion--;
		}
		pView->PosicionActual(); 
		SetModifiedFlag();	
	}	
	/*
	if(!m_arregloDatos.GetSize())
	{
		AgregarRegistros();
		POSITION pos = GetFirstViewPosition();
		CCache2003View *pView = (CCache2003View*)GetNextView(pos);
		pView->PosicionActual();
	}		
	  
	  */
}

CParametros* CCache2003Doc::AgregarParametros()
{
   CParametros *pParametro = new CParametros();
	try
	{
		m_arregloParametros.Add(pParametro);
		SetModifiedFlag();
		m_iPosicionPar = (m_arregloDatos.GetSize() - 1);

	}
	catch (CMemoryException* perr)
	{
		AfxMessageBox("Fuera de memoria", MB_ICONSTOP | MB_OK);
		if( pParametro)
		{
			delete pParametro;
			pParametro = NULL;
		}
		perr->Delete();
	}
	return pParametro;
}

CParametros* CCache2003Doc::ObtienePrimeroPar()
{
  if(m_arregloParametros.GetSize() > 0)
  {
		m_iPosicionPar = 0;
		return (CParametros*)m_arregloParametros[0];
	}
	else
	{
		return NULL;
	}

}

CParametros* CCache2003Doc::ObtieneUltimoPar()
{
	if( m_arregloParametros.GetSize() > 0)
	{
		 m_iPosicionPar = (m_arregloParametros.GetSize() - 1 );
		 
		 return (CParametros*)m_arregloParametros[m_iPosicionPar];
	 }
	 else
	 {
		 return NULL;
	 }


}


CDatos* CCache2003Doc::ObtenerRegActual_par(int pos)
{
	if (m_iPosicion >= 0)
	{
		return (CDatos*)m_arregloDatos[pos];
	}
	else
	{
		return NULL;
	}

}

BOOL CCache2003Doc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	CCache2003View *pView = (CCache2003View *)m_viewList.GetHead();
	pView->AgregarPar();
		
	return CDocument::OnSaveDocument(lpszPathName);
}

void CCache2003Doc::EliminarSecuencia(int pos)
{
	m_iPosicionSec = pos-1;
	int iLongitud = m_arregloSecuencia.GetSize() - 1;//recoje la longitud de el arreglo
	
	//s_tam = _itoa( iLongitud  , buffer, 10);
	//AfxMessageBox(" Longitud del arreglo = " + s_tam);
	if(iLongitud> 0 )
	{
			
		delete m_arregloSecuencia[m_iPosicionSec];//elimina los nodos 1 por 1

		m_arregloSecuencia.RemoveAt(m_iPosicionSec);//renueva el arreglo
		
		//s_pos = _itoa( m_iPosicion  , buffer, 10);
		//AfxMessageBox(" Eliminada Posicion = " + s_pos);
	  
		
		POSITION pos = GetFirstViewPosition();
		CCache2003View *pView = (CCache2003View*)GetNextView(pos);
		if(iLongitud-1 == m_iPosicionSec)
		{
			m_iPosicionSec--;
		}
		pView->PosicionActualSec(); 
		SetModifiedFlag();	
	}	

}
