// Parametros.h: interface for the CParametros class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARAMETROS_H__9C74C47A_B1F9_4CDE_8D61_D60511C78AEE__INCLUDED_)
#define AFX_PARAMETROS_H__9C74C47A_B1F9_4CDE_8D61_D60511C78AEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CParametros : public CObject  
{

	DECLARE_SERIAL (CParametros)


public:
	virtual void Serialize( CArchive &ar);
	
	CParametros();
	virtual ~CParametros();


	//Funciones Set
	
	void SetnMP( int i_nMP)
	{
		m_nMP = i_nMP;
	}
	void SetnMC( int i_nMC)
	{
		m_nMC = i_nMC;
	}
	void SetnBloque( int i_nBloque)
	{
		m_nBloque = i_nBloque;
	}
	void SetnVias( CString s_nVias)
	{
		m_nVias = s_nVias;
	}
	void SetP_Emplazamiento( int iP_Emplazamiento)
	{
		m_iP_Emplazamiento = iP_Emplazamiento;
	}
	void SetP_Reemplazamiento( int iP_Reemplazamiento)
	{
		m_iP_Reemplazamiento = iP_Reemplazamiento;
	}
	void SetTamMP( int i_TamMP)
	{
		m_TamMP = i_TamMP;
	}
	void SetTamMC( int i_TamMC)
	{
		m_TamMC = i_TamMC;
	}
	void SetTamBloque( int i_TamBloque)
	{
		m_TamBloque = i_TamBloque;
	}
	void SetMet_Emplaza( CString sMet_Emplaza)
	{
		m_sMet_Emplaza = sMet_Emplaza;
	}
	void SetMet_Reemplaza( CString sMet_Reemplaza)
	{
		m_sMet_Reemplaza = sMet_Reemplaza;
	}
	void SetTipo_Esc( int iTip_Esc)
	{
		m_iTip_Esc = iTip_Esc;
	}
	void SetAsignacion( int iAsignacion)
	{
		m_iAsignacion = iAsignacion;
	}
	void SetnBloques_MP( int in_Bloques_MP )
	{
		m_in_Bloques_MP = in_Bloques_MP;
	}
	void SetnBloques_MC( int in_Bloques_MC )
	{
		m_in_Bloques_MC = in_Bloques_MC;
	}
	void SetnBloqueConjunto( int in_BloqueConjunto)
	{
		m_nBloqueConjunto = in_BloqueConjunto;
	}
	
	void SetTc( float fTc)
	{
		m_fTc = fTc;
	}	
	void SetTp( float fTp)
	{
		m_fTp = fTp;
	}
	void SetParalelo( int iParalelo)
	{
		m_iParalelo = iParalelo;
	}
	void SetBasico( int iBasico )
	{
		m_iBasico = iBasico;
	}
	void SetAutomatico_Sec( int iAutomatico_Sec )
	{
		m_iAutomatico_Sec = iAutomatico_Sec;
	}
	void SetAutomatico( int iAutomatico)
	{
		m_iAutomatico = iAutomatico;
	}
	void SetnSec( int inSec)
	{
		m_inSec = inSec;
	}
	void SetnEscrituras( int inEscrituras)
	{
		m_nEscrituras = inEscrituras;
	}


	
	//Funciones Get
	
	int GetnMP()
	{
		return m_nMP;
	}
	int GetnMC()
	{
		return m_nMC;
	}
	int GetnBloque()
	{
		return m_nBloque;
	}
	CString GetnVias()
	{
		return m_nVias;
	}
	int GetP_Emplazamiento()
	{
		return 0; // m_iP_Emplazamiento;  // 2020-05-17 - Check this out - nelbren
	}
	int GetP_Reemplazamiento()
	{
		return m_iP_Reemplazamiento;
	}
	int GetTamMP()
	{
		return m_TamMP;
	}
	int GetTamMC()
	{
		return m_TamMC;
	}
	int GetTamBloque()
	{
		return m_TamBloque;
	}
	CString GetMet_Emplaza()
	{
		return m_sMet_Emplaza;
	}
	CString GetMet_Reemplaza()
	{
		return m_sMet_Reemplaza;
	}
	int GetTip_Esc()
	{
		return m_iTip_Esc;
	}
	int GetAsignacion()
	{
		return m_iAsignacion;
	}
	int GetnBloques_MP()
	{
		return m_in_Bloques_MP;
	}
	int GetnBloques_MC()
	{
		return m_in_Bloques_MC;
	}
	int GetnBloqueConjunto()
	{
		return m_nBloqueConjunto;
	}
	

	float GetTc()
	{
		return m_fTc;
	}
	float GetTp()
	{
		return m_fTp;
	}
	int GetParalelo()
	{
		return m_iParalelo;
	}
	int GetBasico()
	{
		return m_iBasico;
	}
	int GetAutomatico_Sec()
	{
		return m_iAutomatico_Sec;
	}
	int GetAutomatico()
	{
		return m_iAutomatico;
	}
	int GetnSec()
	{
		return m_inSec;
	}
	int GetnEscrituras()
	{
		return m_nEscrituras;
	}



private:
	int m_nMP;
	int m_nMC;
	int m_nBloque;
	CString m_nVias;
	int m_iP_Emplazamiento;
	int m_iP_Reemplazamiento;
	int m_TamMP;
	int m_TamMC;
	int m_TamBloque;
	CString m_sMet_Emplaza;
	CString m_sMet_Reemplaza;
	int m_iTip_Esc;
	int m_iAsignacion;
	int m_in_Bloques_MP;
	int m_in_Bloques_MC;
	int m_nBloqueConjunto;
	float m_fTc;
	float m_fTp;
	int m_iParalelo;
	int m_iBasico;
	int m_iAutomatico_Sec;
	int m_iAutomatico;
	int m_inSec;
	int m_nEscrituras;

};

#endif // !defined(AFX_PARAMETROS_H__9C74C47A_B1F9_4CDE_8D61_D60511C78AEE__INCLUDED_)
