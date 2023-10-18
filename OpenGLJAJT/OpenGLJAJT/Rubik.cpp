#include <iostream>
#include <list>
#include "Colores.h"
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

std::list <Rubik> GeneracionCubeListFront;
std::list <Rubik> GeneracionCubeListBack;
std::list <Rubik> GeneracionCubeListTop;
std::list <Rubik> GeneracionCubeListBot;
std::list <Rubik> GeneracionCubeListLeft;
std::list <Rubik> GeneracionCubeListRight;
std::list <Colores> GeneracionDeColoresFront;
std::list <Colores> GeneracionDeColoresBack;
std::list <Colores> GeneracionDeColoresTop;
std::list <Colores> GeneracionDeColoresBot;
std::list <Colores> GeneracionDeColoresLeft;
std::list <Colores> GeneracionDeColoresRight;

Rubik Ge[];


void Rubik::GenerateFrontalFace() {
    //glColor3f(1.0f, 0.0f, 0.0f);  // rojo
    //glVertex3f(m_x - (2 * tempX),m_y- (2 * tempY),m_z);
    //glVertex3f(m_x, m_y - (2 * tempY),m_z);
    //glVertex3f(m_x,m_y,m_z);
    //glVertex3f(m_x - (2 * tempX),m_y,m_z);
    GeneracionDeColoresFront.push_back(Colores(1.0f, 0.0f, 0.0f));
    GeneracionCubeListFront.push_back(Rubik(m_x - (2 * tempX), m_y - (2 * tempY), m_z));
    GeneracionCubeListFront.push_back(Rubik(m_x, m_y - (2 * tempY), m_z));
    GeneracionCubeListFront.push_back(Rubik(m_x, m_y, m_z));
    GeneracionCubeListFront.push_back(Rubik(m_x - (2 * tempX), m_y, m_z));

    
}
void Rubik::GenerateBackFace() {

    //glColor3f(0.0f, 1.0f, 0.0f);  // Verde
    //glVertex3f(m_x - (2 * tempX), m_y - (2 * tempY), m_z - (2 * tempZ));
    //glVertex3f(m_x, m_y - (2 * tempY), m_z - (2 * tempZ));
    //glVertex3f(m_x, m_y, m_z - (2 * tempZ));
    //glVertex3f(m_x - (2 * tempX), m_y, m_z - (2 * tempZ));
    GeneracionDeColoresBack.push_back(Colores(0.0f, 1.0f, 0.0f));
    GeneracionCubeListBack.push_back(Rubik(m_x - (2 * tempX), m_y - (2 * tempY), m_z - (2 * tempZ)));
    GeneracionCubeListBack.push_back(Rubik(m_x, m_y - (2 * tempY), m_z - (2 * tempZ)));
    GeneracionCubeListBack.push_back(Rubik(m_x, m_y, m_z - (2 * tempZ)));
    GeneracionCubeListBack.push_back(Rubik(m_x - (2 * tempX), m_y, m_z - (2 * tempZ)));

}
void Rubik::GenerateTopFace() {

    //glColor3f(0.0f, 0.0f, 1.0f);  // Azul
    //glVertex3f(m_x - (2 * tempX), m_y, m_z - (2 * tempZ));
    //glVertex3f(m_x, m_y, m_z - (2 * tempZ));
    //glVertex3f(m_x, m_y, m_z);
    //glVertex3f(m_x - (2 * tempX), m_y, m_z);
    GeneracionDeColoresTop.push_back(Colores(0.0f, 0.0f, 1.0f));
    GeneracionCubeListTop.push_back(Rubik(m_x - (2 * tempX), m_y, m_z - (2 * tempZ)));
    GeneracionCubeListTop.push_back(Rubik(m_x, m_y, m_z - (2 * tempZ)));
    GeneracionCubeListTop.push_back(Rubik(m_x, m_y, m_z));
    GeneracionCubeListTop.push_back(Rubik(m_x - (2 * tempX), m_y, m_z));

}

void Rubik::GenerateBotFace() {

    //glColor3f(1.0f, 1.0f, 0.0f);  // Amarillo
    //glVertex3f(m_x- (2 * tempX), m_y- (2 * tempY), m_z- (2 * tempZ));
    //glVertex3f(m_x, m_y- (2 * tempY), m_z- (2 * tempZ));
    //glVertex3f(m_x, m_y- (2 * tempY), m_z);
    //glVertex3f(m_x- (2 * tempX), m_y- (2 * tempY), m_z);
    GeneracionDeColoresBot.push_back(Colores(1.0f, 1.0f, 0.0f));
    GeneracionCubeListBot.push_back(Rubik(m_x - (2 * tempX), m_y - (2 * tempY), m_z - (2 * tempZ)));
    GeneracionCubeListBot.push_back(Rubik(m_x, m_y - (2 * tempY), m_z - (2 * tempZ)));
    GeneracionCubeListBot.push_back(Rubik(m_x, m_y - (2 * tempY), m_z));
    GeneracionCubeListBot.push_back(Rubik(m_x - (2 * tempX), m_y - (2 * tempY), m_z));
}

void Rubik::GenerateLeftFace() {

    //glColor3f(1.0f, 0.0f, 1.0f);  // Magenta
    //glVertex3f(m_x - (2 * tempX), m_y - (2 * tempY), m_z - (2 * tempZ));
    //glVertex3f(m_x - (2 * tempX), m_y, m_z - (2 * tempZ));
    //glVertex3f(m_x - (2 * tempX), m_y, m_z);
    //glVertex3f(m_x - (2 * tempX), m_y - (2 * tempY), m_z);
    GeneracionDeColoresLeft.push_back(Colores(1.0f, 0.0f, 1.0f));
    GeneracionCubeListLeft.push_back(Rubik(m_x - (2 * tempX), m_y - (2 * tempY), m_z - (2 * tempZ)));
    GeneracionCubeListLeft.push_back(Rubik(m_x - (2 * tempX), m_y, m_z - (2 * tempZ)));
    GeneracionCubeListLeft.push_back(Rubik(m_x - (2 * tempX), m_y, m_z));
    GeneracionCubeListLeft.push_back(Rubik(m_x - (2 * tempX), m_y - (2 * tempY), m_z));
}

void Rubik::GenerateRightFace() {

    //glColor3f(0.0f, 1.0f, 1.0f);  // Cian
    //glVertex3f(m_x, m_y - (2 * tempY), m_z - (2 * tempZ));
    //glVertex3f(m_x, m_y, m_z - (2 * tempZ));
    //glVertex3f(m_x, m_y, m_z);
    //glVertex3f(m_x, m_y - (2 * tempY), m_z);
    GeneracionDeColoresRight.push_back(Colores(0.0f, 1.0f, 1.0f));
    GeneracionCubeListRight.push_back(Rubik(m_x, m_y - (2 * tempY), m_z - (2 * tempZ)));
    GeneracionCubeListRight.push_back(Rubik(m_x, m_y, m_z - (2 * tempZ)));
    GeneracionCubeListRight.push_back(Rubik(m_x, m_y, m_z));
    GeneracionCubeListRight.push_back(Rubik(m_x, m_y - (2 * tempY), m_z));
}

void Rubik::GenerateCubeLists() {
   
    // Dibuja el cubo
   // glBegin(GL_QUADS);
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

    //glEnd();

}

void Rubik::GenerateMultiCubesList() {
    for (int z = 0; z <= 2;z++) {
        
        for (int x = 0; x <= 2; x++) {
            
            for (int y = 0; y <= 2; y++) {
                GenerateCubeLists();
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

void Rubik::GenerateMultiCubesFig() {
    std::list<Rubik>::iterator it = GeneracionCubeListFront.begin();
        for (int i = 0; i <= 8; i++) {
       
        Rubik rubikActual = *it;
        glBegin(GL_QUADS);
        glVertex3f(rubikActual.m_x, rubikActual.m_y, rubikActual.m_z);
        it++;
        Rubik rubikActual1 = *it;
        glVertex3f(rubikActual1.m_x, rubikActual1.m_y, rubikActual1.m_z);
        it++;
        Rubik rubikActual2 = *it;
        glVertex3f(rubikActual2.m_x, rubikActual2.m_y, rubikActual2.m_z);
        it++;
        Rubik rubikActual3 = *it;
        glVertex3f(rubikActual3.m_x, rubikActual3.m_y, rubikActual3.m_z);
        it++;
        glEnd();
    }
   

}