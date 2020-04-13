#include "chromosome.h"
#include "OGA.h"
#include "function.h"
#include <iostream>

using namespace std;

int main(){
	double range[2][15] = { { -500, -5.12, -32, -600, -50, -50, 0, -PI, -5, -5, -100, -1.28, -10, -100, -100 },
							{ 500, 5.12, 32, 600, 50, 50, PI, PI, 5, 10, 100, 1.28, 10, 100, 100 } };
	int dim[15] = {30, 30, 30, 30, 30, 30, 100, 100, 100, 100, 30, 30, 30, 30, 30 };
	for (int i = 0; i < 5; i++){
		OGA test(15, 30, 29, 3, 4, 0.10, 0.02);
		test.run(1000, 50, -100, 100);

		cout << fixed << setprecision(6) << test.get_best_value();
		cout << endl;
	}
	system("pause");
	return 0;
}