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
    vector3[0] = m_x;
    vector3[1] = m_y;
    vector3[2] = m_z;
    
}



void Rubik::RotateX() {
	float temy = (m_y * cos(angle)) - (m_z * sin(angle));
	float temz = (m_y * sin(angle) + (m_z * cos(angle)));
	//angle = t_angle * 180 / 3.1416;
    m_y = temy;
    m_z = temz;
    vector3[0] = m_x;
    vector3[1] = m_y;
    vector3[2] = m_z;

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
    std::list<Rubik>::iterator itf = GeneracionCubeListFront.begin();
    std::list<Rubik>::iterator itB = GeneracionCubeListBack.begin();
    std::list<Rubik>::iterator itT = GeneracionCubeListTop.begin();
    std::list<Rubik>::iterator itBo = GeneracionCubeListBot.begin();
    std::list<Rubik>::iterator itL = GeneracionCubeListLeft.begin();
    std::list<Rubik>::iterator itR = GeneracionCubeListRight.begin();
    std::list<Colores>::iterator c1 = GeneracionDeColoresFront.begin();
    std::list<Colores>::iterator c2 = GeneracionDeColoresBack.begin();
    std::list<Colores>::iterator c3 = GeneracionDeColoresTop.begin();
    std::list<Colores>::iterator c4 = GeneracionDeColoresBot.begin();
    std::list<Colores>::iterator c5 = GeneracionDeColoresLeft.begin();
    std::list<Colores>::iterator c6 = GeneracionDeColoresRight.begin();
        
    for (int i = 0; i <26; i++) {
       

            Colores c_f = *c1;
            Colores c_b = *c2;
            Colores c_t = *c3;
            Colores c_bo = *c4;
            Colores c_l = *c5;
            Colores c_r = *c6;
        glBegin(GL_QUADS);
        
        //front

        CubeFromList(c_f, itf);
       // back

        CubeFromList(c_b, itB);
        //top

        CubeFromList(c_t, itT);
        //bot

        CubeFromList(c_bo, itBo);
        //Left
      
        CubeFromList(c_l, itL);
        ////Right
        CubeFromList(c_r, itR);

        glEnd();
    }

}

void Rubik::CubeFromList(Colores& c_r, std::list<Rubik>::iterator& itR)
{
    glColor3f(c_r.colorX, c_r.colorY, c_r.colorZ);
    Rubik rubicActual20 = *itR;
    glVertex3f(rubicActual20.m_x, rubicActual20.m_y, rubicActual20.m_z);
    itR++;
    Rubik rubicActual21 = *itR;
    glVertex3f(rubicActual21.m_x, rubicActual21.m_y, rubicActual21.m_z);
    itR++;
    Rubik rubicActual22 = *itR;
    glVertex3f(rubicActual22.m_x, rubicActual22.m_y, rubicActual22.m_z);
    itR++;
    Rubik rubicActual23 = *itR;
    glVertex3f(rubicActual23.m_x, rubicActual23.m_y, rubicActual23.m_z);
    itR++;
}

void Rubik::RotateLeftFace() {

    std::list<Rubik>::iterator itf = GeneracionCubeListFront.begin();
    std::list<Rubik>::iterator itB = GeneracionCubeListBack.begin();
    std::list<Rubik>::iterator itT = GeneracionCubeListTop.begin();
    std::list<Rubik>::iterator itBo = GeneracionCubeListBot.begin();
    std::list<Rubik>::iterator itL = GeneracionCubeListLeft.begin();
    std::list<Rubik>::iterator itR = GeneracionCubeListRight.begin();
  


    for (int i = 0; i < 9; i++) {

        //front
        Rubik rubikActual = *itf;
        std::cout << "El valor antes de y es q: " << rubikActual.m_y << std::endl;
        std::cout << "El valor antes de z es q: " << rubikActual.m_z << std::endl;
        RotateX();
        rubikActual.m_y = vector3[1];
        rubikActual.m_x = vector3[0];
        rubikActual.m_z = vector3[2];
        //std::cout << "El valor de x es q: " << rubikActual.m_x <<  std::endl;
        std::cout << "El valor de y es q: " << rubikActual.m_y << std::endl;
        std::cout << "El valor de z es q: " << rubikActual.m_z << std::endl;
        itf++;


    }
    GenerateMultiCubesFig();
}