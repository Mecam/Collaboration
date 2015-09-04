
#ifndef _SHADER_DAT_
#define _SHADER_DAT_
#define GLSL(src) "#version 330 core\n" #src

static char* basicVertex = GLSL(
	layout(location = 0) in vec3 position;
	layout(location = 1) in vec2 texPos;
	out vec2 texCoord;

	void main()
	{
		texCoord = texPos;
		gl_Position = vec4(position, 1.0f);
	}
);

static char* basicFragment = GLSL(
	in vec2 texCoord;
	layout(location = 0) out vec4 outColor;
	uniform sampler2D tex;

	void main()
	{
		outColor = texture(tex, texCoord);
	 
	}
);

static char* Vectorv = GLSL(
	layout(location = 0) in vec3 position;
	layout(location = 1) in vec3 color;
	out vec3 Color;
	void main()
	{
		gl_Position = vec4(position, 1.0f);
		Color = color;
	}
);

static char* Vectorf = GLSL(
	layout(location = 0) out vec4 outColor;
	in vec3 Color;
	void main()
	{
		outColor = vec4(Color, 1.0f);
	}
);
#endif

