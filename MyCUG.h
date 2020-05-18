// MyCUG.h : interface of the MyCug class
//
/////////////////////////////////////////////////////////////////////////////
#include "ugctrl.h"

#define COLS 2

struct _tagRow
{
	int m_colData[COLS];
};

class MyCug:public CUGCtrl
{
public:
	MyCug();
	~MyCug();

protected:
	//CArray<_tagRow,_tagRow> m_data;
	//int m_data[17179869184][4];
	int m_data[16777216][COLS] ;
	//int m_data2[16777216];
	//static int tmparray[700000000];
	//char b[2ULL * 1024 * 1024 * 1024];

private:

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	//}}AFX_VIRTUAL

	
	//{{AFX_MSG(MyCug)
	// NOTE - the ClassWizard will add and remove member functions here.
	//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	//***** Over-ridable Notify Functions *****
	virtual void OnSetup();

	//mouse and key strokes
	virtual void OnDClicked(int col,int64_t row,RECT *rect,POINT *point,BOOL processed);
	virtual void OnCharDown(UINT *vcKey,BOOL processed);
	//GetCellIndirect notification
	virtual void OnGetCell(int col,int64_t row,CUGCell *cell);
	//SetCell notification
	//virtual void OnSetCell(int col,int64_t row,CUGCell *cell);
	virtual void OnSetCell(int col, int64_t row, CUGCell* cell);
	//editing
	virtual int OnEditVerify(int col,int64_t row,CWnd *edit,UINT *vcKey);
};
