#ifndef TTaskH
#define TTaskH
class TTask
{
 public:
 TTask();
 ~TTask();
 void setX(double _x);
 double getX();
 void setY(double _y);
 double getY();
 private: 
 double x;
 double y;
};
#endif