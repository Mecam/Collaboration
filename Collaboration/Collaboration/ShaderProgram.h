#pragma once
#include <string>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
class ShaderProgram
{
private:
	GLchar**src;


public:
	GLuint prog;
	GLuint gShader;
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
		printf("%u\n", status);
		char buffer[512];
		glGetShaderInfoLog(shader, 512, NULL, buffer);
		std::cout << buffer << std::endl;
	}
};

