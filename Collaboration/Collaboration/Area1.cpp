

#define GLEW_STATIC

#include "Program.h"

void Program::Area1Loop()
{
	LoadArea1Content();

	cout << "::SYSTEM:: " << "Starting New Thread\n";
	thread Thread(&Program::Debugger, this);

	cout << "::SYSTEM:: " << "Entering Area1 Loop\n";
	while (!glfwWindowShouldClose(_Window))
	{
		_Time1 = chrono::high_resolution_clock::now();
		glfwPollEvents();

		UpdateArea();
		RenderArea();

		_DeltaTime = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - _Time1).count() / 1000.0;
		if (_DeltaTime > _MaximumUpdateDelay)
		{
			_DeltaTime = _MaximumUpdateDelay;
		}
	}

	cout << "::SYSTEM:: " << "Terminating Thread\n";
	TerminateThread(&Thread, 0);

	UnloadArea1Content();
	UnloadGameContent();
	ShutdownProgram();
}

void Program::LoadArea1Content()
{
	cout << "::SYSTEM:: " << "Loading Area1 Content\n";
}

void Program::UnloadArea1Content()
{
	cout << "::SYSTEM:: " << "Unloading Area1 Content\n";
}


