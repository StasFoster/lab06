#ifndef TIdentListH
#define TIdentListH

#include "TIdent.h"
#include "TLexemList.h"

class TIdentList : public TLexemList
{
private:
public:
	TIdentList();
	~TIdentList();
	int addIdent(TIdent* _pIdent);
	int getNum(TIdent *_pIdent);
};
#endif