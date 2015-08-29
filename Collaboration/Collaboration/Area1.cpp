

#define GLEW_STATIC

#include "Area.h"

void Area::Area1Loop()
{
	LoadArea1Content();
	while (!glfwWindowShouldClose(window))
	{

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == true)
			glfwSetWindowShouldClose(window, GL_TRUE);


		 

	}
	UnloadArea1Content();
	UnloadGameContent();
	ShutdownProgram();
}

void Area::LoadArea1Content()
{

}

void Area::UnloadArea1Content()
{

}


