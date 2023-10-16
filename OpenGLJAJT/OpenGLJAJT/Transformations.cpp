#include <iostream>
#include "Transformations.h";


Translate::Translate(float t_x, float t_y, float t_z) {
	m_x = t_x;
	m_y = t_y;
	m_z = t_z;
}

Translate Translate::RotateX(Translate& T_rotatex, float t_angle) {

	angle = t_angle * 180 / 3.1416;
	m_y = (m_y * cos(angle)) - (m_z * sin(angle));
	m_z = (m_y * sin(angle) + (m_z * cos(angle)));
	return Translate(m_x, m_y, m_z);
}
Translate Translate::RotateY(Translate& T_rotatey, float t_angle) {

	angle = t_angle * 180 / 3.1416;
	m_x = (m_x * cos(angle)) + (m_z * sin(angle));
	m_z = (-(m_y * sin(angle)) + (m_z * cos(angle)));
	return Translate(m_x, m_y, m_z);
}
Translate Translate::RotateZ(Translate& T_rotatez, float t_angle) {

	angle = t_angle * 180 / 3.1416;
	m_x = (m_x * cos(angle)) - (m_y * sin(angle));
	m_z = ((m_x * sin(angle)) + (m_y * cos(angle)));
	return Translate(m_x, m_y, m_z);
}

float Translate::GetX() {
	return m_x;
}
float Translate::GetY() {
	return m_y;
}
float Translate::GetZ() {
	return m_z;
}




/*
Rx= {1        0           0 }
	{0      cos0        -sen0}
	{0      sen0        cos0}

	Ry= {cos0       0       sen0 }
		{0          1        0   }
		{-sen0      0        cos0}

	 Rz= {cos0   -sen0      0 }
		{sen0     cos0      0 }
		{0         0        1 }
*/

/*
Para x =  { x }
		  { ycos0 -zsen0  }
		  { ysen0 + zcos0}


Para y =  {xcos0 + zsen0}
		  {y}
		  {-xsen0 + zcos0}

Para Z =  {xcos0 - ysen0}
		  {xsen0 + ycos0}
		  {z}
*/