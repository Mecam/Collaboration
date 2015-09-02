
#ifndef _PROGRAM_
#define _PROGRAM_

#include "Global.h"

class Program
{
private:
	/*Data*/
	long double _DeltaTime;
	chrono::time_point<chrono::steady_clock> _Time1;

protected:
	/*OpenGL*/
	GLFWwindow* _Window;

	/*Data*/
	const int _WindowWidth = 1024;
	const int _WindowHeight = 512;
	double _MaximumUpdateDelay = 100.0;

	/*Game Content*/
	vector<GLfloat> _Vertices;
	vector<GLfloat> _TexPos;
	VertexObject* _VertexObject;
	ShaderProgram* _ShaderProgram;
	Texture* _Texture;
	Texture* _DogeTexture;
	Texture* _CircuitTexture;
	int _Mode = 1;

	/*Area Content*/

public:
	/*Setup*/
	void Init();
	void Shutdown();

	void LoadGameContent();
	void UnloadGameContent();

	/*Level Functions*/
	void Area1Loop();

	void LoadArea1Content();
	
	void UnloadArea1Content();


	void UpdateArea();

	void RenderArea();
};

#endif

