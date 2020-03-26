#include "function.h"

Func::Func(int number, chromosome chro){
	switch (number)
	{
	case 1:
		value = function_one(chro);
		break;
	case 2:
		value = function_two(chro);
		break;
	case 3:
		value = function_three(chro);
		break;
	case 4:
		value = function_four(chro);
		break;
	case 5:
		value = function_five(chro);
		break;
	case 6:
		value = function_six(chro);
		break;
	case 7:
		value = function_seven(chro);
		break;
	case 8:
		value = function_eight(chro);
		break;
	case 9:
		value = function_nine(chro);
		break;
	case 10:
		value = function_ten(chro);
		break;
	case 11:
		value = function_eleven(chro);
		break;
	case 12:
		value = function_twelve(chro);
		break;
	case 13:
		value = function_thirteen(chro);
		break;
	case 14:
		value = function_fourteen(chro);
		break;
	case 15:
		value = function_fifteen(chro);
		break;
	}
}
/*
生成0-1的随机数(double)
*/
double Func::get_0_1_random(){
	random_device rd;
	double a = double((rd() * 6553) % 100000) / 100000;
	return a;
}

/*
生成1-A的随机数(int)
*/
int Func::get_1_A_random(int A){
	random_device rd;
	int a = rd() % A + 1;
	return a;
}

/*
生成min - max的随机数(double)
*/
double Func::get_min_max_random(double min, double max){
	double demo = get_0_1_random();
	return min + (max - min)*demo;
}

/*
测试函数function one
*/
double Func::function_one(chromosome chro){
	int len = chro.S_chromosome.size();
	double ans = 0, demo = 0, word;
	for (int i = 0; i < len; i++){
		word = chro.S_chromosome[i];
		demo = -1 * word*sin(sqrt(abs(word)));
		ans += demo;
	}
	//chro.S_value = ans;
	return ans;
}

/*
测试函数function two
*/
double Func::function_two(chromosome chro){
	int len = chro.S_chromosome.size();
	double ans = 0, demo = 0;
	for (int i = 0; i < len; i++){
		demo = pow(chro.S_chromosome[i], 2) - 10 * cos(2 * PI *chro.S_chromosome[i]) + 10;
		ans += demo;
	}
	//chro.S_value = ans;
	return ans;
}

/*
测试函数function three
*/
double Func::function_three(chromosome chro){
	int len = chro.S_chromosome.size();
	double ans = 0, demo_one = 0, demo_two = 0, demo = 0;
	for (int i = 0; i < len; i++){
		demo = pow(chro.S_chromosome[i], 2);
		demo_one += demo;
		demo = cos(2 * PI*chro.S_chromosome[i]);
		demo_two += demo;
	}
	ans = -20 * exp(-0.2*sqrt(demo_one / len)) - exp(demo_two / len) + 20 + exp(1);
	//chro.S_value = ans;
	return ans;
}

/*
测试函数function four
*/
double Func::function_four(chromosome chro){
	int len = chro.S_chromosome.size();
	double demo_one = 0, demo_two = 1.0;
	for (int i = 0; i < len; i++){
		demo_one += pow(chro.S_chromosome[i], 2);
		demo_two *= cos(chro.S_chromosome[i] / sqrt(i+1));
	}
	return demo_one / 4000 - demo_two + 1;
}

/*
测试函数function fives
*/
double Func::function_five(chromosome chro){
	int len = chro.S_chromosome.size();
	chromosome y;
	double u = 0, demo = 0, demo_one = 0, demo_two = 0, demo_three = 0, ans = 0;
	for (int i = 0; i < len; i++){
		demo = 1 + (chro.S_chromosome[i] + 1) / 4;
		y.S_chromosome.push_back(demo);
	}
	for (int i = 0; i < len - 1; i++){
		demo = pow(y.S_chromosome[i] - 1, 2)* (1 + 10 * pow(sin(PI*y.S_chromosome[i + 1]), 2));
		demo_two += demo;
	}
	demo_one = pow(sin(PI*y.S_chromosome[0]), 2) * 10;
	for (int i = 0; i < len; i++){
		if (chro.S_chromosome[i] < -10)
			demo_three += 100 * pow((-chro.S_chromosome[i] - 10), 4);
		else if (chro.S_chromosome[i] > 10)
			demo_three += 100 * pow((chro.S_chromosome[i] - 10), 4);
		else
			demo_three += 0;
	}
	ans = (demo_one + demo_two + pow(y.S_chromosome[len - 1] - 1, 2)) * PI / len + demo_three;
	return ans;
}

/*
测试函数function six
*/
double Func::function_six(chromosome chro){
	double demo_one, demo_two = 0, demo_three = 0, demo_four = 0;
	int len = chro.S_chromosome.size();

	demo_one = pow(3 * PI*chro.S_chromosome[0], 2);
	for (int i = 0; i < len - 1; i++){
		double demo = pow(chro.S_chromosome[i] - 1, 2)*(1 + pow(sin(3 * PI*chro.S_chromosome[i + 1]), 2));
		demo_two += demo;
	}
	demo_three = pow(chro.S_chromosome[len - 1] - 1, 2)*(1 + pow(sin(2 * PI*chro.S_chromosome[len - 1]), 2));
	for (int i = 0; i < len; i++){
		if (chro.S_chromosome[i] < -10)
			demo_four += 100 * pow((-chro.S_chromosome[i] - 5), 4);
		else if (chro.S_chromosome[i] > 10)
			demo_four += 100 * pow((chro.S_chromosome[i] - 5), 4);
		else
			demo_four += 0;
	}

	return ((demo_one + demo_two + demo_three) / 10 + demo_four);
}

/*
测试函数function seven
*/
double Func::function_seven(chromosome chro){
	double demo_one = 0, demo_two = 0;
	int len = chro.S_chromosome.size();

	for (int i = 0; i < len; i++){
		demo_one += sin(chro.S_chromosome[i])*pow(sin((i + 1)*pow(chro.S_chromosome[i], 2)) / PI, 20);
	}
	return -1 * demo_one;
}

/*
测试函数function eight
*/
double Func::function_eight(chromosome chro){
	int len = chro.S_chromosome.size();
	double X_ij, Y_ij, W_j, demo_one = 0, demo_two = 0, demo_three = 0;
	for (int i = 0; i < len; i++){
		for (int j = 0; j < len; j++){
			X_ij = get_min_max_random(-100, 100);
			Y_ij = get_min_max_random(-100, 100);
			W_j = get_min_max_random(-PI, PI);

			demo_one += (X_ij * sin(W_j) + Y_ij*cos(W_j));
			demo_two += (X_ij * sin(chro.S_chromosome[j]) + Y_ij*cos(chro.S_chromosome[j]));
		}
		demo_three += pow(demo_one - demo_two, 2);
	}
	return demo_three;
}

/*
测试函数function nine
*/
double Func::function_nine(chromosome chro){
	int len = chro.S_chromosome.size();
	double demo_one = 0, demo;
	for (int i = 0; i < len; i++){
		demo = chro.S_chromosome[i];
		demo_one += pow(demo, 4) - 16 * pow(demo, 2) + 5 * demo;
	}
	return demo_one / len;
}

/*
测试函数function ten
*/
double Func::function_ten(chromosome chro){
	int len = chro.S_chromosome.size();
	double demo = 0;
	for (int i = 0; i < len - 1; i++){
		demo += 100 * pow(chro.S_chromosome[i] - chro.S_chromosome[i + 1], 2) + pow(chro.S_chromosome[i] - 1, 2);
	}
	return demo;
}

/*
测试函数function eleven
*/
double Func::function_eleven(chromosome chro){
	int len = chro.S_chromosome.size();
	double demo = 0;
	for (int i = 0; i < len; i++){
		demo += pow(chro.S_chromosome[i], 2);
	}
	return demo;
}

/*
测试函数function twelve
*/
double Func::function_twelve(chromosome chro){
	int len = chro.S_chromosome.size();
	double demo = 0;
	for (int i = 0; i < len; i++){
		demo += pow(chro.S_chromosome[i], 4);
	}
	return demo + get_0_1_random();
}

/*
测试函数function thirteen
*/
double Func::function_thirteen(chromosome chro){
	int len = chro.S_chromosome.size();
	double demo_one = 0, demo_two = 1;
	for (int i = 0; i < len; i++){
		demo_one += abs(chro.S_chromosome[i]);
		demo_two *= abs(chro.S_chromosome[i]);
	}
	return demo_one + demo_two;
}

/*
测试函数function fourteen
*/
double Func::function_fourteen(chromosome chro){
	int len = chro.S_chromosome.size();
	double demo = 0, demo_two = 0;
	for (int i = 0; i < len; i++){
		demo = 0;
		for (int j = 0; j <= i; i++){
			demo += chro.S_chromosome[i];
		}
		demo_two += pow(demo, 2);
	}
	return demo_two;
}

/*
测试函数function fifteen
*/
double Func::function_fifteen(chromosome chro){
	int len = chro.S_chromosome.size();
	double answer = 0;
	for (int i = 0; i < len; i++){
		if (answer < abs(chro.S_chromosome[i]))
			answer = abs(chro.S_chromosome[i]);
	}
	return answer;
}

/*
获取value的值
*/
double Func::getValue(){
	return value;
}