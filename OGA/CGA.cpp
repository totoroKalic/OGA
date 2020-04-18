#include "CGA.h"
#include "OGA.h"
#include "function.h"

/*
��GA�ĳ�ʼ��
*/
CGA::CGA(int function_num, int n, double Pc, double Pm) {
	num.getNum(function_num);
	Function_num = function_num;
	N = n;
	pc = Pc;
	pm = Pm;
}

/*
//��ȡȾɫ���Ȩֵ
*/
double CGA::getValue(chromosome demo) {
	func_evalue++;
	return num.getValue(demo);
}

/*
������ʼ��Ⱥ
*/
void CGA::buildinitPoption(double range_left, double range_right) {
	//step -- one ��ʼ��
	c_pool.clear();
	double ran_number, demo_value;

	if (range_right - range_left <= 100)
		S = 10;
	else
		S = 20;

	for (int z = 1; z <= S; z++) {
		double left, right, single;
		single = (range_right - range_left) / S;
		left = range_left + (z - 1) * single;
		right = range_right - (S - z)*single;
		for (int i = 1; i <= G; i++) {
			chromosome demo_chro;
			for (int j = 0; j < N; j++) {
				ran_number = num.get_min_max_random(left, right);
				demo_chro.S_chromosome.push_back(ran_number);
			}
			demo_value = getValue(demo_chro);
			demo_chro.S_value = demo_value;
			c_pool.push_back(demo_chro);
		}
	}
	selectChild();
	Tu.push_back(c_pool[0].S_value);
}

/*
Ⱦɫ��ѡ�����������������
*/
void CGA::buildChild(chromosome parent_one, chromosome parent_two, double range_left, double range_right) {
	double demo_value, ran_number;
	for (int j = 0; j < S; j++) {
		chromosome demo_chro;
		for (int i = 0; i < N; i++) {
			ran_number = num.get_min_max_random(min(parent_one.S_chromosome[i], parent_two.S_chromosome[i]), max(parent_one.S_chromosome[i], parent_two.S_chromosome[i]));
			demo_chro.S_chromosome.push_back(ran_number);
		}
		double Pm = num.get_0_1_random();
		if (Pm <= pm) {
			int position = num.get_1_A_random(N);
			double words = num.get_min_max_random(range_left, range_right);
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
		double demo = num.get_0_1_random();
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
		Tu.push_back(c_pool[0].S_value);
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
				}
				else {
					for (unsigned int i = 0; i < Select_pool.size() / 2; i++) {
						parent_one = Select_pool[i];
						parent_two = Select_pool[Select_pool.size() - i - 1];
						buildChild(parent_one, parent_two, range_left, range_right);
					}
				}
				selectChild();
				Tu.push_back(c_pool[0].S_value);
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
	print();
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
	return func_evalue;
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
