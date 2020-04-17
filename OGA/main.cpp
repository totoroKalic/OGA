#include "OGA.h"
#include "CGA.h"
#include "function.h"
#include <iostream>

using namespace std;

/*
int main(){
	double range[2][15] = { { -500.0, -5.12, -32.0, -600.0, -50.0, -50.0, 0, -PI, -5.0, -5.0, -100.0, -1.28, -10.0, -100.0, -100.0 },
							{ 500.0, 5.12, 32.0, 600.0, 50.0, 50.0, PI, PI, 5.0, 10.0, 100.0, 1.28, 10.0, 100.0, 100.0 } };
	int dim[15] = {30, 30, 30, 30, 30, 30, 100, 100, 100, 100, 30, 30, 30, 30, 30 };
	for (int i = 0; i < 50; i++) {
		OGA test(8, 100, 99, 3, 4, 0.10, 0.02);
		cout << "one"<<endl;
		test.run(1000, 50, -PI,PI);

		cout << i << ": ";
		cout << " function value: " << fixed << setprecision(10) << test.get_best_value() << "    ";
		cout << " function evaluation: " << test.get_func_evalua();
		cout << endl;
	}
	
	system("pause");
	return 0;
}
*/

int main() {
	double range[2][15] = { { -500, -5.12, -32, -600, -50, -50, 0, -PI, -5, -5, -100, -1.28, -10, -100, -100 },
							{ 500, 5.12, 32, 600, 50, 50, PI, PI, 5, 10, 100, 1.28, 10, 100, 100 } };
	int dim[15] = { 30, 30, 30, 30, 30, 30, 100, 100, 100, 100, 30, 30, 30, 30, 30 };
	for (int j = 1; j <= 15; j++) {
		if (j == 8)
			continue;
		cout << "++++++++++++++++++++" << "function:" << j << "++++++++++++++++" << endl;
		for (int i = 0; i < 20; i++) {

			CGA test(j, dim[j-1], 0.10, 0.02);
			test.run(1000, 50,range[0][j-1],range[1][j-1]);

			cout << i << ": ";
			cout << fixed << setprecision(10) << test.get_best_value();
			cout << " function evaluation: " << test.get_func_evalua();
			cout << endl;
		}
	}
	system("pause");
	return 0;
}
