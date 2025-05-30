#ifndef kaLexH
#define kaLexH

#include "..\Class\TLexemList.h"
#include "..\Class\TIdentList.h"
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>


int kaLex(char* _TaskText, TLexemList** _pLexemList, TIdentList** pIdentList, char* cError);

int kaLexTask(int* kaCurPos,		int* iCurPosText, 
	          char* szText,			char* szCurLex, 
			  int* iLenCurLex,		char cCurChar,
	          int* iNumStrCurLex,   int* iPosStrCurLex,
			  int* iPosCurLex,		int* iTypeCurLex, int* iPosStrCurLexDublikat, 
			  TLexemList* pLexemList, TIdentList* pIdentList);


int kaLexIdent(int* kaCurPos,		int* iCurPosText, 
	          char* szText,			char* szCurLex, 
			  int* iLenCurLex,		char cCurChar,
	          int* iNumStrCurLex,   int* iPosStrCurLex,
			  int* iPosCurLex,		int* iTypeCurLex, int* iPosStrCurLexDublikat,
			  TLexemList* pLexemList, TIdentList* pIdentList);

int kaLexEqual(int* kaCurPos,		int* iCurPosText, 
	          char* szText,			char* szCurLex, 
			  int* iLenCurLex,		char cCurChar,
	          int* iNumStrCurLex,   int* iPosStrCurLex,
			  int* iPosCurLex,		int* iTypeCurLex, int* iPosStrCurLexDublikat,
			  TLexemList* pLexemList, TIdentList* pIdentList);

int kaLexNumeric(int* kaCurPos,		int* iCurPosText, 
	          char* szText,			char* szCurLex, 
			  int* iLenCurLex,		char cCurChar,
	          int* iNumStrCurLex,   int* iPosStrCurLex,
			  int* iPosCurLex,		int* iTypeCurLex, int* iPosStrCurLexDublikat,
			  TLexemList* pLexemList, TIdentList* pIdentList);

int kaLexSemicolon(int* kaCurPos,		int* iCurPosText, 
	          char* szText,			char* szCurLex, 
			  int* iLenCurLex,		char cCurChar,
	          int* iNumStrCurLex,   int* iPosStrCurLex,
			  int* iPosCurLex,		int* iTypeCurLex, int* iPosStrCurLexDublikat,
			  TLexemList* pLexemList, TIdentList* pIdentList);

int kaLexArifmOper(int* kaCurPos,		int* iCurPosText, 
	          char* szText,			char* szCurLex, 
			  int* iLenCurLex,		char cCurChar,
	          int* iNumStrCurLex,   int* iPosStrCurLex,
			  int* iPosCurLex,		int* iTypeCurLex, int* iPosStrCurLexDublikat,
			  TLexemList* pLexemList, TIdentList* pIdentList);

int kaLexOperSravn(int* kaCurPos,		int* iCurPosText, 
	          char* szText,			char* szCurLex, 
			  int* iLenCurLex,		char cCurChar,
	          int* iNumStrCurLex,   int* iPosStrCurLex,
			  int* iPosCurLex,		int* iTypeCurLex, int* iPosStrCurLexDublikat,
			  TLexemList* pLexemList, TIdentList* pIdentList);

int kaLexSpaceEnter(int* kaCurPos,		int* iCurPosText, 
	          char* szText,			char* szCurLex, 
			  int* iLenCurLex,		char cCurChar,
	          int* iNumStrCurLex,   int* iPosStrCurLex,
			  int* iPosCurLex,		int* iTypeCurLex, int* iPosStrCurLexDublikat,
			  TLexemList* pLexemList, TIdentList* pIdentList);

int kaLexError(int* kaCurPos,		int* iCurPosText, 
	          char* szText,			char* szCurLex, 
			  int* iLenCurLex,		char cCurChar,
	          int* iNumStrCurLex,   int* iPosStrCurLex,
			  int* iPosCurLex,		int* iTypeCurLex, int* iPosStrCurLexDublikat,
			  TLexemList* pLexemList, TIdentList* pIdentList, char* cError);

#endif