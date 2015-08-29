
#ifndef _AREA_
#define _AREA_

#include "Global.h"

class Area : Global
{
private:

protected:

	/*Data*/

public:

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

