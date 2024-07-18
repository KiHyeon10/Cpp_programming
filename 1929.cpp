#include <iostream>
#include <cmath>
#include <vector>

int main() {
	int N = 0, M = 0;

	std::cin >> M >> N;

	std::vector<bool> answer(N + 1, true);
	answer[0] = answer[1] = false;

	for (int i = 2; i <= static_cast<int>(std::sqrt(N)); i++) {
		if (answer[i] == true) {
			for (int j = i * i; j <= N; j += i) {
				answer[j] = false;
			}
		}
	}

	for (int i = M; i < answer.size(); i++) {
		if (answer[i] == true) {
			std::cout << i << "\n";
		}
	}
	return 0;
}