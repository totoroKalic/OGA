#pragma once
#include <math.h>
#include "chromosome.h"
#include <random>

#define PI 3.14159265358979323846

class Func{
public:
	Func();
	int Num;
	void getNum(int number);
	double getValue(chromosome chro);
	double get_0_1_random();
	int get_1_A_random(int A);
	double get_min_max_random(double min, double max);
private:
	double X[101][101];
	double Y[101][101];
	double Z[101];

	double function_one(chromosome chro);
	double function_two(chromosome chro);
	double function_three(chromosome chro);
	double function_four(chromosome chro);
	double function_five(chromosome chro);
	double function_six(chromosome chro);
	double function_seven(chromosome chro);
	double function_eight(chromosome chro);
	double function_nine(chromosome chro);
	double function_ten(chromosome chro);
	double function_eleven(chromosome chro);
	double function_twelve(chromosome chro);
	double function_thirteen(chromosome chro);
	double function_fourteen(chromosome chro);
	double function_fifteen(chromosome chro);
};