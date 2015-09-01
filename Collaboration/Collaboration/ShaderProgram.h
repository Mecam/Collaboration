
#ifndef _SHADER_PROGRAM_
#define _SHADER_PROGRAM_
#include <string>
#include <fstream>
#include "Libraries\GLlibs\GL\glew.h"
#include "Libraries\GLlibs\GLFW\glfw3.h"
#include <iostream>
class ShaderProgram
{
private:
	GLchar**src;


public:
	GLuint prog;
	GLuint gShader;
	ShaderProgram() {}
	void setup(char* vsource, char* fsource)
	{
		prog = glCreateProgram();

		gShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(gShader, 1, &vsource, NULL);
		glCompileShader(gShader);
		debug(gShader);
		glAttachShader(prog, gShader);

		gShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(gShader, 1, &fsource, NULL);
		glCompileShader(gShader);
		debug(gShader);
		glAttachShader(prog, gShader);

		glLinkProgram(prog);
	}
	ShaderProgram(char* vsource, char* fsource)
	{
		prog = glCreateProgram();

		gShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(gShader, 1, &vsource, NULL);
		glCompileShader(gShader);
		debug(gShader);
		glAttachShader(prog, gShader);

		gShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(gShader, 1, &fsource, NULL);
		glCompileShader(gShader);
		debug(gShader);
		glAttachShader(prog, gShader);

		glLinkProgram(prog);
	}
	~ShaderProgram(void)
	{
		glDeleteProgram(prog);
		glDeleteShader(gShader);
	}
	void addshader(char* source, GLuint type)
	{

	}
	void use(void)
	{
		glUseProgram(prog);
	}
private:
	void debug(GLuint shader)
	{
		GLint status;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
		std::cout << "Status:" << status << "\n";
		char buffer[512];
		glGetShaderInfoLog(shader, 512, NULL, buffer);
		std::cout << "Buffer:" << buffer << "\n";
	}
};

#endif

