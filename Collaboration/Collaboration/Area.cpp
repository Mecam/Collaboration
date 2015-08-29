

#define GLEW_STATIC

#include "Area.h"

/*Area::Area() :
	Global()
{

}*/

void Area::LoadGameContent()
{
	cout << "::SYSTEM:: " << "Loading Game Content\n";

	_Vertices =
	{
		-1.0f, 1.0f, 0.0f,//Top Left
		1.0f,-1.0f, 0.0f,//Bottom Right
		-1.0f,-1.0f, 0.0f,//Bottom Left

		1.0f, 1.0f, 0.0f,//Top  Right
		+1.0f,-1.0f, 0.0f,//Bottom Right
		+-1.0f, 1.0f, 0.0f,//Top Left
	};

	_TexPos = {
		0.0f, 0.0f,//Top Left
		1.0f, 1.0f,//Bottom Right
		0.0f, 1.0f,//Bottom Left

		1.0f, 0.0f,//Top  Right
		1.0f, 1.0f,//Bottom Right
		0.0f, 0.0f,//Top Left
	};

	VertexObject VAO(_Vertices, _TexPos);
	_VertexObject = &VAO;

	ShaderProgram Shader(basicVertex, basicFragment);
	_ShaderProgram = &Shader;

	Texture Tex("Tex/Coffee_Not_Found.png");
	_Texture = &Tex;
	Texture doge("Tex/doge.png");
	_DogeTexture = &doge;
	Texture circuit("Tex/Ciruit.jpeg");
	_CircuitTexture = &circuit;

	Area1Loop();
}

void Area::UnloadGameContent()
{
	cout << "::SYSTEM:: " << "Unloading Game Content\n";

	_VertexObject = 0;
	delete _VertexObject;

	_ShaderProgram = 0;
	delete _ShaderProgram;

	_Texture = 0;
	delete _Texture;

	_DogeTexture = 0;
	delete _DogeTexture;

	_CircuitTexture = 0;
	delete _CircuitTexture;
}

void Area::UpdateArea()
{

}

void Area::RenderArea()
{
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

