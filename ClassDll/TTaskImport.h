#ifndef TTaskH
#define TTaskH
public class __declspec(dllimport) TTask
{
private:
double x;
double y;
public:
__stdcall TTask(void);
__stdcall ~TTask(void);	
void __stdcall set_X(double _a);
double __stdcall get_X();
void __stdcall set_Y(double _b);
double __stdcall get_Y();
};
#endif