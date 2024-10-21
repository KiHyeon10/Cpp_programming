#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
	int N = 0;
	std::cin >> N;

	std::vector<double> num;

	for (int i = 0; i < N; i++) {
		double n = 0;
		std::cin >> n;
		num.push_back(n);
	}
	std::vector<double> sum(num.size(), 0);
	sum[0] = num[0];
	double answer = 0;

	if (num.size() == 1) {
		answer = num[0];
	}
	for (int i = 1; i < num.size(); i++) {
		sum[i] = std::max(sum[i - 1] * num[i], num[i]);
		answer = std::max(sum[i], answer);
	}

	std::cout << std::fixed << std::setprecision(3) << answer;

	return 0;
}