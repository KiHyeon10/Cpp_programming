#include <iostream>

int Stack[1000000];

int main() {
	int total = 0;
	int top = 0;

	std::cin >> total;

	if (total > 1000000) {
		return 0;
	}

	for (int i = 0; i < total; i++) {
		int num = 0;
		std::cin >> num;
		if (num == 0) {
			top--;
		}
		else {
			Stack[top] = num;
			top++;
		}
	}
	int sum = 0;
	for (int i = 0; i < top; i++) {
//		std::cout << "Stack[" << i << "]: " << Stack[i] << std::endl;
		sum += Stack[i];
	}
//	std::cout << top << std::endl;
	std::cout << sum << std::endl;
}