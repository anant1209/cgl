#include<iostream>
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
  
float a1, b1, a2, b2;  
  
// function to initialize 
void myInit (void) 
{ 
    // making background color black as first  
    // 3 arguments all are 0.0 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
      
    // making picture color green (in RGB mode), as middle argument is 1.0 
    glColor3f(0.0, 1.0, 0.0); 
      
    // breadth of picture boundary is 1 pixel 
    glPointSize(1.0); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
      
    // setting window dimension in X- and Y- direction 
    gluOrtho2D(-780, 780, -420, 420); 
} 

void plot(float x, float y)
{
	glBegin(GL_POINTS);
		glVertex2i(x, y); 
	glEnd();
}

void DDA(float x1, float y1, float x2, float y2)
{
	float dx, dy, step, xin, yin, x, y, i;
	
	dx = x2 - x1;
	dy = y2 - y1;
	
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
		x += xin;
		y += yin;
		plot(x, y);	
	}
}

  
void display (void)  
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    
    
    DDA(-100, -100, 100, -100);
    DDA(100, -100, 100, 100);
    DDA(100, 100, -100, 100);
    DDA(-100, 100, -100, -100);
    
    
    
    glFlush(); 
} 
  
int main (int argc, char** argv) 
{ 
	

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
