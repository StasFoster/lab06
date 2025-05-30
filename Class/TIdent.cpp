#pragma hdrstop
#include "TIdent.h"
#include <string.h>
#pragma package(smart_init)

TIdent::TIdent(): TLexem()
{
}

TIdent::TIdent(TIdent* _pIdent) : TLexem(_pIdent)
{
}

TIdent:: TIdent(char* _szText,int _iType, int _iValue, double _dValue, unsigned int _iNumStr, unsigned int _iPosStr, unsigned int _iPos):TLexem( _szText, _iType,  _iValue, _dValue,  _iNumStr,  _iPosStr,  _iPos)
{
}

TIdent::~TIdent()
{
}