#pragma once

#include<vector>
#include<fstream>
#include "Caja.h"
using namespace std;


class Empaquetado {
public:
	//Empaquetado();
	~Empaquetado();
	Empaquetado(GLfloat anchop,GLfloat largop);

	GLfloat anchop, largop;

	vector<Caja>objetos;
	Caja contenedor;
	ifstream inp;
	ofstream out;
};

//Empaquetado::Empaquetado() {}

Empaquetado::~Empaquetado() {}

Empaquetado::Empaquetado(GLfloat anchop, GLfloat largop){
	
	this->anchop = anchop;
	this->largop = largop;
	inp.open("input.txt");
	out.open("output.txt");
	int n;
	inp >> n;
	inp >> contenedor.alto >> contenedor.ancho >> contenedor.largo;
	contenedor.SetPositionDraw(anchop, largop, contenedor.alto, contenedor.ancho, contenedor.largo);
	for(int i=0;i<n;i++){
		GLfloat x, y, z, ancho, largo, alto;
		inp >> x >> y >> z >> alto >> ancho >> largo;
		objetos.push_back(Caja(alto, ancho, largo));
		objetos[i].SetPosition(x, y, z);
		objetos[i].SetPositionDraw(anchop, largop, contenedor.alto, contenedor.ancho, contenedor.largo);
	}
}