#include "kaLex.h"
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace System;

 static int iPosStrCurLexDublikat = 0;

enum KaPos						
{
	kaPosTask,								
	kaPosIdent,								
	kaPosNumeric,
	kaPosEqual,							  
	kaPosSemicolon,	
	kaPosError,								
	kaPosSuccess,	
	kaPosArifmOper,
	kaPosOperSravn,
	kaPosSpace,								
	kaPosEnter,
	kaPosIf,
	kaPosElse,
	kaPosEnd,
};

enum KaTerm          
{
	kaTerm_Space =' ',					
	kaTerm_a='a',						
	kaTerm_b='b',						
	kaTerm_c='c',						
	kaTerm_d='d',						
	kaTerm_e='e',						
	kaTerm_f='f',						
	kaTerm_g='g',						
	kaTerm_h='h',						
	kaTerm_i='i',						
	kaTerm_j='j',						
	kaTerm_k='k',								
	kaTerm_l='l',						
	kaTerm_m='m',						
	kaTerm_n='n',						
	kaTerm_o='o',						
	kaTerm_p='p',						
	kaTerm_q='q',						
	kaTerm_r='r',						
	kaTerm_s='s',						
	kaTerm_t='t',						
	kaTerm_u='u',						
	kaTerm_v='v',					
	kaTerm_w='w',						
	kaTerm_x='x',						
	kaTerm_y='y',						
	kaTerm_z='z',						
	kaTerm_A='A',						
	kaTerm_B='B',						
	kaTerm_C='C',						
	kaTerm_D='D',						
	kaTerm_E='E',						
	kaTerm_F='F',						
	kaTerm_G='G',						
	kaTerm_H='H',						
	kaTerm_I='I',						
	kaTerm_J='J',						
	kaTerm_K='K',						
	kaTerm_L='L',						
	kaTerm_M='M',						
	kaTerm_N='N',						
	kaTerm_O='O',						
	kaTerm_P='P',						
	kaTerm_Q='Q',						
	kaTerm_R='R',						
	kaTerm_S='S',						
	kaTerm_T='T',						
	kaTerm_U='U',						
	kaTerm_V='V',						
	kaTerm_W='W',						
	kaTerm_X='X',						
	kaTerm_Y='Y',						
	kaTerm_Z='Z',						
	kaTerm_0='0',						
	kaTerm_1='1',						
	kaTerm_2='2',						
	kaTerm_3='3',						
	kaTerm_4='4',						
	kaTerm_5='5',						
	kaTerm_6='6',						
	kaTerm_7='7',						
	kaTerm_8='8',						
	kaTerm_9='9',
	kaTerm_minus			= '-',
	kaTerm_Podch			= '_',
	kaTerm_Plus				= '+',
	kaTerm_Point			= '.',	
	kaTerm_Semicolon        = ';',		
	kaTerm_Equal			= '=',	
	kaTerm_Delite			= '/',
	kaTerm_ZnakBolshe       = '>',			
	kaTerm_ZnakMenshe		= '<',		
	kaTerm_Ymnozh			= '*',
	kaTerm_Enter			=  13,		
	kaTerm_Pystoi			= '\0'		
};

int kaLex(char* szText, TLexemList** pLexemList, TIdentList** pIdentList, char* cError)
{
	int iRet = 0;
	
	if(*pLexemList != 0)
		delete *pLexemList;
	*pLexemList = new TLexemList();

	if(*pIdentList != 0)
		delete *pIdentList;
	*pIdentList = new TIdentList();

	int kaCurPos = 0;              
	int iCurPosText = 0;           
	int iLenText = strlen(szText); 
	char szCurLex[256];            
	szCurLex[0] = '\0';
	int iLenCurLex = 0;			   

	int iNumStrCurLex = 1;		   
	int iPosStrCurLex = 1;		   
	int iPosCurLex = 1;			   
	int iTypeCurLex = 0;
    int iPosStrCurLexDublikat = 1; 
	bool bError = false;

	char c;
	while(iCurPosText <= iLenText)
	{
		iPosStrCurLexDublikat++;

		c = szText[iCurPosText];
		switch (kaCurPos)
		{
		case kaPosTask:         
			kaLexTask(&kaCurPos, &iCurPosText, szText, szCurLex, &iLenCurLex, c,
			          &iNumStrCurLex, &iPosStrCurLex, &iPosCurLex, &iTypeCurLex, &iPosStrCurLexDublikat,
					  *pLexemList, *pIdentList);
			break;
		case kaPosIdent:        
			kaLexIdent(&kaCurPos, &iCurPosText, szText, szCurLex, &iLenCurLex, c,
			          &iNumStrCurLex, &iPosStrCurLex, &iPosCurLex, &iTypeCurLex, &iPosStrCurLexDublikat,
					  *pLexemList, *pIdentList);
			break;
		case kaPosEqual:       
			kaLexEqual(&kaCurPos, &iCurPosText, szText, szCurLex, &iLenCurLex, c,
			          &iNumStrCurLex, &iPosStrCurLex, &iPosCurLex, &iTypeCurLex, &iPosStrCurLexDublikat,
					  *pLexemList, *pIdentList);
			break;
		case kaPosNumeric:           
			kaLexNumeric(&kaCurPos, &iCurPosText, szText, szCurLex, &iLenCurLex, c,
			          &iNumStrCurLex, &iPosStrCurLex, &iPosCurLex, &iTypeCurLex, &iPosStrCurLexDublikat,
					  *pLexemList, *pIdentList);
			break;
		case kaPosSemicolon:                
			kaLexSemicolon(&kaCurPos, &iCurPosText, szText, szCurLex, &iLenCurLex, c,
			          &iNumStrCurLex, &iPosStrCurLex, &iPosCurLex, &iTypeCurLex, &iPosStrCurLexDublikat,
					  *pLexemList, *pIdentList);
			break;
			case kaPosOperSravn:	       //[��] = <��������� ���������>
			kaLexOperSravn(&kaCurPos, &iCurPosText, szText, szCurLex, &iLenCurLex, c,
			          &iNumStrCurLex, &iPosStrCurLex, &iPosCurLex, &iTypeCurLex, &iPosStrCurLexDublikat,
					  *pLexemList, *pIdentList);
			break;
		case kaPosArifmOper:         
			kaLexArifmOper(&kaCurPos, &iCurPosText, szText, szCurLex, &iLenCurLex, c,
			          &iNumStrCurLex, &iPosStrCurLex, &iPosCurLex, &iTypeCurLex, &iPosStrCurLexDublikat,
					  *pLexemList, *pIdentList);
			break;
		case kaPosSpace:            
		case kaPosEnter:			
			kaLexSpaceEnter(&kaCurPos, &iCurPosText, szText, szCurLex, &iLenCurLex, c,
			          &iNumStrCurLex, &iPosStrCurLex, &iPosCurLex, &iTypeCurLex, &iPosStrCurLexDublikat,
					  *pLexemList, *pIdentList);
			break;
		case kaPosError:                
			bError = true;
			cError = "123\0";
			iRet = -1;
			iCurPosText = iLenText + 1;
			break;
		case kaPosSuccess:            
			iRet = 0;
			iCurPosText = iLenText +1;
			break;

		default:
			{
				iCurPosText++;
			}
		}
		if(cError)
		{
			break;
		}
	}
	return iRet;
}


int kaLexTask(int* kaCurPos,			int* iCurPosText, char* szText,
				char* szCurLex,			int* iLenCurLex,  char cCurChar,
				int* iNumStrCurLex,     int* iPosStrCurLex,
				int* iPosCurLex,        int* iTypeCurLex, int* iPosStrCurLexDublikat,
				TLexemList* pLexemList,  TIdentList* pIdentList)
{
	int iRet = -1;
	(*iPosStrCurLexDublikat)--;
	switch (cCurChar)
	{
	case kaTerm_a:       
    case kaTerm_b:
	case kaTerm_c:
	case kaTerm_d:
	case kaTerm_e:
	case kaTerm_f:
	case kaTerm_g:
	case kaTerm_h:
	case kaTerm_i:
	case kaTerm_j:
	case kaTerm_k:
	case kaTerm_l:
	case kaTerm_m:
	case kaTerm_n:
	case kaTerm_o:
	case kaTerm_p:
	case kaTerm_q:
	case kaTerm_r:
	case kaTerm_s:
	case kaTerm_t:
	case kaTerm_u:
	case kaTerm_v:
	case kaTerm_w:
	case kaTerm_x:
	case kaTerm_y:
	case kaTerm_z:
	case kaTerm_A:
	case kaTerm_B:
	case kaTerm_C:
	case kaTerm_D:
	case kaTerm_E:
	case kaTerm_F:
	case kaTerm_G:
	case kaTerm_H:
	case kaTerm_I:
	case kaTerm_J:
	case kaTerm_K:
	case kaTerm_L:
	case kaTerm_M:
	case kaTerm_N:
	case kaTerm_O:
	case kaTerm_P:
	case kaTerm_Q:
	case kaTerm_R:
	case kaTerm_S:
	case kaTerm_T:
	case kaTerm_U:
	case kaTerm_V:
	case kaTerm_W:
	case kaTerm_X:
	case kaTerm_Y:
	case kaTerm_Z:
		{
			*kaCurPos = kaPosIdent;      
			iRet = 1;
			break;
		}
	case kaTerm_Equal:                
		{
			*kaCurPos = kaPosEqual;
			iRet = 1;
			break;
		}
	case kaTerm_Semicolon:             
		{
			*kaCurPos = kaPosSemicolon;       
			iRet = 1;
			break;
		}
	case kaTerm_0:      
	case kaTerm_1:		
	case kaTerm_2:		
	case kaTerm_3:		
	case kaTerm_4:		
	case kaTerm_5:		
	case kaTerm_6:		
	case kaTerm_7:		
	case kaTerm_8:		
	case kaTerm_9:		
		{
			*kaCurPos = kaPosNumeric;            
			iRet = 1;
			break;
		}
	case kaTerm_Space: 

		{
			*kaCurPos = kaPosSpace;		
			iRet = 1;
			break;
		}
	case kaTerm_ZnakBolshe:         
	case kaTerm_ZnakMenshe:			  
		{
			*kaCurPos = kaPosOperSravn;		
			iRet = 1;
			break;
		}
	case kaTerm_Delite:
	case kaTerm_Plus:
	case kaTerm_Ymnozh:				
	case kaTerm_Point:
	case kaTerm_minus:
		{
			*kaCurPos = kaPosArifmOper;
			iRet = 1;
			break;
		}
	case kaTerm_Enter:
		{
			*kaCurPos = kaPosEnter;		
			iRet = 1;
			break;
		}
	case kaTerm_Pystoi:
		{
			*kaCurPos = kaPosSuccess;
			iRet = 1;
			break;
		}
	default:
		{
			*kaCurPos = kaPosError;			
			iRet = -1;
		}
	};
	return iRet;
}


int kaLexIdent(int* kaCurPos,			int* iCurPosText, char* szText,
				char* szCurLex,			int* iLenCurLex,  char cCurChar,
				int* iNumStrCurLex,     int* iPosStrCurLex,
				int* iPosCurLex,        int* iTypeCurLex, int* iPosStrCurLexDublikat,
				TLexemList* pLexemList,  TIdentList* pIdentList)
{
	int iRet = -1;
	switch(cCurChar)
	{
	case kaTerm_a:				
	case kaTerm_b:
	case kaTerm_c:
	case kaTerm_d:
	case kaTerm_e:
	case kaTerm_f:
	case kaTerm_g:
	case kaTerm_h:
	case kaTerm_i:
	case kaTerm_j:
	case kaTerm_k:
	case kaTerm_l:
	case kaTerm_m:
	case kaTerm_n:
	case kaTerm_o:
	case kaTerm_p:
	case kaTerm_q:
	case kaTerm_r:
	case kaTerm_s:
	case kaTerm_t:
	case kaTerm_u:
	case kaTerm_v:
	case kaTerm_w:
	case kaTerm_x:
	case kaTerm_y:
	case kaTerm_z:
	case kaTerm_A:
	case kaTerm_B:
	case kaTerm_C:
	case kaTerm_D:
	case kaTerm_E:
	case kaTerm_F:
	case kaTerm_G:
	case kaTerm_H:
	case kaTerm_I:
	case kaTerm_J:
	case kaTerm_K:
	case kaTerm_L:
	case kaTerm_M:
	case kaTerm_N:
	case kaTerm_O:
	case kaTerm_P:
	case kaTerm_Q:
	case kaTerm_R:
	case kaTerm_S:
	case kaTerm_T:
	case kaTerm_U:
	case kaTerm_V:
	case kaTerm_W:
	case kaTerm_X:
	case kaTerm_Y:
	case kaTerm_Z:
	case kaTerm_Podch:
		{
            (*iCurPosText)++;
		   
			szCurLex[(*iLenCurLex)++] = cCurChar;
			szCurLex[*iLenCurLex] = '\0';
			break;
		}
		case kaTerm_Equal:					 				 		 
		case kaTerm_Delite:					
		case kaTerm_Ymnozh:					
		case kaTerm_Semicolon:	
		case kaTerm_Point:					 
		case kaTerm_Pystoi:
		case kaTerm_Enter:
		case kaTerm_Space:
		{
			(*iPosStrCurLexDublikat)--;
			if((szCurLex[0] == 'i')&(szCurLex[1] == 'f'))
			{
				*iTypeCurLex = 11;
				TLexem* pLexem = new TLexem(szCurLex, *iTypeCurLex,0,0.0, 
											 *iNumStrCurLex,*iPosStrCurLex, *iPosCurLex);
				pLexemList->add(pLexem);
				pLexem = 0;

				szCurLex[0] = '\0';
				*iLenCurLex = 0;
				*iTypeCurLex = 0;
				*iPosCurLex = *iCurPosText;
				*iPosStrCurLex = *iPosStrCurLexDublikat;
				*kaCurPos = kaPosTask;
				break;
			}
			else if((szCurLex[0] == 'e')&(szCurLex[1] == 'l')&(szCurLex[2] == 's')&(szCurLex[3] == 'e'))
			{
				*iTypeCurLex = 12;
				TLexem* pLexem = new TLexem(szCurLex, *iTypeCurLex,0,0.0, 
											 *iNumStrCurLex,*iPosStrCurLex, *iPosCurLex);
				pLexemList->add(pLexem);
				pLexem = 0;

				szCurLex[0] = '\0';
				*iLenCurLex = 0;
				*iTypeCurLex = 0;
				*iPosCurLex = *iCurPosText;
				*iPosStrCurLex = *iPosStrCurLexDublikat;
				*kaCurPos = kaPosTask;
				break;
			}
			else if((szCurLex[0] == 'e')&(szCurLex[1] == 'n')&(szCurLex[2] == 'd'))
			{
				*iTypeCurLex = 13;
				TLexem* pLexem = new TLexem(szCurLex, *iTypeCurLex,0,0.0, 
											 *iNumStrCurLex,*iPosStrCurLex, *iPosCurLex);
				pLexemList->add(pLexem);
				pLexem = 0;

				szCurLex[0] = '\0';
				*iLenCurLex = 0;
				*iTypeCurLex = 0;
				*iPosCurLex = *iCurPosText;
				*iPosStrCurLex = *iPosStrCurLexDublikat;
				*kaCurPos = kaPosTask;
				break;
			}
			*iTypeCurLex = 1;
			TLexem* pLexem = new TLexem(szCurLex, *iTypeCurLex,0,0.0,
										 *iNumStrCurLex,*iPosStrCurLex, *iPosCurLex);
			pLexemList->add(pLexem);
			pLexem = 0;

			TIdent* pIdent = new TIdent(szCurLex, *iTypeCurLex,0,0.0,
				                      *iNumStrCurLex,*iPosStrCurLex, *iPosCurLex);
			int iNumIdent = pIdentList->addIdent(pIdent);

			pIdent = 0;

			szCurLex[0] = '\0';
			*iLenCurLex = 0;
			*iTypeCurLex = 0;
			*iPosCurLex = *iCurPosText+1;
			*iPosStrCurLex = *iPosStrCurLexDublikat;

			*kaCurPos = kaPosTask;
			break;
		}
	default:
		{
			*kaCurPos = kaPosError;	
			iRet = -1;
		}

	};
	return iRet;
}

int kaLexEqual(int* kaCurPos,			int* iCurPosText, char* szText,
				char* szCurLex,			int* iLenCurLex,  char cCurChar,
				int* iNumStrCurLex,     int* iPosStrCurLex,
				int* iPosCurLex,        int* iTypeCurLex, int* iPosStrCurLexDublikat,
				TLexemList* pLexemList,  TIdentList* pIdentList)
{
	int iRet = -1;
	switch(cCurChar)
	{
	case kaTerm_Equal:    
		{
			*iTypeCurLex = 3;   
		    (*iCurPosText)++;
			*iLenCurLex = 0;
			szCurLex[(*iLenCurLex)++] = cCurChar;
			szCurLex[*iLenCurLex] = '\0';
			TLexem* pLexem = new TLexem(szCurLex, *iTypeCurLex,0,0.0,    
				                      *iNumStrCurLex,*iPosStrCurLex, *iPosCurLex);
			pLexemList->add(pLexem);
			pLexem = 0;
			szCurLex[0] = '\0';
			*iLenCurLex = 0;

			*iTypeCurLex = 0;
			*iPosCurLex = *iCurPosText+1;
			*iPosStrCurLex = *iPosStrCurLexDublikat;

			*kaCurPos = kaPosTask;         
			iRet = 1;
			break;
		}
	default:
		{
			*kaCurPos = kaPosError;       
			iRet = -1;
		}
	};
	return iRet;
}

int kaLexNumeric(int* kaCurPos,			int* iCurPosText, char* szText,
				char* szCurLex,			int* iLenCurLex,  char cCurChar,
				int* iNumStrCurLex,     int* iPosStrCurLex,
				int* iPosCurLex,        int* iTypeCurLex, int* iPosStrCurLexDublikat,
				TLexemList* pLexemList,  TIdentList* pIdentList)
{
	int iRet = -1;
	unsigned int uiBase = 10;
	if(szCurLex[0] == '\0')
	{
		*iTypeCurLex = 2;
	}
	switch(cCurChar)
	{
    case kaTerm_0:			
	case kaTerm_1:			
	case kaTerm_2:			
	case kaTerm_3:			
	case kaTerm_4:			
	case kaTerm_5:			
	case kaTerm_6:			
	case kaTerm_7:			
	case kaTerm_8:			
	case kaTerm_9:	
		{
			szCurLex[(*iLenCurLex)++] = cCurChar;
			szCurLex[*iLenCurLex] = '\0';
			(*iCurPosText)++;
			break;
		}
	
	case kaTerm_Semicolon:			   	 
	case kaTerm_Equal:					 
	case kaTerm_Space: 					 
	case kaTerm_Ymnozh:		   	 				 
	case kaTerm_Pystoi:				     
	case kaTerm_minus:					
	case kaTerm_Delite:					 
	case kaTerm_Enter:	
		{
			(*iPosStrCurLexDublikat)--;
			if(*iTypeCurLex == 2)
			{
				String^ sStrC	= gcnew String(szCurLex);

				int iVal = (int)(System::Convert::ToInt32(sStrC));


				TLexem* pLexem = new TLexem(szCurLex, *iTypeCurLex,iVal,0.0,   
				                      *iNumStrCurLex,*iPosStrCurLex, *iPosCurLex);
				pLexemList->add(pLexem);
				pLexem = 0;
			}
			else if(*iTypeCurLex == 10)
			{
				String^ sStrC	= gcnew String(szCurLex);

				double dVal = atof(szCurLex);

				TLexem* pLexem = new TLexem(szCurLex, *iTypeCurLex,0,dVal,   
				                      *iNumStrCurLex,*iPosStrCurLex, *iPosCurLex);
				pLexemList->add(pLexem);
				pLexem = 0;
			}
			szCurLex[0] = '\0';
			*iLenCurLex = 0;
			*iTypeCurLex = 0;
			*iPosCurLex = *iCurPosText+1;
			*iPosStrCurLex = *iPosStrCurLexDublikat;

			*kaCurPos = kaPosTask;         
			break;
		}
	case kaTerm_Point:
		{
			szCurLex[(*iLenCurLex)++] = cCurChar;
			szCurLex[*iLenCurLex] = '\0';
			(*iCurPosText)++;
			*iTypeCurLex = 10;
			break;
		}
	default:
		{
			*kaCurPos = kaPosError;				
			iRet = -1;
		}
	};
	return iRet;
}

int kaLexSemicolon(int* kaCurPos,			int* iCurPosText, char* szText,
				char* szCurLex,			int* iLenCurLex,  char cCurChar,
				int* iNumStrCurLex,     int* iPosStrCurLex,
				int* iPosCurLex,        int* iTypeCurLex, int* iPosStrCurLexDublikat,
				TLexemList* pLexemList,  TIdentList* pIdentList)
{
	int iRet = -1;
	switch(cCurChar)
	{
	case kaTerm_Semicolon:          
		{
			*iTypeCurLex = 4
				;
			(*iCurPosText)++;
			*iLenCurLex = 0;
			szCurLex[(*iLenCurLex)++] = cCurChar;
			szCurLex[*iLenCurLex] = '\0';
			TLexem* pLexem = new TLexem(szCurLex, *iTypeCurLex,0,0.0, 
										*iNumStrCurLex,*iPosStrCurLex, *iPosCurLex);  
				pLexemList->add(pLexem);
				pLexem = 0;

				szCurLex[0] = '\0';
				*iLenCurLex = 0;
				*iTypeCurLex = 0;
				*iPosCurLex = *iCurPosText+1;
				*iPosStrCurLex = *iPosStrCurLexDublikat;

			    *kaCurPos = kaPosTask;        
				iRet = 1;
				break;
		}
	default:
		{
			*kaCurPos = kaPosError;				
			iRet = -1;
		}
	};
	return iRet;
}

int kaLexOperSravn(int* kaCurPos,			int* iCurPosText, char* szText,
						char* szCurLex,			int* iLenCurLex,  char cCurChar,
						int* iNumStrCurLex,     int* iPosStrCurLex,
						int* iPosCurLex,        int* iTypeCurLex, int* iPosStrCurLexDublikat,
						TLexemList* pLexemList,  TIdentList* pIdentList)
{
	int iRet = -1;
	switch(cCurChar)
	{
	case kaTerm_ZnakBolshe:				
	case kaTerm_ZnakMenshe:				
	case kaTerm_Equal:					 			
		{
			(*iCurPosText)++;
			
			szCurLex[(*iLenCurLex)++] = cCurChar;
			szCurLex[*iLenCurLex] = '\0';

			if(((szCurLex[0]=='>')||(szCurLex[0]=='<')||(szCurLex[0]=='=')||(szCurLex[0]=='!'))&(szCurLex[1]=='='))
			{
				*iTypeCurLex = 8;
				TLexem* pLexem = new TLexem(szCurLex, *iTypeCurLex,0,0.0, 
											 *iNumStrCurLex,*iPosStrCurLex, *iPosCurLex);
				pLexemList->add(pLexem);
				pLexem = 0;

				szCurLex[0] = '\0';
				*iLenCurLex = 0;
				*iTypeCurLex = 0;
				*iPosCurLex = *iCurPosText+1;
				*iPosStrCurLex = *iPosStrCurLexDublikat;

				*kaCurPos = kaPosTask;
			}
			else if(((szCurLex[0]=='>')||(szCurLex[0]=='<'))&(szCurLex[1]!='=')&(szCurLex[1]!='\0'))
			{
				(*iCurPosText)--;
				szCurLex[1] = '\0';
				*iTypeCurLex = 8;
				TLexem* pLexem = new TLexem(szCurLex, *iTypeCurLex,0,0.0, 
											 *iNumStrCurLex,*iPosStrCurLex, *iPosCurLex);
				pLexemList->add(pLexem);
				pLexem = 0;

				szCurLex[0] = '\0';
				*iLenCurLex = 0;
				*iTypeCurLex = 0;
				*iPosCurLex = *iCurPosText+1;
				*iPosStrCurLex = *iPosStrCurLexDublikat;

				*kaCurPos = kaPosTask;
			}
			else if((szCurLex[0]=='=')&((szCurLex[1]=='>')||(szCurLex[1]=='<')))
			{
				*iTypeCurLex = 8;
				TLexem* pLexem = new TLexem(szCurLex, *iTypeCurLex,0,0.0, 
											 *iNumStrCurLex,*iPosStrCurLex, *iPosCurLex);
				pLexemList->add(pLexem);
				pLexem = 0;

				szCurLex[0] = '\0';
				*iLenCurLex = 0;
				*iTypeCurLex = 0;
				*iPosCurLex = *iCurPosText+1;
				*iPosStrCurLex = *iPosStrCurLexDublikat;

				*kaCurPos = kaPosTask;
			}

			break;
		}
	default:
		{
			if(((szCurLex[0]=='>')||(szCurLex[0]=='<'))&(szCurLex[1]!='='))
			{
				szCurLex[1] = '\0';
				*iTypeCurLex = 8;
				TLexem* pLexem = new TLexem(szCurLex, *iTypeCurLex,0,0.0, 
											 *iNumStrCurLex,*iPosStrCurLex, *iPosCurLex);
				pLexemList->add(pLexem);
				pLexem = 0;

				szCurLex[0] = '\0';
				*iLenCurLex = 0;
				*iTypeCurLex = 0;
				*iPosCurLex = *iCurPosText+1;
				*iPosStrCurLex = *iPosStrCurLexDublikat;

				*kaCurPos = kaPosTask;
			}
			else
			{
				*kaCurPos = kaPosError;       
				iRet = -1;
			}
		}
	};
	return iRet;
}

int kaLexArifmOper(int* kaCurPos,			int* iCurPosText, char* szText,
						char* szCurLex,			int* iLenCurLex,  char cCurChar,
						int* iNumStrCurLex,     int* iPosStrCurLex,
						int* iPosCurLex,        int* iTypeCurLex, int* iPosStrCurLexDublikat,
						TLexemList* pLexemList,  TIdentList* pIdentList)
{
	int iRet = -1;
	switch(cCurChar)
	{ 
	case kaTerm_minus:   
	case kaTerm_Delite:  
	case kaTerm_Ymnozh:
	case kaTerm_Plus:
		{
			if(szCurLex[0]!='.')
			{
				*iTypeCurLex = 7;    
				(*iCurPosText)++;
				*iLenCurLex = 0;
				szCurLex[(*iLenCurLex)++] = cCurChar;
				szCurLex[*iLenCurLex] = '\0';
				TLexem* pLexem = new TLexem(szCurLex, *iTypeCurLex,0,0.0,    
										  *iNumStrCurLex,*iPosStrCurLex, *iPosCurLex);
				pLexemList->add(pLexem);
				pLexem = 0;

				szCurLex[0] = '\0';
				*iLenCurLex = 0;
				*iTypeCurLex = 0;
				*iPosCurLex = *iCurPosText+1;
				*iPosStrCurLex = *iPosStrCurLexDublikat;

				*kaCurPos = kaPosTask;        
				iRet = 1;
				
			}
			else
			{
				*iTypeCurLex = 7;
				szCurLex[1] = cCurChar;
				szCurLex[2] = '\0';
				TLexem* pLexem = new TLexem(szCurLex, *iTypeCurLex,0,0.0, 
											 *iNumStrCurLex,*iPosStrCurLex, *iPosCurLex);
				pLexemList->add(pLexem);
				pLexem = 0;

				szCurLex[0] = '\0';
				*iLenCurLex = 0;
				*iTypeCurLex = 0;
				*iPosCurLex = *iCurPosText+1;
				*iPosStrCurLex = *iPosStrCurLexDublikat;

				*kaCurPos = kaPosTask;
				iRet = 1;
				(*iCurPosText)++;
			}
			break;
		}
	case kaTerm_Point:                     
		{
			szCurLex[(*iLenCurLex)++] = cCurChar;
			szCurLex[*iLenCurLex] = '\0';
			(*iCurPosText)++;
			if(szCurLex[1]=='.')
			{
				*kaCurPos = kaPosError;       
				iRet = -1;
			}

			break;
	}
	default:
		{
			*kaCurPos = kaPosError;       
			iRet = -1;
		}
	};
	return iRet;
}

int kaLexSpaceEnter(int* kaCurPos,			int* iCurPosText, char* szText,
						char* szCurLex,			int* iLenCurLex,  char cCurChar,
						int* iNumStrCurLex,     int* iPosStrCurLex,
						int* iPosCurLex,        int* iTypeCurLex, int* iPosStrCurLexDublikat,
						TLexemList* pLexemList,  TIdentList* pIdentList)
{
	if(cCurChar == 13)
	{
		*iPosStrCurLexDublikat = 1;
		*iPosStrCurLex = 0;
		(*iNumStrCurLex)++;
		(*iCurPosText)++;
		(*iPosCurLex)++;
	}
	(*iPosStrCurLex)++;
	(*iCurPosText)++;
	(*iPosCurLex)++;
	*kaCurPos = kaPosTask;
	return 1;
}
int kaLexError(int* kaCurPos,			int* iCurPosText, char* szText,
						char* szCurLex,			int* iLenCurLex,  char cCurChar,
						int* iNumStrCurLex,     int* iPosStrCurLex,
						int* iPosCurLex,        int* iTypeCurLex, int* iPosStrCurLexDublikat,
						TLexemList* pLexemList,  TIdentList* pIdentList, char* cError)
{
	char * p1 = "Hello world!";
	cError = "123\0";
	return 1;
}