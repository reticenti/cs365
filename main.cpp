#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

//Global Variables
float dy = 0.0f;

bool changeShape = true;
bool simon = false;

int color = 0;
int green = 1;
int red = 2;
int blue = 3;
int yellow = 4;

vector<int> reelNum(3, 0);

int maxSpins = 40;
int numSpins = 0;

int timedelta = 20;



//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) 
   {
	switch (key) 
           {
		case 27: //Escape key
			exit(0);
	   }
   }

//Initializes 3D rendering
void initRendering() 
   {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL); //Enable color
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //background color
   }

//Called when the window is resized
void handleResize(int w, int h) 
   {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
   }

//Draws the 3D scene
void drawScene() 
   {
    int index;
    float offset;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective

    glTranslatef(0.0f, 0.0f, -5.0f); //Move forward 5 units	
    //glEnd();


    //
   glBegin(GL_LINES);
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex3f(-1.5, 0.0, 0.0f);				
      glVertex3f(1.5, 0.0, 0.0f);	
   glEnd();


    if(changeShape && numSpins <= maxSpins)
       {
        
        reelNum[0] = rand() % 128 + 1;    
        reelNum[1] = rand() % 128 + 1;  
        reelNum[2] = rand() % 128 + 1;  

        changeShape = false;
       }
    else if(numSpins > maxSpins)
       {
        dy = 0.0;
        simon = true;
       }

    //SHAPES
    for(index = 0; index < 3; index++)
    {
    offset = -0.9;
    offset = (float) index * 0.9 + offset;

    //J
    if(reelNum[index] <= 2)
    {
    glBegin(GL_QUADS);
       glColor3f(1.0f, 0.75f, 0.0f);
       glVertex3f(offset - 0.20f, dy + 0.25f, 0.0f);				
       glVertex3f(offset + 0.20f, dy + 0.25f, 0.0f);				
       glVertex3f(offset + 0.20f, dy + 0.2f, 0.0f);	
       glVertex3f(offset - 0.20f, dy + 0.2f, 0.0f);
	
       glVertex3f(offset - 0.05f, dy + 0.2f, 0.0f);				
       glVertex3f(offset + 0.05f, dy + 0.2f, 0.0f);				
       glVertex3f(offset + 0.05f, dy - 0.2f, 0.0f);	
       glVertex3f(offset - 0.05f, dy - 0.2f, 0.0f);	    

       glVertex3f(offset - 0.25f, dy - 0.2f, 0.0f);				
       glVertex3f(offset + 0.05f, dy - 0.2f, 0.0f);				
       glVertex3f(offset + 0.05f, dy - 0.25f, 0.0f);	
       glVertex3f(offset - 0.25f, dy - 0.25f, 0.0f);
	
       glVertex3f(offset - 0.25f, dy - 0.15f, 0.0f);				
       glVertex3f(offset - 0.175f, dy - 0.15f, 0.0f);				
       glVertex3f(offset - 0.175f, dy - 0.2f, 0.0f);	
       glVertex3f(offset - 0.25f, dy - 0.2f, 0.0f);
    glEnd();
    }

    //Plus
    else if(reelNum[index] >= 3 && reelNum[index] <= 7)
    {
    glBegin(GL_QUADS);
       glColor3f(1.0f, 0.0f, 0.0f);
       glVertex3f(offset - 0.10f, dy + 0.25f, 0.0f);				
       glVertex3f(offset + 0.10f, dy + 0.25f, 0.0f);				
       glVertex3f(offset + 0.10f, dy - 0.25f, 0.0f);	
       glVertex3f(offset - 0.10f, dy - 0.25f, 0.0f);
       glVertex3f(offset - 0.25f, dy + 0.1f, 0.0f);				
       glVertex3f(offset + 0.25f, dy + 0.1f, 0.0f);				
       glVertex3f(offset + 0.25f, dy - 0.1f, 0.0f);	
       glVertex3f(offset - 0.25f, dy - 0.1f, 0.0f);	    
    glEnd();
    }

    //Star
    else if(reelNum[index] >= 8 && reelNum[index] <= 15)
    {
    glBegin(GL_TRIANGLES);	
       glColor3f(0.75f, 0.75f, 0.75f);
       glVertex3f(offset + 0.0f, dy + 0.25f, 0.0f);				
       glVertex3f(offset - 0.25f, dy - 0.125f, 0.0f);				
       glVertex3f(offset + 0.25f, dy - 0.125f, 0.0f);
       glVertex3f(offset - 0.25f, dy + 0.125f, 0.0f);
       glVertex3f(offset + 0.25f, dy + 0.125f, 0.0f);  				
       glVertex3f(offset + 0.0f, dy - 0.25f, 0.0f);	
    glEnd();
    }

    //Diamond
    else if(reelNum[index] >= 16 && reelNum[index] <= 26)
    {
    glBegin(GL_TRIANGLES);	
       glColor3f(0.0f, 1.0f, 0.0f);
       glVertex3f(offset + 0.0f, dy + 0.25f, 0.0f);				
       glVertex3f(offset - 0.25f, dy + 0.0f, 0.0f);				
       glVertex3f(offset + 0.25f, dy + 0.0f, 0.0f);
       glVertex3f(offset - 0.25f, dy + 0.0f, 0.0f);
       glVertex3f(offset + 0.25f, dy + 0.0f, 0.0f);  				
       glVertex3f(offset + 0.0f, dy - 0.25f, 0.0f);	
    glEnd();
    }

    //Triangle
    else if(reelNum[index] >= 27 && reelNum[index] <= 39)
    {
    glBegin(GL_TRIANGLES);
       glColor3f(0.0f, 0.0f, 1.0f);
       glVertex3f(offset + 0.0f, dy + 0.25f, 0.0f);				
       glVertex3f(offset - 0.25f, dy + 0.0f, 0.0f);				
       glVertex3f(offset + 0.25f, dy + 0.0f, 0.0f);
    glEnd();
    }
   

    //Square
    else if(reelNum[index] >= 40 && reelNum[index] <= 55)
    {
    glBegin(GL_QUADS);
       glColor3f(1.0f, 1.0f, 0.0f); 
       glVertex3f(offset - 0.25f, dy + 0.25f, 0.0f);				
       glVertex3f(offset + 0.25f, dy + 0.25f, 0.0f);				
       glVertex3f(offset + 0.25f, dy - 0.25f, 0.0f);	
       glVertex3f(offset - 0.25f, dy - 0.25f, 0.0f);				 	
    glEnd();
    }

    //Bar (represents blank)
    else
    {
    glBegin(GL_QUADS);
       glColor3f(0.0f, 0.0f, 0.0f); 
       glVertex3f(offset - 0.20f, dy + 0.0125f, 0.0f);				
       glVertex3f(offset + 0.20f, dy + 0.0125f, 0.0f);				
       glVertex3f(offset + 0.20f, dy - 0.0125f, 0.0f);	
       glVertex3f(offset - 0.20f, dy - 0.0125f, 0.0f);				 	
    glEnd();
    }

    }
	
    //Outline of the reels
    glBegin(GL_QUADS);
      
       //Box containing left reel
       glColor3f(1.0f, 1.0f, 1.0f); 
       glVertex3f(-1.25, 1.1, 0.0f);				
       glVertex3f(-0.55, 1.1, 0.0f);				
       glVertex3f(-0.55, -1.1, 0.0f);	
       glVertex3f(-1.25f, -1.1f, 0.0f);	

       //Box containing center reel
       glColor3f(1.0f, 1.0f, 1.0f); 
       glVertex3f(-0.4, 1.1, 0.0f);				
       glVertex3f(0.35, 1.1, 0.0f);				
       glVertex3f(0.35, -1.1, 0.0f);	
       glVertex3f(-0.4f, -1.1f, 0.0f);	

       //Box containing right reel
       glColor3f(1.0f, 1.0f, 1.0f); 
       glVertex3f(0.55, 1.1, 0.0f);				
       glVertex3f(1.3, 1.1, 0.0f);				
       glVertex3f(1.3, -1.1, 0.0f);	
       glVertex3f(0.55f, -1.1f, 0.0f);
 
       //Box containing all reels
       glColor3f(0.35f, 0.35f, 0.35f); 
       glVertex3f(-1.5, 1.25, 0.0f);				
       glVertex3f(1.5, 1.25, 0.0f);				
       glVertex3f(1.5, -1.25, 0.0f);	
       glVertex3f(-1.5f, -1.25f, 0.0f);				 	
    glEnd();

    //After the reels have stopped
    if(simon)
       {
        timedelta = 500;

        glBegin(GL_QUADS);

//just a test
        if(color == 0)
           color = rand() % 4 + 1;
        else
          color = 0;

//end test portion

         //Top Left
           if (green == color)
               glColor3f(0.0f, 1.0f, 0.0f); 
           else
               glColor3f(1.0f, 1.0f, 1.0f); 

           glVertex3f(-1.75f, 1.5f, 0.0f);				
           glVertex3f(0.0f, 1.5f, 0.0f);				
           glVertex3f(0.0f, 1.25f, 0.0f);	
           glVertex3f(-1.75f, 1.25f, 0.0f);

           glVertex3f(-1.75f, 1.25f, 0.0f);				
           glVertex3f(-1.50f, 1.25f, 0.0f);				
           glVertex3f(-1.50f, 0.0f, 0.0f);	
           glVertex3f(-1.75f, 0.0f, 0.0f);
         
           //Top Right
           if (red == color)
               glColor3f(1.0f, 0.0f, 0.0f); 
           else
              glColor3f(1.0f, 1.0f, 1.0f); 

           glVertex3f(0.0f, 1.5f, 0.0f);				
           glVertex3f(1.75f, 1.5f, 0.0f);				
           glVertex3f(1.75f, 1.25f, 0.0f);	
           glVertex3f(0.0f, 1.25f, 0.0f);

           glVertex3f(1.50f, 1.25f, 0.0f);				
           glVertex3f(1.75f, 1.25f, 0.0f);				
           glVertex3f(1.75f, 0.0f, 0.0f);	
           glVertex3f(1.50f, 0.0f, 0.0f);
         
           //Bottom Right
           if (blue == color)
               glColor3f(0.0f, 0.0f, 1.0f); 
           else
              glColor3f(1.0f, 1.0f, 1.0f); 

           glVertex3f(0.0f, -1.25f, 0.0f);				
           glVertex3f(1.75f, -1.25f, 0.0f);				
           glVertex3f(1.75f, -1.5f, 0.0f);	
           glVertex3f(0.0f, -1.5f, 0.0f);

           glVertex3f(1.50f, 0.0f, 0.0f);				
           glVertex3f(1.75f, 0.0f, 0.0f);				
           glVertex3f(1.75f, -1.25f, 0.0f);	
           glVertex3f(1.50f, -1.25f, 0.0f);
         
           //Bottom Left
           if (yellow == color)
               glColor3f(1.0f, 1.0f, 0.0f); 
           else
               glColor3f(1.0f, 1.0f, 1.0f); 

           glVertex3f(-1.75f, -1.25f, 0.0f);				
           glVertex3f(0.0f, -1.25f, 0.0f);				
           glVertex3f(0.0f, -1.5f, 0.0f);	
           glVertex3f(-1.75f, -1.5f, 0.0f);

           glVertex3f(-1.75f, 0.0f, 0.0f);				
           glVertex3f(-1.50f, 0.0f, 0.0f);				
           glVertex3f(-1.50f, -1.25f, 0.0f);	
           glVertex3f(-1.75f, -1.25f, 0.0f);
          

        glEnd();
        
       }

    glutSwapBuffers();
   }



void update(int value) 
   {
        dy -= 0.10;
	if (dy < -0.8) 
           {
            dy = 0.8;
            changeShape = true;
            numSpins++;
           }
         
	glutPostRedisplay(); //Tell GLUT that the display has changed
	
	//Tell GLUT to call update again in X milliseconds
	glutTimerFunc(timedelta, update, 0);
 
   }

int main(int argc, char** argv) 
   {
        srand ( time(NULL) ); 

       	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	
	//Create the window
	glutCreateWindow("Simon Says Play the Slots!");
	initRendering();
	
	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	
	glutTimerFunc(timedelta, update, 0); //Add a timer
	
	glutMainLoop();
	return 0;
   }









