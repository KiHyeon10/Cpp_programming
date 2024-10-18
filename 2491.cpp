#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int length = 0;
	std::cin >> length;

	std::vector<int> num;

	for (int i = 0; i < length; i++) {
		int n = 0;
		std::cin >> n;
		num.push_back(n);
	}

	int Low_count = 1;
	int Up_count = 1;
	int Low_max = 1;
	int Up_max = 1;

	for (int i = 1; i < length; i++) {
		if (num[i - 1] >= num[i]) {
			Low_count += 1;
		}
		else {
			Low_count = 1;
		}
		Low_max = std::max(Low_count, Low_max);
	}
	for (int i = 1; i < length; i++) {
		if (num[i - 1] <= num[i]) {
			Up_count += 1;
		}
		else {
			Up_count = 1;
		}
		Up_max = std::max(Up_count, Up_max);
	}
	std::cout << std::max(Low_max, Up_max);

	return 0;
}