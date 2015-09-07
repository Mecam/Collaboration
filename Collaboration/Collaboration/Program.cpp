

#define GLEW_STATIC

#include "Program.h"

void Program::InitProgram()
{
	cout << "::SYSTEM:: " << "Initializing Program\n";

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	_Window = glfwCreateWindow(_WindowWidth, _WindowHeight, "Game", nullptr, nullptr);

	if (!_Window)
	{
		glfwTerminate();
	}

	glfwMakeContextCurrent(_Window);

	glewExperimental = GL_TRUE;
	glewInit();
	//LoadGameContent();
	//Area *AreaObject = new Area;
	//AreaObject->LoadGameContent();
}

void Program::ShutdownProgram()
{
	cout << "::SYSTEM:: " << "Shutting Down\n";
	exit(0);
}

void Program::LoadGameContent()
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
	Texture circuit("Tex/Circuit.jpg");
	_CircuitTexture = &circuit;
	
	vectors.setup();
	Area1Loop();
}

void Program::UnloadGameContent()
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

void Program::Debugger()
{
	while (true)
	{
		this_thread::sleep_for(chrono::milliseconds(100));
		cout << "Thread:" << _DeltaTime << "\n";
	}
}

void Program::UpdateArea()
{
	//cout << "Delta Time: " << _DeltaTime << " Millisecconds\n";
}

void Program::RenderArea()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	vector<Vector3> VectorList;
	vectors.setcolor(Vector3(0.3f, 0.3f, 0.3f));
	vectors.line = true;
	vectors.draw({ { 1,0,0 },{ -1,0,0 },{ 0,1,0 },{ 0,-1,0 } }, 5.0f);
	vectors.setcolor(Vector3(0.0f, 1.0f, 0.0f));
	vectors.line = false;
	vectors.draw({ 0,0,0 }, 5.0f);
	vectors.line = true;

	Vector3 Normal(Normalize({ 2, -20, 0 }));
	Vector3 Vector(Normalize({ -1, 0.5, 0 }));
	double AngleBetweenNormalUp = AngleBetween(Normal, { 0,1,0 }) * sgn(sgn(Normal.X) + 0.5);
	double AngleBetweenVectorUp = AngleBetween(Vector, { 0,1,0 }) * sgn(sgn(Vector.X) + 0.5);
	double DifferanceAngles = AngleBetweenVectorUp - AngleBetweenNormalUp;
	Vector3 OUTPUT(sin(DifferanceAngles), cos(DifferanceAngles), 0);

	VectorList = { Normal };
	vectors.setcolor(Vector3(0.0f, 0.0f, 1.0f)); vectors.draw(VectorList, 5.0f);
	VectorList = { { -Normal.X, -Normal.Y, 0 }, {Normal.Y, -Normal.X, 0}, { -Normal.Y, Normal.X, 0 } };
	vectors.setcolor(Vector3(0.5f, 0.5f, 1.0f)); vectors.draw(VectorList, 5.0f);

	VectorList = { Vector };
	vectors.setcolor(Vector3(0.0f, 1.0f, 0.0f)); vectors.draw(VectorList, 5.0f);

	VectorList = { OUTPUT };
	vectors.setcolor(Vector3(1.0f, 1.0f, 1.0f)); vectors.draw(VectorList, 5.0f);

	//_VertexObject->use();
	_ShaderProgram->use();

	/*if (_Mode == 1)
	{
	_DogeTexture->use();
	_Mode = 2;
	}
	else if (_Mode == 2)
	{
	_Texture->use();
	_Mode = 3;
	}
	else if (_Mode == 3)
	{
	_CircuitTexture->use();
	_Mode = 1;
	}
	//glDrawArrays(GL_TRIANGLES, 0, 6);

	if (glfwGetKey(_Window, GLFW_KEY_ESCAPE) == true)
	{
	glfwSetWindowShouldClose(_Window, GL_TRUE);
	}*/

	glfwSwapBuffers(_Window);
}