#include <GL/freeglut.h>
#include <GL/gl.h>
#include<stdio.h>
#include<math.h>
void renderFunction();
void Brezenham(float x1,float y1,float x2,float y2);
void plot(int x,int y);
float xi,yi,xf,yf;
void renderFunction()                                //FUNCTION TO RENDER THE FIGURE
{
	
	
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
   
    gluOrtho2D(0.0,640.0,0.0,480.0);
    Brezenham(0.0,240.0,640.0,240.0);
     Brezenham(320.0,0.0,320.0,480.0);
    glColor3f(0.0, 1.0, 1.0);
     Brezenham(xi,yi,xf,yi);
     Brezenham(xf,yi,xf,yf);
     Brezenham(xi,yf,xf,yf);
     Brezenham(xi,yi,xi,yf);
    glColor3f(1.0, 0.0, 1.0);
     Brezenham((xf+xi)/2,yi,xf,(yf+yi)/2);
     Brezenham(xf,(yf+yi)/2,(xf+xi)/2,yf);
     Brezenham((xf+xi)/2,yf,xi,(yf+yi)/2);
     Brezenham(xi,(yf+yi)/2,(xf+xi)/2,yi);
    glColor3f(1.0, 1.0, 0.0);
     Brezenham((3*xi+xf)/4,(3*yi+yf)/4,(3*xf+xi)/4,(3*yi+yf)/4);
     Brezenham((3*xf+xi)/4,(3*yi+yf)/4,(3*xf+xi)/4,(yi+3*yf)/4);
     Brezenham((3*xf+xi)/4,(yi+3*yf)/4,(xf+3*xi)/4,(yi+3*yf)/4);
    Brezenham((xf+3*xi)/4,(yi+3*yf)/4,(xf+3*xi)/4,(3*yi+yf)/4);    
    
}
void  Brezenham(float x1,float y1,float x2,float y2)
{
	
  
	int incx,incy,inc1,inc2,p,x,y;                    //INITIALIZATION
	float dy=y2-y1;
    float dx=x2-x1;
    if(dx<0)
    	dx=-dx;
    if(dy<0)
    	dy=-dy;
    incx=1;
    incy=1;
    if(x2<x1)                                        //IF FINAL CO-ORDINATE IS LESS THAN INITIAL THE INCREMENT ID NEGATIVE   
    	incx=-1;
    if(y2<y1)
    	incy=-1;
    x=x1;
    y=y1;
    if(dx>dy)                                         //TOTAL NUMBER OF STEPS IS DX IF IT IS GREATER THAN DY
    {
    	plot(x,y);
    	p=2*dy-dx;
    	inc1=2*(dy-dx);
    	inc2=2*dy;
    	for(int i=0;i<dx;i++)
    	{
    		if(p>0)
    		{
    			y+=incy;
    			p+=inc1;
    		}
    		else
    			p+=inc2;
    		x+=incx;
    		plot(x,y);
    	}
    }
    else	                                          //TOTAL NUMBER OF STEPS IS DY IF IT IS GREATER THAN DX
    {
	 	plot(x,y);
	 	p=2*dx-dy;
	 	inc1=2*(dx-dy);
	 	inc2=2*dx;
	 	for(int i=0;i<dy;i++)
	 	{
	 		if(p>0)
	 		{
				x+=incx;
				p+=inc1;
			}
			else
			{
				p+=inc2;
			}
			y+=incy;
			plot(x,y);
		}
	}
}
    

void plot(int x,int y)                                 //FUNCTION TO PLOT A POINT
{
	glBegin(GL_POINTS);
     	glVertex2i(x,y);
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
	    glutInit(&argc, argv);
	printf("ENTER THE INITIAL CO-ORDINATES(X,Y)\n");         //INPUT
	scanf("%f%f",&xi,&yi);
	printf("ENTER THE FINAL COORDINATESS(X,Y)\n");
	scanf("%f%f",&xf,&yf);
	xi+=320.0;
	yi+=240.0;
	xf+=320.0;
	yf+=240.0;
	printf("%f %f %f %f \n", xi,yi,xf,yf);
	

    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
