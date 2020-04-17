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
	void run(int Maxnum, int steps, double range_left, double range_right);            //��ʼ����
	double get_best_value();	    //���Ⱦɫ�������ŵ�Ȩֵ
	chromosome get_best_chro();	    //������ŵ���Ⱥ
	int get_func_evalua();			//�����ε�����function evaluations
	void print();
private:
	int G = 200;	// ��Ⱥ��ģ
	double pc;		// �������
	double pm;		// �������
	int Function_num;
	int func_evalue = 0;
	int N;			//������ά�ȣ�LM2��F,J_two
	int S;
	int LM1_row, LM1_col, LM2_row, LM2_col;       //LM1��LM2����ĺ���
	Func num;

	pool c_pool;				//G��Ⱥ��
	pool Select_pool;			//ѡ���ĸ����洢��
	pool Poption_pool;
	bool chooseParents();		//ѡ��һ��Ⱦɫ��
	void selectChild();			//��c_poolѡ����С��S����Ⱥ
	void buildinitPoption(double range_left, double range_right);    //���ɳ�ʼ��Ⱥ
	void buildChild(chromosome parent_one, chromosome parent_two, double range_left, double range_right);	 //�����������ɺ��
	void showChromosome();			//չʾȾɫ��
	double getValue(chromosome demo);				//��ȡȾɫ���ֵ
};
/*
inline bool cmp(chromosome A, chromosome B) {
	return A.S_value < B.S_value;
}
*/