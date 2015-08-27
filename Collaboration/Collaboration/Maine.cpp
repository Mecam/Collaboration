#define GLEW_STATIC
//Program Entrypoint

/*Includes*/
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

 
void main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Game", nullptr, nullptr);

	if (!window)
	{
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		if(glfwGetKey(window, GLFW_KEY_ESCAPE) == true)
			glfwSetWindowShouldClose(window, GL_TRUE);

		glfwSwapBuffers(window);
	}

	glfwTerminate();
}
