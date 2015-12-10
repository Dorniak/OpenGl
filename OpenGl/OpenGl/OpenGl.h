#pragma once
#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#include "Punto3D.h"

using namespace System;
using namespace System::Collections::Generic;
ref class OpenGl {
public:
	void crear();
	void modificarPuntos(List<Punto3D^>^ listEntradaPuntos);
	void modificarObstaculos(List<Punto3D^>^ listEntradaObstaculos);
	static List<Punto3D^>^ puntos = gcnew List<Punto3D^>();
	static List<Punto3D^>^ obstaculos = gcnew List<Punto3D^>();
	void dibujar();
private:

	void iniciarPuntos();
	void iniciarObstaculos();
	void limpiarListas();
};