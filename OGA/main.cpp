#include "chromosome.h"
#include "OGA.h"
#include "function.h"
#include <iostream>

using namespace std;

int main(){
	double answer[15];
	double range[2][15] = { { -500, -5.12, -32, -600, -50, -50, 0, -PI, -5, -5, -100, -1.28, -10, -100, -100 },
							{ 500, 5.12, 32, 600, 50, 50, PI, PI, 5, 10, 100, 1.28, 10, 100, 100 } };
	int dim[15] = {30, 30, 30, 30, 30, 30, 100, 100, 100, 100, 30, 30, 30, 30, 30 };
	for (int i = 0; i < 15; i++){
		OGA test(i + 1, dim[i], dim[i] - 1, 3, 4, 0.10, 0.02);
		test.run(1000, 50, range[0][i], range[1][i]);
		answer[i] = test.get_best_value();
		cout << i+1 << ": ";
		cout << answer[i] << endl;
	}	
	system("pause");
	return 0;
}