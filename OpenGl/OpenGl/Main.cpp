#include "OpenGl.h"
#include <array>
void Main(cli::array<String^>^ args)
{
	OpenGl^ P = gcnew OpenGl();
	P->constructor();
	int q = 1;
	//StreamReader^ sr = gcnew StreamReader("D:\\Documentos\\GitHub\\OpenGl\\OpenGl\\Debug\\prueba1.csv");
	double x, y, z;
	Punto3D^ aa;
	String^ aaa;
	String^ delimi = ",";
	String^ delimi2 = ".";
	String^ X;
	String^ Y;
	String^ Z;
	cli::array<Char>^delimiter = delimi->ToCharArray();
	cli::array<String^, 1>^ split = nullptr;
	cli::array<String^, 1>^ split2 = nullptr;
	cli::array<Char>^delimiter2 = delimi2->ToCharArray();
	List<Punto3D^>^ punta = gcnew List<Punto3D^>();
 	StreamReader^ sr;
	while (1) {
		//sr = gcnew StreamReader("E:\\prueba\\frame-" + q.ToString() + ".log");
		sr = gcnew StreamReader("D:\\Escritorio\\prueba\\prueba ("+ q.ToString()+").csv");
		aaa = sr->ReadLine();
		while (sr->Peek() >= 0) {
			aaa = sr->ReadLine();
			split = aaa->Split(delimiter, 4);
			split2 = split[0]->Split(delimiter2, 2);
			X = split2[0] + "," + split2[1];
			x = Convert::ToDouble(X);
			split2 = split[1]->Split(delimiter2, 2);
			Y = split2[0] + "," + split2[1];
			y = Convert::ToDouble(Y);
			split2 = split[2]->Split(delimiter2, 2);
			Z = split2[0] + "," + split2[1];
			z = Convert::ToDouble(Z);
			//Console::WriteLine(x+":::"+y+":::"+z);
			aa = gcnew Punto3D(x, y, z);
			punta->Add(aa);
		}
		if(P->listo)
		P->modificarPuntos(punta);
		//Console::WriteLine(q);
		q++;
		split->Clear;
		split2->Clear;
		punta->RemoveRange(0, punta->Count);
		if (q == 520) {
			q = 1;
		}
	}
}