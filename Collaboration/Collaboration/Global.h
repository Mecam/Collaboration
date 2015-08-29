
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

class Global
{
private:

protected:

public:
	void InitProgram();
	void ShutdownProgram();

};

#endif

