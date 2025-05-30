#ifndef TLexemListH
#define TLexemListH

#include "TLexem.h"
class TLexemList
{
private:
	TLexem** pList;
	int iCount;
	int iMax;
public:
	TLexemList();
	~TLexemList();
int  add(TLexem* _pLexem);
void set(int _iNum, TLexem*  _pLexem);
void get(int _iNum, TLexem** _pLexem);
TLexem* take(int _iNum);
int getCount();
int getType(int _iNum);
const char* getText(int _iNum);
int getLenText(int _iNum);
int clear(int _iNum);
void sort();
};
#endif