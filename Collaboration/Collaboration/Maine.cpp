

#define GLEW_STATIC
//Program Entrypoint

/*Includes*/
//DO NOT COMMIT THE VCXPROJ FILE !!!!!!!!!!!!!!!!!!!!!!!//
#include "Libraries\GLlibs\GL\glew.h"
#include "Libraries\GLlibs\GLFW\glfw3.h"
#include "Utils.h"
#include "ShaderProgram.h"
#include "ShaderDat.h"
using namespace std;

vector<GLfloat> vertices = {
	-1.0f, 1.0f, 0.0f,//Top Left
	1.0f,-1.0f, 0.0f,//Bottom Right
	-1.0f,-1.0f, 0.0f,//Bottom Left

	1.0f, 1.0f, 0.0f,//Top  Right
	1.0f,-1.0f, 0.0f,//Bottom Right
	-1.0f, 1.0f, 0.0f,//Top Left
};

vector<GLfloat> texPos = {

	0.0f, 0.0f,//Top Left
	1.0f, 1.0f,//Bottom Right
	0.0f, 1.0f,//Bottom Left

	1.0f, 0.0f,//Top  Right
	1.0f, 1.0f,//Bottom Right
	0.0f, 0.0f,//Top Left
};


void main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(900, 900, "Game", nullptr, nullptr);

	if (!window)
	{
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	VertexObject vao(vertices, texPos);
	ShaderProgram program(basicVertex, basicFragment);
	Texture tex("Tex/doge.png");

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		vao.use();
		program.use();
		tex.use();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == true)
			glfwSetWindowShouldClose(window, GL_TRUE);

		glfwSwapBuffers(window);
	}

	glfwTerminate();
}
