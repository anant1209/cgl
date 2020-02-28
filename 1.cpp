//DDA
//Roll No: 23214
//Batch: E10
//Problem Definition: To implement line drawing algorithm 

#include<iostream>
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
using namespace std;
  
float a1, b1, a2, b2;  
  
// function to initialize 
void myInit (void) 
{ 
    // making background color black as first  
    // 3 arguments all are 0.0 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
      
    // breadth of picture boundary is 1 pixel 
    glPointSize(2.0); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
      
    // setting window dimension in X- and Y- direction 
    gluOrtho2D(-100, 100, -100, 100); 
} 

void plot(float x, float y)
{
	glBegin(GL_POINTS);
		glVertex2i(x, y); 
	glEnd();
}

void DDA(float x1, float y1, float x2, float y2)
{
	float dx, dy, step, xin, yin, x, y, i, k;
	
	dx = x2 - x1;
	dy = y2 - y1; //gcc filename.c -lGL -lGLU -lglut y1;
	
	if(abs(dx) > abs(dy))
	{
		step = abs(dx);
	}
	else
	{
		step = abs(dy);
	}
	
	xin = dx/step;
	yin = dy/step;
	
	x = x1;
	y = y1;
	
	plot(x, y);
	
	for(i = 0; i < step; i++)
	{
	//	for(k = 0; k < step ; k++)
	//	{
	//	glColor3f((7*k)/255.0, (8*k)/255.0, k/255.0);
	//	}
		x += xin;
		y += yin;
		plot(x, y);	
	}
}

  
void display (void)  
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    
    glColor3f(132/255.0, 45/255.0, 231/255.0);
    DDA(a1, b1, a1, b2);
    DDA(a1, b2, a2, b2);
    DDA(a2, b2, a2, b1);
    DDA(a2, b1, a1, b1);
    
    glColor3f(42.0/255.0, 130/255.0, 200/255.0);
	DDA((a1+a2)/2, b2, a2, (b1+b2)/2);
	DDA(a2, (b2+b1)/2, (a2+a1)/2, b1);
	DDA((a1+a2)/2, b1, a1, (b1+b2)/2);
	DDA(a1, (b2+b1)/2, (a2+a1)/2, b2);
	
	glColor3f(231/255.0, 150/255.0, 69/255.0);
	DDA((3*a2+a1)/4, (3*b2+b1)/4, (3*a2+a1)/4, (3*b1+b2)/4);
	DDA((3*a2+a1)/4, (3*b1+b2)/4, (3*a1+a2)/4, (3*b1+b2)/4);
	DDA((3*a1+a2)/4, (3*b1+b2)/4, (3*a1+a2)/4, (3*b2+b1)/4);
	DDA((3*a1+a2)/4, (3*b2+b1)/4, (3*a2+a1)/4, (3*b2+b1)/4);
	
	glColor3f(250/255.0, 100/255.0, 159/255.0);//gcc filename.c -lGL -lGLU -lglut 
	DDA(0, 420, 0, -420);
    DDA(-780, 0, 780, 0);

    glFlush(); 
} 
  
int main (int argc, char** argv) 
{ 
	cout << "Enter X1 :";
	cin >> a1;
	cout << "Enter Y1 :";
	cin >> b1;
	cout << "Enter X2 :";
	cin >> a2;
	cout << "Enter Y2 :";
	cin >> b2;

    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
      
    // giving window size in X- and Y- direction 
    glutInitWindowSize(1366, 768); 
    glutInitWindowPosition(0, 0); 
      
    // Giving name to window 
    glutCreateWindow("Drawing"); 
    myInit(); 
      
    glutDisplayFunc(display); 
    glutMainLoop(); 
} 
