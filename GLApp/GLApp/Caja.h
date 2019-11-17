#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>     
#include <stdlib.h>     
#include <time.h>

class Caja {
public:
	Caja();
	~Caja();
	Caja(GLfloat alto, GLfloat ancho, GLfloat largo);
	void SetPositionDraw(GLfloat anchop, GLfloat largop, GLfloat altoc, GLfloat largoc, GLfloat anchoc);
	void SetPosition(int x, int y, int z);


	GLfloat vertices[72];
	GLfloat x, y, z;
	GLfloat alto, ancho, largo;
	GLfloat R, G, B;
};

Caja::Caja() {}

Caja::~Caja() {}

Caja::Caja(GLfloat alto, GLfloat ancho, GLfloat largo){
	
	this->alto = largo * 5.0f;
	this->ancho = alto * 5.0f;
	this->largo = ancho * 5.0f;
	x = 0;
	y = 0;
	z = 0;

	R = (rand() % 255)*1.0F;
	G = (rand() % 255)*1.0F;
	B = (rand() % 255)*1.0F;
}

void Caja::SetPositionDraw(GLfloat anchop, GLfloat largop, GLfloat altoc, GLfloat anchoc, GLfloat largoc){

	this->x += anchop-largoc+largo;
	this->y += largop-anchoc+ancho;
	this->z += -500-altoc+alto;


	GLfloat vert[72]={
		//
											// front face
			x - largo, y + ancho, z + alto, // top left
			x + largo, y + ancho, z + alto, // top right
			x + largo, y - ancho, z + alto, // bottom right
			x - largo, y - ancho, z + alto, // bottom left

											// back face
			x - largo, y + ancho, z - alto, // top left
			x + largo, y + ancho, z - alto, // top right
			x + largo, y - ancho, z - alto, // bottom right
			x - largo, y - ancho, z - alto, // bottom left

											// left face
			x - largo, y + ancho, z + alto, // top left
			x - largo, y + ancho, z - alto, // top right
			x - largo, y - ancho, z - alto, // bottom right
			x - largo, y - ancho, z + alto, // bottom left

											// right face
			x + largo, y + ancho, z + alto, // top left
			x + largo, y + ancho, z - alto, // top right
			x + largo, y - ancho, z - alto, // bottom right
			x + largo, y - ancho, z + alto, // bottom left
	
											// top face
			x - largo, y + ancho, z + alto, // top left
			x - largo, y + ancho, z - alto, // top right
			x + largo, y + ancho, z - alto, // bottom right
			x + largo, y + ancho, z + alto, // bottom left

											// top face
			x - largo, y - ancho, z + alto, // top left
			x - largo, y - ancho, z - alto, // top right
			x + largo, y - ancho, z - alto, // bottom right
			x + largo, y - ancho, z + alto  // bottom left

			//ancho->
	};
	for (int i = 0; i < 72; i++)vertices[i] = vert[i];
}
void Caja::SetPosition(int x, int y, int z){
	this->x += y * 10.0f;
	this->y += z * 10.0f;
	this->z += x * 10.0f;
}
