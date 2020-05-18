// Cache2003Doc.h : interface of the CCache2003Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CACHE2003DOC_H__A0C72586_223F_4680_97BF_70110089879B__INCLUDED_)
#define AFX_CACHE2003DOC_H__A0C72586_223F_4680_97BF_70110089879B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCache2003Doc : public CDocument
{
protected: // create from serialization only
	CCache2003Doc();
	DECLARE_DYNCREATE(CCache2003Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCache2003Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	CDatos* BuscarRegistro( CString dir);
	CDatos* EditarRegistros();
	CDatos* AgregarRegistros();
	CDatos* ObtieneUltimo();
	CDatos* ObtieneAnterior();
	CDatos* ObtieneSiguiente();
	CDatos* ObtienePrimero();
	CDatos* ObtenerRegistroActual();
	int ObtenerCurRegistroNbr();
	int ObtenerTotalRegistros();
	virtual ~CCache2003Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCache2003Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	int m_iOpenDoc;
	CParametros* ObtieneUltimoPar();
	CParametros* ObtienePrimeroPar();
	
	CParametros* AgregarParametros();
	void EliminarRegistros(int pos);
	CSecuencia* EditarSecuencia();
	CSecuencia* ObtieneUltimoSec();
	CSecuencia* ObtieneSiguienteSec();
	CSecuencia* ObtieneAnteriorSec();
	CSecuencia* ObtienePrimeroSec();
	CSecuencia* ObtenerSecuenciaActual();
	int ObtenerCurSecuenciaNbr();
	int ObtenerTotalSecuencias();
	CSecuencia* AgregarSecuencia();
	int m_iPosicionSec;
	int m_iPosicion;
	int m_iPosicionPar;
public:	
	void EliminarSecuencia( int pos);
	CDatos* ObtenerRegActual_par ( int pos);
		
	enum { nLinesPerPage = 36 };
	
	CObArray m_arregloDatos;
	CObArray m_arregloSecuencia;
	CObArray m_arregloParametros;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CACHE2003DOC_H__A0C72586_223F_4680_97BF_70110089879B__INCLUDED_)
