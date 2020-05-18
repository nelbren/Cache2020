// Secuencia.h: interface for the CSecuencia class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SECUENCIA_H__9CCAC83C_5EED_4C2F_A900_87F34ED39F14__INCLUDED_)
#define AFX_SECUENCIA_H__9CCAC83C_5EED_4C2F_A900_87F34ED39F14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSecuencia : public CObject  
{

	DECLARE_SERIAL (CSecuencia)

public:
	virtual void Serialize( CArchive &ar );
	CSecuencia();
	virtual ~CSecuencia();

	//Funciones Set
	
	void SetSecuencia( CString sSecuencia)
	{
		m_sSecuencia = sSecuencia;
	}
	void SetDirSecuencia( CString sDirSecuencia)
	{
		m_sDirSecuencia = sDirSecuencia;
	}
	
	
	//Funciones Get
	
	CString GetSecuencia()
	{
		return m_sSecuencia;
	}
	CString GetDirSecuencia()
	{
		return m_sDirSecuencia;
	}
	


private:
	CString m_sSecuencia;
	CString m_sDirSecuencia;

};

#endif // !defined(AFX_SECUENCIA_H__9CCAC83C_5EED_4C2F_A900_87F34ED39F14__INCLUDED_)
