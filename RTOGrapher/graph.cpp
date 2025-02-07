#include "graph.h"
#include <math.h>

void drawGraph(int size,const int points[]) {
	//Opens gnuplot's pipe
	FILE* gnupipe = NULL;
	gnupipe = _popen("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" -persist", "w");
	
	//Sets the title for the whole graph
	fprintf(gnupipe, "%s\n", "set title \"Jacobson-Karels\"");

	//Creates tmp files for the graph
	drawPoints(size, points);
	drawJacobson(size, points);

	//Sets the commands for gnuplot. Can be modified in style and name through changing the String literal.
	fprintf(gnupipe, "plot 'puntos.tmp' with points pointtype 1 linecolor rgb \"green\" title 'Values', \\\n");
	fprintf(gnupipe, "     'jacobson.tmp' using 1:2 smooth csplines with lines linecolor rgb \"red\" title 'Jacobson', \\\n");
	fprintf(gnupipe, "     'jacobsonkarels.tmp' using 1:2 smooth csplines with lines linecolor rgb \"blue\" title 'Jacobson-Karels'\n");
	_pclose(gnupipe);
	return;
}

void drawJacobsonKarels(int size,const int points[], const float jacobson[]) {
	//writes results in jacobsonkarels.tmp
	FILE* output = fopen("jacobsonkarels.tmp", "w");
	float* jacobsonkarels = new float[size];
	const float beta = 1.0/4.0;
	jacobsonkarels[0] = points[0] / 2;
	for (int i = 1; i < size; i++) {
		//jacobsonkarel's formula
		jacobsonkarels[i] = (1 - beta) * jacobsonkarels[i - 1] + beta * abs(points[i-1] - jacobson[i-1]);
		//RTO = jacobson[i] + 4*jacobsonkarels[i]
		fprintf(output, "%d %f\n", i, jacobson[i] + 4*jacobsonkarels[i]);
	}
	delete[] jacobsonkarels;
	fclose(output);
}

void drawJacobson(int size,const int points[]) {
	//writes results in jacobson.tmp
	FILE* output = fopen("jacobson.tmp", "w");
	float* jacobson = new float[size];
	const float alpha = 1.0 / 8.0;
	jacobson[0] = points[0];

	for (int i = 1; i < size; i++) {
		jacobson[i] = (1 - alpha) * jacobson[i - 1] + alpha * points[i];
		//RTO = 2*jacobson[i]
		fprintf(output, "%d %f\n", i, 2*jacobson[i]);
	}
	//jacobson[] is needed to calculate jacolson-karels
	drawJacobsonKarels(size, points,jacobson);
	delete[] jacobson;
	fclose(output);
}
void drawPoints(int size,const int points[]) {
	FILE* output = fopen("puntos.tmp", "w");
	for (int i = 0; i < size; i++) {
		//just takes the different entries from the file and asigns them an x so f(x) = entry
		fprintf(output, "%d %d\n", i, points[i]);
	}

	fclose(output);
}
