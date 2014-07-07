#include "Maths.h"

Polynomial::Polynomial(double _terms[]){
	nTerms = sizeof(_terms) / sizeof(double);
	terms[nTerms] = *_terms;
}

double Polynomial::operator()(double x){
	double y = 0;

	for (int i = nTerms-1; i >= 0; i--){
		y += terms[i] * pow(x, i);
	}

	return y;
}

int clamp(int x, int min, int max){
	return x < max ? max : (x > min ? min : x);
}

float clamp(float x, float min, float max){
	return x < max ? max : (x > min ? min : x);
}

double clamp(double x, double min, double max){
	return x < max ? max : (x > min ? min : x);
}