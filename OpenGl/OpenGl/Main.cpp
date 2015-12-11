#include "OpenGl.h"
#include <array>
void Main(cli::array<String^>^ args)
{
	StreamReader^ sr = gcnew StreamReader("D:\\Documentos\\GitHub\\OpenGl\\OpenGl\\Debug\\prueba1.csv");
	double x, y, z;
	Punto3D^ aa;
	String^ aaa;
	String^ delimi = ",";
	cli::array<Char>^delimiter = delimi->ToCharArray();
	cli::array<String^, 1>^ split = nullptr;
	List<Punto3D^>^ punta = gcnew List<Punto3D^>();
	while (sr->Peek() >= 0) {
		aaa = sr->ReadLine();
		split = aaa->Split(delimiter, 4);
		x = Convert::ToDouble(split[0]);
		y = Convert::ToDouble(split[1]);
		z = Convert::ToDouble(split[2]);
		aa = gcnew Punto3D(x, y, z);
		punta->Add(aa);
	}
	OpenGl^ P = gcnew OpenGl();
	P->constructor();
	P->modificarPuntos(punta);

}