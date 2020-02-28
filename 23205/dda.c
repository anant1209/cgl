#include <GL/freeglut.h>
#include <GL/gl.h>
#include<math.h>
#include<iostream>
using namespace std;

int xi,yi,xf,yf;
void plot(int x,int y);
void dda_line(int x,int y,int x1,int y1);

void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.075);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(-300,300,-300,300);//(x1,x2,y1,y2)
    
    dda_line(-300,0,300,0);//x ax1s
    
    dda_line(0,-300,0,300);//y ax1s
        
      
    
    /*dda_line(200,200,200,-200);
    dda_line(200,200,-200,200);
    dda_line(-200,200,-200,-200);
    dda_line(-200,-200,200,-200);	//outer square
    
  
    dda_line(200,0,0,200);
    dda_line(0,-200,200,0);
    dda_line(-200,0,0,200);
    dda_line(-200,0,0,-200);	// inner diamond
    

    dda_line(100,100,100,-100);
    dda_line(100,100,-100,100);
    dda_line(-100,100,-100,-100);
    dda_line(-100,-100,100,-100);*/	//inner square
    
          glColor3f(0, 1.0, 1.0);//blue
        
     dda_line(xi,yi,xf,yi);
     dda_line(xf,yi,xf,yf);
     dda_line(xi,yf,xf,yf);
     dda_line(xi,yi,xi,yf);
    
      glColor3f(1.0, 0.0, 1.0);//purple
     dda_line((xf+xi)/2,yi,xf,(yf+yi)/2);
     dda_line(xf,(yf+yi)/2,(xf+xi)/2,yf);
     dda_line((xf+xi)/2,yf,xi,(yf+yi)/2);
     dda_line(xi,(yf+yi)/2,(xf+xi)/2,yi);
   
   glColor3f(1.0, 1.0, 0);//yellow
     dda_line((3*xi+xf)/4,(3*yi+yf)/4,(3*xf+xi)/4,(3*yi+yf)/4);
     dda_line((3*xf+xi)/4,(3*yi+yf)/4,(3*xf+xi)/4,(yi+3*yf)/4);
     dda_line((3*xf+xi)/4,(yi+3*yf)/4,(xf+3*xi)/4,(yi+3*yf)/4);
    dda_line((xf+3*xi)/4,(yi+3*yf)/4,(xf+3*xi)/4,(3*yi+yf)/4);  
     
    glFlush();
}

void plot(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();	
	  glFlush();	
}

void dda_line(int x,int y,int x1,int y1)
{
	float dx,dy,x_inc,y_inc;
	int steps;
	
	dx=x1-x;//dx=x1-x;
	dy=y1-y;//dy=y1-y;
	
	if( abs(dx)>abs(dy) )
		steps=abs(dx);
	else
		steps=abs(dy);
		
	x_inc=(float)dx/steps;
	y_inc=(float)dy/steps;
	
	plot(x,y);
	
	for(int i=0;i<steps;i++)
		{
			x+=x_inc;
			y+=y_inc;
			
			plot( round(x),round(y) );
		}	
				
}
int main(int argc, char** argv)
{	
    glutInit(&argc, argv);
    cout<<"ENTER THE INITIAL CO-ORDINATES(X,Y)\n";         //INPUT
	cin>>xi>>yi;
	
	cout<<"ENTER THE FINAL CO-ORDINATES(X,Y)\n";         //INPUT
	cin>>xf>>yf;
	
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DDA");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
