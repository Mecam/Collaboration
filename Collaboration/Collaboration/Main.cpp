

#define GLEW_STATIC

//#include "Global.h"
#include "Area.h"

void main()
{
	//Global ProgramObject;
	//ProgramObject.InitProgram();

	Area ProgramObject;
	ProgramObject.InitProgram();
	ProgramObject.LoadGameContent();
}

