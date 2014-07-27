#pragma once

#include <math.h>

struct Polynomial{
	unsigned int nTerms;
	double terms[4];

	Polynomial();

	Polynomial(double a, double b, double c, double d);

	double operator()(double x);
};

int clamp(int x, int min, int max);
float clamp(float x, float min, float max);
double clamp(double x, double min, double max);
