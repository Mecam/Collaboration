

#define GLEW_STATIC

#include "Area.h"

/*Area::Area() :
	Global()
{

}*/

void Area::LoadGameContent()
{
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
		circuitpointer = &circuit;
	Area1Loop();
}

void Area::UnloadGameContent()
{

}

void Area::UpdateArea()
{

}

void Area::RenderArea()
{

}

