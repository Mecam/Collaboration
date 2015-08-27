#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include <iostream>
#include <vector>
using namespace std;
class VertexObject
{
public:
	GLuint vao;
	GLuint vbo;
	int i;
	vector<GLfloat> data;

	VertexObject(vector<GLfloat> verts, vector<GLfloat> tex, vector<GLfloat> norms)
	{
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		printf("%u\n", vbo);

		data.insert(data.end(), verts.begin(), verts.end());
		data.insert(data.end(), tex.begin(), tex.end());
		data.insert(data.end(), norms.begin(), norms.end());
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), &data[0], GL_STATIC_DRAW);

		cout << verts.size() * sizeof(GLfloat) << endl;

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * verts.size()));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * (verts.size() + tex.size())));


		glBindVertexArray(0);



	}
	VertexObject(vector<GLfloat> verts, vector<GLfloat> tex)
	{
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		printf("%u\n", vbo);

		data.insert(data.end(), verts.begin(), verts.end());
		data.insert(data.end(), tex.begin(), tex.end());
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), &data[0], GL_STATIC_DRAW);

		cout << verts.size() / sizeof(GLfloat) << endl;

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * verts.size()));



		glBindVertexArray(0);



	}
	void ConfBuf(vector<GLfloat> verts, vector<GLfloat> texture, vector<GLfloat> norms)
	{
		//TODO
	}
	void use()
	{
		glBindVertexArray(vao);

	}

	~VertexObject(void)
	{
		glDeleteBuffers(1, &vbo);
		glDeleteVertexArrays(1, &vao);
	}
};
class Texture
{
public:

	GLuint tex;
	Texture(char* source)
	{

		glGenTextures(1, &tex);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		image = SOIL_load_image(source, &width, &height, 0, SOIL_LOAD_RGB);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
		SOIL_free_image_data(image);

	}
	void use()
	{
		glBindTexture(GL_TEXTURE_2D, tex);
	}
	~Texture(void)
	{
		glDeleteTextures(1, &tex);
	}
private:
	int width, height;
	unsigned char* image;
};
class FrameBuffer
{
public:
	GLuint fBuf;
	GLuint texC;
	GLuint texST;

	FrameBuffer(int w, int h)
	{

		glGenFramebuffers(1, &fBuf);
		glBindFramebuffer(GL_FRAMEBUFFER, fBuf);



		glGenTextures(1, &texC);
		glBindTexture(GL_TEXTURE_2D, texC);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texC, 0);
		glBindTexture(GL_TEXTURE_2D, 0);



		glGenTextures(1, &texST);
		glBindTexture(GL_TEXTURE_2D, texST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, w, h, 0, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, NULL);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, texST, 0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

	}
	void use()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, fBuf);
	}
	void bindColorBuf()
	{
		glBindTexture(GL_TEXTURE_2D, texC);
	}
	~FrameBuffer()
	{
		glDeleteFramebuffers(1, &fBuf);
	}
};
void resetV()
{
	glBindVertexArray(0);
}
void resetF()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
