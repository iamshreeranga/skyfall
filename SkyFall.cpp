#include<stdlib.h>
#include<gl/glut.h>
#include<stdio.h>
#include<time.h>
char name[25];
int ey1=660;
int temp1=30;
int by1=20;
int bx1;
int wflag=1;
int goflag=0;
int score=0;
char scs[20];
int basva=0;
time_t seconds;
int a[]={50,100,200,300,400,500,550,15,250,600};
void renderBitmapString(float x,float y,float z,void *font,char *string)
{
char *c;
glRasterPos3f(x,y,z);
for(c=string; *c != '\0'; c++)
	glutBitmapCharacter(font, *c);
}

void renderStrokeString(float x,float y,float z,void *font,char *string)
{
char *c;
glTranslatef(x,y,z);
glScalef(0.5,0.5,0);
for(c=string; *c != '\0'; c++)
	glutStrokeCharacter(font, *c);
}

void start_disp(void)
{
glClearColor(0,0,0,1);
		glPushMatrix();
		glColor3f(0.5,1,0);
		
		renderStrokeString(170,570,0,GLUT_STROKE_ROMAN,"SKY FALL");
			
		glScalef(6,6,0);
		glPopMatrix();

	

		glColor3f(0.5,1.0,0.0);
			//renderBitmapString(220,600,0,GLUT_BITMAP_TIMES_ROMAN_24,"SKY FALL");
		glColor3f(01,1,1.0);
			renderBitmapString(350,540,0,GLUT_BITMAP_HELVETICA_12,"-CATCH FROM THE SKY");
		glColor3f(0.79,0.5,0.2);
			renderBitmapString(200,410,0,GLUT_BITMAP_HELVETICA_18,"Welcome:");
		glColor3f(0.0,0.5,0.9);
			renderBitmapString(320,410,0,GLUT_BITMAP_TIMES_ROMAN_24,name);
		glColor3f(1.0,0.0,0.0);
			renderBitmapString(150,350,0,GLUT_BITMAP_9_BY_15,"PRESS UPPER ARROW KEY TO START THE GAME");

		glColor3f(0.82,0.5,0.46);
			renderBitmapString(50,250,0,GLUT_BITMAP_HELVETICA_18,"Under The Guidence of :");
			renderBitmapString(50,249,0,GLUT_BITMAP_HELVETICA_10,"________________________________");
		glColor3f(0.85,0.53,0.10);
			renderBitmapString(50,200,0,GLUT_BITMAP_TIMES_ROMAN_24,"SANJAY D S");

		glColor3f(0.65,0.50,0.39);
			renderBitmapString(450,250,0,GLUT_BITMAP_HELVETICA_18,"Project by :");
			renderBitmapString(450,249,0,GLUT_BITMAP_HELVETICA_10,"________________");
		glColor3f(0.92,0.78,0.62);
			renderBitmapString(450,200,0,GLUT_BITMAP_TIMES_ROMAN_24,"Shreeranga");
			renderBitmapString(450,160,0,GLUT_BITMAP_9_BY_15,"(4AI12CS096)");
			renderBitmapString(450,120,0,GLUT_BITMAP_TIMES_ROMAN_24,"Shesha Chandrika");
			renderBitmapString(450,80,0,GLUT_BITMAP_9_BY_15,"(4AI12CS093)");


	glutSwapBuffers();
	glFlush();
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0.196078,0.6,0.8,1);

	if(wflag==1)												//Initial Window Screen "SKYFALL"
		{
			start_disp();
		}
else if(wflag==0)												//Playing window screen
{

	
	glColor3f(0.0,1.0,0.0);
	sprintf(scs,"%d",score);
	
renderBitmapString(600,558,0,GLUT_BITMAP_TIMES_ROMAN_24,scs);
    glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(temp1,ey1,0.0);
	if(basva==0)
	glutSolidSphere(5.0,20,20);									//egg
    glPopMatrix();
	
	glColor3f(.18,.30,.18);
	glPushMatrix();
	glRectf(bx1,0,bx1+80,20);                                  //below bar
    glPopMatrix();
	
	

if(goflag==1)												//result screen
{
	glClearColor(0,1,0,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glColor3f(0.1,0.25,0);

renderBitmapString(270,400,0,GLUT_BITMAP_HELVETICA_18,"GAME OVER!!!");
renderBitmapString(250,200,0,GLUT_BITMAP_TIMES_ROMAN_24,"close the window to exit");
renderBitmapString(250,170,0,GLUT_BITMAP_TIMES_ROMAN_24,"(or right click and exit)");
basva=1;
glColor3f(1.0,1.0,1.0);
renderBitmapString(250,358,0,GLUT_BITMAP_TIMES_ROMAN_24,"You Scored");
//renderBitmapString(200,358,0,GLUT_BITMAP_TIMES_ROMAN_24,"scored:");
sprintf(scs,"%d",score);
renderBitmapString(400,358,0,GLUT_BITMAP_TIMES_ROMAN_24,scs);

}
glutSwapBuffers();
	}

}



void fall(int c)
{	
	
{
	if(ey1>15)       //speed ge
	{
		
	ey1=ey1-4;
	
	}
	else
	{
		if(temp1>=bx1 && temp1<=bx1+80)  //If ball is caught by below bar
		{
		time(&seconds);
	 srand((unsigned int) seconds);
	 
		temp1=a[rand()%5];
		ey1=700;
		score=score+10;
			
		}
		else                              //couldn't catch
		goflag=1;

	}
}

	glutTimerFunc(10,fall,c+50);
		glutPostRedisplay();
}


void mykey(int key,int x,int y)
{
	switch(key)
	{
	
	case GLUT_KEY_RIGHT:if(basva==0)
		if(bx1<700)
		{
			bx1=bx1+20;
		}
		
			break;
	case GLUT_KEY_LEFT:if(basva==0)
			if(bx1>0)
			{
				bx1=bx1-20;
			}
			
			break;

case GLUT_KEY_UP:
		ey1=700;
		goflag=0;
			wflag=0;
			
	}
	glutPostRedisplay();
}
void myinit()
{
	
		glMatrixMode(GL_PROJECTION);
		glShadeModel (GL_SMOOTH);
		glLoadIdentity();
		glOrtho(0,700,0,700,-20,20);
		glEnable(GL_DEPTH_TEST);
		glMatrixMode(GL_MODELVIEW);
}

void mymenu(int ch)
{
	switch(ch)
	{
	case 1: exit(0);
		break;
	}
	glutPostRedisplay();

}

void main(int argc, char ** argv)
{
    printf("\n enter your name:");
    scanf("%s",name);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowPosition(450,50);
	glutInitWindowSize(600,600);
	glutCreateWindow("Catch the fall");
	glutDisplayFunc(display);
	glutSpecialFunc(mykey);
	glutCreateMenu(mymenu);
	glutAddMenuEntry("Quit",1);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glEnable(GL_DEPTH_TEST);
	glutTimerFunc(10,fall,600);
	myinit();
	glutMainLoop();
}
