// Parametros.cpp: implementation of the CParametros class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Cache2003.h"
#include "Parametros.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL (CParametros, CObject, 0)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParametros::CParametros()
{
   m_nMP = 0;
   m_nMC = 0;
   m_nBloque = 0;
   m_nVias = "2";
   m_iP_Emplazamiento = 1;
   m_iP_Reemplazamiento = 0;
   m_TamMP = 0;
   m_TamMC = 0;
   m_TamBloque = 0;
   m_sMet_Emplaza = "";
   m_sMet_Reemplaza = "";
   m_iTip_Esc = 0;
   m_iAsignacion = 0; 
   m_in_Bloques_MP = 0;
   m_in_Bloques_MC = 0;
   m_nBloqueConjunto = 0;
   m_fTc = 0;
   m_fTp = 0;
   m_iParalelo = 0;
   m_iBasico = 0;
   m_iAutomatico_Sec = 0;
   m_iAutomatico = 0;
   m_inSec = 0;
   m_nEscrituras = 0;

}

CParametros::~CParametros()
{

}

void CParametros::Serialize(CArchive &ar)
{
   CObject::Serialize(ar);

	if( ar.IsStoring())
	{
		ar<<m_nMP<<m_nMC<<m_nBloque<<m_nVias<<m_iP_Emplazamiento<<m_iP_Reemplazamiento<<m_TamMP<<m_TamMC<<m_TamBloque<<m_sMet_Emplaza<<m_sMet_Reemplaza<<m_iTip_Esc<<m_iAsignacion<<m_in_Bloques_MP<<m_in_Bloques_MC<<m_nBloqueConjunto<<m_fTc<<m_fTp<<m_iParalelo<<m_iBasico<<m_iAutomatico_Sec<<m_iAutomatico<<m_inSec<<m_nEscrituras;
	}
	else
	{
		ar>>m_nMP>>m_nMC>>m_nBloque>>m_nVias>>m_iP_Emplazamiento>>m_iP_Reemplazamiento>>m_TamMP>>m_TamMC>>m_TamBloque>>m_sMet_Emplaza>>m_sMet_Reemplaza>>m_iTip_Esc>>m_iAsignacion>>m_in_Bloques_MP>>m_in_Bloques_MC>>m_nBloqueConjunto>>m_fTc>>m_fTp>>m_iParalelo>>m_iBasico>>m_iAutomatico_Sec>>m_iAutomatico>>m_inSec>>m_nEscrituras;
	}

}
