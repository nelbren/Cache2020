#if !defined(AFX_VCFOOTNOTE_H__4C89FC64_DB41_4D95_8A90_E0D1AF833EA4__INCLUDED_)
#define AFX_VCFOOTNOTE_H__4C89FC64_DB41_4D95_8A90_E0D1AF833EA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CVcTextLayout;
class CVcLocation;
class CVcBackdrop;
class CVcFont;
class COleFont;

/////////////////////////////////////////////////////////////////////////////
// CVcFootnote wrapper class

class CVcFootnote : public COleDispatchDriver
{
public:
	CVcFootnote() {}		// Calls COleDispatchDriver default constructor
	CVcFootnote(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CVcFootnote(const CVcFootnote& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CVcTextLayout GetTextLayout();
	CVcLocation GetLocation();
	CVcBackdrop GetBackdrop();
	CVcFont GetVtFont();
	CString GetText();
	void SetText(LPCTSTR lpszNewValue);
	short GetTextLength();
	void SetRefFont(LPDISPATCH newValue);
	COleFont GetFont();
	void Select();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCFOOTNOTE_H__4C89FC64_DB41_4D95_8A90_E0D1AF833EA4__INCLUDED_)
