
//Program Entrypoint

/*Includes*/
#include <string>
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;

#define DBOUT(s)								\
{												\
	std::wostringstream os_;					\
	os_ << s;									\
	OutputDebugStringW(os_.str().c_str());		\
}

void main()
{
	DBOUT("\n" << "This Appears in the Output window" << "\n");
	while (GetAsyncKeyState(VK_ESCAPE) >= 0)
	{

	}
}
