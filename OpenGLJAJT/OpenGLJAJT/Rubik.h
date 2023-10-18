#pragma once
#include <GL/glut.h>

class Rubik {
public:
	float m_x;
	float m_y;
	float m_z;
	float tempX;
	float tempY;
	float tempZ;
	
public:
	Rubik();
	Rubik(float m_x, float m_y, float m_z);
	
	void RotateX();
	void RotateY();
	void RotateZ();
	void GenerateCubeLists();
	//float Vertices[];
	void GenerateFrontalFace();
	void GenerateBackFace();
	void GenerateRightFace();
	void GenerateLeftFace();
	void GenerateTopFace();
	void GenerateBotFace();
	void GenerateMultiCubesList();

	void GenerateMultiCubesFig();
};

