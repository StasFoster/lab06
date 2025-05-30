#include "CoDec.h"
#include <cstring>

int Code(unsigned char* _pCode, unsigned char* _pStr, unsigned char* _pK)
{
    int iRet = -1;
    if ((_pStr != nullptr) && (_pCode != nullptr) && (_pK != nullptr))
    {
        int iLenStr = 0;
        while (_pStr[iLenStr] != '\0') iLenStr++;

        for (int i = 0; i < iLenStr; i++)
        {
            _pCode[i] = _pStr[i] + _pK[i % strlen((char*)_pK)];
        }
        
        int N = _pK[strlen((char*)_pK) - 1] - '0';
        if (N < 0) N = 0;
        
        if (N > 0 && iLenStr > 0) {
            unsigned char* temp = new unsigned char[iLenStr + 1];
            for (int i = 0; i < iLenStr; i++) {
                temp[i] = _pCode[(i + N) % iLenStr];
            }
            for (int i = 0; i < iLenStr; i++) {
                _pCode[i] = temp[i];
            }
            delete[] temp;
        }
        
        _pCode[iLenStr] = '\0';
        iRet = iLenStr;
    }
    return iRet;
}

int DeCode(unsigned char* _pCode, unsigned char* _pStr, unsigned char* _pK)
{
    int iRet = -1;
    if ((_pStr != nullptr) && (_pCode != nullptr) && (_pK != nullptr))
    {
        int iLenStr = 0;
        while (_pStr[iLenStr] != '\0') iLenStr++;
        
        int N = _pK[strlen((char*)_pK) - 1] - '0';
        if (N < 0) N = 0;
        
        if (N > 0 && iLenStr > 0) {
            unsigned char* temp = new unsigned char[iLenStr + 1];
            for (int i = 0; i < iLenStr; i++) {
                temp[(i + N) % iLenStr] = _pStr[i];
            }
            for (int i = 0; i < iLenStr; i++) {
                _pCode[i] = temp[i];
            }
            delete[] temp;
        } else {
            for (int i = 0; i < iLenStr; i++) {
                _pCode[i] = _pStr[i];
            }
        }
        
        for (int i = 0; i < iLenStr; i++)
        {
            _pCode[i] = _pCode[i] - _pK[i % strlen((char*)_pK)];
        }
        
        _pCode[iLenStr] = '\0';
        iRet = iLenStr;
    }
    return iRet;
}
