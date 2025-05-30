#pragma hdrstop

#include "TLexem.h"

#include <string.h>

#pragma package(smart_init)

//--------------------------------------

TLexem::TLexem()
{
  szText = 0;
  iType=0;
  iValue=0;
  dValue=0.0;	
  iNumStr=0;
  iPosStr=0;
  iPos=0;
}

TLexem::TLexem(TLexem* _pLexem)
{
   szText=0;
   int iLen = strlen(_pLexem->getText());
   szText = new char[iLen+1];
   strcpy(szText,_pLexem->getText());
  iType=_pLexem->getType();
  iValue=_pLexem->getIval();
  dValue=_pLexem->getDval();
  iNumStr=_pLexem->getNumStr();
  iPosStr=_pLexem->getPosStr();
  iPos=_pLexem->getPos();
}

TLexem::TLexem(char* _szText,int _iType, int _iValue, double _dValue, unsigned int _iNumStr, unsigned int _iPosStr, unsigned int _iPos)
{
   szText=0;
   int iLen = strlen(_szText);
   szText = new char[iLen+1]; 
   strcpy(szText,_szText);
  iType=_iType;
  iValue=_iValue;
  dValue=_dValue;
  iNumStr=_iNumStr;
  iPosStr=_iPosStr;
  iPos=_iPos;
}


TLexem::~TLexem()
{
	if(szText != 0)
	
	delete[] szText;
	szText=0;
	

}
void TLexem::setText(char* _szText)
{
if(szText !=0)
	
	delete[] szText;
	szText=0;
	int iLen = strlen(_szText);
	szText = new char[iLen+1];
	strcpy(szText,_szText);
}


const char* TLexem::getText()
{
 return szText;
}


   int TLexem::getLenText()
   {
	return strlen(szText);
   } 

    void TLexem::setType(int _iType)
	{
	iType=_iType;
	}


	 int TLexem::getType()
	 {
	 return iType;
	 }

   void TLexem::setIval(int _iValue)
   {
   iValue=_iValue;
   }

 int TLexem::getIval()
 {
 return iValue;
 }

 void TLexem::setDval(double _dValue)
 {
	 dValue=_dValue;
 }

 double TLexem::getDval()
 {
	return dValue;
 }

 void TLexem::SetNumStr(unsigned int _iNumStr)
 {
	 iNumStr=_iNumStr;
 }

 unsigned int TLexem::getNumStr()
 {
 return iNumStr;
 }

  void TLexem::SetPosStr(unsigned int _iPosStr)
  {
  iPosStr=_iPosStr;
  }


 unsigned int TLexem::getPosStr()
 {
 return iPosStr;
 }

  void TLexem::SetPos(unsigned int _iPos)
  {
  iPos=_iPos;
  }

 unsigned int TLexem::getPos()
 {
 return iPos;
 }