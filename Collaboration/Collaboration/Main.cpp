

#define GLEW_STATIC

#include "Global.h"
#include "GLhandler.h"

void main()
{
	GLhandler handler;
	handler.Init();
	handler.LoadGameContent();
}

