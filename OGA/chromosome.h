#include <vector>

using namespace std;

struct chromosome{
	vector<double> S_chromosome;
	double S_value;
};

#define pool vector<struct chromosome>

/*
Ⱦɫ������
*/
bool cmp(chromosome A, chromosome B){
	return A.S_value < B.S_value;
}