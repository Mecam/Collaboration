
#ifndef _GLOBAL_
#define _GLOBAL_

/*OpenGL Includes*/
#include "Libraries\GLlibs\GL\glew.h"
#include "Libraries\GLlibs\GLFW\glfw3.h"
#include "Utils.h"
#include "ShaderProgram.h"
#include "ShaderDat.h"

/*Includes*/
#include <string>
#include <vector>
#include <limits>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

struct XMDouble3
{
	double X;
	double Y;
	double Z;
};

class Global
{
private:

protected:

	/*OpenGL*/
	GLFWwindow* _Window;

	/*Data*/
	const int _WindowWidth = 1024;
	const int _WindowHeight = 512;

public:
	//Global();

	void InitProgram();
	void ShutdownProgram();

};

#endif

