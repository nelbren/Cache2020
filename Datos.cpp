// Datos.cpp: implementation of the CDatos class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Cache2003.h"
#include "Datos.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


IMPLEMENT_SERIAL (CDatos, CObject, 1)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDatos::CDatos()
{
   m_sDireccion = "0";
   m_sDato = "";
   m_iTipo = 1;

}

CDatos::~CDatos()
{

}

void CDatos::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);

	if( ar.IsStoring())
	{
		ar<<m_sDireccion<<m_sDato<<m_iTipo;
	}
	else
	{
		ar>>m_sDireccion>>m_sDato>>m_iTipo;
	}
}
