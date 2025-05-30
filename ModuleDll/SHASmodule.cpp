#include "SHASmodule.h"
#include <math.h>
int SHASmodule(TTask* ptr)
{
 int iRet = -1;
 if (ptr != 0)
 {
 double x = ptr->get_X();
 double y = atan(x);
 ptr->set_Y(y);
 iRet = 0;
 }
 return iRet;
}
