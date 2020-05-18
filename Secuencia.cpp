// Secuencia.cpp: implementation of the CSecuencia class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Cache2003.h"
#include "Secuencia.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL (CSecuencia, CObject, 1)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSecuencia::CSecuencia()
{
	m_sSecuencia = "1";
	m_sDirSecuencia = "";
}

CSecuencia::~CSecuencia()
{

}

void CSecuencia::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);

	if( ar.IsStoring())
	{
		ar<<m_sSecuencia<<m_sDirSecuencia;
	}
	else
	{
		ar>>m_sSecuencia>>m_sDirSecuencia;
	}
}
