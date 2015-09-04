
#ifndef _GLOBAL_
#define _GLOBAL_

/*OpenGL Includes*/
#include "Libraries\GLlibs\GL\glew.h"
#include "Libraries\GLlibs\GLFW\glfw3.h"
#include "Utils.h"
#include "ShaderProgram.h"
#include "ShaderDat.h"
#include "Libraries\GLlibs\glm\glm.hpp"
/*Includes*/
#include <string>
#include <vector>
#include <limits>
#include <list>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <Windows.h>
#include <chrono>

using namespace std;

#define PI 3.1415926535897932385
#define TAU 6.2831853071795864769

struct Vector3
{
	Vector3(double x, double y, double z) : X(x), Y(y), Z(z) {}
	Vector3() {}

	double X;
	double Y;
	double Z;


	static Vector3 Cross(Vector3 Vector1, Vector3 Vector2)
	{
		return
		{
			Vector1.Y * Vector2.Z - Vector1.Z * Vector2.Y,
			Vector1.Z * Vector2.X - Vector1.X * Vector2.Z,
			Vector1.X * Vector2.Y - Vector1.Y * Vector2.X
		};
	}
	static double Dot(Vector3 Vector1, Vector3 Vector2)
	{
		return
		{
			Vector1.X * Vector2.X + Vector1.Y * Vector2.Y + Vector1.Z * Vector2.Z
		};
	}
	static Vector3 Invert(Vector3 Vector1)
	{
		return
		{
			-Vector1.X,
			-Vector1.Y,
			-Vector1.Z
		};
	}

	Vector3 operator+(Vector3 Other)
	{
		return{ X + Other.X, Y + Other.Y, Z + Other.Z };
	}
	Vector3 operator-(Vector3 Other)
	{
		return{ X - Other.X, Y - Other.Y, Z - Other.Z };
	}
	glm::vec3 vec3()
	{
		return glm::vec3(X, Y, Z);
	}
};
class VectorTool : public VertexObject
{
public:
	 
	ShaderProgram vectorshaders;
	void setup()
	{
		 

		vectorshaders.setup(Vectorv, Vectorf);

		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		 

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

		glBindVertexArray(0);

	}
	void draw(glm::vec3 vector, GLfloat pointsize)
	{
		 

		glBindVertexArray(vao);
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), &data[0], GL_DYNAMIC_DRAW);

		vectorshaders.use();
		glUniform1f(glGetUniformLocation(vectorshaders.prog, "pSize"), pointsize);
		glDrawArrays(GL_POINTS, 0, 1);
		glUseProgram(0);

		glBindVertexArray(0);
	}
};

#endif

