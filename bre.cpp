#include<iostream>
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
using namespace std;
  
float a1, b1, a2, b2;  

template <typename T> int sgn(T val) {

    return (T(0) < val) - (val < T(0));
}	
  
// function to initialize 
void myInit (void) 
{ 
    // making background color black as first  
    // 3 arguments all are 0.0 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
      
    // breadth of picture boundary is 1 pixel 
    glPointSize(1.0); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
      
    // setting window dimension in X- and Y- direction 
    gluOrtho2D(-400, 400, -400, 400); 
} 

void plot(float x, float y)
{
	glBegin(GL_POINTS);
		glVertex2i(x, y); 
	glEnd();
}

void bre(float x1, float y1, float x2, float y2)
{
	float x, y, dx, dy, s1, s2, temp, sw, n, p;
	
	x = x1;
	y = y1;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	s1 = sgn(x2 - x1);
	s2 = sgn(y2 - y1);
	
	if(dy > dx)
	{
		temp = dx;
		dx = dy;
		dy = temp;
		sw = 1;
	}
	else
	{
		sw = 0;
	}
	
	n = 1;
	p = 2*dy - dx;
	
	plot(x, y);	
	
	while(n <= dx)
	{
		if(p >= 0)
		{
			x = x + s1;
			y = y + s2;
			p = p + 2*(dy - dx);
		}
		else if(sw == 1)
		{
			y = y + s2;
		}
		else
		{
			x = x + s1;
		}
		
		plot(x, y);
		n++;
	}
}


void display (void)  
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    
    glColor3f(132/255.0, 45/255.0, 231/255.0);
    bre(a1, b1, a1, b2);
    bre(a1, b2, a2, b2);
    bre(a2, b2, a2, b1);
    bre(a2, b1, a1, b1);
    
    glColor3f(42.0/255.0, 130/255.0, 220/255.0);
	bre((a1+a2)/2, b2, a2, (b1+b2)/2);
	bre(a2, (b2+b1)/2, (a2+a1)/2, b1);
	bre((a1+a2)/2, b1, a1, (b1+b2)/2);
	bre(a1, (b2+b1)/2, (a2+a1)/2, b2);
	
	glColor3f(231/255.0, 150/255.0, 19/255.0);
	bre((3*a2+a1)/4, (3*b2+b1)/4, (3*a2+a1)/4, (3*b1+b2)/4);
	bre((3*a2+a1)/4, (3*b1+b2)/4, (3*a1+a2)/4, (3*b1+b2)/4);
	bre((3*a1+a2)/4, (3*b1+b2)/4, (3*a1+a2)/4, (3*b2+b1)/4);
	bre((3*a1+a2)/4, (3*b2+b1)/4, (3*a2+a1)/4, (3*b2+b1)/4);
	
	glColor3f(125/255.0, 190/255.0, 59/255.0);
	bre(0, 420, 0, -420);
    bre(-780, 0, 780, 0);

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
