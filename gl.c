#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

void setup(){glClearColor(1.0f,1.0f,1.0f);}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glColor3f(0.0f,0.0f,0.0f);
	glRectf(-0.75f,0.75f,0.75,-0.75f);
	glutSwapBuffer();
	}

	int main(int argc,char *argv[])
	{

      glutInit(&agrc,argv);
      glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);

      glutInitWindow(800,800);
      glutCreateWindow("hello word");

      setup();

      glutDispalyFunc(display);

      glutMainLoop();

      return 0;

	}