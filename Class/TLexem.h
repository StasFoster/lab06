#ifndef TLexemH
#define TLexemH

class TLexem
{
	
private:
 char* szText;
 int iType;
 int iValue;
 double dValue;
 unsigned int iNumStr;
 unsigned int iPosStr;
 unsigned int iPos;


	 public:
 TLexem();
  TLexem(TLexem* _pLexem);
  TLexem(char* _szText,int _iType, int _iValue, double _dValue, unsigned int _iNumStr, unsigned int _iPosStr, unsigned int _iPos);

  ~TLexem();

 void setText(char* _szText);
 const char* getText();

  int getLenText();

  void setType(int _iType);
 int getType();

 void setIval(int _iValue);
 int getIval();

 void setDval(double _dValue);
 double getDval();

 void SetNumStr(unsigned int _iNumStr);
 unsigned int getNumStr();

  void SetPosStr(unsigned int _iPosStr);
 unsigned int getPosStr();

  void SetPos(unsigned int _iPos);
 unsigned int getPos();

};
#endif