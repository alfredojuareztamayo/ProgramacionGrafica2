#include <iostream>
#include "Rubik.h"

float angle = 90;

Rubik::Rubik() {

};

Rubik::Rubik(float t_x, float t_y, float t_z) {
	m_x = t_x;
	m_y = t_y;
	m_z = t_z;
    tempX = t_x;
    tempY = t_y;
    tempZ = t_z;
}

void Rubik::RotateX() {
	
	//angle = t_angle * 180 / 3.1416;
	m_y = (m_y * cos(angle)) - (m_z * sin(angle));
	m_z = (m_y * sin(angle) + (m_z * cos(angle)));
}
void Rubik::RotateY() {
	
	//angle = t_angle * 180 / 3.1416;
	m_x = (m_x * cos(angle)) + (m_z * sin(angle));
	m_z = (-(m_y * sin(angle)) + (m_z * cos(angle)));
}
void Rubik::RotateZ() {

	//angle = t_angle * 180 / 3.1416;
	m_x = (m_x * cos(angle)) - (m_y * sin(angle));
	m_z = ((m_x * sin(angle)) + (m_y * cos(angle)));
}

float Vertices[][3] = {
    {-1.0f, -1.0f, 1.0f},
    {1.0f, -1.0f, 1.0f},
    {1.0f, 1.0f, 1.0f},
    {-1.0f, 1.0f, 1.0f}
};


void Rubik::GenerateFrontalFace() {
    glColor3f(1.0f, 0.0f, 0.0f);  // rojo
    glVertex3f(m_x - (2 * tempX),m_y- (2 * tempY),m_z);
    glVertex3f(m_x, m_y - (2 * tempY),m_z);
    glVertex3f(m_x,m_y,m_z);
    glVertex3f(m_x - (2 * tempX),m_y,m_z);
    
}
void Rubik::GenerateBackFace() {

    glColor3f(0.0f, 1.0f, 0.0f);  // Verde
    glVertex3f(m_x - (2 * tempX), m_y - (2 * tempY), m_z - (2 * tempZ));
    glVertex3f(m_x, m_y - (2 * tempY), m_z - (2 * tempZ));
    glVertex3f(m_x, m_y, m_z - (2 * tempZ));
    glVertex3f(m_x - (2 * tempX), m_y, m_z - (2 * tempZ));

}
void Rubik::GenerateTopFace() {

    glColor3f(0.0f, 0.0f, 1.0f);  // Azul
    glVertex3f(m_x - (2 * tempX), m_y, m_z - (2 * tempZ));
    glVertex3f(m_x, m_y, m_z - (2 * tempZ));
    glVertex3f(m_x, m_y, m_z);
    glVertex3f(m_x - (2 * tempX), m_y, m_z);
}

void Rubik::GenerateBotFace() {

    glColor3f(1.0f, 1.0f, 0.0f);  // Amarillo
    glVertex3f(m_x- (2 * tempX), m_y- (2 * tempY), m_z- (2 * tempZ));
    glVertex3f(m_x, m_y- (2 * tempY), m_z- (2 * tempZ));
    glVertex3f(m_x, m_y- (2 * tempY), m_z);
    glVertex3f(m_x- (2 * tempX), m_y- (2 * tempY), m_z);
}

void Rubik::GenerateLeftFace() {

    glColor3f(1.0f, 0.0f, 1.0f);  // Magenta
    glVertex3f(m_x - (2 * tempX), m_y - (2 * tempY), m_z - (2 * tempZ));
    glVertex3f(m_x - (2 * tempX), m_y, m_z - (2 * tempZ));
    glVertex3f(m_x - (2 * tempX), m_y, m_z);
    glVertex3f(m_x - (2 * tempX), m_y - (2 * tempY), m_z);
}

void Rubik::GenerateRightFace() {

    glColor3f(0.0f, 1.0f, 1.0f);  // Cian
    glVertex3f(m_x, m_y - (2 * tempY), m_z - (2 * tempZ));
    glVertex3f(m_x, m_y, m_z - (2 * tempZ));
    glVertex3f(m_x, m_y, m_z);
    glVertex3f(m_x, m_y - (2 * tempY), m_z);
}

void Rubik::GenerateCube() {
   
    // Dibuja el cubo
    glBegin(GL_QUADS);
    // Cara frontal
    GenerateFrontalFace();
    // Cara trasera
    GenerateBackFace();
    // Cara superior
    GenerateTopFace();
    // Cara inferior
    GenerateBotFace();
    // Cara izquierda
    GenerateLeftFace();
    // Cara derecha
    GenerateRightFace();

    glEnd();

}

void Rubik::GenerateMultiCubes() {
    for (int z = 0; z <= 2;z++) {
        
        for (int x = 0; x <= 2; x++) {
            //GenerateCube();
            //
            for (int y = 0; y <= 2; y++) {
                GenerateCube();
                m_y -= ((tempY + tempY) + 0.1);
            }
            m_x += ((tempX + tempX) + 0.1);
            m_y = tempY;
        }
        m_z -= ((tempZ + tempZ) + 0.1);
        m_x = tempX;
    }
   
    std::cout << "El valor de x es: " << m_x << "y el valor de temp es: " << tempX << std::endl;
}
//glColor3f(1.0f, 0.0f, 0.0f);  // Rojo
   //glVertex3f(-1.0f, -1.0f, 1.0f);
   //glVertex3f(1.0f, -1.0f, 1.0f);
   //glVertex3f(1.0f, 1.0f, 1.0f);
   //glVertex3f(-1.0f, 1.0f, 1.0f);