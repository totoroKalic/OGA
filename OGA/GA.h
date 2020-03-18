#include <vector>
#include <cstring>
#include <memory>
#include <random>
#include <algorithm>
#include <iostream>
#include "chromosome.h"
#include <math.h>

#define PI 3.14159265

class GA{
public:
	GA(int N, int Q1, int Q2, int F, double pc, double pm);

	void run(int Maxnum, int steps, double range_left, double range_right);            //��ʼ����
	double get_best_value();	    //���Ⱦɫ�������ŵ�Ȩֵ
	chromosome get_best_chro();	    //������ŵ���Ⱥ
	int get_func_evalua();			//�����ε�����function evaluations
	void build();
private:
	int G = 200;	// ��Ⱥ��ģ
	double pc;		// �������
	double pm;		// �������
	int chro_count = 0;
	int N, Q1, Q2, J, F, J_two, S;			//������ά�ȣ�LM2��F,J_two
	int LM1_row, LM1_col, LM2_row, LM2_col;       //LM1��LM2����ĺ���
	int LM1[1000][200];      //��������LM1
	int LM2[1000][200];		 //��������LM2

	pool c_pool;				//G��Ⱥ��
	pool Select_pool;			//ѡ���ĸ����洢��
	bool chooseParents();		//ѡ��һ��Ⱦɫ��
	void selectChild();			//��c_poolѡ����С��S����Ⱥ
	void buildinitLM();		    //������������LM1
	void buildinitPoption(double range_left, double range_right);    //���ɳ�ʼ��Ⱥ
	void buildinitLM2();        //������������LM2
	void buildChild(chromosome parent_one, chromosome parent_two);	 //�����������ɺ��
	void showChromosome();			//չʾȾɫ��

};

/*
����0-1�������(double)
*/
double get_0_1_random(){
	random_device rd;
	double a = double((rd() * 6553) % 100000) / 100000;
	return a;
}

/*
����1-A�������(int)
*/
int get_1_A_random(int A){
	random_device rd;
	int a = rd() % A + 1;
	return a;
}

/*
����min - max�������(double)
*/
double get_min_max_random(double min, double max){
	double demo = get_0_1_random();
	return min + (max - min)*demo;
}

/*
Ⱦɫ������
*/
bool cmp(chromosome A, chromosome B){
	return A.S_value < B.S_value;
}

/*
���Ժ���function one
*/
double function_one(chromosome chro){
	int len = chro.S_chromosome.size();
	double ans = 0, demo = 0;
	for (int i = 0; i < len; i++){
		demo = (sin(sqrt(abs(chro.S_chromosome[i])) * (-1)*chro.S_chromosome[i]));
		ans += demo;
	}
	//chro.S_value = ans;
	return ans;
}


/*
���Ժ���function two
*/
inline double function_two(chromosome chro){
	int len = chro.S_chromosome.size();
	double ans = 0, demo = 0;
	for (int i = 0; i < len; i++){
		demo = pow(chro.S_chromosome[i], 2) - 10 * cos(2 * PI*chro.S_chromosome[i]) + 10;
		ans += demo;
	}
	//chro.S_value = ans;
	return ans;
}

/*
���Ժ���function three
*/
inline double function_three(chromosome chro){
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
���Ժ���function four
*/
inline double function_four(chromosome chro){
	int len = chro.S_chromosome.size();
	double ans = 0, demo_one = 0, demo_two = 1, demo = 0;
	for (int i = 0; i < len; i++){
		demo = pow(chro.S_chromosome[i], 2);
		demo_one += demo;
		demo = cos(chro.S_chromosome[i] / sqrt(i));
		demo_two *= demo;
	}
	ans = demo_one / 4000 - demo_two + 1;
	//chro.S_value = ans;
	return ans;
}

/*
���Ժ���function fives
*/
inline double function_five(chromosome chro){
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
		demo = pow(sin(PI*y.S_chromosome[i]), 2) * 10;
		demo_one += demo;
	}
	demo_one += pow(sin(PI*y.S_chromosome[len - 1]), 2) * 10;
	for (int i = 1; i < len; i++){
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