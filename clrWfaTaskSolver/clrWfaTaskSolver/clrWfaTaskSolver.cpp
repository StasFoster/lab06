// clrWfaTaskSolver.cpp: ������� ���� �������.

#include "Form1.h"
#include "FormRPN.h"
#include "FormParser.h"

using namespace clrWfaTaskSolver;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// run main tabbed form
	Application::Run(gcnew Form1());

	return 0;
}
