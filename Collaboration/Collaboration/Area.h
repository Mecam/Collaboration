
#ifndef _AREA_
#define _AREA_

#include "Global.h"

class Area : Global
{
private:

protected:

	void LoadLevelsContent();
	void UnloadLevelsContent();

	/*Level Functions*/
	void Level1Loop();

	void LoadLevel1Content();

	void UpdateLevel();
	
	void UnloadLevel1Content();

	/*Data*/
};

#endif

