#include <GL/freeglut.h>
#include <GL/gl.h>
#include<math.h>
#include<iostream>
using namespace std;

void plot(int x,int y);
int abs (int n) ;
void brezen_circle(int r);
void dda(int X0, int Y0, int X1, int Y1) ;


int abs (int n) 
{ 
    return ( (n>0) ? n : ( n * (-1))); 
} 
  

void dda(int X0, int Y0, int X1, int Y1) 
{ 
    
    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
  
    
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
 
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
     
    float X = X0; 
    float Y = Y0; 
    for (int i = 0; i <= steps; i++) 
    { 
       plot(X,Y); 
        X += Xinc;       
        Y += Yinc;         
                  
    } 
} 

void plot(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();	
	   glFlush();	
}

void brezen_circle(int r,int xc,int yc)
{
	int x,y;
	x=0;y=r;
	int d=3-2*r;
		plot(xc,yc+r);
		plot(xc,yc-r);
		plot(xc,yc);
		plot(xc-r,yc);
	while(x<=y)
	{
		if(d<=0)
			{
				x+=1;
				plot(xc+x,yc+y);
				plot(xc+y,yc+x);
				plot(xc+y,yc+-x);
				plot(xc+x,yc+-y);
				plot(xc+-x,yc+-y);
				plot(xc+-y,yc+-x);
				plot(xc+-y,yc+x);
				plot(xc+-x,yc+y);
				
				
				d=d+4*x+6;
			}
			
		else
			{
				x+=1;
				y-=1;
				plot(xc+x,yc+y);
				plot(xc+y,yc+x);
				plot(xc+y,yc+-x);
				plot(xc+x,yc+-y);
				plot(xc+-x,yc+-y);
				plot(xc+-y,yc+-x);
				plot(xc+-y,yc+x);
				plot(xc+-x,yc+y);
				d+=4*(x-y)+10;
			}	
	}
}


void semi_brezen_circle(int r,int xc,int yc)
{
	int x,y;
	x=0;y=r;
	int d=3-2*r;
       // plot(xc,yc+r);
		plot(xc,yc-r);
		plot(xc,yc);
		plot(xc-r,yc);
	while(x<=y)
	{
		if(d<=0)
			{
				x+=1;
				//plot(xc+x,yc+y);
				//plot(xc+y,yc+x);
				plot(xc+y,yc+-x);
				plot(xc+x,yc+-y);
				plot(xc+-x,yc+-y);
				plot(xc+-y,yc+-x);
			//	plot(xc+-y,yc+x);
				//plot(xc+-x,yc+y);
				
				
				d=d+4*x+6;
			}
			
		else
			{
				x+=1;
				y-=1;
				//plot(xc+x,yc+y);
				//plot(xc+y,yc+x);
				plot(xc+y,yc+-x);
				plot(xc+x,yc+-y);
				plot(xc+-x,yc+-y);
				plot(xc+-y,yc+-x);
				//plot(xc+-y,yc+x);
				//plot(xc+-x,yc+y);
				d+=4*(x-y)+10;
			}	
	}
}



void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.075);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(-300,300,-300,300);
    	
    	
		glColor3f(1.0, 1.0, 0.0);//face
		brezen_circle(150,0,150);
		
		glColor3f(1.0, 1.0, 0.0);//eye1
		brezen_circle(40,-40,260);
		
		glColor3f(1.0, 1.0, 0.0);//eye2
		brezen_circle(40,40,260);
		
		glColor3f(1.0, 1.0, 0.0);//nose
		brezen_circle(20,0,220);
		
		
		
        glFlush();
}


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("CIRCLE");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
	
	return 0;
}


