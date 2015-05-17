#ifndef WORLDOBJ_H_
#define WORLDOBJ_H_
#include <GL/glew.h>//it actually fucking matters what order to put these in
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include <vector>

namespace objects
{
	class worldObj
	{
		public:
			void draw();
	};
}

GLuint loadShader(const char* vertexFileName, const char* fragmentFileName);


#endif