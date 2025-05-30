#include "TTask.h"
__stdcall TTask::TTask()
{
 x = 0.0;
 y = 0.0;
}
__stdcall TTask::~TTask()
{
}
void __stdcall TTask::set_X(double _x)
{
 x = _x;
}
double __stdcall TTask::get_X()
{
 return x;
}
void __stdcall TTask::set_Y(double _y)
{
 y = _y;
}
double __stdcall TTask::get_Y()
{
 return y;
}