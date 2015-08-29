

#define GLEW_STATIC

#include "Area.h"

void Area::Area1Loop()
{
	LoadArea1Content();

	cout << "::SYSTEM:: " << "Entering Area1 Loop\n";
	while (!glfwWindowShouldClose(_Window))
	{
		glfwPollEvents();

		UpdateArea();
		RenderArea();
	}

	UnloadArea1Content();
	UnloadGameContent();
	ShutdownProgram();
}

void Area::LoadArea1Content()
{
	cout << "::SYSTEM:: " << "Loading Area1 Content\n";
}

void Area::UnloadArea1Content()
{
	cout << "::SYSTEM:: " << "Unloading Area1 Content\n";
}


