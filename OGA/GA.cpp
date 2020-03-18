#include "GA.h"

/*
类GA的初始化
*/
GA::GA(int n, int q1, int q2, int f, double Pc, double Pm){
	N = n;
	Q1 = q1;
	Q2 = q2;
	F = f;
	pc = Pc;
	pm = Pm;
}

/*
生成初始正交数组LM1
*/
void GA::buildinitLM(){
	//step -- one
	int N_demo;		//N`的值和J的值
	int row, col;
	for (int i = 1;; i++){
		if ((pow(Q1, i) - 1) / (Q1 - 1) >= N){
			J = i;
			break;
		}
	}
	//step -- two
	if ((pow(Q1, J) - 1) / (Q1 - 1) == N)
		N_demo = N;
	else
		N_demo = (int)((pow(Q1, J) - 1) / (Q1 - 1)) + 1;

	row = pow(Q1, J) + 1;
	col = (pow(Q1, J) - 1) / (Q1 - 1) + 1;
	int **LM = new int *[row];
	for (int i = 0; i < row; ++i)
		LM[i] = new int[col]();

	//step -- three
	//compute the basic columns
	for (int k = 1; k <= J; k++){
		col = (pow(Q1, k - 1) - 1) / (Q1 - 1) + 1;
		for (row = 1; row <= pow(Q1, J); row++){
			int number = ((row - 1) / (pow(Q1, J - k)));
			LM[row][col] = number % Q1;
		}
	}

	//compute the non basic columns
	for (int k = 2; k <= J; k++){
		col = (pow(Q1, k - 1) - 1) / (Q1 - 1) + 1;
		for (int s = 1; s <= col - 1; s++){
			for (int t = 1; t <= Q1 - 1; t++){
				//进行列的处理
				int x = col + (s - 1)*(Q1 - 1) + t;
				for (int rol = 1; rol <= pow(Q1, J); rol++)
					LM[rol][x] = (LM[rol][s] * t + LM[rol][col]) % Q1;
			}
		}
	}

	//step -- 4
	LM1_row = pow(Q1, J);
	LM1_col = N;

	for (int i = 1; i <= LM1_row; i++)
		for (int j = 1; j <= LM1_col; j++)
			LM1[i][j] = LM[i][j] + 1;
}

/*
生成初始正交数组LM2
*/
void GA::buildinitLM2(){
	//step -- one
	int F_demo;		//F`的值和J的值
	int row, col;
	for (int i = 1;; i++){
		if ((pow(Q2, i) - 1) / (Q2 - 1) >= F){
			J_two = i;
			break;
		}
	}

	//step -- two
	if ((pow(Q2, J_two) - 1) / (Q2 - 1) == F)
		F_demo = F;
	else
		F_demo = (int)((pow(Q2, J_two) - 1) / (Q2 - 1)) + 1;
	//创建数组
	row = pow(Q2, J_two) + 1;
	col = (pow(Q2, J_two) - 1) / (Q2 - 1) + 1;
	int **LM = new int *[row];
	for (int i = 0; i < row; ++i)
		LM[i] = new int[col]();

	//step -- three
	//compute the basic columns
	for (int k = 1; k <= J_two; k++){
		col = (pow(Q2, k - 1) - 1) / (Q2 - 1) + 1;
		for (row = 1; row <= pow(Q2, J_two); row++){
			int number = ((row - 1) / (pow(Q2, J_two - k)));
			LM[row][col] = number % Q2;
		}
	}
	//compute the non basic columns
	for (int k = 2; k <= J_two; k++){
		col = (pow(Q2, k - 1) - 1) / (Q2 - 1) + 1;
		for (int s = 1; s <= col - 1; s++){
			for (int t = 1; t <= Q2 - 1; t++){
				//进行列的处理
				int x = col + (s - 1)*(Q2 - 1) + t;
				for (int rol = 1; rol <= pow(Q2, J_two); rol++){
					LM[rol][x] = (LM[rol][s] * t + LM[rol][col]) % Q2;
				}
			}
		}
	}
	//step -- 4
	LM2_row = pow(Q2, J_two);
	LM2_col = F;

	for (int i = 1; i <= LM2_row; i++)
		for (int j = 1; j <= LM2_col; j++)
			LM2[i][j] = LM[i][j] + 1;
}

/*
产生初始种群
维度：D = N
分成子空间：S
*/
void GA::buildinitPoption(double range_left, double range_right){
	//step -- one 初始化
	double range[101][3];

	for (int i = 1; i <= N; i++){
		range[i][1] = range_left;
		range[i][2] = range_right;
	}
	//step -- two 分成S个子空间，第一个代表维度
	//本应该取最大的空间划分，这里都一样...随机取一个
	/*
	int max = 0, demo_flag = 0;
	for (int i = 1; i <= D; i++){
	int demo;
	demo = range[i][2] - range[i][1];
	if (demo >= max){
	demo_flag = i;
	max = demo;
	}
	}
	*/
	int demo_flag = get_1_A_random(N);
	for (int i = 1; i <= S; i++){
		double Subrange[101][3];
		for (int j = 1; j <= N; j++){
			if (j == demo_flag){
				Subrange[j][1] = range[j][1] + (i - 1)*((range[j][2] - range[j][1]) / S);
				Subrange[j][2] = range[j][2] - (S - i)*((range[j][2] - range[j][1]) / S);
			}
			else{
				Subrange[j][1] = range[j][1];
				Subrange[j][2] = range[j][2];
			}
		}
		double Selectrange[101][50];
		for (int j = 1; j <= N; j++){
			Selectrange[j][1] = Subrange[j][1];
			for (int k = 2; k <= Q1 - 1; k++){
				double demo;
				demo = Subrange[j][1] + (k - 1)*((Subrange[j][2] - Subrange[j][1]) / (Q1 - 1));
				Selectrange[j][k] = demo;
			}
			Selectrange[j][Q1] = Subrange[j][2];
		}

		for (int j = 1; j <= LM1_row; j++){
			chromosome chro_demo;
			chro_demo.S_chromosome.clear();
			for (int k = 1; k <= N; k++){
				int x = k;
				int y = LM1[j][k];
				chro_demo.S_chromosome.push_back(Selectrange[x][y]);
			}
			double value = function_one(chro_demo); //对函数一进行测试
			chro_demo.S_value = value;
			c_pool.push_back(chro_demo);
		}
	}
	//step -- three 选择G个最小的S个染色体
	selectChild();
}

/*
染色体选择进行正交交叉量化
*/
void GA::buildChild(chromosome parent_one, chromosome parent_two){
	//step -- one
	double SolutionPlace[3][101];
	for (int i = 0; i < N; i++){
		double min, max;
		if (parent_one.S_chromosome[i] > parent_two.S_chromosome[i]){
			min = parent_two.S_chromosome[i];
			max = parent_one.S_chromosome[i];
		}
		else{
			min = parent_one.S_chromosome[i];
			max = parent_two.S_chromosome[i];
		}
		SolutionPlace[1][i + 1] = min;
		SolutionPlace[2][i + 1] = max;
	}

	//step -- two 进行量化
	double Quantize[101][100];
	for (int i = 1; i <= N; i++){
		Quantize[i][1] = SolutionPlace[1][i];
		for (int j = 2; j <= Q2 - 1; j++){
			double demo = SolutionPlace[1][i] + (j - 1)*((SolutionPlace[2][i] - SolutionPlace[1][i]) / (Q2 - 1));
			Quantize[i][j] = demo;
		}
		Quantize[i][Q2] = SolutionPlace[2][i];
	}

	//step -- three 分成F组-(随机产生F-1个不同数据，并排序)
	int random[101];
	int count = 1, flag = 1;
	while (count != F){
		int demo = get_1_A_random(N - 2) + 1;
		flag = 1;
		for (int j = 1; j <= count - 1; j++){
			if (random[j] == demo){
				flag = 0;
				break;
			}
		}
		if (flag == 1){
			random[count] = demo;
			count++;
		}
	}
	sort(random, random + F);		//从小到大排序
	random[F] = N;

	//step -- four 根据LM2函数进行染色体选择
	for (int i = 1; i <= LM2_row; i++){
		chromosome chro_demo;
		chro_demo.S_chromosome.clear();
		for (int j = 1; j <= N; j++){
			int demo;
			for (int k = 1; k <= F; k++){
				if (j <= random[k] && j > random[k - 1]){
					demo = k;
					break;
				}
			}
			chro_demo.S_chromosome.push_back(Quantize[j][LM2[i][demo]]);
		}
		// 染色体变异
		double Pm = get_0_1_random();
		if (Pm <= pm){
			int position = get_1_A_random(N);
			double words = get_min_max_random(SolutionPlace[1][position], SolutionPlace[2][position]);
			chro_demo.S_chromosome[position - 1] = words;
		}
		double value = function_one(chro_demo);
		chro_demo.S_value = value;
		c_pool.push_back(chro_demo);
		chro_count++;
	}
}

/*
选择一个染色体作为父代染色体
*/
bool GA::chooseParents(){
	Select_pool.clear();
	int len = c_pool.size();
	for (int i = 0; i < len; i++){
		double demo = get_0_1_random();
		if (demo <= pc){
			Select_pool.push_back(c_pool[i]);
		}
	}
	int Select_len = Select_pool.size();
	if (Select_len <= 1)
		return false;
	else
		return true;
}

/*
对c_pool选择最小的S个种群
*/
void GA::selectChild(){
	int len = c_pool.size();
	sort(c_pool.begin(), c_pool.end(), cmp);
	c_pool.erase(c_pool.begin() + G, c_pool.end());
}

/*
开始遗传迭代
*/
void GA::run(int Maxnum, int steps, double range_left, double range_right){
	//step -- one 初始化
	chromosome parent_one, parent_two;
	buildinitLM();

	if (range_right - range_left <= 100)
		S = 10;
	else
		S = 20;
	buildinitPoption(range_left, range_right);
	//step -- two 先执行Maxnum代

	buildinitLM2();

	for (int i = 0; i < Maxnum; i++){
		if (chooseParents() == true){
			if (Select_pool.size() % 2 == 1){
				for (unsigned int i = 1; i < (Select_pool.size() - 1) / 2; i++){
					parent_one = Select_pool[i];
					parent_two = Select_pool[Select_pool.size() - i];
					buildChild(parent_one, parent_two);
				}
				selectChild();
			}
			else{
				for (unsigned int i = 0; i < Select_pool.size() / 2; i++){
					parent_one = Select_pool[i];
					parent_two = Select_pool[Select_pool.size() - i - 1];
					buildChild(parent_one, parent_two);
				}
				selectChild();
			}
		}
		else
			continue;
	}
	while (true){
		double last = c_pool[0].S_value;
		double now = 0;
		int flag = 0;	//flag = 1时，说明在后50代中有进一步较小染色体成本
		for (int i = 0; i < steps; i++){
			if (chooseParents() == true){
				if (Select_pool.size() % 2 == 1){
					for (unsigned int i = 1; i < (Select_pool.size() - 1) / 2; i++){
						parent_one = Select_pool[i];
						parent_two = Select_pool[Select_pool.size() - i];
						buildChild(parent_one, parent_two);
					}
					selectChild();
				}
				else{
					for (unsigned int i = 0; i < Select_pool.size() / 2; i++){
						parent_one = Select_pool[i];
						parent_two = Select_pool[Select_pool.size() - i - 1];
						buildChild(parent_one, parent_two);
					}
					selectChild();
				}
				now = c_pool[0].S_value;
				if (now < last)
					flag = 1;
			}
			else
				continue;
		}
		if (flag == 0)
			break;
	}
}

/*
获得染色体中最优的权值
*/
double GA::get_best_value(){
	return c_pool[0].S_value;
}

/*
获得最优的种群
*/
chromosome GA::get_best_chro(){
	return c_pool[0];
}

/*
获得这次迭代的function evaluations
*/
int GA::get_func_evalua(){
	return chro_count;
}

/*
展示染色体
*/
void GA::showChromosome(){
	int len = c_pool.size();
	cout << endl;
	for (int i = 0; i < len; i++){
		int len_two = c_pool[i].S_chromosome.size();
		for (int j = 0; j < len_two; j++){
			cout << c_pool[i].S_chromosome[j] << "    ";
		}
		cout << endl;
	}
}

int main(){
	GA test(30, 29, 3, 4, 0.10, 0.02);
	test.run(1000, 50, -500, 500);

	cout << test.get_best_value() << endl;
	system("pause");
	return 0;
}