#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int T = 0;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::vector<int> num;
		int sum = 0;
		for (int j = 0; j < 10; j++) {
			int n = 0;
			std::cin >> n;
			if (n % 2 != 0) {
				sum += n;
			}
		}
		std::cout << '#' << i + 1 << ' ' << sum << std::endl;
	}
	return 0;
}