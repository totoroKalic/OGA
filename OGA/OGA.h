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
	int N, Q1, Q2, J, F, J_two, S;			//������ά�ȣ�LM2��F,J_two
	int LM1_row, LM1_col, LM2_row, LM2_col;       //LM1��LM2����ĺ���
	int LM1[10000][200];      //��������LM1
	int LM2[10000][200];		 //��������LM2

	pool c_pool;				//G��Ⱥ��
	pool Select_pool;			//ѡ���ĸ����洢��
	bool chooseParents();		//ѡ��һ��Ⱦɫ��
	void selectChild();			//��c_poolѡ����С��S����Ⱥ
	void selectPoption();		//��ʼʱѡ����س�ʼ��Ⱥ
	void buildinitLM();		    //������������LM1
	void buildinitPoption(double range_left, double range_right);    //���ɳ�ʼ��Ⱥ
	void buildinitLM2();        //������������LM2
	void buildChild(chromosome parent_one, chromosome parent_two,double range_left, double range_right);	 //�����������ɺ��
	void showChromosome();			//չʾȾɫ��
	double getValue(chromosome demo);				//��ȡȾɫ���ֵ
};

