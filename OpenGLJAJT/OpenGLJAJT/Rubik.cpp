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



void Rubik::RotateX(Rubik &t) {
	
	//angle = t_angle * 180 / 3.1416;
	t.m_y = (t.m_y * cos(angle)) - (t.m_z * sin(angle));
	t.m_z = (t.m_y * sin(angle) + (t.m_z * cos(angle)));
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
        Rubik rubikActual = *itf;
        glColor3f(c_f.colorX, c_f.colorY, c_f.colorZ);
        glVertex3f(rubikActual.m_x, rubikActual.m_y, rubikActual.m_z);
        itf++;
        Rubik rubikActual1 = *itf;
        glVertex3f(rubikActual1.m_x, rubikActual1.m_y, rubikActual1.m_z);
        itf++;
        Rubik rubikActual2 = *itf;
        glVertex3f(rubikActual2.m_x, rubikActual2.m_y, rubikActual2.m_z);
        itf++;
        Rubik rubikActual3 = *itf;
        glVertex3f(rubikActual3.m_x, rubikActual3.m_y, rubikActual3.m_z);
        itf++;

       // back
        glColor3f(c_b.colorX, c_b.colorY, c_b.colorZ);
        Rubik rubicActual4 = *itB;
        glVertex3f(rubicActual4.m_x, rubicActual4.m_y, rubicActual4.m_z);
        itB++;
        Rubik rubicActual5 = *itB;
        glVertex3f(rubicActual5.m_x, rubicActual5.m_y, rubicActual5.m_z);
        itB++;
        Rubik rubicActual6 = *itB;
        glVertex3f(rubicActual6.m_x, rubicActual6.m_y, rubicActual6.m_z);
        itB++;
        Rubik rubicActual7 = *itB;
        glVertex3f(rubicActual7.m_x, rubicActual7.m_y, rubicActual7.m_z);
        itB++;

        //top
        glColor3f(c_t.colorX, c_t.colorY, c_t.colorZ);
        Rubik rubicActual8 = *itT;
        glVertex3f(rubicActual8.m_x, rubicActual8.m_y, rubicActual8.m_z);
        itT++;
        Rubik rubicActual9 = *itT;
        glVertex3f(rubicActual9.m_x, rubicActual9.m_y, rubicActual9.m_z);
        itT++;
        Rubik rubicActual10 = *itT;
        glVertex3f(rubicActual10.m_x, rubicActual10.m_y, rubicActual10.m_z);
        itT++;
        Rubik rubicActual11 = *itT;
        glVertex3f(rubicActual11.m_x, rubicActual11.m_y, rubicActual11.m_z);
        itT++;
        //bot

        glColor3f(c_bo.colorX, c_bo.colorY, c_bo.colorZ);
        Rubik rubicActual12 = *itBo;
        glVertex3f(rubicActual12.m_x, rubicActual12.m_y, rubicActual12.m_z);
        itBo++;
        Rubik rubicActual13 = *itBo;
        glVertex3f(rubicActual13.m_x, rubicActual13.m_y, rubicActual13.m_z);
        itBo++;
        Rubik rubicActual14 = *itBo;
        glVertex3f(rubicActual14.m_x, rubicActual14.m_y, rubicActual14.m_z);
        itBo++;
        Rubik rubicActual15 = *itBo;
        glVertex3f(rubicActual15.m_x, rubicActual15.m_y, rubicActual15.m_z);
        itBo++;

        //Left
        glColor3f(c_l.colorX, c_l.colorY, c_l.colorZ);
        Rubik rubicActual16 = *itL;
        glVertex3f(rubicActual16.m_x, rubicActual16.m_y, rubicActual16.m_z);
        itL++;
        Rubik rubicActual17 = *itL;
        glVertex3f(rubicActual17.m_x, rubicActual17.m_y, rubicActual17.m_z);
        itL++;
        Rubik rubicActual18 = *itL;
        glVertex3f(rubicActual18.m_x, rubicActual18.m_y, rubicActual18.m_z);
        itL++;
        Rubik rubicActual19 = *itL;
        glVertex3f(rubicActual19.m_x, rubicActual19.m_y, rubicActual19.m_z);
        itL++;

        ////Right
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

        glEnd();
    }

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
        RotateX(&rubikActual);
        //std::cout << "El valor de x es q: " << rubikActual.m_x <<  std::endl;
        std::cout << "El valor de y es q: " << rubikActual.m_y << std::endl;
        std::cout << "El valor de z es q: " << rubikActual.m_z << std::endl;
        itf++;
        /*Rubik rubikActual1 = *itf;
        rubikActual1.RotateX();
        itf++;
        Rubik rubikActual2 = *itf;
        rubikActual2.RotateX();
        itf++;
        Rubik rubikActual3 = *itf;
        rubikActual3.RotateX();
        itf++;*/

        //// back
        //Rubik rubicActual4 = *itB;
        //rubicActual4.RotateX();
        //itB++;
        //Rubik rubicActual5 = *itB;
        //rubicActual5.RotateX();
        //itB++;
        //Rubik rubicActual6 = *itB;
        //rubicActual6.RotateX();
        //itB++;
        //Rubik rubicActual7 = *itB;
        //rubicActual7.RotateX();
        //itB++;

        ////top
        //Rubik rubicActual8 = *itT;
        //rubicActual8.RotateX();
        //itT++;
        //Rubik rubicActual9 = *itT;
        //rubicActual9.RotateX();
        //itT++;
        //Rubik rubicActual10 = *itT;
        //rubicActual10.RotateX();
        //itT++;
        //Rubik rubicActual11 = *itT;
        //rubicActual11.RotateX();
        //itT++;
        ////bot

        //Rubik rubicActual12 = *itBo;
        //rubicActual12.RotateX();
        //itBo++;
        //Rubik rubicActual13 = *itBo;
        //rubicActual13.RotateX();
        //itBo++;
        //Rubik rubicActual14 = *itBo;
        //rubicActual14.RotateX();
        //itBo++;
        //Rubik rubicActual15 = *itBo;
        //rubicActual15.RotateX();
        //itBo++;

        ////Left
        //Rubik rubicActual16 = *itL;
        //rubicActual16.RotateX();
        //itL++;
        //Rubik rubicActual17 = *itL;
        //rubicActual16.RotateX();
        //itL++;
        //Rubik rubicActual18 = *itL;
        //rubicActual18.RotateX();
        //itL++;
        //Rubik rubicActual19 = *itL;
        //rubicActual19.RotateX();
        //itL++;

        //////Right
        //Rubik rubicActual20 = *itR;
        //rubicActual20.RotateX();
        //itR++;
        //Rubik rubicActual21 = *itR;
        //rubicActual21.RotateX();
        //itR++;
        //Rubik rubicActual22 = *itR;
        //rubicActual22.RotateX();
        //itR++;
        //Rubik rubicActual23 = *itR;
        //rubicActual23.RotateX();
        //itR++;

    }
    GenerateMultiCubesFig();
}