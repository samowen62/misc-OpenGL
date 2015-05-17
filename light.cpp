#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "worldObj.h"

static int aroundZ = 0;
static int aroundX = 0;
static int zoom = 100;
static int zoomY = 0;

using namespace objects;
worldObj house;

void init(void) 
{
   GLfloat flag [3][5][3] = { {{0.0,2.5,0.0},{3.0,2.5,-3.0},{6.0,2.5,0.0},{7.0,2.5,2.0},{9.0,2.5,0.5}},
                        {{0.0,0.0,0.0},{3.0,0.0,0.0},{6.0,0.0,0.0},{7.0,0.0,0.0},{9.0,0.0,0.0}},
                        {{0.0,-2.5,0.0},{3.0,-2.5,2.0},{6.0,-2.5,0.0},{7.0,-2.5,-3.0},{9.0,-2.5,0.0}}

   };
   glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 3, 0, 1, 15, 3, &flag[0][0][0]);
   glEnable(GL_MAP2_VERTEX_3);
   glEnable(GL_AUTO_NORMAL);
   
   glEnable(GL_DEPTH_TEST);
   glDepthMask(GL_TRUE);
   glDepthFunc(GL_LEQUAL);
   glDepthRange(0.0f, 1.0f);
   GLfloat mat_specular[] = { 0.727811  ,  0.626959  ,  0.626959, 1.0 };
   GLfloat mat_shininess[] = { 6.0 };
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
   GLfloat mat_diffuse[] = {0.61424  ,  0.04136 , 0.04136, 1.0};
   //GLfloat mat_abient[] = {0.1745  , 0.01175 , 0.01175,1.0};
   GLfloat mat_abient[] = {.6,.6,.6,1.0};
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);    //
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);      //
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_abient);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);    //
   glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 2.0);
   //glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 1.0);
   //glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.5);

   glEnable(GL_AMBIENT);
//   glEnable(GL_LIGHTING);                                //
   glEnable(GL_MAP2_VERTEX_3);
   glEnable(GL_LIGHT0);
   glewExperimental=GL_TRUE;
   if (glewInit() != GLEW_OK)
      printf("death\n");
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode (GL_MODELVIEW) ;
   glLoadIdentity();
   gluLookAt(20.0,0.0,0.0, 0.0,0.0,0.0, 0.0,1.0,0.0);
   glTranslatef(-zoom,0.f,0.f);
   glTranslatef(0.f,-zoomY,0.f);
   glRotatef(aroundZ, 0.f, 0.f, 1.f);
   glRotatef(aroundX, 0.f, 1.f, 0.f);
   house.draw();
   glutSwapBuffers();
}

void reshape (int w, int h)
{
   float ratio = (1.0*w)/h;
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   gluPerspective(45.0,ratio,2.0,1000.0);
   
   glMatrixMode(GL_MODELVIEW);
}

void rot (unsigned char key, int x, int y){//x and y tell where mouse is
   switch(key){
      case 'a':
         aroundZ = (aroundZ + 3) % 360;
         break;
      case 'd':
         aroundZ = (aroundZ - 3) % 360;
         break;
      case 'w':
         aroundX = (aroundX + 3) % 360;
         break;
      case 's':
         aroundX = (aroundX - 3) % 360;
         break;
      case 'z':
         zoom += 1;
         break;
      case 'x':
         zoom -= 1;
         break;
      case 'c':
         zoomY += 1;
         break;
      case 'v':
         zoomY -= 1;
         break;
   }
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (800, 800); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(rot);
   glutMainLoop();
   return 0;
}