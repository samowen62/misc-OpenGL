#include "worldObj.h"
#define MODE 1
#define PI 3.14159

using namespace objects;
using namespace std;

/*******crapload of functs******/
	void cube(float faces[9]);
	void house3(); //draws house 3
	void store1(float r, float g, float b); //draws store1
	void store2(float r, float g, float b);
	void hill();
	void flag();
	void capitol();
	void house2(float r, float g, float b, float rr, float rg, float rb);
	void ufo();
	void drawDome(int rad);
	void window();
	void semicircle(float rad);
	void mountains();
	void mole();
	void saturn();
	void satfeet();
	void plane();
	void wave(int step);

/********************************/


void worldObj::draw(){
	glClear(GL_DEPTH_BUFFER_BIT);

    //house3(); //this is cool so far
    //store1(.6,.6,.6);
    //capitol();
    //store2(.8,.1,.2);
	//house2(0.f,.74,1.0,.04,.04,.38);
	//ufo();
	//hill();
	//flag();
	//mountains();
	//saturn();
	//wave(2);
	plane();
}

static unsigned int planeShdr = 0;
static bool triedPlaneshdr = false;

void plane(){
	float land[11][11][3] = {{{-6.0f, -6.0f, 3.0f}, {-4.8f, -6.0f, 3.039f}, {-3.6f, -6.0f, 3.3f}, {-2.4f, -6.0f, 3.934f}, {-1.2f, -6.0f, 4.987f}, {0.0f, -6.0f, 6.375f}, {1.2f, -6.0f, 7.908f}, {2.4f, -6.0f, 9.325f}, {3.6f, -6.0f, 10.373f}, {4.8f, -6.0f, 10.902f}, {6.0f, -6.0f, 11.0f}}, {{-6.0f, -4.8f, 3.0f}, {-4.8f, -4.8f, 3.04f}, {-3.6f, -4.8f, 3.302f}, {-2.4f, -4.8f, 3.937f}, {-1.2f, -4.8f, 4.986f}, {0.0f, -4.8f, 6.364f}, {1.2f, -4.8f, 7.882f}, {2.4f, -4.8f, 9.282f}, {3.6f, -4.8f, 10.314f}, {4.8f, -4.8f, 10.836f}, {6.0f, -4.8f, 10.932f}}, {{-6.0f, -3.6f, 3.0f}, {-4.8f, -3.6f, 3.042f}, {-3.6f, -3.6f, 3.309f}, {-2.4f, -3.6f, 3.941f}, {-1.2f, -3.6f, 4.962f}, {-0.0f, -3.6f, 6.282f}, {1.2f, -3.6f, 7.714f}, {2.4f, -3.6f, 9.019f}, {3.6f, -3.6f, 9.973f}, {4.8f, -3.6f, 10.449f}, {6.0f, -3.6f, 10.537f}}, {{-6.0f, -2.4f, 3.0f}, {-4.8f, -2.4f, 3.044f}, {-3.6f, -2.4f, 3.311f}, {-2.4f, -2.4f, 3.919f}, {-1.2f, -2.4f, 4.867f}, {0.0f, -2.4f, 6.056f}, {1.2f, -2.4f, 7.312f}, {2.4f, -2.4f, 8.431f}, {3.6f, -2.4f, 9.231f}, {4.8f, -2.4f, 9.624f}, {6.0f, -2.4f, 9.695f}}, {{-6.0f, -1.2f, 3.0f}, {-4.8f, -1.2f, 3.043f}, {-3.6f, -1.2f, 3.295f}, {-2.4f, -1.2f, 3.842f}, {-1.2f, -1.2f, 4.662f}, {-0.0f, -1.2f, 5.649f}, {1.2f, -1.2f, 6.655f}, {2.4f, -1.2f, 7.522f}, {3.6f, -1.2f, 8.123f}, {4.8f, -1.2f, 8.41f}, {6.0f, -1.2f, 8.46f}}, {{-6.0f, 0.0f, 3.0f}, {-4.8f, -0.0f, 3.038f}, {-3.6f, -0.0f, 3.252f}, {-2.4f, -0.0f, 3.699f}, {-1.2f, 0.0f, 4.339f}, {0.0f, 0.0f, 5.078f}, {1.2f, 0.0f, 5.799f}, {2.4f, -0.0f, 6.394f}, {3.6f, 0.0f, 6.789f}, {4.8f, 0.0f, 6.969f}, {6.0f, 0.0f, 7.0f}}, {{-6.0f, 1.2f, 3.0f}, {-4.8f, 1.2f, 3.029f}, {-3.6f, 1.2f, 3.186f}, {-2.4f, 1.2f, 3.501f}, {-1.2f, 1.2f, 3.936f}, {-0.0f, 1.2f, 4.417f}, {1.2f, 1.2f, 4.864f}, {2.4f, 1.2f, 5.213f}, {3.6f, 1.2f, 5.431f}, {4.8f, 1.2f, 5.525f}, {6.0f, 1.2f, 5.54f}}, {{-6.0f, 2.4f, 3.0f}, {-4.8f, 2.4f, 3.017f}, {-3.6f, 2.4f, 3.11f}, {-2.4f, 2.4f, 3.29f}, {-1.2f, 2.4f, 3.529f}, {0.0f, 2.4f, 3.782f}, {1.2f, 2.4f, 4.005f}, {2.4f, 2.4f, 4.169f}, {3.6f, 2.4f, 4.263f}, {4.8f, 2.4f, 4.3f}, {6.0f, 2.4f, 4.305f}}, {{-6.0f, 3.6f, 3.0f}, {-4.8f, 3.6f, 3.007f}, {-3.6f, 3.6f, 3.044f}, {-2.4f, 3.6f, 3.115f}, {-1.2f, 3.6f, 3.206f}, {-0.0f, 3.6f, 3.298f}, {1.2f, 3.6f, 3.375f}, {2.4f, 3.6f, 3.427f}, {3.6f, 3.6f, 3.454f}, {4.8f, 3.6f, 3.462f}, {6.0f, 3.6f, 3.463f}}, {{-6.0f, 4.8f, 3.0f}, {-4.8f, 4.8f, 3.001f}, {-3.6f, 4.8f, 3.007f}, {-2.4f, 4.8f, 3.019f}, {-1.2f, 4.8f, 3.033f}, {-0.0f, 4.8f, 3.047f}, {1.2f, 4.8f, 3.058f}, {2.4f, 4.8f, 3.065f}, {3.6f, 4.8f, 3.068f}, {4.8f, 4.8f, 3.068f}, {6.0f, 4.8f, 3.068f}}, {{-6.0f, 6.0f, 3.0f}, {-4.8f, 6.0f, 3.0f}, {-3.6f, 6.0f, 3.0f}, {-2.4f, 6.0f, 3.0f}, {-1.2f, 6.0f, 3.0f}, {0.0f, 6.0f, 3.0f}, {1.2f, 6.0f, 3.0f}, {2.4f, 6.0f, 3.0f}, {3.6f, 6.0f, 3.0f}, {4.8f, 6.0f, 3.0f}, {6.0f, 6.0f, 3.0f}}};



	GLint shdFd;
	if (!planeShdr && !triedPlaneshdr) {
		triedPlaneshdr = true;
		char* error;
		if (!(planeShdr = loadShader("plane.vert", "plane.frag"))) {
			printf("error with plane shader");
		}
	}
	/*glUseProgram(planeShdr);

	GLfloat mvMatrix[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, mvMatrix);
	GLfloat projectionMatrix[16];
	glGetFloatv(GL_PROJECTION_MATRIX, projectionMatrix);

	if ((shdFd = glGetUniformLocation(planeShdr, "MV")) != -1){
		glUniformMatrix4fv(shdFd, 1, GL_FALSE, &mvMatrix[0]);
	};
	if ((shdFd = glGetUniformLocation(planeShdr, "P")) != -1){
		glUniformMatrix4fv(shdFd, 1, GL_FALSE, &projectionMatrix[0]);
	};*/
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(0.f,.7f,.3f);
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++){
			glVertex3fv((const GLfloat *)&land[i][j]);
			glVertex3fv((const GLfloat *)&land[i+1][j]);
			glVertex3fv((const GLfloat *)&land[i+1][j+1]);
			glVertex3fv((const GLfloat *)&land[i][j+1]);
		}
	glEnd();
	glPopMatrix();
	//glUseProgram(0);

}


void wave(int step){
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(0.f,.5,.75);
	float curr = 0.0, next = 0.0;
	for (float j = 0.0; j < 40;j+=5.0){
		for(float i = 5.0*step; i < 5*step + 40; i+=5.0){
			//fprintf(stdout, "%d\n", (int)i%40);
			switch(((int)i % 40)/5){
				case 0:
					next = 2.9;
					curr = 0.0;
					goto c7;
				case 7:
					curr = -2.9;
					next = 0.0;
				c7:
					glNormal3f(-.5,.866,0.f);
					break;
				case 1:
					next = 4.2;
					curr = 2.9;
					goto c6;
				case 6:
					curr = -4.2;
					next = -2.9;
				c6:
					glNormal3f(-.25,.96,0.f);
					break;
				case 2:
					next = 2.9;
					curr = 4.2;
					goto c5;
				case 5:
					curr = -2.9;
					next = -4.2;
				c5:
					glNormal3f(.25,.96,0.f);
					break;
				case 3:
					curr = 2.9;
					next = 0.0;
					goto c4;
				case 4:
					next = -2.9;
					curr = 0.0;
				c4:
					glNormal3f(.5,.866,0.f);
					break;
			}
			//fprintf(stdout, "%f %f\n", curr, next);
			glVertex3f(i+5.0,next,j);
			glVertex3f(i+5.0,next,j+5.0);
			glVertex3f(i,curr,j+5.0);
			glVertex3f(i,curr,j);
		}
	}
	glEnd();
	glPopMatrix();
}

void saturn(){
	glColor3f(.96,.85,.51);
	glPushMatrix();
		glTranslatef(1.0,1.5,3.0);
		//satfeet();
		glScalef(1.0,.7,1.0);
		glutSolidSphere(2.0,10,10);
		glTranslatef(0.f,0.f,-6.f);
		//satfeet();
		glutSolidSphere(2.0,10,10);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.f,6.f,0.f);
		glutSolidSphere(5, 15, 15);
		glTranslatef(5.f,-.5,0.f);
		glutSolidSphere(2.5,8,8);
		glTranslatef(-1.0,2.7,2.5);
		glColor3f(0.f,0.f,0.f);
		glutSolidSphere(.5,5,5);
		glTranslatef(0.f,0.f,-5.0);
		glutSolidSphere(.5,5,5);
	glPopMatrix();
}

void satfeet(){
	glBegin(GL_QUADS);
		glNormal3f(0.f,1.f,0.f);//because I'm lazy
		glVertex3f(-.7,1.f,.8);
		glVertex3f(.7,1.f,.8);
		glVertex3f(.7,0.0,2.0);
		glVertex3f(-.7,0.0,2.0);
		glNormal3f(0.f,1.f,0.f);
		glVertex3f(.7,1.0,-.8);
		glVertex3f(-.7,1.0,-.8);
		glVertex3f(-.7,0.0,-2.0);
		glVertex3f(.7,0.0,-2.0);

		glNormal3f(0.f,1.f,0.f);
		glVertex3f(-.7,1.0,-.8);
		glVertex3f(-.7,1.0,.8);
		glVertex3f(-2.5,0.0,.8);
		glVertex3f(-2.5,0.0,-.8);
		glNormal3f(0.f,1.f,0.f);
		glVertex3f(.7,1.0,.8);
		glVertex3f(.7,1.0,-.8);
		glVertex3f(2.5,0.0,-.8);
		glVertex3f(2.5,0.0,.8);

		glNormal3f(0.f,1.f,0.f);
		glVertex3f(-.7,1.0,-.8);
		glVertex3f(.7,1.0,-.8);
		glVertex3f(.7,1.0,.8);
		glVertex3f(-.7,1.0,.8);

		glNormal3f(0.f,-1.f,0.f);//because I'm lazy
		glVertex3f(-.7,-1.0,.8);
		glVertex3f(.7,-1.0,.8);
		glVertex3f(.7,0.0,2.0);
		glVertex3f(-.7,0.0,2.0);
		glNormal3f(0.f,-1.f,0.f);
		glVertex3f(.7,-1.0,-.8);
		glVertex3f(-.7,-1.0,-.8);
		glVertex3f(-.7,0.0,-2.0);
		glVertex3f(.7,0.0,-2.0);

		glNormal3f(0.f,-1.f,0.f);
		glVertex3f(-.7,-1.0,-.8);
		glVertex3f(-.7,-1.0,.8);
		glVertex3f(-2.5,0.0,.8);
		glVertex3f(-2.5,0.0,-.8);
		glNormal3f(0.f,-1.f,0.f);
		glVertex3f(.7,-1.0,.8);
		glVertex3f(.7,-1.0,-.8);
		glVertex3f(2.5,0.0,-.8);
		glVertex3f(2.5,0.0,.8);

		glNormal3f(0.f,-1.f,0.f);
		glVertex3f(-.7,-1.0,.8);
		glVertex3f(.7,-1.0,.8);
		glVertex3f(.7,-1.0,-.8);
		glVertex3f(-.7,-1.0,-.8);

		//now for the 4 oddballs NOT 8
		glNormal3f(-.83,0.f,-.56);
		glVertex3f(-.7,1.0,-.8);
		glVertex3f(-.7,0.0,-2.0);
		glVertex3f(-.7,-1.0,-.8);
		glVertex3f(-2.5,0.0,-.8);

		glNormal3f(.83,0.f,.56);
		glVertex3f(.7,1.0,.8);
		glVertex3f(.7,0.0,2.0);
		glVertex3f(.7,-1.0,.8);
		glVertex3f(2.5,0.0,.8);

		glNormal3f(.83,0.f,-.56);
		glVertex3f(.7,1.0,-.8);
		glVertex3f(.7,0.0,-2.0);
		glVertex3f(.7,-1.0,-.8);
		glVertex3f(2.5,0.0,-.8);

		glNormal3f(-.83,0.f,.56);
		glVertex3f(-.7,1.0,.8);
		glVertex3f(-.7,0.0,2.0);
		glVertex3f(-.7,-1.0,.8);
		glVertex3f(-2.5,0.0,.8);
	glEnd();

};

void mountains(){
	glColor3f(0.2,0.64,0.1);
	float a[6] = {36.0,26.4,21.6,18.0,12.0,0.0};
	float b[6] = {60.0,44.0,36.0,30.0,20.0,0.0};
	float y[6] = {0.0,4.28,8.8,14.8,20.6,25.8};

	glPushMatrix();
		glBegin(GL_QUADS);
		float ux,lx;
		int i,j;
		for(i = 0; i < 360; i += 9){
				ux = i * (PI / 180);
				lx = (i + 9) * (PI / 180);
				glNormal3f(.259*cos(ux),.966,.259*sin(lx));
				glVertex3f(a[0]*cos(ux),y[0],b[0]*sin(ux));
				glVertex3f(a[0]*cos(lx),y[0],b[0]*sin(lx));
				glVertex3f(a[1]*cos(lx),y[1],b[1]*sin(lx));
				glVertex3f(a[1]*cos(ux),y[1],b[1]*sin(ux));

				glNormal3f(.5*cos(ux),.866,.5*sin(lx));
				glVertex3f(a[1]*cos(ux),y[1],b[1]*sin(ux));
				glVertex3f(a[1]*cos(lx),y[1],b[1]*sin(lx));
				glVertex3f(a[2]*cos(lx),y[2],b[2]*sin(lx));
				glVertex3f(a[2]*cos(ux),y[2],b[2]*sin(ux));
				
				glNormal3f(.71*cos(ux),.71,.71*sin(lx));
				glVertex3f(a[2]*cos(ux),y[2],b[2]*sin(ux));
				glVertex3f(a[2]*cos(lx),y[2],b[2]*sin(lx));
				glVertex3f(a[3]*cos(lx),y[3],b[3]*sin(lx));
				glVertex3f(a[3]*cos(ux),y[3],b[3]*sin(ux));
				
				glNormal3f(.5*cos(ux),.866,.5*sin(lx));
				glVertex3f(a[3]*cos(ux),y[3],b[3]*sin(ux));
				glVertex3f(a[3]*cos(lx),y[3],b[3]*sin(lx));
				glVertex3f(a[4]*cos(lx),y[4],b[4]*sin(lx));
				glVertex3f(a[4]*cos(ux),y[4],b[4]*sin(ux));
			
				glNormal3f(.259*cos(ux),.966,.259*sin(lx));
				glVertex3f(a[4]*cos(ux),y[4],b[4]*sin(ux));
				glVertex3f(a[4]*cos(lx),y[4],b[4]*sin(lx));
				glVertex3f(a[5]*cos(lx),y[5],b[5]*sin(lx));
				glVertex3f(a[5]*cos(ux),y[5],b[5]*sin(ux));
			
		}
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(60.0,0.f,0.f);
		mole();
		glTranslatef(-30.0,0.f,40.f);
		glScalef(2.0,2.0,2.0);
		mole();
	glPopMatrix();
}

void mole(){
	float r[7] = {31.0,25.0,22.0,12.0,9.0,5.0,0.0};
	float yy[7] = {0.0,3.5,6.7,24.0,27.0,29.0,30.3};
	float ux,lx;
	int i,j;

	glBegin(GL_QUADS);
		for(i = 0; i < 360; i += 9){
				ux = i * (PI / 180);
				lx = (i + 9) * (PI / 180);
				glNormal3f(.5*cos(ux),.866,.5*sin(lx));
				glVertex3f(r[0]*cos(ux),yy[0],r[0]*sin(ux));
				glVertex3f(r[0]*cos(lx),yy[0],r[0]*sin(lx));
				glVertex3f(r[1]*cos(lx),yy[1],r[1]*sin(lx));
				glVertex3f(r[1]*cos(ux),yy[1],r[1]*sin(ux));

				glNormal3f(.71*cos(ux),.71,.71*sin(lx));
				glVertex3f(r[1]*cos(ux),yy[1],r[1]*sin(ux));
				glVertex3f(r[1]*cos(lx),yy[1],r[1]*sin(lx));
				glVertex3f(r[2]*cos(lx),yy[2],r[2]*sin(lx));
				glVertex3f(r[2]*cos(ux),yy[2],r[2]*sin(ux));
				
				glNormal3f(.866*cos(ux),.5,.866*sin(lx));
				glVertex3f(r[2]*cos(ux),yy[2],r[2]*sin(ux));
				glVertex3f(r[2]*cos(lx),yy[2],r[2]*sin(lx));
				glVertex3f(r[3]*cos(lx),yy[3],r[3]*sin(lx));
				glVertex3f(r[3]*cos(ux),yy[3],r[3]*sin(ux));
				
				glNormal3f(.71*cos(ux),.71,.71*sin(lx));
				glVertex3f(r[3]*cos(ux),yy[3],r[3]*sin(ux));
				glVertex3f(r[3]*cos(lx),yy[3],r[3]*sin(lx));
				glVertex3f(r[4]*cos(lx),yy[4],r[4]*sin(lx));
				glVertex3f(r[4]*cos(ux),yy[4],r[4]*sin(ux));
			
				glNormal3f(.5*cos(ux),.866,.5*sin(lx));
				glVertex3f(r[4]*cos(ux),yy[4],r[4]*sin(ux));
				glVertex3f(r[4]*cos(lx),yy[4],r[4]*sin(lx));
				glVertex3f(r[5]*cos(lx),yy[5],r[5]*sin(lx));
				glVertex3f(r[5]*cos(ux),yy[5],r[5]*sin(ux));

				glNormal3f(.259*cos(ux),.966,.259*sin(lx));
				glVertex3f(r[5]*cos(ux),yy[5],r[5]*sin(ux));
				glVertex3f(r[5]*cos(lx),yy[5],r[5]*sin(lx));
				glVertex3f(r[6]*cos(lx),yy[6],r[6]*sin(lx));
				glVertex3f(r[6]*cos(ux),yy[6],r[6]*sin(ux));
			
		}
	glEnd();
}

void cube(float faces[9]){//put in order of x,y,z x,y,z r,g,b
	float currface, ul, ur, ll, lr;

	glPushMatrix();

	if(MODE == 1){
    	glBegin(GL_TRIANGLES);
    	glColor3f(faces[6],faces[7],faces[8]);

    	for(int i = 0; i < 6; i++){
    		currface = faces[i];
    		ul = faces[(i + 1) % 6];
    		ur = faces[(i + 2) % 6];
    		ll = faces[(i + 4) % 6];
    		lr = faces[(i + 5) % 6];
    		switch(i){
    			case 0:
    			case 3:
    				glVertex3f(currface,ul,lr);
    				glVertex3f(currface,ul,ur);
    				glVertex3f(currface,ll,lr);
    				glVertex3f(currface,ul,ur);
    				glVertex3f(currface,ll,lr);
    				glVertex3f(currface,ll,ur);
    				break;
    			case 1:
    			case 4:
    				glVertex3f(lr,currface,ul);
    				glVertex3f(ur,currface,ul);
    				glVertex3f(lr,currface,ll);
    				glVertex3f(ur,currface,ul);
    				glVertex3f(lr,currface,ll);
    				glVertex3f(ur,currface,ll);
    				break;
    			default:
    				glVertex3f(ul,lr,currface);
    				glVertex3f(ul,ur,currface);
    				glVertex3f(ll,lr,currface);
    				glVertex3f(ul,ur,currface);
    				glVertex3f(ll,lr,currface);
    				glVertex3f(ll,ur,currface);
    		}
    	}

    	glEnd();
    }
    /*
    else if( MODE == 2){

    }
    else if (MODE == 3){//you'd better freaking make sure the lower values of x,y and z are listed first
    					//because I don't feel like modifying this right now, but I probs will in the future
    	for(int i = 0; i < 6; i++){
    		double tmp;
    		currface = faces[i];
    		ul = faces[(i + 1) % 6];
    		ur = faces[(i + 2) % 6];
    		ll = faces[(i + 4) % 6];
    		lr = faces[(i + 5) % 6];
    		switch(i){
    			case 3:
    				tmp = ul;
    				ll = tmp;
    				ul = ll;
    			case 0:
    				polygoni(4, currface,ul,ur, currface,ll,ur, currface,ll,lr, currface,ul,lr);
    				break;
    			case 4:
    				tmp = ul;
    				ll = tmp;
    				ul = ll;
    			case 1:
    				glVertex3f(lr,currface,ul);
    				glVertex3f(ur,currface,ul);
    				glVertex3f(lr,currface,ll);
    				glVertex3f(ur,currface,ul);
    				glVertex3f(lr,currface,ll);
    				glVertex3f(ur,currface,ll);
    				break;
    			case 5:
    				tmp = ul;
    				ll = tmp;
    				ul = ll;
    			case 2:
    				glVertex3f(ul,lr,currface);
    				glVertex3f(ul,ur,currface);
    				glVertex3f(ll,lr,currface);
    				glVertex3f(ul,ur,currface);
    				glVertex3f(ll,lr,currface);
    				glVertex3f(ll,ur,currface);
    			glEnd();
    		}
    }*/
    
    glPopMatrix();
}

void house3(){
		float x [8] = {-25.0,-20.0, -17.0, -13.0,-5.0,-3.0,-2.0,0.0};
		float y [9] = {0.0,2.0,4.0,17.0,18.0,20.0,20 + 9.0, 38.0,43.0};
		float z [11] = {-20.0,-18.0,-17.0,-15.0,-3.0,0.0,3.0,6.0,10.0,19.5,20.0};

		float yellowBlock [9] = {x[0],y[1],z[2],x[3],y[5],z[5] +0.5,1.0,1.0,0.0};
        float porch [9] = {x[0] - .1,y[0],z[2] - .5,x[6] + .1,y[2],z[5] + .5,.4,.12,.04};
        float step [9] = {x[6],y[0],z[3],x[7],y[1],z[4],.2,.2,.2};
        float knoll1 [9] = {x[4],y[3],z[2] - .5,x[6],y[5],z[3],1.0,1.0,1.0};
        float knoll2 [9] = {x[4],y[3],z[4],x[6],y[5],z[5],1.0,1.0,1.0};
        float post1 [9] = {x[4],y[2],z[2],x[5],y[3],z[3],1.0,1.0,1.0};
        float post2 [9] = {x[4],y[2],z[4],x[5],y[3],z[5],1.0,1.0,1.0};
        float beam1 [9] = {x[4],y[3],z[3],x[5],y[4],z[4],1.0,1.0,1.0};
        float beam2 [9] = {x[3],y[3],z[2],x[6],y[4],z[3],1.0,1.0,1.0};
        float beam3 [9] = {x[3],y[3],z[4],x[4],y[4],z[5],1.0,1.0,1.0};
        float chimney [9] = {x[1],y[6],z[6],x[2],y[8],z[7],.2,.2,.2};
        float leftBlock [9] = {x[0] - .1,y[0],z[5] + 0.5,x[7],y[5],z[9],1.0,1.0,0.};
        cube(yellowBlock);
        cube(porch);
        cube(knoll1);
        cube(knoll2);
        cube(post1);
        cube(post2);
        cube(beam1);
        cube(beam2);
        cube(beam3);
        cube(step);
        cube(chimney);
        cube(leftBlock);
    glPushMatrix();
      	glBegin(GL_TRIANGLES);

    	glColor3f(1.0,1.0,0.0);
    	glVertex3f(x[6],y[5],z[2] - .5);
    	glVertex3f(x[6],y[6],(z[3] + z[4])/2.0);
    	glVertex3f(x[6],y[5],z[5] + .5);
    	glVertex3f(x[0],y[5],z[2] - .5);
    	glVertex3f(x[0],y[7],z[5] + .5);
    	glVertex3f(x[0],y[5],z[9]);

    	glVertex3f(x[3],y[7],z[5] + .5);    	
    	glVertex3f(x[3],y[5],z[5] + .5);
    	glVertex3f(x[7],y[5],z[5] + .5);

    	glVertex3f(x[6],y[5],z[2] - .5);
    	glVertex3f(x[0],y[5],z[2] - .5);
    	glVertex3f(x[6],y[5],z[5] + .5);
    	glVertex3f(x[0],y[5],z[2] - .5);
    	glVertex3f(x[6],y[5],z[5] + .5);
    	glVertex3f(x[0],y[5],z[5] + .5);

    	glVertex3f(x[3],y[5],z[5] + .5);
    	glVertex3f(x[3],y[6],(z[3] + z[4])/2.0);
    	glVertex3f(x[3],y[7],z[5] + .5);


    	glColor3f(1.0,0.0,0.0);
    	glVertex3f(x[6],y[6],(z[3] + z[4])/2.0);
    	glVertex3f(x[6],y[5],z[2] - .5);
    	glVertex3f(x[0],y[6],(z[3] + z[4])/2.0);
    	glVertex3f(x[6],y[5],z[2] - .5);
    	glVertex3f(x[0],y[6],(z[3] + z[4])/2.0);
    	glVertex3f(x[0],y[5],z[2] - .5);

    	glVertex3f(x[3],y[6],(z[3] + z[4])/2.0);
    	glVertex3f(x[3],y[7],z[5] + .5);
    	glVertex3f(x[0],y[6],(z[3] + z[4])/2.0);
    	glVertex3f(x[3],y[7],z[5] + .5);
    	glVertex3f(x[0],y[6],(z[3] + z[4])/2.0);
    	glVertex3f(x[0],y[7],z[5] + .5);

    	glVertex3f(x[3],y[6],(z[3] + z[4])/2.0);
    	glVertex3f(x[3],y[5],z[5] + .5);
    	glVertex3f(x[6],y[6],(z[3] + z[4])/2.0);
    	glVertex3f(x[3],y[5],z[5] + .5);
    	glVertex3f(x[6],y[6],(z[3] + z[4])/2.0);
    	glVertex3f(x[6],y[5],z[5] + .5);

		glVertex3f(x[3],y[7],z[5] + .5);    	
    	glVertex3f(x[7],y[5],z[5] + .5);
    	glVertex3f(x[7],y[5],z[9]);

    	glVertex3f(x[3],y[7],z[5] + .5);    	
    	glVertex3f(x[7],y[5],z[9]);
    	glVertex3f(x[3],y[5],z[9]);

    	glVertex3f(x[3],y[7],z[5] + .5);    	
    	glVertex3f(x[3],y[5],z[9]);
    	glVertex3f(x[0],y[7],z[5] + .5);
    	glVertex3f(x[3],y[5],z[9]);
    	glVertex3f(x[0],y[7],z[5] + .5);
    	glVertex3f(x[0],y[5],z[9]);

    	glEnd();
   	glPopMatrix();
}


void store1(float r,float g, float b){
	float x [11] = {-22.0,-21.0,-20.0,-16.0,-15.0,-13.0,-8.0,-6.0,-5.0,-4.0,-3.0}; //the model is symetrical across x 
	float y [15] = {0.0,4.0,18.0,20.0,21.0,27.0,28.0,30.0,35.0,36.0,41.0,43.0,44.0,49.0,52.0};
	float z [8] = {22.0,21.0,20.0,17.0,16.0,7.0,6.0,4.0};
	int i;

	glColor3f(1.0,0.0,0.0);	//there are 16 knolls for 4 windows and there's also a door with 2

	float base [9] = {x[2],y[0],z[2],-x[2],y[13],-z[2],r,g,b};
	float stoop [9] = {x[6],y[0],z[0] + 4,-x[6],y[1],z[2],.3,.3,.3};
	//float porch [9] = {x[1],y[0],z[2],(-1.0) *x[1],(-1.0) *y[13],(-1.0) *z[2] +0.5,1.0,0.0,0.0};
	float leftKnolls [4][9] = {	{x[0],y[10],z[5],x[2],y[12],z[7],1.0,1.0,1.0},
								{x[0],y[5],z[5],x[2],y[7],z[7],1.0,1.0,1.0},
								{x[0],y[5],-z[5],x[2],y[7],-z[7],1.0,1.0,1.0},
								{x[0],y[10],-z[5],x[2],y[12],-z[7],1.0,1.0,1.0}};
	float rightKnolls [4][9] = {	{-x[0],y[10],z[5],-x[2],y[12],z[7],1.0,1.0,1.0},
								{-x[0],y[5],z[5],-x[2],y[7],z[7],1.0,1.0,1.0},
								{-x[0],y[5],-z[5],-x[2],y[7],-z[7],1.0,1.0,1.0},
								{-x[0],y[10],-z[5],-x[2],y[12],-z[7],1.0,1.0,1.0}};
	float flKnolls [4][9] = {	{-x[3],y[10],z[0],-x[5],y[12],z[2],1.0,1.0,1.0},
								{-x[3],y[5],z[0],-x[5],y[7],z[2],1.0,1.0,1.0},
								{-x[7],y[5],z[0],-x[10],y[7],z[2],1.0,1.0,1.0},
								{-x[7],y[10],z[0],-x[10],y[12],z[2],1.0,1.0,1.0}};
	float frKnolls [4][9] = {	{x[3],y[10],z[0],x[5],y[12],z[2],1.0,1.0,1.0},
								{x[3],y[5],z[0],x[5],y[7],z[2],1.0,1.0,1.0},
								{x[7],y[5],z[0],x[10],y[7],z[2],1.0,1.0,1.0},
								{x[7],y[10],z[0],x[10],y[12],z[2],1.0,1.0,1.0}};

	float leftBeams [5][9] = {	{x[1],y[7],z[6],x[2],y[10],z[7],1.0,1.0,1.0},
								{x[1],y[7],-z[6],x[2],y[10],-z[7],1.0,1.0,1.0},
								{x[1],y[6],-z[7],x[2],y[7],z[7],1.0,1.0,1.0},
								{x[1],y[8],-z[7],x[2],y[9],z[7],1.0,1.0,1.0},
								{x[1],y[10],-z[7],x[2],y[11],z[7],1.0,1.0,1.0}};
	float rightBeams [5][9] = {	{-x[1],y[7],z[6],-x[2],y[10],z[7],1.0,1.0,1.0},
								{-x[1],y[7],-z[6],-x[2],y[10],-z[7],1.0,1.0,1.0},
								{-x[1],y[6],-z[7],-x[2],y[7],z[7],1.0,1.0,1.0},
								{-x[1],y[8],-z[7],-x[2],y[9],z[7],1.0,1.0,1.0},
								{-x[1],y[10],-z[7],-x[2],y[11],z[7],1.0,1.0,1.0}};
	float flBeams [5][9] = {	{-x[4],y[7],z[1],-x[5],y[10],z[2],1.0,1.0,1.0},
								{-x[7],y[7],z[1],-x[9],y[10],z[2],1.0,1.0,1.0},
								{-x[5],y[6],z[1],-x[7],y[7],z[2],1.0,1.0,1.0},
								{-x[5],y[8],z[1],-x[7],y[9],z[2],1.0,1.0,1.0},
								{-x[5],y[10],z[1],-x[7],y[11],z[2],1.0,1.0,1.0}};
	float frBeams [5][9] = {	{x[4],y[7],z[1],x[5],y[10],z[2],1.0,1.0,1.0},
								{x[7],y[7],z[1],x[9],y[10],z[2],1.0,1.0,1.0},
								{x[5],y[6],z[1],x[7],y[7],z[2],1.0,1.0,1.0},
								{x[5],y[8],z[1],x[7],y[9],z[2],1.0,1.0,1.0},
								{x[5],y[10],z[1] - .5,x[7],y[11],z[2],1.0,1.0,1.0}};
	float topLedge [4][9] = {	{x[0],y[13],z[0],-x[0],y[14],z[2],.2,.2,.2},
								{x[0],y[13],-z[0],-x[0],y[14],-z[2],.2,.2,.2},
								{x[2] + 1,y[13],z[0],x[0],y[14],-z[0],.2,.2,.2},
								{-x[0],y[13],z[0],-x[2] - 1,y[14],-z[0],.2,.2,.2}};
	float doorFrame[5][9] = {  {x[7],y[2],z[0],x[10],y[4],z[2],1.0,1.0,1.0},
								{-x[7],y[2],z[0],-x[10],y[4],z[2],1.0,1.0,1.0},
								{x[7]+1,y[1],z[0],x[10],y[2],z[2],1.0,1.0,1.0},
								{-x[7]-1,y[1],z[0],-x[10],y[2],z[2],1.0,1.0,1.0},
								{x[7],y[2],z[0],-x[10],y[3],z[2],1.0,1.0,1.0}
								};

	glBegin(GL_TRIANGLES);
		glColor3f(0.0,.75,.5);
		glVertex3f((x[1] + x[2])/-2,y[10],-z[7]);
		glVertex3f((x[1] + x[2])/-2,y[10],z[7]);
		glVertex3f((x[1] + x[2])/-2,y[7],-z[7]);
		glVertex3f((x[1] + x[2])/-2,y[7],-z[7]);
		glVertex3f((x[1] + x[2])/-2,y[10],z[7]);
		glVertex3f((x[1] + x[2])/-2,y[7],z[7]);

		glVertex3f((x[1] + x[2])/2,y[10],-z[7]);
		glVertex3f((x[1] + x[2])/2,y[10],z[7]);
		glVertex3f((x[1] + x[2])/2,y[7],-z[7]);
		glVertex3f((x[1] + x[2])/2,y[7],-z[7]);
		glVertex3f((x[1] + x[2])/2,y[10],z[7]);
		glVertex3f((x[1] + x[2])/2,y[7],z[7]);

		glVertex3f(x[7],y[10],(z[1] + z[2])/2);
		glVertex3f(x[4],y[10],(z[1] + z[2])/2);
		glVertex3f(x[7],y[7],(z[1] + z[2])/2);
		glVertex3f(x[7],y[7],(z[1] + z[2])/2);
		glVertex3f(x[4],y[10],(z[1] + z[2])/2);
		glVertex3f(x[4],y[7],(z[1] + z[2])/2);

		glVertex3f(-x[7],y[10],(z[1] + z[2])/2);
		glVertex3f(-x[4],y[10],(z[1] + z[2])/2);
		glVertex3f(-x[7],y[7],(z[1] + z[2])/2);
		glVertex3f(-x[7],y[7],(z[1] + z[2])/2);
		glVertex3f(-x[4],y[10],(z[1] + z[2])/2);
		glVertex3f(-x[4],y[7],(z[1] + z[2])/2);

		glVertex3f(x[10],y[1],(z[1] + z[2])/2);
		glVertex3f(-x[10],y[1],(z[1] + z[2])/2);
		glVertex3f(x[10],y[2],(z[1] + z[2])/2);
		glVertex3f(x[10],y[2],(z[1] + z[2])/2);
		glVertex3f(-x[10],y[1],(z[1] + z[2])/2);
		glVertex3f(-x[10],y[2],(z[1] + z[2])/2);


	glEnd();
	glPushMatrix();
		glColor3f(.4,.4,.4);
		GLUquadricObj *quadratic;
	 	quadratic = gluNewQuadric();
	 	glTranslatef(-15.0,y[13],10.0);
	 	glRotatef(-90, 1.f, 0.f, 0.f); 	
		gluCylinder(quadratic,  2.0,  2.0,  10,  10,  2);
		glTranslatef(0.f,0.f,10.f);
		gluCylinder(quadratic,  3.0,  0.0,  4,  10,  2);
	glPopMatrix();

	cube(base);
	cube(stoop);

	for (i = 0; i < 4; i++){
		cube(leftKnolls[i]);
		cube(rightKnolls[i]);
		cube(flKnolls[i]);
		cube(frKnolls[i]);
		cube(topLedge[i]);
	}
	for(i = 0; i < 5; i++){
		cube(leftBeams[i]);
		cube(rightBeams[i]);
		cube(flBeams[i]);
		cube(frBeams[i]);
		cube(doorFrame[i]);
	}
}

void hill(){
	float r[6] = {1000.0,1002.5,1004.33,1040.0,1041.83,1044.33};
	float y[6] = {0,-.66,-2.5,-57.0,-58.83,-59.5};

	for(int i = 0; i < 6; i++)
	{
		r[i] = r[i]/10;
		y[i] = y[i]/10;
	}

	glPushMatrix();
		glColor3f(.2,.8,0.f);
		glBegin(GL_QUADS);
		float ux,lx;
		int i,j;
		for(i = 0; i < 360; i += 9){
				ux = i * (PI / 180);
				lx = (i + 9) * (PI / 180);
				glNormal3f(.5*cos(ux),.86,.5*sin(lx));
				glVertex3f(r[0]*cos(ux),y[0],r[0]*sin(ux));
				glVertex3f(r[0]*cos(lx),y[0],r[0]*sin(lx));
				glVertex3f(r[1]*cos(lx),y[1],r[1]*sin(lx));
				glVertex3f(r[1]*cos(ux),y[1],r[1]*sin(ux));

				glNormal3f(.71*cos(ux),.71,.71*sin(lx));
				glVertex3f(r[1]*cos(ux),y[1],r[1]*sin(ux));
				glVertex3f(r[1]*cos(lx),y[1],r[1]*sin(lx));
				glVertex3f(r[2]*cos(lx),y[2],r[2]*sin(lx));
				glVertex3f(r[2]*cos(ux),y[2],r[2]*sin(ux));
				
				glNormal3f(.86*cos(ux),.5,.86*sin(lx));
				glVertex3f(r[2]*cos(ux),y[2],r[2]*sin(ux));
				glVertex3f(r[2]*cos(lx),y[2],r[2]*sin(lx));
				glVertex3f(r[3]*cos(lx),y[3],r[3]*sin(lx));
				glVertex3f(r[3]*cos(ux),y[3],r[3]*sin(ux));
				
				glNormal3f(.71*cos(ux),.71,.71*sin(lx));
				glVertex3f(r[3]*cos(ux),y[3],r[3]*sin(ux));
				glVertex3f(r[3]*cos(lx),y[3],r[3]*sin(lx));
				glVertex3f(r[4]*cos(lx),y[4],r[4]*sin(lx));
				glVertex3f(r[4]*cos(ux),y[4],r[4]*sin(ux));
			
				glNormal3f(.5*cos(ux),.86,.5*sin(lx));
				glVertex3f(r[4]*cos(ux),y[4],r[4]*sin(ux));
				glVertex3f(r[4]*cos(lx),y[4],r[4]*sin(lx));
				glVertex3f(r[5]*cos(lx),y[5],r[5]*sin(lx));
				glVertex3f(r[5]*cos(ux),y[5],r[5]*sin(ux));
			
		}
		glEnd();
	glPopMatrix();
}
void flag(){
   	glColor3f(0.f,0.f,0.f);
   	glPushMatrix();
   	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
    glPopMatrix();
    glFlush();

}
void capitol(){
	glPushMatrix();
		float rad = 19;
		int i,j;

		glColor3f(.8,.8,.8);
		GLUquadricObj *quadratic;
	 	quadratic = gluNewQuadric();
	 	//glTranslatef(0.0,3.f,0.0);
	 	glRotatef(-90, 1.f, 0.f, 0.f); 	
		gluCylinder(quadratic,  15.0,  15.0,  3,  20,  1);
		glTranslatef(0.f,0.f,3.f);
		gluDisk(quadratic,10.0,15.0,20,1);
		gluCylinder(quadratic,  13.0,  13.0,  3,  20,  1);
		glTranslatef(0.f,0.f,3.f);
		gluDisk(quadratic,0.0,13.0,20,1);
		glTranslatef(0.f,0.f,34.f);
		gluDisk(quadratic,0.0,rad,20,1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.f,40.f,0.f);
		glColor3f(.7,.7,.7);
		glRotatef(-90,1.f,0.f,0.f);
		drawDome(rad);
		glTranslatef(0.0,0.0,rad - 1.0);
		gluCylinder(quadratic,  1.0,  1.0,  18.0,  10,  1);

		//flag();
	glPopMatrix();
	glPushMatrix();
		glColor3f(.7,.7,.7);
		glRotatef(-90, 1.f, 0.f, 0.f); 
		glTranslatef(11.0,-11.0,0.0);
		gluCylinder(quadratic,  4.0,  4.0,  40,  20,  5);
		glTranslatef(0.0,22.0,0.0);
		gluCylinder(quadratic,  4.0,  4.0,  40,  20,  5);

		glTranslatef(-18.0,28.0,0.0);
		gluCylinder(quadratic,  4.0,  4.0,  40,  20,  5);
		glTranslatef(0.f,0.f,40.0);
		drawDome(4);
		glTranslatef(0.f,0.f,-40.0);

		glTranslatef(-33.0,0.0,0.0);
		gluCylinder(quadratic,  4.0,  4.0,  40,  20,  5);
		glTranslatef(0.f,0.f,40.0);
		drawDome(4);
		glTranslatef(0.f,0.f,-40.0);

		glTranslatef(0.0,-78.0,0.0);
		gluCylinder(quadratic,  4.0,  4.0,  40,  20,  5);
		glTranslatef(0.f,0.f,40.0);
		drawDome(4);
		glTranslatef(0.f,0.f,-40.0);

		glTranslatef(33.0,0.0,0.0);
		gluCylinder(quadratic,  4.0,  4.0,  40,  20,  5);
		glTranslatef(0.f,0.f,40.0);
		drawDome(4);
		glTranslatef(0.f,0.f,-40.0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-7.0,15.0,-25.0);
		window();
		glTranslatef(0.0,15.0,0.0);
		window();
		glTranslatef(0.0,0.0,17.0);
		window();
		glTranslatef(0.0,0.0,16.0);
		window();
		glTranslatef(0.0,0.0,17.0);
		window();
		glTranslatef(0.0,-15.0,0.0);
		window();
	glPopMatrix();
	glPushMatrix();
		glRotatef(180,0.f,1.f,0.f);
		glTranslatef(40.0,15.0,-25.0);
		window();
		glTranslatef(0.0,0.0,17.0);
		window();
		glTranslatef(0.0,0.0,16.0);
		window();
		glTranslatef(0.0,-0.0,17.0);
		window();
		glTranslatef(0.0,15.0,0.0);
		window();
		glTranslatef(0.0,0.0,-17.0);
		window();
		glTranslatef(0.0,0.0,-16.0);
		window();
		glTranslatef(0.0,0.0,-17.0);
		window();
	glPopMatrix();
	float door [3][9] = {	{-7.0,6.0,-5.0,-6.0,21.0,-4.0,1.f,1.f,1.f},
							{-7.0,6.0,5.0,-6.0,21.0,4.0,1.f,1.f,1.f},
							{-7.0,20.0,-4.0,-6.0,21.0,4.0,1.f,1.f,1.f}
	};
    float mainBox [9] = {-7,0,-39,-40,40,39,.7,.1,.1};
    cube(mainBox);
    for(int i = 0; i < 3; i++)
    	cube(door[i]);
    glBegin(GL_TRIANGLES);
    	glColor3f(0.f,0.f,0.f);
    	glVertex3f(-6.5,21.0,-4.0);
    	glVertex3f(-6.5,21.0,4.0);
    	glVertex3f(-6.5,6.0,-4.0);
    	glVertex3f(-6.5,6.0,-4.0);
    	glVertex3f(-6.5,21.0,4.0);
    	glVertex3f(-6.5,6.0,4.0);
    glEnd();
}

void store2(float r, float g, float b){
	float x [5] = {-17.0,-14.0,-8.0,-5.0,-4.0};
	float y [7] = {0.0,13.0,14.0,16.0,22.0,30.0,40.0};
	float z[4] = {17.0,12.0,11.0,-15.0};

	float mainbl [9] = {x[0],y[0],z[2],-x[0],y[6],z[3],r,g,b};
	float door [3][9] = {	{x[3],y[0],z[2],x[4],y[2],z[2]+1,1.f,1.f,1.f},
							{-x[3],y[0],z[2],-x[4],y[2],z[2]+1,1.f,1.f,1.f},
							{-x[3],y[1],z[2],x[3],y[2],z[2]+1,1.f,1.f,1.f},
	};
	cube(mainbl);
	for (int i = 0; i<3;i++)
		cube(door[i]);

	glColor3f(0.f,0.f,0.f);
	glBegin(GL_TRIANGLES);
		glVertex3f(x[4],y[1],z[2]+.5);
		glVertex3f(-x[4],y[1],z[2]+.5);
		glVertex3f(x[4],y[0],z[2]+.5);
		glVertex3f(-x[4],y[1],z[2]+.5);
		glVertex3f(x[4],y[0],z[2]+.5);
		glVertex3f(-x[4],y[0],z[2]+.5);

	glEnd();

	glPushMatrix();
		glColor3f(.4,.4,.4);
		GLUquadricObj *quadratic;
	 	quadratic = gluNewQuadric();
	 	glTranslatef(-13.0,y[6],2.0);
	 	glRotatef(-90, 1.f, 0.f, 0.f); 	
		gluCylinder(quadratic,  1.5,  1.5,  6,  10,  2);
		glTranslatef(0.f,0.f,6.f);
		gluCylinder(quadratic,  2.7,  0.0,  3,  10,  2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(x[2],y[5],z[2]);
		glRotatef(-90,0.f,1.f,0.f);
		window();
		glTranslatef(0.f,0.f,-16.0);
		window();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-x[0],20.f,0.f);
		window();
	glPopMatrix();

	glBegin(GL_TRIANGLES);
		glColor3f(0.f,0.f,1.f);
		glVertex3f(x[1],y[4],z[2]);
		glVertex3f(x[1],y[3],z[0]);
		glVertex3f(x[1],y[3],z[2]);
		glVertex3f(x[1],y[3],z[2]);
		glVertex3f(x[1],y[4],z[2]);
		glVertex3f(x[1],y[3],z[0]);
		
		glVertex3f(-x[1],y[4],z[2]);
		glVertex3f(-x[1],y[3],z[0]);
		glVertex3f(-x[1],y[3],z[2]);
		glVertex3f(-x[1],y[3],z[2]);
		glVertex3f(-x[1],y[4],z[2]);
		glVertex3f(-x[1],y[3],z[0]);
	glEnd();

	for(int i = 0; i < 7; i++){
		(i % 2) == 0 ? glColor3f(0.f,0.f,1.f) : glColor3f(1.f,1.f,0.f);

		glBegin(GL_TRIANGLES);
			glVertex3f(x[1],y[4],z[2]);
			glVertex3f(x[1] + 4.0,y[4],z[2]);
			glVertex3f(x[1],y[3],z[0]);
			glVertex3f(x[1],y[3],z[0]);
			glVertex3f(x[1] + 4.0,y[4],z[2]);
			glVertex3f(x[1] + 4.0,y[3],z[0]);

			
			glVertex3f(x[1] + 4.0,y[4],z[2]);
			glVertex3f(x[1],y[4],z[2]);
			glVertex3f(x[1],y[3],z[0]);	
			glVertex3f(x[1] + 4.0,y[4],z[2]);
			glVertex3f(x[1],y[3],z[0]);
			glVertex3f(x[1] + 4.0,y[3],z[0]);
		glEnd();

		glTranslatef(x[1] + 2.0,y[3],z[0]);
		semicircle(2.0);
		glTranslatef(-x[1] - 2.0,-y[3],-z[0]);
		x[1] += 4.0;
	}

}

void semicircle(float rad){
	float step = 20.0;
	float x,y,nx,ny;

	glBegin(GL_TRIANGLES);
	for(float angle = 0.0f ;angle < 180; angle += step)
	{
	   float r  = (PI/180) * angle;
	   x  = rad*cos(r);
	   y  = -rad*sin(r);
	   nx = rad*cos(r + (PI/180)*step);
	   ny = -rad*sin(r + (PI/180)*step);
	   glVertex3f(0.f,0.f,0.f);
	   glVertex3f(x,y,0.f);
	   glVertex3f(nx,ny,0.f);
	   glVertex3f(x,y,0.f);
	   glVertex3f(0.f,0.f,0.f);
	   glVertex3f(nx,ny,0.f);

	}
	glEnd();
}

void ufo(){
	float rad = 28.0;
	float innerRad = 6.0;
	float binnerRad = 4.0;

	glPushMatrix();
		glColor3f(.64,.64,.64);
		glBegin(GL_QUADS);
		float ux,lx;
		int i,j;
		for(i = 0; i < 360; i += 9){
				ux = i * (PI / 180);
				lx = (i + 9) * (PI / 180);
				glNormal3f(.225*cos(ux),.975,.225*sin(lx));
				glVertex3f(rad*cos(ux),2.0,rad*sin(ux));
				glVertex3f(rad*cos(lx),2.0,rad*sin(lx));
				glVertex3f(innerRad*cos(lx),7.0,innerRad*sin(lx));
				glVertex3f(innerRad*cos(ux),7.0,innerRad*sin(ux));

				glNormal3f(.707*cos(ux),-.707,.707*sin(lx));
				glVertex3f(rad*cos(ux),2.0,rad*sin(ux));
				glVertex3f(rad*cos(lx),2.0,rad*sin(lx));
				glVertex3f((rad-2)*cos(lx),0.f,(rad-2)*sin(lx));
				glVertex3f((rad-2)*cos(ux),0.f,(rad-2)*sin(ux));

				glNormal3f(.99*cos(ux),-.135,.99*sin(lx));
				glVertex3f((rad-2)*cos(ux),0.f,(rad-2)*sin(ux));
				glVertex3f((rad-2)*cos(lx),0.f,(rad-2)*sin(lx));
				glVertex3f(binnerRad*cos(lx),-3.f,binnerRad*sin(lx));
				glVertex3f(binnerRad*cos(ux),-3.f,binnerRad*sin(ux));
			
		}
		glEnd();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.f,7.0,0.f);
		glRotatef(-90,1.f,0.f,0.f);
		glColor3f(0.f,1.f,0.f);
		drawDome(6.0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.f,-3.f,0.f);
		glRotatef(90,1.f,0.f,0.f);
		glColor3f(1.f,1.f,0.f);
		GLUquadricObj *quadratic;
	 	quadratic = gluNewQuadric();
	 	gluDisk(quadratic,0.f,4.0,40,1);
	glPopMatrix();	
}

void house2(float r, float g, float b, float rr, float rg, float rb){
	int i;

	float main [4][9] = {	{-18.0,0.0,-1.0,22.0,17.0,-15.0,r,g,b},
							{-18.0,0.0,15.0,-15.0,17.0,-1.0,r,g,b},
							{5.0,0.0,15.0,8.0,17.0,-1.0,r,g,b},
							{-18.0,17.0,15.0,8.0,36.0,-15.0,r,g,b}
	};
	for(i = 0; i<4; i++)
		cube(main[i]);

	float door [3][9] = {	{10.f,0.f,0.f,12.f,14.f,-1.f,1.f,1.f,1.f},
							{18.f,0.f,0.f,20.f,14.f,-1.f,1.f,1.f,1.f},
							{12.f,12.f,0.f,18.f,14.f,-1.f,1.f,1.f,1.f}
	};
	for(i=0;i<3;i++)
		cube(door[i]);

	glBegin(GL_TRIANGLES);
		glColor3f(r,g,b);
		glVertex3f(8.f,22.f,-15.f);
		glVertex3f(8.f,17.f,-15.f);
		glVertex3f(22.f,17.f,-15.f);

		glVertex3f(8.f,22.f,-1.f);
		glVertex3f(8.f,17.f,-1.f);
		glVertex3f(22.f,17.f,-1.f);

		glVertex3f(-18.f,36.f,15.f);
		glVertex3f(8.f,36.f,15.f);
		glVertex3f(-5.f,42.f,15.f);

		glVertex3f(-18.f,36.f,-15.f);
		glVertex3f(8.f,36.f,-15.f);
		glVertex3f(-5.f,42.f,-15.f);

	glEnd();

	glBegin(GL_QUADS);
		glColor3f(.8,.8,.8);
		glNormal3f(0.f,0.f,1.f);
		glVertex3f(-15.f,17.f,14.f);
		glVertex3f(5.f,17.f,14.f);
		glVertex3f(5.f,0.f,14.f);
		glVertex3f(-15.f,0.f,14.f);

		glColor3f(rr,rg,rb);
		glNormal3f(.42,.9,0.f);
		glVertex3f(8.f,36.f,16.f);
		glVertex3f(8.f,36.f,-16.f);
		glVertex3f(-5.f,42.f,-16.f);
		glVertex3f(-5.f,42.f,16.f);

		glNormal3f(-.42,.9,0.f);
		glVertex3f(-18.f,36.f,16.f);
		glVertex3f(-18.f,36.f,-16.f);
		glVertex3f(-5.f,42.f,-16.f);
		glVertex3f(-5.f,42.f,16.f);

		glNormal3f(.34,.94,0.f);
		glVertex3f(8.f,22.f,0.f);
		glVertex3f(8.f,22.f,-16.f);
		glVertex3f(22.f,17.f,-16.f);
		glVertex3f(22.f,17.f,0.f);

		glColor3f(0.f,0.f,0.f);
		glNormal3f(0.f,0.f,1.f);
		glVertex3f(12.f,12.f,-.5);
		glVertex3f(18.f,12.f,-.5);
		glVertex3f(18.f,0.f,-.5);
		glVertex3f(12.f,0.f,-.5);
	glEnd();

	glPushMatrix();
		glTranslatef(-11.5,27.0,15.0);
		glRotatef(-90,0.f,1.f,0.f);
		window();
		glTranslatef(0.f,0.f,-13.f);
		window();
	glPopMatrix();
}

void window(){
	float window [5][9] = {	{-1,-5,-5,1,6,-4,1.f,1.f,1.f},
							{-1,-5,4,1,6,5,1.f,1.f,1.f},
							{-1,-5,-4,1,-4,4,1.f,1.f,1.f},
							{-1,0,-4,1,1,4,1.f,1.f,1.f},
							{-1,5,-4,1,6,4,1.f,1.f,1.f},
	};
	for(int i = 0; i < 5; i++){
		cube(window[i]);
	}
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLES);
		glVertex3f(.5,5.0,-4.0);
		glVertex3f(.5,5.0,4.0);
		glVertex3f(.5,-4.0,-4.0);
		glVertex3f(.5,-4.0,-4.0);
		glVertex3f(.5,5.0,4.0);
		glVertex3f(.5,-4.0,4.0);
	glEnd();
}

void drawDome(int rad){
	glPushMatrix();
	
		glBegin(GL_QUADS);
		float ux,lx,uy,ly;
		int i,j;
		for(i = 0; i < 360; i += 18){
			for (j = 0; j < 90; j += 18)
			{	
				ux = i * (PI / 180);
				lx = (i + 18) * (PI / 180);
				uy = j * (PI / 180);
				ly = (j + 18) * (PI / 180);
				glNormal3f(cos(ux)*cos(uy),cos(ux)*sin(uy),sin(uy));
				glVertex3f(rad*cos(ux)*sin(ly),rad*sin(ux)*sin(ly),rad*cos(ly));
				glVertex3f(rad*cos(lx)*sin(ly),rad*sin(lx)*sin(ly),rad*cos(ly));
				glVertex3f(rad*cos(lx)*sin(uy),rad*sin(lx)*sin(uy),rad*cos(uy));
				glVertex3f(rad*cos(ux)*sin(uy),rad*sin(ux)*sin(uy),rad*cos(uy));
			}
		}
		glEnd();
	glPopMatrix();
}
	
GLuint loadShader(const char* vertexFileName, const char* fragmentFileName)
{
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vs, 1, (const GLchar**)&vertexFileName, NULL);
	glCompileShader(vs);
	GLuint vs_program = glCreateProgram();
	glAttachShader(vs_program, vs);
	glProgramParameteri(vs_program, GL_PROGRAM_SEPARABLE, GL_TRUE);
	glLinkProgram(vs_program);

	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fs, 1, (const GLchar**)&fragmentFileName, NULL);
	glCompileShader(fs);
	GLuint fs_program = glCreateProgram();
	glAttachShader(fs_program, fs);
	glProgramParameteri(fs_program, GL_PROGRAM_SEPARABLE, GL_TRUE);
	glLinkProgram(fs_program);

	GLuint program_pipeline;
	glGenProgramPipelines(1, &program_pipeline);
	glUseProgramStages(program_pipeline, GL_VERTEX_SHADER_BIT, vs_program);
	glUseProgramStages(program_pipeline, GL_FRAGMENT_SHADER_BIT, fs_program);
}
