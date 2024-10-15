#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
	int T = 0;
	std::cin >> T;
	std::cin.ignore();

	for (int i = 0; i < T; i++) {
		std::string X, Y;
		
		std::getline(std::cin, X);
		std::getline(std::cin, Y);

		while (Y != X) {
			if (Y.back() == 'Y') {
				Y.pop_back();
				std::reverse(Y.begin(), Y.end());
			}
			else if (Y.back() == 'X') {
				Y.pop_back();
			}
			if (Y.size() == X.size()) {
				std::cout << '#' << i + 1 << ' ';
				if (Y == X) {
					std::cout << "Yes" << std::endl;
				}
				else {
					std::cout << "No" << std::endl;
				}
				break;
			}
		}
	}
	return 0;
}
