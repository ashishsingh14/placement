#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <assert.h>
#include <map>
#include <math.h>
using namespace std;
int noofwaystoreachscore(int *, int,int );


char* addgeneralbase(char * str1, char* str2, int base);
int converttonumber(char a);
char converttochar(int a);

void multiply(int F[2][2], int M[2][2]);
void powermatrix(int F[2][2], int n);
void power(int F, int n);
int getperiod(int n);
int countnumberoffour(int n, int *arr, int size );
#endif // FUNCTIONS_H
