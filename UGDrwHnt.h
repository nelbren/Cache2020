/*************************************************************************
				Class Declaration : CUGDrawHint
**************************************************************************
	Source file : UGDrwHnt.cpp
	Header file : UGDrwHnt.h
// This software along with its related components, documentation and files ("The Libraries")
// is © 1994-2007 The Code Project (1612916 Ontario Limited) and use of The Libraries is
// governed by a software license agreement ("Agreement").  Copies of the Agreement are
// available at The Code Project (www.codeproject.com), as part of the package you downloaded
// to obtain this file, or directly from our office.  For a copy of the license governing
// this software, you may contact us at legalaffairs@codeproject.com, or by calling 416-849-8900.

	Purpose
		This class is used internally by the grid
		to keep track of which cells need redrawing
		The grid draws its cells in an extremely
		optimized manner which gives it is great
		speed.

		This is the class which helps the optimization
		process by maintaining a list of cells that
		need to be redrawn.

		When the grid is doing the drawing it calls
		IsInvalid function to see if a cell needs
		to be redrawn.
************************************************/
#ifndef _UGDrwHnt_H_
#define _UGDrwHnt_H_

#include <cstdint>

//drawing hint linked list structure
typedef struct UGDrwHintListTag
{
	int startCol;
	int64_t startRow;
	int endCol;
	int64_t endRow;
	
	UGDrwHintListTag * next;

}UGDrwHintList;

typedef struct UGDrwHintVListTag
{
	int Col;
	int64_t Row;
	
	UGDrwHintVListTag * next;

}UGDrwHintVList;

//drawing hint class
class UG_CLASS_DECL CUGDrawHint
{
private:
	UGDrwHintList * m_List;
	UGDrwHintVList * m_VList;

	int  m_minCol,m_maxCol;
	int64_t m_minRow,m_maxRow;

	int  m_vMinCol,m_vMaxCol;
	int64_t m_vMinRow,m_vMaxRow;

public:
	CUGDrawHint();
	~CUGDrawHint();

	void AddHint(int col,int64_t row);
	void AddHint(int startCol,int64_t startRow,int endCol,int64_t endRow);

	void AddToHint(int col,int64_t row);
	void AddToHint(int startCol,int64_t startRow,int endCol,int64_t endRow);
	void ClearHints();

	BOOL IsInvalid(int col,int64_t row);
	BOOL IsValid(int col,int64_t row);
	int GetTotalRange(int *startCol,int64_t *startRow,int *endCol,int64_t *endRow);

	void SetAsValid(int col,int64_t row);
	void SetAsValid(int startCol,int64_t startRow,int endCol,int64_t endRow);
};

#endif // _UGDrwHnt_H_