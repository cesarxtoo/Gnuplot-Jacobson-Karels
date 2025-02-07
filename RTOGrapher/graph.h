#pragma once
#include <iostream>
#include <stdio.h>
//Opens gnupipe, calls the different module's functions and calls gnuplot to draw the graph
void drawGraph(int size,const int points[]);
//Prepares the file for the different times
void drawPoints(int size,const int points[]);
//Prepares the file for jacobsons algorithm. Will always call drawJacobsonKarels because of laziness
void drawJacobson(int size,const int points[]);
//Prepares the file for jacobsons-karels algorithm given jacobson[] that has already been calculated from 0->size1-1
void drawJacobsonKarels(int size,const int points[],const float jacobson[]);