#include <iostream>
#include <fstream>
#include "graph.h"
using namespace std;

int* copiarArray(int array1[], int nElem) {
	int* retArray = new int[nElem];
	for (int i = 0; i < nElem -1; i++) {
		retArray[i] = array1[i];
	}
	delete[] array1;
	return retArray;
}
int main() {

	
	ifstream archivo;
	string nombreArchivo;

	cout << "Introduce el nombre del archivo a abrir (solo admite archivos .dat, no incluir extension):\n";

	cin >> nombreArchivo;
	nombreArchivo += ".dat";


	archivo.open(nombreArchivo);
	if (archivo.is_open()) {
		int aux, contador = 0;
		int* valores = new int[contador];
		while (archivo >> aux)
		{
			contador++;
			valores = copiarArray(valores, contador);
			valores[contador - 1] = aux;
		}
		archivo.close();
		drawGraph(contador, valores);
		delete[] valores;
	}

	else cout << "No existe/no se pudo abrir el archivo: " << nombreArchivo << endl;
	
	return 0;
}
