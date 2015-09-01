

#define GLEW_STATIC

#include "GLhandler.h"

void GLhandler::Area1Loop()
{
	LoadArea1Content();

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

	UnloadArea1Content();
	UnloadGameContent();
	Shutdown();
}

void GLhandler::LoadArea1Content()
{
	cout << "::SYSTEM:: " << "Loading Area1 Content\n";
}

void GLhandler::UnloadArea1Content()
{
	cout << "::SYSTEM:: " << "Unloading Area1 Content\n";
}


