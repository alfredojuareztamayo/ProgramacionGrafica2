#include "Figures.h"
#include <GL/glut.h>
#include "Transformations.h"
#include "Rubik.h"

float rotationAngle = 0.0f;
float posX;
float posY;
float posZ;

void displayCube() {

    Translate vertices[] =
    {
        //1
         Translate (-1.0, -1.0, 1.0),
         Translate(-0.33, -1.0, 1.0),
         Translate(-0.33, -0.33, 1.0),
         Translate(-1.0,-0.33,1.0),
         //2
         Translate(-0.33, -1.0, 1.0),
         Translate(0.33, -1.0, 1.0),
         Translate(0.33, -0.33, 1.0),
         Translate(-0.33, -0.33, 1.0),
         //3
         Translate(1.0, 0.0, 0.0),
         Translate(0.33, -1.0, 1.0),
         Translate(1.0, -1.0, 1.0),
         Translate(1.0, -0.33, 1.0),
         Translate(0.33, -0.33, 1.0),
            //4
         Translate(-1.0, -0.33, 1.0),
         Translate(-0.33, -0.33, 1.0),
         Translate(-0.33, 0.33, 1.0),
         Translate(-1.0, 0.33, 1.0),
         //5
        
        Translate(-0.33, -0.33, 1.0),
        Translate(0.33, -0.33, 1.0),
        Translate(0.33, 0.33, 1.0),
        Translate(-0.33, 0.33, 1.0),
        //6
        Translate(0.33, -0.33, 1.0),
        Translate(1.0, -0.33, 1.0),
        Translate(1.0, 0.33, 1.0),
        Translate(0.33, 0.33, 1.0),
        //7
        Translate(-1.0, 0.33, 1.0),
        Translate(-0.33, 0.33, 1.0),
        Translate(-0.33, 1.0, 1.0),
        Translate(-1.0, 1.0, 1.0),

        // Cara frontal8.0
       
       Translate(-0.33, 0.33, 1.0),
       Translate(0.33, 0.33, 1.0),
       Translate(0.33, 1.0, 1.0),
       Translate(-0.33, 1.0, 1.0),
       // Cara frontal9.0
       
       Translate(0.33, 0.33, 1.0),
       Translate(1.0, 0.33, 1.0),
       Translate(1.0, 1.0, 1.0),
       Translate(0.33, 1.0, 1.0),

       // Cara Trasera
       
        Translate(-1.0, -1.0, -1.0),
        Translate(-0.33, -1.0, -1.0),
        Translate(-0.33, -0.33, -1.0),
        Translate(-1.0, -0.33, -1.0),

        // Cara Trasera2.0
     
         Translate(-0.33, -1.0, -1.0),
         Translate(0.33, -1.0, -1.0),
         Translate(0.33, -0.33, -1.0),
         Translate(-0.33, -0.33, -1.0),
             // Cara Trasera3.0
           
         Translate(0.33, -1.0, -1.0),
         Translate(1.0, -1.0, -1.0),
         Translate(1.0, -0.33, -1.0),
         Translate(0.33, -0.33, -1.0),
             // Cara Trasera4.0
            
         Translate(-1.0, -0.33, -1.0),
         Translate(-0.33, -0.33, -1.0),
         Translate(-0.33, 0.33, -1.0),
         Translate(-1.0, 0.33, -1.0),
             // Cara Trasera5.0
          
         Translate(-0.33, -0.33, -1.0),
         Translate(0.33, -0.33, -1.0),
         Translate(0.33, 0.33, -1.0),
         Translate(-0.33, 0.33, -1.0),
             // Cara Trasera6.0
  
         Translate(0.33, -0.33, -1.0),
         Translate(1.0, -0.33, -1.0),
         Translate(1.0, 0.33, -1.0),
         Translate(0.33, 0.33, -1.0),
             // Cara Trasera7.0
         
         Translate(-1.0, 0.33, -1.0),
         Translate(-0.33, 0.33, -1.0),
         Translate(-0.33, 1.0, -1.0),
         Translate(-1.0, 1.0, -1.0),
             // Cara Trasera8.0
            
         Translate(-0.33, 0.33, -1.0),
         Translate(0.33, 0.33, -1.0),
         Translate(0.33, 1.0, -1.0),
         Translate(-0.33, 1.0, -1.0),
        // Cara Trasera9.0
     
        Translate(0.33, 0.33, -1.0),
        Translate(1.0, 0.33, -1.0),
        Translate(1.0, 1.0, -1.0),
        Translate(0.33, 1.0, -1.0),

        // Cara LD
         
             Translate(1.0, -1.0, 1.0),
         Translate(1.0, -1.0, 0.33),
         Translate(1.0, -0.33, 0.33),
         Translate(1.0, -0.33, 1.0),

         // Cara LD 2.0
      
         Translate(1.0, -1.0, 0.33),
         Translate(1.0, -1.0, -0.33),
         Translate(1.0, -0.33, -0.33),
         Translate(1.0, -0.33, 0.33),
         // Cara LD 3.0
        
         Translate(1.0, -1.0, -0.33),
         Translate(1.0, -1.0, -1.0),
         Translate(1.0, -0.33, -1.0),
         Translate(1.0, -0.33, -0.33),
         // Cara LD 4.0
       
         Translate(1.0, -0.33, 1.0),
         Translate(1.0, -0.33, 0.33),
         Translate(1.0, 0.33, 0.33),
         Translate(1.0, 0.33, 1.0),
         // Cara LD 5.0
      
         Translate(1.0, -0.33, 0.33),
         Translate(1.0, -0.33, -0.33),
         Translate(1.0, 0.33, -0.33),
         Translate(1.0, 0.33, 0.33),
         // Cara LD 6.0
     
         Translate(1.0, -0.33, -0.33),
         Translate(1.0, -0.33, -1.0),
         Translate(1.0, 0.33, -1.0),
         Translate(1.0, 0.33, -0.33),
         // Cara LD 7.0

         Translate(1.0, 0.33, 1.0),
         Translate(1.0, 0.33, 0.33),
         Translate(1.0, 1.0, 0.33),
         Translate(1.0, 1.0, 1.0),
         // Cara LD 8.0
       
         Translate(1.0, 0.33, 0.33),
         Translate(1.0, 0.33, -0.33),
         Translate(1.0, 1.0, -0.33),
         Translate(1.0, 1.0, 0.33),
         // Cara LD 9.0

         Translate(1.0, 0.33, -0.33),
         Translate(1.0, 0.33, -1.0),
         Translate(1.0, 1.0, -1.0),
         Translate(1.0, 1.0, -0.33),


         //Cara LI

       // Cara LI
       
         Translate(-1.0, -1.0, 1.0),
         Translate(-1.0, -1.0, 0.33),
         Translate(-1.0, -0.33, 0.33),
         Translate(-1.0, -0.33, 1.0),

         // Cara LI 2.0

         Translate(-1.0, -1.0, 0.33),
         Translate(-1.0, -1.0, -0.33),
         Translate(-1.0, -0.33, -0.33),
         Translate(-1.0, -0.33, 0.33),
         // Cara LI 3.0

         Translate(-1.0, -1.0, -0.33),
         Translate(-1.0, -1.0, -1.0),
         Translate(-1.0, -0.33, -1.0),
         Translate(-1.0, -0.33, -0.33),
         // Cara LI 4.0
  
         Translate(-1.0, -0.33, 1.0),
         Translate(-1.0, -0.33, 0.33),
         Translate(-1.0, 0.33, 0.33),
         Translate(-1.0, 0.33, 1.0),
         // Cara LI 5.0
        
         Translate(-1.0, -0.33, 0.33),
         Translate(-1.0, -0.33, -0.33),
         Translate(-1.0, 0.33, -0.33),
         Translate(-1.0, 0.33, 0.33),
         // Cara LI 6.0

         Translate(-1.0, -0.33, -0.33),
         Translate(-1.0, -0.33, -1.0),
         Translate(-1.0, 0.33, -1.0),
         Translate(-1.0, 0.33, -0.33),
         // Cara LI 7.0

         Translate(-1.0, 0.33, 1.0),
         Translate(-1.0, 0.33, 0.33),
         Translate(-1.0, 1.0, 0.33),
         Translate(-1.0, 1.0, 1.0),
         // Cara LI 8.0
    
         Translate(-1.0, 0.33, 0.33),
         Translate(-1.0, 0.33, -0.33),
         Translate(-1.0, 1.0, -0.33),
         Translate(-1.0, 1.0, 0.33),
         // Cara LI 9.0
        
         Translate(-1.0, 0.33, -0.33),
         Translate(-1.0, 0.33, -1.0),
         Translate(-1.0, 1.0, -1.0),
         Translate(-1.0, 1.0, -0.33),

         //Cara TOP

      // Cara TOP
       
         Translate(-1.0, 1.0, 1.0),
         Translate(-0.33, 1.0, 1.0),
         Translate(-0.33, 1.0, 0.33),
         Translate(-1.0, 1.0, 0.33),

         // Cara TOP 2.0

         Translate(-0.33, 1.0, 1.0),
         Translate(0.33, 1.0, 1.0),
         Translate(0.33, 1.0, 0.33),
         Translate(-0.33, 1.0, 0.33),
         // Cara TOP 3.0
      
         Translate(0.33, 1.0, 1.0),
         Translate(1.0, 1.0, 1.0),
         Translate(1.0, 1.0, 0.33),
         Translate(0.33, 1.0, 0.33),
         // Cara TOP 4.0
         Translate(-1.0, 1.0, 0.33),
         Translate(-0.33, 1.0, 0.33),
         Translate(-0.33, 1.0, -0.33),
         Translate(-1.0, 1.0, -0.33),
         // Cara TOP 5.0
       
         Translate(-0.33, 1.0, 0.33),
         Translate(0.33, 1.0, 0.33),
         Translate(0.33, 1.0, -0.33),
         Translate(-0.33, 1.0, -0.33),
         // Cara TOP 6.0
      
         Translate(0.33, 1.0, 0.33),
         Translate(1.0, 1.0, 0.33),
         Translate(1.0, 1.0, -0.33),
         Translate(0.33, 1.0, -0.33),
         // Cara TOP 7.0

         Translate(-1.0, 1.0, -0.33),
         Translate(-0.33, 1.0, -0.33),
         Translate(-0.33, 1.0, -1.0),
         Translate(-1.0, 1.0, -1.0),
         // Cara TOP 8.0
     
         Translate(-0.33, 1.0, -0.33),
         Translate(0.33, 1.0, 0.33),
         Translate(0.33, 1.0, -1.0),
         Translate(-0.33, 1.0, -1.0),
         // Cara TOP 9.0
     
         Translate(0.33, 1.0, -0.33),
         Translate(1.0, 1.0, -0.33),
         Translate(1.0, 1.0, -1.0),
         Translate(0.33, 1.0, -1.0),


         //Cara Bot

     // Cara Bot

         Translate(-1.0, -1.0, 1.0),
         Translate(-0.33, -1.0, 1.0),
         Translate(-0.33, -1.0, 0.33),
         Translate(-1.0, -1.0, 0.33),

         // Cara Bot 2.0

         Translate(-0.33, -1.0, 1.0),
         Translate(0.33, -1.0, 1.0),
         Translate(0.33, -1.0, 0.33),
         Translate(-0.33, -1.0, 0.33),
         // Cara Bot 3.0

         Translate(0.33, -1.0, 1.0),
         Translate(1.0, -1.0, 1.0),
         Translate(1.0, -1.0, 0.33),
         Translate(0.33, -1.0, 0.33),
         // Cara Bot 4.0
      
         Translate(-1.0, -1.0, 0.33),
         Translate(-0.33, -1.0, 0.33),
         Translate(-0.33, -1.0, -0.33),
         Translate(-1.0, -1.0, -0.33),
         // Cara Bot 5.0

         Translate(-0.33, -1.0, 0.33),
         Translate(0.33, -1.0, 0.33),
         Translate(0.33, -1.0, -0.33),
         Translate(-0.33, -1.0, -0.33),
         // Cara Bot 6.0
   
         Translate(0.33, -1.0, 0.33),
         Translate(1.0, -1.0, 0.33),
         Translate(1.0, -1.0, -0.33),
         Translate(0.33, -1.0, -0.33),
         // Cara Bot 7.0
      
         Translate(-1.0, -1.0, -0.33),
         Translate(-0.33, -1.0, -0.33),
         Translate(-0.33, -1.0, -1.0),
         Translate(-1.0, -1.0, -1.0),
         // Cara Bot 8.0

         Translate(-0.33, -1.0, -0.33),
         Translate(0.33, -1.0, 0.33),
         Translate(0.33, -1.0, -1.0),
         Translate(-0.33, -1.0, -1.0),
         // Cara Bot 9.0

         Translate(0.33, -1.0, -0.33),
         Translate(1.0, -1.0, -0.33),
         Translate(1.0, -1.0, -1.0),
         Translate(0.33, -1.0, -1.0)

    };

    float colores[][3] =
    {
         //Naranja: 
        {1.0, 0.5, 0.0},
        // Rosa: 
        {1.0, 0.41, 0.71},
        //Marrón: 
        {0.6, 0.4, 0.2},
        //Gris claro :
        {0.7, 0.7, 0.7},
        //Violeta: 
        {0.5, 0.0, 0.5},
        //Verde claro : 
        {0.5, 1.0, 0.5},
        //Azul claro : 
        {0.5, 0.5, 1.0},
        //Gris oscuro : 
        {0.3, 0.3, 0.3},
        //Amarillo claro : 
        {1.0, 1.0, 0.5},
        //Verde oscuro : 
        {0.0, 0.5, 0.0} //falta generar colores

    };



        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

        // Aplica la rotación al cuadrado
        //glRotatef(rotationAngle, posX, posY, posZ);

        for (int i = 0; i < 54; i += 4) {
            glColor3f(colores[i / 4][0], colores[i / 4][1], colores[i / 4][2]);
            glBegin(GL_QUADS);
            for (int j = 0; j < 4; j++) {
                glVertex3f(vertices[i + j].GetX(), vertices[i + j].GetY(), vertices[i + j].GetZ());
            }
            glEnd();
        }

        glutSwapBuffers();
    
}

void keyboard2(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        
        break;
    case 's':
        rotationAngle -= 5.0f;  // Rotación hacia abajo
        //posX = 0;
        //posY = 0;
        posZ -= 1;
        break;
    case 'd':
        rotationAngle += 5.0f;  // Rotación hacia la derecha
        //posX = 0;
        posY -= 1;
        //posZ = 0;
        break;
    case 'a':
        rotationAngle -= 5.0f;  // Rotación hacia la izquierda
        //posX = 0;
        posY += 1;
        //posZ = 0;
        break;
    case 32:
        rotationAngle = 0.0f;  // Rotación hacia la izquierda
        posX = 0;
        posY = 0;
        posZ = 0;
        break;
    }

    glutPostRedisplay();
}
