#include "main.h"
#include "Figures.h"
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

    glutDisplayFunc(displayCube);
   // glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}