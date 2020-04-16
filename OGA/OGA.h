#include <vector>
#include <cstring>
#include <memory>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
#include "chromosome.h"

class OGA{
public:
	vector<double> Tu;

	OGA(int function_num,int N, int Q1, int Q2, int F, double pc, double pm);
	void run(int Maxnum, int steps, double range_left, double range_right);            //开始迭代
	double get_best_value();	    //获得染色体中最优的权值
	chromosome get_best_chro();	    //获得最优的种群
	int get_func_evalua();			//获得这次迭代的function evaluations
	void print();

private:
	int G = 200;	// 种群规模
	double pc;		// 交叉概率
	double pm;		// 变异概率
	int Function_num;
	int func_evalue = 0;
	int N, Q1, Q2, J, F, J_two, S;			//函数的维度，LM2的F,J_two
	int LM1_row, LM1_col, LM2_row, LM2_col;       //LM1和LM2数组的横纵
	int LM1[10000][200];      //正交数组LM1
	int LM2[10000][200];		 //正交数组LM2

	pool c_pool;				//G种群池
	pool Select_pool;			//选择后的父代存储池
	bool chooseParents();		//选择一个染色体
	void selectChild();			//对c_pool选择最小的S个种群
	void selectPoption();		//初始时选择相关初始种群
	void buildinitLM();		    //构造正交数组LM1
	void buildinitPoption(double range_left, double range_right);    //生成初始种群
	void buildinitLM2();        //构造正交数组LM2
	void buildChild(chromosome parent_one, chromosome parent_two,double range_left, double range_right);	 //正交量化生成后代
	void showChromosome();			//展示染色体
	double getValue(chromosome demo);				//获取染色体的值
};

