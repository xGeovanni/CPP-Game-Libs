#include "Maths.h"

Polynomial::Polynomial() {};

Polynomial::Polynomial(double a, double b, double c, double d){
	terms[0] = a;
	terms[1] = b;
	terms[2] = c;
	terms[3] = d;

	nTerms = 4;
}

double Polynomial::operator()(double x){
	double y = 0;

	for (int i = nTerms-1; i >= 0; i--){
		y += terms[i] * pow(x, i);
	}

	return y;
}

int clamp(int x, int min, int max){
	return x < min ? min : (x > max ? max : x);
}

float clamp(float x, float min, float max){
	return x < min ? min : (x > max ? max : x);
}

double clamp(double x, double min, double max){
	return x < min ? min : (x > max ? max : x);
}