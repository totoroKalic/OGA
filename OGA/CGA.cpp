#include "CGA.h"
#include "OGA.h"
#include "function.h"

/*
��GA�ĳ�ʼ��
*/
CGA::CGA(int function_num, int n, double Pc, double Pm) {
	Function_num = function_num;
	N = n;
	pc = Pc;
	pm = Pm;
}

/*
//��ȡȾɫ���Ȩֵ
*/
double CGA::getValue(chromosome demo) {
	Func num(Function_num, demo);
	return num.getValue();
}

/*
������ʼ��Ⱥ
*/
void CGA::buildinitPoption(double range_left, double range_right) {
	//step -- one ��ʼ��
	c_pool.clear();
	double ran_number, demo_value;
	chromosome demo_chro;

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < N; j++) {
			ran_number = Func::get_min_max_random(range_left, range_right);
			demo_chro.S_chromosome.push_back(ran_number);
		}
		demo_value = getValue(demo_chro);
		demo_chro.S_value = demo_value;
		c_pool.push_back(demo_chro);
	}
	selectChild();
}

/*
Ⱦɫ��ѡ�����������������
*/
void CGA::buildChild(chromosome parent_one, chromosome parent_two, double range_left, double range_right) {
	chromosome demo_chro;
	double demo_value, ran_number;
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < N; i++) {
			ran_number = Func::get_min_max_random(min(parent_one.S_chromosome[i], parent_two.S_chromosome[i]), max(parent_one.S_chromosome[i], parent_two.S_chromosome[i]));
			demo_chro.S_chromosome.push_back(ran_number);
		}
		double Pm = Func::get_0_1_random();
		if (Pm <= pm) {
			int position = Func::get_1_A_random(N);
			double words = Func::get_min_max_random(range_left, range_right);
			demo_chro.S_chromosome[position - 1] = words;
		}
		demo_value = getValue(demo_chro);
		demo_chro.S_value = demo_value;

		c_pool.push_back(demo_chro);
	}
}

/*
ѡ��һ��Ⱦɫ����Ϊ����Ⱦɫ��
*/
bool CGA::chooseParents() {
	Select_pool.clear();
	int len = c_pool.size();
	for (int i = 0; i < len; i++) {
		double demo = Func::get_0_1_random();
		if (demo <= pc) {
			Select_pool.push_back(c_pool[i]);
		}
	}
	int Select_len = Select_pool.size();
	if (Select_len <= 1)
		return false;
	else
		return true;
}

//?
/*
��c_poolѡ����С��S����Ⱥ
*/
void CGA::selectChild() {
	sort(c_pool.begin(), c_pool.end(), cmp);
	c_pool.erase(c_pool.begin() + G, c_pool.end());
}


/*
��ʼ�Ŵ�����
*/
void CGA::run(int Maxnum, int steps, double range_left, double range_right) {
	//step -- one ��ʼ��
	chromosome parent_one, parent_two;
	buildinitPoption(range_left, range_right);

	for (int i = 0; i < Maxnum; i++) {
		if (chooseParents() == true) {
			if (Select_pool.size() % 2 == 1) {
				for (unsigned int i = 1; i < ((Select_pool.size() - 1) / 2); i++) {
					parent_one = Select_pool[i];
					parent_two = Select_pool[Select_pool.size() - i];
					buildChild(parent_one, parent_two, range_left, range_right);
				}
			}
			else {
				for (unsigned int i = 0; i < Select_pool.size() / 2; i++) {
					parent_one = Select_pool[i];
					parent_two = Select_pool[Select_pool.size() - i - 1];
					buildChild(parent_one, parent_two, range_left, range_right);
				}
			}
		}
		selectChild();
		/*
		double dddd = 0;
		for (int ll = 0; ll < G; ll++)
			dddd += c_pool[ll].S_value;
		Tu.push_back(dddd / G);
		*/
	}
	int over_count = 0;
	while (true) {
		double last = c_pool[0].S_value;
		double now = 0;
		int flag = 0;	//flag = 1ʱ��˵���ں�50�����н�һ����СȾɫ��ɱ�
		for (int i = 0; i < steps; i++) {
			over_count++;
			if (chooseParents() == true) {
				if (Select_pool.size() % 2 == 1) {
					for (unsigned int i = 1; i < (Select_pool.size() - 1) / 2; i++) {
						parent_one = Select_pool[i];
						parent_two = Select_pool[Select_pool.size() - i];
						buildChild(parent_one, parent_two, range_left, range_right);
					}
					selectChild();
					/*
					double dddd = 0;
					for (int ll = 0; ll < G; ll++)
						dddd += c_pool[ll].S_value;
					Tu.push_back(dddd / G);
					*/
				}
				else {
					for (unsigned int i = 0; i < Select_pool.size() / 2; i++) {
						parent_one = Select_pool[i];
						parent_two = Select_pool[Select_pool.size() - i - 1];
						buildChild(parent_one, parent_two, range_left, range_right);
					}
					selectChild();
					/*
					double dddd = 0;
					for (int ll = 0; ll < G; ll++)
						dddd += c_pool[ll].S_value;
					Tu.push_back(dddd / G);
					*/
				}
				now = c_pool[0].S_value;
				if (now < last)
					flag = 1;
			}
			else
				continue;
		}
		if (flag == 0) {
			//cout << "*****************" << over_count << endl;
			break;
		}
	}
}

/*
���Ⱦɫ�������ŵ�Ȩֵ
*/
double CGA::get_best_value() {
	return c_pool[0].S_value;
}

/*
������ŵ���Ⱥ
*/
chromosome CGA::get_best_chro() {
	return c_pool[0];
}

/*
�����ε�����function evaluations
*/
int CGA::get_func_evalua() {
	return chro_count;
}

/*
չʾȾɫ��
*/
void CGA::showChromosome() {
	int len = c_pool.size();
	//cout <<"_______________"<< c_pool[1].S_chromosome.size()<<endl;
	//cout << endl;
	for (int i = 0; i < len; i++) {
		/*
		int len_two = c_pool[i].S_chromosome.size();
		for (int j = 0; j < len_two; j++){
		cout << c_pool[i].S_chromosome[j] << "    ";
		}
		*/
		cout << c_pool[i].S_value;
		cout << endl;
	}
}

void CGA::print() {
	ofstream ofile;
	ofile.open("E:\\data.txt");
	int len = Tu.size();
	for (int i = 0; i < len; i++) {
		ofile << i << "," << Tu[i] << endl;
	}
	ofile.close();
}