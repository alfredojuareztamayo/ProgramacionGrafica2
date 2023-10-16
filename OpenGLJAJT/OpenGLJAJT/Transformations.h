#pragma once
#include <cmath>
#include <iostream>

class Translate {
private:
	float m_x;
	float m_y;
	float m_z;
	float angle;

public:
	Translate(float m_x, float m_y, float m_z);
	Translate RotateX(Translate &T_rotatex, float angle);
	Translate RotateY(Translate &T_rotatey, float angle);
	Translate RotateZ(Translate &T_rotatez, float angle);
	float GetX();
	float GetY();
	float GetZ();

};
//End Class Traslate
