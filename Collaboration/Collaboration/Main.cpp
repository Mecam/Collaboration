

#define GLEW_STATIC

#include "Global.h"
#include "Program.h"
 
void main()
{
	Program ProgramObject;
	ProgramObject.Init();
	ProgramObject.LoadGameContent();
}

