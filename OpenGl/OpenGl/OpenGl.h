#pragma once
#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#include "Punto3D.h"


using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;
using namespace System::IO;
ref class OpenGl {
public:
	void constructor();
	void modificarPuntos(List<Punto3D^>^ listEntradaPuntos);
	void modificarObstaculos(List<Punto3D^>^ listEntradaObstaculos);
	void dibujar();
	static List<Punto3D^>^ puntos = gcnew List<Punto3D^>();
	static List<Punto3D^>^ obstaculos = gcnew List<Punto3D^>();
	static bool listo = false;
private:
	
	void threadconstructor();
	void iniciarPuntos();
	void iniciarObstaculos();
	void limpiarListas();
	
};