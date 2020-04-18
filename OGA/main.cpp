#include "OGA.h"
#include "CGA.h"
#include "function.h"
#include <iostream>
#include <stdio.h>

using namespace std;

char *savePath = "E:\\result\\data.txt";
char *OGA_f1 = "E:\\result\\O_function_one.txt";
char *OGA_f2 = "E:\\result\\O_function_two.txt";
char *OGA_f3 = "E:\\result\\O_function_three.txt";
char *OGA_f4 = "E:\\result\\O_function_four.txt";
char *OGA_f5 = "E:\\result\\O_function_five.txt";
char *OGA_f6 = "E:\\result\\O_function_six.txt";
char *OGA_f7 = "E:\\result\\O_function_seven.txt";
char *OGA_f8 = "E:\\result\\O_function_eight.txt";
char *OGA_f9 = "E:\\result\\O_function_nine.txt";
char *OGA_f10 = "E:\\result\\O_function_ten.txt";
char *OGA_f11 = "E:\\result\\O_function_eleven.txt";
char *OGA_f12 = "E:\\result\\O_function_twelve.txt";
char *OGA_f13 = "E:\\result\\O_function_thirteen.txt";
char *OGA_f14 = "E:\\result\\O_function_fourteen.txt";
char *OGA_f15 = "E:\\result\\O_function_fifteen.txt";

char *CGA_f1 = "E:\\result\\C_function_one.txt";
char *CGA_f2 = "E:\\result\\C_function_two.txt";
char *CGA_f3 = "E:\\result\\C_function_three.txt";
char *CGA_f4 = "E:\\result\\C_function_four.txt";
char *CGA_f5 = "E:\\result\\C_function_five.txt";
char *CGA_f6 = "E:\\result\\C_function_six.txt";
char *CGA_f7 = "E:\\result\\C_function_seven.txt";
char *CGA_f8 = "E:\\result\\C_function_eight.txt";
char *CGA_f9 = "E:\\result\\C_function_nine.txt";
char *CGA_f10 = "E:\\result\\C_function_ten.txt";
char *CGA_f11 = "E:\\result\\C_function_eleven.txt";
char *CGA_f12 = "E:\\result\\C_function_twelve.txt";
char *CGA_f13 = "E:\\result\\C_function_thirteen.txt";
char *CGA_f14 = "E:\\result\\C_function_fourteen.txt";
char *CGA_f15 = "E:\\result\\C_function_fifteen.txt";

/*
	one--要输出文件;
	two--要输出文件;
*/
void exchange(char *filename1, char *filename2) {
	char content[256];
	ifstream f1; //要输出文件
	ofstream f2; //要输出文件

	f1.open(filename1, ios::in);
	f2.open(filename2, ios::out);

	while (!f1.eof()) {
		f1.getline(content,128);
		f2 << content << endl;
	}

	f1.close();
	f2.close();
}

void change(int flag, int function) {
	if (flag == 1) {
		switch (function)
		{
		case 1:
			exchange(savePath,OGA_f1);
		case 2:
			exchange(savePath,OGA_f2);
		case 3:
			exchange(savePath,OGA_f3);
		case 4:
			exchange(savePath,OGA_f4);
		case 5:
			exchange(savePath,OGA_f5);
		case 6:
			exchange(savePath,OGA_f6);
		case 7:
			exchange(savePath,OGA_f7);
		case 8:
			exchange(savePath,OGA_f8);
		case 9:
			exchange(savePath,OGA_f9);
		case 10:
			exchange(savePath,OGA_f10);
		case 11:
			exchange(savePath,OGA_f11);
		case 12:
			exchange(savePath,OGA_f12);
		case 13:
			exchange(savePath,OGA_f13);
		case 14:
			exchange(savePath,OGA_f14);
		case 15:
			exchange(savePath,OGA_f15);
		}
	}
	else {
		switch (function)
		{
		case 1:
			exchange(savePath,CGA_f1);
		case 2:
			exchange(savePath,CGA_f2);
		case 3:
			exchange(savePath,CGA_f3);
		case 4:
			exchange(savePath,CGA_f4);
		case 5:
			exchange(savePath,CGA_f5);
		case 6:
			exchange(savePath,CGA_f6);
		case 7:
			exchange(savePath,CGA_f7);
		case 8:
			exchange(savePath,CGA_f8);
		case 9:
			exchange(savePath,CGA_f9);
		case 10:
			exchange(savePath,CGA_f10);
		case 11:
			exchange(savePath,CGA_f11);
		case 12:
			exchange(savePath,CGA_f12);
		case 13:
			exchange(savePath,CGA_f13);
		case 14:
			exchange(savePath,CGA_f14);
		case 15:
			exchange(savePath,CGA_f15);
		}
	}
}

void del_func(int flag, int function) {
	if (flag == 1) {
		switch (function)
		{
		case 1:
			remove(OGA_f1);
		case 2:
			remove(OGA_f2);
		case 3:
			remove(OGA_f3);
		case 4:
			remove(OGA_f4);
		case 5:
			remove(OGA_f5);
		case 6:
			remove(OGA_f6);
		case 7:
			remove(OGA_f7);
		case 8:
			remove(OGA_f8);
		case 9:
			remove(OGA_f9);
		case 10:
			remove(OGA_f10);
		case 11:
			remove(OGA_f11);
		case 12:
			remove(OGA_f12);
		case 13:
			remove(OGA_f13);
		case 14:
			remove(OGA_f14);
		case 15:
			remove(OGA_f15);
		}
	}
	else {
		switch (function)
		{
		case 1:
			remove(CGA_f1);
		case 2:
			remove(CGA_f2);
		case 3:
			remove(CGA_f3);
		case 4:
			remove(CGA_f4);
		case 5:
			remove(CGA_f5);
		case 6:
			remove(CGA_f6);
		case 7:
			remove(CGA_f7);
		case 8:
			remove(CGA_f8);
		case 9:
			remove(CGA_f9);
		case 10:
			remove(CGA_f10);
		case 11:
			remove(CGA_f11);
		case 12:
			remove(CGA_f12);
		case 13:
			remove(CGA_f13);
		case 14:
			remove(CGA_f14);
		case 15:
			remove(CGA_f15);
		}
	}
}

int main() {
	ofstream f3;
	ofstream f4;
	f3.open("E:\\result\\OGA_result.txt");
	f4.open("E:\\result\\CGA_result.txt");
	double range[2][15] = { { -500, -5.12, -32, -600, -50, -50, 0, -PI, -5, -5, -100, -1.28, -10, -100, -100 },
							{ 500, 5.12, 32, 600, 50, 50, PI, PI, 5, 10, 100, 1.28, 10, 100, 100 } };
	int dim[15] = { 30, 30, 30, 30, 30, 30, 100, 100, 100, 100, 30, 30, 30, 30, 30 };
	double demo = 0, result = 0,num = 0,end_num = 0;
	int Allnumber[60];

	for (int j = 1; j <= 15; j++) {
		if (j == 8)
			continue;
		f3 << "+++++++++++++++++++++++++++++" << "function:" << j << "+++++++++++++++++++++++++++++" << endl;
		for (int i = 0; i < 50; i++) {
			OGA test(j, dim[j-1],dim[j-1]-1, 3, 4, 0.10, 0.02);
			test.run(1000, 100, range[0][j - 1], range[1][j - 1]);
			
			result = test.get_best_value();
			num = test.get_func_evalua();
			Allnumber[i] = num;

			if (i == 0)
				demo = result;
			f3 << i << ": ";
			f3 << fixed << setprecision(10) << result;
			f3 << " function evaluation: " << num << endl;

			if (demo >= result) {
				demo = result;
				del_func(1, j);
				change(1, j);
			}
			remove(savePath);
		}
		for (int i = 0; i < 50; i++)
			end_num += Allnumber[i];
		f3 << "Final___value: ";
		f3 << fixed << setprecision(10) << demo;
		f3 << " function evaluation: " << (int)end_num/50 << endl;
	}
	f3.close();
	for (int j = 1; j <= 15; j++) {
		if (j == 8)
			continue;
		f4 << "+++++++++++++++++++++++++++++" << "function:" << j << "+++++++++++++++++++++++++++++" << endl;
		end_num = 0;
		for (int i = 0; i < 50; i++) {
			CGA test(j, dim[j - 1], 0.10, 0.02);
			test.run(1000, 100, range[0][j - 1], range[1][j - 1]);

			result = test.get_best_value();
			num = test.get_func_evalua();
			Allnumber[i] = num;

			if (i == 0)
				demo = result;
			f4 << i << ": ";
			f4 << fixed << setprecision(10) << result;
			f4 << " function evaluation: " << num << endl;

			if (demo >= result) {
				demo = result;
				del_func(1, j);
				change(1, j);
			}
			remove(savePath);
		}
		for (int i = 0; i < 50; i++)
			end_num += Allnumber[i];
		f4 << "Final___value: ";
		f4 << fixed << setprecision(10) << demo;
		f4 << " function evaluation: " << (int)end_num / 50 << endl;
	}
	f4.close();
	system("pause");
	return 0;
}
