

#define GLEW_STATIC

#include "Program.h"

void Program::Area1Loop()
{
	LoadArea1Content();

	cout << "::SYSTEM:: " << "Entering Area1 Loop\n";
	while (!glfwWindowShouldClose(_Window))
	{
		_Time1 = clock();
		glfwPollEvents();

		UpdateArea();
		RenderArea();

		_DeltaTime = static_cast<double>((static_cast<double>(clock()) - _Time1) / CLOCKS_PER_SEC) * 1000;
		if (_DeltaTime > _MaximumUpdateDelay)
		{
			_DeltaTime = _MaximumUpdateDelay;
		}
	}

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


