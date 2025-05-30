#pragma hdrstop
#include "TIdentList.h"
#include <string.h>
#pragma package(smart_init)

TIdentList::TIdentList() : TLexemList()
{
}

TIdentList::~TIdentList()
{
}

int TIdentList::addIdent(TIdent *_pIdent)
{
	int iNumIdent = -1;
	iNumIdent = getNum(_pIdent);
    if(iNumIdent < 0) 
	{
		iNumIdent = add((TLexem*) _pIdent) - 1;
		iNumIdent = getCount() - 1;
	}
	return iNumIdent;
}

int TIdentList::getNum(TIdent *_pIdent)
{
	int iNumIdent = -1;
	int iCount = getCount();
	if(iCount > 0)
	{
		TLexem *pLexem = 0;
		int iLenLexem = 0;
		int iLenIdent = _pIdent->getLenText();
		char *szTextIdent = new char[iLenIdent+1];
		strcpy(szTextIdent, _pIdent->getText());
		char *szTextLexem = 0;
		
		for(int i = 0; i < iCount; i++)
		{
			pLexem = 0;
			get(i, &pLexem);
			if(pLexem != 0)
			{
				iLenLexem = pLexem->getLenText();
				if(iLenLexem == iLenIdent)
				{
					szTextLexem = new char[iLenLexem+1];
					strcpy(szTextLexem, pLexem->getText());
					bool isEqu = true;
					for(int j = 0; j < iLenIdent; j++)
					{
						if(szTextLexem[j] != szTextIdent[j])
						{
							isEqu = false;
							break;
						}
					}
					if(isEqu)
					{
						iNumIdent = i;
						delete[] szTextLexem;
						break;
					}
					delete[] szTextLexem;
				}
			}
		}
		delete[] szTextIdent;
	}
	return iNumIdent;
}
     