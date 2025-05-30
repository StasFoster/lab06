#include "TTask.h"
TTask:: TTask()
{
 x = 0.0;
 y = 0.0;
}
TTask:: ~TTask()
{
}
void TTask::setX(double _x)
{
 x = _x;
}
double TTask::getX()
{
 return x;
}
void TTask::setY(double _y)
{
 y = _y;
}
double TTask::getY()
{
 return y;
}