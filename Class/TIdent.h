#ifndef TIdentH
#define TIdentH

#include "TLexem.h"
class TIdent: public TLexem
{
	
 private:
public:
	TIdent();
	 TIdent(TIdent* _pIdent);
  TIdent(char* _szText,int _iType, int _iValue, double _dValue, unsigned int _iNumStr, unsigned int _iPosStr, unsigned int _iPos);

  ~TIdent();
};
#endif