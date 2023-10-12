#include "main.h"

#include <GL/glut.h>

void displayCuadrado() {
    glClear(GL_COLOR_BUFFER_BIT);  // Limpiar el búfer de color

    glColor3f(0.0f, 1.0f, 0.0f);  // Establecer el color a verde (R=0, G=1, B=0)

    glBegin(GL_QUADS);  // Comenzar a dibujar un cuadrado
    glVertex2f(-0.5f, -0.5f);  // Esquina inferior izquierda
    glVertex2f(0.5f, -0.5f);   // Esquina inferior derecha
    glVertex2f(0.5f, 0.5f);    // Esquina superior derecha
    glVertex2f(-0.5f, 0.5f);   // Esquina superior izquierda
    glEnd();  // Finalizar el dibujo del cuadrado

    glFlush();  // Forzar la representación en pantalla
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glBegin(GL_QUADS);

    // Cara frontal
    glColor3f(1.0, 0.0, 0.0); // Rojo
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-0.5,-1.0,1.0);
    glVertex3f(-0.5,-0.5,1.0);
    glVertex3f(-1.0,-0.5,1.0);

    // Cara frontal2.0
    glColor3f(0.0, 1.0, 0.0); // VERDE
    glVertex3f(-0.5, -1.0, 1.0);
    glVertex3f(0.5,-1.0,1.0);
    glVertex3f(0.5,-0.5,1.0);
    glVertex3f(-0.5,-0.5,1.0);
    // Cara frontal3.0
    glColor3f(1.0, 0.0, 1.0); // AZUL
    glVertex3f(0.5,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-0.5,1.0);
    glVertex3f(0.5,-0.5,1.0);
    // Cara frontal4.0
    glColor3f(1.0, 1.0, 0.0); // AMA
    glVertex3f(-1.0,-0.5,1.0);
    glVertex3f(-0.5,-0.5,1.0);
    glVertex3f(-0.5,0.5,1.0);
    glVertex3f(-1.0,0.5,1.0);
    // Cara frontal5.0
    glColor3f(0.0,0.0,0.0); // BLANCO
    glVertex3f(-0.5, -0.5, 1.0);
    glVertex3f(0.5,-0.5,1.0);
    glVertex3f(0.5,0.5,1.0);
    glVertex3f(-0.5, 0.5, 1.0);
    // Cara frontal6.0
    glColor3f(0.0, 0.1, 0.1); // CIAN
    glVertex3f(0.5, -0.5, 1.0);
    glVertex3f(1.0, -0.5, 1.0);
    glVertex3f(1.0, 0.5, 1.0);
    glVertex3f(0.5, 0.5, 1.0);
    // Cara frontal7.0
    glColor3f(1.0, 0.0, 1.0); // MAGENTA
    glVertex3f(-1.0, 0.5, 1.0);
    glVertex3f(-0.5, 0.5, 1.0);
    glVertex3f(-0.5,1.0,1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    // Cara frontal8.0
    glColor3f(1.0, 0.0, 0.0); // NEGRO
    glVertex3f(-0.5,0.5,1.0);
    glVertex3f(0.5,0.5,1.0);
    glVertex3f(0.5,1.0,1.0);
    glVertex3f(-0.5,1.0,1.0);
    // Cara frontal9.0
    glColor3f(0.5, 0.5, 0.5); // GRIS
    glVertex3f(0.5,0.5,1.0);
    glVertex3f(1.0,0.5,1.0);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(0.5,1.0,1.0);





    //// Cara trasera
    //glColor3f(0.0, 0.0, 1.0); // Azul
    //glVertex3f(-1.0, -1.0, -1.0);
    //glVertex3f(1.0, -1.0, -1.0);
    //glVertex3f(1.0, 1.0, -1.0);
    //glVertex3f(-1.0, 1.0, -1.0);

    //// Cara superior
    //glColor3f(0.0, 1.0, 0.0); // Verde
    //glVertex3f(-1.0, 1.0, 1.0);
    //glVertex3f(1.0, 1.0, 1.0);
    //glVertex3f(1.0, 1.0, -1.0);
    //glVertex3f(-1.0, 1.0, -1.0);

    //// Cara inferior
    //glColor3f(1.0, 1.0, 0.0); // Amarillo
    //glVertex3f(-1.0, -1.0, 1.0);
    //glVertex3f(1.0, -1.0, 1.0);
    //glVertex3f(1.0, -1.0, -1.0);
    //glVertex3f(-1.0, -1.0, -1.0);

    //// Cara izquierda
    //glColor3f(1.0, 0.0, 1.0); // Magenta
    //glVertex3f(-1.0, -1.0, 1.0);
    //glVertex3f(-1.0, 1.0, 1.0);
    //glVertex3f(-1.0, 1.0, -1.0);
    //glVertex3f(-1.0, -1.0, -1.0);

    //// Cara derecha
    //glColor3f(0.0, 1.0, 1.0); // Cian
    //glVertex3f(1.0, -1.0, 1.0);
    //glVertex3f(1.0, 1.0, 1.0);
    //glVertex3f(1.0, 1.0, -1.0);
    //glVertex3f(1.0, -1.0, -1.0);

    glEnd();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 1.0, 10.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Cubo OpenGL");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}