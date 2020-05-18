// Datos.h: interface for the CDatos class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATOS_H__844069EE_2D04_4426_BE8C_851836CB1CA2__INCLUDED_)
#define AFX_DATOS_H__844069EE_2D04_4426_BE8C_851836CB1CA2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDatos : public CObject  
{

	DECLARE_SERIAL (CDatos)

public:
	virtual void Serialize( CArchive &ar);
	
	CDatos();
	virtual ~CDatos();
	
	//Funciones Set
	
	void SetDireccion( CString sDireccion)
	{
		m_sDireccion = sDireccion;
	}
	void SetDato( CString sDato)
	{
		m_sDato = sDato;
	}
	void SetTipo( int iTipo)
	{
		m_iTipo = iTipo;
	}
	
	//Funciones Get
	
	CString GetDireccion()
	{
		return m_sDireccion;
	}
	CString GetDato()
	{
		return m_sDato;
	}
	int GetTipo()
	{
		return m_iTipo;
	}


private:
	CString m_sDireccion;
	CString m_sDato;
	int m_iTipo;


};

#endif // !defined(AFX_DATOS_H__844069EE_2D04_4426_BE8C_851836CB1CA2__INCLUDED_)
