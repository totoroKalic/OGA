#include <vector>
#include <cstring>
#include <memory>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
#include "chromosome.h"
#include "function.h"

class CGA {
public:
	vector<double> Tu;

	CGA(int function_num, int N, double pc, double pm);
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
	int N;			//函数的维度，LM2的F,J_two
	int S;
	int LM1_row, LM1_col, LM2_row, LM2_col;       //LM1和LM2数组的横纵
	Func num;

	pool c_pool;				//G种群池
	pool Select_pool;			//选择后的父代存储池
	pool Poption_pool;
	bool chooseParents();		//选择一个染色体
	void selectChild();			//对c_pool选择最小的S个种群
	void buildinitPoption(double range_left, double range_right);    //生成初始种群
	void buildChild(chromosome parent_one, chromosome parent_two, double range_left, double range_right);	 //正交量化生成后代
	void showChromosome();			//展示染色体
	double getValue(chromosome demo);				//获取染色体的值
};
/*
inline bool cmp(chromosome A, chromosome B) {
	return A.S_value < B.S_value;
}
*/