

#define GLEW_STATIC

#include "Global.h"

void Global::InitProgram()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(1024, 512, "Game", nullptr, nullptr);

	if (!window)
	{
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();
}

void Global::ShutdownProgram()
{

}
