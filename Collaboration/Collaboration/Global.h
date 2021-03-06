
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
#include <thread>

using namespace std;
using namespace glm;
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

struct quaternion
{
	float x, y, z, w;
	quaternion(vec3 axis, float angle) : x(axis.x), y(axis.y), z(axis.z), w(angle)
	{
		float mag = this->lenght();
		if(mag != 1.0f)
		{
			x /= mag;
			y /= mag;
			z /= mag;
			w /= mag;
		}
	}
	float lenght()
	{
		return sqrt(x * x + y * y + z * z + w * w);
	}
	quaternion operator*(quaternion B)
	{
		quaternion C(vec3(1.0f), 1.0f);

		C.x = this->w*B.x + this->x*B.w + this->y*B.z - this->z*B.y;
		C.y = this->w*B.y - this->x*B.z + this->y*B.w + this->z*B.x;
		C.z = this->w*B.z + this->x*B.y - this->y*B.x + this->z*B.w;
		C.w = this->w*B.w - this->x*B.x - this->y*B.y - this->z*B.z;
		return C;
	}
	quaternion operator-()
	{
		return quaternion(vec3(this->x * -1.0f, this->y * -1.0f, this->z * -1.0f), this->w * -1.0f);
	}
};
class VectorTool 
{
public:
	GLuint vao, vbo;
	vector<GLfloat> data;
	ShaderProgram vectorshaders;
	glm::vec3 colors = glm::vec3(1.0f);
	vector<Vector3> colorv;
	bool line;
	void setup()
	{
		 

		vectorshaders.setup(Vectorv, Vectorf);

		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		 
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glBindVertexArray(0);

	}
	
	void draw(Vector3 vector, GLfloat pointsize)
	{
		data.clear();
		data.push_back(vector.vec3().x);
		data.push_back(vector.vec3().y);
		data.push_back(vector.vec3().z);
		data.push_back(colors.x);
		data.push_back(colors.y);
		data.push_back(colors.z);
		

		if (line)
		{
			data.push_back(0.0f);
			data.push_back(0.0f);
			data.push_back(0.0f);
			data.push_back(colors.x);
			data.push_back(colors.y);
			data.push_back(colors.z);
		}
		glBindVertexArray(vao);
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), &data[0], GL_STREAM_DRAW);

		vectorshaders.use();
		glPointSize(pointsize);
		if (line)
			glDrawArrays(GL_LINES, 0, 2);
		else
			glDrawArrays(GL_POINTS, 0, 1);
		 
		glBindVertexArray(0);
	}
	void setcolor(Vector3 color)
	{
		colors = color.vec3();
	}
	void setcolor(vector<Vector3> color)
	{
		colorv = color;
	}
	void draw(vector<Vector3> vectors, GLfloat pointsize)
	{
		data.clear();
		for (int i = 0; i < vectors.size(); i++)
		{
			data.push_back(vectors[i].vec3().x / 10.0);
			data.push_back(vectors[i].vec3().y / 10.0);
			data.push_back(vectors[i].vec3().z / 10.0);
			if (colorv.size() >= 1)
			{
				data.push_back(colorv[i].vec3().x);
				data.push_back(colorv[i].vec3().y);
				data.push_back(colorv[i].vec3().z);
			}
			else
			{
				data.push_back(colors.x);
				data.push_back(colors.y);
				data.push_back(colors.z);
			}
			if (line)
			{
				data.push_back(0.0f);
				data.push_back(0.0f);
				data.push_back(0.0f);
				data.push_back(colors.x);
				data.push_back(colors.y);
				data.push_back(colors.z);
			}
		}
		glBindVertexArray(vao);
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), &data[0], GL_STREAM_DRAW);

		vectorshaders.use();
		glPointSize(pointsize);
		if (line)
			glDrawArrays(GL_LINES, 0, data.size());
		else
			glDrawArrays(GL_POINTS, 0, data.size() / 2);
		glUseProgram(0);

		glBindVertexArray(0);
	}
};

#endif

