
#ifndef _AREA_
#define _AREA_

#include "Global.h"

class Area : Global
{
private:

protected:

	/*Data*/

public:

	static void LoadGameContent();
	static void UnloadGameContent();

	/*Level Functions*/
	static void Area1Loop();

	static void LoadArea1Content();
	
	static void UnloadArea1Content();


	static void UpdateArea();

	static void RenderArea();
};

#endif

