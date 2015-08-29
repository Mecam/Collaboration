

#define GLEW_STATIC

#include "Global.h"
#include "Area.h"

/*Global::Global()
{

}*/

void Global::InitProgram()
{
	cout << "::SYSTEM:: " << "Initializing Program\n";

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	_Window = glfwCreateWindow(_WindowWidth, _WindowHeight, "Game", nullptr, nullptr);

	if (!_Window)
	{
		glfwTerminate();
	}

	glfwMakeContextCurrent(_Window);

	glewExperimental = GL_TRUE;
	glewInit();

	//Area *AreaObject = new Area;
	//AreaObject->LoadGameContent();
}

void Global::ShutdownProgram()
{
	cout << "::SYSTEM:: " << "Shutting Down\n";
	exit(0);
}
