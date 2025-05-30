#pragma hdrstop

#include "TLexemList.h"

#include <string.h>

#pragma package(smart_init)

TLexemList::TLexemList()
{
 pList	= 0;
 iCount	= 0;
 iMax   = 10;
}

TLexemList::~TLexemList()
{
  if(pList != 0) 
    {
     for(int i=0; i<iCount; i++) 
         {
       TLexem* ptr = pList[i];
	 if(ptr != 0)
         delete ptr;
       ptr = 0;
	 pList[i] = 0;
         }
      delete[] pList;
    }
  pList = 0;
}

int TLexemList::add(TLexem *_pLexem)
{
 if(pList == 0)
  {
    pList = new TLexem*[iMax];
  }
 if (pList != 0)
 {
   if(iCount == iMax)
  {
    iMax += 10;
    TLexem** pNewList = new TLexem*[iMax];
    for(int i=0; i<iCount; i++)
	{
	   pNewList[i] = pList[i];
	   pList[i] = 0;
	} 
      delete[] pList;
      pList = pNewList;
      pNewList = 0;
   }
 if(iCount<iMax)
{
pList[iCount++] = _pLexem;
}
  }
return iCount;
 }


void TLexemList::get(int _iNum, TLexem **_pLexem)
{
if(pList != 0) 
{
if(iCount >= _iNum)
{
*_pLexem = pList[_iNum];
}
}
}


TLexem* TLexemList::take(int _iNum)
{
TLexem *pLexem = 0;
if(pList != 0) 
{
if(iCount >= _iNum)
{
pLexem = pList[_iNum];
pList[_iNum] = 0;
}
}
return pLexem;
}


void TLexemList::set(int _iNum, TLexem *_pLexem)
{
if(pList != 0)
{
if(iCount >= _iNum)
{
TLexem *ptr = pList[_iNum];
if(ptr != 0)
delete ptr;
pList[_iNum] = _pLexem;
}
}
}


int TLexemList::getCount()
{
	return iCount;
}

int TLexemList::getType(int _iNum)
{
int iType = -1;
if(pList != 0)
{
if(iCount >= _iNum)
{
iType = pList[_iNum]->getType();
}
}
return iType;
}

const char* TLexemList::getText(int _iNum)
{
const char* cText = 0;
if(pList != 0)
{
if(iCount >= _iNum)
{
cText = pList[_iNum]->getText();
}
}
return cText;
}


int TLexemList::getLenText(int _iNum)
{
int iLen = 0;
if(pList != 0)
{
if(iCount >= _iNum)
{
iLen = ((TLexem*)(pList[_iNum]))->getLenText();
}
}
return iLen;
}


int TLexemList::clear(int _iNum)
{
int iRet = -1;
if(pList != 0)
{
if(iCount >= _iNum)
{
TLexem *pLexem = pList[_iNum];
if(pLexem != 0)
{
delete pLexem;
iRet = 0;
}
pLexem = 0;
pList[_iNum] = 0;
}
}
return iRet;
}


void TLexemList::sort()
{
int iCount = getCount();
if(iCount > 1)
{
TLexem** pNewList = new TLexem*[iMax];

int iNumMin = 0;
TLexem *pMin = 0;
int iLenMin = 0;
char *szTextMin = 0;

TLexem *pCur = 0;
int iLenCur = 0;
char *szTextCur = 0;

int iLen = 0;

int iSorted = 0;

while(iSorted < iCount)
{
for(int i = iNumMin; i<iCount; i++)
{
pMin = take(i);
if(pMin != 0)
{
iNumMin = i;
iLenMin = pMin->getLenText();
szTextMin = new char[iLenMin+1];
strcpy(szTextMin,pMin->getText());
break;
}
}
if(pMin != 0) 
{
pCur = 0;
for(int i=iNumMin+1; i<iCount; i++)
{
iLenCur = getLenText(i);
if(iLenCur > 0)
{
szTextCur = new char[iLenCur+1];
strcpy(szTextCur,getText(i));
if(iLenMin > iLenCur)
iLen = iLenCur;
else
iLen = iLenMin;
int iEqCount = 0;
char c = 0;
for(int j=0; j<iLen; j++)
{
c = szTextMin[j] - szTextCur[j];
if(c == 0)
{
iEqCount++;
continue;
}
if(c > 0)
{
if(iEqCount == j)
{
pCur = take(i);
set(i,pMin);
if(szTextMin != 0)
delete[] szTextMin;
szTextMin = szTextCur;
szTextCur = 0;
iLenMin = iLenCur;
pMin = pCur;
pCur = 0;
break;
}
}
if(c < 0)
{
break;
}
}
if(szTextCur != 0)
delete[] szTextCur;
szTextCur = 0;
iLenCur = 0;
}
}
if(pMin != 0)
{
pNewList[iSorted++] = pMin;
pMin = 0;
if(szTextMin != 0)
delete[] szTextMin;
szTextMin = 0;
iLenMin = 0;
}
}
else
break;
}
delete[] pList;
pList = pNewList;
pNewList = 0;
}
}