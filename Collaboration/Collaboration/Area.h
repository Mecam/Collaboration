
#ifndef _AREA_
#define _AREA_

#include "Global.h"

class Area : public Global
{
private:
	/*Data*/
	double _DeltaTime = 0.0;
	double _Time1 = 0.0;

protected:

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
	//Area();

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

