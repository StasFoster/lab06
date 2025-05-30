#include "SHASmodule.h"
#include <math.h>
int SHASmodule(TTask* ptr)
{
 int iRet = -1;
 if (ptr != 0)
 {
 double x = ptr->getX();
 double y = atan(x);
 ptr->setY(y);
 iRet = 0;
 }
 return iRet;
}
