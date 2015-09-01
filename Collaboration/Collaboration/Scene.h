#pragma once
#include "Utils.h"
#include "ShaderDat.h"
#include "ShaderProgram.h"

class Scene 
{
	public:
		virtual void loadContent();
		virtual void update();
		virtual void render();
		virtual void unloadContent();
};

static class Area1 : public Scene
{
	public:

		VertexObject VAO;
		ShaderProgram Shader;
		Texture Tex;
		Texture doge;
		Texture circuit;

		void loadContent()
		{
			 cout << "::SYSTEM:: " << "Loading Game Content\n" <<  endl;

			vector<GLfloat> Vertices =
			{
				-1.0f, 1.0f, 0.0f,//Top Left
				1.0f,-1.0f, 0.0f,//Bottom Right
				-1.0f,-1.0f, 0.0f,//Bottom Left

				1.0f, 1.0f, 0.0f,//Top  Right
				+1.0f,-1.0f, 0.0f,//Bottom Right
				+-1.0f, 1.0f, 0.0f,//Top Left
			};

			vector<GLfloat> TexPos = {
				0.0f, 0.0f,//Top Left
				1.0f, 1.0f,//Bottom Right
				0.0f, 1.0f,//Bottom Left

				1.0f, 0.0f,//Top  Right
				1.0f, 1.0f,//Bottom Right
				0.0f, 0.0f,//Top Left
			};

			VAO.setup(Vertices, TexPos);
			 

			Shader.setup(basicVertex, basicFragment);
			 

			Tex.setup("Tex/Coffee_Not_Found.png");
			 
			doge.setup("Tex/doge.png");
			 
			circuit.setup("Tex/Circuit.jpg");
			 
		}
};