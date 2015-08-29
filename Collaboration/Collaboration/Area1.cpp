

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
		if (mode == 1)
		{
			_DogeTexture->use();
			mode = 2;
		}
		else if (mode == 2)
		{
			_Texture->use();
			mode = 3;
		}
		else if (mode == 3)
		{
			_CircuitTexture->use();
			mode = 1;
		}
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


