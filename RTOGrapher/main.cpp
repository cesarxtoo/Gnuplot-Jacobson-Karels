#include <iostream>
#include <fstream>
#include "graph.h"
using namespace std;
//Auxilary function used to copy a dynamic array onto another, deletes array1[] from memory
int* copyArray(int array1[], int nElem) {
	int* retArray = new int[nElem];
	for (int i = 0; i < nElem -1; i++) {
		retArray[i] = array1[i];
	}
	delete[] array1;
	return retArray;
}
int main() {

	
	ifstream file;
	string fileName;

	cout << "Type in the name of the file you'd like to open (only admits .dat extensions):\n";

	cin >> fileName;
	fileName += ".dat";


	file.open(fileName);
	if (file.is_open()) {
		int aux, counter = 0;
		int* values = new int[counter];
		while (file >> aux)
		{
			counter++;
			values = copyArray(values, counter);
			values[counter - 1] = aux;
		}
		file.close();
		drawGraph(counter, values);
		delete[] values;
	}

	else cout << "File " << fileName << " does not exist or couldn't be opened" << endl;
	
	return 0;
}
