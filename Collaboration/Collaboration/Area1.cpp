

#define GLEW_STATIC

#include "Area.h"

void Area::Area1Loop()
{
	LoadArea1Content();
	while (!glfwWindowShouldClose(_Window))
	{
		glfwPollEvents();
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		_VertexObject->use();
		_ShaderProgram->use();
		if (glfwGetKey(_Window, GLFW_KEY_D) == true)
			dogepointer->use();
		else
		     _Texture->use();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		if (glfwGetKey(_Window, GLFW_KEY_ESCAPE) == true)
		{
			glfwSetWindowShouldClose(_Window, GL_TRUE);
		}

		glfwSwapBuffers(_Window);
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


