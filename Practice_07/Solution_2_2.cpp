#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	vector<float> vec;
	int n, index1, index2;
	float x;
	float median;
	scanf("%d", &n);


	for (int i = 0; i<n; i++) {

		scanf("%f", &x);
		auto itr = upper_bound(vec.begin(), vec.end(), x);
		vec.insert(itr, x);

		if (i % 2 == 0) {
			index1 = i / 2;
			index2 = index1;
		}
		else {
			index1 = i / 2;
			index2 = index1 + 1;
		}

		median = (vec[index1] + vec[index2]) / 2.0;

		printf("%.1f\n", median);
	}
	return 0;
}